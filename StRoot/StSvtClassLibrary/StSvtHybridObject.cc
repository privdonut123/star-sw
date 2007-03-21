/***************************************************************************
 *
 * $Id: StSvtHybridObject.cc,v 1.3 2007/03/21 17:22:20 fisyak Exp $
 *
 * Author: Marcelo Munhoz
 ***************************************************************************
 *
 * Description: SVT Hybrid Object BASE class
 *
 ***************************************************************************
 *
 * $Log: StSvtHybridObject.cc,v $
 * Revision 1.3  2007/03/21 17:22:20  fisyak
 * Ivan Kotov's drift velocities, use TGeoHMatrix for coordinate transformation
 *
 * Revision 1.2  2001/07/12 16:56:30  munhoz
 * layer numbers changed for barrel 2 due to new geometry
 *
 * Revision 1.1.1.1  2000/03/10 14:26:21  munhoz
 * SVT Class Library
 *
 **************************************************************************/
////////////////////////////////////////////////////////////////////////////
//                                                                        //
// This class represents the basic unit of the SVT, i.e, a hybrid.        //
// It should be the base class for any "hybrid object".                   //
// "Anything" (data, pedestal, drift velocity, clusters, hit points, etc.)// 
// that is particular to one hybrid, should inherit from this class.      // 
//                                                                        //
////////////////////////////////////////////////////////////////////////////


#include "StSvtHybridObject.hh"

ClassImp(StSvtHybridObject)
