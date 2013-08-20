// $Id: AliHLTTPCCATrackParamVector.cxx,v 1.4 2013/08/20 16:05:09 fisyak Exp $
// **************************************************************************
// This file is property of and copyright by the ALICE HLT Project          *
// ALICE Experiment at CERN, All rights reserved.                           *
//                                                                          *
// Primary Authors: Sergey Gorbunov <sergey.gorbunov@kip.uni-heidelberg.de> *
//                  Ivan Kisel <kisel@kip.uni-heidelberg.de>                *
//                  for The ALICE HLT Project.                              *
//                                                                          *
// Developed by:   Igor Kulakov <I.Kulakov@gsi.de>                          *
//                 Maksym Zyzak <M.Zyzak@gsi.de>                            *
//                                                                          *
// Permission to use, copy, modify and distribute this software and its     *
// documentation strictly for non-commercial purposes is hereby granted     *
// without fee, provided that the above copyright notice appears in all     *
// copies and that both the copyright notice and this permission notice     *
// appear in the supporting documentation. The authors make no claims       *
// about the suitability of this software for any purpose. It is            *
// provided "as is" without express or implied warranty.                    *
//                                                                          *
//***************************************************************************


#include "AliHLTTPCCATrackParamVector.h"
#include "AliHLTTPCCAMath.h"
#include "AliHLTTPCCATrackLinearisationVector.h"
#include <iostream>
#include <iomanip>
#ifndef NVALGRIND 
#include <valgrind/memcheck.h>
#endif
#include <assert.h>
#include "debug.h"

//
// Circle in XY:
//
// kCLight = 0.000299792458;
// Kappa = Bz*kCLight*QPt;
// R  = 1/CAMath::Abs(Kappa);
// Xc = X - sin(Phi)/Kappa;
// Yc = Y + cos(Phi)/Kappa;
//

sfloat_v AliHLTTPCCATrackParamVector::GetDist2( const AliHLTTPCCATrackParamVector &t ) const
{
  // get squared distance between tracks

  const sfloat_v &dx = GetX() - t.GetX();
  const sfloat_v &dy = GetY() - t.GetY();
  const sfloat_v &dz = GetZ() - t.GetZ();
  return dx*dx + dy*dy + dz*dz;
}

sfloat_v AliHLTTPCCATrackParamVector::GetDistXZ2( const AliHLTTPCCATrackParamVector &t ) const
{
  // get squared distance between tracks in X&Z

  const sfloat_v &dx = GetX() - t.GetX();
  const sfloat_v &dz = GetZ() - t.GetZ();
  return dx*dx + dz*dz;
}


sfloat_v  AliHLTTPCCATrackParamVector::GetS( const sfloat_v &_x, const sfloat_v &_y, const sfloat_v &Bz ) const
{
  //* Get XY path length to the given point

  const sfloat_v &k  = GetKappa( Bz );
  const sfloat_v &ex = GetCosPhi();
  const sfloat_v &ey = GetSinPhi();
  const sfloat_v &x = _x - GetX();
  const sfloat_v &y = _y - GetY();
  sfloat_v dS = x * ex + y * ey;
  const sfloat_m &mask = CAMath::Abs( k ) > 1.e-4;
  if ( !mask.isEmpty() ) {
    dS( mask ) = CAMath::ATan2( k * dS, 1 + k * ( x * ey - y * ex ) ) / k;
  }
  return dS;
}

