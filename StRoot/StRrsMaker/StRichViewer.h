/*********************************************************
 * $Id: StRichViewer.h,v 1.1 2000/01/18 21:32:04 lasiuk Exp $
 *
 * Description:
 *  Struct holds different histograms filled by different
 *  function throughout the program. 
 *
 *  It creates a root Canvas, and draws histograms in it.
 *
 ************************************************************
 * $Log: StRichViewer.h,v $
 * Revision 1.1  2000/01/18 21:32:04  lasiuk
 * Initial Revision
 *
 * Revision 1.1  2000/01/18 21:32:04  lasiuk
 * Initial Revision
 *
 *  Revision history:

 * 
 ***********************************************************/
#include "StRichRrsMacros.h"
#ifdef RICH_WITH_VIEWER
#ifndef ST_RICH_VIEWER_H
#define ST_RICH_VIEWER_H

#include "TROOT.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TH1.h"
#include "TH2.h"

#ifndef ST_NO_NAMESPACES
    struct StRichViewer {

	StRichViewer();
	~StRichViewer();
	static StRichViewer* getView();   // sole instance access
	void update();

	TH1F    * mParticleId;       // Types of particles
	TH1F    * mWhichQuadrant;    // Quadrants hit            
	TH1F    * mClusterElectrons; // Electrons in Ionization Clusters
	TH1F    * mErrorDetection;   // Counts exceptions - desactivated
	TH1F    * mWires;            // wires with charge - obsolete
	TH1F    * mWhichWire;        // wires with charge
	TH1F    * mFeedback;         // feedback photons
	TH1F    * mPolia;            // Polia distribution
	TH1F    * mNoise;            // Electric noise on pads
	TH1F    * mTotalCharge;      // Charge simulated vs. charge collected
	
	TH2F    * mADCSignal;        // ADC counts
	TH2F    * mAnalogSignals;    // Analog Signals
	TH2F    * mPadPlane;         // Initial hits
	
	static int      histograms;  // flag turning them off
	static StRichViewer * p2View;      // handle to only instance
	
	TCanvas * mCanvas1;
	TFile   * mHFile;

    };
    TFile   * mHFile;
    
};

#ifndef ST_NO_NAMESPACES
//}
#endif

#endif // ST_RICH_VIEWER_H

#endif // RICH_WITH_VIEWER
