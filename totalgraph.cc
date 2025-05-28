void totalgraph() {

double dist[14] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140};
double sim1[14] = {7.47, 6.526, 5.705, 5.148, 4.651, 4.275, 3.968, 3.763, 3.438, 3.247, 3.155, 3.096, 3.008, 2.944};
double simerr1[14] = {1.04916, 1.04475, 1.016418, 1.00848, 0.87582, 0.860551, 0.8442456, 0.84065, 0.797184, 0.738804, 0.720125, 0.722128, 0.71544, 0.685696};
double sim2[14] = {7.62, 6.753, 5.89, 5.387, 4.925, 4.513, 4.255, 3.904, 3.72, 3.518, 3.399, 3.269, 3.222, 3.153};
double simerr2[14] = {1.127808, 1.069533, 1.009944, 0.9234744, 0.970224, 0.858714, 0.828776, 0.84422, 0.7998, 0.810505, 0.788046, 0.71079, 0.76825, 0.758032};
double sim3[14] = {6.52, 5.128, 4.262, 3.581, 3.057, 2.627, 2.291, 2.131, 1.81, 1.58, 1.459, 1.349, 1.271, 1.281};
double simerr3[14] = {1.14878, 0.867428, 0.77685, 0.74175, 0.695856, 0.630344, 0.548264, 0.5466678, 0.53244, 0.490365, 0.467698, 0.444618, 0.44454, 0.448725};
double exp[14] = {7, 5.94, 5.28, 5.14, 4.91, 4.66, 4.34, 4.24, 4.42, 4.32, 4.25, 4.3, 4.14, 4.31};
double experr[14] = {1.77, 1.59, 1.58, 1.51, 1.5, 1.47, 1.45, 1.45, 1.32, 1.32, 1.34, 1.27, 1.34, 1.31};

TCanvas *c1 = new TCanvas();
c1 -> SetGrid();
/*
TGraph *grb = new TGraphErrors(14, dist, exp, nullptr, experr);
grb -> SetFillColor(96);
grb -> SetFillStyle(3002);
grb -> SetLineColor(kRed);
grb -> GetYaxis() -> SetRangeUser(0, 9);
grb -> SetTitle("NPE vs Distance;Distance (cm);NPE");
grb -> Draw("a3");
*/
TGraph *gr1 = new TGraphErrors(14, dist, sim1, nullptr, simerr1);
/*
grs -> SetFillColor(4);
grs -> SetFillStyle(3003);
grs -> SetLineColor(kBlue);
grs -> Draw("3 SAME");
*/

gr1 -> SetMarkerStyle(21);
gr1 -> SetMarkerColor(38);
gr1 -> SetMarkerSize(2);
gr1 -> GetYaxis() -> SetRangeUser(0, 9);
gr1 -> SetTitle("NPE vs Distance (Simulation);Distance (cm);NPE");
//grs -> SetLineColor(kBlack);
//grs -> SetLineWidth(2);
gr1 -> Draw("AP");

TGraph *gr2 = new TGraphErrors(14, dist, sim2, nullptr, simerr2);

gr2 -> SetMarkerStyle(21);
gr2 -> SetMarkerColor(30);
gr2 -> SetMarkerSize(2);
gr2 -> Draw("P SAME");

TGraph *gr3 = new TGraphErrors(14, dist, sim3, nullptr, simerr3);

gr3 -> SetMarkerStyle(21);
gr3 -> SetMarkerColor(208);
gr3 -> SetMarkerSize(2);
gr3 -> Draw("P SAME");

TLegend *legend = new TLegend(0.5, 0.7, 0.9, 0.9);
legend -> AddEntry(gr1, "Reflectivity as a Function (~92%)", "lp");
legend -> AddEntry(gr2, "Constant Reflectivity 95%", "lp");
legend -> AddEntry(gr3, "LUTDAVIS Surface Model", "lp");
//legend -> AddEntry(grb, "Calib Experiment", "f");
legend -> Draw();

c1 -> Modified();
c1 -> Update();
}

