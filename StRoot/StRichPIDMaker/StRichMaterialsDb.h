/**********************************************************
 * $Id: StRichMaterialsDb.h,v 2.0 2000/08/09 16:26:18 gans Exp $
 *
 * Description:
 *  
 *
 *  $Log: StRichMaterialsDb.h,v $
 *  Revision 2.0  2000/08/09 16:26:18  gans
 *  Naming Convention for TDrawable Ojects. All drawable objects now in StRichDisplayMaker
 *
 *  Revision 1.2  2000/05/19 19:06:10  horsley
 *  many revisions here, updated area calculation ring calc, ring, tracks , etc...
 *
 *  Revision 1.1  2000/04/03 19:36:07  horsley
 *  initial revision
 **********************************************************/

#ifndef ST_RICH_MATERIALS_H
#define ST_RICH_MATERIALS_H

#include "StRichMaterialsDbInterface.h"

class StRichMaterialsDb : public StRichMaterialsDbInterface {
public:

  static StRichMaterialsDb* getDb();
  
  // Interface
  // common to all materials
  double meanWaveLength();
  double shortestWaveLength();
  double longestWaveLength();
  double meanRadiatorDepth();  

  // C6F14    
  double indexOfRefractionOfC6F14At(double wavelength);
  double absorptionCoefficientOfC6F14At(double wavelength);
  
  // quartz 
  double indexOfRefractionOfQuartzAt(double wavelength);
  double absorptionCoefficientOfQuartzAt(double wavelength);
  
  // methane
  double indexOfRefractionOfMethaneAt(double wavelength);
  double absorptionCoefficientOfMethaneAt(double wavelength);
  
  double quantumEfficiencyOfCsIAt(double wavelength);

  double version() const;
  void   print(ostream& os = cout) const;
    
protected:
    StRichMaterialsDb();
    
private:
    void my_fill();             // fill with my own stuff
    
    static StRichMaterialsDb* p2Db;   // handle to only instance

    bool boundsCheck(double index);
   
  double mVersion;
  double mLongestWaveLength;
  double mShortestWaveLength;
  double mMeanWaveLength;  
  double mConversion;

  double mMeanRadiatorDepth;
  

    ///////////    measured CERN data    /////////////
    /* index of refraction measured at 11 different wavelengths  169 -- 220 */
  //    static const int arraySize = 11;
    double mC6F14IndexOfRefraction[11]; 
    double mQuartzIndexOfRefraction[11];
    double mMethaneIndexOfRefraction; 
    
    /* photon absorption coefficient measured at 11 different wavelengths  169 -- 220 */
    double mC6F14AbsCoeff[11]; 
    double mQuartzAbsCoeff[11];
    double mMethaneAbsCoeff;

    /* CsI QE measured at 11 different wavelengths  169 -- 220 */
    double mCsIQE[11];
      
};

#endif


