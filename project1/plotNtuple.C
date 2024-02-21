// ROOT macro file for plotting project1 ntuple
//
// Can be run from ROOT session:
// root[0] .x plotNtuple.C

{
  gROOT->Reset();
  gROOT->SetStyle("Plain");

  // Draw histos filled by Geant4 simulation
  //

  // Open file filled by Geant4 simulation
  TFile f("project1.root");

  // Create a canvas and divide it into 2x2 pads
  TCanvas* c1 = new TCanvas("c1", "", 20, 20, 1000, 1000);
  //c1->Divide(2,2);
  c1->Divide(2,2);

  // Get ntuple
  TNtuple* ntuple = (TNtuple*)f.Get("project1");

  c1->cd(1);
  ntuple->Draw("Eenv");

  c1->cd(2);
  ntuple->Draw("Emat1");

  c1->cd(3);
  ntuple->Draw("Emat2");

  c1->cd(4);
  ntuple->Draw("Emat3");

  //set logarithmic scale for y
  //gPad->SetLogy(1); 
}
