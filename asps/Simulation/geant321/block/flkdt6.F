*
* $Id: flkdt6.F,v 1.1.1.1 2004/01/15 00:11:55 potekhin Exp $
*
* $Log: flkdt6.F,v $
* Revision 1.1.1.1  2004/01/15 00:11:55  potekhin
*
* Revision 1.1.1.1  1997/11/03 15:24:12  atlascvs
* Importing CERNLIB version 08.21.
*
* Revision 1.1.1.1  1995/10/24 10:19:36  cernlib
* Geant
*
*
#include "geant321/pilot.h"
*CMZ :  3.21/02 29/03/94  15.41.45  by  S.Giani
*-- Author :
*$ CREATE BLKDT6.FOR
*COPY BLKDT6
*
*=== blkdt6 ===========================================================*
*==                                                                    *
      SUBROUTINE FLKDT6
 
#include "geant321/dblprc.inc"
#include "geant321/dimpar.inc"
#include "geant321/iounit.inc"
*---Block Data 6 (ex 1)                                                *
#include "geant321/part.inc"
#include "geant321/qquark.inc"
      CHARACTER*8 ANAME1(IDMAX8)
      DIMENSION AM1(IDMAX8),GA1(IDMAX8),TAU1(IDMAX8),
     & ICH1(IDMAX8),IBAR1(IDMAX8),K11(IDMAX8),K21(IDMAX8),
     & KPTIP1(IDMAX8),IPTKP1(39),
     & IQECH1(-6:6),IQBCH1(-6:6),IQICH1(-6:6),IQSCH1(-6:6),
     & IQCCH1(-6:6),IQUCH1(-6:6),IQTCH1(-6:6),MQUAR1(3,39)
