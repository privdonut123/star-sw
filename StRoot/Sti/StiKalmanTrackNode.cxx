#include <iostream>
#include "StiHit.h"
#include "StiKalmanTrackNode.h"


//_____________________________________________________________________________
// Local Track Model
//
// x[0] = y  ordinate
// x[1] = z  position along beam axis
// x[2] = eta=C*x0
// x[3] = C  (local) curvature of the track
// x[4] = tan(l) 

double StiKalmanTrackNode::kField = 0.5;

//_____________________________________________________________________________
void StiKalmanTrackNode::reset()
{ 
  // Base class reset
  StiTrackNode::reset();
  // Reference angle
  fAlpha= 0.;
  // Reference position
  fX    = 0.;
  // Track State at this node
  fP0   = 0.;
  fP1   = 0.;
  fP2   = 0.;
  fP3   = 0.;
  fP4   = 0.;
  // covariance error matrix
  fC00  = 0.;
  fC10  = 0.;
  fC11  = 0.;
  fC20  = 0.;
  fC21  = 0.;
  fC22  = 0.;
  fC30  = 0.;
  fC31  = 0.;
  fC32  = 0.;
  fC33  = 0.;
  fC40  = 0.;
  fC41  = 0.;
  fC42  = 0.;
  fC43  = 0.;
  fC44  = 0.;
  // fit quality
  fChi2  = 0;
  // dedx information
  fdEdx = 0.;
}


//_____________________________________________________________________________
void StiKalmanTrackNode::set(int   depth,
			     StiHit * hit,
			     const double alpha,
			     const double xRef,
			     const double xx[5], 
			     const double cc[15], 
			     const double dEdx,
			     const double chi2)
{
  StiTrackNode::set(depth, hit);
  fAlpha  = alpha;
  fX      = xRef;
  fdEdx   = dEdx;
  fChi2   = chi2;
  fP0=xx[0]; 
  fP1=xx[1]; 
  fP2=xx[2]; 
  fP3=xx[3]; 
  fP4=xx[4];
  // covariance error matrix
  fC00=cc[0];
  fC10=cc[1];  
  fC11=cc[2];
  fC20=cc[3];  
  fC21=cc[4];  
  fC22=cc[5];
  fC30=cc[6];  
  fC31=cc[7];  
  fC32=cc[8];  
  fC33=cc[9];
  fC40=cc[10]; 
  fC41=cc[11]; 
  fC42=cc[12]; 
  fC43=cc[13]; 
  fC44=cc[14];
}

void StiKalmanTrackNode::setState(const StiKalmanTrackNode * node)
{
  fX   = node->fX;
  // state matrix
  fP0  = node->fP0;
  fP1  = node->fP1;
  fP2  = node->fP2;
  fP3  = node->fP3;
  fP4  = node->fP4;
  // covariance error matrix
  fC00 = node->fC00;
  fC10 = node->fC10;
  fC11 = node->fC11;
  fC20 = node->fC20;
  fC21 = node->fC21;
  fC22 = node->fC22;
  fC30 = node->fC30;
  fC31 = node->fC31;
  fC32 = node->fC32;
  fC33 = node->fC33;
  fC40 = node->fC40;
  fC41 = node->fC41;
  fC42 = node->fC42;
  fC43 = node->fC43;
  fC44 = node->fC44;
}


//_____________________________________________________________________________
void StiKalmanTrackNode::setAsCopyOf(const StiKalmanTrackNode * node)
{
  StiTrackNode::setAsCopyOf(node);
  fX    = node->fX;
  fAlpha= node->fAlpha;
  fdEdx = node->fdEdx;
  fChi2  = node->fChi2;
  fP0   = node->fP0;
  fP1   = node->fP1;
  fP2   = node->fP2;
  fP3   = node->fP3;
  fP4   = node->fP4;
  // covariance error matrix
  fC00  = node->fC00;
  fC10  = node->fC10;
  fC11  = node->fC11;
  fC20  = node->fC20;
  fC21  = node->fC21;
  fC22  = node->fC22;
  fC30  = node->fC30;
  fC31  = node->fC31;
  fC32  = node->fC32;
  fC33  = node->fC33;
  fC40  = node->fC40;
  fC41  = node->fC41;
  fC42  = node->fC42;
  fC43  = node->fC43;
  fC44  = node->fC44;
}

