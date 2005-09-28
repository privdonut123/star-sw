/***************************************************************************
 *
 * $Id: StMcVertex.cc,v 2.10 2005/09/28 21:30:15 fisyak Exp $
 * $Log: StMcVertex.cc,v $
 * Revision 2.10  2005/09/28 21:30:15  fisyak
 * Persistent StMcEvent
 *
 * Revision 2.9  2005/01/27 23:40:49  calderon
 * Adding persistency to StMcEvent as a step for Virtual MonteCarlo.
 *
 * Revision 2.8  2003/08/20 18:50:21  calderon
 * Addition of Tof classes and Pixel classes.  Modified track, event, and
 * container code to reflect this.
 * Fix bug in StMcVertex and in clearing of some hit collections.
 *
 * Revision 2.7  2000/05/05 15:25:44  calderon
 * Reduced dependencies and made constructors more efficient
 *
 * Revision 2.6  2000/03/29 16:15:54  calderon
 * Added more information from g2t_vertex table
 *
 * Revision 2.5  2000/03/06 18:05:24  calderon
 * 1) Modified SVT Hits storage scheme from layer-ladder-wafer to
 * barrel-ladder-wafer.
 * 2) Added Rich Hit class and collection, and links to them in other
 * classes.
 *
 * Revision 2.4  2000/01/18 20:52:31  calderon
 * Works with CC5
 *
 * Revision 2.3  1999/12/14 07:04:50  calderon
 * Numbering scheme as per SVT request.
 *
 * Revision 2.2  1999/12/03 00:51:53  calderon
 * Tested with new StMcEventMaker.  Added messages for
 * diagnostics.
 *
 * Revision 2.1  1999/11/19 19:06:34  calderon
 * Recommit after redoing the files.
 *
 * Revision 2.0  1999/11/17 02:12:17  calderon
 * Completely revised for new StEvent
 *
 * Revision 1.4  1999/09/23 21:25:55  calderon
 * Added Log & Id
 * Modified includes according to Yuri
 *
 * Revision 1.3  1999/07/29 00:13:14  calderon
 * Read ge_volume correctly
 *
 *
 **************************************************************************/
#include <algorithm>
#ifndef ST_NO_NAMESPACES
using std::find;
#endif

#include "StMcVertex.hh"
#include "StMcTrack.hh"
#include "tables/St_g2t_vertex_Table.h"

static const char rcsid[] = "$Id: StMcVertex.cc,v 2.10 2005/09/28 21:30:15 fisyak Exp $";

ClassImp(StMcVertex);

StMcVertex::StMcVertex()
{
 
    mParent = 0;
    mGeantVolume = "aaaa";
    mTof = 0;
    mGeantProcess = 0;
}

StMcVertex::StMcVertex(g2t_vertex_st* vtx)
{

    
  mPosition.setX(vtx->ge_x[0]);
  mPosition.setY(vtx->ge_x[1]);
  mPosition.setZ(vtx->ge_x[2]);
  char tmp[5]; tmp[4]=0; strncpy(tmp,vtx->ge_volume,4);
  mGeantVolume=tmp;
  mTof = vtx->ge_tof;
  mGeantProcess = vtx->ge_proc;
  mGeneratorProcess = vtx->eg_proc;
  mKey = vtx->id;
  mGeantMedium = vtx->ge_medium;
  mParent = 0;
    
}

StMcVertex::~StMcVertex()
{
    mDaughters.clear();  //Not owner, so we don't have to delete.
}


int StMcVertex::operator==(const StMcVertex& v) const
{
    return (mGeantProcess == v.mGeantProcess &&
	    mPosition     == v.mPosition     &&
	    mTof          == v.mTof          &&
	    mKey          == v.mKey);
}

int StMcVertex::operator!=(const StMcVertex& v) const
{
    return !(v == *this);
}

ostream&  operator<<(ostream& os, const StMcVertex& v)
{
  os << "StMcVertex: pos:"
     << "Position      : " << Form("%8.3f%8.3f%8.3f",v.position().x(),v.position().y(),v.position().z())
     << "Geant Volume  : " << v.geantVolume().c_str()
     << "Time of Flight: " << v.tof()
     << "Geant Process : " << v.geantProcess();
  Int_t nDaughters = v.numberOfDaughters();
  os << "N. Daughters: " << nDaughters;
  for (int j = 0; j < nDaughters; j++) {
    os << "\t" << v.daughter(j)->key();
  }
  
  return os;
}


void StMcVertex::setPosition(const StThreeVectorF& val) { mPosition = val; }

void StMcVertex::setParent(StMcTrack* val) {  mParent = val; }         

void StMcVertex::addDaughter(StMcTrack* val) { mDaughters.push_back(val); }  

void StMcVertex::setGeantVolume(string val) { mGeantVolume = val; } 

void StMcVertex::setTof(float val) { mTof = val; }

void StMcVertex::setGeantProcess(int val) { mGeantProcess = val; }     

void StMcVertex::removeDaughter(StMcTrack* trk) {
    StMcTrackIterator iter = find(mDaughters.begin(), mDaughters.end(), trk);
  if (iter != mDaughters.end()) mDaughters.erase(iter);
}
