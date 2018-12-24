//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Mar 23 21:13:47 2018 by ROOT version 5.34/36
// from TTree bnbTree/BNB tree
// found on file: beammc_annie_0000.root
//////////////////////////////////////////////////////////

#ifndef bnbTree_h
#define bnbTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class bnbTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Float_t         beamwgt;
   Int_t           ntp;
   Int_t           npart;
   Int_t           id[7];   //[npart]
   Float_t         ini_pos[7][3];   //[npart]
   Float_t         ini_mom[7][3];   //[npart]
   Float_t         ini_eng[7];   //[npart]
   Float_t         ini_t[7];   //[npart]
   Float_t         fin_mom[7][3];   //[npart]
   Float_t         fin_pol[7][3];   //[npart]
   Float_t         mul_weight[7][1000];

   // List of branches
   TBranch        *b_beamwgt;   //!
   TBranch        *b_ntp;   //!
   TBranch        *b_npart;   //!
   TBranch        *b_id;   //!
   TBranch        *b_ini_pos;   //!
   TBranch        *b_ini_mom;   //!
   TBranch        *b_ini_eng;   //!
   TBranch        *b_ini_t;   //!
   TBranch        *b_fin_mom;   //!
   TBranch        *b_fin_pol;   //!
   TBranch        *b_mul_weight;   //!

   bnbTree(TTree *tree=0);
   virtual ~bnbTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   vector<double>   Transit(double x0, double y0, double z0, double xslope, double yslope, double baseline, double radius);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef bnbTree_cxx
bnbTree::bnbTree(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("beammc_annie_0000.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("beammc_annie_0000.root");
      }
      f->GetObject("h201",tree);

   }
   Init(tree);
}

bnbTree::~bnbTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t bnbTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t bnbTree::LoadTree(Long64_t entry)
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

void bnbTree::Init(TTree *tree)
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

   fChain->SetBranchAddress("beamwgt", &beamwgt, &b_beamwgt);
   fChain->SetBranchAddress("ntp", &ntp, &b_ntp);
   fChain->SetBranchAddress("npart", &npart, &b_npart);
   fChain->SetBranchAddress("id", id, &b_id);
   fChain->SetBranchAddress("ini_pos", ini_pos, &b_ini_pos);
   fChain->SetBranchAddress("ini_mom", ini_mom, &b_ini_mom);
   fChain->SetBranchAddress("ini_eng", ini_eng, &b_ini_eng);
   fChain->SetBranchAddress("ini_t", ini_t, &b_ini_t);
   fChain->SetBranchAddress("fin_mom", fin_mom, &b_fin_mom);
   fChain->SetBranchAddress("fin_pol", fin_pol, &b_fin_pol);
   fChain->SetBranchAddress("mul_weight", mul_weight, &b_mul_weight);
   Notify();
}

Bool_t bnbTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void bnbTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t bnbTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef bnbTree_cxx
