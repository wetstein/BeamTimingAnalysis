//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Jul 21 16:19:22 2018 by ROOT version 5.34/36
// from TTree dk2nuTree/g4lbne neutrino ntuple, dk2Nu format
// found on file: g4lbne_v3r5p4_QGSP_BERT_OptimizedEngineeredNov2017_neutrino_00118.dk2nu.root
//////////////////////////////////////////////////////////

#ifndef dk2nuTree_h
#define dk2nuTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxnuray = 3;
   const Int_t kMaxancestor = 15;
   const Int_t kMaxtraj = 10;

class dk2nuTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
 //bsim::Dk2Nu     *dk2nu;
   Int_t           job;
   Int_t           potnum;
   Int_t           decay_norig;
   Int_t           decay_ndecay;
   Int_t           decay_ntype;
   Double_t        decay_vx;
   Double_t        decay_vy;
   Double_t        decay_vz;
   Double_t        decay_pdpx;
   Double_t        decay_pdpy;
   Double_t        decay_pdpz;
   Double_t        decay_ppdxdz;
   Double_t        decay_ppdydz;
   Double_t        decay_pppz;
   Double_t        decay_ppenergy;
   Int_t           decay_ppmedium;
   Int_t           decay_ptype;
   Double_t        decay_muparpx;
   Double_t        decay_muparpy;
   Double_t        decay_muparpz;
   Double_t        decay_mupare;
   Double_t        decay_necm;
   Double_t        decay_nimpwt;
   Int_t           nuray_;
   Double_t        nuray_px[kMaxnuray];   //[nuray_]
   Double_t        nuray_py[kMaxnuray];   //[nuray_]
   Double_t        nuray_pz[kMaxnuray];   //[nuray_]
   Double_t        nuray_E[kMaxnuray];   //[nuray_]
   Double_t        nuray_wgt[kMaxnuray];   //[nuray_]
   Int_t           ancestor_;
   Int_t           ancestor_pdg[kMaxancestor];   //[ancestor_]
   Double_t        ancestor_startx[kMaxancestor];   //[ancestor_]
   Double_t        ancestor_starty[kMaxancestor];   //[ancestor_]
   Double_t        ancestor_startz[kMaxancestor];   //[ancestor_]
   Double_t        ancestor_startt[kMaxancestor];   //[ancestor_]
   Double_t        ancestor_startpx[kMaxancestor];   //[ancestor_]
   Double_t        ancestor_startpy[kMaxancestor];   //[ancestor_]
   Double_t        ancestor_startpz[kMaxancestor];   //[ancestor_]
   Double_t        ancestor_stoppx[kMaxancestor];   //[ancestor_]
   Double_t        ancestor_stoppy[kMaxancestor];   //[ancestor_]
   Double_t        ancestor_stoppz[kMaxancestor];   //[ancestor_]
   Double_t        ancestor_polx[kMaxancestor];   //[ancestor_]
   Double_t        ancestor_poly[kMaxancestor];   //[ancestor_]
   Double_t        ancestor_polz[kMaxancestor];   //[ancestor_]
   Double_t        ancestor_pprodpx[kMaxancestor];   //[ancestor_]
   Double_t        ancestor_pprodpy[kMaxancestor];   //[ancestor_]
   Double_t        ancestor_pprodpz[kMaxancestor];   //[ancestor_]
   Int_t           ancestor_nucleus[kMaxancestor];   //[ancestor_]
   Int_t           ancestor_parIndex[kMaxancestor];   //[ancestor_]
   string          ancestor_proc[kMaxancestor];
   string          ancestor_ivol[kMaxancestor];
   string          ancestor_imat[kMaxancestor];
   Double_t        ppvx;
   Double_t        ppvy;
   Double_t        ppvz;
   Double_t        tgtexit_tvx;
   Double_t        tgtexit_tvy;
   Double_t        tgtexit_tvz;
   Double_t        tgtexit_tpx;
   Double_t        tgtexit_tpy;
   Double_t        tgtexit_tpz;
   Int_t           tgtexit_tptype;
   Int_t           tgtexit_tgen;
   Int_t           traj_;
   Double_t        traj_trkx[kMaxtraj];   //[traj_]
   Double_t        traj_trky[kMaxtraj];   //[traj_]
   Double_t        traj_trkz[kMaxtraj];   //[traj_]
   Double_t        traj_trkpx[kMaxtraj];   //[traj_]
   Double_t        traj_trkpy[kMaxtraj];   //[traj_]
   Double_t        traj_trkpz[kMaxtraj];   //[traj_]
   Int_t           flagbits;
   vector<int>     vint;
   vector<double>  vdbl;

   // List of branches
   TBranch        *b_dk2nu_job;   //!
   TBranch        *b_dk2nu_potnum;   //!
   TBranch        *b_dk2nu_decay_norig;   //!
   TBranch        *b_dk2nu_decay_ndecay;   //!
   TBranch        *b_dk2nu_decay_ntype;   //!
   TBranch        *b_dk2nu_decay_vx;   //!
   TBranch        *b_dk2nu_decay_vy;   //!
   TBranch        *b_dk2nu_decay_vz;   //!
   TBranch        *b_dk2nu_decay_pdpx;   //!
   TBranch        *b_dk2nu_decay_pdpy;   //!
   TBranch        *b_dk2nu_decay_pdpz;   //!
   TBranch        *b_dk2nu_decay_ppdxdz;   //!
   TBranch        *b_dk2nu_decay_ppdydz;   //!
   TBranch        *b_dk2nu_decay_pppz;   //!
   TBranch        *b_dk2nu_decay_ppenergy;   //!
   TBranch        *b_dk2nu_decay_ppmedium;   //!
   TBranch        *b_dk2nu_decay_ptype;   //!
   TBranch        *b_dk2nu_decay_muparpx;   //!
   TBranch        *b_dk2nu_decay_muparpy;   //!
   TBranch        *b_dk2nu_decay_muparpz;   //!
   TBranch        *b_dk2nu_decay_mupare;   //!
   TBranch        *b_dk2nu_decay_necm;   //!
   TBranch        *b_dk2nu_decay_nimpwt;   //!
   TBranch        *b_dk2nu_nuray_;   //!
   TBranch        *b_nuray_px;   //!
   TBranch        *b_nuray_py;   //!
   TBranch        *b_nuray_pz;   //!
   TBranch        *b_nuray_E;   //!
   TBranch        *b_nuray_wgt;   //!
   TBranch        *b_dk2nu_ancestor_;   //!
   TBranch        *b_ancestor_pdg;   //!
   TBranch        *b_ancestor_startx;   //!
   TBranch        *b_ancestor_starty;   //!
   TBranch        *b_ancestor_startz;   //!
   TBranch        *b_ancestor_startt;   //!
   TBranch        *b_ancestor_startpx;   //!
   TBranch        *b_ancestor_startpy;   //!
   TBranch        *b_ancestor_startpz;   //!
   TBranch        *b_ancestor_stoppx;   //!
   TBranch        *b_ancestor_stoppy;   //!
   TBranch        *b_ancestor_stoppz;   //!
   TBranch        *b_ancestor_polx;   //!
   TBranch        *b_ancestor_poly;   //!
   TBranch        *b_ancestor_polz;   //!
   TBranch        *b_ancestor_pprodpx;   //!
   TBranch        *b_ancestor_pprodpy;   //!
   TBranch        *b_ancestor_pprodpz;   //!
   TBranch        *b_ancestor_nucleus;   //!
   TBranch        *b_ancestor_parIndex;   //!
   TBranch        *b_ancestor_proc;   //!
   TBranch        *b_ancestor_ivol;   //!
   TBranch        *b_ancestor_imat;   //!
   TBranch        *b_dk2nu_ppvx;   //!
   TBranch        *b_dk2nu_ppvy;   //!
   TBranch        *b_dk2nu_ppvz;   //!
   TBranch        *b_dk2nu_tgtexit_tvx;   //!
   TBranch        *b_dk2nu_tgtexit_tvy;   //!
   TBranch        *b_dk2nu_tgtexit_tvz;   //!
   TBranch        *b_dk2nu_tgtexit_tpx;   //!
   TBranch        *b_dk2nu_tgtexit_tpy;   //!
   TBranch        *b_dk2nu_tgtexit_tpz;   //!
   TBranch        *b_dk2nu_tgtexit_tptype;   //!
   TBranch        *b_dk2nu_tgtexit_tgen;   //!
   TBranch        *b_dk2nu_traj_;   //!
   TBranch        *b_traj_trkx;   //!
   TBranch        *b_traj_trky;   //!
   TBranch        *b_traj_trkz;   //!
   TBranch        *b_traj_trkpx;   //!
   TBranch        *b_traj_trkpy;   //!
   TBranch        *b_traj_trkpz;   //!
   TBranch        *b_dk2nu_flagbits;   //!
   TBranch        *b_dk2nu_vint;   //!
   TBranch        *b_dk2nu_vdbl;   //!

   dk2nuTree(TTree *tree=0);
   virtual ~dk2nuTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef dk2nuTree_cxx
