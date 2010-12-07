#include <stdio.h>
#include <stdlib.h>

#include "Jevp/StJevpPlot/JevpPlotSet.h"
#include "DAQ_READER/daqReader.h"
#include "DAQ_READER/daq_dta.h"
#include "DAQ_READER/daq_det.h"
#include "StDaqLib/TRG/trgStructures2009.h"
#include "StEvent/StTriggerData2009.h"

#include "Jevp/StJevpPlot/RunStatus.h"
#include "StEvent/StTriggerData.h"
#include <TH1I.h>
#include <TH2F.h>

#include <math.h>
#include "bbcBuilder.h"
#include <RTS/include/rtsLog.h>

// This is the one PlotSet that is guarenteed to always exist
// It's main purpose is to provide the run information 
// To the server...
//
// It has no plots (currently)
//


ClassImp(bbcBuilder);
  
typedef JevpPlot * ptrJevpPlot;

bbcBuilder::bbcBuilder() {
  plotsetname = (char *)"bbc";
  
  int np = sizeof(contents) / sizeof(TH1 *);

  plots = new ptrJevpPlot[np]();
  // start with histograms undefined...
  memset(&contents, 0, sizeof(contents));
  memset(plots, 0, sizeof(JevpPlot *) * np);
}

bbcBuilder::~bbcBuilder() {
  // Delete any existing histograms...
  int n = sizeof(contents) / sizeof(TH1 *);
  for(int i=0;i<n;i++) {
    if(plots[i]) delete plots[i];
  }
  
  delete plots;
}

void bbcBuilder::initialize(int argc, char *argv[]) {

  // Build Root Histograms...
  
  contents.h190_bbc_hitmap_EAST = new TH1F("h190_bbc_hitmap_EAST","Hit Pattern BBC EAST",24,0.5,24.5);
  contents.h191_bbc_hitmap_WEST = new TH1F("h191_bbc_hitmap_WEST","Hit Pattern BBC WEST",24,0.5,24.5);
  contents.h192_bbc_weight_hitmap_EAST = new TH1F("h192_bbc_weight_hitmap_EAST","Weighted Hit Pattern BBC EAST",24,0.5,24.5);
  contents.h193_bbc_weight_hitmap_WEST = new TH1F("h193_bbc_weight_hitmap_WEST","Weighted Hit Pattern BBC WEST",24,0.5,24.5);
  
  contents.h194_bbc_hits_east = new TH1F("h194_bbc_hits_east","BBC Small-tile Hits East",17,-0.5,16.5);
  contents.h195_bbc_hits_west = new TH1F("h195_bbc_hits_west","BBC Small-tile Hits West",17,-0.5,16.5);
  contents.h196_bbcl_hits_east = new TH1F("h196_bbcl_hits_east","BBC Large-tile Hits East",9,-0.5,8.5);
  contents.h197_bbcl_hits_west = new TH1F("h197_bbcl_hits_west","BBC Large-tile Hits West",9,-0.5,8.5);
  contents.h198_bbc_AdcSum_east = new TH1F("h198_bbc_AdcSum_east","BBC Small-tile AdcSum East",128,0,4096);
  contents.h199_bbc_AdcSum_west = new TH1F("h199_bbc_AdcSum_west","BBC Small-tile AdcSum West",128,0,4096);
  contents.h200_bbcl_AdcSum_east = new TH1F("h200_bbcl_AdcSum_east","BBC Large-tile AdcSum East",128,0,4096);
  contents.h201_bbcl_AdcSum_west = new TH1F("h201_bbcl_AdcSum_west","BBC Large-tile AdcSum West",128,0,4096);

  for(int i=0;i<16;i++) {
    char tmp[256];
    char tmp1[256];
    sprintf(tmp, "bbce_tdc_%d",i);
    sprintf(tmp1, "BBCE TDC %d",i);

    contents.bbce_tdc[i] = new TH1F(tmp,tmp1,128,0,4096);

    sprintf(tmp, "bbcw_tdc_%d",i);
    sprintf(tmp1, "BBCW TDC %d",i);
    contents.bbcw_tdc[i] = new TH1F(tmp,tmp1,128,0,4096);
  }

  contents.h202_bbc_earliest_tac_east = new TH1F("h202_bbc_earliest_tac_east","BBC East Earliest TAC",256,0,4096);
  contents.h203_bbc_earliest_tac_west = new TH1F("h203_bbc_earliest_tac_west","BBC West Earliest TAC",256,0,4096);
  contents.h204_bbc_tac_difference_ew = new TH1F("h204_bbc_tac_difference_e-w","BBC TAC Difference",256,-4096,4096);
  contents.h452_bbc_tac_difference_ew = new TH1F("h452_bbc_tac_difference_e-w","BBC Vertex (cm)",256,-300,300);
  contents.h205_bbc_tac_e_w = new TH2F("h205_bbc_tac_e_w","BBC TAC East vs West",64,0,4096,64, 0,4096);

  
  // Add root histograms to Plots
  JevpPlot *plots[100];
  int n=0;

  plots[n] = new JevpPlot(contents.h190_bbc_hitmap_EAST);
  plots[++n] = new JevpPlot(contents.h191_bbc_hitmap_WEST);
  plots[++n] = new JevpPlot(contents.h192_bbc_weight_hitmap_EAST);
  plots[++n] = new JevpPlot(contents.h193_bbc_weight_hitmap_WEST);
  plots[++n] = new JevpPlot(contents.h194_bbc_hits_east);
  plots[++n] = new JevpPlot(contents.h195_bbc_hits_west);
  plots[++n] = new JevpPlot(contents.h196_bbcl_hits_east);
  plots[++n] = new JevpPlot(contents.h197_bbcl_hits_west);
  plots[++n] = new JevpPlot(contents.h198_bbc_AdcSum_east);
  plots[++n] = new JevpPlot(contents.h199_bbc_AdcSum_west);
  plots[++n] = new JevpPlot(contents.h200_bbcl_AdcSum_east);
  plots[++n] = new JevpPlot(contents.h201_bbcl_AdcSum_west);

  for(int i=0;i<16;i++) plots[++n] = new JevpPlot(contents.bbce_tdc[i]);       
  for(int i=0;i<16;i++) plots[++n] = new JevpPlot(contents.bbcw_tdc[i]);

  plots[++n] = new JevpPlot(contents.h202_bbc_earliest_tac_east);
  plots[++n] = new JevpPlot(contents.h203_bbc_earliest_tac_west);
  plots[++n] = new JevpPlot(contents.h204_bbc_tac_difference_ew);
  plots[++n] = new JevpPlot(contents.h452_bbc_tac_difference_ew);
  plots[++n] = new JevpPlot(contents.h205_bbc_tac_e_w);
  plots[n]->setDrawOpts("colz");
  plots[n]->setOptStat(0);
 

  // Add Plots to plot set...
  for(int i=0;i<=n;i++) {
    LOG("JEFF", "Adding plot %d",i);
    addPlot(plots[i]);
    if(i<8) plots[i]->logy = 1;

    contents.array[i]->SetFillColor(30);
  }
  
}
  
