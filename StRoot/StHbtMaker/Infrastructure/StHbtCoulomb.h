/***************************************************************************
 *
 * $Id: StHbtCoulomb.h,v 1.9 2000/05/31 20:12:53 rcwells Exp $
 *
 * Author: Randy Wells, Ohio State, rcwells@mps.ohio-state.edu
 ***************************************************************************
 *
 * Description: part of STAR HBT Framework: StHbtMaker package
 *    This is a Coulomb correction class which
 *  1. Reads in the dat from a file
 *  2. Performs a linear interpolation in R and creates any array of interpolations
 *  3. Interpolates in eta and returns the Coulomb correction to user
 *
 ***************************************************************************
 *
 * $Log: StHbtCoulomb.h,v $
 * Revision 1.9  2000/05/31 20:12:53  rcwells
 * Modified StHbtCoulomb for Id and Log entries
 *
 *
 **************************************************************************/

#ifndef StHbtCoulomb_HH
#define StHbtCoulomb_HH

#include <stdio.h>
#include "StHbtMaker/Infrastructure/StHbtTypes.hh"
#include "StHbtMaker/Infrastructure/StHbtPair.hh"
#include "StHbtMaker/Infrastructure/StHbtParticle.hh"
#include "TH1.h"

class StHbtCoulomb {

public:
  StHbtCoulomb();
  StHbtCoulomb(const char *readFile, const double& radius, const double& charge);
  virtual ~StHbtCoulomb();

  void SetRadius(const double& radius);
  double GetRadius();
  void SetFile(const char *readFile);
  void SetChargeProduct(const double& charge);

  // These have different names so eta/Qinv don't confuse the compiler
  double CoulombCorrect(const double& eta);
  double CoulombCorrect(const double& eta, const double& radius);
  double CoulombCorrect(const StHbtPair* pair);
  double CoulombCorrect(const StHbtPair* pair, const double& radius);
  StHbt1DHisto* CorrectionHistogram(const double& mass1, const double& mass2, const int& nBins, 
				    const double& low, const double& high);


private:
  double Eta(const StHbtPair* pair);                // Calculates eta
  void CreateLookupTable(const double& radius);  // Creates look-up table
  const char* mFile;                             // File to interpolate corrections from    
  double mRadius;                                // Radius from previous iteration
  double mZ1Z2;                                  // Charge product of particles
  double mEta[1000];                             // interpolated Coulomb correction table
  double mCoulomb[1000];                         // interpolated Coulomb correction table
  int mNLines;                                   // Number of Eta's in lookup-table

#ifdef __ROOT__
  ClassDef(StHbtCoulomb, 1)
#endif
};


#endif