*
* / Part /
*     datas     datas    datas      datas     datas                    *
*     ---------------------------------------------                    *
*                                                                      *
*     Particle  masses                                                 *
*                                                                      *
      DATA ( AM1 ( I ), I =   1, 54 ) /
     & 9.38272310000000D-01, 9.38272310000000D-01,       AMELCT        ,
     &       AMELCT        , 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 9.39565630000000D-01, 9.39565630000000D-01,
     &       AMMUON        ,       AMMUON        , 4.97671000000000D-01,
     & 1.39567500000000D-01, 1.39567500000000D-01, 4.93646000000000D-01,
     & 4.93646000000000D-01, 1.11563000000000D+00, 1.11563000000000D+00,
     & 4.97671000000000D-01, 1.19743000000000D+00, 1.18937000000000D+00,
     & 1.19255000000000D+00, 1.34973900000000D-01, 4.97671000000000D-01,
     & 4.97671000000000D-01, 1.34973900000000D-01, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 5.48800000000000D-01, 7.68300000000000D-01, 7.68300000000000D-01,
     & 7.68300000000000D-01, 7.81950000000000D-01, 8.91830000000000D-01,
     & 8.96100000000000D-01, 8.91830000000000D-01, 8.96100000000000D-01,
     & 1.25000000000000D+00, 1.25000000000000D+00, 1.25000000000000D+00,
     & 1.25000000000000D+00, 1.42100000000000D+00, 1.42100000000000D+00,
     & 1.42100000000000D+00, 1.42100000000000D+00, 1.38280000000000D+00,
     & 1.38370000000000D+00, 1.38720000000000D+00, 1.82000000000000D+00,
     & 2.03000000000000D+00, 1.23200000000000D+00, 1.23200000000000D+00/
      DATA ( AM1 ( I ), I =  55,108 ) /
     & 1.23200000000000D+00, 1.23200000000000D+00, 1.67500000000000D+00,
     & 1.67500000000000D+00, 1.67500000000000D+00, 1.67500000000000D+00,
     & 1.44000000000000D+00, 1.44000000000000D+00, 1.52000000000000D+00,
     & 1.52000000000000D+00, 1.77500000000000D+00, 1.77500000000000D+00,
     & 1.23200000000000D+00, 1.23200000000000D+00, 1.23200000000000D+00,
     & 1.23200000000000D+00, 1.67500000000000D+00, 1.67500000000000D+00,
     & 1.67500000000000D+00, 1.67500000000000D+00, 1.52000000000000D+00,
     & 1.52000000000000D+00, 2.40000000000000D+00, 4.89000000000000D-01,
     & 4.89000000000000D-01, 4.89000000000000D-01, 1.30000000000000D+00,
     & 1.30000000000000D+00, 1.30000000000000D+00, 1.30000000000000D+00,
     & 2.20000000000000D+00, 2.20000000000000D+00, 2.20000000000000D+00,
     & 2.20000000000000D+00, 1.70000000000000D+00, 1.70000000000000D+00,
     & 1.70000000000000D+00, 1.70000000000000D+00, 1.82000000000000D+00,
     & 2.03000000000000D+00, 9.57500000000000D-01, 1.01941200000000D+00,
     & 1.31490000000000D+00, 1.32132000000000D+00, 1.18937000000000D+00,
     & 1.19255000000000D+00, 1.19743000000000D+00, 1.31490000000000D+00,
     & 1.32132000000000D+00, 1.38280000000000D+00, 1.38370000000000D+00,
     & 1.38720000000000D+00, 1.53180000000000D+00, 1.53500000000000D+00/
      DATA ( AM1 ( I ), I = 109,162 ) /
     & 1.67243000000000D+00, 1.38280000000000D+00, 1.38370000000000D+00,
     & 1.38720000000000D+00, 1.53180000000000D+00, 1.53500000000000D+00,
     & 1.67243000000000D+00, 1.86450000000000D+00, 1.86930000000000D+00,
     & 1.86930000000000D+00, 1.86450000000000D+00, 1.96880000000000D+00,
     & 1.96880000000000D+00, 2.03000000000000D+00, 2.00710000000000D+00,
     & 2.01010000000000D+00, 2.01010000000000D+00, 2.00710000000000D+00,
     & 2.11030000000000D+00, 2.11030000000000D+00, 3.68600000000000D+00,
     & 3.09693000000000D+00, 1.78410000000000D+00, 1.78410000000000D+00,
     & 3.50000000000000D-02, 3.50000000000000D-02, 2.70000000000000D-04,
     & 2.70000000000000D-04, 2.26000000000000D+00, 2.47000000000000D+00,
     & 2.47000000000000D+00, 2.41000000000000D+00, 2.42000000000000D+00,
     & 2.41000000000000D+00, 2.56000000000000D+00, 2.56000000000000D+00,
     & 2.73000000000000D+00, 3.61000000000000D+00, 3.61000000000000D+00,
     & 3.79000000000000D+00, 2.26000000000000D+00, 2.47000000000000D+00,
     & 2.47000000000000D+00, 2.41000000000000D+00, 2.42000000000000D+00,
     & 2.41000000000000D+00, 2.56000000000000D+00, 2.56000000000000D+00,
     & 2.73000000000000D+00, 3.61000000000000D+00, 3.61000000000000D+00,
     & 3.79000000000000D+00, 2.49000000000000D+00, 2.49000000000000D+00/
      DATA ( AM1 ( I ), I = 163,183 ) /
     & 2.49000000000000D+00, 2.61000000000000D+00, 2.61000000000000D+00,
     & 2.77000000000000D+00, 3.67000000000000D+00, 3.67000000000000D+00,
     & 3.85000000000000D+00, 4.89000000000000D+00, 2.49000000000000D+00,
     & 2.49000000000000D+00, 2.49000000000000D+00, 2.61000000000000D+00,
     & 2.61000000000000D+00, 2.77000000000000D+00, 3.67000000000000D+00,
     & 3.67000000000000D+00, 3.85000000000000D+00, 4.89000000000000D+00,
     & 1.25000000000000D+00, 1.25000000000000D+00, 1.25000000000000D+00/