void bbcBuilder::startrun(daqReader *rdr) {
  LOG("JEFF", "TriggerPlotBuilder starting run #%d",rdr->run);
  resetAllPlots();
}

void bbcBuilder::event(daqReader *rdr)
{
  StTriggerData2009 *trgd2009;
  int run = rdr->run;

  daq_dta *dd = rdr->det("trg")->get("raw");
  if(dd && dd->iterate()) {
    char *td = (char *)dd->Void;
    
    if(td[3] != 0x40) {
      LOG("ERR", "TRG RAW: version mismatch 0x%2x-0x%2x-0x%2x-0x%2x", td[0], td[1], td[2], td[3]);
      return;
    }

    TriggerDataBlk2009 *trgdatablock2009 = (TriggerDataBlk2009 *)td;
    trgd2009 = new StTriggerData2009(trgdatablock2009, run);
  }
  else {
    LOG(ERR, "No trigger data exists...");
    return;
  }
  
  StTriggerData *trgd = (StTriggerData *)trgd2009;

  //BBC
  double bbcTimeDiff = -9999;
  double bbcVertex   = -9999;
  int nhit[2]={0,0},nhitl[2]={0,0};
  for(int i=0; i<2; i++){
    for(int j=1; j<=24; j++){
      float adc = (float)trgd->bbcADC((StBeamDirection)i,j);
      if(adc>5) {
	if(j<=16) nhit[i]++;
	else      nhitl[i]++;

	if(i==0) {
	  contents.h190_bbc_hitmap_EAST->Fill(j);
	  contents.h192_bbc_weight_hitmap_EAST->Fill(j,adc);
	}
	if(i==1) {
	  contents.h191_bbc_hitmap_WEST->Fill(j); 	 
	  contents.h193_bbc_weight_hitmap_WEST->Fill(j,adc);
	}
      }
    }
    for(int j=1; j<=16; j++){
      float tac=(float)trgd->bbcTDC((StBeamDirection)i,j);

      if(i==0) {
	contents.bbce_tdc[j-1]->Fill(tac);
      }
      if(i==1) {
	contents.bbcw_tdc[j-1]->Fill(tac);
      }
    }
  }

  contents.h194_bbc_hits_east->Fill(nhit[0]);
  contents.h195_bbc_hits_west->Fill(nhit[1]);
  contents.h196_bbcl_hits_east->Fill(nhitl[0]);
  contents.h197_bbcl_hits_west->Fill(nhitl[1]);
  contents.h198_bbc_AdcSum_east->Fill(trgd->bbcADCSum(east));
  contents.h199_bbc_AdcSum_west->Fill(trgd->bbcADCSum(west));
  contents.h200_bbcl_AdcSum_east->Fill(trgd->bbcADCSumLargeTile(east));
  contents.h201_bbcl_AdcSum_west->Fill(trgd->bbcADCSumLargeTile(west));
  contents.h202_bbc_earliest_tac_east->Fill(trgd->bbcEarliestTDC(east));
  contents.h203_bbc_earliest_tac_west->Fill(trgd->bbcEarliestTDC(west));
  
  if( trgd->bbcEarliestTDC(east)>10 && trgd->bbcEarliestTDC(east)<3000 &&
      trgd->bbcEarliestTDC(west)>10 && trgd->bbcEarliestTDC(west)<3000 ) {
    bbcTimeDiff = trgd->bbcTimeDifference()-4096;
    //mBbcVertex   = mBbcTimeDiff/3/10.0;     
    bbcVertex   = bbcTimeDiff/2 *0.02*30;      
    contents.h204_bbc_tac_difference_ew->Fill(bbcTimeDiff);
    contents.h452_bbc_tac_difference_ew->Fill(bbcVertex);
  }
  contents.h205_bbc_tac_e_w->Fill(trgd->bbcEarliestTDC(east), trgd->bbcEarliestTDC(west));

  if(trgd) delete trgd;
}

void bbcBuilder::stoprun(daqReader *rdr) {
//   printf("Stopping run #%d\n",run);
//   status.setEndOfRun(1);
//   send((TObject *)&status);
}

void bbcBuilder::main(int argc, char *argv[])
{
  bbcBuilder me;
  
  me.Main(argc, argv);
}

