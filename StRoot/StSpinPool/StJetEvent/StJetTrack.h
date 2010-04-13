// -*- mode: c++ -*-

//
// Pibero Djawotho <pibero@tamu.edu>
// Texas A&M University
// 31 August 2009
//

#ifndef ST_JET_TRACK_H
#define ST_JET_TRACK_H

#include "StJetElement.h"

class StJetTrack : public StJetElement {
public:
  StJetTrack()
    : StJetElement()
    , mFlag(0)
    , mCharge(0)
    , mNHits(0)
    , mNHitsFit(0)
    , mNHitsPoss(0)
    , mNHitsDedx(0)
    , mDedx(0)
    , mNSigmaPion(0)
    , mNSigmaKaon(0)
    , mNSigmaProton(0)
    , mNSigmaElectron(0)
    , mExitPoint(0,0,0)
    , mExitTowerId(0)
    , mExitDetectorId(0)
    , mDca(0)
    , mDcaX(0)
    , mDcaY(0)
    , mDcaZ(0)
    , mDcaD(0)
    , mChi2(0)
    , mChi2Prob(0)
  {}

  friend class StjeJetEventTreeWriter;

  short flag()                const { return mFlag; }
  short charge()              const { return mCharge; }
  short nHits()               const { return mNHits; }
  short nHitsFit()            const { return mNHitsFit; }
  short nHitsPoss()           const { return mNHitsPoss; }
  short nHitsDedx()           const { return mNHitsDedx; }
  float dEdx()                const { return mDedx; }
  float nSigmaPion()          const { return mNSigmaPion; }
  float nSigmaKaon()          const { return mNSigmaKaon; }
  float nSigmaProton()        const { return mNSigmaProton; }
  float nSigmaElectron()      const { return mNSigmaElectron; }
  const TVector3& exitPoint() const { return mExitPoint; }
  short exitTowerId()         const { return mExitTowerId; }
  short exitDetectorId()      const { return mExitDetectorId; }
  float dca()                 const { return mDca; }
  float dcaX()                const { return mDcaX; }
  float dcaY()                const { return mDcaY; }
  float dcaZ()                const { return mDcaZ; }
  float dcaD()                const { return mDcaD; }
  float chi2()                const { return mChi2; }
  float chi2prob()            const { return mChi2Prob; }

private:
  short mFlag;
  short mCharge;
  short mNHits;
  short mNHitsFit;
  short mNHitsPoss;
  short mNHitsDedx;
  float mDedx;
  float mNSigmaPion;
  float mNSigmaKaon;
  float mNSigmaProton;
  float mNSigmaElectron;
  TVector3 mExitPoint;
  short mExitTowerId;
  short mExitDetectorId;
  float mDca;
  float mDcaX;
  float mDcaY;
  float mDcaZ;
  float mDcaD;
  float mChi2;
  float mChi2Prob;

  ClassDef(StJetTrack, 2);
};

#endif // ST_JET_TRACK_H
