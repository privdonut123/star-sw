#include "tables/St_Survey_Table.h"

TDataSet *CreateTable() {
  if (!gROOT->GetClass("St_Survey")) return 0;
  Survey_st row = {0, 1,0,0, 0,1,0, 0,0,1, 0,0,0,.1,.1,.1,.1,.1,.1,"ideal position"};
  St_Survey *tableSet = new St_Survey("SvtOnGlobal",1);
  tableSet->AddAt(&row.Id, 0);
  return (TDataSet *)tableSet;
}
