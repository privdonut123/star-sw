//////////////////////////////////////////////////////////////////////////
//
// StEmcPmtSimulator.h 
//
// This class simulates EMC response with accounting primary 
// and secondary photostatistics. It supports the modes for 
// simple simulator also.
//
// mode = 2; Taking into account only primary photostatistics.
//
// mode = 3; Taking into account primary and secondary 
//           photostatistics(full simulation);
//
// mode = 4; Taking into account primary and secondary 
//           photostatistics(fast simulation);
//                                                                    
//////////////////////////////////////////////////////////////////////////

#ifndef STAR_StEmcPmtSimulator
#define STAR_StEmcPmtSimulator

#ifndef ROOT_Rtypes
#include <Rtypes.h>
#endif
#include <TMath.h>
#include <TRandom.h>

#include "StEmcSimpleSimulator.h"
#include "tables/St_controlEmcPmtSimulator_Table.h"
#include "StPmtSignal.h"

class StEmcPmtSimulator : public StEmcSimpleSimulator{
protected:

  StPmtSignal mPmtSignal;
  TRandom     mRandom;
  
  // 29-may-2002
  Int_t    mTypeOfPmt;
  Double_t mNpheMip;
  Double_t mDepMip; 
  // Working variable
  Double_t mC2;  // Number of PHE on one Gev
  Double_t mC3;
  Int_t    mVer; 

public: 
  StEmcPmtSimulator(UInt_t det);
  virtual ~StEmcPmtSimulator() {/* nothing */};
  Bool_t   setControlDefault(UInt_t det);

  virtual void    init();
  virtual void    setParameters(const Float_t calibCoeff,const UInt_t type, const Float_t pedMean, const Float_t pedRMS);
  virtual Int_t   getAdc(const Double_t de, const Double_t eta);
  virtual Float_t getEnergy();
  virtual void    print();

  ClassDef(StEmcPmtSimulator, 1) // Emc simulator with accounting primary and secondary photostatistics
};
#endif

//////////////////////////////////////////////////////////////////////////
//  $Id: StEmcPmtSimulator.h,v 1.2 2002/06/04 16:09:35 pavlinov Exp $
//  $Log: StEmcPmtSimulator.h,v $
//  Revision 1.2  2002/06/04 16:09:35  pavlinov
//  added option with DB(pedestal ans calibration  coefficients
//
//  Revision 1.1  2000/10/23 22:53:14  pavlinov
//  First working C++ version
//
//////////////////////////////////////////////////////////////////////////
