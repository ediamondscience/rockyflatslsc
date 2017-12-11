void edbsscalemac(int brun, int drun, double btime, double dtime)
{
char bgname[80];
sprintf(bgname, "/home/fgray/fadc_software/show_pulses/run%05d.root", brun);
char dtname[80];
sprintf(dtname, "/home/fgray/fadc_software/show_pulses/run%05d.root", drun);
TFile *bg = TFile::Open(bgname);

double xsfc = 0.1179;  
double xsfs = 0.07478;

ngamma_tree->Draw("areaResampled/(0.1215)>>bghist(500, 0, 8000)","","");
bghist->SetName("bghist");
TH1F* bghist = bghist;

TFile *dt = TFile::Open(dtname);
TTree* ngt2 = (TTree*) dt->Get("ngamma_tree");
ngt2->Draw("areaResampled/(0.0820)>>dthist(500,0,8000)","","");
dthist->SetName("dthist");

dthist->Sumw2();
bghist->Sumw2();

bghist->Scale(dtime/btime);

//divided areaResampled by scale factors

TH1F* bgsub;
cout<<dthist->Integral();
cout<<"\n";
dthist->Add(bghist, -1);
dthist->SetTitle("Uranium Sample (Background Subtracted)");
dthist->GetXaxis()->SetTitle("Energy (keV)");
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
