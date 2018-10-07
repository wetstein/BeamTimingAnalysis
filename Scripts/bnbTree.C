#define bnbTree_cxx
#include "bnbTree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void bnbTree::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L bnbTree.C
//      Root > bnbTree t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   TH1D* arrival_time = new TH1D("at","at",500,0.,4.);
   TH2D* at_vs_E = new TH2D("atvsE","atvsE",100,0.,10.,100,0.,4.);

   TH1D* Energy = new TH1D("Energy","Energy",100,0.,3.);
   TH1D* EnergyTb1 = new TH1D("EnergyTb1","EnergyTb1",100,0.,3.);
   TH1D* EnergyTb2 = new TH1D("EnergyTb2","EnergyTb2",100,0.,3.);
   TH1D* EnergyTb3 = new TH1D("EnergyTb3","EnergyTb3",100,0.,3.);

   // Tree variables
   int nparticles,nutype,nuparent;
   double nustartx,nustarty,nustartz,nustartT;
   double nuE, bwt;
   double nupx,nupy,nupz,nupperp,nuang;
   double parentpx,parentpy,parentpz,parentpperp;
   double parentE,parentang;
   double dT,dTsm0,dTsm1,dTsm2,dTsm3,dTsm4;

   double nuendx = 0.;
   double nuendy = 0.;
   double nuendz = 0.;
   double nuendT = 0.;

   TFile* tf = new TFile("outfile.root","recreate");
   TTree *outtree = new TTree("ANNIEOutTree","ANNIEOutTree");

   outtree->Branch("nutype",&nutype);
   outtree->Branch("nuparent",&nuparent);
   outtree->Branch("nparticles",&nparticles);
   outtree->Branch("nuE",&nuE);
   outtree->Branch("nupx",&nupx);
   outtree->Branch("nupy",&nupy);
   outtree->Branch("nupz",&nupz);
   outtree->Branch("nupperp",&nupperp);
   outtree->Branch("nuang",&nuang);
   outtree->Branch("nustartx",&nustartx);
   outtree->Branch("nustarty",&nustarty);
   outtree->Branch("nustartz",&nustartz);
   outtree->Branch("nustartT",&nustartT);
   outtree->Branch("nuendx",&nuendx);
   outtree->Branch("nuendy",&nuendy);
   outtree->Branch("nuendz",&nuendz);
   outtree->Branch("dT",&dT);
   outtree->Branch("dTs0",&dTsm0);
   outtree->Branch("dTs1",&dTsm1);
   outtree->Branch("dTs2",&dTsm2);
   outtree->Branch("dTs3",&dTsm3);
   outtree->Branch("dTs4",&dTsm4);
   outtree->Branch("parentE",&parentE);
   outtree->Branch("parentpx",&parentpx);
   outtree->Branch("parentpy",&parentpy);
   outtree->Branch("parentpz",&parentpz);
   outtree->Branch("parentpperp",&parentpperp);
   outtree->Branch("parentang",&parentang);
   outtree->Branch("bwt",&bwt);

   int rseed=64800095;

   TRandom3* mrand1 = new TRandom3(rseed);
   TRandom3* mrand2 = new TRandom3(rseed+1);

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      nutype=ntp;
      nuparent=id[1];
      nparticles=npart;

      nustartx = ini_pos[0][0];
      nustarty = ini_pos[0][1];
      nustartz = ini_pos[0][2];
      nustartT = ini_t[0];

      nupx = ini_mom[0][0];
      nupy = ini_mom[0][1];
      nupz = ini_mom[0][2];
      nupperp = sqrt(nupx*nupx+nupy*nupy);
      nuang = TMath::ATan(nupperp/nupz);

      parentpx = ini_mom[1][0];
      parentpy = ini_mom[1][1];
      parentpz = ini_mom[1][2];
      parentpperp = sqrt(parentpx*parentpx+parentpy*parentpy);
      parentE = ini_eng[1];
      parentang = TMath::ATan(parentpperp/parentpz);

      nuE = ini_eng[0];

      // Find Nus that make it to ANNIE ///////////////////////////////////////////////
      /////////////////////////////////////////////////////////////////////////////////

      double targetR=100.;
      double baseline=10000.;
      double xslope=0;
      double yslope=0;
      vector<double> vtransit;
      double transit=-1;
      bool passescut=false;

      if(nupz>0.){
        xslope = nupx/nupz;
        yslope = nupy/nupz;
        vtransit = Transit(nustartx, nustarty, nustartz, xslope, yslope, baseline, targetR);
      }

      double beamdist = sqrt(nustartx*nustartx + nustarty*nustarty + nustartz*nustartz);

      if(vtransit.size()>0){

        passescut=true;

        transit = vtransit.at(3);

        nuendT = nustartT + transit/30.;
        nuendx = nustartx + vtransit.at(0);
        nuendy = nustarty + vtransit.at(1);
        nuendz = nustartz + vtransit.at(2);

        double tshift = baseline/30.;
        double beamtime = nuendT-tshift;
        double timecorrection = beamdist/30.;

      }



      nuendx = ini_pos[0][0];
      nuendy = ini_pos[0][1];
      nuendz = ini_pos[0][2];

      bwt = (double)beamwgt;

      dT = nustartT - ((nustartz)/29.98);

      if(passescut){
        arrival_time->Fill(dT,bwt);
        Energy->Fill(nuE,bwt);

        if(dT>0.15){
            EnergyTb1->Fill(nuE,bwt);
        }

        if(dT>0.25){
          EnergyTb2->Fill(nuE,bwt);
        }

        if(dT>0.5){
          EnergyTb3->Fill(nuE,bwt);
        }
      }

      double ts0 = mrand1->Gaus(0,0.1);
      double ts1 = mrand1->Gaus(0,0.25);
      double ts2 = mrand1->Gaus(0,0.5);
      double ts3 = mrand2->Gaus(0,0.9);
      double ts4 = mrand2->Gaus(0,1.2);

      dTsm0 = dT + ts0;
      dTsm1 = dT + ts1;
      dTsm2 = dT + ts2;
      dTsm3 = dT + ts3;
      dTsm4 = dT + ts4;

      if(passescut) {
        at_vs_E->Fill(nuE,dT,bwt);
        outtree->Fill();
      }
   }

   TCanvas* tc1 = new TCanvas();
   arrival_time->Draw();

   TCanvas* tc2 = new TCanvas();
   at_vs_E->Draw("colz");

   TCanvas* tc3 = new TCanvas();
   Energy->Draw();
   EnergyTb1->SetLineColor(2);
   EnergyTb1->Draw("SAME");
   EnergyTb2->SetLineColor(4);
   EnergyTb2->Draw("SAME");
   EnergyTb3->SetLineColor(6);
   EnergyTb3->Draw("SAME");
   outtree->Write();
}


vector<double> bnbTree::Transit(double x0, double y0, double z0, double xslope, double yslope, double baseline, double radius){

  vector<double> vtransit;
  double transit;

  double deltaY = y0 + yslope*(baseline-z0);
  double deltaX = x0 + xslope*(baseline-z0);

  if(sqrt(deltaX*deltaX + deltaY*deltaY)<=radius){

    transit = sqrt( (baseline-z0)*(baseline-z0) + deltaY*deltaY + deltaX*deltaX );
    vtransit.push_back(deltaX);
    vtransit.push_back(deltaY);
    vtransit.push_back(baseline-z0);
    vtransit.push_back(transit);
  }


  return vtransit;
}
