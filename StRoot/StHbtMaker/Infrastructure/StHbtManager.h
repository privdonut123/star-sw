/***************************************************************************
 *
 * $Id: StHbtManager.h,v 1.8 2000/01/25 17:35:17 laue Exp $
 *
 * Author: Mike Lisa, Ohio State, lisa@mps.ohio-state.edu
 ***************************************************************************
 *
 * Description: part of STAR HBT Framework: StHbtMaker package
 *   The Manager is the top-level object that coordinates activities
 *   and performs event, particle, and pair loops, and checks the
 *   various Cuts of the Analyses in its AnalysisCollection
 *
 ***************************************************************************
 *
 * $Log: StHbtManager.h,v $
 * Revision 1.8  2000/01/25 17:35:17  laue
 * I. In order to run the stand alone version of the StHbtMaker the following
 * changes have been done:
 * a) all ClassDefs and ClassImps have been put into #ifdef __ROOT__ statements
 * b) unnecessary includes of StMaker.h have been removed
 * c) the subdirectory StHbtMaker/doc/Make has been created including everything
 * needed for the stand alone version
 *
 * II. To reduce the amount of compiler warning
 * a) some variables have been type casted
 * b) some destructors have been declared as virtual
 *
 * Revision 1.7  1999/10/04 15:38:58  lisa
 * include Franks new accessor methods StHbtAnalysis::CorrFctn and StHbtManager::Analysis as well as McEvent example macro
 *
 * Revision 1.6  1999/09/24 01:23:12  fisyak
 * Reduced Include Path
 *
 * Revision 1.5  1999/09/08 04:15:52  lisa
 * persistent microDST implementation tweaked to please fickle solaris details
 *
 * Revision 1.4  1999/09/05 02:58:12  lisa
 * add ASCII microDST reader/writer AND franksParticle cuts
 *
 * Revision 1.3  1999/09/04 04:41:02  lisa
 * StHbtEvent IO   --and--  StHbtEventWriter (microDST) method added to framework
 *
 * Revision 1.2  1999/07/06 22:33:22  lisa
 * Adjusted all to work in pro and new - dev itself is broken
 *
 * Revision 1.1.1.1  1999/06/29 16:02:57  lisa
 * Installation of StHbtMaker
 *
 **************************************************************************/

#ifndef StHbtManager_hh
#define StHbtManager_hh


#include "StHbtMaker/Infrastructure/StHbtTypes.hh"
#include "StHbtMaker/Infrastructure/StHbtAnalysisCollection.hh"
#include "StHbtMaker/Infrastructure/StHbtAnalysis.h"
#include "StHbtMaker/Infrastructure/StHbtEvent.hh"
#include "StHbtMaker/Base/StHbtEventReader.hh"

class StHbtManager{

private:
  StHbtAnalysisCollection* mAnalysisCollection;
  StHbtEventReader*        mEventReader;
  StHbtEventReader*        mEventWriter;

public:
  StHbtManager();
  virtual ~StHbtManager();

  // Gets and Sets...
  StHbtAnalysisCollection* AnalysisCollection();
  StHbtAnalysis* Analysis(int n);  // Access to Analysis within Collection

  StHbtEventReader* EventReader();
  void SetEventReader(StHbtEventReader*);
  void SetEventWriter(StHbtEventReader*);

  void AddAnalysis(StHbtAnalysis*);

  int Init();
  int ProcessEvent();   // a "0" return value means success - otherwise quit
  void Finish();

  StHbtString Report(); //!
#ifdef __ROOT__
  ClassDef(StHbtManager, 0)
#endif
};

inline StHbtAnalysisCollection* StHbtManager::AnalysisCollection(){return mAnalysisCollection;}
inline StHbtEventReader* StHbtManager::EventReader(){return mEventReader;}
inline void StHbtManager::SetEventReader(StHbtEventReader* reader){mEventReader = reader;}
inline void StHbtManager::SetEventWriter(StHbtEventReader* writer){mEventWriter = writer;}

inline void StHbtManager::AddAnalysis(StHbtAnalysis* anal){mAnalysisCollection->push_back(anal);}

#endif

