/***************************************************************************
 *
 * $Id: StHiMicroHit.cxx,v 1.1 2002/04/02 19:36:15 jklay Exp $                                                         
 *
 * Author: Bum Choi, UT Austin, Apr 2002
 *
 ***************************************************************************
 *
 * Description:  This is a uDST for highpt Analysis: Hit Information               
 *               
 ***************************************************************************
 *
 * $Log: StHiMicroHit.cxx,v $
 * Revision 1.1  2002/04/02 19:36:15  jklay
 * Bums highpt uDST format
 *
 *
 **************************************************************************/
#include "StHiMicroHit.h"
#include <iostream>
#define DEBUG 0

StHiMicroHit::StHiMicroHit()
{
  if(DEBUG) cout << "StHiMicroHit::StHiMicroHit" << endl;
}

StHiMicroHit::~StHiMicroHit()
{
  if(DEBUG) cout << "StHiMicroHit::~StHiMicroHit" << endl;
}

ClassImp(StHiMicroHit)

