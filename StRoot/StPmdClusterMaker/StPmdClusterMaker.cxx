/*************************************************
 *
 * $Id: StPmdClusterMaker.cxx,v 1.8 2004/06/29 17:31:23 perev Exp $
 * Author: Subhasis Chattopadhyay
 *************************************************
 *
 * Description: Base class for Pmd cluster Maker
 *
 *************************************************
 *
 * $Log: StPmdClusterMaker.cxx,v $
 * Revision 1.8  2004/06/29 17:31:23  perev
 * Zeroing in ctr added and tests for null pointers
 *
 * Revision 1.7  2004/06/24 13:46:52  subhasis
 * several changes in clustering code
 *
 * 2004/06/24: findCpvCluster() function removed,
 * findPmdCluster() has been called for both the planes.
 * New clustering algorithm has been implemented.
 * Presently we are filling SigmaL only(not SigmaS)
 * in StEvent with function name sigma() but in 
 * TDataSet both SigmaL and SigmaS are present : Dipak
 * 
 * Revision 1.6  2004/03/23 05:18:54  subhasis
 * refclust changed to have correct sigma/ncell
 *
 * Revision 1.4  2003/09/02 17:58:48  perev
 * gcc 3.2 updates + WarnOff
 *
 * Revision 1.3  2003/05/14 10:49:12  subhasis
 * CPV clustering added
 *
 *
 *************************************************/

#include<Stiostream.h>
#include<assert.h>
#include<math.h>
#include"TROOT.h"
#include<TRandom.h>
#include<TBrowser.h>
#include<TPad.h>
#include<StMessMgr.h>
#include<TFile.h>

#include "StBFChain.h"
#include "StPmdUtil/StPmdGeom.h"
#include "StPmdClusterMaker.h"
#include "StPmdAbsClustering.h"
#include "StPmdClustering.h"
#include "StPmdUtil/StPmdDetector.h" //! will be obtained 
#include "StPmdUtil/StPmdModule.h" //! will be obtained 
#include "StPmdUtil/StPmdCollection.h" //! will be obtained 
#include "StPmdUtil/StPmdClusterCollection.h" //! will be obtained 
#include "StPmdUtil/StPmdCluster.h" //! will be obtained 


#include "StEventTypes.h"

ClassImp(StPmdClusterMaker)
  
  TDataSet *clusterIn;
StPmdCollection *cluster_hit;
//-------------------- 
StPmdClusterMaker::StPmdClusterMaker(const char *name):StMaker(name)
{
}
//-------------------

StPmdClusterMaker::~StPmdClusterMaker()
{
}
//---------------------
Int_t StPmdClusterMaker::Init()
{
  
  bookHistograms();
  
  return StMaker::Init();
}