*                                                                      *
*     Particle  mean lives                                             *
*                                                                      *
      DATA ( TAU1 ( I ), I =   1, 54 ) /
     & 1.00000000000000D+18, 1.00000000000000D+18, 1.00000000000000D+18,
     & 1.00000000000000D+18, 1.00000000000000D+18, 1.00000000000000D+18,
     & 1.00000000000000D+18, 8.88600000000000D+02, 8.88600000000000D+02,
     & 2.19703000000000D-06, 2.19703000000000D-06, 5.17000000000000D-08,
     & 2.60300000000000D-08, 2.60300000000000D-08, 1.23710000000000D-08,
     & 1.23710000000000D-08, 2.63200000000000D-10, 2.63200000000000D-10,
     & 8.92200010000000D-11, 1.47900000000000D-10, 7.99000000000000D-11,
     & 7.40000000000000D-20, 8.40000000000000D-17, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00/
      DATA ( TAU1 ( I ), I =  55,108 ) /
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 2.90000000000000D-10, 1.63900000000000D-10, 7.99000000000000D-11,
     & 7.40000000000000D-20, 1.47900000000000D-10, 2.90000000000000D-10,
     & 1.63900000000000D-10, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00/
      DATA ( TAU1 ( I ), I = 109,162 ) /
     & 8.22000000000000D-11, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 8.22000000000000D-11, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 3.03000000000000D-13, 3.03000000000000D-13,
     & 1.00000000000000D+18, 1.00000000000000D+18, 1.00000000000000D+18,
     & 1.00000000000000D+18, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00/
      DATA ( TAU1 ( I ), I = 163,183 ) /
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00/
*                                                                      *
*     Resonance width Gamma in GeV                                     *
*                                                                      *
      DATA ( GA1 ( I ), I =   1, 54 ) /
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 1.19000000000000D-06, 1.49100000000000D-01, 1.49100000000000D-01,
     & 1.49100000000000D-01, 8.43000000000000D-03, 4.98000000000000D-02,
     & 4.98000000000000D-02, 4.98000000000000D-02, 4.98000000000000D-02,
     & 4.50000000000000D-01, 4.50000000000000D-01, 4.50000000000000D-01,
     & 4.50000000000000D-01, 1.08000000000000D-01, 1.08000000000000D-01,
     & 1.08000000000000D-01, 1.08000000000000D-01, 3.58000000000000D-02,
     & 3.65000000000000D-02, 3.94000000000000D-02, 8.50000000000000D-02,
     & 1.80000000000000D-01, 1.15000000000000D-01, 1.15000000000000D-01/
      DATA ( GA1 ( I ), I =  55,108 ) /
     & 1.15000000000000D-01, 1.15000000000000D-01, 2.00000000000000D-01,
     & 2.00000000000000D-01, 2.00000000000000D-01, 2.00000000000000D-01,
     & 2.00000000000000D-01, 2.00000000000000D-01, 1.00000000000000D-01,
     & 1.00000000000000D-01, 2.00000000000000D-01, 2.00000000000000D-01,
     & 1.15000000000000D-01, 1.15000000000000D-01, 1.15000000000000D-01,
     & 1.15000000000000D-01, 2.00000000000000D-01, 2.00000000000000D-01,
     & 2.00000000000000D-01, 2.00000000000000D-01, 1.00000000000000D-01,
     & 1.00000000000000D-01, 2.00000000000000D-01, 1.00000000000000D-01,
     & 1.00000000000000D-01, 1.00000000000000D-01, 1.00000000000000D-01,
     & 1.00000000000000D-01, 1.00000000000000D-01, 1.00000000000000D-01,
     & 2.00000000000000D-01, 2.00000000000000D-01, 2.00000000000000D-01,
     & 2.00000000000000D-01, 1.50000000000000D-01, 1.50000000000000D-01,
     & 1.50000000000000D-01, 1.50000000000000D-01, 8.50000000000000D-02,
     & 1.80000000000000D-01, 2.08000000000000D-04, 4.41000000000000D-03,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 3.58000000000000D-02, 3.65000000000000D-02,
     & 3.94000000000000D-02, 9.10000000000000D-03, 9.90000000000000D-03/
      DATA ( GA1 ( I ), I = 109,162 ) /
     & 0.00000000000000D+00, 3.40000000000000D-02, 3.40000000000000D-02,
     & 3.60000000000000D-02, 9.10000000000000D-03, 9.90000000000000D-03,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 2.10000000000000D-03,
     & 1.10000000000000D-03, 1.10000000000000D-03, 5.00000000000000D-03,
     & 2.00000000000000D-03, 2.00000000000000D-03, 2.43000000000000D-04,
     & 6.80000000000000D-05, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00/
      DATA ( GA1 ( I ), I = 163,183 ) /
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 0.00000000000000D+00, 0.00000000000000D+00, 0.00000000000000D+00,
     & 3.00000000000000D-01, 3.00000000000000D-01, 3.00000000000000D-01/