//_____________________________________________________________________________
void StiKalmanTrackNode::get(double& alpha,
			     double& xRef,
			     double  x[5], 
			     double  e[15], 
			     double& dEdx,
			     double& chi2)
{
  /** returns the node information
      double& alpha : angle of the local reference frame
      double& xRef  : refence position of this node in the local frame
      double x[5],  : state, for a definition, see the top of this file
      double cc[15] : error matrix of the state "x"
      double& dEdx  : energy loss info
      double& chi2) : chi2 of the track at this node
  */
  alpha = fAlpha;
  xRef  = fX;
  x[0] = fP0;
  x[1] = fP1;
  x[2] = fP2;
  x[3] = fP3;
  x[4] = fP4;
  e[0] = fC00;
  e[1] = fC10;
  e[2] = fC11;
  e[3] = fC20;
  e[4] = fC21;
  e[5] = fC22;
  e[6] = fC30;
  e[7] = fC31;
  e[8] = fC32;
  e[9] = fC33;
  e[10] = fC40;
  e[11] = fC41;
  e[12] = fC42;
  e[13] = fC43;
  e[14] = fC44;
  dEdx = fdEdx;
  chi2 = fChi2;
}


//_____________________________________________________________________________
void StiKalmanTrackNode::getMomentum(double p[3], double e[6]) const
{	
  // returns momentum and its error matrix 
  // in cartesian coordinates in the _local_
  // ref frame of this node.
  // p[0] = px  - outward
  // p[1] = py  - 
  // p[2] = pz  - along beam axis
  
  double c, pt, sinPhi, cosPhi;
  c = fP3;
  if (c<1e-9 && c>0)
    c = 1e-9;
  else if (c>-1e-9 && c<0)
    c = -1e-9;
  
  pt = kField/c;
  sinPhi = c*fX-fP2;
  cosPhi = sqrt(1-sinPhi*sinPhi);
  p[0] = pt*cosPhi;
  p[1] = pt*sinPhi;
  p[2] = pt*fP4;
  if (e==0)
    return;
  double sa = 1-(c*fX-fP2)*(c*fX-fP2);
  if (sa<0)
    {
      cout << "StiKalmanTrackNode::getMomentum() - Error - sa<0 - Value was:" << sa << " - reset to sa=0." << endl;
      sa = 0.;
    }
  sa = sqrt(sa);
  double a00=kField*(fX-fP2/c)/sa;
  double a01=-kField*(fP2*fP2-fX*fP2*c-1)/(c*c*sa);
  double a02=0;
  double a10=-kField/c; 
  double a11=kField*fP2/(c*c);
  double a12=0;
  double a20=0;
  double a21=-kField*fP4/c;
  double a22=kField/c;
  // original error matrix
  double b00=fC22, b01=fC32, b02=fC42;
  double b10=fC32, b11=fC33, b12=fC43;
  double b20=fC42, b21=fC43, b22=fC44;
  // intermediate results matrices
  double c00, c01, c02;
  double c10, c11, c12;
  double c20, c21, c22;
  double d00, d01, d02;
  double      d11, d12;
  double           d22;
  // C=A*B
  c00 = a00*b00+a01*b10+a02*b20;
  c01 = a00*b01+a01*b11+a02*b21;
  c02 = a00*b02+a01*b12+a02*b22;
  
  c10 = a10*b00+a11*b10+a12*b20;
  c11 = a10*b01+a11*b11+a12*b21;
  c12 = a10*b02+a11*b12+a12*b22;
  
  c20 = a20*b00+a21*b10+a22*b20;
  c21 = a20*b01+a21*b11+a22*b21;
  c22 = a20*b02+a21*b12+a22*b22;
  // D=C*At 
  d00 = c00*a00+c01*a01+c02*a02;
  d01 = c00*a10+c01*a11+c02*a12;
  d02 = c00*a20+c01*a21+c02*a22;
  //d10 = c10*a00+c11*a01+c12*a02;
  d11 = c10*a10+c11*a11+c12*a12;
  d12 = c10*a20+c11*a21+c12*a22;
  //d20 = c20*a00+c21*a01+c22*a02;
  //d21 = c20*a10+c21*a11+c22*a12;
  d22 = c20*a20+c21*a21+c22*a22;
  
  e[0] = d00;  // px-px
  e[1] = d01;  // px-py
  e[2] = d02;  // px-pz
  e[3] = d11;  // py-py
  e[4] = d12;  // py-pz
  e[5] = d22;  // pz-pz
}

