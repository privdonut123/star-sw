/*!
 * \class StPxlCluster
 * \author Qiu Hao, Jan 2013, according codes from Xiangming Sun
 * \Initial Revision.
 */
/***************************************************************************
 *
 * $Id: StPxlCluster.cxx,v 1.2 2014/01/27 02:37:02 qiuh Exp $
 *
 * Author: Qiu Hao, Jan 2013, according codes from Xiangming Sun
 ***************************************************************************
 *
 * Description:
 * a group of neighboring pixel raw hits
 * More information at
 * https://www.star.bnl.gov/protected/heavy/qiuh/HFT/software/PXL_software.pdf
 *
 ***************************************************************************
 *
 * $Log: StPxlCluster.cxx,v $
 * Revision 1.2  2014/01/27 02:37:02  qiuh
 * *** empty log message ***
 *
 *
 **************************************************************************/

#include "StPxlCluster.h"
#include "StPxlRawHitMaker/StPxlRawHit.h"
#include <algorithm>
#include <map>
using namespace std;

ClassImp(StPxlCluster)

StPxlCluster::StPxlCluster()
{
   mColumnCenter = -9999;
   mRowCenter = -9999;
   mIdTruth = -9999;
}

Int_t StPxlCluster::nRawHits() const
{
   return mRawHitVec.size();
}

void StPxlCluster::addRawHit(const StPxlRawHit *rawHit)
{
   mRawHitVec.push_back(rawHit);
}

bool compareSecond(const pair<int, int> &pair1, const pair<int, int> &pair2)
{
   return pair1.second < pair2.second;
}

void StPxlCluster::summarize()
{
   // calculate average column and row
   float columnSum = 0;
   float rowSum = 0;
   int nRawHits_ = nRawHits();
   for (int i = 0; i < nRawHits_; i++) {
      columnSum += mRawHitVec[i]->column();
      rowSum += mRawHitVec[i]->row();
   }
   mColumnCenter = columnSum / float(nRawHits_);
   mRowCenter = rowSum / float(nRawHits_);

   // find the most frequent raw hit idTruth as cluster idTruth
   map<int, int> idTruthMap;
   for (int i = 0; i < nRawHits_; i++) {
      if (mRawHitVec[i]->idTruth()) {idTruthMap[mRawHitVec[i]->idTruth()] ++;}
   }
   if (!idTruthMap.size()) {mIdTruth = 0;}
   else { mIdTruth = max_element(idTruthMap.begin(), idTruthMap.end(), compareSecond)->first;}
}



