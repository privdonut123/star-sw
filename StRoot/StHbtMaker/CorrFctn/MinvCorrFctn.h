/***************************************************************************
 *
 * $Id: MinvCorrFctn.h,v 1.3 2000/01/25 17:34:45 laue Exp $
 *
 * Author: Frank Laue, Ohio State, laue@mps.ohio-state.edu
 ***************************************************************************
 *
 * Description: part of STAR HBT Framework: StHbtMaker package
 *     A simple invariant-mass correlation function
 *
 ***************************************************************************
 *
 * $Log: MinvCorrFctn.h,v $
 * Revision 1.3  2000/01/25 17:34:45  laue
 * I. In order to run the stand alone version of the StHbtMaker the following
 * changes have been done:
 * a) all ClassDefs and ClassImps have been put into #ifdef __ROOT__ statements
 * b) unnecessary includes of StMaker.h have been removed
 * c) the subdirectory StHbtMaker/doc/Make has been created including everything
 * needed for the stand alone version
 *
 * II. To reduce the amount of compiler warning
 * a) some variables have been type casted
 * b) some destructors have been declared as virtual
 *
 * Revision 1.2  1999/07/06 22:33:20  lisa
 * Adjusted all to work in pro and new - dev itself is broken
 *
 * Revision 1.1.1.1  1999/06/29 16:02:57  lisa
 * Installation of StHbtMaker
 *
 **************************************************************************/

#ifndef MinvCorrFctn_hh
#define MinvCorrFctn_hh

#include "StHbtMaker/Infrastructure/StHbtAnalysis.h"
#include "StHbtMaker/Base/StHbtCorrFctn.hh"
#include "StHbtMaker/Cut/mikesEventCut.h"

class MinvCorrFctn : public StHbtCorrFctn {
public:
  MinvCorrFctn(const MinvCorrFctn& ); // copy constructor
  MinvCorrFctn(char* title, const int& nbins, const float& MinvLo, const float& MinvHi);
  virtual ~MinvCorrFctn();

  virtual StHbtString Report();
  virtual void AddRealPair(const StHbtPair*);
  virtual void AddMixedPair(const StHbtPair*);

  virtual void Finish();

  StHbt1DHisto* Numerator();
  StHbt1DHisto* Denominator();
  StHbt1DHisto* Difference();

private:
  StHbt1DHisto* mNumerator;
  StHbt1DHisto* mDenominator;
  StHbt1DHisto* mDifference;

#ifdef __ROOT__
  ClassDef(MinvCorrFctn, 1)   
#endif 
};


inline  StHbt1DHisto* MinvCorrFctn::Numerator(){return mNumerator;}
inline  StHbt1DHisto* MinvCorrFctn::Denominator(){return mDenominator;}
inline  StHbt1DHisto* MinvCorrFctn::Difference(){return mDifference;}


#endif