//--------------------------------------
void StPmdClusterMaker::bookHistograms()
{
  mSmPmdCluster   = new TH1F("Smno_pmd","SuperModule No",24,1.,24.);
  mEdepPmdCluster = new TH1F("EdepPmd","Energy deposited",10000,0.,10000);  
  mSigmaLPmdCluster = new TH1F("SigmaLClusterPmd","Cluster SigmaL",50,0.5,4.5);  
  mSigmaSPmdCluster = new TH1F("SigmaSClusterPmd","Cluster SigmaS",50,0.5,4.5);  
  mNcellPmdCluster = new TH1F("NcellPmd","No of Cells per cls",50,-0.5,49.5);  
  mEtaPmdCluster  = new TH1F("EtaPmd","Eta Distribution",100,-4.,-2.);  
  mPhiPmdCluster  = new TH1F("PhiPmd","Phi Distribution",100,-3.14,3.14);
  mPmdCluster  = new TH1F("PmdCluster"," NCluster in PMD",100,0,5000);
  mPhi2ModPmd  = new TH2F("Phi2ModPmd","Phi vs Mod",12,0.5,12.5,360,-3.14,3.14);
  mHitVscluster  = new TH2F("Pmd_hitvsClus","Hit vsclusPMD",50,0.5,50.5,50,0.5,50.5);
  mSigmaLCpvCluster = new TH1F("SigmaLClusterCpv","Cluster SigmaL",50,0.5,4.5);  
  mSigmaSCpvCluster = new TH1F("SigmaSClusterCpv","Cluster SigmaS",50,0.5,4.5);  
  mSmCpvCluster   = new TH1F("Smno_cpv","CPV SuperModule No",24,1.,24.);
  mEdepCpvCluster = new TH1F("EdepCpv","Cpv Energy deposited",5000,0.,5000.);  
  mNcellCpvCluster = new TH1F("NcellCpv","No of Cellsper cls (CPV)",50,-0.5,49.5);  
  mEtaCpvCluster  = new TH1F("EtaCpv","Cpv Eta Distribution",100,-4.,-2.);  
  mPhiCpvCluster  = new TH1F("PhiCpv","Cpv Phi Distribution",100,-3.14,3.14);
  mCpvCluster  = new TH1F("CPVCluster"," NCluster in CPV",100,0,5000);
  mXYCpvCluster = new TH2F("CPV2D" ,"CPV Cluster 2D", 400,-200.,200.,400,-200.,200.);
  mXYPmdCluster = new TH2F("PMD2D" ,"PMD Cluster 2D", 400,-200.,200.,400,-200.,200.);
}
//--------------------------------
Int_t StPmdClusterMaker::Make() 
{
  clusterIn = GetDataSet("PmdSimulator"); //! getting data from StPmdSimulator
  if(!clusterIn){
    clusterIn = GetDataSet("pmdReader"); //! getting data from StPmdReader
  }
  if(!clusterIn){
    cout<<" No Hit_dataset found, return "<<endl;
    return kStWarn;
  }
  cluster_hit = (StPmdCollection*)clusterIn->Find("PmdCollection");
  
  if(!cluster_hit){
    cout<<" No PmdCollection found, return "<<endl;
    return kStWarn;
  }
  
  
  if(cluster_hit)
    {
      StPmdDetector * cpv_det = cluster_hit->detector(Int_t(0)); //CPV = 0 in PmdCollection
      StPmdDetector * pmd_det = cluster_hit->detector(Int_t(1)); //PMD = 1 in PmdCollection
      StPmdClustering *clust1=0; // added for getting pointer to StPmdClustering
      Int_t choice=1; // Enter choice
      if(choice==1){
//        clust1 = new StPmdClustering(pmd_det, cpv_det);
	if(clust1)
	  {
	    for(Int_t d=0;d<2;d++)  // Loop over detectors
	      {
		StPmdDetector *det = cluster_hit->detector(d); //PMD = 1 and 0 for CPV in PmdCollection
		clust1->findPmdClusters(det); //! find Clustering 
	      } //for loop 'd'
      }
	else
	  {
	    cout<<"clust1 not made"<<endl;
	  }
      } // if loop 'choice'
      
      FillStEvent(pmd_det,cpv_det);
      FillHistograms(pmd_det,cpv_det);
      
    }
  return kStOK;
}/*! loop for make ends here.*/
//--------------------------
void StPmdClusterMaker::Browse(TBrowser *b)
{
  TDataSet::Browse(b);
}
//---------------------------------------------------
void StPmdClusterMaker::FillHistograms(StPmdDetector* pmd_det, StPmdDetector* cpv_det)
{
  //! Get Hits
  Int_t tothitpmd=0;
  Int_t tothitcpv=0;
  for(Int_t id=1;id<=12;id++){
    if(pmd_det->module_hit(id)>0){
      Int_t nmh=pmd_det->module_hit(id);
      tothitpmd+=nmh;  
    }
    
    if(cpv_det->module_hit(id)>0){
      Int_t nmh1=cpv_det->module_hit(id);
      tothitcpv+=nmh1;  
    }
  }
  
  StPmdClusterCollection* clusters = (StPmdClusterCollection*)pmd_det->cluster();
  StPmdClusterCollection* cpvclusters = (StPmdClusterCollection*)cpv_det->cluster();
  
  Int_t nclust     = (clusters   )? clusters->Nclusters()   :0;   //! no of Pmd clusters
  
  Int_t nclust_cpv = (cpvclusters)? cpvclusters->Nclusters():0; //! no of Cpv clusters
  
  //! First Fill PMD
  if ( nclust ) {
    TIter next(clusters->Clusters());

    StPmdCluster *spmcl1;
    for(Int_t i=0; i<nclust ; i++)
      {
	spmcl1 = (StPmdCluster*)next();
	Float_t eta=spmcl1->CluEta(); 
	Float_t phi=spmcl1->CluPhi();
	Float_t edep=spmcl1->CluEdep();
	Float_t sigmaL=spmcl1->CluSigmaL();
	Float_t sigmaS=spmcl1->CluSigmaS();
	Int_t mod=spmcl1->Module();
	Float_t ncell=spmcl1->NumofMems();
	Float_t xclu = spmcl1->CluX();
	Float_t yclu = spmcl1->CluY();

	mSmPmdCluster->Fill(Float_t(mod));
	mEdepPmdCluster->Fill(edep);    // In keV
	mSigmaLPmdCluster->Fill(sigmaL);
	mSigmaSPmdCluster->Fill(sigmaS);
	mNcellPmdCluster->Fill(ncell);
	mEtaPmdCluster->Fill(eta);
	mPhiPmdCluster->Fill(phi);
	mXYPmdCluster->Fill(xclu,yclu);
      }
  }
  mHitVscluster->Fill(tothitpmd,Float_t(nclust));
  mPmdCluster->Fill(nclust);
  mCpvCluster->Fill(nclust_cpv);  
  //! NOW for Fill CPV
  if (nclust_cpv) {
    TIter nextcpv(cpvclusters->Clusters());
    StPmdCluster *spmcl2;
    for(Int_t i=0; i<nclust_cpv ; i++)
      {
	spmcl2 = (StPmdCluster*)nextcpv();
	Float_t eta=spmcl2->CluEta();
	Float_t phi=spmcl2->CluPhi();
	Float_t edep=spmcl2->CluEdep();
	Int_t mod=spmcl2->Module();
	Float_t sigmaL=spmcl2->CluSigmaL();
	Float_t sigmaS=spmcl2->CluSigmaS();
	Float_t ncell1=spmcl2->NumofMems();
	Float_t xclu = spmcl2->CluX();
	Float_t yclu = spmcl2->CluY();


	mSmCpvCluster->Fill(Float_t(mod));
	mEdepCpvCluster->Fill(edep); //In keV
	mSigmaLCpvCluster->Fill(sigmaL);
	mSigmaSCpvCluster->Fill(sigmaS);
	mNcellCpvCluster->Fill(ncell1);
	mEtaCpvCluster->Fill(eta);
	mPhiCpvCluster->Fill(phi);
	mXYCpvCluster->Fill(xclu,yclu);
      }
   }
}

