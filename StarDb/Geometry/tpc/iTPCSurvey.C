#include "tables/St_iTPCSurvey_Table.h"

TDataSet *CreateTable() { 
  if (!gROOT->GetClass("St_iTPCSurvey")) return 0;
  iTPCSurvey_st row[24] = {
    //  Id,    Angle,    dx,    dy,  ScaleX,  ScaleY,  comment[32],
    {    1,        0,     0,     0,       0,       0, ""},
    {    2,        0,     0,     0,       0,       0, ""},
    {    3,        0,     0,     0,       0,       0, ""},
    {    4,        0,     0,     0,       0,       0, ""},
    {    5,        0,     0,     0,       0,       0, ""},
    {    6,        0,     0,     0,       0,       0, ""},
    {    7,        0,     0,     0,       0,       0, ""},
    {    8,        0,     0,     0,       0,       0, ""},
    {    9,        0,     0,     0,       0,       0, ""},
    {   10,        0,     0,     0,       0,       0, ""},
    {   11,        0,     0,     0,       0,       0, ""},
    {   12,        0,     0,     0,       0,       0, ""},
    {   13,        0,     0,     0,       0,       0, ""},
    {   14,        0,     0,     0,       0,       0, ""},
    {   15,        0,     0,     0,       0,       0, ""},
    {   16,        0,     0,     0,       0,       0, ""},
    {   17,        0,     0,     0,       0,       0, ""},
    {   18,        0,     0,     0,       0,       0, ""},
    {   19,        0,     0,     0,       0,       0, ""},
    {   20, -47.2e-6, -1e-4, 24e-4, 3.26e-4, 1.09e-4, "SN006"},
    {   21,        0,     0,     0,       0,       0, ""},
    {   22,        0,     0,     0,       0,       0, ""},
    {   23,        0,     0,     0,       0,       0, ""},
    {   24,        0,     0,     0,       0,       0, ""}
  };
  Int_t n = 24;
  St_iTPCSurvey *tableSet = new St_iTPCSurvey("iTPCSurvey",n);
  for (Int_t i = 1; i <= 24; i++) {
    tableSet->AddAt(&row[i-1].Id);
  }
  return (TDataSet *)tableSet;
}
