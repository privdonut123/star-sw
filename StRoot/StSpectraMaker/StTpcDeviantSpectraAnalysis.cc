#include "StTpcDeviantSpectraAnalysis.h"
#include "StTpcDedxPidAlgorithm.h"
#include "SystemOfUnits.h"
#include "PhysicalConstants.h"
#include <string.h>
#include <TFile.h>
#include "StEventTypes.h"

StTpcDeviantSpectraAnalysis::StTpcDeviantSpectraAnalysis() {}

StTpcDeviantSpectraAnalysis::~StTpcDeviantSpectraAnalysis() {}

void StTpcDeviantSpectraAnalysis::bookHistograms() {

  mNumEvent = 0;
 
  float ldevbin = -5.;
  float udevbin = 5. ;
  int Ndevbins = 50;

  // use abscissa and ordinate types
  string hlab2DSpectra = "YPt";

  hlab2DSpectra = hlab2DSpectra + mTitle;
  const char* h2DSpectra = hlab2DSpectra.c_str(); 
  m2DSpectra = new TH2D(h2DSpectra,"2-D spectra",
			 mnbinAbscissa, mlbinAbscissa,mubinAbscissa,
			 mnbinOrdinate,mlbinOrdinate,mubinOrdinate);
  m2DSpectra->Sumw2();

  string hlabDedx = "dedxvsP";
  hlabDedx = hlabDedx + mTitle;
  const char* hDedx = hlabDedx.c_str(); 
  mDedxvsP = new TH2D(hDedx,"dedx vs p",50,0.,1.,50, 0., 1.e-05);
  mDedxvsP->Sumw2();

  string hlab2DSpectraDev = "YPtDeviant";

  hlab2DSpectraDev = hlab2DSpectraDev + mTitle;
  const char* h2DSpectraDev = hlab2DSpectraDev.c_str(); 
  m2DSpectraDeviant = new TH3D(h2DSpectraDev,
			       "number sigma from PID band in 2D phase space bins",
			 mnbinAbscissa, mlbinAbscissa,mubinAbscissa,
			 mnbinOrdinate,mlbinOrdinate,mubinOrdinate,
			 Ndevbins,ldevbin,udevbin);
  m2DSpectraDeviant->Sumw2();  


  string hlabPID = "PIDDeviant";
  hlabPID = hlabPID + mTitle;
  const char* hPID = hlabPID.c_str(); 
  mPIDDeviant = new TH1D(hPID,"number sigma from pid band",
		Ndevbins,ldevbin,udevbin);
  mPIDDeviant->Sumw2();
}

void StTpcDeviantSpectraAnalysis::fillHistograms(StEvent& event) {

  StVertex* primvtx = event.primaryVertex();
  if (primvtx==0) return;
  mNumEvent++ ; 
 
  double mMassPid = mParticle->mass();
  cout << mParticle->charge() << endl;

  const StSPtrVecPrimaryTrack& tracks = event.primaryVertex()->daughters();
  StPrimaryTrackIterator iter;
  StPrimaryTrack *track;

  for (iter = tracks.begin();
       iter != tracks.end(); iter++) {
    track = *iter;
    if (track==0) continue;
       StTpcDedxPidAlgorithm tpcDedxAlgorithm;
          // 
	  // check to see if track satisfies the quality cuts set up
	  // for this analysis
	  //
       vector<StSpectraCut*>::const_iterator cutIter;
       bool satisfiesAllCuts = true ;
       for (cutIter = mEffic.mSpectraCutContainer.begin();
	    cutIter != mEffic.mSpectraCutContainer.end();
	    cutIter++) {
	    if (!((*cutIter)->satisfiesCut(track,&event)) && satisfiesAllCuts){
	       satisfiesAllCuts = false;
	    }
       }

       if (satisfiesAllCuts && 
	      fabs(mParticle->charge() - 
		   track->geometry()->charge())<0.01) {

	    StThreeVectorD mom = track->geometry()->momentum();
	    double p = abs(mom);

       // now apply pid algorithm tpcDedxAlgorithm, which finds the tpc dedx
       // object in the collection of pidTraits, and initializes
       // the data members of the algorithm
       // which can then be accessed through member functions
       // of the algorithm e.g. numberOfSigma
       // guess is currently not used
       //
            track->pidTraits(tpcDedxAlgorithm);
	    double deviant = tpcDedxAlgorithm.numberOfSigma(mParticle);


	    double effic = mEffic.efficiency(track);
	    //  cout << effic << endl;
	    if (effic > 0. && effic <= 1.) {
		float weight = 1./effic;
		double pperp = mom.perp();
		// double mt = sqrt(pperp*pperp + mMassPid*mMassPid);
		double E = sqrt(p*p+mMassPid*mMassPid);
		double pz = mom.z();
		double y = 0.5*log((E+pz)/(E-pz)); 
		m2DSpectraDeviant->Fill(y,pperp,deviant,weight);
	    }
       }       
  }   
}

void StTpcDeviantSpectraAnalysis::projectHistograms() {

  if (mNumEvent==0) return;
  float xnorm = 1./float(mNumEvent);
  m2DSpectraDeviant->Scale(xnorm);

  // check for histograms
  cout << m2DSpectraDeviant->GetDimension() << "-D histogram" << endl;
  int NYbins  = m2DSpectraDeviant->GetNbinsX();
  int NPtbins = m2DSpectraDeviant->GetNbinsY();

  cout << "has "<< NYbins*NPtbins << " bins" << endl ;
 
  Stat_t stats[8];
  m2DSpectraDeviant->GetStats(stats);
  cout << "sum of weights " << stats[0] << endl;

}

void StTpcDeviantSpectraAnalysis::writeHistograms(){

  const char* outputName = ((*this).getTitle()+".root").c_str();
  TFile* analysisOutputFile = new TFile(outputName,"RECREATE");
  m2DSpectraDeviant->Write(outputName);
  mPIDDeviant->Write(outputName);
  delete analysisOutputFile;
}






