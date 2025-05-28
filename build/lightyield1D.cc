void lightyield1D(){

TFile *gammafile = new TFile("eventgamma_1000.root", "READ");
TTree *gammatree = (TTree *) gammafile -> Get("event");

int n_photons_gamma;
double dE_gamma;

gammatree -> SetBranchAddress("n_photons", &n_photons_gamma);
gammatree -> SetBranchAddress("dE", &dE_gamma);

TCanvas *c1 = new TCanvas();
c1 -> Divide(2,1);

TH1D *h1 = new TH1D("h1", "Lightyield Distribution (#gamma)", 100, 0, 5);

for (int i = 0; i < 1000; i++) {

    gammatree -> GetEntry(i);

    h1 -> Fill(n_photons_gamma/dE_gamma);

}

c1 -> cd(1);
h1 -> GetXaxis() -> SetTitle("Lightyield");
h1 -> GetYaxis() -> SetTitle("Counts");
h1 -> Draw();

TFile *mufile = new TFile("eventmu_1000.root", "READ");
TTree *mutree = (TTree *) mufile -> Get("event");

int n_photons_mu;
double dE_mu;

mutree -> SetBranchAddress("n_photons", &n_photons_mu);
mutree -> SetBranchAddress("dE", &dE_mu);

TH1D *h2 = new TH1D("h2", "Lightyield Distribution (#mu)", 100, 0, 5);

for (int j = 0; j < 1000; j++) {

    mutree -> GetEntry(j);

    h2 -> Fill(n_photons_mu/dE_mu);

}

c1 -> cd(2);
h2 -> GetXaxis() -> SetTitle("Lightyield");
h2 -> GetYaxis() -> SetTitle("Counts");
h2 -> Draw();

}