*                                                                      *
*     Particle  names                                                  *
*                                                                      *
*     S+1385+Sigma+(1385)    L02030+Lambda0(2030)                      *
*     Rho77=Rho(770) Om783=Omega(783) K*14=K*(1420) and so on          *
*     designation N*@@ means N*@1(@2)                                  *
*                                                                      *
*                                                                      *
      DATA (    ANAME1 ( I ), I =   1,108 ) /
     &'P       ','AP      ','E-      ','E+      ','NUE     ','ANUE    ',
     &'GAM     ','NEU     ','ANEU    ','MUE+    ','MUE-    ','K0L     ',
     &'PI+     ','PI-     ','K+      ','K-      ','LAM     ','ALAM    ',
     &'K0S     ','SIGM-   ','SIGM+   ','SIGM0   ','PI0     ','K0      ',
     &'AK0     ','BLANK   ','BLANK   ','BLANK   ','BLANK   ','BLANK   ',
     &'ETA550  ','RHO+77  ','RHO077  ','RHO-77  ','OM0783  ','K*+892  ',
     &'K*0892  ','K*-892  ','AK*089  ','KA+125  ','KA0125  ','KA-125  ',
     &'AKA012  ','K*+142  ','K*0142  ','K*-142  ','AK*014  ','S+1385  ',
     &'S01385  ','S-1385  ','L01820  ','L02030  ','DE++12  ','DEL+12  ',
     &'DEL012  ','DEL-12  ','N*++16  ','N*+16   ','N*016   ','N*-16   ',
     &'N*+14   ','N*014   ','N*+15   ','N*015   ','N*+18   ','N*018   ',
     &'AD--12  ','ADE-12  ','ADE012  ','ADE+12  ','AN--16  ','AN*-16  ',
     &'AN*016  ','AN*+16  ','AN*-15  ','AN*015  ','DE*=24  ','RPI+49  ',
     &'RPI049  ','RPI-49  ','PIN++   ','PIN+0   ','PIN+-   ','PIN-0   ',
     &'PPPI    ','PNPI    ','APPPI   ','APNPI   ','K+PPI   ','K-PPI   ',
     &'K+NPI   ','K-NPI   ','S+1820  ','S-2030  ','ETA*    ','PHI     ',
     &'XSI0    ','XSI-    ','ASIG-   ','ASIG0   ','ASIG+   ','AXSI0   ',
     &'AXSI+   ','SIG*+   ','SIG*0   ','SIG*-   ','XSI*0   ','XSI*-   '/
      DATA (    ANAME1 ( I ), I = 109,183 ) /
     &'OMEGA-  ','ASIG*-  ','ASIG*0  ','ASIG*+  ','AXSI*0  ','AXSI*+  ',
     &'OMEGA+  ','D0      ','D+      ','D-      ','AD0     ','DS+     ',
     &'DS-     ','ETAC    ','D*0     ','D*+     ','D*-     ','AD*0    ',
     &'DS*+    ','DS*-    ','PSI     ','JPSI    ','TAU+    ','TAU-    ',
     &'NUET    ','ANUET   ','NUEM    ','ANUEM   ','C0+     ','A+      ',
     &'A0      ','C1++    ','C1+     ','C10     ','S+      ','S0      ',
     &'T0      ','XU++    ','XD+     ','XS+     ','AC0-    ','AA-     ',
     &'AA0     ','AC1--   ','AC1-    ','AC10    ','AS-     ','AS0     ',
     &'AT0     ','AXU--   ','AXD-    ','AXS     ','C1*++   ','C1*+    ',
     &'C1*0    ','S*+     ','S*0     ','T*0     ','XU*++   ','XD*+    ',
     &'XS*+    ','TETA++  ','AC1*--  ','AC1*-   ','AC1*0   ','AS*-    ',
     &'AS*0    ','AT*0    ','AXU*--  ','AXD*-   ','AXS*-   ','ATET--  ',
     &'RO      ','R+      ','R-      '/