void  AliHLTTPCCATrackParamVector::GetDCAPoint( const sfloat_v &x, const sfloat_v &y, const sfloat_v &z,
    sfloat_v *xp, sfloat_v *yp, sfloat_v *zp, const sfloat_v &Bz ) const
{
  //* Get the track point closest to the (x,y,z)

  const sfloat_v &x0 = GetX();
  const sfloat_v &y0 = GetY();
  const sfloat_v &k  = GetKappa( Bz );
  const sfloat_v &ex = GetCosPhi();
  const sfloat_v &ey = GetSinPhi();
  const sfloat_v &dx = x - x0;
  const sfloat_v &dy = y - y0;
  const sfloat_v &ax = dx * k + ey;
  const sfloat_v &ay = dy * k - ex;
  const sfloat_v &a = sqrt( ax * ax + ay * ay );
  *xp = x0 + ( dx - ey * ( ( dx * dx + dy * dy ) * k - 2.f * ( -dx * ey + dy * ex ) ) / ( a + 1.f ) ) / a;
  *yp = y0 + ( dy + ex * ( ( dx * dx + dy * dy ) * k - 2.f * ( -dx * ey + dy * ex ) ) / ( a + 1.f ) ) / a;
  const sfloat_v s = GetS( x, y, Bz );
  *zp = GetZ() + GetDzDs() * s;
  const sfloat_v dZ = CAMath::Abs( GetDzDs() * CAMath::TwoPi() / k );
  const sfloat_m mask = CAMath::Abs( k ) > 1.e-2f && dZ > .1f;
  ( *zp )( mask ) += CAMath::Round( ( z - *zp ) / dZ ) * dZ;
}


//*
//* Transport routines
//*


