/***************************************************************************
 *
 * $Id: StHbtParticle.cc,v 1.18 2002/11/19 23:36:00 renault Exp $
 *
 * Author: Mike Lisa, Ohio State, lisa@mps.ohio-state.edu
 ***************************************************************************
 *
 * Description: part of STAR HBT Framework: StHbtMaker package
 *   Particle objects are part of the PicoEvent, which is what is
 *   stored in the EventMixingBuffers
 *   A Track object gets converted to a Particle object if it
 *   passes the ParticleCut of an Analysis
 *
 ***************************************************************************
 *
 * $Log: StHbtParticle.cc,v $
 * Revision 1.18  2002/11/19 23:36:00  renault
 * Enable calculation of exit/entrance separation for V0 daughters
 *
 * Revision 1.17  2001/12/14 23:11:30  fretiere
 * Add class HitMergingCut. Add class fabricesPairCut = HitMerginCut + pair purity cuts. Add TpcLocalTransform function which convert to local tpc coord (not pretty). Modify StHbtTrack, StHbtParticle, StHbtHiddenInfo, StHbtPair to handle the hit information and cope with my code
 *
 * Revision 1.16  2001/05/25 23:23:59  lisa
 * Added in StHbtKink stuff
 *
 * Revision 1.15  2001/04/03 21:04:36  kisiel
 *
 *
 *   Changes needed to make the Theoretical code
 *   work. The main code is the ThCorrFctn directory.
 *   The most visible change is the addition of the
 *   HiddenInfo to StHbtPair.
 *
 * Revision 1.14  2000/10/05 23:09:05  lisa
 * Added kT-dependent radii to mixed-event simulator AND implemented AverageSeparation Cut and CorrFctn
 *
 * Revision 1.13  2000/08/31 22:31:31  laue
 * StHbtAnalysis: output changed (a little bit less)
 * StHbtEvent: new version, members for reference mult added
 * StHbtIOBinary: new IO for new StHbtEvent version
 * StHbtTypes: TTree typedef to StHbtTTree added
 * StHbtVertexAnalysis: overflow and underflow added
 *
 * Revision 1.12  2000/07/23 13:52:56  laue
 * NominalExitPoint set to (-9999.,-9999.-9999.) if helix.at()
 * returns nan (not a number).
 *
 * Revision 1.11  2000/07/19 17:18:48  laue
 * Calculation of Entrance and Exit point added in StHbtParticle constructor
 *
 * Revision 1.10  2000/07/17 20:03:17  lisa
 * Implemented tools for addressing and assessing trackmerging
 *
 * Revision 1.9  2000/07/16 21:38:23  laue
 * StHbtCoulomb.cxx StHbtSectoredAnalysis.cxx : updated for standalone version
 * StHbtV0.cc StHbtV0.hh : some cast to prevent compiling warnings
 * StHbtParticle.cc StHbtParticle.hh : pointers mTrack,mV0 initialized to 0
 * StHbtIOBinary.cc : some printouts in #ifdef STHBTDEBUG
 * StHbtEvent.cc : B-Field set to 0.25Tesla, we have to think about a better
 *                 solution
 *
 * Revision 1.8  2000/05/03 17:44:43  laue
 * StHbtEvent, StHbtTrack & StHbtV0 declared friend to StHbtIOBinary
 * StHbtParticle updated for V0 pos,neg track Id
 *
 * Revision 1.7  2000/04/03 16:21:51  laue
 * some include files changed
 * Multi track cut added
 *
 * Revision 1.6  1999/12/11 15:58:29  lisa
 * Add vertex decay position datum and accessor to StHbtParticle to allow pairwise cuts on seperation of V0s
 *
 * Revision 1.5  1999/09/17 22:38:02  lisa
 * first full integration of V0s into StHbt framework
 *
 * Revision 1.4  1999/09/01 19:04:53  lisa
 * update Particle class AND add parity cf and Randys Coulomb correction
 *
 * Revision 1.3  1999/07/06 22:33:23  lisa
 * Adjusted all to work in pro and new - dev itself is broken
 *
 * Revision 1.2  1999/06/29 17:50:27  fisyak
 * formal changes to account new StEvent, does not complie yet
 *
 * Revision 1.1.1.1  1999/06/29 16:02:57  lisa
 * Installation of StHbtMaker
 *
 **************************************************************************/