dk2nuTree::dk2nuTree(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("g4lbne_v3r5p4_QGSP_BERT_OptimizedEngineeredNov2017_neutrino_00118.dk2nu.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("g4lbne_v3r5p4_QGSP_BERT_OptimizedEngineeredNov2017_neutrino_00165.dk2nu.root");
      }
      f->GetObject("dk2nuTree",tree);

   }
   Init(tree);
}

dk2nuTree::~dk2nuTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t dk2nuTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t dk2nuTree::LoadTree(Long64_t entry)
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

void dk2nuTree::Init(TTree *tree)
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

   fChain->SetBranchAddress("job", &job, &b_dk2nu_job);
   fChain->SetBranchAddress("potnum", &potnum, &b_dk2nu_potnum);
   fChain->SetBranchAddress("decay.norig", &decay_norig, &b_dk2nu_decay_norig);
   fChain->SetBranchAddress("decay.ndecay", &decay_ndecay, &b_dk2nu_decay_ndecay);
   fChain->SetBranchAddress("decay.ntype", &decay_ntype, &b_dk2nu_decay_ntype);
   fChain->SetBranchAddress("decay.vx", &decay_vx, &b_dk2nu_decay_vx);
   fChain->SetBranchAddress("decay.vy", &decay_vy, &b_dk2nu_decay_vy);
   fChain->SetBranchAddress("decay.vz", &decay_vz, &b_dk2nu_decay_vz);
   fChain->SetBranchAddress("decay.pdpx", &decay_pdpx, &b_dk2nu_decay_pdpx);
   fChain->SetBranchAddress("decay.pdpy", &decay_pdpy, &b_dk2nu_decay_pdpy);
   fChain->SetBranchAddress("decay.pdpz", &decay_pdpz, &b_dk2nu_decay_pdpz);
   fChain->SetBranchAddress("decay.ppdxdz", &decay_ppdxdz, &b_dk2nu_decay_ppdxdz);
   fChain->SetBranchAddress("decay.ppdydz", &decay_ppdydz, &b_dk2nu_decay_ppdydz);
   fChain->SetBranchAddress("decay.pppz", &decay_pppz, &b_dk2nu_decay_pppz);
   fChain->SetBranchAddress("decay.ppenergy", &decay_ppenergy, &b_dk2nu_decay_ppenergy);
   fChain->SetBranchAddress("decay.ppmedium", &decay_ppmedium, &b_dk2nu_decay_ppmedium);
   fChain->SetBranchAddress("decay.ptype", &decay_ptype, &b_dk2nu_decay_ptype);
   fChain->SetBranchAddress("decay.muparpx", &decay_muparpx, &b_dk2nu_decay_muparpx);
   fChain->SetBranchAddress("decay.muparpy", &decay_muparpy, &b_dk2nu_decay_muparpy);
   fChain->SetBranchAddress("decay.muparpz", &decay_muparpz, &b_dk2nu_decay_muparpz);
   fChain->SetBranchAddress("decay.mupare", &decay_mupare, &b_dk2nu_decay_mupare);
   fChain->SetBranchAddress("decay.necm", &decay_necm, &b_dk2nu_decay_necm);
   fChain->SetBranchAddress("decay.nimpwt", &decay_nimpwt, &b_dk2nu_decay_nimpwt);
   fChain->SetBranchAddress("nuray", &nuray_, &b_dk2nu_nuray_);
   fChain->SetBranchAddress("nuray.px", nuray_px, &b_nuray_px);
   fChain->SetBranchAddress("nuray.py", nuray_py, &b_nuray_py);
   fChain->SetBranchAddress("nuray.pz", nuray_pz, &b_nuray_pz);
   fChain->SetBranchAddress("nuray.E", nuray_E, &b_nuray_E);
   fChain->SetBranchAddress("nuray.wgt", nuray_wgt, &b_nuray_wgt);
   fChain->SetBranchAddress("ancestor", &ancestor_, &b_dk2nu_ancestor_);
   fChain->SetBranchAddress("ancestor.pdg", ancestor_pdg, &b_ancestor_pdg);
   fChain->SetBranchAddress("ancestor.startx", ancestor_startx, &b_ancestor_startx);
   fChain->SetBranchAddress("ancestor.starty", ancestor_starty, &b_ancestor_starty);
   fChain->SetBranchAddress("ancestor.startz", ancestor_startz, &b_ancestor_startz);
   fChain->SetBranchAddress("ancestor.startt", ancestor_startt, &b_ancestor_startt);
   fChain->SetBranchAddress("ancestor.startpx", ancestor_startpx, &b_ancestor_startpx);
   fChain->SetBranchAddress("ancestor.startpy", ancestor_startpy, &b_ancestor_startpy);
   fChain->SetBranchAddress("ancestor.startpz", ancestor_startpz, &b_ancestor_startpz);
   fChain->SetBranchAddress("ancestor.stoppx", ancestor_stoppx, &b_ancestor_stoppx);
   fChain->SetBranchAddress("ancestor.stoppy", ancestor_stoppy, &b_ancestor_stoppy);
   fChain->SetBranchAddress("ancestor.stoppz", ancestor_stoppz, &b_ancestor_stoppz);
   fChain->SetBranchAddress("ancestor.polx", ancestor_polx, &b_ancestor_polx);
   fChain->SetBranchAddress("ancestor.poly", ancestor_poly, &b_ancestor_poly);
   fChain->SetBranchAddress("ancestor.polz", ancestor_polz, &b_ancestor_polz);
   fChain->SetBranchAddress("ancestor.pprodpx", ancestor_pprodpx, &b_ancestor_pprodpx);
   fChain->SetBranchAddress("ancestor.pprodpy", ancestor_pprodpy, &b_ancestor_pprodpy);
   fChain->SetBranchAddress("ancestor.pprodpz", ancestor_pprodpz, &b_ancestor_pprodpz);
   fChain->SetBranchAddress("ancestor.nucleus", ancestor_nucleus, &b_ancestor_nucleus);
   fChain->SetBranchAddress("ancestor.parIndex", ancestor_parIndex, &b_ancestor_parIndex);
   fChain->SetBranchAddress("ancestor.proc", ancestor_proc, &b_ancestor_proc);
   fChain->SetBranchAddress("ancestor.ivol", ancestor_ivol, &b_ancestor_ivol);
   fChain->SetBranchAddress("ancestor.imat", ancestor_imat, &b_ancestor_imat);
   fChain->SetBranchAddress("ppvx", &ppvx, &b_dk2nu_ppvx);
   fChain->SetBranchAddress("ppvy", &ppvy, &b_dk2nu_ppvy);
   fChain->SetBranchAddress("ppvz", &ppvz, &b_dk2nu_ppvz);
   fChain->SetBranchAddress("tgtexit.tvx", &tgtexit_tvx, &b_dk2nu_tgtexit_tvx);
   fChain->SetBranchAddress("tgtexit.tvy", &tgtexit_tvy, &b_dk2nu_tgtexit_tvy);
   fChain->SetBranchAddress("tgtexit.tvz", &tgtexit_tvz, &b_dk2nu_tgtexit_tvz);
   fChain->SetBranchAddress("tgtexit.tpx", &tgtexit_tpx, &b_dk2nu_tgtexit_tpx);
   fChain->SetBranchAddress("tgtexit.tpy", &tgtexit_tpy, &b_dk2nu_tgtexit_tpy);
   fChain->SetBranchAddress("tgtexit.tpz", &tgtexit_tpz, &b_dk2nu_tgtexit_tpz);
   fChain->SetBranchAddress("tgtexit.tptype", &tgtexit_tptype, &b_dk2nu_tgtexit_tptype);
   fChain->SetBranchAddress("tgtexit.tgen", &tgtexit_tgen, &b_dk2nu_tgtexit_tgen);
   fChain->SetBranchAddress("traj", &traj_, &b_dk2nu_traj_);
   fChain->SetBranchAddress("traj.trkx", traj_trkx, &b_traj_trkx);
   fChain->SetBranchAddress("traj.trky", traj_trky, &b_traj_trky);
   fChain->SetBranchAddress("traj.trkz", traj_trkz, &b_traj_trkz);
   fChain->SetBranchAddress("traj.trkpx", traj_trkpx, &b_traj_trkpx);
   fChain->SetBranchAddress("traj.trkpy", traj_trkpy, &b_traj_trkpy);
   fChain->SetBranchAddress("traj.trkpz", traj_trkpz, &b_traj_trkpz);
   fChain->SetBranchAddress("flagbits", &flagbits, &b_dk2nu_flagbits);
   fChain->SetBranchAddress("vint", &vint, &b_dk2nu_vint);
   fChain->SetBranchAddress("vdbl", &vdbl, &b_dk2nu_vdbl);
   Notify();
}

Bool_t dk2nuTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void dk2nuTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t dk2nuTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef dk2nuTree_cxx
