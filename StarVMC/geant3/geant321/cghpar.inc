*
* $Id: cghpar.inc,v 1.1.1.2 2009/02/01 17:10:19 fisyak Exp $
*
* $Log: cghpar.inc,v $
* Revision 1.1.1.2  2009/02/01 17:10:19  fisyak
* Merge with .DEV2
*
* Revision 1.1.1.1  2008/12/10 20:47:07  fisyak
* Merge with macos version
*
* Revision 1.1.1.1  2005/05/25 22:37:28  fisyak
* Alice version of geant3 (-minicern)
*
* Revision 1.1.1.1  2002/07/24 15:56:26  rdm
* initial import into CVS
*
* Revision 1.1.1.1  2002/06/16 15:18:38  hristov
* Separate distribution  of Geant3
*
* Revision 1.1.1.1  1999/05/18 15:55:16  fca
* AliRoot sources
*
* Revision 1.1.1.1  1995/10/24 10:20:42  cernlib
* Geant
*
*
#ifndef CERNLIB_GEANT321_CGHPAR_INC
#define CERNLIB_GEANT321_CGHPAR_INC
*
*
* cghpar.inc
*
#if !defined(CERNLIB_INCLUDE)
      PARAMETER (I4SIZE = 1)
      PARAMETER (LHHEAD=18,KHSIZE=1)
      PARAMETER (          KHNT  =2)
      PARAMETER (          KHIFWI=3)
      PARAMETER (          KHNXYZ=8)
      PARAMETER (          KHNFAC=9)
      PARAMETER (          KHNEDG=10)
      PARAMETER (          KHJXYZ=11)
      PARAMETER (          KHJFA =12)
      PARAMETER (          KHJPFA=13)
      PARAMETER (          KHJDFA=14)
      PARAMETER (          KHJTRE=15)
      PARAMETER (          KHJSTA=16)
      PARAMETER (          KHJALE=17)
      PARAMETER (          KHJARI=18)
#endif
*
* cghpar.inc
*
#if defined(CERNLIB_INCLUDE)
#include "geant321/incbeg.inc"
       +   CGHPAR.
#include "geant321/incend.inc"
*
#endif

#endif
