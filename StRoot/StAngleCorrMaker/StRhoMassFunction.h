#ifndef StRhoMassFunction_HH
#define StRhoMassFunction_HH

///////////////////////////////////////////////////////////////////////////////
//
// StRhoMassFunction
//
// Description: 
//
// Environment:
//  Software developed for the STAR Detector at Brookhaven National Laboratory
//
// Author List: 
//  Craig Ogilvie, MIT
//  Matt Horsley,  YALE
// History:
//
///////////////////////////////////////////////////////////////////////////////

#include "StTrackForPool.h"
#include "StAngleCorrFunction.h"
#include <TH1.h>


class StRhoMassFunction: public StAngleCorrFunction {
public:
          ~StRhoMassFunction();
  void    Fill(StTrackForPool* t1, StTrackForPool* t2, TH1D* hist);
  TString GetName();
private:

Double_t correlation,weight;
Double_t p1,p2;
Double_t px1,py1,pz1;
Double_t px2,py2,pz2;
  
};

#endif
