#include "StAzimuthalAngle.h"
#include <TH1.h>


StAzimuthalAngle::~StAzimuthalAngle() {}

void 
StAzimuthalAngle::Fill(StTrackForPool* tp1, StTrackForPool* tp2, TH1D* hist) 
{
  // calculates  angle between the momenta of two tracks
  // 0 < alphadiff < pi
  weight = 1.0;
  tp1->GetMomentum(px1,py1,pz1);
  tp2->GetMomentum(px2,py2,pz2);
  Double_t rap1,rap2;
  tp1->GetPseudoRapidity(rap1);
  tp2->GetPseudoRapidity(rap2);

  Double_t phi1 = atan2(py1,px1);
  Double_t phi2 = atan2(py2,px2);
  Double_t pi=3.14159265;
  
  if (phi1 < 0.0) {phi1 = phi1 + 2.*pi;}
  if (phi2 < 0.0) {phi2 = phi2 + 2.*pi;}
  
  Double_t phidiff = fabs(phi1-phi2);
  
  if (phidiff > pi) 
    {
      phidiff = 2.*pi - phidiff ;
    }
  correlation = (180./pi)*phidiff;
  hist->Fill(correlation,weight);
}


TString
StAzimuthalAngle::GetName() 
{
  TString name = "azimuthalAngle";
  return name;
}
