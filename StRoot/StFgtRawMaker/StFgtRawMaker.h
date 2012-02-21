// \class StFgtRawMaker
// \author Anselm Vossen (avossen@indiana.edu)
// 
//  $Id: StFgtRawMaker.h,v 1.20 2012/02/21 19:44:45 avossen Exp $
//  $Log: StFgtRawMaker.h,v $
//  Revision 1.20  2012/02/21 19:44:45  avossen
//  implementing reviewers comments take 2
//
//  Revision 1.19  2012/02/21 04:41:57  avossen
//  *** empty log message ***
//
//  Revision 1.18  2012/02/20 23:56:39  avossen
//  addressing reviewers comments take 1
//
//  Revision 1.17  2012/01/18 03:10:51  avossen
//  added db access to the raw maker
//
//  Revision 1.16  2011/11/01 18:45:32  sgliske
//  Updated to correspond with StEvent containers, take 2.
//  Note: new FGT containers (and StEvent access) no longer
//  motivate the use of a common base class
//
//  Revision 1.15  2011/10/26 20:57:49  avossen
//  hopefully made cosmic and raw maker compatible with bfc (again), added clear in make. Unnecessary if member fkt clear() is called after every event
//
//  Revision 1.14  2011/09/21 17:49:34  sgliske
//  alternate base class with more
//   functionality and not an StMaker
//
//  Revision 1.11  2011/09/20 15:53:09  sgliske
//  Update so that everything compiles nicely
//  and so that one can execute the macro/simpleTestStandTest.C file
//
//
//
//
#ifndef STAR_StFgtRawMaker_HH
#define STAR_StFgtRawMaker_HH

#include <math.h>
#include "StRoot/StChain/StRTSBaseMaker.h"

class StFgtCollection;
class StFgtDb;

/**
   This is the raw maker for the FGT data. It makes use of its base class functions to read daq files into the StFgtEvent Data structure.

*/
class StFgtRawMaker : public StRTSBaseMaker
{
 public: 
  StFgtRawMaker(const Char_t* name="FgtRaw");
  virtual ~StFgtRawMaker();
/**
Init function. Not doing anything at the moment.
*/
  virtual Int_t Init();
/**
Maker main function. Getting pointer to StEvent and fills the event structure
*/
  virtual Int_t Make();
  virtual void Clear( Option_t *opts = "" );

  /**
     sets the pointer to the StFgtDb
  */
  void setFgtDb(StFgtDb *x) {mFgtDb=x;}

 protected:

/**
utility function to get the data from the daq file and fill the StEvent structure
*/
  virtual Int_t fillHits();
/**
Function to get pointer to StEvent datastructures. Creates them if they do not exist already.
*/
  virtual Int_t prepareEnvironment();
  StFgtCollection *mFgtCollectionPtr;

 private:
  /** copy contructor. It is private since there is no use case for this
   */
  StFgtRawMaker(const StFgtRawMaker &source);

  /**
     private asignment operator
  */
  StFgtRawMaker& operator=(const StFgtRawMaker &source);
  StFgtDb *mFgtDb;
  ClassDef(StFgtRawMaker,1);
};

#endif
