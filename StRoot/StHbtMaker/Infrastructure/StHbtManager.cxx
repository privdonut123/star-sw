/***************************************************************************
 *
 * $Id: StHbtManager.cxx,v 1.14 2000/02/13 17:17:12 laue Exp $
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
 * $Log: StHbtManager.cxx,v $
 * Revision 1.14  2000/02/13 17:17:12  laue
 * Calls to the EventBegin() and EventEnd() functions implemented
 * The actual analysis is moved from StHbtManager to StHbtAnalysis
 *
 * Revision 1.13  2000/01/25 17:35:17  laue
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
 * Revision 1.12  1999/10/15 01:57:29  lisa
 * Important enhancement of StHbtMaker - implement Franks CutMonitors
 * ----------------------------------------------------------
 * This means 3 new files in Infrastructure area (CutMonitor),
 * several specific CutMonitor classes in the Cut area
 * and a new base class in the Base area (StHbtCutMonitor).
 * This means also changing all Cut Base class header files from .hh to .h
 * so we have access to CutMonitor methods from Cint command line.
 * This last means
 * 1) files which include these header files are slightly modified
 * 2) a side benefit: the TrackCuts and V0Cuts no longer need
 * a SetMass() implementation in each Cut class, which was stupid.
 * Also:
 * -----
 * Include Franks StHbtAssociationReader
 * ** None of these changes should affect any user **
 *
 * Revision 1.11  1999/10/04 15:38:57  lisa
 * include Franks new accessor methods StHbtAnalysis::CorrFctn and StHbtManager::Analysis as well as McEvent example macro
 *
 * Revision 1.10  1999/09/17 22:38:02  lisa
 * first full integration of V0s into StHbt framework
 *
 * Revision 1.9  1999/09/08 04:15:52  lisa
 * persistent microDST implementation tweaked to please fickle solaris details
 *
 * Revision 1.8  1999/09/05 02:58:11  lisa
 * add ASCII microDST reader/writer AND franksParticle cuts
 *
 * Revision 1.7  1999/09/04 04:41:01  lisa
 * StHbtEvent IO   --and--  StHbtEventWriter (microDST) method added to framework
 *
 * Revision 1.6  1999/09/03 22:39:15  lisa
 * Readers now MUST have Report() methods and MAY have WriteHbtEvent() methods
 *
 * Revision 1.5  1999/07/27 10:47:04  lisa
 * now works in dev on linux and solaris - mistake in deleting picoEvents fixed
 *
 * Revision 1.4  1999/07/26 16:21:26  lisa
 * always convert string to char when output - needed on solaris
 *
 * Revision 1.3  1999/07/22 18:49:10  lisa
 * Implement idea of Fabrice to not create and delete StHbtPair all the time
 *
 * Revision 1.2  1999/07/06 22:33:22  lisa
 * Adjusted all to work in pro and new - dev itself is broken
 *
 * Revision 1.1.1.1  1999/06/29 16:02:57  lisa
 * Installation of StHbtMaker
 *
 **************************************************************************/

#include "StHbtMaker/Infrastructure/StHbtManager.h"
//#include "StHbtMaker/Infrastructure/StHbtParticleCollection.hh"
//#include "StHbtMaker/Base/StHbtTrackCut.h"
//#include "StHbtMaker/Base/StHbtV0Cut.h"
#include <cstdio>

#ifdef __ROOT__
ClassImp(StHbtManager)
#endif



