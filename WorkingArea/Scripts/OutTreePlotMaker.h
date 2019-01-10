//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Dec 24 13:43:36 2018 by ROOT version 5.34/36
// from TTree ANNIEOutTree/ANNIEOutTree
// found on file: outfileFHC_all.root
//////////////////////////////////////////////////////////

#ifndef OutTreePlotMaker_h
#define OutTreePlotMaker_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class OutTreePlotMaker {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           nutype;
   Int_t           nuparent;
   Int_t           nparticles;
   Double_t        nuE;
   Double_t        nupx;
   Double_t        nupy;
   Double_t        nupz;
   Double_t        nupperp;
   Double_t        nuang;
   Double_t        nustartx;
   Double_t        nustarty;
   Double_t        nustartz;
   Double_t        nustartT;
   Double_t        nuendx;
   Double_t        nuendy;
   Double_t        nuendz;
   Double_t        dT;
   Double_t        dTs0;
   Double_t        dTs1;
   Double_t        dTs2;
   Double_t        dTs3;
   Double_t        dTs4;
   Double_t        parentE;
   Double_t        parentpx;
   Double_t        parentpy;
   Double_t        parentpz;
   Double_t        parentpperp;
   Double_t        parentang;
   Double_t        bwt;

   // List of branches
   TBranch        *b_nutype;   //!
   TBranch        *b_nuparent;   //!
   TBranch        *b_nparticles;   //!
   TBranch        *b_nuE;   //!
   TBranch        *b_nupx;   //!
   TBranch        *b_nupy;   //!
   TBranch        *b_nupz;   //!
   TBranch        *b_nupperp;   //!
   TBranch        *b_nuang;   //!
   TBranch        *b_nustartx;   //!
   TBranch        *b_nustarty;   //!
   TBranch        *b_nustartz;   //!
   TBranch        *b_nustartT;   //!
   TBranch        *b_nuendx;   //!
   TBranch        *b_nuendy;   //!
   TBranch        *b_nuendz;   //!
   TBranch        *b_dT;   //!
   TBranch        *b_dTs0;   //!
   TBranch        *b_dTs1;   //!
   TBranch        *b_dTs2;   //!
   TBranch        *b_dTs3;   //!
   TBranch        *b_dTs4;   //!
   TBranch        *b_parentE;   //!
   TBranch        *b_parentpx;   //!
   TBranch        *b_parentpy;   //!
   TBranch        *b_parentpz;   //!
   TBranch        *b_parentpperp;   //!
   TBranch        *b_parentang;   //!
   TBranch        *b_bwt;   //!

   TRandom3* trs;

   OutTreePlotMaker(TTree *tree=0);
   virtual ~OutTreePlotMaker();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   double SmearIt(double res);
};

#endif

#ifdef OutTreePlotMaker_cxx
OutTreePlotMaker::OutTreePlotMaker(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("outfileFHC_all.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("outfileFHC_all.root");
      }
      f->GetObject("ANNIEOutTree",tree);

   }
   Init(tree);
}

OutTreePlotMaker::~OutTreePlotMaker()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t OutTreePlotMaker::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t OutTreePlotMaker::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void OutTreePlotMaker::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("nutype", &nutype, &b_nutype);
   fChain->SetBranchAddress("nuparent", &nuparent, &b_nuparent);
   fChain->SetBranchAddress("nparticles", &nparticles, &b_nparticles);
   fChain->SetBranchAddress("nuE", &nuE, &b_nuE);
   fChain->SetBranchAddress("nupx", &nupx, &b_nupx);
   fChain->SetBranchAddress("nupy", &nupy, &b_nupy);
   fChain->SetBranchAddress("nupz", &nupz, &b_nupz);
   fChain->SetBranchAddress("nupperp", &nupperp, &b_nupperp);
   fChain->SetBranchAddress("nuang", &nuang, &b_nuang);
   fChain->SetBranchAddress("nustartx", &nustartx, &b_nustartx);
   fChain->SetBranchAddress("nustarty", &nustarty, &b_nustarty);
   fChain->SetBranchAddress("nustartz", &nustartz, &b_nustartz);
   fChain->SetBranchAddress("nustartT", &nustartT, &b_nustartT);
   fChain->SetBranchAddress("nuendx", &nuendx, &b_nuendx);
   fChain->SetBranchAddress("nuendy", &nuendy, &b_nuendy);
   fChain->SetBranchAddress("nuendz", &nuendz, &b_nuendz);
   fChain->SetBranchAddress("dT", &dT, &b_dT);
   fChain->SetBranchAddress("dTs0", &dTs0, &b_dTs0);
   fChain->SetBranchAddress("dTs1", &dTs1, &b_dTs1);
   fChain->SetBranchAddress("dTs2", &dTs2, &b_dTs2);
   fChain->SetBranchAddress("dTs3", &dTs3, &b_dTs3);
   fChain->SetBranchAddress("dTs4", &dTs4, &b_dTs4);
   fChain->SetBranchAddress("parentE", &parentE, &b_parentE);
   fChain->SetBranchAddress("parentpx", &parentpx, &b_parentpx);
   fChain->SetBranchAddress("parentpy", &parentpy, &b_parentpy);
   fChain->SetBranchAddress("parentpz", &parentpz, &b_parentpz);
   fChain->SetBranchAddress("parentpperp", &parentpperp, &b_parentpperp);
   fChain->SetBranchAddress("parentang", &parentang, &b_parentang);
   fChain->SetBranchAddress("bwt", &bwt, &b_bwt);

   trs = new TRandom3(12441);

   Notify();
}

Bool_t OutTreePlotMaker::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void OutTreePlotMaker::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t OutTreePlotMaker::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef OutTreePlotMaker_cxx