*                                                                      *
*     Charge of particles and resonances                               *
*                                                                      *
      DATA ( ICH1 ( I ), I =   1,183 ) /
     &  1, -1, -1,  1,  0,  0,  0,  0,  0,  1, -1,  0,  1, -1,  1,
     & -1,  0,  0,  0, -1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     &  0,  1,  0, -1,  0,  1,  0, -1,  0,  1,  0, -1,  0,  1,  0,
     & -1,  0,  1,  0, -1,  0,  0,  2,  1,  0, -1,  2,  1,  0, -1,
     &  1,  0,  1,  0,  1,  0, -2, -1,  0,  1, -2, -1,  0,  1, -1,
     &  0,  1,  1,  0, -1,  2,  1,  0, -1,  2,  1,  0, -1,  2,  0,
     &  1, -1,  1, -1,  0,  0,  0, -1, -1,  0,  1,  0,  1,  1,  0,
     & -1,  0, -1, -1, -1,  0,  1,  0,  1,  1,  0,  1, -1,  0,  1,
     & -1,  0,  0,  1, -1,  0,  1, -1,  0,  0,  1, -1,  0,  0,  0,
     &  0,  1,  1,  0,  2,  1,  0,  1,  0,  0,  2,  1,  1, -1, -1,
     &  0, -2, -1,  0, -1,  0,  0, -2, -1, -1,  2,  1,  0,  1,  0,
     &  0,  2,  1,  1,  2, -2, -1,  0, -1,  0,  0, -2, -1, -1, -2,
     &  0,  1, -1/
*                                                                      *
*     Particle  baryonic charges                                       *
*                                                                      *
      DATA ( IBAR1 ( I ), I =   1,183 ) /
     &  1, -1,  0,  0,  0,  0,  0,  1, -1,  0,  0,  0,  0,  0,  0,
     &  0,  1, -1,  0,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,
     &  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     &  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
     &  1,  1,  1,  1,  1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
     & -1,  2,  0,  0,  0,  1,  1,  1,  1,  2,  2,  0,  0,  1,  1,
     &  1,  1,  1,  1,  0,  0,  1,  1, -1, -1, -1, -1, -1,  1,  1,
     &  1,  1,  1,  1, -1, -1, -1, -1, -1, -1,  0,  0,  0,  0,  0,
     &  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     &  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, -1, -1,
     & -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1,  1,  1,  1,  1,
     &  1,  1,  1,  1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
     &  0,  0,  0/
*                                                                      *
*     First number of decay channels used for resonances               *
*     and decaying particles                                           *
*                                                                      *
      DATA K11/1,2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 16, 17, 18, 24, 30,
     & 34, 38, 40, 41, 43, 44, 136, 138, 5*330, 46, 51, 52, 54, 55, 58,
     &  60, 62, 64, 66, 68, 70, 72, 74, 82, 90, 98, 106, 109, 112, 114,
     & 123, 140, 141, 143, 145, 146, 150, 157, 164, 168, 174, 180, 187,
     & 194, 202, 210, 211, 213, 215, 216, 220, 227, 234, 238, 245, 252,
     & 254, 255, 256, 257, 259, 262, 265, 267, 269, 272, 276, 279, 282,
     & 286, 290, 293, 299, 331, 335, 339, 340, 341, 343, 344, 345, 346,
     & 347, 350, 353, 356, 358, 360, 363, 366, 369, 372, 374, 376, 379,
     & 383, 385, 387, 391, 394, 397, 400, 402, 405, 408, 410, 412, 414,
     & 417, 420, 425, 430, 431, 432, 433, 434, 448, 452, 457, 458, 459,
     & 460, 461, 462, 466, 468, 470, 472, 486, 490, 495, 496, 497, 498,
     & 499, 500, 504, 506, 508, 510, 511, 512, 513, 514, 515, 516, 517,
     & 518, 519, 522, 523, 524, 525, 526, 527, 528, 529, 530, 531, 534,
     & 537, 539 /
