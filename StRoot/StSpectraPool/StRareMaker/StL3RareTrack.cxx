//
//  StL3RareTrack.cxx
//
//  Christof struck
//
// -------------------------------------------

#include "StL3RareTrack.h"
#include "Rtypes.h"
#include "StEventTypes.h"

double dEdx_formula(double momentum, double mass);

ClassImp(StL3RareTrack)

StL3RareTrack::StL3RareTrack()
{
  mDca = 0;
  mNPntpossible = 0;
  mTracknumber = 0;
  mFlag = 0;
  mNPntfit = 0;
  mChisqXY = 0;
  mChisqSZ = 0;
  mPx = 0;
  mPy = 0;
  mPz = 0;
  mDedxPion = 0;
  mDedxProton = 0;
  mDedxDeuteron = 0;
  mDedxTriton = 0;
  mDedxHe3 = 0;
  mDedxHe4 = 0;
  mChargesign = 0;
  mTrigType = 0;
  mDedx = 0.0;
}

StL3RareTrack::StL3RareTrack(StGlobalTrack* track)
{
  mDca = track->impactParameter();
  mNPntpossible = track->numberOfPossiblePoints();
  mTracknumber = track->key();
  mFlag = track->flag();
  mNPntfit = track->detectorInfo()->numberOfPoints();
  mChisqXY = track->fitTraits().chi2(0)/mNPntfit;
  mChisqSZ = track->fitTraits().chi2(1)/mNPntfit;
  mPx = track->geometry()->momentum().x();
  mPy = track->geometry()->momentum().y();
  mPz = track->geometry()->momentum().z();
  mDedxPion = dedxPi();
  mDedxProton = dedxProton();
  mDedxDeuteron = dedxDeuteron();
  mDedxTriton = dedxTriton();
  mDedxHe3 = dedxHe3();
  mDedxHe4 = dedxHe4();
  mChargesign = track->geometry()->charge();
  mTrigType = 0;
  mDedx = 0.0;
  mNDedx = 0;
  StSPtrVecTrackPidTraits& traits = track->pidTraits();
  StDedxPidTraits* dedxPidTr;
  for (unsigned int itrait = 0; itrait < traits.size(); itrait++){
        dedxPidTr = 0;
	if (traits[itrait]->detector() == kTpcId) {
	      StTrackPidTraits* thisTrait = traits[itrait];
	      dedxPidTr = dynamic_cast<StDedxPidTraits*>(thisTrait);
	      if (dedxPidTr && dedxPidTr->method() == kTruncatedMeanId) {
		    mDedx = dedxPidTr->mean();
		    mNDedx = dedxPidTr->numberOfPoints();
	      }
	}
  }

}


float StL3RareTrack::dedxExpected(float mass, float charge = 1) const {
  float real_mom = p()*charge;
  float dedx = charge*charge*dEdx_formula(real_mom,mass);
  return dedx;
} 

void  StL3RareTrack::SetTrigType(int type) {mTrigType = type;}
