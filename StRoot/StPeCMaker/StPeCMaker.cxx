// $Id: StPeCMaker.cxx,v 1.24 2002/12/19 18:09:53 yepes Exp $
// $Log: StPeCMaker.cxx,v $
// Revision 1.24  2002/12/19 18:09:53  yepes
// MuDST input added
//
// Revision 1.23  2002/06/04 17:55:02  meissner
// filtering: filter all  UPC triggerwords
//
// Revision 1.21  2002/04/18 19:02:11  meissner
// Change Init to  InitRun
//
// Revision 1.20  2002/03/19 22:23:44  meissner
// New variables: zdc unatt., Trigger word, MC tree if Geant Branch, DCA  for primary pairs, all tracks for secondary pairs (Test)
//
// Revision 1.19  2002/02/11 20:20:09  akio
// remove SetFormat
//
// Revision 1.18  2001/08/07 19:52:35  akio
// added a flag to make udst can have more than 1 depth of branches.
//
// Revision 1.17  2001/04/23 21:44:33  meissner
// add dEdx z variable to tree, setFormat(1) for tree, use private BetheBloch (temp solution)
//
// Revision 1.16  2001/02/21 20:42:05  yepes
// Add ctb signals to tree
//
// Revision 1.15  2001/02/14 18:34:44  yepes
// bug in deleting StEvent and the of of Make
//
// Revision 1.14  2001/02/13 17:54:41  yepes
// still problems on differnt platforms
//
// Revision 1.13  2001/02/13 16:33:58  yepes
// fix problem on Sun
//
// Revision 1.12  2001/02/12 21:15:55  yepes
// New version of StPeCMaker, lots of changes
//
// Revision 1.9  2000/04/21 19:09:49  nystrand
// Update StPeCPair class, new histograms
//
// Revision 1.8  2000/03/24 22:36:24  nystrand
// First version with StPeCEvent
//
// Revision 1.7  2000/01/20 23:03:08  nystrand
// First Version of StPeCMaker with new StEvent
//
// Revision 1.6  1999/09/24 01:23:19  fisyak
// Reduced Include Path
//
// Revision 1.5  1999/07/15 13:57:20  perev
// cleanup
//
// Revision 1.4  1999/06/27 22:45:29  fisyak
// Merge StRootEvent and StEvent
//
// Revision 1.3  1999/05/01 00:57:02  fisyak
// Change Clear function to defualt
//
// Revision 1.2  1999/04/08 16:37:15  nystrand
// MakeBranch,SetBranch removed
//
// Revision 1.1  1999/04/06 20:47:27  akio
// The first version
//
// Revision 1.0  1999/03/05 11:00:00  Nystrand
// initial version
//
//
///////////////////////////////////////////////////////////////////////////////
//
// StPeCMaker
//
// Description: 
//  Maker for Peripheral Collisions DST analysis
//  This version uses StPeCEvent
//
// Environment:
//  Software developed for the STAR Detector at Brookhaven National Laboratory
//
// Author List: 
//  Joakim Nystrand, LBNL
//
// History:
//
///////////////////////////////////////////////////////////////////////////////
#include "StPeCMaker.h"
#include "StEventTypes.h"
#include "StChain.h"
#include "Stypes.h"
#include "StMessMgr.h"
#include "TH1.h"
#include <vector>
#ifndef ST_NO_NAMESPACES
using std::vector;
#endif

#include "StTriggerDetectorCollection.h"
#include "StCtbTriggerDetector.h"
#include "StMwcTriggerDetector.h"
#include "StVpdTriggerDetector.h"
#include "StZdcTriggerDetector.h"
#include "StFtpcHitCollection.h"
#include "StFtpcPlaneHitCollection.h"
#include "StFtpcSectorHitCollection.h"

#include "StMcEventTypes.hh"
#include "StMcEventMaker/StMcEventMaker.h"
#include "StIOMaker/StIOMaker.h"



static const char rcsid[] = "$Id: StPeCMaker.cxx,v 1.24 2002/12/19 18:09:53 yepes Exp $";

ClassImp(StPeCMaker)

StPeCMaker::StPeCMaker(const Char_t *name) : StMaker(name), infoLevel(0), filter(0), outputPerRun(0), muDst(0)
{
   treeFileName = "StPeCMaker.tree.root" ;
   return;
}


StPeCMaker::~StPeCMaker()
{
   return;
}


Int_t StPeCMaker::Init() {

   cout << "tree output file: " << treeFileName << endl;

   //Get the standard root format to be independent of Star IO   
   m_outfile = new TFile(treeFileName, "recreate");
   m_outfile->SetCompressionLevel(1);


   uDstTree = new TTree("uDst", "Pcol uDst", 99);

   //Instantiate StPeCEvent
   pevent = new StPeCEvent();
   pevent->setInfoLevel(infoLevel);

   trigger = new StPeCTrigger();
   trigger->setInfoLevel(infoLevel);

   geant = new StPeCGeant();

   //Add branches
   uDstTree->Branch("Event", "StPeCEvent", &pevent, 64000, 99);
   uDstTree->Branch("Trigger", "StPeCTrigger", &trigger, 64000, 99);
   uDstTree->Branch("Geant", "StPeCGeant", &geant, 64000, 99);

   return StMaker::Init();
}


