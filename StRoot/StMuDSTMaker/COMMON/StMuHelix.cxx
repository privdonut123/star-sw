/***************************************************************************
 *   
 * $Id: StMuHelix.cxx,v 1.3 2003/10/30 20:08:13 perev Exp $
 * Author: Frank Laue, BNL, laue@bnl.gov
 *
 ***************************************************************************/

#include "StMuHelix.h"

StMuHelix::StMuHelix(StPhysicalHelixD hh, double field) {
  mP = hh.momentum(field*kilogauss);
  mOrigin = hh.origin();
  mQ = hh.charge( field*kilogauss );
  mB = field;
}

int StMuHelix::bad() const 
{
   double qwe;
   if(!mOrigin.valid())		return 10;
   if(!mP.valid     ()) 	return 20;

   qwe = fabs(mP.x())+fabs(mP.y());
   if (qwe <=1.e-10)   		return 21;

   if (abs(mQ)  >    10)        return 30;

   if (!::finite(mB))           return 40;
   if (fabs(mB) >  1000)        return 41;
   return 0;
}
ClassImp(StMuHelix)
/***************************************************************************
 *
 * $Log: StMuHelix.cxx,v $
 * Revision 1.3  2003/10/30 20:08:13  perev
 * Check of quality added
 *
 * Revision 1.2  2003/10/28 18:57:56  perev
 * BadData protection added
 *
 * Revision 1.1  2002/03/08 17:04:18  laue
 * initial revision
 *
 *
 **************************************************************************/