sfloat_m AliHLTTPCCATrackParamVector::TransportToX( const sfloat_v &x, AliHLTTPCCATrackLinearisationVector &t0, const sfloat_v &Bz,  const float maxSinPhi, sfloat_v *DL, const sfloat_m &_mask )
{
  //* Transport the track parameters to X=x, using linearization at t0, and the field value Bz
  //* maxSinPhi is the max. allowed value for |t0.SinPhi()|
  //* linearisation of trajectory t0 is also transported to X=x,
  //* returns 1 if OK
  //*

  debugKF() << "Start TransportToX(" << x << ", " << _mask << ")\n" << *this << std::endl;
  assert( ( x == 0 && _mask ).isEmpty() );
  const sfloat_v ex = t0.CosPhi();
  const sfloat_v ey = t0.SinPhi();
  const sfloat_v k  = t0.QPt() * Bz;
  const sfloat_v dx = x - X();

  sfloat_v ey1 = k * dx + ey;

  // check for intersection with X=x


  sfloat_v ex1 = CAMath::Sqrt( 1.f - ey1 * ey1 );
  ex1( ex < Vc::Zero ) = -ex1;

  const sfloat_v dx2 = dx * dx;
  const sfloat_v ss = ey + ey1;
  const sfloat_v cc = ex + ex1;

  sfloat_m mask = _mask && CAMath::Abs( ey1 ) <= maxSinPhi && CAMath::Abs( cc ) >= 1.e-4f && CAMath::Abs( ex ) >= 1.e-4f && CAMath::Abs( ex1 ) >= 1.e-4f;

  // TODO: change to CAMath::Reciprocal(..)
  sfloat_v cci  = 1.f / cc;
  sfloat_v exi  = 1.f / ex;
  sfloat_v ex1i = 1.f / ex1;

  const sfloat_v tg = ss * cci; // tan((phi1+phi)/2)

  const sfloat_v dy = dx * tg;
  sfloat_v dl = dx * CAMath::Sqrt( 1.f + tg * tg );
  dl( cc < Vc::Zero ) = -dl;

  const sfloat_v dSin = CAMath::Max( sfloat_v( -1.f ), CAMath::Min( sfloat_v( Vc::One ), dl * k * 0.5f ) );
  const sfloat_v dS = ( CAMath::Abs( k ) > 1.e-4 )  ? ( 2 * CAMath::ASin( dSin ) / k ) : dl;
  const sfloat_v dz = dS * t0.DzDs();

  if ( DL ) {
    ( *DL )( mask ) = -dS * CAMath::Sqrt( 1.f + t0.DzDs() * t0.DzDs() );
  }

  const sfloat_v d[5] = {
    0.f,
    0.f,
    fP[2] - t0.SinPhi(),
    fP[3] - t0.DzDs(),
    fP[4] - t0.QPt()
  };

  const sfloat_v h2 = dx * ( 1 + ey * ey1 + ex * ex1 ) * exi * ex1i * cci;
  const sfloat_v h4 = dx2 * ( cc + ss * ey1 * ex1i ) * cci * cci * Bz;
  const sfloat_v dxBz = dx * Bz;

  ex1( !mask ) = ex;
  ey1( !mask ) = ey;
  t0.SetCosPhi( ex1 );
  t0.SetSinPhi( ey1 );

  fX   ( mask ) += dx;
  fP[0]( mask ) += dy     + h2 * d[2]           +   h4 * d[4];
  fP[1]( mask ) += dz               + dS * d[3];
  fP[2]( mask )  = t0.SinPhi() +     d[2]           + dxBz * d[4];

  const sfloat_v c00 = fC[0];
  const sfloat_v c10 = fC[1];
  const sfloat_v c11 = fC[2];
  const sfloat_v c20 = fC[3];
  const sfloat_v c21 = fC[4];
  const sfloat_v c22 = fC[5];
  const sfloat_v c30 = fC[6];
  const sfloat_v c31 = fC[7];
  const sfloat_v c32 = fC[8];
  const sfloat_v c33 = fC[9];
  const sfloat_v c40 = fC[10];
  const sfloat_v c41 = fC[11];
  const sfloat_v c42 = fC[12];
  const sfloat_v c43 = fC[13];
  const sfloat_v c44 = fC[14];

  fC[0] ( mask ) = ( c00  + h2 * h2 * c22 + h4 * h4 * c44
                     + 2.f * ( h2 * c20 + h4 * c40 + h2 * h4 * c42 )  );

  fC[1] ( mask ) = c10 + h2 * c21 + h4 * c41 + dS * ( c30 + h2 * c32 + h4 * c43 );
  fC[2] ( mask ) = c11 + 2.f * dS * c31 + dS * dS * c33;

  fC[3] ( mask ) = c20 + h2 * c22 + h4 * c42 + dxBz * ( c40 + h2 * c42 + h4 * c44 );
  fC[4] ( mask ) = c21 + dS * c32 + dxBz * ( c41 + dS * c43 );
  fC[5] ( mask ) = c22 + 2.f * dxBz * c42 + dxBz * dxBz * c44;

  fC[6] ( mask ) = c30 + h2 * c32 + h4 * c43;
  fC[7] ( mask ) = c31 + dS * c33;
  fC[8] ( mask ) = c32 + dxBz * c43;
  fC[9] ( mask ) = c33;

  fC[10]( mask ) = c40 + h2 * c42 + h4 * c44;
  fC[11]( mask ) = c41 + dS * c43;
  fC[12]( mask ) = c42 + dxBz * c44;
  fC[13]( mask ) = c43;
  fC[14]( mask ) = c44;

  debugKF() << mask << "\n" << *this << std::endl;
  return mask;
}


sfloat_m AliHLTTPCCATrackParamVector::TransportToX( const sfloat_v &x, const sfloat_v &Bz,
    const float maxSinPhi, const sfloat_m &mask )
{
  //* Transport the track parameters to X=x

  assert( ( x == 0 && mask ).isEmpty() );

  AliHLTTPCCATrackLinearisationVector t0( *this );

  return TransportToX( x, t0, Bz, maxSinPhi, 0, mask );
}



sfloat_m AliHLTTPCCATrackParamVector::TransportToXWithMaterial( const sfloat_v &x,  AliHLTTPCCATrackLinearisationVector &t0, AliHLTTPCCATrackFitParam &par, const sfloat_v &Bz, const float maxSinPhi )
{
  //* Transport the track parameters to X=x  taking into account material budget

  const float kRho = 1.025e-3f;//0.9e-3;
  const float kRadLen = 29.532f;//28.94;
  const float kRhoOverRadLen = kRho / kRadLen;
  sfloat_v dl;

  const sfloat_m &mask = TransportToX( x, t0, Bz,  maxSinPhi, &dl );
  if ( !mask.isEmpty() ) {
    CorrectForMeanMaterial( dl * kRhoOverRadLen, dl * kRho, par, mask );
  }

  return mask;
}