#include "StHbtMaker/Infrastructure/StHbtParticle.hh"
#include "math_constants.h"
#ifdef __CC5__
  #include <math.h>
#else
  #include <cmath>
#endif
int TpcLocalTransform(StThreeVectorD& xgl, 
		      int& iSector, 
		      int& iPadrow, 
		      double& xlocal,
		      double& ttPhi);


//_____________________
StHbtParticle::StHbtParticle() : mTrack(0), mV0(0), mKink(0) {
  /* no-op for default */
}
//_____________________
StHbtParticle::~StHbtParticle(){
  if (mTrack) delete mTrack;
  if (mV0) delete mV0;
  if (mKink) delete mKink;
}
//_____________________
StHbtParticle::StHbtParticle(const StHbtTrack* const hbtTrack,const double& mass) : mTrack(0), mV0(0), mKink(0) {
  // I know there is a better way to do this...
  mTrack = new StHbtTrack(*hbtTrack);
  StHbtThreeVector temp = hbtTrack->P();
  mFourMomentum.setVect(temp);
  double ener = sqrt(temp.mag2()+mass*mass);
  mFourMomentum.setE(ener);
  mMap[0] = hbtTrack->TopologyMap(0);
  mMap[1] = hbtTrack->TopologyMap(1);
  mNhits = hbtTrack->NHits();
  mHelix = hbtTrack->Helix();
  CalculateNominalTpcExitAndEntrancePoints();
  // test
  mHelixTrackTest = hbtTrack->Helix();

  StHbtThreeVector ZeroVectTrackTest(0.,0.,0.);
  ZeroVectTrackTest = hbtTrack->Helix().origin();
  CalculateTpcExitAndEntrancePoints(&mHelixTrackTest,&ZeroVectTrackTest,
				    &mTpcTrackTestEntrancePoint,
				    &mTpcTrackTestExitPoint,
				    &mTpcTrackTestPosSample[0],&mTrackTestZ[0],
				    &mTrackTestU[0],&mTrackTestSect[0]);
//   cout <<"Entrance Orig ="<< mNominalTpcEntrancePoint << endl;
//   cout <<"Entrance Modi ="<< mTpcTrackTestEntrancePoint << endl;
//   cout <<"Exit Orig ="<< mNominalTpcExitPoint << endl;
//   cout <<"Exit Modi ="<< mTpcTrackTestExitPoint << endl;
//   cout <<"PosSample Orig0 ="<< mNominalPosSample[0] << endl;
//   cout <<"PosSample Modi0 ="<< mTpcTrackTestPosSample[0] << endl;
//   cout <<"PosSample Orig1 ="<< mNominalPosSample[1] << endl;
//   cout <<"PosSample Modi1 ="<< mTpcTrackTestPosSample[1] << endl;
//   cout <<"Z Orig0 ="<<mZ[0] << endl;
//   cout <<"Z Modi0 ="<<mTrackTestZ[0] << endl;
//   cout <<"U Orig0 ="<<mU[0] << endl;
//   cout <<"U Modi0 ="<<mTrackTestU[0] << endl;
//   cout <<"Sect Orig0 ="<<mSect[0] << endl;
//   cout <<"Sect Modi0 ="<<mTrackTestSect[0] << endl;
  // end test
  // ***
  mHiddenInfo= 0;
  if(hbtTrack->ValidHiddenInfo()){
    mHiddenInfo= hbtTrack->getHiddenInfo()->clone();
  }
  // ***

}
//_____________________
StHbtParticle::StHbtParticle(const StHbtV0* const hbtV0,const double& mass) : mTrack(0), mV0(0), mKink(0) {
  mV0 = new StHbtV0(*hbtV0);
  mMap[0]= 0;
  mMap[1]= 0;
  // I know there is a better way to do this...
  StHbtThreeVector temp = hbtV0->momV0();
  mFourMomentum.setVect(temp);
  double ener = sqrt(temp.mag2()+mass*mass);
  mFourMomentum.setE(ener);
  //  cout << mPosTrackId << " " << mNegTrackId << " " << hbtV0->idPos() << " " << hbtV0->idNeg() << endl;
  //  mHelix = hbtTrack->Helix(); ?? what to do with mHelix for a Particle coming from a V0?
  // Calculating TpcEntrancePoint for Positive V0 daugther
  mPrimaryVertex = hbtV0->primaryVertex();
//   cout <<"StHbtParticle---DEBUT_V0" << endl;



  mHelixV0Pos = hbtV0->HelixPos();
//   cout <<"StHbtParticle---mHelixV0Pos->x==" << mHelixV0Pos.origin().x() << endl;
//   cout <<"StHbtParticle---mHelixV0Pos->y==" << mHelixV0Pos.origin().y() << endl;
//   cout <<"StHbtParticle---mHelixV0Pos->z==" << mHelixV0Pos.origin().z() << endl;
//   cout <<"StHbtParticle---==PrimVtx" << mPrimaryVertex << endl;

  CalculateTpcExitAndEntrancePoints(&mHelixV0Pos,&mPrimaryVertex,&mTpcV0PosEntrancePoint,
				    &mTpcV0PosExitPoint,&mTpcV0PosPosSample[0],&mV0PosZ[0],
				    &mV0PosU[0],&mV0PosSect[0]);

  mHelixV0Neg = hbtV0->HelixNeg();
  CalculateTpcExitAndEntrancePoints(&mHelixV0Neg,&mPrimaryVertex,&mTpcV0NegEntrancePoint,
				    &mTpcV0NegExitPoint,&mTpcV0NegPosSample[0],&mV0NegZ[0],
				    &mV0NegU[0],&mV0NegSect[0]);
//   cout <<"StHbtParticle---==mTpcV0PosEntrancePoint" << mTpcV0PosEntrancePoint << endl;
//   cout <<"StHbtParticle---==mTpcV0PosExitPoint" << mTpcV0PosExitPoint << endl;
//   cout <<"StHbtParticle---==mTpcV0PosPosSample[0]" << mTpcV0PosPosSample[0] << endl;
//   cout <<"StHbtParticle---==mV0PosZ[0]" <<mV0PosZ[0]  << endl;
//   cout <<"StHbtParticle---==mV0PosU[0]" << mV0PosU[0] << endl;
//   cout <<"StHbtParticle---==mV0PosSect[0]" <<mV0PosSect[0]  << endl;

//   cout <<"StHbtParticle---==mTpcV0MegEntrancePoint" << mTpcV0NegEntrancePoint << endl;
//   cout <<"StHbtParticle---==mTpcV0MegExitPoint" << mTpcV0NegExitPoint << endl;
//   cout <<"StHbtParticle---==mTpcV0MegMegSample[0]" << mTpcV0NegPosSample[0] << endl;
//   cout <<"StHbtParticle---==mV0MegZ[0]" <<mV0NegZ[0]  << endl;
//   cout <<"StHbtParticle---==mV0MegU[0]" << mV0NegU[0] << endl;
//   cout <<"StHbtParticle---==mV0MegSect[0]" <<mV0NegSect[0]  << endl;

//   cout <<"StHbtParticle---FIN_V0" << endl;

}
//_____________________
StHbtParticle::StHbtParticle(const StHbtKink* const hbtKink,const double& mass) : mTrack(0), mV0(0) {
  mKink = new StHbtKink(*hbtKink);
  mMap[0]= 0;
  mMap[1]= 0;
  // I know there is a better way to do this...
  StHbtThreeVector temp = hbtKink->Parent().P();
  mFourMomentum.setVect(temp);
  double ener = sqrt(temp.mag2()+mass*mass);
  mFourMomentum.setE(ener);
}

