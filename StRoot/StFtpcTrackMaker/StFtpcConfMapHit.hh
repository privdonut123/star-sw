// $Id: StFtpcConfMapHit.hh,v 1.1 2000/05/10 13:39:08 oldi Exp $
// $Log: StFtpcConfMapHit.hh,v $
// Revision 1.1  2000/05/10 13:39:08  oldi
// Initial version of StFtpcTrackMaker
//

/////////////////////////////////////////////////////////////////////////////////////
//                                                                                 //
// StFtpcConfMapHit class - derived FTPC Hit class to represent additional data    //
//                          needed by the conformel mapping track algorithm.       //
//                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////

#ifndef STAR_StFtpcConfMapHit
#define STAR_StFtpcConfMapHit

#include "StFtpcHit.hh"
#include "StFtpcVertex.hh"

class StFtpcConfMapHit : public StFtpcHit {
  
private:
  
  // Interaction point
  Double_t   mXt;          // x-value of the interaction point
  Double_t   mYt;          // y-value of the interaction point
  Double_t   mZt;          // z-value of the interaction point
  
  Double_t   mXterr;       // error of mXt
  Double_t   mYterr;       // error of mYt
  Double_t   mZterr;       // error of mZt
  
  // conformal mapping coordinates
  Double_t   mXprime;      // transformed x
  Double_t   mYprime;      // transformed y  
  
  Double_t   mXprimeerr;   // error of mXprime
  Double_t   mYprimeerr;   // error of mYprime
  
  // coordinates with respect to the vertex
  
  // cartesian coordinates
  Double_t   mXv;          // x with respect to vertex
  Double_t   mYv;          // y with respect to vertex
  Double_t   mZv;          // z with respect to vertex
  
  Double_t   mXverr;       // error of mXv
  Double_t   mYverr;       // error of mYv
  Double_t   mZverr;       // error of mZv
  
  // spherical coordinates
  Double_t   mPhi;         // angle phi
  Double_t   mEta;         // pseudorapidity
  
  // distances to the conformal mapping fits
  Double_t   mCircleDist;  // distance from the fitted circle
  Double_t   mLengthDist;  // distance from the length fit
  
  
public:
  
            StFtpcConfMapHit();                                                 // default constructor
            StFtpcConfMapHit(fcl_fppoint_st *point_st, StFtpcVertex *vertex);   // constructor
  virtual  ~StFtpcConfMapHit();                                                 // destructor
  
  // getter
  Double_t   GetCircleDist() const   { return mCircleDist; }
  Double_t   GetLengthDist() const   { return mLengthDist; }
  
  Double_t   GetPhi() const          { return mPhi;        }
  Double_t   GetEta() const          { return mEta;        }
  
  Double_t   GetXprime() const       { return mXprime;     }
  Double_t   GetYprime() const       { return mYprime;     }
  Double_t   GetXprimeerr() const    { return mXprimeerr;  }
  Double_t   GetYprimeerr() const    { return mYprimeerr;  }
  
  Double_t   GetXt() const           { return mXt;         }
  Double_t   GetYt() const           { return mYt;         }
  Double_t   GetZt() const           { return mZt;         }
  Double_t   GetXterr() const        { return mXterr;      }
  Double_t   GetYterr() const        { return mYterr;      }
  Double_t   GetZterr() const        { return mZterr;      }
  
  Double_t   GetXv() const           { return mXv;         }
  Double_t   GetYv() const           { return mYv;         }
  Double_t   GetZv() const           { return mZv;         }
  Double_t   GetXverr() const        { return mXverr;      }
  Double_t   GetYverr() const        { return mYverr;      }
  Double_t   GetZverr() const        { return mZverr;      }
  
  // setter
  void    SetDist(Double_t c, Double_t l)  { mCircleDist = c; mLengthDist = l; }
  void    SetCircleDist(Double_t f)        { mCircleDist = f;                  }
  void    SetLengthDist(Double_t f)        { mLengthDist = f;                  }  
  
  void    SetPhi(Double_t f)         {           mPhi = f; }
  void    SetEta(Double_t f)         {           mEta = f; }
  
  void    SetXprime(Double_t f)      {        mXprime = f; }
  void    SetYprime(Double_t f)      {        mYprime = f; }
  void    SetXprimeerr(Double_t f)   {     mXprimeerr = f; }
  void    SetYprimeerr(Double_t f)   {     mYprimeerr = f; }
  
  void    SetXt(Double_t f)          {            mXt = f; }
  void    SetYt(Double_t f)          {            mYt = f; }
  void    SetZt(Double_t f)          {            mZt = f; }
  void    SetXterr(Double_t f)       {         mXterr = f; }
  void    SetYterr(Double_t f)       {         mYterr = f; }
  void    SetZterr(Double_t f)       {         mZterr = f; }
  
  void    SetXv(Double_t f)          {            mXv = f; }
  void    SetYv(Double_t f)          {            mYv = f; }
  void    SetZv(Double_t f)          {            mZv = f; }
  void    SetXverr(Double_t f)       {         mXverr = f; }
  void    SetYverr(Double_t f)       {         mYverr = f; }
  void    SetZverr(Double_t f)       {         mZverr = f; }
  
  void    Setup(StFtpcVertex *vertex);                                                 // does the usual setup in the right order
  void    SetAngles();                                                                 // calculate spherical angles and set values
  void    SetIntPoint(const Double_t in_x = 0.,     const Double_t in_y = 0.,     const Double_t in_z = 0.,
		      const Double_t in_x_err = 0., const Double_t in_y_err = 0., const Double_t in_z_err = 0.);  // set interaction point
  void    SetShiftedCoord();                                                           // set shifted coordinates  
  void    SetAllCoord(const StFtpcConfMapHit *hit);                                    // set conformal mapping coordinates in respect to given hit
  void    SetConfCoord();                                                              // conformal mapping
  
  ClassDef(StFtpcConfMapHit, 1)   //Ftpc conformal mapping hit class
};

#endif
