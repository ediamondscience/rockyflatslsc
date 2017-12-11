void edbsmac(int brun, int drun, double btime, double dtime)
{
char bgname[80];
sprintf(bgname, "/home/fgray/fadc_software/show_pulses/run%05d.root", brun);
char dtname[80];
sprintf(dtname, "/home/fgray/fadc_software/show_pulses/run%05d.root", drun);
TFile *bg = TFile::Open(bgname);
//TFile *dt = TFile::Open(dtname);

//gROOT->ProcessLine("bg->cd()");
ngamma_tree->Draw("areaResampled>>bghist(500, 0, 1000)","","");
bghist->SetName("bghist");
TH1F* bghist = bghist;

TFile *dt = TFile::Open(dtname);
//gROOT->ProcessLine("dt->cd()");
TTree* ngt2 = (TTree*) dt->Get("ngamma_tree");
ngt2->Draw("areaResampled>>dthist(500,0,1000)","","");
dthist->SetName("dthist");
bghist->Scale(dtime/btime);
TH1F* bgsub;
cout<<dthist->Integral();
cout<<"\n";
dthist->Add(bghist, -1);

cout<<dthist->Integral();
cout << "\n";
//c2 = new TCanvas();
dthist->Draw();
char outFileName[80];
sprintf(outFileName,"bs%d%d.root", brun, drun);
TFile *newfile = new TFile(outFileName, "RECREATE");
newfile->Write("dthist"); 
newfile->Close();
} 
