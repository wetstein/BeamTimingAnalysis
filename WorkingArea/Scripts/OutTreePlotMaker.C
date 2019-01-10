#define OutTreePlotMaker_cxx
#include "OutTreePlotMaker.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void OutTreePlotMaker::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L OutTreePlotMaker.C
//      Root > OutTreePlotMaker t
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

   bool smearing;
   smearing = false;

   bool isFHC;
   isFHC = true;

   double detectionsmearing=0.15;
   TH1D* bunchsmearing;

   TString outfilename;
   outfilename = "outfile_";
   if(isFHC) outfilename+="FHC_";
   else outfilename+="RHC_";
   if(smearing) outfilename+="smeared.root";
   else outfilename+="unsmeared.root";

   Long64_t nentries = fChain->GetEntriesFast();

   TH1D* BeamTiming = new TH1D("beamtiming","beamtiming",1200,-4.0,8.0);
   TH1D* BeamTimingSM1 = new TH1D("beamtimingSM1","beamtimingSM1",1200,-4.0,8.0);
   TH1D* BeamTimingSM2 = new TH1D("beamtimingSM2","beamtimingSM2",1200,-4.0,8.0);
   TH1D* BeamTimingSM3 = new TH1D("beamtimingSM3","beamtimingSM3",1200,-4.0,8.0);
   TH1D* BeamTimingSM4 = new TH1D("beamtimingSM4","beamtimingSM4",1200,-4.0,8.0);
   TH1D* BeamTimingRepeating = new TH1D("beamtimingRepeating","beamtimingRepeating",6100,-1.0,60.);

   TH1D* BeamTiming_piplus = new TH1D("beamtiming_piplus","beamtiming_piplus",1200,-4.0,8.0);
   TH1D* BeamTiming_piminus = new TH1D("beamtiming_piminus","beamtiming_piminus",1200,-4.0,8.0);
   TH1D* BeamTiming_kplus = new TH1D("beamtiming_kplus","beamtiming_kplus",1200,-4.0,8.0);
   TH1D* BeamTiming_kminus = new TH1D("beamtiming_kminus","beamtiming_kminus",1200,-4.0,8.0);

   TH1D* BeamTiming_nue = new TH1D("beamtiming_nue","beamtiming_nue",1200,-4.0,8.0);
   TH1D* BeamTiming_nuebar = new TH1D("beamtiming_nuebar","beamtiming_nuebar",1200,-4.0,8.0);
   TH1D* BeamTiming_numu = new TH1D("beamtiming_numu","beamtiming_numu",1200,-4.0,8.0);
   TH1D* BeamTiming_numubar = new TH1D("beamtiming_numubar","beamtiming_numubar",1200,-4.0,8.0);


   TH1D* AvgBeamE = new TH1D("AvgBeamE","AvgBeamE",1200,-4.0,8.0);

   TH1D* BeamEspect = new TH1D("BeamEspect","BeamEspect",500,0.,15.);
   TH1D* BeamEspect_cut1 = new TH1D("BeamEspect_cut1","BeamEspect_cut1",500,0.,15.);
   TH1D* BeamEspect_cut2 = new TH1D("BeamEspect_cut2","BeamEspect_cut2",500,0.,15.);
   TH1D* BeamEspect_cut3 = new TH1D("BeamEspect_cut3","BeamEspect_cut3",500,0.,15.);
   TH1D* BeamEspect_cut4 = new TH1D("BeamEspect_cut4","BeamEspect_cut4",500,0.,15.);
   TH1D* BeamEspect_cut5 = new TH1D("BeamEspect_cut5","BeamEspect_cut5",500,0.,15.);

   TH2D* BeamTimingRepeating2D = new TH2D("beamtimingRepeating2D","beamtimingRepeating2D",6100,-1.0,60.,1,0,1);
   TH2D* BeamTiming2Dcount = new TH2D("beamtiming2Dcount","beamtiming2Dcount",6100,-1.0,60.,1,0,1);


   TRandom3* tr = new TRandom3(234342);

   double dTr;

   //nentries=500000;
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      if(jentry%100000==0) cout<<jentry<<" out of "<<nentries<<endl;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      if(smearing==false) dTr = dT;
      //dTr = dT + this->SmearIt(0.1);

      BeamTiming->Fill(dTr,bwt);
      AvgBeamE->Fill(dTr,nuE*bwt);


      if(nutype==12) BeamTiming_nue->Fill(dTr,bwt);
      if(nutype==14) BeamTiming_numu->Fill(dTr,bwt);
      if(nutype==-12) BeamTiming_nuebar->Fill(dTr,bwt);
      if(nutype==-14) BeamTiming_numubar->Fill(dTr,bwt);

      if(nuparent==211) BeamTiming_piplus->Fill(dTr,bwt);
      if(nuparent==-211) BeamTiming_piminus->Fill(dTr,bwt);
      if(nuparent==321) BeamTiming_kplus->Fill(dTr,bwt);
      if(nuparent==-321) BeamTiming_kminus->Fill(dTr,bwt);

      BeamEspect->Fill(nuE,bwt);
      if(dT>0.1) BeamEspect_cut1->Fill(nuE,bwt);
      if(dT>0.25) BeamEspect_cut2->Fill(nuE,bwt);
      if(dT>0.5) BeamEspect_cut3->Fill(nuE,bwt);
      if(dT>0.75) BeamEspect_cut4->Fill(nuE,bwt);

      double dTsmr = dT + this->SmearIt(0.1);
      BeamTimingSM1->Fill(dTsmr,bwt);
      double dTsmr = dT + this->SmearIt(0.25);
      BeamTimingSM2->Fill(dTsmr,bwt);
      double dTsmr = dT + this->SmearIt(0.5);
      BeamTimingSM3->Fill(dTsmr,bwt);
      double dTsmr = dT + this->SmearIt(1.0);
      BeamTimingSM4->Fill(dTsmr,bwt);

      for(int i=0; i<6; i++){
        BeamTimingRepeating->Fill(dTr+(i*10.),bwt);

        //double rn = tr->Rndm();
        //if(tr->Rndm()<bwt){
        if(dT>0.0 && dT<1.5){
          BeamTimingRepeating2D->Fill(dTr+(i*10.),0.5,nuE*bwt);
          BeamTiming2Dcount->Fill(dTr+(i*10.),0.5,bwt);
        }
      }
      // if (Cut(ientry) < 0) continue;
   }


   TFile* theoutputhists = new TFile(outfilename,"RECREATE");
   BeamTiming->Write();
   BeamEspect_cut1->Write();
   BeamEspect_cut2->Write();
   BeamEspect_cut3->Write();
   BeamEspect_cut4->Write();
   BeamTimingSM1->Write();
   BeamTimingSM2->Write();
   BeamTimingSM3->Write();
   BeamTimingSM4->Write();
   BeamTiming_nue->Write();
   BeamTiming_numu->Write();
   BeamTiming_nuebar->Write();
   BeamTiming_numubar->Write();
   BeamTiming_piplus->Write();
   BeamTiming_piminus->Write();
   BeamTiming_kplus->Write();
   BeamTiming_kminus->Write();
   BeamTimingRepeating->Write();

   TCanvas *tc1 = new TCanvas("OriginalBeamTiming","Original Beam Timing");
   BeamTiming->Draw();

   TCanvas *tc5 = new TCanvas("BeamTimingSmeared","BeamTimingSmeared");
   BeamTiming->Draw();
   BeamTimingSM1->SetLineColor(2);
   BeamTimingSM1->Draw("SAME");
   BeamTimingSM2->SetLineColor(4);
   BeamTimingSM2->Draw("SAME");
   BeamTimingSM3->SetLineColor(6);
   BeamTimingSM3->Draw("SAME");
   BeamTimingSM4->SetLineColor(8);
   BeamTimingSM4->Draw("SAME");

   TCanvas *tc6 = new TCanvas("neutrinoFlav","neutrinoFlav");
   BeamTiming->Draw();
   BeamTiming_nue->SetLineColor(2);
   BeamTiming_nue->Draw("SAME");
   BeamTiming_numu->SetLineColor(4);
   BeamTiming_numu->Draw("SAME");
   BeamTiming_nuebar->SetLineColor(6);
   BeamTiming_nuebar->Draw("SAME");
   BeamTiming_numubar->SetLineColor(8);
   BeamTiming_numubar->Draw("SAME");

   TCanvas *tc7 = new TCanvas("Parent","Parent");
   BeamTiming->SetLineColor(1);
   BeamTiming->Draw();
   BeamTiming_piplus->SetLineColor(2);
   BeamTiming_piplus->Draw("SAME");
   BeamTiming_piminus->SetLineColor(4);
   BeamTiming_piminus->Draw("SAME");
   BeamTiming_kplus->SetLineColor(6);
   BeamTiming_kplus->Draw("SAME");
   BeamTiming_kminus->SetLineColor(8);
   BeamTiming_kminus->Draw("SAME");

   TCanvas *tc8 = new TCanvas("FlavaFractions","FlavaFractions");
   BeamTiming_numu->SetLineColor(4);
   BeamTiming_numu->Divide(BeamTiming);
   BeamTiming_numu->Draw();
   BeamTiming_nue->SetLineColor(2);
   BeamTiming_nue->Divide(BeamTiming);
   BeamTiming_nue->Draw("SAME");
   BeamTiming_nuebar->SetLineColor(6);
   BeamTiming_nuebar->Divide(BeamTiming);
   BeamTiming_nuebar->Draw("SAME");
   BeamTiming_numubar->SetLineColor(8);
   BeamTiming_numubar->Divide(BeamTiming);
   BeamTiming_numubar->Draw("SAME");

   TCanvas *tc9 = new TCanvas("ParentFractions","ParentFractions");
   BeamTiming_piplus->SetLineColor(2);
   BeamTiming_piplus->Divide(BeamTiming);
   BeamTiming_piplus->Draw();
   BeamTiming_piminus->SetLineColor(4);
   BeamTiming_piminus->Divide(BeamTiming);
   BeamTiming_piminus->Draw("SAME");
   BeamTiming_kplus->SetLineColor(6);
   BeamTiming_kplus->Divide(BeamTiming);
   BeamTiming_kplus->Draw("SAME");
   BeamTiming_kminus->SetLineColor(8);
   BeamTiming_kminus->Divide(BeamTiming);
   BeamTiming_kminus->Draw("SAME");

   BeamTiming_nue->Write("nue_Frac");
   BeamTiming_numu->Write("numu_Frac");
   BeamTiming_nuebar->Write("nuebar_Frac");
   BeamTiming_numubar->Write("numubar_Frac");
   BeamTiming_piplus->Write("piplus_Frac");
   BeamTiming_piminus->Write("piminus_Frac");
   BeamTiming_kplus->Write("kplus_Frac");
   BeamTiming_kminus->Write("kminus_Frac");


   TCanvas *tc2 = new TCanvas("BeamtTimeRepeating","BeamtTimeRepeating");
   BeamTimingRepeating->Draw();
   BeamTimingRepeating2D->Divide(BeamTiming2Dcount);

   TCanvas *tc3 = new TCanvas("BeamTimeandEnergy2D","BeamTimeandEnergy2D");
   BeamTimingRepeating2D->Draw("colz");
   TCanvas *tc4 = new TCanvas("AvgBeamEnergy","AvgBeamEnergy");
   AvgBeamE->Divide(BeamTiming);
   AvgBeamE->Draw();

   TCanvas *tc4 = new TCanvas("EnergySlices","EnergySlices");
   BeamEspect->Draw();
   BeamEspect_cut1->SetLineColor(2);
   BeamEspect_cut1->Draw("SAME");
   BeamEspect_cut2->SetLineColor(5);
   BeamEspect_cut2->Draw("SAME");
   BeamEspect_cut3->SetLineColor(8);
   BeamEspect_cut3->Draw("SAME");
   BeamEspect_cut4->SetLineColor(10);
   BeamEspect_cut4->Draw("SAME");

   AvgBeamE->Write();
   BeamTimingRepeating2D->Write();
   tc1->Write();
   tc2->Write();
   tc3->Write();
   tc4->Write();
   tc5->Write();
   tc6->Write();
   tc7->Write();
   tc8->Write();
   tc8->Write();


   theoutputhists->Close();
}


double OutTreePlotMaker::SmearIt(double timeresolution)
{
  double smR=0.;
  smR = trs->Gaus(0.,timeresolution);
  return smR;
}
