/***************************************************************************
 *
 * $Id: StHbtClassImp.cxx,v 1.1 2000/05/24 21:13:37 laue Exp $
 *
 * Author: Frank Laue, Ohio State, laue@mps.ohio-state.edu
 ***************************************************************************
 *
 * Description: part of STAR HBT Framework: StHbtMaker package
 * Root fix. All the base classes which have a 'ClassDef' now need a 
 * corresponding 'ClassImp'  
 *
 ***************************************************************************
 *
 * $Log: StHbtClassImp.cxx,v $
 * Revision 1.1  2000/05/24 21:13:37  laue
 * Since new rootcint (2.24.04 and higher) each ClassDef has to have matched
 * ClassImp otherwise you will have missing Dictionary symbol in a shared
 * library.
 * In this file we collect the 'ClassImp's from classes which do not have
 * a '.cxx' or '.cc' file (.e.g base classes).
 *
 *
 **************************************************************************/

#include "StHbtMaker/Base/StHbtEventCut.h"
#include "StHbtMaker/Base/StHbtPairCut.h"
#include "StHbtMaker/Base/StHbtParticleCut.h"
#include "StHbtMaker/Base/StHbtTripletCut.h"
#include "StHbtMaker/Base/StHbtTrackCut.h"
#include "StHbtMaker/Base/StHbtV0Cut.h"

#ifdef __ROOT__
  ClassImp(StHbtEventCut)
  ClassImp(StHbtPairCut)
  ClassImp(StHbtParticleCut)
  ClassImp(StHbtTripletCut)
  ClassImp(StHbtTrackCut)
  ClassImp(StHbtV0Cut)
#endif