Int_t StPmdClusterMaker::Finish()
{
  return StMaker::Finish();
}



//---------------------------------------------------
void StPmdClusterMaker::FillStEvent(StPmdDetector* pmd_det, StPmdDetector* cpv_det)
{
  cout<<"Filling StEvent in ClusterMaker"<<endl;
  // Get StEvent
  StPhmdCollection * PmdCollection; 
  StEvent *currevent = (StEvent*)GetInputDS("StEvent");
  if(!currevent){
    cout<<"ClusterMaker **, No StEvent Pointer "<<endl;
  }
  
  if(currevent)PmdCollection= currevent->phmdCollection();
  if(PmdCollection)
    {
      StPhmdDetector* evtdet0 = PmdCollection->detector(StDetectorId(kPhmdId));
      StPhmdDetector* evtdet1 = PmdCollection->detector(StDetectorId(kPhmdCpvId));
      // add clustercollection
      StPhmdClusterCollection* cluscollpmd = new StPhmdClusterCollection();
      cluscollpmd->setClusterFinderId(1);
      cluscollpmd->setClusterFinderParamVersion(1);
      //CPV
      StPhmdClusterCollection* cluscollcpv = new StPhmdClusterCollection();
      cluscollcpv->setClusterFinderId(1);
      cluscollcpv->setClusterFinderParamVersion(1);
      
      StPmdClusterCollection* clusters = (StPmdClusterCollection*)pmd_det->cluster();
      StPmdClusterCollection* cpvclusters = (StPmdClusterCollection*)cpv_det->cluster();
      
      Int_t nclust     = (clusters   )?clusters->Nclusters()   :0;   //! no of Pmd clusters
      Int_t nclust_cpv = (cpvclusters)?cpvclusters->Nclusters():0; //! no of Cpv clusters
      
      //! First Fill PMD
      if(evtdet0 && clusters)
	{
	  evtdet0->setCluster(cluscollpmd);
	  TIter next(clusters->Clusters());
	  StPmdCluster *spmcl1;
	  for(Int_t i=0; i<nclust ; i++)
	    {
	      spmcl1 = (StPmdCluster*)next();
	      Float_t eta=spmcl1->CluEta();
	      Float_t phi=spmcl1->CluPhi();
	      Float_t edep=spmcl1->CluEdep();
	      Float_t sigmaL=spmcl1->CluSigmaL();
	      // Float_t sigmaS=spmcl1->CluSigmaS();
	      Int_t mod=spmcl1->Module();
	      Float_t ncell=spmcl1->NumofMems();
	      // Filling PmdCluster info in StEvent
	      StPhmdCluster *pcls = new StPhmdCluster();
	      pcls->setModule(mod);           //! Supermodule
	      pcls->setNumberOfCells(Int_t(ncell));  //! # of Cells( Integer type) in a cluster
	      // Commented temporarily because of problem in StEvent
	      // pcls->setNumberOfCells(ncell);  //! # of Cells in a cluster
	      pcls->setEta(eta);              //! Cluster Eta
	      pcls->setPhi(phi);              //! Cluster Phi
	      pcls->setEnergy(edep);          //! Cluster Edep
	      pcls->setSigma(sigmaL);           //! Filling Sigma Large
		// Presently we are filling SigmaL only into StEvent
		// Later on we will fill both the parameter( L & S)
		//Following two lines are temporarily commented
	      // pcls->setSigmaL(sigmaL);        //! Cluster Sigma Large
	      // pcls->setSigmaS(sigmaS);        //! Cluster Sigma Small 
	      cluscollpmd->addCluster(pcls);  // Adding to ClusterCollection in StEvent
	    }       
	} 
      //! NOW for Fill CPV
      if(evtdet1 && cpvclusters)
	{
	  evtdet1->setCluster(cluscollcpv);
	  TIter nextcpv(cpvclusters->Clusters());
	  StPmdCluster *spmcl2;
	  for(Int_t i=0; i<nclust_cpv ; i++)
	    {
	      spmcl2 = (StPmdCluster*)nextcpv();
	      Float_t eta=spmcl2->CluEta();
	      Float_t phi=spmcl2->CluPhi();
	      Float_t edep=spmcl2->CluEdep();
	      Float_t sigmaL=spmcl2->CluSigmaL();
	      //  Float_t sigmaS=spmcl2->CluSigmaS();
	      Int_t mod=spmcl2->Module();
	      Float_t ncell=spmcl2->NumofMems();
	      // Filling PmdCluster for StEvent
	      StPhmdCluster *pcls = new StPhmdCluster();
	      pcls->setModule(mod);            //! Supermodule
	      pcls->setNumberOfCells(Int_t(ncell));  //! # of Cells( Integer type) in a cluster
	      // Commented temporarily because of problem in StEvent
	      //  pcls->setNumberOfCells(ncell);   //! # of Cells in a cluster
	      pcls->setEta(eta);               //! Cluster Eta
	      pcls->setPhi(phi);               //! Cluster Phi
	      pcls->setEnergy(edep);           //! Cluster Edep
	      pcls->setSigma(sigmaL);           //! Filling Sigma Large
		
		// Presently we are filling SigmaL only into StEvent
		// Later on we will fill both the parameter( L & S)
		//Following two lines are temporarily commented
		// pcls->setSigmaL(sigmaL);        //! Cluster Sigma Large
		//  pcls->setSigmaS(sigmaS);         //! Cluster Sigma Small
	      cluscollcpv->addCluster(pcls);   // Adding to ClusterCollection in StEvent
	    }       
	}
    }
    cout<<"Filled PMD StEvent in ClusterMaker"<<endl;
}





