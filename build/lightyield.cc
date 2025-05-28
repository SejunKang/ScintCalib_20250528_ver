void lightyield() {

TFile *gammafile = new TFile("eventgamma_1000.root", "READ");
TTree *gammatree = (TTree *) gammafile -> Get("event");

int n_photons_gamma;
double dE_gamma;

gammatree -> SetBranchAddress("n_photons", &n_photons_gamma);
gammatree -> SetBranchAddress("dE", &dE_gamma);

TCanvas *c1 = new TCanvas();
c1 -> Divide(2,1);

TH2D *h1 = new TH2D("h1", "Gamma Energy vs # of photons Distribution", 100, 0, 25, 100, 0, 70);

for (int i = 0; i < 1000; i++) {

    gammatree -> GetEntry(i);

    h1 -> Fill(dE_gamma, n_photons_gamma);

}

c1 -> cd(1);
h1 -> GetXaxis() -> SetTitle("#DeltaE");
h1 -> GetYaxis() -> SetTitle("# of photons");
h1 -> Draw("COLZ");

TFile *mufile = new TFile("eventmu_1000.root", "READ");
TTree *mutree = (TTree *) mufile -> Get("event");

int n_photons_mu;
double dE_mu;

mutree -> SetBranchAddress("n_photons", &n_photons_mu);
mutree -> SetBranchAddress("dE", &dE_mu);

TH2D *h2 = new TH2D("h2", "Muon Energy vs # of photons Distribution", 100, 6000, 22000, 100, 15000, 45000);

for (int j = 0; j < 1000; j++) {

    mutree -> GetEntry(j);

    h2 -> Fill(dE_mu, n_photons_mu);

}

c1 -> cd(2);
h2 -> GetXaxis() -> SetTitle("#DeltaE");
h2 -> GetYaxis() -> SetTitle("# of photons");
h2 -> Draw("COLZ");

}