//____________________________
StHbtManager::StHbtManager(){
  mAnalysisCollection = new StHbtAnalysisCollection;
  mEventReader = 0;
  mEventWriter = 0;
}
//____________________________
StHbtManager::~StHbtManager(){
  delete mEventReader;
  // now delete each Analysis in the Collection, and then the Collection itself
  StHbtAnalysisIterator AnalysisIter;
  for (AnalysisIter=mAnalysisCollection->begin();AnalysisIter!=mAnalysisCollection->end();AnalysisIter++){
    delete *AnalysisIter;
    *AnalysisIter = 0;
  }
  delete mAnalysisCollection;
}
//____________________________
int StHbtManager::Init(){
  StHbtString temp = " ";
  if (mEventReader) {
    if (mEventReader->Init("r")){
      cout << " StHbtManager::Init() - Reader initialization failed " << endl;
      return (1);
    }
    temp = mEventReader->Report();
  }
  if (mEventWriter) {
    if (mEventWriter->Init("w",temp)){
      cout << " StHbtManager::Init() - Writer initialization failed " << endl;
      return (1);
    }
  }
  return (0);
}
//____________________________
void StHbtManager::Finish(){
  StHbtAnalysisIterator AnalysisIter;
  StHbtAnalysis* currentAnalysis;
  for (AnalysisIter=mAnalysisCollection->begin();AnalysisIter!=mAnalysisCollection->end();AnalysisIter++){
    currentAnalysis = *AnalysisIter;
    currentAnalysis->Finish();
  }
  if (mEventReader) mEventReader->Finish();
  if (mEventWriter) mEventWriter->Finish();
}
//____________________________
StHbtString StHbtManager::Report(){
  string stemp;
  //  cout << "StHbtManager Starting report " << endl;
  //cout << mAnalysisCollection->size() << endl;
  char ctemp[100];
  stemp = mEventReader->Report();
  sprintf(ctemp,"\nStHbtManager Reporting %u Analyses\n",mAnalysisCollection->size());
  stemp += ctemp;
  StHbtAnalysisIterator AnalysisIter;
  StHbtAnalysis* currentAnalysis;
  //cout << stemp.c_str();
  for (AnalysisIter=mAnalysisCollection->begin();AnalysisIter!=mAnalysisCollection->end();AnalysisIter++){
    cout << "StHbtManager - asking for Analysis Report" << endl;
    currentAnalysis = *AnalysisIter;
    stemp+=currentAnalysis->Report();
  }
  StHbtString returnThis = stemp;
  return returnThis;
}
//____________________________
StHbtAnalysis* StHbtManager::Analysis( int n ){  // return pointer to n-th analysis
  if ( n<0 || n > (int) mAnalysisCollection->size() )
    return NULL;
  StHbtAnalysisIterator iter = mAnalysisCollection->begin();
  for (int i=0; i<n ;i++){
    iter++;
  }
  return *iter;
}
 //____________________________
int StHbtManager::ProcessEvent(){
  cout << "StHbtManager::ProcessEvent" << endl;
  // NOTE - this ReturnHbtEvent makes a *new* StHbtEvent - delete it when done!
  StHbtEvent* currentHbtEvent = mEventReader->ReturnHbtEvent();
  cout << "Event reader has returned control to manager" << endl;
  
  // if no HbtEvent is returned, then we abort processing.
  // the question is now: do we try again next time (i.e. there may be an HbtEvent next time)
  // or are we at EOF or something?  If Reader says Status=0, then that means try again later.
  // so, we just return the Reader's Status.
  if (!currentHbtEvent){
    cout << "StHbtManager::ProcessEvent() - Reader::ReturnHbtEvent() has returned null pointer\n";
    return mEventReader->Status();
  }
  
  // shall we write a microDST? - added 3sep99
  if (mEventWriter) mEventWriter->WriteHbtEvent(currentHbtEvent);

  // loop over all the analysis
  StHbtAnalysisIterator AnalysisIter;
  for (AnalysisIter=mAnalysisCollection->begin();AnalysisIter!=mAnalysisCollection->end();AnalysisIter++){
    (*AnalysisIter)->ProcessEvent(currentHbtEvent);
  } 
  delete currentHbtEvent;
  cout << "StHbtManager::ProcessEvent() - return to caller ... " << endl;
  return 0;    // 0 = "good return"
}       // ProcessEvent
