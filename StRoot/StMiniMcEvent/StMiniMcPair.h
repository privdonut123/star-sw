/**
 * $Id $
 * \file  StMiniMcPair.h
 * \brief  for simplicity, this contains both the rc and mc track information.
 * 
 *
 * \author Bum Choi
 * \date   March 2001
 *  
*/

#ifndef StMiniMcPair_H
#define StMiniMcPair_H

#include "StTinyMcTrack.h"
#include "StTinyRcTrack.h"

class StMiniMcPair : public StTinyMcTrack, public StTinyRcTrack {
public:
    StMiniMcPair();
    virtual ~StMiniMcPair();
    
    void setNCommonHit(Short_t val) { mNCommonHit=val; }
    void setIsBestContam(Short_t val ) {mIsBestContam=val ; }
    
    float    commonFrac() const { 
	return static_cast<float>(mNCommonHit)/static_cast<float>(allPts());
    }

    int commonHits() { return mNCommonHit; }
    bool isBestContam() { return mIsBestContam; }
private:
    Short_t      mNCommonHit;
    Bool_t     mIsBestContam;

   
  ClassDef(StMiniMcPair,2)
};
  
#endif

//
// $Log: StMiniMcPair.h,v $
// Revision 1.1  2002/05/30 01:20:58  calderon
// Classes for use in a general framework for extracting efficiencies
// from both embedding and full simulations
// (after GSTAR+TRS+StEvent+StMcEvent+StAssociationMaker)
// so that the information of the track matches gets stored persistently.
//
//
