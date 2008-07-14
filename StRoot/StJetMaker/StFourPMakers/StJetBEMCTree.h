// -*- mode: c++;-*-
// $Id: StJetBEMCTree.h,v 1.2 2008/07/14 03:35:53 tai Exp $
#ifndef STJETBEMCTREE_H
#define STJETBEMCTREE_H

#include "StJetBEMC.h"

#include <Rtypes.h>

class TTree;

namespace StSpinJet {

class StJetBEMCTree : public StJetBEMC {

public:
  StJetBEMCTree(TTree *tree,
		const Int_t& indexMajor, const Int_t& indexMinor,
		const char* indexMajorName = "runNumber",
		const char* indexMinorName = "eventId"
		);
  virtual ~StJetBEMCTree() { }

  TowerEnergyList getEnergyList();

private:

  TTree* _tree;

  const Int_t& _indexMajor;
  const Int_t& _indexMinor;

  Int_t    _runNumber;
  Int_t    _eventId;
  Int_t    _detectorId; // 9: BEMC, 13: EEMC
  Int_t    _nTowers;
  Int_t    _towerId[4800];
  Double_t _towerR[4800];
  Double_t _towerEta[4800];
  Double_t _towerPhi[4800];
  Double_t _vertexX[4800];
  Double_t _vertexY[4800];
  Double_t _vertexZ[4800];
  Double_t _energy[4800];
  UInt_t   _adc[4800];
  Double_t _pedestal[4800];
  Double_t _rms[4800];
  Int_t    _status[4800];     // 1 is good for BEMC. 0 is good for EEMC

};

}

#endif // STJETBEMCTREE_H