//_____________________________________________________________________________
void StiKalmanTrackNode::getGlobalMomentum(double p[3], double e[6]) const
{	
  // returns momentum and its error matrix 
  // in cartesian coordinates in the _global_
  // ref frame of the experiment
  // p[0] = px
  // p[1] = py
  // p[2] = pz
  // e[0] = // px-px
  // e[1] = // px-py
  // e[2] = // px-pz
  // e[3] = // py-py
  // e[4] = // py-pz
  // e[5] = // pz-pz
  
  // first get p & e in the local ref frame
  getMomentum(p,e);
  
  // now rotate the p & e in the global ref frame
  // for the time being, assume an azimuthal rotation 
  // by alpha is sufficient.
  // transformation matrix - needs to be set
  double ca = cos(fAlpha);
  double sa = sin(fAlpha);
  double a00=ca, a01=-sa, a02=0;
  double a10=sa, a11= ca, a12=0;
  double a20= 0, a21=  0, a22=1.;

  double px=p[0];
  double py=p[1];
  double pz=p[2];
  p[0] = a00*px + a01*py + a02*pz;
  p[1] = a10*px + a11*py + a12*pz;
  p[2] = a20*px + a21*py + a22*pz;

  // original error matrix
  double b00=e[0], b01=e[1], b02=e[2];
  double b10=e[1], b11=e[3], b12=e[4];
  double b20=e[2], b21=e[4], b22=e[5];
  // intermediate results matrices
  double c00, c01, c02;
  double c10, c11, c12;
  double c20, c21, c22;
  double d00, d01, d02;
  double      d11, d12;
  double           d22;
  // C=A*B
  c00 = a00*b00+a01*b10+a02*b20;
  c01 = a00*b01+a01*b11+a02*b21;
  c02 = a00*b02+a01*b12+a02*b22;
  
  c10 = a10*b00+a11*b10+a12*b20;
  c11 = a10*b01+a11*b11+a12*b21;
  c12 = a10*b02+a11*b12+a12*b22;
  
  c20 = a20*b00+a21*b10+a22*b20;
  c21 = a20*b01+a21*b11+a22*b21;
  c22 = a20*b02+a21*b12+a22*b22;
  // D=C*At
  d00 = c00*a00+c01*a01+c02*a02;
  d01 = c00*a10+c01*a11+c02*a12;
  d02 = c00*a20+c01*a21+c02*a22;
  //d10 = c10*a00+c11*a01+c12*a02;
  d11 = c10*a10+c11*a11+c12*a12;
  d12 = c10*a20+c11*a21+c12*a22;
  //d20 = c20*a00+c21*a01+c22*a02;
  //d21 = c20*a10+c21*a11+c22*a12;
  d22 = c20*a20+c21*a21+c22*a22;
		
  e[0] = d00;  // px-px
  e[1] = d01;  // px-py
  e[2] = d02;  // px-pz
  e[3] = d11;  // py-py
  e[4] = d12;  // py-pz
  e[5] = d22;  // pz-pz
}

double StiKalmanTrackNode::getTanL() const
{
  return fP4;
}

double StiKalmanTrackNode::getPt() const
{
  double c,pt;
  c = fP3;
  if (c<1e-9 && c>0)
    c = 1e-9;
  else if (c>-1e-9 && c<0)
    c = -1e-9;
  pt = kField/c;
  return pt;
}


ostream& operator<<(ostream& os, const StiKalmanTrackNode& n)
{
	// print to the ostream "os" the parameters of this node 
	// and all its children recursively

  os << "Node Level: " << n.mDepth << endl
		 << "x:" << n.fX  <<"\t"
		 << "a:" << n.fAlpha<<"\t"
		 << "dedx:" << n.fdEdx <<"\t"
		 << "chi2:" << n.fChi2 << endl
		 << "P0/1/2/3/4:" << n.fP0 << " " 
		 << n.fP1 <<" "
		 << n.fP2 <<" "
		 << n.fP3 <<" "
		 << n.fP4 << endl
		 << "ERROR:" << n.fC00 << "\t"
		 << n.fC10<<"\t"
		 << n.fC11<<"\t"
		 << n.fC20<<"\t"
		 << n.fC21<<"\t"
		 << n.fC22<<"\t"
		 << n.fC30<<"\t"
		 << n.fC31<<"\t"
		 << n.fC32<<"\t"
		 << n.fC33<<"\t"
		 << n.fC40<<"\t"
		 << n.fC41<<"\t"
		 << n.fC42<<"\t"
		 << n.fC43<<"\t"
		 << n.fC44 << endl;
	int nChildren = n.getChildCount();
	for (int i=0;i<nChildren;i++)
		{
			const StiKalmanTrackNode * child = dynamic_cast<const StiKalmanTrackNode *>(n.getChildAt(i));
			os << *child;
		}
	return os;
}