sfloat_m AliHLTTPCCATrackParamVector::TransportToXWithMaterial( const sfloat_v &x,  AliHLTTPCCATrackFitParam &par, const sfloat_v &Bz, const float maxSinPhi )
{
  //* Transport the track parameters to X=x  taking into account material budget

  AliHLTTPCCATrackLinearisationVector t0( *this );
  return TransportToXWithMaterial( x, t0, par, Bz, maxSinPhi );
}

sfloat_m AliHLTTPCCATrackParamVector::TransportToXWithMaterial( const sfloat_v &x, const sfloat_v &Bz, const float maxSinPhi )
{
  //* Transport the track parameters to X=x taking into account material budget

  AliHLTTPCCATrackFitParam par;
  CalculateFitParameters( par );
  return TransportToXWithMaterial( x, par, Bz, maxSinPhi );
}


//*
//*  Multiple scattering and energy losses
//*


sfloat_v AliHLTTPCCATrackParamVector::BetheBlochGeant( const sfloat_v &bg2,
    const sfloat_v &kp0,
    const sfloat_v &kp1,
    const sfloat_v &kp2,
    const sfloat_v &kp3,
    const sfloat_v &kp4 )
{
  //
  // This is the parameterization of the Bethe-Bloch formula inspired by Geant.
  //
  // bg2  - (beta*gamma)^2
  // kp0 - density [g/cm^3]
  // kp1 - density effect first junction point
  // kp2 - density effect second junction point
  // kp3 - mean excitation energy [GeV]
  // kp4 - mean Z/A
  //
  // The default values for the kp* parameters are for silicon.
  // The returned value is in [GeV/(g/cm^2)].
  //

  const float mK  = 0.307075e-3f; // [GeV*cm^2/g]
  const float _2me  = 1.022e-3f;    // [GeV/c^2]
  const sfloat_v &rho = kp0;
  const sfloat_v &x0  = kp1 * 2.303f;
  const sfloat_v &x1  = kp2 * 2.303f;
  const sfloat_v &mI  = kp3;
  const sfloat_v &mZA = kp4;
  const sfloat_v &maxT = _2me * bg2;    // neglecting the electron mass

  //*** Density effect
  sfloat_v d2( Vc::Zero );
  const sfloat_v x = 0.5f * CAMath::Log( bg2 );
  const sfloat_v lhwI = CAMath::Log( 28.816f * 1e-9f * CAMath::Sqrt( rho * mZA ) / mI );
  d2( x > x1 ) = lhwI + x - 0.5;
  const sfloat_v &r = ( x1 - x ) / ( x1 - x0 );
  d2( x > x0 && x <= x1 ) = lhwI + x - 0.5 + ( 0.5 - lhwI - x0 ) * r * r * r;

  return mK*mZA*( sfloat_v( Vc::One ) + bg2 ) / bg2*( 0.5f*CAMath::Log( maxT * maxT / ( mI*mI ) ) - bg2 / ( sfloat_v( Vc::One ) + bg2 ) - d2 );
}

sfloat_v AliHLTTPCCATrackParamVector::BetheBlochSolid( const sfloat_v &bg )
{
  //------------------------------------------------------------------
  // This is an approximation of the Bethe-Bloch formula,
  // reasonable for solid materials.
  // All the parameters are, in fact, for Si.
  // The returned value is in [GeV]
  //------------------------------------------------------------------

  return BetheBlochGeant( bg );
}