*                                                                      *
*     Last number of decay channels used for resonances                *
*     and decaying particles                                           *
*                                                                      *
      DATA K21/ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 15, 16, 17, 23, 29,
     & 31, 35, 39, 40, 42, 43, 45, 137, 139, 5* 330, 50, 51, 53, 54, 57,
     & 59, 61, 63, 65, 67, 69, 71, 73, 81, 89, 97, 105, 108, 111, 113,
     & 122, 135, 140, 142, 144, 145, 149, 156, 163, 167, 173, 179, 186,
     & 193, 201, 209, 210, 212, 214, 215, 219, 226, 233, 237, 244, 251,
     & 253, 254, 255, 256, 258, 261, 264, 266, 268, 271, 275, 278, 281,
     & 285, 289, 292, 298, 307, 334, 338, 339, 340, 342, 343, 344, 345,
     & 346, 349, 352, 355, 357, 359, 362, 365, 368, 371, 373, 375, 378,
     & 382, 384, 386, 390, 393, 396, 399, 401, 404, 407, 409, 411, 413,
     & 416, 419, 424, 429, 430, 431, 432, 433, 447, 451, 456, 457, 458,
     & 459, 460, 461, 465, 467, 469, 471, 485, 489, 494, 495, 496, 497,
     & 498, 499, 503, 505, 507, 509, 510, 511, 512, 513, 514, 515, 516,
     & 517, 518, 521, 522, 523, 524, 525, 526, 527, 528, 529, 530, 533,
     & 536, 538, 540 /
*                                                                      *
*     Conversion from part to paprop numbering                         *
*                                                                      *
      DATA KPTIP1 / 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
     & 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 66*0,
     & 34, 36, 31, 32, 33, 35, 37, 5*0, 38, 5*0, 39, 68*0 /
*                                                                      *
*     Conversion from paprop to part numbering                         *
*                                                                      *
      DATA IPTKP1 / 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
     & 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 99,
     & 100, 101, 97, 102, 98, 103, 109, 115 /
* / Qquark /
      DATA IQECH1 / -2, 1, -2, 1, 1, -2, 0, 2, -1, -1, 2, -1, 2 /
      DATA IQBCH1 / 6*-1, 0, 6*1 /
      DATA IQICH1 / 4*0, 1, -1, 0, 1, -1, 4*0 /
      DATA IQSCH1 / 3*0, 1, 5*0, -1, 3*0 /
      DATA IQCCH1 / 2*0, -1, 7*0, 1, 2*0 /
      DATA IQUCH1 / 0, 1, 9*0, -1, 0 /
      DATA IQTCH1 / -1, 11*0, 1 /
      DATA MQUAR1 /                1,1,2,    -1,-1,-2,
     *   0,0,0,       0,0,0,       0,0,0,       0,0,0,       0,0,0,
     *   1,2,2,    -1,-2,-2,       0,0,0,       0,0,0,       0,0,0,
     *  1,-2,0,      2,-1,0,      1,-3,0,      3,-1,0,
     *   1,2,3,    -1,-2,-3,       0,0,0,
     *   2,2,3,     1,1,3,     1,2,3,     1,-1,0,
     *   2,-3,0,    3,-2,0,    2,-2,0,    0,0,0,
     *   0,0,0,       0,0,0,       0,0,0,
     *  -1,-1,-3,    -1,-2,-3,    -2,-2,-3,
     *   1,3,3,      -1,-3,-3,     2,3,3,      -2,-3,-3,
     *   3,3,3,      -3,-3,-3 /
*
      DO 10 J=1, 39
         IPTOKP(J)=IPTKP1(J)
   10 CONTINUE
      DO 20 J=1,IDMAX8
         AM(J)=AM1(J)
         GA(J)=GA1(J)
         TAU(J)=TAU1(J)
         ICH(J)=ICH1(J)
         IBAR(J)=IBAR1(J)
         K1(J)=K11(J)
         K2(J)=K21(J)
         KPTOIP(J)=KPTIP1(J)
         ANAME(J)=ANAME1(J)
   20 CONTINUE
      DO 30 J=-6,6
         IQECHR(J)=IQECH1(J)
         IQBCHR(J)=IQBCH1(J)
         IQICHR(J)=IQICH1(J)
         IQSCHR(J)=IQSCH1(J)
         IQCCHR(J)=IQCCH1(J)
         IQUCHR(J)=IQUCH1(J)
         IQTCHR(J)=IQTCH1(J)
   30 CONTINUE
      DO 50 J=1,3
         DO 40 I=1,39
            MQUARK(J,I)=MQUAR1(J,I)
   40    CONTINUE
   50 CONTINUE
*=                                               end*block.blkdt6      *
      END
