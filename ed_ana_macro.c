#include "rsp_res_ana.c"

void ed_ana_macro(int num)
{
gROOT->LoadMacro("./rsp_res_ana.c");
char outFileName[80];
sprintf(outFileName, "run%05d.root",num);
TFile *d = new TFile(outFileName,"RECREATE");
rsp_res_ana(num, 0x80, 2);
d->Write("ngamma_tree");
d->Close();
gROOT->ProcessLine(".q");
}