//_____________________
StHbtParticle::StHbtParticle(const StHbtXi* const hbtXi, const double& mass){
  mXi = new StHbtXi(*hbtXi);
  mMap[0]= 0;
  mMap[1]= 0;
  StHbtThreeVector temp;// = hbtXi->mMomXi;
  mFourMomentum.setVect(temp);
  double ener = sqrt(temp.mag2()+mass*mass);
  mFourMomentum.setE(ener);
}
//_____________________
const StHbtThreeVector& StHbtParticle::NominalTpcExitPoint() const{
  // in future, may want to calculate this "on demand" only, sot this routine may get more sophisticated
  // for now, we calculate Exit and Entrance points upon instantiation
  return mNominalTpcExitPoint;
}
//_____________________
const StHbtThreeVector& StHbtParticle::NominalTpcEntrancePoint() const{
  // in future, may want to calculate this "on demand" only, sot this routine may get more sophisticated
  // for now, we calculate Exit and Entrance points upon instantiation
  return mNominalTpcEntrancePoint;
}
//_____________________
void StHbtParticle::CalculateNominalTpcExitAndEntrancePoints(){
  // this calculates the "nominal" exit point of a track, either through the endcap or through the Outer Field Cage
  // "nominal" means the track is assumed to start at (0,0,0)
  // it also calculates the "nominal" entrance point of the track, which is the point at which it crosses the
  // inner field cage
  static StHbtThreeVector ZeroVec(0.,0.,0.);
  double dip, curv, phase;
  int h;
  curv = mHelix.curvature();
  dip  = mHelix.dipAngle();
  phase= mHelix.phase();
  h    = mHelix.h();
  StHelixD hel(curv,dip,phase,ZeroVec,h);

  pairD candidates;
  double sideLength;  // this is how much length to go to leave through sides of TPC
  double endLength;  // this is how much length to go to leave through endcap of TPC
  // figure out how far to go to leave through side...
  candidates = hel.pathLength(200.0);  // bugfix MAL jul00 - 200cm NOT 2cm
  sideLength = (candidates.first > 0) ? candidates.first : candidates.second;

  static StHbtThreeVector WestEnd(0.,0.,200.);  // bugfix MAL jul00 - 200cm NOT 2cm
  static StHbtThreeVector EastEnd(0.,0.,-200.); // bugfix MAL jul00 - 200cm NOT 2cm
  static StHbtThreeVector EndCapNormal(0.,0.,1.0);

  endLength = hel.pathLength(WestEnd,EndCapNormal);
  if (endLength < 0.0) endLength = hel.pathLength(EastEnd,EndCapNormal);

  if (endLength < 0.0) cout << "StHbtParticle::CalculateNominalTpcExitAndEntrancePoints(): "
                            << "Hey-- I cannot find an exit point out endcaps" << endl;

  // OK, firstExitLength will be the shortest way out of the detector...
  double firstExitLength = (endLength < sideLength) ? endLength : sideLength;

  // now then, let's return the POSITION at which particle leaves TPC...
  mNominalTpcExitPoint = hel.at(firstExitLength);


  // Finally, calculate the position at which the track crosses the inner field cage
  candidates = hel.pathLength(50.0);  // bugfix MAL jul00 - 200cm NOT 2cm

  sideLength = (candidates.first > 0) ? candidates.first : candidates.second;
//   if (sideLength < 0.0)
//     {
//       cout 
//      << "no crossing with IFC" 
//      << " curve=" << curv 
//      << " candidates=" << candidates.first << " " << candidates.second 
//       << "origin=" << mHelix.origin() << " "<< dip << " " << phase << " " << h << endl;
//     }
//   else
//     {
//       cout 
//      << "does cross       IFC" 
//      << " curve=" << curv 
//      << " candidates=" << candidates.first << " " << candidates.second 
//      << "origin=" << mHelix.origin() << " "<< dip << " " << phase << " " << h << endl;
//     }


//   if (sideLength < 0.0)
//     {
//       if (phase > C_PI)
//      {
//        cout << "righto" << endl;
//      }
//       else
//      {
//        cout << "WRONGO!! 1 " << phase << endl;
//      }
//     }
//   else
//     {
//       if (phase > C_PI)
//      {
//        cout << "WRONGO!! 2 " << phase << endl;
//      }
//       else
//      {
//        cout << "righto " << endl;
//      }
//    }

  mNominalTpcEntrancePoint = hel.at(sideLength);


  // This is the secure way !  
//   if (isnan(mNominalTpcEntrancePoint.x()) || 
//       isnan(mNominalTpcEntrancePoint.x()) || 
//       isnan(mNominalTpcEntrancePoint.x()) ) mNominalTpcEntrancePoint = StHbtThreeVector(-9999.,-9999.,-9999); 
//   if (isnan(mNominalTpcExitPoint.x()) || 
//       isnan(mNominalTpcExitPoint.x()) || 
//       isnan(mNominalTpcExitPoint.x()) ) mNominalTpcExitPoint = StHbtThreeVector(-9999.,-9999.,-9999); 

  // This is faster  
  if (isnan(mNominalTpcExitPoint.x())) mNominalTpcExitPoint = StHbtThreeVector(-9999.,-9999.,-9999); 


  // 03Oct00 - mal.  OK, let's try something a little more along the lines of NA49 and E895 strategy.
  //    calculate the "nominal" position at N radii (say N=11) within the TPC, and for a pair cut
  //    use the average separation of these N
  for (int irad=0; irad<11; irad++){
    float radius = 50.0 + irad*15.0;
    candidates = hel.pathLength(radius);
    sideLength = (candidates.first > 0) ? candidates.first : candidates.second;
    mNominalPosSample[irad] = hel.at(sideLength);
  }



  static double tSectToPhi[24]={2.,1.,0.,11.,10.,9.,8. ,7. ,6.,5.,4.,3.,
				4.,5.,6., 7., 8.,9.,10.,11.,0.,1.,2.,3.};
  static float tRowRadius[45] = {60,64.8,69.6,74.4,79.2,84,88.8,93.6,98.8, 
				 104,109.2,114.4,119.6,127.195,129.195,131.195,
				 133.195,135.195,137.195,139.195,141.195,
				 143.195,145.195,147.195,149.195,151.195,
				 153.195,155.195,157.195,159.195,161.195,
				 163.195,165.195,167.195,169.195,171.195,
				 173.195,175.195,177.195,179.195,181.195,
				 183.195,185.195,187.195,189.195};
  int tRow,tSect,tOutOfBound;
  double tU,tLength,tPhi;
  StHbtThreeVector tPoint;
  StThreeVectorD tn(0,0,0);
  StThreeVectorD tr(0,0,0);
  for(int ti=0;ti<45;ti++){
    // Find which sector it is on
    candidates =  hel.pathLength(tRowRadius[ti]);
    tLength = (candidates.first > 0) ? candidates.first : candidates.second;
    tPoint = hel.at(tLength);
    TpcLocalTransform(tPoint,mSect[ti],tRow,tU,tPhi);
    // calculate crossing plane
    //tPhi = tSectToPhi[mSect[ti]-1]*TMath::Pi()/6.;
    tn.setX(cos(tPhi));
    tn.setY(sin(tPhi));       
    tr.setX(tRowRadius[ti]*cos(tPhi));
    tr.setY(tRowRadius[ti]*sin(tPhi));
    // find crossing point
    tLength = hel.pathLength(tr,tn);
    tPoint = hel.at(tLength);
    mZ[ti] = tPoint.z();
    tOutOfBound = TpcLocalTransform(tPoint,tSect,tRow,mU[ti],tPhi);
    if(tOutOfBound || (mSect[ti] == tSect && tRow!=(ti+1))){
      //cout << "Out of bound " << tOutOfBound2 << " " << tOutOfBound << " " 
      //   << tSect << " " << mSect[ti] << " "
      //   << ti+1 << " " << tRow << " " << tRowRadius[ti] << " " 
      //   << tU << " " << mU[ti] << endl;
      mSect[ti]=-1;
    }
    else{
      if(mSect[ti] != tSect){
	// Try again on the other sector
	tn.setX(cos(tPhi));
	tn.setY(sin(tPhi));       
	tr.setX(tRowRadius[ti]*cos(tPhi));
	tr.setY(tRowRadius[ti]*sin(tPhi));
	// find crossing point
	tLength = hel.pathLength(tr,tn);
	tPoint = hel.at(tLength);
	mZ[ti] = tPoint.z();
	mSect[ti] = tSect;
	tOutOfBound = TpcLocalTransform(tPoint,tSect,tRow,mU[ti],tPhi);
	if(tOutOfBound || tSect!= mSect[ti] || tRow!=(ti+1)){
	  mSect[ti]=-1;
	  //cout << "Twice bad : OutOfBound =  " << tOutOfBound 
	  //   << " SectOk = " << (tSect!= mSect[ti])
	  //   << " RowOk = " <<  (tRow!=(ti+1)) << endl;
	}
      }
    }
  }
}
//_____________________
void StHbtParticle::CalculateTpcExitAndEntrancePoints( const StPhysicalHelixD* tHelix,
						       StHbtThreeVector*  PrimVert,
						       StHbtThreeVector* tmpTpcEntrancePoint,
						       StHbtThreeVector* tmpTpcExitPoint,
						       StHbtThreeVector* tmpPosSample,
						       double* tmpZ,double* tmpU,int* tmpSect){
  // this calculates the exit point of a secondary track, 
  // either through the endcap or through the Outer Field Cage
  // We assume the track to start at tHelix.origin-PrimaryVertex
  // it also calculates the entrance point of the secondary track, 
  // which is the point at which it crosses the
  // inner field cage
  //  static StHbtThreeVector ZeroVec(0.,0.,0.);
  StHbtThreeVector ZeroVec(0.,0.,0.);
  ZeroVec.setX(tHelix->origin().x()-PrimVert->x());
  ZeroVec.setY(tHelix->origin().y()-PrimVert->y());
  ZeroVec.setZ(tHelix->origin().z()-PrimVert->z());
  double dip, curv, phase;
  int h;
  curv = tHelix->curvature();
  dip  = tHelix->dipAngle();
  phase= tHelix->phase();
  h    = tHelix->h();
  
  StHelixD hel(curv,dip,phase,ZeroVec,h);

  pairD candidates;
  double sideLength;  // this is how much length to go to leave through sides of TPC
  double endLength;  // this is how much length to go to leave through endcap of TPC
  // figure out how far to go to leave through side...
  candidates = hel.pathLength(200.0);  // bugfix MAL jul00 - 200cm NOT 2cm
  sideLength = (candidates.first > 0) ? candidates.first : candidates.second;

  static StHbtThreeVector WestEnd(0.,0.,200.);  // bugfix MAL jul00 - 200cm NOT 2cm
  static StHbtThreeVector EastEnd(0.,0.,-200.); // bugfix MAL jul00 - 200cm NOT 2cm
  static StHbtThreeVector EndCapNormal(0.,0.,1.0);

  endLength = hel.pathLength(WestEnd,EndCapNormal);
  if (endLength < 0.0) endLength = hel.pathLength(EastEnd,EndCapNormal);

  if (endLength < 0.0) cout << "StHbtParticle::CalculateTpcExitAndEntrancePoints(): "
                            << "Hey -- I cannot find an exit point out endcaps" << endl;

  // OK, firstExitLength will be the shortest way out of the detector...
  double firstExitLength = (endLength < sideLength) ? endLength : sideLength;

  // now then, let's return the POSITION at which particle leaves TPC...
  *tmpTpcExitPoint = hel.at(firstExitLength);

  // Finally, calculate the position at which the track crosses the inner field cage
  candidates = hel.pathLength(50.0);  // bugfix MAL jul00 - 200cm NOT 2cm

  sideLength = (candidates.first > 0) ? candidates.first : candidates.second;

  *tmpTpcEntrancePoint = hel.at(sideLength);

  if (isnan(tmpTpcExitPoint->x())) *tmpTpcExitPoint = StHbtThreeVector(-9999.,-9999.,-9999); 


  // 03Oct00 - mal.  OK, let's try something a little more 
  // along the lines of NA49 and E895 strategy.
  // calculate the "nominal" position at N radii (say N=11) 
  // within the TPC, and for a pair cut
  // use the average separation of these N
  for (int irad=0; irad<11; irad++){
    float radius = 50.0 + irad*15.0;
    candidates = hel.pathLength(radius);
    sideLength = (candidates.first > 0) ? candidates.first : candidates.second;
    //    cout <<"StHbtParticle==sideLength==" << sideLength<< endl;
    tmpPosSample[irad] = hel.at(sideLength);
  }

  static float tRowRadius[45] = {60,64.8,69.6,74.4,79.2,84,88.8,93.6,98.8, 
				 104,109.2,114.4,119.6,127.195,129.195,131.195,
				 133.195,135.195,137.195,139.195,141.195,
				 143.195,145.195,147.195,149.195,151.195,
				 153.195,155.195,157.195,159.195,161.195,
				 163.195,165.195,167.195,169.195,171.195,
				 173.195,175.195,177.195,179.195,181.195,
				 183.195,185.195,187.195,189.195};
  int tRow,tSect,tOutOfBound;
  double tU,tLength,tPhi;
  StHbtThreeVector tPoint;
  StThreeVectorD tn(0,0,0);
  StThreeVectorD tr(0,0,0);
  for(int ti=0;ti<45;ti++){
    // Find which sector it is on
    candidates =  hel.pathLength(tRowRadius[ti]);
    tLength = (candidates.first > 0) ? candidates.first : candidates.second;
    tPoint = hel.at(tLength);
    TpcLocalTransform(tPoint,tmpSect[ti],tRow,tU,tPhi);
    // calculate crossing plane
    //tPhi = tSectToPhi[tmpSect[ti]-1]*TMath::Pi()/6.;
    tn.setX(cos(tPhi));
    tn.setY(sin(tPhi));       
    tr.setX(tRowRadius[ti]*cos(tPhi));
    tr.setY(tRowRadius[ti]*sin(tPhi));
    // find crossing point
    tLength = hel.pathLength(tr,tn);
    tPoint = hel.at(tLength);
    tmpZ[ti] = tPoint.z();
    tOutOfBound = TpcLocalTransform(tPoint,tSect,tRow,tmpU[ti],tPhi);
    if(tOutOfBound || (tmpSect[ti] == tSect && tRow!=(ti+1))){
      tmpSect[ti]=-1;
    }
    else{
      if(tmpSect[ti] != tSect){
	// Try again on the other sector
	tn.setX(cos(tPhi));
	tn.setY(sin(tPhi));       
	tr.setX(tRowRadius[ti]*cos(tPhi));
	tr.setY(tRowRadius[ti]*sin(tPhi));
	// find crossing point
	tLength = hel.pathLength(tr,tn);
	tPoint = hel.at(tLength);
	tmpZ[ti] = tPoint.z();
	tmpSect[ti] = tSect;
	tOutOfBound = TpcLocalTransform(tPoint,tSect,tRow,tmpU[ti],tPhi);
	if(tOutOfBound || tSect!= tmpSect[ti] || tRow!=(ti+1)){
	  tmpSect[ti]=-1;
	}
      }
    }
  }
}
//_____________________
const StHbtThreeVector& StHbtParticle::TpcV0PosExitPoint() const{
  return mTpcV0PosExitPoint;
}
//_____________________
const StHbtThreeVector& StHbtParticle::TpcV0PosEntrancePoint() const{
  return mTpcV0PosEntrancePoint;
}
//______________________
const StHbtThreeVector& StHbtParticle::TpcV0NegExitPoint() const{
  return mTpcV0NegExitPoint;
}
//_____________________
const StHbtThreeVector& StHbtParticle::TpcV0NegEntrancePoint() const{
  return mTpcV0NegEntrancePoint;
}
//______________________