sfloat_v AliHLTTPCCATrackParamVector::BetheBlochGas( const sfloat_v &bg )
{
  //------------------------------------------------------------------
  // This is an approximation of the Bethe-Bloch formula,
  // reasonable for gas materials.
  // All the parameters are, in fact, for Ne.
  // The returned value is in [GeV]
  //------------------------------------------------------------------

  const sfloat_v rho = 0.9e-3f;
  const sfloat_v x0  = 2.f;
  const sfloat_v x1  = 4.f;
  const sfloat_v mI  = 140.e-9f;
  const sfloat_v mZA = 0.49555f;

  return BetheBlochGeant( bg, rho, x0, x1, mI, mZA );
}




sfloat_v AliHLTTPCCATrackParamVector::ApproximateBetheBloch( const sfloat_v &beta2 )
{
  //------------------------------------------------------------------
  // This is an approximation of the Bethe-Bloch formula with
  // the density effect taken into account at beta*gamma > 3.5
  // (the approximation is reasonable only for solid materials)
  //------------------------------------------------------------------

  const sfloat_v &beta2_1subBeta2 = beta2 / ( sfloat_v( Vc::One ) - beta2 ); // beta2 * CAMath::Reciprocal( sfloat_v( Vc::One ) - beta2 );
  const sfloat_v &_0p000153_beta2 = 0.153e-3f / beta2;
  const float log_3p5mul5940 = 9.942227380852058f; // log( 3.5 * 5940 )
  const float log_5940 = 8.68946441235669f; // log( 5940 )
  const sfloat_v &log_beta2_1subBeta2 = CAMath::Log( beta2_1subBeta2 );

  sfloat_v ret = _0p000153_beta2 * ( log_5940 + log_beta2_1subBeta2 - beta2 );
  ret( beta2_1subBeta2 > 3.5f*3.5f ) =
    _0p000153_beta2 * ( log_3p5mul5940 + 0.5f * log_beta2_1subBeta2 - beta2 );
  ret.setZero( beta2 >= sfloat_v( Vc::One ) );
  return ret;
}


void AliHLTTPCCATrackParamVector::CalculateFitParameters( AliHLTTPCCATrackFitParam &par, const sfloat_v &mass )
{
  //*!

  const sfloat_v p2 = ( sfloat_v( Vc::One ) + fP[3] * fP[3] );
  const sfloat_v k2 = fP[4] * fP[4];
  const sfloat_v mass2 = mass * mass;
  const sfloat_v beta2 = p2 / ( p2 + mass2 * k2 );

  sfloat_v pp2 = 10000.f; pp2( k2 > 1.e-8f ) = p2 / k2; // impuls 2

  //par.fBethe = BetheBlochGas( pp2/mass2);
  par.fBethe = ApproximateBetheBloch( pp2 / mass2 );
  par.fE = CAMath::Sqrt( pp2 + mass2 );
  par.fTheta2 = 14.1f * 14.1f / ( beta2 * pp2 * 1.e6f );
  par.fEP2 = par.fE / pp2;

  // Approximate energy loss fluctuation (M.Ivanov)

  const float knst = 0.07f; // To be tuned.
  par.fSigmadE2 = knst * par.fEP2 * fP[4];
  par.fSigmadE2 = par.fSigmadE2 * par.fSigmadE2;

  par.fK22 = ( sfloat_v( Vc::One ) + fP[3] * fP[3] );
  par.fK33 = par.fK22 * par.fK22;
  par.fK43 = fP[3] * fP[4] * par.fK22;
  par.fK44 = fP[3] * fP[3] * fP[4] * fP[4];
}


