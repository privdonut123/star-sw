// $Id: StFtpcSlowSimCluster.hh,v 1.3 2002/06/07 09:55:41 fsimon Exp $
// $Log: StFtpcSlowSimCluster.hh,v $
// Revision 1.3  2002/06/07 09:55:41  fsimon
// Additional debug info to trace electron drift
//
// Revision 1.2  2001/03/06 23:35:58  jcs
// use database instead of params
//
// Revision 1.1  2000/11/23 10:16:43  hummler
// New FTPC slow simulator in pure maker form
//
//
///////////////////////////////////////////////////////////////////////////
//  Author: W.G.Gong
//  Email: gong@mppmu.mpg.de
//  Date:  Oct 25, 1996
///////////////////////////////////////////////////////////////////////////
#ifndef STAR_StFtpcSlowSimCluster
#define STAR_StFtpcSlowSimCluster

#include "math.h"

class StFtpcSlowSimField;
class StFtpcParamReader;
class StFtpcDbReader;

//
//  class cluster will diffuse and drift a cluster of electrons 
//  generated by ionization
//
class StFtpcSlowSimCluster
{
public:
  
  StFtpcSlowSimCluster(StFtpcParamReader *paramReader,
                       StFtpcDbReader *dbReader,
		       StFtpcSlowSimField *field,
		       const float el, const float rad_offset, 
		       const float pad_offset, const float r, 
		       const float ph, const float time, 
		       const int call_padrow);		
                                // constructor
  ~StFtpcSlowSimCluster();     // destructor
  
  void DriftDiffuse(StFtpcSlowSimField  *field);	
                                // drift&diffuse in radial/azimuthal dir.
  
  void Print() const;
  float GetElectron() const  {return electron;}   
                                // get the number of electrons
  float GetSigRad() const    {return sqrt(sigma_rad_squared);}
                                // get the radial sigma
  float GetSigPhi() const    {return sqrt(sigma_phi_squared);}
                                // get the azimuthal sigma
  float GetRadOff() const    { return radialDipWidth;}
                                // get the radial dip width
  float GetPadOff() const    {return azimuthalCrossWidth;}
                                // get the azimuthal crossing width
  float GetRad() const       {return currentRadius;}
                                // get the radial position
  float GetPhi() const    {return currentPhi;}   
                                // get the azimuthal position
  float GetDriftTime() const {return drift_time;}
                                // get the accumulated drift time in usec
  
private:
  int mIntDiffCoarseness;//number of steps skipped by diffusion
  float mFlDiffCoarseness;// correction for skipped steps;
  float outerRadius;    // limit of drift range
  float deltaRadius;    // delta radius in one drift step
  float twoDeltaRadius; // 2*deltaRadius
  float electron;	// number of electrons in a cluster
  float electronLoss;   // gas attenuation per drift step
  float sigma_rad_squared; // sigma width in radial dir squared
  float sigma_phi_squared; // sigma width in azimuthal dir sq
  float radialDipWidth; // radial dip width
  float azimuthalCrossWidth; // azimuthal crossing width
  float currentRadius;	// radial position in cm 
  float currentPhi;	// azimuthal position in deg
  float drift_time;	// accumulated drift time in usec.
  int padrow;           // self-explanatory (needed for drift field)
  int original_padrow;   // only for debug output


};

#endif





