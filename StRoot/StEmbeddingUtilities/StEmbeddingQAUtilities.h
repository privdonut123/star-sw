//----------------------------------------------------------------------------------------------------
//  Class StEmbeddingQAUtilities
//    - Provide category id, such as 'MC' track in the minimc tree
//----------------------------------------------------------------------------------------------------
/****************************************************************************************************
 * $Id: StEmbeddingQAUtilities.h,v 1.7 2010/07/12 21:27:29 hmasui Exp $
 * $Log: StEmbeddingQAUtilities.h,v $
 * Revision 1.7  2010/07/12 21:27:29  hmasui
 * Added StParticleTable & StParticleDefinition utilities
 *
 * Revision 1.6  2010/01/26 17:45:06  hmasui
 * Add runid functions
 *
 * Revision 1.5  2009/12/22 21:37:55  hmasui
 * Add comments for functions and members
 *
 ****************************************************************************************************/

#ifndef __StEmbeddingQAUtilities_h__
#define __StEmbeddingQAUtilities_h__

class StParticleDefinition ;
class TH1 ;
#include <map>
#include "TString.h"
#include "StMiniMcEvent/StMiniMcEvent.h"

//____________________________________________________________________________________________________
namespace StEmbeddingQAConst 
{
  //----------------------------------------------------------------------------------------------------
  //  id       node           description
  //----------------------------------------------------------------------------------------------------
  //  0         MC             MC tracks (embedding)
  //  1         MATCHED        Matched pairs (embedding)
  //  2         GHOST          Ghost pairs (embedding)
  //  3         CONTAM         Contaminated pairs (embedding)
  //  4         MATGLOB        Matched global pairs (embedding)
  //----------------------------------------------------------------------------------------------------
  //  5         PRIMARY        Primary tracks (real)
  //  6         GLOBAL         Global tracks (real)
  //----------------------------------------------------------------------------------------------------
  enum {
    mNEmbedding = 5,
    mNReal      = 2,
    mNCategory  = mNEmbedding + mNReal
  };
}

//____________________________________________________________________________________________________
class StEmbeddingQAUtilities {
  public:
    /// Get instance
    static StEmbeddingQAUtilities* instance();

    /// Destructor
    virtual ~StEmbeddingQAUtilities();

    // Track category for minimc nodes
    Category getCategory(const UInt_t id) const ;      /// Category from category id
    TString getCategoryName(const UInt_t id) const ;   /// Category name from category id
    TString getCategoryTitle(const UInt_t id) const ;  /// Category title from category id
    Int_t getCategoryId(const TString name) const ;    /// Category id from category name

    // Input string is case insensitive
    //  - For example, MC, mc, mC and Mc are ok for isMc()
    Bool_t isMc(const TString name) const ;            /// Check whether the track is MC track or not   
    Bool_t isMatched(const TString name) const ;       /// Check whether the track is Matched pair or not   
    Bool_t isGhost(const TString name) const ;         /// Check whether the track is Ghost pair or not   
    Bool_t isContaminated(const TString name) const ;  /// Check whether the track is Contaminated pair or not   
    Bool_t isMatchedGlobal(const TString name) const ; /// Check whether the track is Contaminated pair or not   
    Bool_t isPrimary(const TString name) const ;       /// Check whether the track is primary track or not
    Bool_t isGlobal(const TString name) const ;        /// Check whether the track is global track or not
    Bool_t isEmbedding(const TString name) const ;     /// Check whether the track is embedding pair or not
    Bool_t isReal(const TString name) const ;          /// Check whether the track is real track or not

    // Check geantid
    Bool_t isElectrons(const Int_t geantid) const ;    /// Check the input geantid is electrons
    Bool_t isPions(const Int_t geantid) const ;        /// Check the input geantid is pions
    Bool_t isKaons(const Int_t geantid) const ;        /// Check the input geantid is kaons
    Bool_t isProtons(const Int_t geantid) const ;      /// Check the input geantid is protons
    Bool_t isEPiKP(const Int_t geantid) const ;        /// Check the input geantid is e/pi/K/p

    // Histogram style
    void setStyle() const ;       /// Set overall styles
    void setStyle(TH1* h) const ; /// Set font, title and label styles

    // Run id
    Int_t getRunId(const Int_t runnumber, const Int_t year) const ; /// get runid from runnumber
    Int_t getRunNumber(const Int_t runid, const Int_t year) const ; /// runnumber = runid - (year - 2000 + 1) * 10^6

    /// Get StParticleDefinition from geantid
    StParticleDefinition* getParticleDefinition(const UInt_t geantid) const ;

    /// Check geant id is defined in StParticleTable or not
    Bool_t isGeantIdOk(const UInt_t geantid) const ;

  private:
    /// Default constructor
    StEmbeddingQAUtilities();

    /// Single StEmbeddingQAUtilities object
    static StEmbeddingQAUtilities* mInstance ;

    /// Utility function to compare two TString
    Bool_t CompareString(const TString s0, const TString s1, const Bool_t isExact=kFALSE) const ;

    // Data members
    Category mCategory[StEmbeddingQAConst::mNEmbedding] ;    /// Category of minimc nodes
    TString mCategoryName[StEmbeddingQAConst::mNCategory] ;  /// Category name of minimc nodes
    TString mCategoryTitle[StEmbeddingQAConst::mNCategory] ; /// Category title of minimc nodes
    std::map<const TString, const UInt_t> mCategoryId ;      /// Pair of category name and category id

    // Run id
    Int_t getYearNumber(const Int_t year) const ; // (year - 2000 + 1) * 10^6

    ClassDef(StEmbeddingQAUtilities, 1)
};

//____________________________________________________________________________________________________
inline Int_t StEmbeddingQAUtilities::getYearNumber(const Int_t year) const { return (year - 1999) * 1000000 ; }

//____________________________________________________________________________________________________
inline Int_t StEmbeddingQAUtilities::getRunId(const Int_t runnumber, const Int_t year) const
{
  return runnumber + getYearNumber(year) ;
}

//____________________________________________________________________________________________________
inline Int_t StEmbeddingQAUtilities::getRunNumber(const Int_t runid, const Int_t year) const
{
  return runid - getYearNumber(year) ;
}

#endif