sfloat_m AliHLTTPCCATrackParamVector::CorrectForMeanMaterial( const sfloat_v &xOverX0,  const sfloat_v &xTimesRho, const AliHLTTPCCATrackFitParam &par, const sfloat_m &_mask )
{
  //------------------------------------------------------------------
  // This function corrects the track parameters for the crossed material.
  // "xOverX0"   - X/X0, the thickness in units of the radiation length.
  // "xTimesRho" - is the product length*density (g/cm^2).
  //------------------------------------------------------------------

  sfloat_v &fC22 = fC[5];
  sfloat_v &fC33 = fC[9];
  sfloat_v &fC40 = fC[10];
  sfloat_v &fC41 = fC[11];
  sfloat_v &fC42 = fC[12];
  sfloat_v &fC43 = fC[13];
  sfloat_v &fC44 = fC[14];

  //Energy losses************************

  const sfloat_v &dE = par.fBethe * xTimesRho;
  sfloat_m mask = _mask && CAMath::Abs( dE ) <= 0.3f * par.fE; //30% energy loss is too much!
  const sfloat_v &corr = ( sfloat_v( Vc::One ) - par.fEP2 * dE );
  mask &= corr >= 0.3f && corr <= 1.3f;

  fP[4]( mask ) *= corr;
  fC40 ( mask ) *= corr;
  fC41 ( mask ) *= corr;
  fC42 ( mask ) *= corr;
  fC43 ( mask ) *= corr;
  fC44 ( mask ) *= corr * corr;
  fC44 ( mask ) += par.fSigmadE2 * CAMath::Abs( dE );

  //Multiple scattering******************

  const sfloat_v &theta2 = par.fTheta2 * CAMath::Abs( xOverX0 );
  fC22( mask ) += theta2 * par.fK22 * ( sfloat_v( Vc::One ) - fP[2] * fP[2] );
  fC33( mask ) += theta2 * par.fK33;
  fC43( mask ) += theta2 * par.fK43;
  fC44( mask ) += theta2 * par.fK44;

  return mask;
}

#include <iostream>

std::istream &operator>>( std::istream &in, AliHLTTPCCATrackParamVector &t )
{
  sfloat_v::Memory x, s, p[5], c[15], chi2;
  short_v::Memory ndf;
  for ( int j = 0; j < ushort_v::Size; ++j ) {
    in >> x[j];
    in >> s[j];
    for ( int i = 0; i < 5; i++ ) in >> p[i][j];
    for ( int i = 0; i < 15; i++ ) in >> c[i][j];
    in >> chi2[j];
    in >> ndf[j];
  }
  t.fX.load( x );
  t.fSignCosPhi.load( s );
  for ( int i = 0; i < 5; i++ ) t.fP[i].load( p[i] );
  for ( int i = 0; i < 5; i++ ) t.fC[i].load( c[i] );
  t.fChi2.load( chi2 );
  t.fNDF.load( ndf );
  return in;
}

std::ostream &operator<<( std::ostream &out, const AliHLTTPCCATrackParamVector &t )
{
  if ( out == std::cerr ) {
    out << "------------------------------ Track Param ------------------------------"
        << "\n             X: " << t.X()
        << "\n    SignCosPhi: " << t.SignCosPhi()
        << "\n          Chi2: " << t.Chi2()
        << "\n           NDF: " << t.NDF()
        << "\n             Y: " << t.Par()[0]
        << "\n             Z: " << t.Par()[1]
        << "\n        SinPhi: " << t.Par()[2]
        << "\n          DzDs: " << t.Par()[3]
        << "\n          q/Pt: " << t.Par()[4]
        << "\nCovariance Matrix\n";
    int i = 0;
    out << std::setprecision( 2 );
    for ( int step = 1; step <= 5; ++step ) {
      int end = i + step;
      for ( ; i < end; ++i ) {
        out << t.Cov()[i] << '\t';
      }
      out << "\n";
    }
    out << std::setprecision( 6 );
    return out << std::endl;
  }
  for ( int j = 0; j < ushort_v::Size; ++j ) {
    out << t.X()[j] << " "
        << t.SignCosPhi()[j] << " "
        << t.Chi2()[j] << " "
        << t.NDF()[j]
        << std::endl;
    for ( int i = 0; i < 5; i++ ) out << t.Par()[i][j] << " ";
    out << std::endl;
    for ( int i = 0; i < 15; i++ ) out << t.Cov()[i][j] << " ";
    out << std::endl;
  }
  return out;
}