Int_t StPeCMaker::InitRun(Int_t runnr) {
   treeFileName="StPeCMaker.tree.root";

   if ( outputPerRun ) {
      StIOMaker* pIOMaker = (StIOMaker*)GetMaker("IO");
      if (pIOMaker)
      {
         treeFileName = pIOMaker->GetFile();
         char* ccc = "/";
         Ssiz_t slashPosition = treeFileName.Last(*ccc);

         if (slashPosition != -1 && slashPosition < treeFileName.Length()) 
	    treeFileName.Remove(0,slashPosition+1);
      }

   //Make token replacements
      treeFileName.ReplaceAll("dst", "tree");
      treeFileName.ReplaceAll("event", "tree");
      treeFileName.ReplaceAll("evtsel", "treeSel");

      cout << "tree output file: " << treeFileName << endl;

   //Get the standard root format to be independent of Star IO   
      m_outfile = new TFile(treeFileName, "recreate");
      m_outfile->SetCompressionLevel(1);
   }

   cout << "Exiting InitRun(Int_t runnr)" << endl;
   return StMaker::InitRun(runnr);
}


Int_t StPeCMaker::Make()
{
   StEvent* event = 0;
   Int_t flag = kStOk;


   Int_t NTracks = 0 ;
   int tw        = 0 ;
   if(muDst)
   {
      NTracks = muDst->globalTracks()->GetEntries();
       
      StL0Trigger &trig = muDst->event()->l0Trigger();
      tw = trig.triggerWord();

      trigger->process(muDst);

   }
   else
   {
      event = (StEvent *)GetInputDS("StEvent");
      if (!event)
      {
	 cout << "There was no StEvent! Exiting..." << endl;
	 return kStOK; 
      }
      //Process StEvent trigger simulations
      trigger->process(event);

      StSPtrVecTrackNode& tempn = event->trackNodes();
      NTracks = tempn.size();

      tw = event->l0Trigger()->triggerWord();
   }


   //Fill geant simulations
   TDataSet* geantBranch = GetInputDS("geantBranch");
   if (geantBranch)
   {
      geant->fill(geantBranch);
   }

   //  Check number of tracks


   if(NTracks > StPeCnMaxTracks) {
      cout << "Number of tracks: " << NTracks << endl;
      cout << "Not a peripheral event (NTracks > 15)" << endl;
//    flag = kStErr;
   }
   if(NTracks <= 1) {
      cout << "Event has no tracks" << endl;
      flag = kStErr;
   }

   if (tw == 0x3001 || tw==0x3002 || tw == 0x3011 || tw == 0x1001)
      cout << "UPC trigger"  << endl;

   //Fill StPeCEvent
   if ( geantBranch || (flag == kStOk) ) {

      int ok = 0 ;
      if (event) ok = pevent->fill(event);
      else       ok = pevent->fill(muDst);

      if ( !ok ) {
	 uDstTree->Fill();
      }

      //Select only 4 prong candidates
      //NOTE: This does not appear to do anything because the return code isn't used
      if (event)
      {
	 if (filter == 1)
	    flag = Cuts(event, pevent);
	 else if (filter == 2)
	    flag = Cuts4Prong(event, pevent);
      }
   }
   else
      cout << "Do Not fill Event to Tree!" << endl;


   //Cleanup
   pevent->clear();
   geant->clear();
   trigger->clear();

   cout << "Exiting StPeCMaker::Make()" << endl;


   return kStOk;
}


Int_t StPeCMaker::Cuts(StEvent *event, StPeCEvent *pevent)
{
	StPrimaryVertex* vtx = event->primaryVertex();


	cout << "Entering StPeCMaker::Cuts(StEvent *event, StPeCEvent *pevent)" << endl;

	//Get vertex info
	if (!vtx)
		return kStErr;

	if (vtx->position().x() < -5.)
		return kStErr;
	if (vtx->position().x() >  5.)
		return kStErr;
	if (vtx->position().y() < -5.)
		return kStErr;
	if (vtx->position().y() >  5.)
		return kStErr;

	if (fabs(vtx->position().z()) >  200.)
		return kStErr ;

	//Select interesting events
	if (pevent->getNPriPairs() != 1)
		return kStErr;

	StPeCPair *pair = pevent->getPriPair(0);
	if (pair->getOpeningAngle() > 3.0)
		return kStErr;
	if (pair->getSumCharge())
		return kStErr;



	return kStOK;
}


Int_t StPeCMaker::Cuts4Prong(StEvent *event, StPeCEvent *pevent)
{

	if (pevent->getNTot() != 4)
		return kStErr;
	if (fabs(pevent->getZVertex()) > 200)
		return kStErr;
	if (pevent->getNPriPairs() != 1)
		return kStErr;
	if (pevent->getNSecPairs() != 1)
		return kStErr;
	if (pevent->getPriPair(0)->getSumCharge())
		return kStErr;
	if (pevent->getSecPair(0)->getSumCharge())
		return kStErr;
	if (pevent->getPriPair(0)->getOpeningAngle() > 3)
		return kStErr;
	if (pevent->getSecPair(0)->getOpeningAngle() > 3)
		return kStErr;



	return kStOK;
}


Int_t StPeCMaker::Finish()
{
	cout << "Entering StPeCMaker::Finish()" << endl;

	m_outfile->Write();
	m_outfile->Close();
	StMaker::Finish();



	return kStOK;
}


