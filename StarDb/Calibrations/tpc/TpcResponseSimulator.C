#include "tables/St_TpcResponseSimulator_Table.h"

// $Id: TpcResponseSimulator.C,v 1.15 2018/10/17 20:45:17 fisyak Exp $
// $Log: TpcResponseSimulator.C,v $
// Revision 1.15  2018/10/17 20:45:17  fisyak
// Restore update for Run XVIII dE/dx calibration removed by Gene on 08/07/2018
//
// Revision 1.13  2018/08/06 15:41:44  fisyak
// RunXVIII isobar dE/dx calibration
//
// Revision 1.12  2012/04/03 14:06:55  fisyak
// Speed up using  GetSaveL (__PAD_BLOCK__), sluggish shape histograms, Heed electron generation
//
// Revision 1.6  2012/01/18 13:57:57  fisyak
// Adjust T0offset : Xianglei Zhu from Run 11 AuAu 27 & 19.6 GeV embedding
//
// Revision 1.5  2011/12/30 00:04:01  fisyak
// Freeze parameters for y2011 base on TpcRS_2011_pp500LowLum_Q
//
// Revision 1.3  2011/10/11 19:09:23  fisyak
// Add Yi Guo's tables for Run XI AuAu200 RFF dE/dx calibration
//
// Revision 1.2  2010/10/28 23:41:54  fisyak
// extra t0 off set for Altro chip
//
// Revision 1.7  2010/06/14 23:36:08  fisyak
// Freeze version V
//
// Revision 1.6  2010/05/24 21:39:53  fisyak
// Fix bracket
//
// Revision 1.5  2010/05/24 16:07:20  fisyak
// Add default dE/dx calibration tables, replace TpcAltroParameters and asic_thresholds_tpx by tpcAltroParams
//
// Revision 1.4  2010/04/19 15:05:58  fisyak
// Final (2010_i) parameters for Run X
//
// Revision 1.3  2010/04/16 19:31:19  fisyak
// Intermidiate version
//
// Revision 1.3  2010/04/04 23:14:33  fisyak
// Add Row Correction
//
// Revision 1.2  2010/04/01 22:17:57  fisyak
// Freeze version W
//
TDataSet *CreateTable() { 
  // -----------------------------------------------------------------
  // db/.const/StarDb/Calibrations/tpc/.TpcResponseSimulator/TpcResponseSimulator Allocated rows: 1  Used rows: 1  Row size: 124 bytes
  //  Table: TpcResponseSimulator_st[0]--> TpcResponseSimulator_st[0]
  // ====================================================================
  // ------  Test whether this table share library was loaded ------
  if (!TClass::GetClass("St_TpcResponseSimulator")) return 0;
  TpcResponseSimulator_st row;
  St_TpcResponseSimulator *tableSet = new St_TpcResponseSimulator("TpcResponseSimulator",1);
  memset(&row,0,tableSet->GetRowSize());
  row.I0                    = 13.1;// eV, CH4 		       
  row.Cluster    	    = 3.2; // average no. of electrons per primary  			       
  row.W          	    = 26.2;// eV 								       
  row.OmegaTau   	    = 3.02;// fit of data 							       
  row.K3IP       	    = 0.68;//(pads) for a/s = 2.5e-3 and h/s = 0.5 
  row.K3IR       	    = 0.89;//(row)  for a/s = 2.5e-3 and h/s = 0.5 
  row.K3OP       	    = 0.55;//(pads) for a/s = 2.5e-3 and h/s = 1.0 
  row.K3OR       	    = 0.61;//(row)  for a/s = 2.5e-3 and h/s = 1.0 
  row.FanoFactor 	    = 0.3; //                                                                        
  row.AveragePedestal       = 50.0;// 
  row.AveragePedestalRMS    = 1.4; // Old Tpc electronics 
  row.AveragePedestalRMSX   = 0.7; // New Tpx electronics 
  row.tauIntegration        = 2.5*74.6e-9;//   secs 
  row.tauF                  = 394.0e-9;// secs Tpc 
  row.tauP                  = 775.0e-9;// secs Tpc 
  row.tauXI                 =  60.0e-9;// secs Tpx Inner integration time 
  row.tauXO                 =  74.6e-9;// secs Tpx Outer integration time 
  row.tauCI                 =   0;  
  row.tauCO                 =   0;  
  row.SigmaJitterTI         = 0.31;// 0.4317;// 0.25;//ad  0.0;// b for Tpx inner 
  row.SigmaJitterTO         = 0.25;// 0.4300;// E: 0.4801;//0.25;//ad  0.0;// b for Tpx outer 
  row.SigmaJitterXI         = 0;// 0.1027785; // P: 0.1353*1.05/1.10; //O: 0.1353*1.05;// N: 0.1353; // C:0.;
  row.SigmaJitterXO         = 0; // i 0.2;// 0.107525;  // P: 0.1472*1.05/1.03; //O: 0.1472*1.05;// N: 0.1472; // C:0.;
  row.longitudinalDiffusion = 0.0370;// i 0.03624; // Magboltz // HD 0.03624*1.5; //HC 0.03624; // Magboltz 
  row.transverseDiffusion   = 0.073265;// i 0.02218*TMath::Sqrt(1 + row.OmegaTau*row.OmegaTau) ; // Magboltz
  row.NoElPerAdc            = 335.;   // No. of electrons per 1 ADC count
  row.OmegaTauScaleI        = 3.18;// i 2.145*1.515;// HC 1.;// 2.145*1.515;  //i; 2.145*1.4;  //h 2.145;  //ad 2.145*1.25;  //b effective reduction of OmegaTau near Inner sector anode wire
  row.OmegaTauScaleO        = 1.8; // i 1.8  *1.201;  //HC 1.;// 1.8  *1.201;  //i 1.8  *1.1;    //h 1.8;    //ad 1.8  *1.25;  //b effective reduction of OmegaTau near Outer sector anode wire
  // Inner_wire_to_plane_coupling ( 0.533 ) * Inner_wire_to_plane_couplingScale ( 0.843485 )
  // Outer_wire_to_plane_coupling ( 0.512 ) * Outer_wire_to_plane_couplingScale ( 0.725267 )
  row.SecRowCorIW[0] = row.SecRowCorIE[0] = 9.13547015017355246e-01 + 6.84784e-03; 
  row.SecRowCorOW[0] = row.SecRowCorOE[0] = 1.08188887000493295e+00  -2.77741e-02;
  /* SecRow3CGFTpcRS_2005_CuCu22_a :  FitP->Draw("sigma:y>>s(45,0.5,45.5)","(i&&j)/dsigma**2","profg")
                                      Inner : 3.40619e-01, Outer:  2.97670e-01
      SecRow3CGFTpcRS_2005_CuCu22_a : Inner : 3.21839e-01, Outer:  2.86936e-01
      diff                          :         1.11539e-01,         7.92159e-02 
      SecRow3CGFTpcRS_2005_CuCu22_f :         3.44367e-0           2.99333e-01
  */
  const Double_t RowSigmaTrs[4] = {//  
    1.11539e-01, 0., 
    7.92159e-02, 0.};
  Float_t *b = &row.SecRowSigIW[0];
  for (Int_t i = 0; i < 8; i++) {
    b[i] = RowSigmaTrs[i%4];
  }
  row.PolyaInner = 1.38;
  row.PolyaOuter = 1.38;
  //  row.T0offset   = 0.50; // From  Lokesh Kumar for Run X
  // TpcT->Draw("fMcHit.mMcl_t+0.165*Frequency-fRcHit.mMcl_t/64:fMcHit.mPosition.mX3>>T(210,-210,210,100,-2,3)","fNoMcHit==1&&fNoRcHit==1&&fRcHit.mQuality>90","colz")
  // TpcT->Draw("fMcHit.mPosition.mX3-fRcHit.mPosition.mX3:fMcHit.mPosition.mX3>>Z(210,-210,210,100,-2,3)","fNoMcHit==1&&fNoRcHit==1&&fRcHit.mQuality>90","colz")
  // The corection has to be added                                                                    M             P
  //row.T0offset   = 0.50 + 1.65431e-01 -  3.45247e-01 -1.54583e+00 -2.90686e-03+ 1.54353e+00 + 0.0191135  -1.20938e-03 ; //E
  //  row.T0offset   = 0.50-6.83675e-01; // 01/18/12 Xianglei Zhu from Run 11 AuAu 27 & 19.6 GeV embedding 
  // -(-dZE+dzW)/2/(DV[cm/sec]/frequancy[Hz]) : DV = 5533042; f = 9.386470*1e 6
  // row.T0offset   = 0.50-6.83675e-01; // 01/18/12 Xianglei Zhu from Run 11 AuAu 27 & 19.6 GeV embedding
  row.T0offset   = 0.50-6.83675e-01-5.74e-02; // 07/26/18 2005 CuCu200, run 6059070
  tableSet->AddAt(&row);
  // ----------------- end of code ---------------
  return (TDataSet *)tableSet;
}
