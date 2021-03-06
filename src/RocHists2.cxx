#include <time.h>
#include "include/RocHists2.h"
#include "SFrameTools/include/EventCalc.h"
#include "include/ZprimeFullHadTools.h"
#include "NtupleWriter/include/JetProps.h"
#include "include/TopTagfunctions.h"
 #include "fastjet/PseudoJet.hh"
#include "fastjet/ClusterSequenceArea.hh"
 #include "fastjet/ClusterSequencePassiveArea.hh"
#include "NtupleWriter/include/JetPropsPseudo.h"
#include "fastjet/contrib/ClusteringVetoPlugin.hh"
#include "fastjet/contrib/HHTopTagger.hh"
#include <iostream>
#include "TH3.h"
using namespace std;
using namespace fastjet;
using namespace contrib;
RocHists2::RocHists2(const char* name) : BaseHists(name)
{
  // named default constructor
   
}

RocHists2::~RocHists2()
{
  // default destructor, does nothing
}

void RocHists2::Init()
{
  // book all histograms here

  double jetpt_bbins[] = {
    20, 30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 500, 600, 800, 1600
  };
  Book(TH1F("topgen","generated had tops",15,-0.5,14.5));
  Book(TH1F("MVA200","MVA values after selection",1600,-2,2));
  Book(TH1F("MVA400","MVA values after selection",1600,-2,2));
  Book(TH1F("MVA600","MVA values after selection",1600,-2,2));
  Book(TH1F("MVA800","MVA values after selection",1600,-2,2));
   Book(TH1F("MVA_pT","MVA values after selection",50,0,2000));
  Book(TH1F("MVA_2","MVA values after selection",50,0,2000));
  Book(TH1F("MVA500_2","MVA values after selection",1600,-2,2));
  Book(TH1F("MVA700_2","MVA values after selection",1600,-2,2));
  Book(TH1F("MVA700inf_2","MVA values after selection",1600,-2,2));
  Book(TH1F("MVAsingle_2","MVA values after selection",50,0,2000));
  Book(TH1F("MVA500single_2","MVA values after selection",50,0,2000));
  Book(TH1F("MVA700single_2","MVA values after selection",50,0,2000));
  Book(TH1F("MVA700infsingle_2","MVA values after selection",50,0,2000));
  Book(TH1F("MVA200btag","MVA values after selection",1600,-2,2));
  Book(TH1F("MVA400btag","MVA values after selection",1600,-2,2));
  Book(TH1F("MVA600btag","MVA values after selection",1600,-2,2));
  Book(TH1F("MVA800btag","MVA values after selection",1600,-2,2));
  Book(TH1F("SD_fine200","log(chi) (microjets) shower deconstruction PT>200",10000,-10,10));
  Book(TH1F("SD_fine400","log(chi) (microjets) shower deconstruction PT>400",10000,-10,10));
  Book(TH1F("SD_fine600","log(chi) (microjets) shower deconstruction PT>600",10000,-10,10));
  Book(TH1F("SD_fine800","log(chi) (microjets) shower deconstruction PT>800",10000,-10,10));
  Book(TH1F("SD_fine200mis","log(chi) (microjets) shower deconstruction PT>200",10000,-10,10));
  Book(TH1F("SD_fine400mis","log(chi) (microjets) shower deconstruction PT>400",10000,-10,10));
  Book(TH1F("SD_fine600mis","log(chi) (microjets) shower deconstruction PT>600",10000,-10,10));
  Book(TH1F("SD_fine800mis","log(chi) (microjets) shower deconstruction PT>800",10000,-10,10));
  Book(TH2F("SD_fine200btag","log(chi) (microjets) shower deconstruction PT>200",10000,-10,10,50,0,1));
  Book(TH2F("SD_fine400btag","log(chi) (microjets) shower deconstruction PT>400",10000,-10,10,50,0,1));
  Book(TH2F("SD_fine600btag","log(chi) (microjets) shower deconstruction PT>600",10000,-10,10,50,0,1));
  Book(TH2F("SD_fine800btag","log(chi) (microjets) shower deconstruction PT>800",10000,-10,10,50,0,1));
  Book(TH2F("SD_fine200nsub","log(chi) (microjets) shower deconstruction PT>200",10000,-10,10,50,0,1));
  Book(TH2F("SD_fine400nsub","log(chi) (microjets) shower deconstruction PT>400",10000,-10,10,50,0,1));
  Book(TH2F("SD_fine600nsub","log(chi) (microjets) shower deconstruction PT>600",10000,-10,10,50,0,1));
  Book(TH2F("SD_fine800nsub","log(chi) (microjets) shower deconstruction PT>800",10000,-10,10,50,0,1));
  Book(TH2F("SD_fine200mmin","log(chi) (microjets) shower deconstruction PT>200",10000,-10,10,50,0,150));
  Book(TH2F("SD_fine400mmin","log(chi) (microjets) shower deconstruction PT>400",10000,-10,10,50,0,150));
  Book(TH2F("SD_fine600mmin","log(chi) (microjets) shower deconstruction PT>600",10000,-10,10,50,0,150));
  Book(TH2F("SD_fine800mmin","log(chi) (microjets) shower deconstruction PT>800",10000,-10,10,50,0,150));
  Book(TH2F("SD_fine200bdt","log(chi) (microjets) shower deconstruction PT>200",1000,-10,10,49,-1,1));
  Book(TH2F("SD_fine400bdt","log(chi) (microjets) shower deconstruction PT>400",1000,-10,10,49,-1,1));
  Book(TH2F("SD_fine600bdt","log(chi) (microjets) shower deconstruction PT>600",1000,-10,10,49,-1,1));
  Book(TH2F("SD_fine800bdt","log(chi) (microjets) shower deconstruction PT>800",1000,-10,10,49,-1,1));
  Book(TH2F("SD_fine200misbtag","log(chi) (microjets) shower deconstruction PT>200",10000,-10,10,50,0,1));
  Book(TH2F("SD_fine400misbtag","log(chi) (microjets) shower deconstruction PT>400",10000,-10,10,50,0,1));
  Book(TH2F("SD_fine600misbtag","log(chi) (microjets) shower deconstruction PT>600",10000,-10,10,50,0,1));
  Book(TH2F("SD_fine800misbtag","log(chi) (microjets) shower deconstruction PT>800",10000,-10,10,50,0,1));
  Book(TH2F("SD_fine200misnsub","log(chi) (microjets) shower deconstruction PT>200",10000,-10,10,50,0,1));
  Book(TH2F("SD_fine400misnsub","log(chi) (microjets) shower deconstruction PT>400",10000,-10,10,50,0,1));
  Book(TH2F("SD_fine600misnsub","log(chi) (microjets) shower deconstruction PT>600",10000,-10,10,50,0,1));
  Book(TH2F("SD_fine800misnsub","log(chi) (microjets) shower deconstruction PT>800",10000,-10,10,50,0,1));
  Book(TH2F("SD_fine200mismmin","log(chi) (microjets) shower deconstruction PT>200",10000,-10,10,50,0,150));
  Book(TH2F("SD_fine400mismmin","log(chi) (microjets) shower deconstruction PT>400",10000,-10,10,50,0,150));
  Book(TH2F("SD_fine600mismmin","log(chi) (microjets) shower deconstruction PT>600",10000,-10,10,50,0,150));
  Book(TH2F("SD_fine800mismmin","log(chi) (microjets) shower deconstruction PT>800",10000,-10,10,50,0,150));
  Book(TH2F("SD_fine200misbdt","log(chi) (microjets) shower deconstruction PT>200",1000,-10,10,49,-1,1));
  Book(TH2F("SD_fine400misbdt","log(chi) (microjets) shower deconstruction PT>400",1000,-10,10,49,-1,1));
  Book(TH2F("SD_fine600misbdt","log(chi) (microjets) shower deconstruction PT>600",1000,-10,10,49,-1,1));
  Book(TH2F("SD_fine800misbdt","log(chi) (microjets) shower deconstruction PT>800",1000,-10,10,49,-1,1));
  Book( TH1F( "pT_s1"," p_{T} topjets (selection)",75,0,3000));
  Book( TH1F( "pT_s1_all"," p_{T} topjets (selection)",75,0,3000));
  Book( TH1F( "pT_s1_mis"," p_{T} topjets (selection)",75,0,3000));
  Book( TH1F( "pT_s1400"," p_{T} topjets (selection)",75,0,3000));
  Book( TH1F( "pT_s1_cms_tagged400"," p_{T} topjets (cms tagged)",75,0,3000));
  Book( TH1F( "pT_s1_cms_nsub_tagged"," p_{T}  nsubjettiness (cms tagged)",75,0,3000));
  Book( TH1F( "pT_s1_tobi_tagged"," p_{T} topjets (tobi tagged)",75,0,3000));
  Book( TH1F( "pT_s1_tobi2_tagged"," p_{T} topjets (tobi tagged)",75,0,3000));
  Book( TH1F( "pT_s1_tobi3_tagged"," p_{T} topjets (tobi tagged)",75,0,3000));
  Book( TH1F( "pT_s1_tobi4_tagged"," p_{T} topjets sd mass (tobi tagged)",75,0,3000));
  Book( TH1F( "pT_s1_tobi5_tagged"," p_{T} topjets nsubjettiness (tobi tagged)",75,0,3000));
  Book( TH1F( "pT_s1_tobi6_tagged"," p_{T} topjets w mass (tobi tagged)",75,0,3000));
   Book( TH1F( "pT_s1_varR_tagged"," p_{T} topjets w mass (tobi tagged)",75,0,3000));
  Book( TH1F( "pT_s1_mis400"," p_{T} topjets (selection)",75,0,3000));
  Book( TH1F( "pT_s1_cms_tagged_mis400"," p_{T} topjets (cms tagged)",75,0,3000));
  Book( TH1F( "pT_s1600"," p_{T} topjets (selection)",75,0,3000));
  Book( TH1F( "pT_s1_cms_tagged600"," p_{T} topjets (cms tagged)",75,0,3000));
  Book( TH1F( "pT_s1_mis600"," p_{T} topjets (selection)",75,0,3000));
  Book( TH1F( "pT_s1_cms_tagged_mis600"," p_{T} topjets (cms tagged)",75,0,3000));
  Book( TH1F( "pT_s1800"," p_{T} topjets (selection)",75,0,3000));
  Book( TH1F( "pT_s1_cms_tagged800"," p_{T} topjets (cms tagged)",75,0,3000));
  Book( TH1F( "pT_s1_mis800"," p_{T} topjets (selection)",75,0,3000));
  Book( TH1F( "pT_s1_cms_tagged_mis800"," p_{T} topjets (cms tagged)",75,0,3000));
  Book( TH1F( "pT_s1hep"," p_{T} topjets (selection)",75,0,3000));
  Book( TH1F( "pT_s1_mishep"," p_{T} topjets (selection)",75,0,3000));
  Book( TH1F( "pT_s1400hep"," p_{T} topjets (selection)",75,0,3000));
  Book( TH1F( "pT_s1_cms_tagged400hep"," p_{T} topjets (cms tagged)",75,0,3000));
  Book( TH1F( "pT_s1_mis400hep"," p_{T} topjets (selection)",75,0,3000));
  Book( TH1F( "pT_s1_cms_tagged_mis400hep"," p_{T} topjets (cms tagged)",75,0,3000));
  Book( TH1F( "pT_s1600hep"," p_{T} topjets (selection)",75,0,3000));
  Book( TH1F( "pT_s1_cms_tagged600hep"," p_{T} topjets (cms tagged)",75,0,3000));
  Book( TH1F( "pT_s1_mis600hep"," p_{T} topjets (selection)",75,0,3000));
  Book( TH1F( "pT_s1_cms_tagged_mis600hep"," p_{T} topjets (cms tagged)",75,0,3000));
  Book( TH1F( "pT_s1800hep"," p_{T} topjets (selection)",75,0,3000));
  Book( TH1F( "pT_s1_cms_tagged800hep"," p_{T} topjets (cms tagged)",75,0,3000));
  Book( TH1F( "pT_s1_mis800hep"," p_{T} topjets (selection)",75,0,3000));
  Book( TH1F( "pT_s1_cms_tagged_mis800hep"," p_{T} topjets (cms tagged)",75,0,3000));
  Book( TH1F( "N_topjets", ";N^{jets};Events", 20, 0, 20 ) );
  Book( TH1F( "N_mu", ";N^{muons};Events", 5, 0, 5 ) );
  Book( TH1F( "N_pv", ";N^{PV};Events", 50, 0, 50 ) );
  Book( TH1F( "N_events_perLumiBin", ";N^{evt};Events", 24, 0, 24 ) );
  Book( TH1F( "N_pv_perLumiBin", ";N^{PV};Events", 24, 0, 24 ) );
double PT_bins[] = {0,40,80,120,160,200,240,280,320,360,400,500,600,1000};
  Book( TH1D( "Toppt_all", ";Pt top-jet (GeV);Events", sizeof(PT_bins)/sizeof(double)-1,PT_bins));
  Book( TH1D( "Toppt_tagged", ";Pt top-jet (GeV);Events", sizeof(PT_bins)/sizeof(double)-1,PT_bins));
  Book( TH1D( "Npv200_all", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv200_htt_tagged", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv200_httnsub_tagged", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv200_httcsv_tagged", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv200_httnsubcsv_tagged", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv300_all", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv300_htt_tagged", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv300_httnsub_tagged", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv300_httcsv_tagged", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv300_httnsubcsv_tagged", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv400_all", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv400_htt_tagged", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv400_httnsub_tagged", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv400_httcsv_tagged", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv400_httnsubcsv_tagged", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv500_all", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv500_htt_tagged", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv500_httnsub_tagged", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv500_httcsv_tagged", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv500_httnsubcsv_tagged", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv600_all", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv600_htt_tagged", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv600_httnsub_tagged", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv600_httcsv_tagged", ";Pileup;Events", 50, 0, 50));
  Book( TH1D( "Npv600_httnsubcsv_tagged", ";Pileup;Events", 50, 0, 50));
  
  Book( TH1D( "Nsub", ";#tau_{3}/#tau_{2};Events", 100, 0., 1.));
  Book( TH1D( "Nsub_tagged", ";#tau_{3}/#tau_{2};Events", 100, 0., 1.));
  
  Book( TH1D( "Jetmass", ";Jet mass (GeV/c^{2});Events", 100, 0., 400.));
  Book( TH1D( "JetmassW", ";Jet mass (GeV/c^{2});Events", 100, 0., 400.));
  Book( TH1D( "Jetmass_m", ";Jet mass (GeV/c^{2});Events", 100, 0., 400.));
  Book( TH1D( "JetmassCA15", ";Jet mass (GeV/c^{2});Events", 100, 0., 400.));
  Book( TH1D( "JetmassCA15_m", ";Jet mass (GeV/c^{2});Events", 100, 0., 400.));
  Book( TH1D( "Jetmass_tagged", ";Jet mass (GeV/c^{2});Events", 100, 0., 400.));
  Book( TH1D( "Jetmass_taggedW", ";Jet mass (GeV/c^{2});Events", 100, 0., 400.));
  Book( TH1D( "weight", ";weight;Events", 400, 0., 1000.));
  
  //double roc_ptbins[] = {150,200,400,600,800,1000,10000};
  double roc_ptbins[] = {200,400,600,800,1000,10000};
//   Book( TH1D( "eff_all", ";Pt top-gen (GeV);Events", sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
// //   Book( TH1D( "eff_tagged", ";Pt top-gen (GeV);Events", sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
// //   Book( TH1D( "eff_tagged_nomass", ";Pt top-gen (GeV);Events", sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
//   
//   Book( TH1D( "eff_tagged_mjet", ";Pt top-gen (GeV);Events", sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
//   Book( TH1D( "eff_tagged_mgroom", ";Pt top-gen (GeV);Events", sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
// //   Book( TH1D( "eff_tagged_cvsl", ";Pt top-gen (GeV);Events", sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
// //   Book( TH1D( "eff_tagged_cvsm", ";Pt top-gen (GeV);Events", sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
//   
//   Book( TH1D( "mistag_all", ";Pt parton (GeV);Events", sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
//   Book( TH1D( "mistag_tagged", ";Pt parton (GeV);Events", sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
//   Book( TH1D( "mistag_tagged_nomass", ";Pt parton (GeV);Events", sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
//   
//   Book( TH1D( "mistag_tagged_mjet", ";Pt parton (GeV);Events", sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
//   Book( TH1D( "mistag_tagged_mgroom", ";Pt parton (GeV);Events", sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
//   Book( TH1D( "mistag_tagged_cvsl", ";Pt parton (GeV);Events", sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
//   Book( TH1D( "mistag_tagged_cvsm", ";Pt parton (GeV);Events", sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  
  Book( TH2D( "eff_mwl_tagged", ";lower mass window;Pt top-gen (GeV)",100,0.5,1.0,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "eff_mwu_tagged", ";upper mass window;Pt top-gen (GeV)",100,1.0,1.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "eff_rsa_tagged", ";R soft in condition A;Pt top-gen (GeV)",100,0.0,0.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "eff_rsb_tagged", ";R soft in condition B;Pt top-gen (GeV)",100,0.0,0.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "eff_tml_tagged", ";Lower top mass window;Pt top-gen (GeV)",100,90.0,160.0,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "eff_tmu_tagged", ";Upper top mass window;Pt top-gen (GeV)",100,190.0,260.0,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  
  Book( TH2D( "eff_mwl_tagged_cvsl", ";lower mass window;Pt top-gen (GeV)",100,0.5,1.0,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "eff_mwu_tagged_cvsl", ";upper mass window;Pt top-gen (GeV)",100,1.0,1.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "eff_rsa_tagged_cvsl", ";R soft in condition A;Pt top-gen (GeV)",100,0.0,0.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "eff_rsb_tagged_cvsl", ";R soft in condition B;Pt top-gen (GeV)",100,0.0,0.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "eff_tml_tagged_cvsl", ";Lower top mass window;Pt top-gen (GeV)",100,90.0,160.0,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "eff_tmu_tagged_cvsl", ";Upper top mass window;Pt top-gen (GeV)",100,190.0,260.0,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  
  Book( TH2D( "eff_mwl_tagged_cvsm", ";lower mass window;Pt top-gen (GeV)",100,0.5,1.0,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "eff_mwu_tagged_cvsm", ";upper mass window;Pt top-gen (GeV)",100,1.0,1.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "eff_rsa_tagged_cvsm", ";R soft in condition A;Pt top-gen (GeV)",100,0.0,0.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "eff_rsb_tagged_cvsm", ";R soft in condition B;Pt top-gen (GeV)",100,0.0,0.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "eff_tml_tagged_cvsm", ";Lower top mass window;Pt top-gen (GeV)",100,90.0,160.0,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "eff_tmu_tagged_cvsm", ";Upper top mass window;Pt top-gen (GeV)",100,190.0,260.0,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  
  
  
  Book( TH2D( "mistag_mwl_tagged", ";lower mass window;Pt parton (GeV)",100,0.5,1.0,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "mistag_mwu_tagged", ";upper mass window;Pt parton (GeV)",100,1.0,1.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "mistag_rsa_tagged", ";R soft in condition A;Pt parton (GeV)",100,0.0,0.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "mistag_rsb_tagged", ";R soft in condition B;Pt parton (GeV)",100,0.0,0.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "mistag_tml_tagged", ";Lower top mass window;Pt top-gen (GeV)",100,90.0,160.0,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "mistag_tmu_tagged", ";Upper top mass window;Pt top-gen (GeV)",100,190.0,260.0,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  
  Book( TH2D( "mistag_mwl_tagged_cvsl", ";lower mass window;Pt parton (GeV)",100,0.5,1.0,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "mistag_mwu_tagged_cvsl", ";upper mass window;Pt parton (GeV)",100,1.0,1.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "mistag_rsa_tagged_cvsl", ";R soft in condition A;Pt parton (GeV)",100,0.0,0.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "mistag_rsb_tagged_cvsl", ";R soft in condition B;Pt parton (GeV)",100,0.0,0.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "mistag_tml_tagged_cvsl", ";Lower top mass window;Pt top-gen (GeV)",100,90.0,160.0,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "mistag_tmu_tagged_cvsl", ";Upper top mass window;Pt top-gen (GeV)",100,190.0,260.0,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  
  Book( TH2D( "mistag_mwl_tagged_cvsm", ";lower mass window;Pt parton (GeV)",100,0.5,1.0,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "mistag_mwu_tagged_cvsm", ";upper mass window;Pt parton (GeV)",100,1.0,1.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "mistag_rsa_tagged_cvsm", ";R soft in condition A;Pt parton (GeV)",100,0.0,0.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "mistag_rsb_tagged_cvsm", ";R soft in condition B;Pt parton (GeV)",100,0.0,0.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "mistag_tml_tagged_cvsm", ";Lower top mass window;Pt top-gen (GeV)",100,90.0,160.0,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  Book( TH2D( "mistag_tmu_tagged_cvsm", ";Upper top mass window;Pt top-gen (GeV)",100,190.0,260.0,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));

  //////////////////////////////ROC
//   Book( TH3D( "eff_roc_tagged", ";w;RsoftB;Pt top-gen (GeV)",100,0.0,0.5,100,0.0,0.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins)); 
//   Book( TH3D( "eff_roc_tagged_cvsl", ";w;RsoftB;Pt top-gen (GeV)",100,0.0,0.5,100,0.0,0.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
//   Book( TH3D( "eff_roc_tagged_cvsm", ";w;RsoftB;Pt top-gen (GeV)",100,0.0,0.5,100,0.0,0.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
//   Book( TH3D( "mistag_roc_tagged", ";w;RsoftB;Pt parton (GeV)",100,0.0,0.5,100,0.0,0.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins)); 
//   Book( TH3D( "mistag_roc_tagged_cvsl", ";w;RsoftB;Pt parton (GeV)",100,0.0,0.5,100,0.0,0.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
//   Book( TH3D( "mistag_roc_tagged_cvsm", ";w;RsoftB;Pt parton (GeV)",100,0.0,0.5,100,0.0,0.5,sizeof(roc_ptbins)/sizeof(double)-1,roc_ptbins));
  int nsteps=50;
  double wmin=0.0;
  double wmax=0.5;
  double nsubmin=0.0;
  double nsubmax=1.0;
  double csvmin=0.0;
  double csvmax=1.0;
//   Book( TH3D( "eff_roc_tagged", ";w;RsoftB;Pt top-gen (GeV)",nsteps,0.0,0.5,nsteps,0.0,0.5,50,0.0,10000.0)); 
//   Book( TH3D( "eff_roc_tagged_cvsl", ";w;RsoftB;Pt top-gen (GeV)",nsteps,0.0,0.5,nsteps,0.0,0.5,50,0.0,10000.0));
//   Book( TH3D( "eff_roc_tagged_cvsm", ";w;RsoftB;Pt top-gen (GeV)",nsteps,0.0,0.5,nsteps,0.0,0.5,50,0.0,10000.0));
//   Book( TH3D( "mistag_roc_tagged", ";w;RsoftB;Pt parton (GeV)",nsteps,0.0,0.5,nsteps,0.0,0.5,50,0.0,10000.0)); 
//   Book( TH3D( "mistag_roc_tagged_cvsl", ";w;RsoftB;Pt parton (GeV)",nsteps,0.0,0.5,nsteps,0.0,0.5,50,0.0,10000.0));
//   Book( TH3D( "mistag_roc_tagged_cvsm", ";w;RsoftB;Pt parton (GeV)",nsteps,0.0,0.5,nsteps,0.0,0.5,50,0.0,10000.0)); 
  
//   Book( TH3D( "eff_roc_tagged", ";w;tml;Pt top-gen (GeV)",nsteps,0.0,0.5,nsteps,90.0,160.0,50,0.0,10000.0)); 
//   Book( TH3D( "eff_roc_tagged_cvsl", ";w;tml;Pt top-gen (GeV)",nsteps,0.0,0.5,nsteps,90.0,160.0,50,0.0,10000.0));
//   Book( TH3D( "eff_roc_tagged_cvsm", ";w;tml;Pt top-gen (GeV)",nsteps,0.0,0.5,nsteps,90.0,160.0,50,0.0,10000.0));
//   Book( TH3D( "mistag_roc_tagged", ";w;tml;Pt parton (GeV)",nsteps,0.0,0.5,nsteps,90.0,160.0,50,0.0,10000.0)); 
//   Book( TH3D( "mistag_roc_tagged_cvsl", ";w;tml;Pt parton (GeV)",nsteps,0.0,0.5,nsteps,90.0,160.0,50,0.0,10000.0));
//   Book( TH3D( "mistag_roc_tagged_cvsm", ";w;tml;Pt parton (GeV)",nsteps,0.0,0.5,nsteps,90.0,160.0,50,0.0,10000.0)); 
  
//   Book( TH3D( "eff_roc_tagged", ";w;nsub;Pt top-gen (GeV)",nsteps,0.0,0.5,nsteps,0.5,1.0,50,0.0,10000.0)); 
//   Book( TH3D( "eff_roc_tagged_cvsl", ";w;nsub;Pt top-gen (GeV)",nsteps,0.0,0.5,nsteps,0.5,1.0,50,0.0,10000.0));
//   Book( TH3D( "eff_roc_tagged_cvsm", ";w;nsub;Pt top-gen (GeV)",nsteps,0.0,0.5,nsteps,0.5,1.0,50,0.0,10000.0));
//   Book( TH3D( "mistag_roc_tagged", ";w;nsub;Pt parton (GeV)",nsteps,0.0,0.5,nsteps,0.5,1.0,50,0.0,10000.0)); 
//   Book( TH3D( "mistag_roc_tagged_cvsl", ";w;nsub;Pt parton (GeV)",nsteps,0.0,0.5,nsteps,0.5,1.0,50,0.0,10000.0));
//   Book( TH3D( "mistag_roc_tagged_cvsm", ";w;nsub;Pt parton (GeV)",nsteps,0.0,0.5,nsteps,0.5,1.0,50,0.0,10000.0)); 
  
  Book( TH3D( "eff_roc_tagged200", ";w;nsub;csv",nsteps,wmin,wmax,nsteps,nsubmin,nsubmax,nsteps,csvmin,csvmax)); 
  Book( TH3D( "mistag_roc_tagged200", ";w;nsub;csv",nsteps,wmin,wmax,nsteps,nsubmin,nsubmax,nsteps,csvmin,csvmax));
  Book( TH3D( "eff_roc_tagged400", ";w;nsub;csv",nsteps,wmin,wmax,nsteps,nsubmin,nsubmax,nsteps,csvmin,csvmax)); 
  Book( TH3D( "mistag_roc_tagged400", ";w;nsub;csv",nsteps,wmin,wmax,nsteps,nsubmin,nsubmax,nsteps,csvmin,csvmax));
  Book( TH3D( "eff_roc_tagged600", ";w;nsub;csv",nsteps,wmin,wmax,nsteps,nsubmin,nsubmax,nsteps,csvmin,csvmax)); 
  Book( TH3D( "mistag_roc_tagged600", ";w;nsub;csv",nsteps,wmin,wmax,nsteps,nsubmin,nsubmax,nsteps,csvmin,csvmax));
  Book( TH3D( "eff_roc_tagged800", ";w;nsub;csv",nsteps,wmin,wmax,nsteps,nsubmin,nsubmax,nsteps,csvmin,csvmax)); 
  Book( TH3D( "mistag_roc_tagged800", ";w;nsub;csv",nsteps,wmin,wmax,nsteps,nsubmin,nsubmax,nsteps,csvmin,csvmax));

  
  Book( TH1D( "eff_all", ";Pt top-gen (GeV);Events", 50,0.0,10000.0));
  Book( TH1D( "eff_tagged", ";Pt top-gen (GeV);Events", 50,0.0,10000.0));
  Book( TH1D( "eff_tagged_cvsl", ";Pt top-gen (GeV);Events", 50,0.0,10000.0));
  Book( TH1D( "eff_tagged_cvsm", ";Pt top-gen (GeV);Events", 50,0.0,10000.0));
  
  Book( TH1D( "mistag_all", ";Pt parton (GeV);Events", 50,0.0,10000.0));
  Book( TH1D( "mistag_tagged", ";Pt parton (GeV);Events", 50,0.0,10000.0));
  Book( TH1D( "mistag_tagged_cvsl", ";Pt parton (GeV);Events", 50,0.0,10000.0));
  Book( TH1D( "mistag_tagged_cvsm", ";Pt parton (GeV);Events", 50,0.0,10000.0));
  
  Book( TH1F( "TopPt_Eff",";p_{T} [GeV];Events",100,0.0,2000.0));
  Book( TH1F( "TopPt_Mistag",";p_{T} [GeV];Events",100,0.0,2000.0));
  
  Book( TH1F( "TopPtWeightHisto","TopPtWeightHisto;Weight;Events",500,0.5,2));
  Book( TH1F( "TopPtFullWeightHisto","TopPtFullWeightHisto;Weight;Events",500,0.5,2));
  Book( TH2F( "TopWeightVsPtHisto","TopWeightVsPtHisto;Weight;pT(GeV)",500,0.5,2,100,0,1000));
  Book( TH2F( "TopWeightVsGenPtHisto","TopWeightVsGenPtHisto;Weight;pT(GeV)",500,0.5,2,100,0,1000));
  Book( TH2F( "TopWeightVsGenPtHisto2","TopWeightVsGenPtHisto2;Weight;pT(GeV)",500,0.5,2,100,0,1000));
  
  Book( TH1D( "MassTop", ";Top jet mass (GeV);Events", 50, 0, 500));
  Book( TH1D( "MassTopUnfiltered", ";Top jet mass (GeV);Events", 50, 0, 500));
  
  Book( TH2D("PtGenVsRecoEff","PtGenVsReco;pT gen;pT reco",100,0,1000,100,0,1000) );
  Book( TH2D("PtGenVsRecoMistag","PtGenVsReco;pT gen;pT reco",100,0,1000,100,0,1000) );

  //multi r
  Book( TH1F( "multiR_Rmin", "hep m_unfiltered", 21,-0.05,2.05 ) );
  Book( TH1F( "multiR_massRmin", "hep m_unfiltered", 25,0,400 ) );
  Book( TH1F( "multiR_ptRmin", "hep m_unfiltered", 25,0,1000 ) );
  Book( TH1F( "multiR_Rmin200", "multiR R_{min} pt>200", 21,-0.05,2.05 ) );
  Book( TH1F( "multiR_Rmin400", "multiR R_{min} pt>400 ", 21,-0.05,2.05 ) );
  Book( TH1F( "multiR_Rmin600", "multiR R_{min} pt>600 ", 21,-0.05,2.05 ) );
  Book( TH1F( "multiR_Rmin800", "multiR R_{min} pt>800 ", 21,-0.05,2.05 ) );
  Book( TH1F( "multiR_Rmin1000", "multiR R_{min} pt>1000 ", 21,-0.05,2.05 ) );

  //jwj
  Book(TH1F("Jetm00","jet multiplicity 01",50,0,10));
  Book(TH1F("Jetm01","jet multiplicity 01",50,0,10));
  Book(TH1F("Jetm02","jet multiplicity 02",50,0,10));
  Book(TH1F("Jetm03","jet multiplicity 03",50,0,10));
  Book(TH1F("Jetm04","jet multiplicity 04",50,0,10));
  Book(TH1F("Jetm00bkg","jet multiplicity 01",50,0,10));
  Book(TH1F("Jetm01bkg","jet multiplicity 01",50,0,10));
  Book(TH1F("Jetm02bkg","jet multiplicity 02",50,0,10));
  Book(TH1F("Jetm03bkg","jet multiplicity 03",50,0,10));
  Book(TH1F("Jetm04bkg","jet multiplicity 04",50,0,10));

  Book(TH1F("Jetm00_400","jet multiplicity 01",50,0,10));
  Book(TH1F("Jetm01_400","jet multiplicity 01",50,0,10));
  Book(TH1F("Jetm02_400","jet multiplicity 02",50,0,10));
  Book(TH1F("Jetm03_400","jet multiplicity 03",50,0,10));
  Book(TH1F("Jetm04_400","jet multiplicity 04",50,0,10));
  Book(TH1F("Jetm00bkg_400","jet multiplicity 01",50,0,10));
  Book(TH1F("Jetm01bkg_400","jet multiplicity 01",50,0,10));
  Book(TH1F("Jetm02bkg_400","jet multiplicity 02",50,0,10));
  Book(TH1F("Jetm03bkg_400","jet multiplicity 03",50,0,10));
  Book(TH1F("Jetm04bkg_400","jet multiplicity 04",50,0,10));


   Book(TH1F("Jetm00_600","jet multiplicity 01",50,0,10));
  Book(TH1F("Jetm01_600","jet multiplicity 01",50,0,10));
  Book(TH1F("Jetm02_600","jet multiplicity 02",50,0,10));
  Book(TH1F("Jetm03_600","jet multiplicity 03",50,0,10));
  Book(TH1F("Jetm04_600","jet multiplicity 04",50,0,10));
  Book(TH1F("Jetm00bkg_600","jet multiplicity 01",50,0,10));
  Book(TH1F("Jetm01bkg_600","jet multiplicity 01",50,0,10));
  Book(TH1F("Jetm02bkg_600","jet multiplicity 02",50,0,10));
  Book(TH1F("Jetm03bkg_600","jet multiplicity 03",50,0,10));
  Book(TH1F("Jetm04bkg_600","jet multiplicity 04",50,0,10));


 Book(TH1F("Jetm00_800","jet multiplicity 01",50,0,10));
  Book(TH1F("Jetm01_800","jet multiplicity 01",50,0,10));
  Book(TH1F("Jetm02_800","jet multiplicity 02",50,0,10));
  Book(TH1F("Jetm03_800","jet multiplicity 03",50,0,10));
  Book(TH1F("Jetm04_800","jet multiplicity 04",50,0,10));
  Book(TH1F("Jetm00bkg_800","jet multiplicity 01",50,0,10));
  Book(TH1F("Jetm01bkg_800","jet multiplicity 01",50,0,10));
  Book(TH1F("Jetm02bkg_800","jet multiplicity 02",50,0,10));
  Book(TH1F("Jetm03bkg_800","jet multiplicity 03",50,0,10));
  Book(TH1F("Jetm04bkg_800","jet multiplicity 04",50,0,10));



  //qjet
  Book(TH1D("Qvolatility_mmin","Q-jets volatilty",30,0,0.6));
  Book(TH1D("Qvolatility_mmin_bkg","Q-jets volatilty",30,0,0.6));

  Book(TH1D("Qvolatility_mass","Q-jets volatilty",30,0,0.6));
  Book(TH1D("Qvolatility_mass_bkg","Q-jets volatilty",30,0,0.6));

  Book(TH1D("Qvolatility_nsubjets","Q-jets volatilty",30,0,0.6));
  Book(TH1D("Qvolatility_nsubjets_bkg","Q-jets volatilty",30,0,0.6));

  Book(TH1D("Qvolatility_mmin_cms","Q-jets volatilty",30,0,0.6));
  Book(TH1D("Qvolatility_mmin_cms_bkg","Q-jets volatilty",30,0,0.6));

  Book(TH1D("Qvolatility_mass_cms","Q-jets volatilty",30,0,0.6));
  Book(TH1D("Qvolatility_mass_cms_bkg","Q-jets volatilty",30,0,0.6));

  Book(TH1D("Qvolatility_nsubjets_cms","Q-jets volatilty",30,0,0.6));
  Book(TH1D("Qvolatility_nsubjets_cms_bkg","Q-jets volatilty",30,0,0.6));

  
  Book(TH1D("Qvolatility_nsubjettiness1_cms","Q-jets volatilty",30,0,0.6));
  Book(TH1D("Qvolatility_nsubjettiness1_cms_bkg","Q-jets volatilty",30,0,0.6));
  Book(TH1D("Qvolatility_nsubjettiness2_cms","Q-jets volatilty",30,0,0.6));
  Book(TH1D("Qvolatility_nsubjettiness2_cms_bkg","Q-jets volatilty",30,0,0.6));
  Book(TH1D("Qvolatility_nsubjettiness3_cms","Q-jets volatilty",30,0,0.6));
  Book(TH1D("Qvolatility_nsubjettiness3_cms_bkg","Q-jets volatilty",30,0,0.6));
  Book(TH1D("Qvolatility_nsubjettiness1","Q-jets volatilty",30,0,0.6));
  Book(TH1D("Qvolatility_nsubjettiness1_bkg","Q-jets volatilty",30,0,0.6));
  Book(TH1D("Qvolatility_nsubjettiness2","Q-jets volatilty",30,0,0.6));
  Book(TH1D("Qvolatility_nsubjettiness2_bkg","Q-jets volatilty",30,0,0.6));
  Book(TH1D("Qvolatility_nsubjettiness3","Q-jets volatilty",30,0,0.6));
  Book(TH1D("Qvolatility_nsubjettiness3_bkg","Q-jets volatilty",30,0,0.6));
  
  //ecf
  Book(TH1F("ecf_c3","ECF C3 pt>500GeV",20,0,1.0));
  Book(TH1F("ecf_c3_bkg","ECF C3 pt>500GeV",20,0,1.0));
  Book(TH1F("ecf_d3","ECF D3 pt>500GeV",20,0,20));
  Book(TH1F("ecf_d3_bkg","ECF D3 pt>500GeV",20,0,20));
  Book(TH1F("ecf_c3_mass","ECF C3 pt>500GeV",20,0,1.0));
  Book(TH1F("ecf_c3_mass_bkg","ECF C3 pt>500GeV",20,0,1.0));
  Book(TH1F("ecf_d3_mass","ECF D3 pt>500GeV",20,0,20));
  Book(TH1F("ecf_d3_mass_bkg","ECF D3 pt>500GeV",20,0,20));


  //Variable R
  Book( TH1D( "Jetmass2", ";Top jet mass (GeV);Events", 100, 0, 500));
   Book( TH1D( "Subjetmass2", ";subjet mass (GeV);Events", 50, 0, 500));
  Book( TH1D( "mmin2", ";Top jet mass (GeV);Events", 50, 0, 200));
   Book( TH1D( "mmin3", ";Top jet mass (GeV);Events", 50, 0, 200));
   Book(TH1D("rho","rho",60,-10,200));
   Book(TH1D("CMS_pt","cms",50,0,2000));
   Book(TH1D("TL_pt","tl",50,0,2000));
   Book(TH2F("pT_njets","njets vs pt",1000,0,2000,10,0,10));
   Book(TH2F("VariableR","VariableR",1000,0,2000,20,0,40));
   Book(TH2F("VariableR_area","VariableR area",1000,0,2000,20,0,2));
   Book(TH2F("Area2d","Area vs pt",1000,0,2000,100,0,20));
   Book(TH1D("mmin","mmin",50,0,100));
   Book(TH1D("massjump_mmin200","massjump mmin",50,0,100));
   Book(TH1D("massjump_mmin400","massjump mmin",50,0,100));
   Book(TH1D("massjump_mmin600","massjump mmin",50,0,100));
   Book(TH1D("massjump_mmin800","massjump mmin",50,0,100));
   Book(TH1D("massjump_mmin1000","massjump mmin",50,0,100));
   Book(TH1D("mjet","mjet",100,0,300));
   Book(TH1D("mjet400","mjet",100,0,300));
   Book(TH1D("mjet200","mjet",100,0,300));
   Book(TH1D("mjet600","mjet",100,0,300));
   Book(TH1D("mjet800","mjet",100,0,300));
   Book(TH1D("mjet1000","mjet",100,0,300));

   Book(TH1D("mjet_1","mjet",100,0,300));
   Book(TH1D("mjet400_1","mjet",100,0,300));
   Book(TH1D("mjet200_1","mjet",100,0,300));
   Book(TH1D("mjet600_1","mjet",100,0,300));
   Book(TH1D("mjet800_1","mjet",100,0,300));
   Book(TH1D("mjet1000_1","mjet",100,0,300));

   Book(TH1D("mjet_2","mjet",100,0,300));
   Book(TH1D("mjet400_2","mjet",100,0,300));
   Book(TH1D("mjet200_2","mjet",100,0,300));
   Book(TH1D("mjet600_2","mjet",100,0,300));
   Book(TH1D("mjet800_2","mjet",100,0,300));
   Book(TH1D("mjet1000_2","mjet",100,0,300));

   Book(TH1D("mjet_before","mjet",100,0,300));
   Book(TH1D("mjet500_before","mjet",100,0,300));
   Book(TH1D("mjet200_before","mjet",100,0,300));
   Book(TH1D("mjet600_before","mjet",100,0,300));
   Book(TH1D("mjet800_before","mjet",100,0,300));
   Book(TH1D("mjet1000_before","mjet",100,0,300));

   Book(TH1D("mjet_massjump200","mjet massjump",100,0,300));
   Book(TH1D("mjet_massjump400","mjet massjump",100,0,300));
   Book(TH1D("mjet_massjump600","mjet massjump",100,0,300));
   Book(TH1D("mjet_massjump800","mjet massjump",100,0,300));
   Book(TH1D("mjet_massjump1000","mjet massjump",100,0,300));
   Book(TH1D("nsubjets","nsubjets",5,-0.5,4.5));
   Book(TH1D("nsubjets_massjump","nsubjets massjump",20,-0.5,19.5));
   Book(TH1D("nsubjets_massjump200","nsubjets massjump",20,-0.5,19.5));
   Book(TH1D("nsubjets_massjump400","nsubjets massjump",20,-0.5,19.5));
   Book(TH1D("nsubjets_massjump600","nsubjets massjump",20,-0.5,19.5));
   Book(TH1D("nsubjets_massjump800","nsubjets massjump",20,-0.5,19.5));
    Book(TH1D("nsubjets_massjump1000","nsubjets massjump",20,-0.5,19.5));
   Book(TH1D("NJets","njets",20,-0.5,19.5));
   Book(TH1D("NJets-1","njets radiation",20,-0.5,19.5));
   Book(TH1D("NJets-2","njets beam jets",20,-0.5,19.5));
   Book(TH1D("NJetstop","NJets top",20,-0.5,19.5));
   Book(TH1D("NJets200","njets",20,-0.5,19.5));
   Book(TH1D("NJetstop200","NJets top",20,-0.5,19.5));
   Book(TH1D("NJets400","njets",20,-0.5,19.5));
   Book(TH1D("NJetstop400","NJets top",20,-0.5,19.5));
   Book(TH1D("NJets600","njets",20,-0.5,19.5));
   Book(TH1D("NJetstop600","NJets top",20,-0.5,19.5));
   Book(TH1F("pT_beam"," p_{T} beam jets",50,0,2000));
   Book(TH1F("pT_radiation"," p_{T} radiation jets",50,0,2000));
   Book(TH1F("pT_fatjets"," p_{T} fatjets",50,0,2000));
 
   for(int t=0;t<5;t++) {
     for(int L=0;L<6;L++){
       TString hname1 = TString::Format("distance_subjet%d_decaypro%d", t,L);
       TString hname2 = TString::Format("distance between subjet%d and decay product %d", t,L);
       Book(TH1F(hname1,hname2,20,0,7));
     }
   }
   


   for(int L=0;L<6;L++) {
     TString effname = TString::Format("pT_decay%d", L);
      TString effname1 = TString::Format("pT_decay%d_akt", L);
      Book(TH1F(effname,"pT decay products",100,0,2000));
     Book(TH1F(effname1,"pT decay products",100,0,2000));
   
   }
   Book(TH1D("pT_gen_match_skt","pT_gen_match_skt",100,0,2000));
   Book(TH1D("pT_gen_match_skt_collimated","pT_gen_match_skt_collimated",100,0,2000));
   Book(TH1D("pT_gen_match_skt_collimated_01","pT_gen_match_skt_collimated",100,0,2000));
   Book(TH1D("pT_gen_match_skt_collimated_02","pT_gen_match_skt_collimated",100,0,2000));
   Book(TH1D("pT_gen_match_skt_collimated_03","pT_gen_match_skt_collimated",100,0,2000));
   Book(TH1D("pT_gen_match_skt_collimated_04","pT_gen_match_skt_collimated",100,0,2000));
   Book(TH1D("pT_gen_match_skt_collimated_05","pT_gen_match_skt_collimated",100,0,2000));
   Book(TH1D("pT_gen_match_skt_collimated_06","pT_gen_match_skt_collimated",100,0,2000));
   Book(TH1D("pT_gen_match_skt_collimated_07","pT_gen_match_skt_collimated",100,0,2000));
   Book(TH1D("pT_gen","pT_gen",100,0,2000));
   Book(TH1D("Area","area",100,0,20));
   Book(TH1D("Area200","area",100,0,20));
   Book(TH1D("Area400","area",100,0,20));
   Book(TH1D("Area600","area",100,0,20));
   Book(TH1D("Area800","area",100,0,20));
   Book(TH1D("pT_jets","pT varRjet",100,0,2000));
   Book(TH1D("pT_topjets","pT varRjet",100,0,2000));
   Book(TH1D("Njets_var","pt vs njet",200,0,2000));
   Book(TH1D("Njets_norm","pt vs njet",200,0,2000));
   Book(TH1D("tau1","tau1",100,0,1.0));
   Book(TH1D("tau1_200","tau1 pt>200GeV",100,0,1.0));
   Book(TH1D("tau1_500","tau1 pt>500GeV",100,0,1.0));
   Book(TH1D("tau1_600","tau1 pt>600GeV",100,0,1.0));
   Book(TH1D("tau1_800","tau1 pt>800GeV",100,0,1.0));
   Book(TH1D("tau1_1000","tau1 pt>1000GeV",100,0,1.0));
   Book(TH1D("tau2","tau2",100,0,1.0));
   Book(TH1D("tau2_200","tau2 pt>200GeV",100,0,1.0));
   Book(TH1D("tau2_500","tau2 pt>500GeV",100,0,1.0));
   Book(TH1D("tau2_600","tau2 pt>600GeV",100,0,1.0));
   Book(TH1D("tau2_800","tau2 pt>800GeV",100,0,1.0));
   Book(TH1D("tau2_1000","tau1 pt>1000GeV",100,0,1.0));
   Book(TH1D("tau3","tau3",100,0,1.0));
   Book(TH1D("tau3_200","tau3 pt>200GeV",100,0,1.0));
   Book(TH1D("tau3_500","tau3 pt>500GeV",100,0,1.0));
   Book(TH1D("tau3_600","tau3 pt>600GeV",100,0,1.0));
   Book(TH1D("tau3_800","tau3 pt>800GeV",100,0,1.0));
   Book(TH1D("tau3_1000","tau3 pt>1000GeV",100,0,1.0));
   Book(TH1D("tau4","tau4",100,0,1.0));
   Book(TH1D("tau4_200","tau4 pt>200GeV",100,0,1.0));
   Book(TH1D("tau4_500","tau4 pt>500GeV",100,0,1.0));
   Book(TH1D("tau4_600","tau4 pt>600GeV",100,0,1.0));
   Book(TH1D("tau4_800","tau4 pt>800GeV",100,0,1.0));
   Book(TH1D("tau4_1000","tau2tau1 pt>1000GeV",100,0,1.0));
   Book(TH1D("tau2tau1","tau2tau1",100,0,1.0));
   Book(TH1D("tau2tau1_200","tau2tau1 pt>200GeV",100,0,1.0));
   Book(TH1D("tau2tau1_500","tau2tau1 pt>500GeV",100,0,1.0));
   Book(TH1D("tau2tau1_600","tau2tau1 pt>600GeV",100,0,1.0));
   Book(TH1D("tau2tau1_800","tau2tau1 pt>800GeV",100,0,1.0));
   Book(TH1D("tau2tau1_1000","tau2tau1 pt>1000GeV",100,0,1.0));
   Book(TH1D("tau3tau2","tau2tau1",100,0,1.0));
   Book(TH1D("tau3tau1","tau2tau1",100,0,1.0));
   Book(TH1D("tau3tau2_200","tau3tau2 pt>200GeV",100,0,1.0));
   Book(TH1D("tau3tau2_400","tau3tau2 pt>500GeV",100,0,1.0));
   Book(TH1D("tau3tau2_600","tau3tau2 pt>600GeV",100,0,1.0));
   Book(TH1D("tau3tau2_800","tau3tau2 pt>800GeV",100,0,1.0));
   Book(TH1D("tau3tau2_1000","tau3tau2 pt>1000GeV",100,0,1.0));
   Book(TH1D("tau1_massjump","tau1",100,0,1.0));
   Book(TH1D("tau1_200_massjump","tau1 pt>200GeV massjump",100,0,1.0));
   Book(TH1D("tau1_500_massjump","tau1 pt>500GeV massjump",100,0,1.0));
   Book(TH1D("tau1_600_massjump","tau1 pt>600GeV massjump",100,0,1.0));
   Book(TH1D("tau1_800_massjump","tau1 pt>800GeV massjump",100,0,1.0));
   Book(TH1D("tau1_1000_massjump","tau1 pt>1000GeV massjump",100,0,1.0));
   Book(TH1D("tau2_massjump","tau2 massjump",100,0,1.0));
   Book(TH1D("tau2_200_massjump","tau2 pt>200GeV massjump",100,0,1.0));
   Book(TH1D("tau2_500_massjump","tau2 pt>500GeV massjump",100,0,1.0));
   Book(TH1D("tau2_600_massjump","tau2 pt>600GeV massjump",100,0,1.0));
   Book(TH1D("tau2_800_massjump","tau2 pt>800GeV massjump",100,0,1.0));
   Book(TH1D("tau2_1000_massjump","tau1 pt>1000GeV massjump",100,0,1.0));
   Book(TH1D("tau3_massjump","tau3 massjump",100,0,1.0));
   Book(TH1D("tau3_200_massjump","tau3 pt>200GeV massjump",100,0,1.0));
   Book(TH1D("tau3_500_massjump","tau3 pt>500GeV massjump",100,0,1.0));
   Book(TH1D("tau3_600_massjump","tau3 pt>600GeV massjump",100,0,1.0));
   Book(TH1D("tau3_800_massjump","tau3 pt>800GeV massjump",100,0,1.0));
   Book(TH1D("tau3_1000_massjump","tau3 pt>1000GeV massjump",100,0,1.0));
   Book(TH1D("tau4_massjump","tau4 massjump",100,0,1.0));
   Book(TH1D("tau4_200_massjump","tau4 pt>200GeV massjump",100,0,1.0));
   Book(TH1D("tau4_500_massjump","tau4 pt>500GeV massjump",100,0,1.0));
   Book(TH1D("tau4_600_massjump","tau4 pt>600GeV massjump",100,0,1.0));
   Book(TH1D("tau4_800_massjump","tau4 pt>800GeV massjump",100,0,1.0));
   Book(TH1D("tau4_1000_massjump","tau2tau1 pt>1000GeV massjump",100,0,1.0));
   Book(TH1D("tau2tau1_massjump","tau2tau1 massjump",100,0,1.0));
   Book(TH1D("tau2tau1_200_massjump","tau2tau1 pt>200GeV massjump",100,0,1.0));
   Book(TH1D("tau2tau1_500_massjump","tau2tau1 pt>500GeV massjump",100,0,1.0));
   Book(TH1D("tau2tau1_600_massjump","tau2tau1 pt>600GeV massjump",100,0,1.0));
   Book(TH1D("tau2tau1_800_massjump","tau2tau1 pt>800GeV massjump",100,0,1.0));
   Book(TH1D("tau2tau1_1000_massjump","tau2tau1 pt>1000GeV massjump",100,0,1.0));
   Book(TH1D("tau3tau2_massjump","tau2tau1 massjump",100,0,1.0));
   Book(TH1D("tau3tau1_massjump","tau2tau1 massjump",100,0,1.0));
   Book(TH1D("tau3tau2_200_massjump","tau3tau2 pt>200GeV massjump",100,0,1.0));
   Book(TH1D("tau3tau2_500_massjump","tau3tau2 pt>400GeV massjump",100,0,1.0));
   Book(TH1D("tau3tau2_600_massjump","tau3tau2 pt>600GeV massjump",100,0,1.0));
   Book(TH1D("tau3tau2_800_massjump","tau3tau2 pt>800GeV massjump",100,0,1.0));
   Book(TH1D("tau3tau2_1000_massjump","tau3tau2 pt>1000GeV massjump",100,0,1.0));
   //subjetmass
   Book(TH1D("subjet01_massjump","subjet01 mass",100,0,200));
   Book(TH1D("subjet02_massjump","subjet02 mass",100,0,200));
   Book(TH1D("subjet12_massjump","subjet12 mass",100,0,200));
   Book(TH1D("subjet03_massjump","subjet03 mass",100,0,200));
   Book(TH1D("subjet13_massjump","subjet13 mass",100,0,200));
   Book(TH1D("subjet23_massjump","subjet23 mass",100,0,200));
   Book(TH1D("Wmass","reconstructed W-mass",100,0,200));
   Book(TH1D("pT_pf","pT pf",100,0,1000));
   Book(TH1D("sd_mass","softdrop mass",100,0,300));
   Book(TH1D("sd_mass200","softdrop mass",100,0,300));
   Book(TH1D("sd_mass500","softdrop mass",100,0,300));
   Book(TH1D("sd_mass600","softdrop mass",100,0,300));
   Book(TH1D("sd_mass800","softdrop mass",100,0,300));
   Book(TH1D("sd_mass1000","softdrop mass",100,0,300));
   //pt
    Book( TH1F( "pT_jet1"," p_{T} jets -1 ",50,0,2000));
    Book(TH1F("event1","events with only -1 jets",5,0,5));
    Book(TH1F("match","events with only -1 jets",5,0,5));
    Book(TH1F("deltaR_fatjets","deltaR fatjets",40,0,10));
    Book(TH1F("Cluster_deltaR","deltaR fatjets",40,0,10));
    Book(TH1F("Cluster_deltapT","deltaR fatjets",40,0,100));
    Book(TH1F("mj_wmass","mass at mj",200,0,200));

    //jet display
    Book(TH2F("JetDisplay","Jet event display",100,-PI,PI,100,-6,6));
    Book(TH2F("JetDisplay1","Jet event display",100,-PI,PI,100,-6,6));
    Book(TH2F("JetDisplay_fatjet","Jet event display",100,-PI,PI,100,-6,6));
    Book(TH2F("JetDisplay_pf","Jet event display",100,-PI,PI,100,-6,6));
     Book(TH2F("JetDisplay_pf_all","Jet event display",100,-PI,PI,100,-6,6));
    Book(TH2F("JetDisplay_top","Jet event display",100,-PI,PI,100,-6,6));
    Book(TH2F("JetDisplay_decay","Jet event display",100,-PI,PI,100,-6,6));

   //jetshapes
  Book( TH1F( "psi02_ly","Jetshapes #Psi (0.2)",70,0,1.4));
  Book( TH1F( "psi04_ly","Jetshapes #Psi (0.4)",70,0,1.4));
  Book( TH1F( "psi06_ly","Jetshapes #Psi (0.6)",70,0,1.4));
  Book( TH1F( "psi08_ly","Jetshapes #Psi (0.8)",70,0,1.4));
  Book( TH1F( "psi10_ly","Jetshapes #Psi (1.0)",70,0,1.4));

  //helicity angles
  Book(TH1D("HelAng12","Helicity angle subjet 1,2",35,0,3.5));
  Book(TH1D("HelAng13","Helicity angle subjet 1,3",35,0,3.5));
  Book(TH1D("HelAng23","Helicity angle subjet 2,3",35,0,3.5));

  //pt subjets
  Book( TH1F( "pT_subjet1"," p_{T} leading subjet",100,0,2000));
  Book( TH1F( "pT_subjetfrac1"," p_{T} leading subjet",100,0,1));
  Book( TH1F( "pT_subjet1_ly"," p_{T} leading subjet",100,0,2000));
  Book( TH1F( "pT_subjet2","p_{T} 2nd subjet",100,0,2000));
  Book( TH1F( "pT_subjetfrac2"," p_{T} leading subjet",100,0,1));
  Book( TH1F( "pT_subjet2_ly","p_{T} 2nd subjet",100,0,2000));
  Book( TH1F( "pT_subjet3","p_{T} 3rd subjet",100,0,1000));
  Book( TH1F( "pT_subjetfrac3"," p_{T} leading subjet",100,0,3));
  Book( TH1F( "pT_subjet3_ly","p_{T} 3rd subjet",100,0,1000));
  Book( TH1F( "pT_subjet4","p_{T} 4th subjet",100,0,800));
  Book( TH1F( "pT_subjetfrac4","p_{T} 4th subjet",100,0,800));
  Book( TH1F( "pT_subjet4_ly","p_{T} 4th subjet",100,0,800));
  Book( TH1F( "eta_subjet1","#eta leading subjet",100,-3,3));
  Book( TH1F( "eta_subjet1_ly","#eta leading subjet",100,-3,3));
  Book( TH1F( "eta_subjet2","#eta 2nd subjet",100,-3,3));
  Book( TH1F( "eta_subjet2_ly","#eta 2nd subjet",100,-3,3));
  Book( TH1F( "eta_subjet3","#eta 3rd subjet",100,-3,3));
  Book( TH1F( "eta_subjet3_ly","#eta 3rd subjet",100,-3,3));
  Book( TH1F( "eta_subjet4","#eta 4th subjet",100,-3,3));
  Book( TH1F( "eta_subjet4_ly","#eta 4th subjet",100,-3,3));
  Book( TH1F( "phi_subjet1","#phi leading subjet",100,-M_PI,M_PI));
  Book( TH1F( "phi_subjet1_ly","#phi leading subjet",100,-M_PI,M_PI));
  Book( TH1F( "phi_subjet2","#phi 2nd subjet",100,-M_PI,M_PI));
  Book( TH1F( "phi_subjet2_ly","#phi 2nd subjet",100,-M_PI,M_PI));
  Book( TH1F( "phi_subjet3","#phi 3rd subjet",100,-M_PI,M_PI));
  Book( TH1F( "phi_subjet3_ly","#phi 3rd subjet",100,-M_PI,M_PI));
  Book( TH1F( "phi_subjet4","#phi 4th subjet",100,-M_PI,M_PI));
  Book( TH1F( "phi_subjet4_ly","#phi 4th subjet",100,-M_PI,M_PI));
  Book( TH1D("nsub_eff200","eff nsub",100,-0.005,0.995));
  Book( TH1D("nsub_eff400","eff nsub",100,-0.005,0.995));
  Book( TH1D("nsub_eff600","eff nsub",100,-0.005,0.995));
  Book( TH1D("nsub_eff800","eff nsub",100,-0.005,0.995));
  Book( TH2D("nsub_eff","eff nsub",75,0,3000,100,-0.005,0.995));
  Book( TH3D("nsub_eff_mass","eff mass",75,0,3000,250,0,250,250,0,250));
  Book( TH3D("nsub_eff_mass_norm","eff mass",75,0,3000,250,0,250,250,0,250));
  Book( TH2D("nsub_eff_norm","eff nsub",75,0,3000,100,-0.005,0.995));
  Book( TH1D("nsub_eff200_norm","eff nsub",3,0,2));
  Book( TH1D("nsub_eff400_norm","eff nsub",3,0,2));
  Book( TH1D("nsub_eff600_norm","eff nsub",3,0,2));
  Book( TH1D("nsub_eff800_norm","eff nsub",3,0,2));


  Book(TH1D("delta_top_jet","delta betwen top jet",100,0,1));
  Book(TH1D("delta_top_jet200","delta betwen top jet",100,0,1));
   Book(TH1D("delta_top_jet400","delta betwen top jet",100,0,1));
    Book(TH1D("delta_top_jet600","delta betwen top jet",100,0,1));
     Book(TH1D("delta_top_jet800","delta betwen top jet",100,0,1));
      Book(TH1D("delta_top_jet1000","delta betwen top jet",100,0,1));
       Book(TH1D("delta_top_jet1200","delta betwen top jet",100,0,1));
        Book(TH1D("deltapt_top_jet","delta betwen top jet",100,0,1));
  Book(TH1D("deltapt_top_jet200","delta betwen top jet",100,-20,20));
   Book(TH1D("deltapt_top_jet400","delta betwen top jet",100,-20,20));
    Book(TH1D("deltapt_top_jet600","delta betwen top jet",100,-20,20));
     Book(TH1D("deltapt_top_jet800","delta betwen top jet",100,-20,20));
      Book(TH1D("deltapt_top_jet1000","delta betwen top jet",100,-20,20));
       Book(TH1D("deltapt_top_jet1200","delta betwen top jet",100,-20,20));
       Book(TH1D("pT_fraction1_200","pT_sub/p_T_jet",40,0,1));
        Book(TH1D("pT_fraction1_400","pT_sub/p_T_jet",40,0,1));
	 Book(TH1D("pT_fraction1_600","pT_sub/p_T_jet",40,0,1));
	  Book(TH1D("pT_fraction1_800","pT_sub/p_T_jet",40,0,1));
	   Book(TH1D("pT_fraction1_1000","pT_sub/p_T_jet",40,0,1));

  tmva_tagger=new TMVA_tagger();
  tmva_tagger2=new TMVA_tagger();
  tmva_tagger300=new TMVA_tagger();
  tmva_tagger500=new TMVA_tagger();
  tmva_tagger700=new TMVA_tagger();
  tmva_taggerInf=new TMVA_tagger();
  Showerdeconstruction_tagger= new Showerdeconstruction();
  Showerdeconstruction_taggerV2= new ShowerdeconstructionV2();
  Softdrop = new SoftDrop();
  jwj = new Jetswithoutjets();
  ecf = new ECF();
  varR = new VariableR();
  IR_Saftey= new Infrared_Saftey();
}

void RocHists2::SetIdVersion(TString s)
{
  idVersion=s;
}

void RocHists2::Fill()
{
  std::cout<<"-----"<<std::endl;
  // fill the histograms
  string algo="hhtoptagger";
  double akt_r=0.8;
  double rho(600.);
  double mu(30.), theta(0.7), mw(0.),mtopLow(140.),mtopHigh(220.);
  double min_r(0.1), max_r(1.5);//double mu(30.), theta(0.7);
  /*  if(idVersion.Contains("R700")) rho=700;
  if(idVersion.Contains("R600")) rho=600;
  if(idVersion.Contains("R500")) rho=500;
  if(idVersion.Contains("R400")) rho=400;
  if(idVersion.Contains("th70")) theta=0.7;
  if(idVersion.Contains("th60")) theta=0.6;
  if(idVersion.Contains("th80")) theta=0.8;
  if(idVersion.Contains("mu30")) mu=30;
  if(idVersion.Contains("mu40")) mu=40;
  if(idVersion.Contains("mu20")) mu=20;
  if(idVersion.Contains("mw40")) mw=40;
  if(idVersion.Contains("mw30")) mw=30;
  if(idVersion.Contains("mw20")) mw=20;
  if(idVersion.Contains("mw50")) mw=50;*/


    EventCalc* calc = EventCalc::Instance();
    BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
  bool IsRealData = calc->IsRealData();
  LuminosityHandler* lumih = calc->GetLumiHandler();

  // important: get the event weight
  double weight = calc->GetWeight();
  Hist("weight")->Fill(weight);
  int run = calc->GetRunNum();
  int lumiblock = calc->GetLumiBlock();
  int Npvs = calc->GetPrimaryVertices()->size();

  
 

  Hist("N_pv")->Fill(Npvs, weight);
  if(calc->IsRealData()){  
    Hist( "N_pv_perLumiBin")->Fill( lumih->GetLumiBin(run, lumiblock), Npvs*weight);
  Hist( "N_events_perLumiBin")->Fill( lumih->GetLumiBin(run, lumiblock), weight);
  }

 

  int Ntopjets = bcc->toptagjets->size();
  Hist("N_topjets")->Fill(Ntopjets, weight);

  std::vector<Muon>* muons = calc->GetMuons();
  int Nmuons = muons->size();
  Hist("N_mu")->Fill(Nmuons, weight);

  
  float minDeltaR=10000;
  int bestjetindex=-1;
  int bestjetindex2=-1;
  
 
  
  
  
  
  
  
  
  int nsteps=50;
  double wmin=0.0;
  double wmax=0.5;
  double nsubmin=0.0;
  double nsubmax=1.0;
  double csvmin=0.0;
  double csvmax=1.0;
  

  
  double nsub_step=(nsubmax-nsubmin)/nsteps;
  double w_step=(wmax-wmin)/nsteps;
  double csv_step=(csvmax-csvmin)/nsteps;
  double tstart=clock();
  double time1=0;
//EFFICIENCY
  if(!IsRealData && (idVersion=="TTbarEff" || idVersion=="TTbarEff_1" || idVersion=="TTbarEff_2" || idVersion=="TTbarEff_3" || idVersion.Contains("Zprime")))
  {
   
    //std::cout<<"works"<<std::endl;
    //  std:cout<<std::endl;
    std::vector<fastjet::PseudoJet> SortedSubJets;
    TTbarGen* Decay = calc->GetTTbarGen();
    //std::cout<<calc->GetEventNum()<<std::endl;
    //std::cout<<std::endl;
    //std::cout<<std::endl;
    std::vector<GenParticle> Had_Tops;
    std::vector<GenParticle> decay_products;
   bool isHadronic=false;
    if (Decay->IsTopHadronicDecay()) {
      Had_Tops.push_back(Decay->Top());
      decay_products.push_back(Decay->Wdecay1());
      decay_products.push_back(Decay->Wdecay2());
      decay_products.push_back(Decay->bTop());
    }
    if (Decay->IsAntiTopHadronicDecay()){ 
      Had_Tops.push_back(Decay->Antitop());
      decay_products.push_back(Decay->WMinusdecay1());
      decay_products.push_back(Decay->WMinusdecay2());
      decay_products.push_back(Decay->bAntitop());
    }
    if (Decay->IsTopHadronicDecay()) Had_Tops.push_back(Decay->Top());
    if (Decay->IsAntiTopHadronicDecay()) Had_Tops.push_back(Decay->Antitop());
     TTbarGen::E_DecayChannel decaymode= Decay->DecayChannel();
     // std::cout<<"decaymode "<<decaymode<<std::endl;
    int oldbestjet=-1;
     int oldbestjet2=-1;
     // std::cout<<"1"<<std::endl;
     Hist("topgen")->Fill(decaymode,weight);
    for (unsigned int j=0; j<Had_Tops.size(); j++)//if (isHadronic)
    {
     
        minDeltaR=10000;
	bestjetindex=-1;
        for(unsigned int i=0; i<bcc->toptagjets->size(); ++i)
	{
	  double DeltaR=Had_Tops[j].deltaR(bcc->toptagjets->at(i));
	  if(DeltaR<minDeltaR)
	  {
	    minDeltaR=DeltaR;
	    bestjetindex=i;
	  }
	}

	fastjet::ClusterSequence clustersq,clustersq2;
	double subjetmass, mmin2;
	double distance;
	vector<fastjet::PseudoJet> varjets,fatjets,fatjets_backup,fatjets_comb2;

	Hist("pT_s1_all")->Fill(Had_Tops[j].pt(),weight);
	if(Had_Tops[j].pt()>200) Hist("nsub_eff200_norm")->Fill(1,weight);
	if(Had_Tops[j].pt()>400) Hist("nsub_eff400_norm")->Fill(1,weight);
	if(Had_Tops[j].pt()>600) Hist("nsub_eff600_norm")->Fill(1,weight);
	if(Had_Tops[j].pt()>800) Hist("nsub_eff800_norm")->Fill(1,weight);
	for(int roc=0;roc<100;roc++) {((TH2D*)Hist("nsub_eff_norm"))->Fill(Had_Tops[j].pt(),roc/100.,weight);}
	for(int roc=0;roc<250;roc++) for(int roc2=0;roc2<250;roc2++)  {((TH3D*)Hist("nsub_eff_mass_norm"))->Fill(Had_Tops[j].pt(),roc,roc2,weight); }
	 EventCalc* calc = EventCalc::Instance();
  fastjet::JetDefinition *JetDef ;
 
  TopJet topjet;
  JetProps jp(&topjet,calc->GetPFParticles());
  std::vector<PFParticle> *pfparticles=calc->GetPFParticles();
  for(int pf=0;pf<pfparticles->size();pf++) Hist("pT_pf")->Fill(pfparticles->at(pf).pt(),weight);
  // fastjet::AreaDefinition area_def;
  // bool use_voronoi = true;
  /*if (!use_voronoi) {
    double ghost_etamax = 7.0;  
    double ghost_area    = 0.05;
    int    active_area_repeats = 1;*/
    // alternative settings for more precision:
    // reducing ghost area gives better sensitivity to the exact edges of the jet
     //double ghost_area    = 0.01;
     // increasing the repeats is useful in sparse events
   //int    active_area_repeats = 100; 
     // now create the object that holds info about ghosts, and from that
     // get an area definition
    // fastjet::GhostedAreaSpec ghost_spec(ghost_etamax, active_area_repeats, ghost_area);
   //area_def = fastjet::AreaDefinition(fastjet::passive_area,ghost_spec);
  // } else {
      //double effective_Rfact = 1.0;
      //area_def = fastjet::VoronoiAreaSpec(effective_Rfact);
  //}
  std::vector<fastjet::PseudoJet> jetpart = jp.Get_all_pfparticles();
  //if(jetpart.size()>0) IR_Saftey->add_soft_particles(jetpart);
  double ptmin(10.);
  // std::cout<<rho<<std::endl;
  vector<fastjet::PseudoJet> inclusive_jetsCA;
  fastjet::JetDefinition jet_defCA2;
  /* if(algo=="varR"){
    VariableRPlugin pluginAKT(rho, min_r, max_r, VariableRPlugin::AKTLIKE);
    fastjet::JetDefinition jet_defCA(&pluginAKT);
    jet_defCA2=jet_defCA;
  
  } //variableR
  if(algo=="massjump") {
    ClusteringVetoPlugin pluginAKT(mu, theta, max_r, ClusteringVetoPlugin::AKTLIKE);
     fastjet::JetDefinition jet_defCA(&pluginAKT);
    jet_defCA2=jet_defCA;
    //std::cout<<mu<<" "<<theta<<std::endl;
    }//mass jump
    if(algo=="hhtoptagger") {*/
  //ClusteringVetoPlugin pluginAKT(mu, theta, max_r, ClusteringVetoPlugin::AKTLIKE);
  //std::cout<<"rho "<<rho<<" mu "<<mu<<" theta "<<theta<<" mw "<<mw<<std::endl;
  HHTopTagger pluginAKT(mu, theta,min_r, max_r,rho,mw, HHTopTagger::CALIKE,fatjets);
     fastjet::JetDefinition jet_defCA(&pluginAKT);
    jet_defCA2=jet_defCA;
   
    //std::cout<<mu<<" "<<theta<<std::endl;
  //mass jump
  /*
  if(algo=="akt") {
    // std::cout<<"akt"<<std::endl;
    fastjet::JetDefinition jet_defCA(fastjet::antikt_algorithm,akt_r);
    jet_defCA2=jet_defCA;
    //normal
    }*/
  
  //if(algo=="varR" || algo=="massjump")  fastjet::JetDefinition jet_defCA(&pluginAKT);
 
   
  
  // fastjet::ClusterSequence clust_seqCA(jetpart, jet_defCA);
  //fastjet::ClusterSequenceArea clust_seq(jetpart,jet_defCA, area_def);
     fastjet::ClusterSequence clust_seqCA(jetpart, jet_defCA2);
    inclusive_jetsCA = clust_seqCA.inclusive_jets(ptmin);
  //vector<fastjet::PseudoJet> inclusive_jetsCA = clust_seqCA.inclusive_jets(ptmin);
    
  SortedSubJets = sorted_by_pt(inclusive_jetsCA);
  std::vector<fastjet::PseudoJet> constituents;
  //std::cout<<"!!!!!!!!!!!!!"<<SortedSubJets.size()<<std::endl;

  fatjets=pluginAKT.get_fatjets();
  std::vector<double> deltaR,deltapT,mj_wmass;
  deltaR=pluginAKT.get_deltaR();
  deltapT=pluginAKT.get_deltapT();
  mj_wmass=pluginAKT.get_mass();
  for(int o=0;o<mj_wmass.size();o++) Hist("mj_wmass")->Fill(mj_wmass[o],weight);
  for(int o=0;o<deltaR.size();o++) Hist("Cluster_deltaR")->Fill(deltaR[o],weight);
  for(int o=0;o<deltapT.size();o++) Hist("Cluster_deltapT")->Fill(deltapT[o],weight);
  fatjets_comb2=pluginAKT.get_fatjets_comb();
  // for(int o=0;o<fatjets_comb2.size();o++) std::cout<<"new combination "<<fatjets_comb2[o].pt()<<" phi "<<fatjets_comb2[o].phi()<<" user index "<<fatjets_comb2[o].user_index()<<std::endl;
  fastjet::ClusterSequence cs2;
  //if(calc->GetEventNum()==4252538) pluginAKT.CheckPassive();
  fatjets_backup=fatjets;
  bool event1=true;
  for(int o=0;o<fatjets.size();o++) if(fatjets[o].user_index()!=-1) event1=false;
  if(event1) Hist("event1")->Fill(1,weight);
  else  Hist("event1")->Fill(3,weight);
   for(int o=0;o<fatjets.size();o++) if(fatjets[o].user_index()==-1) Hist("pT_jet1")->Fill(fatjets[o].perp(),weight);
   /*ClusterSequence bigjets_cs;
   bigjets_cs=pluginAKT.get_cs_fatjets();
   std::vector<fastjet::PseudoJet> big_jets;
   big_jets=bigjets_cs.inclusive_jets(ptmin);
   std::cout<<"number of FATJETS "<<big_jets.size()<<std::endl;*/
   // if(calc->GetEventNum()==4252236) std::cout<<"*****"<<std::endl;

    std::vector<fastjet::PseudoJet> fatjets_comb, garbage;
   
    if(/*calc->GetEventNum()==4252236*/true)  
    
       int index=0;
       std::vector<fastjet::PseudoJet> subjets[fatjets.size()];
       std::vector<int> jetindex[fatjets.size()];




       for(int o=0;o<fatjets.size();o++){
	 for(int L=0;L<clust_seqCA.jets().size();L++)  if(clust_seqCA.jets()[L].pt()==fatjets[o].pt()) jetindex[o].push_back(L);
	 jetindex[o].push_back(fatjets[o].user_index());
	
	 
	    
       }
       /*    bool taken=false;
       for(int o=0;o<fatjets.size();o++){
	 taken=false;
	 for(int k=o;k<jetindex[o].size();k++) {
	   for(int j=o;j<fatjets.size();j++){
	     if(fatjets[j].user_index()==jetindex[o].at(k)  ) {
	       
	       for(int p=0;p<jetindex[o].size();p++) if(jetindex[j].at(0)==jetindex[o].at(p)) taken=true;
	       if(!taken) jetindex[o].push_back(jetindex[j].at(0));
	       
	     }
	   }
	   std::cout<<" new algorithm "<<jetindex[o].at(k)<<std::endl;
	   std::cout<<std::endl;
	 }
       }
       */



       /* for(int o=0;o<fatjets.size();o++){
      testjet=fatjets[o];
      index++;
      bool taken=false;
      bool taken2=false;
      for(int u=o+1;u<fatjets.size();u++){
	
	if(fatjets[o].user_index()==fatjets[u].user_index() && fatjets[o].user_index()!=-1 &&  fatjets[o].user_index()>20) {
	  //  std::cout<<"FATJETS "<<fatjets[o].perp()<<" phi "<<fatjets[o].phi()<<" user index "<<fatjets[o].user_index()<<std::endl;
	  fatjets[u].set_user_index(index);
	   subjets[index-1].push_back(fatjets[u]);
	  testjet.operator+=(fatjets[u]);
	  for(int h=0;h<fatjets.size();h++){
	    if(jetindex[u].at(0)==fatjets[h].user_index()){
	      fatjets[h].set_user_index(index);
	      subjets[index-1].push_back(fatjets[h]);
	      testjet.operator+=(fatjets[h]);
	    }

	  }
	  // testjet.set_user_index(0);
	  
	}

	
      }
      if(fatjets[o].user_index()!=-1) for(int g=0;g<fatjets.size();g++){
	if(jetindex[g].at(0)==fatjets[o].user_index()) for(int b=0;b<fatjets.size();b++) if(fatjets_backup[b].user_index()==jetindex[g].at(1) && o!=b && fatjets[b].user_index()<20) taken=true;
	}
      if( fatjets[o].user_index()>20 && !taken) {
	testjet.operator+=(clust_seqCA.jets()[fatjets[o].user_index()]);
	subjets[index-1].push_back(clust_seqCA.jets()[fatjets[o].user_index()]);
	subjets[index-1][subjets[index-1].size()-1].set_user_index(index);
	taken2=true;
	//std::cout<<"TEST-------------------------------------------------------------------------"<<std::endl;
      }
      if(!taken2 && fatjets[o].user_index()!=-1){
      for(int g=0;g<fatjets.size();g++){
	std::cout<<"merge------------------------------------------"<<std::endl;
	if(jetindex[g].at(0)==fatjets[o].user_index() && fatjets[g].user_index()>0) {
	     //   std::cout<<"MERGE********************************************** "<<fatjets[g].user_index()-1<<" "<<fatjets_comb.size()<<std::endl;
	     //fatjets_comb[fatjets[g].user_index()-1].operator+=(fatjets[o]);
	  if(fatjets.size()>fatjets[g].user_index() ) subjets[fatjets[g].user_index()-1].push_back(fatjets[o]);
	     fatjets[o].set_user_index(fatjets[g].user_index());
	     
	    		 }
      }}
				   
      if( fatjets[o].user_index()!=-1)for(int g=o;g<fatjets.size();g++) if(clust_seqCA.jets()[fatjets[o].user_index()].pt()==fatjets[g].pt() && fatjets[g].user_index()!=-1) fatjets[g].set_user_index(index);
      if(fatjets[o].user_index()>20 || fatjets[o].user_index()<0) {
	//	fatjets_comb.push_back(testjet);

	//	fatjets_comb[fatjets_comb.size()-1].set_user_index(index);
	fatjets[o].set_user_index(index);
	subjets[index-1].push_back(fatjets[o]);
      }
    
     }

    //bulid fatjets
    int index2=0;
    for(int o=0;o<fatjets.size();o++){
      index2++;
      fastjet::PseudoJet testjet=fatjets[o];
      for(int b=0;b<fatjets.size();b++)
	if(fatjets[o].user_index()==fatjets[b].user_index() && o!=b) {
	testjet.operator+=(fatjets[b]);
	//	std::cout<<"FUCK"<<std::endl;
      
      }
      if(fatjets[o].user_index()-1>=o){
      fatjets_comb.push_back(testjet);
      fatjets_comb[fatjets_comb.size()-1].set_user_index(fatjets[o].user_index());
      //std::cout<<"TOBIAS   "<< fatjets_comb[fatjets_comb.size()-1].perp()<<std::endl;
      }
      }*/
      

       /*     index=0;
       int index3=0;
       bool setjet;
       while(index3<fatjets.size()){
	 //std::cout<<"0   "<<index3<<std::endl;
	 fastjet::PseudoJet testjet;
       std::vector<int> liste;
       setjet=false;
       //std::cout<<"1"<<std::endl;
       index++;
       for(int o=0;o<fatjets.size();o++){
	 //std::cout<<"2"<<std::endl;
	 if(fatjets[o].user_index()!=-99 && !setjet) {
	   liste.push_back(jetindex[o].at(0));//changes 0
	   index3++;
	   setjet=true;
	   fatjets[o].set_user_index(-99);
	 }
	 for(int p=0;p<liste.size();p++){
	   if(fatjets[o].user_index()==liste[p]) {
	     liste.push_back(jetindex[o].at(0));
	     fatjets[o].set_user_index(-99);
	     index3++;
	 }
	 }
	 //std::cout<<"3"<<std::endl;
	

       }
       if(setjet){
	 for(int o=0;o<liste.size();o++){
	   if(subjets[index-1].size()==0){
	   testjet.operator+=(clust_seqCA.jets()[liste[o]]);
	   subjets[index-1].push_back(clust_seqCA.jets()[liste[o]]);}
	   else if(clust_seqCA.jets()[liste[o]].pt()>ptmin) {
	      testjet.operator+=(clust_seqCA.jets()[liste[o]]);
	      subjets[index-1].push_back(clust_seqCA.jets()[liste[o]]);
	   }
	 
	 }
	 //std::cout<<"4"<<std::endl;
	 //index3++;
	 if(testjet.pt()>ptmin){
	 fatjets_comb.push_back(testjet);
	 fatjets_comb[fatjets_comb.size()-1].set_user_index(index);
	 subjets[fatjets_comb.size()-1]=sorted_by_pt(subjets[fatjets_comb.size()-1]);
	 }
	 }
       // for(int o=0;o<liste.size();o++) std::cout<<"LISTE   "<<liste[o]<<std::endl;
       }*/
       int index=0;

	 std::vector<fastjet::PseudoJet> jet_radiation, jet_beam;
       for(int o=0;o<fatjets.size();o++){
	 //std::cout<<"TEST5"<<std::endl; 
	 if(fatjets[o].user_index()!=-99 && fatjets[o].pt()>ptmin){
	   index++;
	   fastjet::PseudoJet testjet=fatjets[o];
	   // std::cout<<"TEST2"<<std::endl;
	   subjets[index-1].push_back(clust_seqCA.jets()[jetindex[o].at(0)]);
	 for(int t=0;t<fatjets.size();t++) {
	   if(fatjets[o].user_index()==fatjets[t].user_index() && t!=o && fatjets[o].user_index()!=-1&& fatjets[o].pt()>ptmin){
	      testjet.operator+=(fatjets[t]);
	     //std::cout<<"TEST3"<<std::endl;
	     fatjets[t].set_user_index(-99);
	    
	      subjets[index-1].push_back(clust_seqCA.jets()[jetindex[t].at(0)]);
	   }
	 }
	
	 for(int k=0;k<fatjets.size();k++) if(fatjets[k].user_index()/100.==fatjets[o].user_index()){ fatjets_comb.push_back(fatjets[k]);
	 fatjets[o].set_user_index(-99);
	  fatjets_comb[fatjets_comb.size()-1].set_user_index(index);
	  subjets[fatjets_comb.size()-1]=sorted_by_pt(subjets[fatjets_comb.size()-1]);
	   }
	   else {
	     // std::cout<<"USER INDEX"<<fatjets[o].user_index()<<std::endl;
	     if(fatjets[o].user_index()==-1) jet_beam.push_back(fatjets[o]);
	     if(fatjets[o].user_index()==-2) jet_radiation.push_back(fatjets[o]);
	     //std::cout<<"TEST4"<<std::endl;
	   }
	 }
	 
       }
       Hist("NJets-1")->Fill(jet_beam.size(),weight);
       Hist("NJets-2")->Fill(jet_radiation.size(),weight);
       for(int y=0;y<jet_beam.size();y++) Hist("pT_beam")->Fill(jet_beam[y].pt(),weight);
       for(int y=0;y<jet_radiation.size();y++) Hist("pT_radiation")->Fill(jet_radiation[y].pt(),weight);
       for(int y=0;y<fatjets_comb.size();y++) Hist("pT_fatjets")->Fill(fatjets_comb[y].pt(),weight);
       //  std::cout<<"TEST"<<std::endl;




  
       //fastjet::ClusterSequence cs2;
       // pluginAKT.Fatjets(cs2);
       //fatjets_comb=cs2.inclusive_jets(ptmin);


      
       for(int o=0;o<fatjets_comb.size();o++)
	 for(int t=o;t<fatjets_comb.size();t++){
	   if(subjets[fatjets_comb[o].user_index()-1].size()>1 && subjets[fatjets_comb[t].user_index()-1].size()>1)  Hist("deltaR_fatjets")->Fill(fatjets_comb[o].delta_R(fatjets_comb[t]));
	 }
    
	     
       //  std::cout<<" number of jets "<<fatjets_comb.size()<<std::endl;     
       //std::cout<<"--------"<<std::endl;
std::vector<fastjet::PseudoJet> fatjet_constituents[fatjets_comb.size()];
 for(int o=0;o<fatjets_comb.size();o++){
       for(int p=0;p<subjets[fatjets_comb[o].user_index()-1].size();p++)
     for(int k=0;k<subjets[fatjets_comb[o].user_index()-1][p].constituents().size();k++)
       fatjet_constituents[o].push_back(subjets[fatjets_comb[o].user_index()-1][p].constituents().at(k));
       }
 /*if(true){
  for(int o=0;o<fatjets_comb.size();o++)  std::cout<<"FATJETS comb "<<fatjets_comb[o].perp()<<" phi "<<fatjets_comb[o].phi()<<" user index "<<fatjets_comb[o].user_index()<<" constituents "<<fatjet_constituents[o].size()<<std::endl;
   for(int o=0;o<fatjets.size();o++)   std::cout<<"FATJETS "<<fatjets[o].perp()<<" phi "<<fatjets[o].phi()<<" user index "<<fatjets[o].user_index()<<std::endl;
 for(int o=0;o<fatjets_comb.size();o++){
    std::cout<<"FATJET "<<fatjets_comb[o].perp()<<" phi "<<fatjets_comb[o].phi()<<" user index "<<fatjets_comb[o].user_index()<<std::endl;
    for(int k=0;k<subjets[fatjets_comb[o].user_index()-1].size();k++)   std::cout<<"subjet "<<subjets[fatjets_comb[o].user_index()-1][k].perp()<<" phi "<<subjets[fatjets_comb[o].user_index()-1][k].phi()<<" user index "<<subjets[fatjets_comb[o].user_index()-1][k].user_index()<<"const "<<subjets[fatjets_comb[o].user_index()-1][k].constituents().size()<<std::endl;
    }
    }*/

 if(calc->GetEventNum()==4252236){ //jetdisplay 4252236 4251318 4251364 4251321 4251818 
   for(int o=0;o<fatjets_backup.size();o++) 
     if(fatjets_backup[o].user_index()!=-1)   ((TH2D*)Hist("JetDisplay"))->Fill(fatjets[o].phi_std(),fatjets[o].eta(),fatjets[o].perp());
     else ((TH2D*)Hist("JetDisplay1"))->Fill(fatjets[o].phi_std(),fatjets[o].eta(),fatjets[o].perp());
   for(int o=0;o<fatjets_comb.size();o++) {
      ((TH2D*)Hist("JetDisplay_fatjet"))->Fill(fatjets_comb[o].phi_std(),fatjets_comb[o].eta(),fatjets_comb[o].perp());
      for(int h=0;h<fatjet_constituents[o].size();h++) ((TH2D*)Hist("JetDisplay_pf"))->Fill(fatjet_constituents[o].at(h).phi_std(),fatjet_constituents[o].at(h).eta(),fatjet_constituents[o].at(h).perp());
      
   }
   ((TH2D*)Hist("JetDisplay_top"))->Fill(Had_Tops[j].phi(),Had_Tops[j].eta(),Had_Tops[j].pt());
   for(int o=0;o<decay_products.size();o++) ((TH2D*)Hist("JetDisplay_decay"))->Fill(decay_products[o].phi(),decay_products[o].eta(),decay_products[o].pt());
   for(int o=0;o<jetpart.size();o++) ((TH2D*)Hist("JetDisplay_pf_all"))->Fill(jetpart[o].phi_std(),jetpart[o].eta(),jetpart[o].pt());
 }
 


 /* for(int o=0;o<SortedSubJets.size();++o){
    std::cout<<SortedSubJets[o].perp()<<std::endl;
    }*/


  // SortedJets =  fatjets_comb;
  // cout << "Ran " << jet_defCA.description() << endl;

  //  std::cout<<"bla2"<<std::endl;
  

  //merge subjets to fatjets
  /* vector<fastjet::PseudoJet> inclusive_jets_varR;
   // std::vector<fastjet::PseudoJet> SortedJets;
  VariableRPlugin pluginAKT2(600, min_r,max_r, VariableRPlugin::AKTLIKE);
  fastjet::JetDefinition jet_defCA3(&pluginAKT2);
  std::vector<fastjet::PseudoJet> jetpart_var=SortedSubJets;
  //std::vector<fastjet::PseudoJet> jetpart_var=fatjets;
  fastjet::ClusterSequence clust_seq_varR(jetpart_var, jet_defCA3);
  inclusive_jets_varR = clust_seq_varR.inclusive_jets(ptmin);
  // inclusive_jets_varR.push_back(garbage);
  // std::cout<<"!!!!!!!!!!!!!"<<garbage.size()<<std::endl;
  //for(int o=0;o<garbage.size();o++) inclusive_jets_varR.push_back(garbage[o]); 
  */  std::vector<fastjet::PseudoJet> SortedJets;
 // SortedJets = sorted_by_pt(inclusive_jets_varR) ;
 // for(int o=0;o<fatjets.size();o++) if(fatjets[o].user_index()==-99) SortedJets.push_back(fatjets[o]);
SortedJets =  fatjets_comb;

  /*  for(int y=0;y<SortedJets.size(); y++) {
    std::cout<<"fatjet "<<y<<" mass: "<<SortedJets[y].m()<<std::endl;
    std::cout<<"----------"<<std::endl;
    for(int x=0;x<SortedJets[y].constituents().size();x++){
      std::cout<<SortedJets[y].constituents()[x].perp()<<std::endl;
    }
    }*/
  for(int i=0;i<SortedJets.size();i++){


    
    double mjet=SortedJets[i].m();

    //  Hist("mjet")->Fill(mjet,weight);
     if(Had_Tops[j].pt()>200)  Hist("mjet200_before")->Fill(mjet,weight);
    if(Had_Tops[j].pt()>500)  Hist("mjet500_before")->Fill(mjet,weight);
    if(Had_Tops[j].pt()>600)  Hist("mjet600_before")->Fill(mjet,weight);
    if(Had_Tops[j].pt()>800)  Hist("mjet800_before")->Fill(mjet,weight);
    if(Had_Tops[j].pt()>1000)  Hist("mjet1000_before")->Fill(mjet,weight);

    //   std::cout<<"pt"<<SortedJets[i].pt()<<" dij"<<clust_seqCA.exclusive_subdmerge ( SortedJets[i], 1 )<<std::endl;
    //  Hist("Njets_norm")->Fill(SortedJets.at(i).perp(),weight);
   
    
 for(int t=0;t<SortedJets.size();t++) Hist("Njets_var")->Fill(SortedJets.at(i).perp(),weight);
 // std::vector<fastjet::PseudoJet> pfcands = fatjet_constituents[i];
    // std::vector<fastjet::PseudoJet> pfcands= subjets[fatjets_comb[i].user_index()-1];
    std::vector<fastjet::PseudoJet> pfcands = SortedJets[i].constituents();
     double oldR=0;
     
     for(int j=0;j<pfcands.size();j++){
       double R;
       //  if(pfcands.size()==1) R=0.000001;
        R=SortedJets[i].delta_R(pfcands[j]);
       
       //  std::cout<<"Abstand "<<R<<std::endl;
       //  double R=sqrt(pow(SortedJets[i].phi()-pfcands[j].phi(),2)+pow(SortedJets[i].pseudorapidity()-pfcands[j].pseudorapidity(),2));
       // std::cout<<"pf distance "<<R<<std::endl;
	 if(R>oldR){
	  
	   oldR=R;
	 }
					  }
     // std::cout<<"jet "<<oldR<<" pt "<<SortedJets[i].perp()<<std::endl;
     // std::cout<<"maxR "<<oldR<<std::endl;
     SortedJets[i].set_user_index(int(oldR*10));
     // if(SortedJets[i].user_index()>15) std::cout<<"ATTETTION  "<<SortedJets[i].user_index()<<std::endl;


     /* double area=clust_seq.area(SortedJets[i]);
     // std::cout<<"Area "<<area<<"Jet "<<i<<"pt "<<SortedJets[i].perp()<<std::endl;
     Hist("Area")->Fill(area,weight);
     if(SortedJets[i].perp()>200 && SortedJets[i].perp()<250)  Hist("Area200")->Fill(area,weight);
     if(SortedJets[i].perp()>400 && SortedJets[i].perp()<450)  Hist("Area400")->Fill(area,weight);
     if(SortedJets[i].perp()>600 && SortedJets[i].perp()<650)  Hist("Area600")->Fill(area,weight);
     if(SortedJets[i].perp()>800)  Hist("Area800")->Fill(area,weight);
     ((TH2D*)Hist("Area2d"))->Fill(SortedJets[i].perp(),area,weight); 
     ((TH2D*)Hist("VariableR_area"))->Fill(SortedJets[i].perp(),sqrt(area/3.14),weight); */
     // ((TH2D*)Hist("VariableR"))->Fill(SortedJets[i].perp(),oldR*10,weight); 
     //  std::cout<<"maxR "<< SortedJets[i].user_index()<<std::endl;
     //  std::cout<<"pt "<< SortedJets[i].perp()<<std::endl;
  }
  // std::vector<fastjet::PseudoJet> pfcands = SortedJets[0].pieces();
  //std::cout<<"test2"<<std::endl;
  //  delete JetDef;

  varjets=SortedJets;
  
  Hist("NJets")->Fill(varjets.size(),weight);
  Hist("NJetstop")->Fill(bcc->topjets->size(),weight);
	
	//	std::cout<<"bla"<<std::endl;
        double minDeltaR2=10000;
	int bestjetindex2=-1;
	//	std::cout<<"Njets "<<varjets.size()<<std::endl;
        
	if(/*event1*/true){
	for(unsigned int i=0; i<varjets.size(); ++i)
	{
	  double DeltaR2=sqrt(pow(Had_Tops[j].phi()-varjets[i].phi_std(),2)+pow(Had_Tops[j].eta()-varjets[i].pseudorapidity(),2));
	 
	  if(DeltaR2<minDeltaR2/* && fatjets_comb[i].perp()>200*/ )
	  {
	    minDeltaR2=DeltaR2;
	    bestjetindex2=i;
	      }
	}
	}
	else {
	  for(unsigned int i=0; i<varjets.size(); ++i)
	    {
	      double DeltaR2=sqrt(pow(Had_Tops[j].phi()-varjets[i].phi_std(),2)+pow(Had_Tops[j].eta()-varjets[i].pseudorapidity(),2));
	 
	      if(DeltaR2<minDeltaR2/* && fatjets_comb[i].perp()>200*/ && subjets[fatjets_comb[i].user_index()-1].size()>1 )
		{
		  minDeltaR2=DeltaR2;
		  bestjetindex2=i;
		}
	}
	}

	//std::cout<<"test"<<std::endl;
	//std::cout<<bestjetindex2<<std::endl;
	// std::cout<<"deltaR "<<minDeltaR2<<std::endl;
	//	if (minDeltaR>1.0) bestjetindex=-1;//protect against large deltaR
	if(bestjetindex2>-1) if (minDeltaR2>varjets[bestjetindex2].user_index()/10. /*&& varjets[bestjetindex2].perp()>200*/) bestjetindex2=-1;//protect against large deltaR
	/*	if((bestjetindex>-1) && (bestjetindex!=oldbestjet)){

	  

		}*/


	


	Hist("pT_gen")->Fill(Had_Tops[j].pt(),weight);
	 
	if(bestjetindex2>-1 )
	  {
	    /* if(subjets[fatjets_comb[bestjetindex2].user_index()-1].size()==1 && !event1) Hist("match")->Fill(1,weight);
	       else Hist("match")->Fill(3,weight);*/
	    //std::cout<<"CIRCLE"<<std::endl;
	     Hist("nsubjets_massjump")->Fill(subjets[fatjets_comb[bestjetindex2].user_index()-1].size(),weight);
	     if(Had_Tops[j].pt()>200 && Had_Tops[j].pt()<400) Hist("nsubjets_massjump200")->Fill(subjets[fatjets_comb[bestjetindex2].user_index()-1].size(),weight);
	     if(Had_Tops[j].pt()>600  && Had_Tops[j].pt()<600) Hist("nsubjets_massjump400")->Fill(subjets[fatjets_comb[bestjetindex2].user_index()-1].size(),weight);
	     if(Had_Tops[j].pt()>600  && Had_Tops[j].pt()<800) Hist("nsubjets_massjump600")->Fill(subjets[fatjets_comb[bestjetindex2].user_index()-1].size(),weight);
	     if(Had_Tops[j].pt()>800  && Had_Tops[j].pt()<1000) Hist("nsubjets_massjump800")->Fill(subjets[fatjets_comb[bestjetindex2].user_index()-1].size(),weight);
	     if(Had_Tops[j].pt()>1000  && Had_Tops[j].pt()<1200) Hist("nsubjets_massjump1000")->Fill(subjets[fatjets_comb[bestjetindex2].user_index()-1].size(),weight);
	    // Hist("nsubjets_massjump")->Fill(SortedJets[bestjetindex2].constituents().size(),weight);
	      // std::cout<<"CIRCLE2"<<std::endl;
	      double mmin2=0;
	  double wmass_rec=0;
	  //std::cout<<SortedJets[bestjetindex2].user_index()-1<<std::endl;


	  std::vector<fastjet::PseudoJet> SortedSubJets2=sorted_by_pt(subjets[fatjets_comb[bestjetindex2].user_index()-1]);
	  // subjets[fatjets_comb.size()-1]=sorted_by_pt(subjets[fatjets_comb.size()-1]);
	  	  // std::vector<fastjet::PseudoJet> SortedSubJets2=SortedJets[bestjetindex2].constituents();
	  //std::cout<<"check"<<std::endl;
	  double m12=0;
	  if(SortedSubJets2.size()>2){
	    //   std::cout<<"CIRCLE2"<<std::endl;
	  double m01 = 0;
	  m01=(SortedSubJets2[0]+SortedSubJets2[1]).m();
	  double m02 = 0;
	  m02=(SortedSubJets2[0]+SortedSubJets2[2]).m();
	  m12 = 0; 
	  m12 = (SortedSubJets2[1]+SortedSubJets2[2]).m();
	  Hist("subjet01_massjump")->Fill(m01,weight);
	  Hist("subjet02_massjump")->Fill(m02,weight);
	  Hist("subjet12_massjump")->Fill(m12,weight);
	  double m03=0;
	  double m13=0;
	  double m23=0;
	  if(SortedSubJets2.size()>3){
	  m03=(SortedSubJets2[0]+SortedSubJets2[3]).m();
	  m13=(SortedSubJets2[1]+SortedSubJets2[3]).m();
	  m23=(SortedSubJets2[2]+SortedSubJets2[3]).m();
	  Hist("subjet03_massjump")->Fill(m03,weight);
	  Hist("subjet13_massjump")->Fill(m13,weight);
	  Hist("subjet23_massjump")->Fill(m23,weight);
	  double deltaW, deltaW1,deltaW2,deltaW3,deltaW4,deltaW5;
	  deltaW=abs(80.4-m01);
	  deltaW1=abs(80.4-m02);
	  deltaW2=abs(80.4-m12);
	  deltaW3=abs(80.4-m03);
	  deltaW4=abs(80.4-m13);
	  deltaW5=abs(80.4-m23);
	  if(deltaW<deltaW1 && deltaW<deltaW2 && deltaW<deltaW3 && deltaW<deltaW4 && deltaW<deltaW5) wmass_rec=m01;
	  if(deltaW1<deltaW && deltaW1<deltaW2 && deltaW1<deltaW3&& deltaW1<deltaW4 && deltaW1<deltaW5) wmass_rec=m02; 
	  if(deltaW2<deltaW && deltaW2<deltaW1&& deltaW2<deltaW3&& deltaW2<deltaW4 && deltaW2<deltaW5)  wmass_rec=m12;
	  if(deltaW3<deltaW  && deltaW3<deltaW1&& deltaW3<deltaW2&& deltaW3<deltaW4 && deltaW3<deltaW5)   wmass_rec=m03;
	  if(deltaW4<deltaW  && deltaW4<deltaW1&& deltaW4<deltaW2&& deltaW4<deltaW3 && deltaW4<deltaW5)   wmass_rec=m13;
	  if(deltaW5<deltaW  && deltaW5<deltaW1&& deltaW5<deltaW2&& deltaW5<deltaW4 && deltaW5<deltaW3)   wmass_rec=m23; 
	  Hist("Wmass")->Fill(wmass_rec,weight);
	  
	  }
	  else{
	  double deltaW, deltaW1,deltaW2;
	  deltaW=abs(80.4-m01);
	  deltaW1=abs(80.4-m02);
	  deltaW2=abs(80.4-m12);
	  if(deltaW<deltaW1 && deltaW<deltaW2) wmass_rec=m01;
	  if(deltaW1<deltaW && deltaW1<deltaW2) wmass_rec=m02;
	  if(deltaW2<deltaW && deltaW2<deltaW1) wmass_rec=m12;
	  Hist("Wmass")->Fill(wmass_rec,weight);
	  }
	  mmin2 = std::min(m01,std::min(m02,m12));
	  if(Had_Tops[j].pt()>200 && Had_Tops[j].pt()<400) Hist("massjump_mmin200")->Fill(mmin2,weight);
	  if(Had_Tops[j].pt()>400 && Had_Tops[j].pt()<600) Hist("massjump_mmin400")->Fill(mmin2,weight);
	  if(Had_Tops[j].pt()>600 && Had_Tops[j].pt()<800) Hist("massjump_mmin600")->Fill(mmin2,weight);
	  if(Had_Tops[j].pt()>800 && Had_Tops[j].pt()<1000) Hist("massjump_mmin800")->Fill(mmin2,weight);
	  if(Had_Tops[j].pt()>1000 && Had_Tops[j].pt()<1200) Hist("massjump_mmin1000")->Fill(mmin2,weight);
	  }
	  
	  //subjet pt
	  

	  for (unsigned int bk =0; bk<=3; ++bk)
    {
      if (SortedSubJets2.size()> bk)
	{
	  
	 
	  TString hname = TString::Format("pT_subjet%d", bk+1);
	  Hist(hname)->Fill(SortedSubJets2.at(bk).pt(),weight);
	  hname = TString::Format("pT_subjetfrac%d", bk+1);
	  Hist(hname)->Fill(SortedSubJets2.at(bk).pt()/SortedJets[bestjetindex2].pt(),weight);
	  TString hname_ly = TString::Format("pT_subjet%d_ly", bk+1);
	  Hist(hname_ly)->Fill(SortedSubJets2.at(bk).pt(),weight);
	  TString hname_eta = TString::Format("eta_subjet%d", bk+1);
	  Hist(hname_eta)->Fill(SortedSubJets2.at(bk).eta(),weight);
	  TString hname_eta_ly = TString::Format("eta_subjet%d_ly", bk+1);
	  Hist(hname_eta_ly)->Fill(SortedSubJets2.at(bk).eta(),weight);
	  TString hname_phi = TString::Format("phi_subjet%d", bk+1);
	  Hist(hname_phi)->Fill(SortedSubJets2.at(bk).phi(),weight);
	  TString hname_phi_ly = TString::Format("phi_subjet%d_ly", bk+1);
	  Hist(hname_phi_ly)->Fill(SortedSubJets2.at(bk).phi(),weight);

	}
    }
	  

	  // std::cout<<"CIRCLE"<<std::endl;
	 

	  if(SortedSubJets2.size()>2)  Hist("pT_s1_tobi_tagged")->Fill(Had_Tops[j].pt(),weight);
	  if(SortedJets[bestjetindex2].m()>mtopLow &&  SortedJets[bestjetindex2].m()<mtopHigh)  Hist("pT_s1_tobi2_tagged")->Fill(Had_Tops[j].pt(),weight);
	  if(SortedJets[bestjetindex2].user_index()>5)  Hist("pT_s1_varR_tagged")->Fill(Had_Tops[j].pt(),weight);
	  /* && (bestjetindex2!=oldbestjet2)*/
	  /*vector<fastjet::PseudoJet> inclusive_subjetsCA;
	  std::vector<fastjet::PseudoJet> jetpart2 = SortedJets[bestjetindex2].constituents();
	  ClusteringVetoPlugin pluginAKT(mu, theta, max_r, ClusteringVetoPlugin::AKTLIKE);
	  // HHTopTagger pluginAKT(mu, theta, max_r, HHTopTagger::AKTLIKE);
	  fastjet::JetDefinition jet_defCA2(&pluginAKT);
	  fastjet::ClusterSequence clust_seqCA2(jetpart2, jet_defCA2);
	  inclusive_subjetsCA = clust_seqCA2.inclusive_jets(ptmin);
	  std::vector<fastjet::PseudoJet> SortedSubJets = sorted_by_pt(inclusive_subjetsCA);
	  // std::cout<<SortedSubJets.size()<<std::endl;
	  //if(SortedSubJets.size()>0)if(SortedSubJets[0].perp()>500) Hist("mjet_massjump")->Fill(SortedSubJets[0].m(),weight);
	  fastjet::PseudoJet sum=SortedSubJets[0];
	  for(int mj=1;mj<SortedSubJets.size();mj++) {
	    sum.operator+=(SortedSubJets[mj]);
	  }
	  if(Had_Tops[j].pt()>500) Hist("mjet_massjump200")->Fill(sum.m(),weight);
	  if(Had_Tops[j].pt()>500) Hist("mjet_massjump500")->Fill(sum.m(),weight);
	  if(Had_Tops[j].pt()>600) Hist("mjet_massjump600")->Fill(sum.m(),weight);
	  if(Had_Tops[j].pt()>800) Hist("mjet_massjump800")->Fill(sum.m(),weight);
	  if(Had_Tops[j].pt()>1000) Hist("mjet_massjump1000")->Fill(sum.m(),weight);
	  // std::cout<<sum.m()<<std::endl;
	  Hist("nsubjets_massjump")->Fill(SortedSubJets.size(),weight);

	  if(SortedSubJets.size()>2)  Hist("pT_s1_tobi_tagged")->Fill(Had_Tops[j].pt(),weight);
	  if(SortedSubJets.size()>2 && SortedJets[bestjetindex2].m()>150 &&  SortedJets[bestjetindex2].m()<250)  Hist("pT_s1_tobi2_tagged")->Fill(Had_Tops[j].pt(),weight);
	  
	  //calculating mmin for new subjets
	  double mmin2=0;
	  double wmass_rec=0;
	  if(SortedSubJets.size()>2){
	  double m01 = 0;
	  m01=(SortedSubJets[0]+SortedSubJets[1]).m();
	  double m02 = 0;
	  m02=(SortedSubJets[0]+SortedSubJets[2]).m();
	  double m12 = 0; 
	  m12 = (SortedSubJets[1]+SortedSubJets[2]).m();
	  Hist("subjet01_massjump")->Fill(m01,weight);
	  Hist("subjet02_massjump")->Fill(m02,weight);
	  Hist("subjet12_massjump")->Fill(m12,weight);
	  double m03=0;
	  double m13=0;
	  double m23=0;
	  if(SortedSubJets.size()>3){
	  m03=(SortedSubJets[0]+SortedSubJets[3]).m();
	  m13=(SortedSubJets[1]+SortedSubJets[3]).m();
	  m23=(SortedSubJets[2]+SortedSubJets[3]).m();
	  Hist("subjet03_massjump")->Fill(m03,weight);
	  Hist("subjet13_massjump")->Fill(m13,weight);
	  Hist("subjet23_massjump")->Fill(m23,weight);
	  double deltaW, deltaW1,deltaW2,deltaW3,deltaW4,deltaW5;
	  deltaW=abs(80.4-m01);
	  deltaW1=abs(80.4-m02);
	  deltaW2=abs(80.4-m12);
	  deltaW3=abs(80.4-m03);
	  deltaW4=abs(80.4-m13);
	  deltaW5=abs(80.4-m23);
	  if(deltaW<deltaW1 && deltaW<deltaW2 && deltaW<deltaW3 && deltaW<deltaW4 && deltaW<deltaW5) wmass_rec=m01;
	  if(deltaW1<deltaW && deltaW1<deltaW2 && deltaW1<deltaW3&& deltaW1<deltaW4 && deltaW1<deltaW5) wmass_rec=m02; 
	  if(deltaW2<deltaW && deltaW2<deltaW1&& deltaW2<deltaW3&& deltaW2<deltaW4 && deltaW2<deltaW5)  wmass_rec=m12;
	  if(deltaW3<deltaW  && deltaW3<deltaW1&& deltaW3<deltaW2&& deltaW3<deltaW4 && deltaW3<deltaW5)   wmass_rec=m03;
	  if(deltaW4<deltaW  && deltaW4<deltaW1&& deltaW4<deltaW2&& deltaW4<deltaW3 && deltaW4<deltaW5)   wmass_rec=m13;
	  if(deltaW5<deltaW  && deltaW5<deltaW1&& deltaW5<deltaW2&& deltaW5<deltaW4 && deltaW5<deltaW3)   wmass_rec=m23; 
	  Hist("Wmass")->Fill(wmass_rec,weight);
	  
	  }
	  else{
	  double deltaW, deltaW1,deltaW2;
	  deltaW=abs(80.4-m01);
	  deltaW1=abs(80.4-m02);
	  deltaW2=abs(80.4-m12);
	  if(deltaW<deltaW1 && deltaW<deltaW2) wmass_rec=m01;
	  if(deltaW1<deltaW && deltaW1<deltaW2) wmass_rec=m02;
	  if(deltaW2<deltaW && deltaW2<deltaW1) wmass_rec=m12;
	  Hist("Wmass")->Fill(wmass_rec,weight);
	  }
	  mmin2 = std::min(m01,std::min(m02,m12));
	  Hist("massjump_mmin")->Fill(mmin2,weight);
	  }
	  if(SortedSubJets.size()>2 && SortedJets[bestjetindex2].m()>150 &&  SortedJets[bestjetindex2].m()<250 && mmin2>50)  Hist("pT_s1_tobi3_tagged")->Fill(Had_Tops[j].pt(),weight);
	  if(SortedSubJets.size()>2 && SortedJets[bestjetindex2].m()>150 &&  SortedJets[bestjetindex2].m()<250 && wmass_rec>70 && wmass_rec<90)  Hist("pT_s1_tobi6_tagged")->Fill(Had_Tops[j].pt(),weight);
	  */
	  if(Had_Tops[j].pt()>200 && Had_Tops[j].pt()<400) Hist("pT_fraction1_200")->Fill(SortedSubJets2.at(0).pt()/SortedJets[bestjetindex2].pt(),weight);
	  if(Had_Tops[j].pt()>400 && Had_Tops[j].pt()<600) Hist("pT_fraction1_400")->Fill(SortedSubJets2.at(0).pt()/SortedJets[bestjetindex2].pt(),weight);
	  if(Had_Tops[j].pt()>600 && Had_Tops[j].pt()<800) Hist("pT_fraction1_600")->Fill(SortedSubJets2.at(0).pt()/SortedJets[bestjetindex2].pt(),weight);
	  if(Had_Tops[j].pt()>800 && Had_Tops[j].pt()<1000) Hist("pT_fraction1_800")->Fill(SortedSubJets2.at(0).pt()/SortedJets[bestjetindex2].pt(),weight);
	  if(Had_Tops[j].pt()>1000 && Had_Tops[j].pt()<1200) Hist("pT_fraction1_1000")->Fill(SortedSubJets2.at(0).pt()/SortedJets[bestjetindex2].pt(),weight);
	 
	  if(SortedSubJets2.size()>2 && SortedJets[bestjetindex2].m()>mtopLow &&  SortedJets[bestjetindex2].m()<mtopHigh)  Hist("pT_s1_tobi3_tagged")->Fill(Had_Tops[j].pt(),weight);
	  if(SortedSubJets2.size()>2 && SortedJets[bestjetindex2].m()>mtopLow &&  SortedJets[bestjetindex2].m()<mtopHigh  &&SortedSubJets2.at(0).pt()>30 && SortedSubJets2.at(1).pt()>30 &&  SortedSubJets2.at(0).pt()/SortedJets[bestjetindex2].pt()<0.8 /*&&mmin2>50*/) {
	    Hist("pT_s1_tobi6_tagged")->Fill(Had_Tops[j].pt(),weight);
	    double deltaR_tag=sqrt(pow(SortedJets[bestjetindex2].eta()-Had_Tops[j].eta(),2)+pow(SortedJets[bestjetindex2].phi_std()-Had_Tops[j].phi(),2));
	    double deltapT= SortedJets[bestjetindex2].pt()-Had_Tops[j].pt();
	    if(Had_Tops[j].pt()>200 &&Had_Tops[j].pt()<400) Hist("delta_top_jet200")->Fill(deltaR_tag,weight);
	    if(Had_Tops[j].pt()>400 &&Had_Tops[j].pt()<600) Hist("delta_top_jet400")->Fill(deltaR_tag,weight);
	    if(Had_Tops[j].pt()>600 &&Had_Tops[j].pt()<800) Hist("delta_top_jet600")->Fill(deltaR_tag,weight);
	    if(Had_Tops[j].pt()>800 &&Had_Tops[j].pt()<1000) Hist("delta_top_jet800")->Fill(deltaR_tag,weight);
	    if(Had_Tops[j].pt()>1000 &&Had_Tops[j].pt()<1200) Hist("delta_top_jet1000")->Fill(deltaR_tag,weight);
	    
	     if(Had_Tops[j].pt()>200 &&Had_Tops[j].pt()<400) Hist("deltapt_top_jet200")->Fill(deltapT,weight);
	    if(Had_Tops[j].pt()>400 &&Had_Tops[j].pt()<600) Hist("deltapt_top_jet400")->Fill(deltapT,weight);
	    if(Had_Tops[j].pt()>600 &&Had_Tops[j].pt()<800) Hist("deltapt_top_jet600")->Fill(deltapT,weight);
	    if(Had_Tops[j].pt()>800 &&Had_Tops[j].pt()<1000) Hist("deltapt_top_jet800")->Fill(deltapT,weight);
	    if(Had_Tops[j].pt()>1000 &&Had_Tops[j].pt()<1200) Hist("deltapt_top_jet1000")->Fill(deltapT,weight);
	  

	    if(Had_Tops[j].pt()>1200 ) Hist("delta_top_jet1200")->Fill(deltaR_tag,weight);
	  }
	  Hist("pT_jets")->Fill(varjets.at(bestjetindex2).perp(),weight);
	  TString hname1 = TString::Format("pT_gen_match_skt");
	  Hist(hname1)->Fill(Had_Tops[j].pt(),weight);


	  fastjet::PseudoJet jet=varjets.at(bestjetindex2);
	   fastjet::PseudoJet probejet=varjets.at(bestjetindex2);
	   bool collimated=false;
	   bool collimated01=false;
	   bool collimated02=false;
	   bool collimated03=false;
	   bool collimated04=false;
	   bool collimated05=false;
	   bool collimated06=false;
	   bool collimated07=false;
	   double  microjet_cone=varjets[bestjetindex2].user_index()/10.;
	   if(Decay->IsTopHadronicDecay()){
	    double distanceW1, distanceW2, distanceb;
	    if(probejet.phi()>PI) distanceW1=sqrt(pow(Decay->Wdecay1().phi()-(probejet.phi()-2*PI),2)+pow(Decay->Wdecay1().eta()-probejet.eta(),2));
	    else distanceW1=sqrt(pow(Decay->Wdecay1().phi()-probejet.phi(),2)+pow(Decay->Wdecay1().eta()-probejet.eta(),2));
	    if(probejet.phi()>PI) distanceW2=sqrt(pow(Decay->Wdecay2().phi()-(probejet.phi()-2*PI),2)+pow(Decay->Wdecay2().eta()-probejet.eta(),2));
	    else distanceW2=sqrt(pow(Decay->Wdecay2().phi()-probejet.phi(),2)+pow(Decay->Wdecay2().eta()-probejet.eta(),2));
	    if(probejet.phi()>PI) distanceb=sqrt(pow(Decay->bTop().phi()-(probejet.phi()-2*PI),2)+pow(Decay->bTop().eta()-probejet.eta(),2));
	    else distanceb=sqrt(pow(Decay->bTop().phi()-probejet.phi(),2)+pow(Decay->bTop().eta()-probejet.eta(),2));
	    if(distanceW1<microjet_cone && distanceW2<microjet_cone && distanceb<microjet_cone) collimated=true; 
	    if(distanceW1<0.9*microjet_cone && distanceW2<0.9*microjet_cone && distanceb<0.9*microjet_cone) collimated01=true;
	    if(distanceW1<0.8*microjet_cone && distanceW2<0.8*microjet_cone && distanceb<0.8*microjet_cone) collimated02=true;
	    if(distanceW1<0.7*microjet_cone && distanceW2<0.7*microjet_cone && distanceb<0.7*microjet_cone) collimated03=true;
	    if(distanceW1<0.6*microjet_cone && distanceW2<0.6*microjet_cone && distanceb<0.6*microjet_cone) collimated04=true;
	    if(distanceW1<0.5*microjet_cone && distanceW2<0.5*microjet_cone && distanceb<0.5*microjet_cone) collimated05=true;
	    if(distanceW1<0.4*microjet_cone && distanceW2<0.4*microjet_cone && distanceb<0.4*microjet_cone) collimated06=true;
	    if(distanceW1<0.3*microjet_cone && distanceW2<0.3*microjet_cone && distanceb<0.3*microjet_cone) collimated07=true;
	  }
	  if(Decay->IsAntiTopHadronicDecay()){
	    double distanceW1, distanceW2, distanceb;
	    if(probejet.phi()>PI) distanceW1=sqrt(pow(Decay->WMinusdecay1().phi()-(probejet.phi()-2*PI),2)+pow(Decay->WMinusdecay1().eta()-probejet.eta(),2));
	    else distanceW1=sqrt(pow(Decay->WMinusdecay1().phi()-probejet.phi(),2)+pow(Decay->WMinusdecay1().eta()-probejet.eta(),2));
	    if(probejet.phi()>PI) distanceW2=sqrt(pow(Decay->WMinusdecay2().phi()-(probejet.phi()-2*PI),2)+pow(Decay->WMinusdecay2().eta()-probejet.eta(),2));
	    else distanceW2=sqrt(pow(Decay->WMinusdecay2().phi()-probejet.phi(),2)+pow(Decay->WMinusdecay2().eta()-probejet.eta(),2));
	    if(probejet.phi()>PI) distanceb=sqrt(pow(Decay->bAntitop().phi()-(probejet.phi()-2*PI),2)+pow(Decay->bAntitop().eta()-probejet.eta(),2));
	    else distanceb=sqrt(pow(Decay->bAntitop().phi()-probejet.phi(),2)+pow(Decay->bAntitop().eta()-probejet.eta(),2));
	    if(distanceW1<microjet_cone && distanceW2<microjet_cone && distanceb<microjet_cone) collimated=true; 
	    if(distanceW1<0.9*microjet_cone && distanceW2<0.9*microjet_cone && distanceb<0.9*microjet_cone) collimated01=true;
	    if(distanceW1<0.8*microjet_cone && distanceW2<0.8*microjet_cone && distanceb<0.8*microjet_cone) collimated02=true;
	    if(distanceW1<0.7*microjet_cone && distanceW2<0.7*microjet_cone && distanceb<0.7*microjet_cone) collimated03=true;
	    if(distanceW1<0.6*microjet_cone && distanceW2<0.6*microjet_cone && distanceb<0.6*microjet_cone) collimated04=true;
	    if(distanceW1<0.5*microjet_cone && distanceW2<0.5*microjet_cone && distanceb<0.5*microjet_cone) collimated05=true;
	    if(distanceW1<0.4*microjet_cone && distanceW2<0.4*microjet_cone && distanceb<0.4*microjet_cone) collimated06=true;
	    if(distanceW1<0.3*microjet_cone && distanceW2<0.3*microjet_cone && distanceb<0.3*microjet_cone) collimated07=true;
	    }
	  if(collimated) {
	    Hist("pT_gen_match_skt_collimated")->Fill(Had_Tops[j].pt(),weight);
	    if(!collimated01) Hist("pT_gen_match_skt_collimated_01")->Fill(Had_Tops[j].pt(),weight);
	    if(!collimated02) Hist("pT_gen_match_skt_collimated_02")->Fill(Had_Tops[j].pt(),weight);
	    if(!collimated03) Hist("pT_gen_match_skt_collimated_03")->Fill(Had_Tops[j].pt(),weight);
	    if(!collimated04) Hist("pT_gen_match_skt_collimated_04")->Fill(Had_Tops[j].pt(),weight);
	    if(!collimated05) Hist("pT_gen_match_skt_collimated_05")->Fill(Had_Tops[j].pt(),weight);
	    if(!collimated06) Hist("pT_gen_match_skt_collimated_06")->Fill(Had_Tops[j].pt(),weight);
	    if(!collimated07) Hist("pT_gen_match_skt_collimated_07")->Fill(Had_Tops[j].pt(),weight);

	  }
	  // std::cout<<"test3"<<std::endl;
	  // std::cout<<bestjetindex<<std::endl;
	  oldbestjet2=bestjetindex2;
	
	  ((TH2D*)Hist("VariableR"))->Fill(jet.perp(),jet.user_index(),weight); 
	  double mjet,mmin;
	  int nsubjets;
	  std::vector<fastjet::PseudoJet> subjets;
	  fastjet::PseudoJet CMSjet;
	  Hist("pT_s1")->Fill(Had_Tops[j].pt(),weight);
	  //if(CMSTopTagFull_pseudo_CA(jet,3.0,0.05,0.4,0.0004,mjet, nsubjets,mmin,subjets,CMSjet)) Hist("pT_s1_cms_tagged400")->Fill(Had_Tops[j].pt(),weight);
	 
	  int index;
	  bool taken[6]={true,true,true,true,true,true};
	  double olddistance=1000.;
	  double distance=100.;
	   for(int t=0;t<subjets.size();t++){
	       for(int L=0;L<decay_products.size();L++){
		  if(subjets[t].phi()>PI)  distance=sqrt(pow(decay_products[L].phi()-(subjets[t].phi()-2*PI),2)+pow(decay_products[L].eta()-subjets[t].eta(),2));
		  else distance=sqrt(pow(decay_products[L].phi()-subjets[t].phi(),2)+pow(decay_products[L].eta()-subjets[t].eta(),2));
		 if(distance<olddistance && taken[L]){ 
		   index=L;
		   olddistance=distance;
		 }
		 
		
		 TString hnamex = TString::Format("distance_subjet%d_decaypro%d", t,L);
		 Hist(hnamex)->Fill(distance,weight);
	       }
	       TString effname = TString::Format("pT_decay%d", index);
	       Hist(effname)->Fill(decay_products[index].pt(),weight);
	       if(distance<jet.user_index()/10.){
		 TString effname1 = TString::Format("pT_decay%d_akt", index);
		 Hist(effname1)->Fill(decay_products[index].pt(),weight);
		
	       }
	       taken[index]=false;
	      
	     }
	  
	   Hist("mmin")->Fill(mmin,weight);
	   Hist("nsubjets")->Fill(nsubjets,weight);
	   mjet=SortedJets[bestjetindex2].m();

	   Hist("mjet")->Fill(mjet,weight);
	   if(Had_Tops[j].pt()>200  && Had_Tops[j].pt()<400)  Hist("mjet200")->Fill(mjet,weight);
	   if(Had_Tops[j].pt()>400  && Had_Tops[j].pt()<600)  Hist("mjet400")->Fill(mjet,weight);
	   if(Had_Tops[j].pt()>600  && Had_Tops[j].pt()<800)  Hist("mjet600")->Fill(mjet,weight);
	   if(Had_Tops[j].pt()>800  && Had_Tops[j].pt()<1000)  Hist("mjet800")->Fill(mjet,weight);
	   if(Had_Tops[j].pt()>1000  && Had_Tops[j].pt()<1200)  Hist("mjet1000")->Fill(mjet,weight);

	    if(SortedSubJets2.size()>2){
	   if(Had_Tops[j].pt()>200  && Had_Tops[j].pt()<400)  Hist("mjet200_1")->Fill(mjet,weight);
	   if(Had_Tops[j].pt()>400  && Had_Tops[j].pt()<600)  Hist("mjet400_1")->Fill(mjet,weight);
	   if(Had_Tops[j].pt()>600  && Had_Tops[j].pt()<800)  Hist("mjet600_1")->Fill(mjet,weight);
	   if(Had_Tops[j].pt()>800  && Had_Tops[j].pt()<1000)  Hist("mjet800_1")->Fill(mjet,weight);
	   if(Had_Tops[j].pt()>1000  && Had_Tops[j].pt()<1200)  Hist("mjet1000_1")->Fill(mjet,weight);
	   }
	  	  // std::cout<<"test2"<<std::endl;
	     if(SortedSubJets2.size()>3){
	   if(Had_Tops[j].pt()>200  && Had_Tops[j].pt()<400)  Hist("mjet200_2")->Fill(mjet,weight);
	   if(Had_Tops[j].pt()>400  && Had_Tops[j].pt()<600)  Hist("mjet400_2")->Fill(mjet,weight);
	   if(Had_Tops[j].pt()>600  && Had_Tops[j].pt()<800)  Hist("mjet600_2")->Fill(mjet,weight);
	   if(Had_Tops[j].pt()>800  && Had_Tops[j].pt()<1000)  Hist("mjet800_2")->Fill(mjet,weight);
	   if(Had_Tops[j].pt()>1000  && Had_Tops[j].pt()<1200)  Hist("mjet1000_2")->Fill(mjet,weight);
	   }
	   

	   ////cutting variables
	   // std::cout<<"CIRCLE"<<std::endl;
	   //nsubjettiness
	       double tau1,tau2,tau3,tau4;
	       JetPropsPseudo jp(&jet);
	   tau1 = jp.GetNsubjettiness(1, Njettiness::onepass_kt_axes, 1., varjets[bestjetindex2].user_index()/10.);
	   tau2 = jp.GetNsubjettiness(2, Njettiness::onepass_kt_axes, 1., varjets[bestjetindex2].user_index()/10.);
	   tau3 = jp.GetNsubjettiness(3, Njettiness::onepass_kt_axes, 1., varjets[bestjetindex2].user_index()/10.);
	   tau4 = jp.GetNsubjettiness(4, Njettiness::onepass_kt_axes, 1., varjets[bestjetindex2].user_index()/10.);
	   Hist("tau1")->Fill(tau1,weight);
	   if(Had_Tops[j].pt()>200) Hist("tau1_200")->Fill(tau1,weight);
	   if(Had_Tops[j].pt()>500) Hist("tau1_500")->Fill(tau1,weight);
	   if(Had_Tops[j].pt()>600) Hist("tau1_600")->Fill(tau1,weight);
	   if(Had_Tops[j].pt()>800) Hist("tau1_800")->Fill(tau1,weight);
	   if(Had_Tops[j].pt()>1000) Hist("tau1_1000")->Fill(tau1,weight);
	  
	   Hist("tau2")->Fill(tau2,weight);
	   if(Had_Tops[j].pt()>200) Hist("tau2_200")->Fill(tau2,weight);
	   if(Had_Tops[j].pt()>500) Hist("tau2_500")->Fill(tau2,weight);
	   if(Had_Tops[j].pt()>600) Hist("tau2_600")->Fill(tau2,weight);
	   if(Had_Tops[j].pt()>800) Hist("tau2_800")->Fill(tau2,weight);
	   if(Had_Tops[j].pt()>1000) Hist("tau2_1000")->Fill(tau2,weight);
	   Hist("tau3")->Fill(tau3,weight);
	   if(Had_Tops[j].pt()>200) Hist("tau3_200")->Fill(tau3,weight);
	   if(Had_Tops[j].pt()>500) Hist("tau3_500")->Fill(tau3,weight);
	   if(Had_Tops[j].pt()>600) Hist("tau3_600")->Fill(tau3,weight);
	   if(Had_Tops[j].pt()>800) Hist("tau3_800")->Fill(tau3,weight);
	   if(Had_Tops[j].pt()>1000) Hist("tau3_1000")->Fill(tau3,weight);
	   Hist("tau4")->Fill(tau4,weight);
	   if(Had_Tops[j].pt()>200) Hist("tau4_200")->Fill(tau4,weight);
	   if(Had_Tops[j].pt()>500) Hist("tau4_500")->Fill(tau4,weight);
	   if(Had_Tops[j].pt()>600) Hist("tau4_600")->Fill(tau4,weight);
	   if(Had_Tops[j].pt()>800) Hist("tau4_800")->Fill(tau4,weight);
	   if(Had_Tops[j].pt()>1000) Hist("tau4_1000")->Fill(tau4,weight);
	   Hist("tau2tau1")->Fill(tau2/tau1,weight);
	   if(Had_Tops[j].pt()>200)  Hist("tau2tau1_200")->Fill(tau2/tau1,weight);
	   if(Had_Tops[j].pt()>500)  Hist("tau2tau1_500")->Fill(tau2/tau1,weight);
	   if(Had_Tops[j].pt()>600)  Hist("tau2tau1_600")->Fill(tau2/tau1,weight);
	   if(Had_Tops[j].pt()>800)  Hist("tau2tau1_800")->Fill(tau2/tau1,weight);
	   if(Had_Tops[j].pt()>1000)  Hist("tau2tau1_1000")->Fill(tau2/tau1,weight);
	   Hist("tau3tau2")->Fill(tau3/tau2,weight);
	   if(Had_Tops[j].pt()>200  && Had_Tops[j].pt()<400)  Hist("tau3tau2_200")->Fill(tau3/tau2,weight);
	   if(Had_Tops[j].pt()>400  && Had_Tops[j].pt()<600)  Hist("tau3tau2_400")->Fill(tau3/tau2,weight);
	   if(Had_Tops[j].pt()>600  && Had_Tops[j].pt()<800)  Hist("tau3tau2_600")->Fill(tau3/tau2,weight);
	   if(Had_Tops[j].pt()>800  && Had_Tops[j].pt()<1000)  Hist("tau3tau2_800")->Fill(tau3/tau2,weight);
	   if(Had_Tops[j].pt()>1000  && Had_Tops[j].pt()<1200)  Hist("tau3tau2_1000")->Fill(tau3/tau2,weight);
	   //nsubjettiness massjump
	   /*if(SortedSubJets.size()>0){
	    double tau1_mj,tau2_mj,tau3_mj,tau4_mj;
	    JetPropsPseudo jp2(&sum);
	   tau1_mj = jp2.GetNsubjettiness(1, Njettiness::onepass_kt_axes, 1., varjets[bestjetindex2].user_index()/10.);
	   tau2_mj = jp2.GetNsubjettiness(2, Njettiness::onepass_kt_axes, 1., varjets[bestjetindex2].user_index()/10.);
	   tau3_mj = jp2.GetNsubjettiness(3, Njettiness::onepass_kt_axes, 1., varjets[bestjetindex2].user_index()/10.);
	   tau4_mj = jp2.GetNsubjettiness(4, Njettiness::onepass_kt_axes, 1., varjets[bestjetindex2].user_index()/10.);
	   Hist("tau1_massjump")->Fill(tau1_mj,weight);
	   if(Had_Tops[j].pt()>200) Hist("tau1_200_massjump")->Fill(tau1_mj,weight);
	   if(Had_Tops[j].pt()>500) Hist("tau1_500_massjump")->Fill(tau1_mj,weight);
	   if(Had_Tops[j].pt()>600) Hist("tau1_600_massjump")->Fill(tau1_mj,weight);
	   if(Had_Tops[j].pt()>800) Hist("tau1_800_massjump")->Fill(tau1_mj,weight);
	   if(Had_Tops[j].pt()>1000) Hist("tau1_1000_massjump")->Fill(tau1_mj,weight);
	   Hist("tau2_massjump")->Fill(tau2_mj,weight);
	   if(Had_Tops[j].pt()>200) Hist("tau2_200_massjump")->Fill(tau2_mj,weight);
	   if(Had_Tops[j].pt()>500) Hist("tau2_500_massjump")->Fill(tau2_mj,weight);
	   if(Had_Tops[j].pt()>600) Hist("tau2_600_massjump")->Fill(tau2_mj,weight);
	   if(Had_Tops[j].pt()>800) Hist("tau2_800_massjump")->Fill(tau2_mj,weight);
	   if(Had_Tops[j].pt()>1000) Hist("tau2_1000_massjump")->Fill(tau2_mj,weight);
	   Hist("tau3_massjump")->Fill(tau3_mj,weight);
	   if(Had_Tops[j].pt()>200) Hist("tau3_200_massjump")->Fill(tau3_mj,weight);
	   if(Had_Tops[j].pt()>500) Hist("tau3_500_massjump")->Fill(tau3_mj,weight);
	   if(Had_Tops[j].pt()>600) Hist("tau3_600_massjump")->Fill(tau3_mj,weight);
	   if(Had_Tops[j].pt()>800) Hist("tau3_800_massjump")->Fill(tau3_mj,weight);
	   if(Had_Tops[j].pt()>1000) Hist("tau3_1000_massjump")->Fill(tau3_mj,weight);
	   Hist("tau4_massjump")->Fill(tau4_mj,weight);
	   if(Had_Tops[j].pt()>200) Hist("tau4_200_massjump")->Fill(tau4_mj,weight);
	   if(Had_Tops[j].pt()>500) Hist("tau4_500_massjump")->Fill(tau4_mj,weight);
	   if(Had_Tops[j].pt()>600) Hist("tau4_600_massjump")->Fill(tau4_mj,weight);
	   if(Had_Tops[j].pt()>800) Hist("tau4_800_massjump")->Fill(tau4_mj,weight);
	   if(Had_Tops[j].pt()>1000) Hist("tau4_1000_massjump")->Fill(tau4_mj,weight);
	   Hist("tau2tau1_massjump")->Fill(tau2_mj/tau1_mj,weight);
	   if(Had_Tops[j].pt()>200)  Hist("tau2tau1_200_massjump")->Fill(tau2_mj/tau1_mj,weight);
	   if(Had_Tops[j].pt()>500)  Hist("tau2tau1_500_massjump")->Fill(tau2_mj/tau1_mj,weight);
	   if(Had_Tops[j].pt()>600)  Hist("tau2tau1_600_massjump")->Fill(tau2_mj/tau1_mj,weight);
	   if(Had_Tops[j].pt()>800)  Hist("tau2tau1_800_massjump")->Fill(tau2_mj/tau1_mj,weight);
	   if(Had_Tops[j].pt()>1000)  Hist("tau2tau1_1000_massjump")->Fill(tau2_mj/tau1_mj,weight);
	   Hist("tau3tau2_massjump")->Fill(tau3_mj/tau2_mj,weight);
	   if(Had_Tops[j].pt()>200)  Hist("tau3tau2_200_massjump")->Fill(tau3_mj/tau2_mj,weight);
	   if(Had_Tops[j].pt()>500)  Hist("tau3tau2_500_massjump")->Fill(tau3_mj/tau2_mj,weight);
	   if(Had_Tops[j].pt()>600)  Hist("tau3tau2_600_massjump")->Fill(tau3_mj/tau2_mj,weight);
	   if(Had_Tops[j].pt()>800)  Hist("tau3tau2_800_massjump")->Fill(tau3_mj/tau2_mj,weight);
	   if(Had_Tops[j].pt()>1000)  Hist("tau3tau2_1000_massjump")->Fill(tau3_mj/tau2_mj,weight);
	   }*/
	   //softdrop
	   fastjet::PseudoJet groomed_jet;
	   //  Softdrop->GetJet(jet,0.1,2.0,groomed_jet);
	   Hist("sd_mass")->Fill(groomed_jet.m(),weight);
	   if(Had_Tops[j].pt()>200) Hist("sd_mass200")->Fill(groomed_jet.m(),weight);
	   if(Had_Tops[j].pt()>500) Hist("sd_mass500")->Fill(groomed_jet.m(),weight);
	   if(Had_Tops[j].pt()>600) Hist("sd_mass600")->Fill(groomed_jet.m(),weight);
	   if(Had_Tops[j].pt()>800) Hist("sd_mass800")->Fill(groomed_jet.m(),weight);
	   if(Had_Tops[j].pt()>1000) Hist("sd_mass1000")->Fill(groomed_jet.m(),weight);
	   //if(groomed_jet.m()>150 && groomed_jet.m()<250)  Hist("pT_s1_tobi_tagged")->Fill(Had_Tops[j].pt(),weight);
	   //if(SortedSubJets2.size()>2 && groomed_jet.m()>150 &&  groomed_jet.m()<250 && mmin2>50)  Hist("pT_s1_tobi4_tagged")->Fill(Had_Tops[j].pt(),weight);
	   //  if(SortedSubJets2.size()>2 && SortedJets[bestjetindex2].m()>150 &&  SortedJets[bestjetindex2].m()<250 && mmin2>50 && varjets.size()>2)  Hist("pT_s1_tobi4_tagged")->Fill(Had_Tops[j].pt(),weight);
	   if(SortedSubJets2.size()>2 && SortedJets[bestjetindex2].m()>mtopLow &&  SortedJets[bestjetindex2].m()<mtopHigh  &&SortedSubJets2.at(0).pt()>30 && SortedSubJets2.at(1).pt()>30 &&   SortedSubJets2.at(0).pt()/SortedJets[bestjetindex2].pt()<0.8  &&tau3/tau2<0.7/*&&mmin2>50*/  )  Hist("pT_s1_tobi5_tagged")->Fill(Had_Tops[j].pt(),weight);
	     //if(CMSTopTagFull_pseudo_CA(jet,3.0,0.05,0.4,0.0004,mjet, nsubjets,mmin,subjets,CMSjet) && tau3/tau2<0.7) Hist("pT_s1_cms_nsub_tagged")->Fill(Had_Tops[j].pt(),weight);
	      if(SortedSubJets2.size()>2 && SortedJets[bestjetindex2].m()>mtopLow &&  SortedJets[bestjetindex2].m()<mtopHigh  &&SortedSubJets2.at(0).pt()>30 && SortedSubJets2.at(1).pt()>30 &&   SortedSubJets2.at(0).pt()/SortedJets[bestjetindex2].pt()<0.8 /*&&mmin2>50 */ ) for(int roc=0;roc<100;roc++){
	  if(tau3/tau2<roc/100.){
	    ((TH2D*)Hist("nsub_eff"))->Fill(Had_Tops[j].pt(),roc/100.,weight);
	       if(Had_Tops[j].pt()>200) Hist("nsub_eff200")->Fill(roc/100.,weight);
	       if(Had_Tops[j].pt()>400) Hist("nsub_eff400")->Fill(roc/100.,weight);
	       if(Had_Tops[j].pt()>600) Hist("nsub_eff600")->Fill(roc/100.,weight);
	       if(Had_Tops[j].pt()>800) Hist("nsub_eff800")->Fill(roc/100.,weight);
	  
	  }
		}
	  
	      if(SortedSubJets2.size()>2  &&SortedSubJets2.at(0).pt()>30 && SortedSubJets2.at(1).pt()>30 &&   SortedSubJets2.at(0).pt()/SortedJets[bestjetindex2].pt()<0.8&& mmin2>50)  for(int roc=0;roc<250;roc++) for(int roc2=0;roc2<roc;roc2++){
		    if(SortedJets[bestjetindex2].m()<roc && SortedJets[bestjetindex2].m()>roc2)  ((TH3D*)Hist("nsub_eff_mass"))->Fill(Had_Tops[j].pt(),roc,roc2,weight);
	      }
	     
	}
    }
    //for(int i=0;i<SortedJets.size();i++) Hist("Njets_norm")->Fill(SortedJets.at(i).perp(),weight);

    
    time1+=clock()-tstart;
  }
  

  if(!IsRealData && idVersion.Contains("QCD15to3000"))
  {
    
    if(weight>100000) weight=0;
    std::vector<GenParticle>* genparticles = calc->GetGenParticles();
    	fastjet::ClusterSequence clustersq,clustersq2;
	double subjetmass, mmin2;
	double distance;
	vector<fastjet::PseudoJet> varjets,fatjets,fatjets_backup;
	


	 EventCalc* calc = EventCalc::Instance();
  fastjet::JetDefinition *JetDef ;
  std::vector<fastjet::PseudoJet> SortedSubJets;
  TopJet topjet;
  //std::cout<<calc->GetEventNum()<<std::endl;
  JetProps jp(&topjet,calc->GetPFParticles());
  std::vector<fastjet::PseudoJet> jetpart = jp.Get_all_pfparticles();
  double ptmin(10.);
  // fastjet::JetDefinition jet_defCA;
   vector<fastjet::PseudoJet> inclusive_jetsCA;
  fastjet::JetDefinition jet_defCA2;
 
  HHTopTagger pluginAKT(mu, theta,min_r, max_r,rho,mw, HHTopTagger::CALIKE,fatjets);
     fastjet::JetDefinition jet_defCA(&pluginAKT);
    jet_defCA2=jet_defCA;
   
    //std::cout<<mu<<" "<<theta<<std::endl;
  //mass jump
  /*
  if(algo=="akt") {
    // std::cout<<"akt"<<std::endl;
    fastjet::JetDefinition jet_defCA(fastjet::antikt_algorithm,akt_r);
    jet_defCA2=jet_defCA;
    //normal
    }*/
  
  //if(algo=="varR" || algo=="massjump")  fastjet::JetDefinition jet_defCA(&pluginAKT);
 
   
  
  // fastjet::ClusterSequence clust_seqCA(jetpart, jet_defCA);
  //fastjet::ClusterSequenceArea clust_seq(jetpart,jet_defCA, area_def);
     fastjet::ClusterSequence clust_seqCA(jetpart, jet_defCA2);
    inclusive_jetsCA = clust_seqCA.inclusive_jets(ptmin);
  //vector<fastjet::PseudoJet> inclusive_jetsCA = clust_seqCA.inclusive_jets(ptmin);
    
  SortedSubJets = sorted_by_pt(inclusive_jetsCA);
   fatjets=pluginAKT.get_fatjets();
   std::vector<double> deltaR,deltapT,mj_wmass;
  deltaR=pluginAKT.get_deltaR();
  deltapT=pluginAKT.get_deltapT();
  mj_wmass=pluginAKT.get_mass();
  for(int o=0;o<mj_wmass.size();o++) Hist("mj_wmass")->Fill(mj_wmass[o],weight);
  for(int o=0;o<deltaR.size();o++) Hist("Cluster_deltaR")->Fill(deltaR[o],weight);
  for(int o=0;o<deltapT.size();o++) Hist("Cluster_deltapT")->Fill(deltapT[o],weight);
   fatjets_backup=fatjets;
   bool event1=true;
   for(int o=0;o<fatjets.size();o++) if(fatjets[o].user_index()!=-1) event1=false;
  if(event1) Hist("event1")->Fill(1,weight);
  else  Hist("event1")->Fill(3,weight);
   for(int o=0;o<fatjets.size();o++) if(fatjets[o].user_index()==-1) Hist("pT_jet1")->Fill(fatjets[o].perp(),weight);
   /*ClusterSequence bigjets_cs;
   bigjets_cs=pluginAKT.get_cs_fatjets();
   std::vector<fastjet::PseudoJet> big_jets;
   big_jets=bigjets_cs.inclusive_jets(ptmin);
   std::cout<<"number of FATJETS "<<big_jets.size()<<std::endl;*/
   // std::cout<<"*****"<<std::endl;

    std::vector<fastjet::PseudoJet> fatjets_comb, garbage;
    fastjet::PseudoJet testjet;
    /*       for(int o=0;o<fatjets.size();++o){
	 std::cout<<"fatjets "<<fatjets[o].perp()<<" phi "<<fatjets[o].phi()<<" user index "<<fatjets[o].user_index()<<std::endl;
      //  if(fatjets[o].user_index()!=-1) fatjets_comb.push_back(fatjets[o]);
      //else garbage.push_back(fatjets[o]);
           for(int L=0;L<clust_seqCA.jets().size();L++) 
	if(clust_seqCA.jets()[L].pt()==fatjets[o].pt()) {
	  std::cout<<"Jet number "<<L<<std::endl;
	  
	  //fatjets_comb.push_back(testJet);
	  }
	  }*/

  std::vector<int> jetindex[fatjets.size()];




       for(int o=0;o<fatjets.size();o++){
	 for(int L=0;L<clust_seqCA.jets().size();L++)  if(clust_seqCA.jets()[L].pt()==fatjets[o].pt()) jetindex[o].push_back(L);
	 jetindex[o].push_back(fatjets[o].user_index());
	
	 
	    
       }


       int index=0;
       std::vector<fastjet::PseudoJet> subjets[fatjets.size()];
       /* for(int o=0;o<fatjets.size();o++){
      testjet=fatjets[o];
      index++;
      bool taken=false;
      bool taken2=false;
      for(int u=o+1;u<fatjets.size();u++){
	
	if(fatjets[o].user_index()==fatjets[u].user_index() && fatjets[o].user_index()!=-1 &&  fatjets[o].user_index()>20) {
	  //  std::cout<<"FATJETS "<<fatjets[o].perp()<<" phi "<<fatjets[o].phi()<<" user index "<<fatjets[o].user_index()<<std::endl;
	  fatjets[u].set_user_index(index);
	   subjets[index-1].push_back(fatjets[u]);
	  testjet.operator+=(fatjets[u]);
	  for(int h=0;h<fatjets.size();h++){
	    if(jetindex[u].at(0)==fatjets[h].user_index()){
	      fatjets[h].set_user_index(index);
	      subjets[index-1].push_back(fatjets[h]);
	      testjet.operator+=(fatjets[h]);
	    }

	  }
	  // testjet.set_user_index(0);
	  
	}

	
      }
      if(fatjets[o].user_index()!=-1) for(int g=0;g<fatjets.size();g++){
	if(jetindex[g].at(0)==fatjets[o].user_index()) for(int b=0;b<fatjets.size();b++) if(fatjets_backup[b].user_index()==jetindex[g].at(1) && o!=b && fatjets[b].user_index()<20) taken=true;
	}
      if( fatjets[o].user_index()>20 && !taken) {
	testjet.operator+=(clust_seqCA.jets()[fatjets[o].user_index()]);
	subjets[index-1].push_back(clust_seqCA.jets()[fatjets[o].user_index()]);
	subjets[index-1][subjets[index-1].size()-1].set_user_index(index);
	taken2=true;
	//std::cout<<"TEST-------------------------------------------------------------------------"<<std::endl;
      }
      if(!taken2 && fatjets[o].user_index()!=-1){
      for(int g=0;g<fatjets.size();g++){
	std::cout<<"merge------------------------------------------"<<std::endl;
	if(jetindex[g].at(0)==fatjets[o].user_index() && fatjets[g].user_index()>0) {
	     //   std::cout<<"MERGE********************************************** "<<fatjets[g].user_index()-1<<" "<<fatjets_comb.size()<<std::endl;
	     //fatjets_comb[fatjets[g].user_index()-1].operator+=(fatjets[o]);
	  if(fatjets.size()>fatjets[g].user_index() ) subjets[fatjets[g].user_index()-1].push_back(fatjets[o]);
	     fatjets[o].set_user_index(fatjets[g].user_index());
	     
	    		 }
      }}
				   
      if( fatjets[o].user_index()!=-1)for(int g=o;g<fatjets.size();g++) if(clust_seqCA.jets()[fatjets[o].user_index()].pt()==fatjets[g].pt() && fatjets[g].user_index()!=-1) fatjets[g].set_user_index(index);
      if(fatjets[o].user_index()>20 || fatjets[o].user_index()<0) {
	//	fatjets_comb.push_back(testjet);

	//	fatjets_comb[fatjets_comb.size()-1].set_user_index(index);
	fatjets[o].set_user_index(index);
	subjets[index-1].push_back(fatjets[o]);
      }
    
     }

    //bulid fatjets
    int index2=0;
    for(int o=0;o<fatjets.size();o++){
      index2++;
      fastjet::PseudoJet testjet=fatjets[o];
      for(int b=0;b<fatjets.size();b++)
	if(fatjets[o].user_index()==fatjets[b].user_index() && o!=b) {
	testjet.operator+=(fatjets[b]);
	//	std::cout<<"FUCK"<<std::endl;
      
      }
      if(fatjets[o].user_index()-1>=o){
      fatjets_comb.push_back(testjet);
      fatjets_comb[fatjets_comb.size()-1].set_user_index(fatjets[o].user_index());
      //std::cout<<"TOBIAS   "<< fatjets_comb[fatjets_comb.size()-1].perp()<<std::endl;
      }
      }*/




       /* index=0;
       int index3=0;
       bool setjet;
       while(index3<fatjets.size()){
	 //std::cout<<"0   "<<index3<<std::endl;
	 fastjet::PseudoJet testjet;
       std::vector<int> liste;
       setjet=false;
       //std::cout<<"1"<<std::endl;
       index++;
       for(int o=0;o<fatjets.size();o++){
	 //std::cout<<"2"<<std::endl;
	 if(fatjets[o].user_index()!=-99 && !setjet) {
	   liste.push_back(jetindex[o].at(0));
	   index3++;
	   setjet=true;
	   fatjets[o].set_user_index(-99);
	 }
	 for(int p=0;p<liste.size();p++){
	   if(fatjets[o].user_index()==liste[p]) {
	     liste.push_back(jetindex[o].at(0));
	     fatjets[o].set_user_index(-99);
	     index3++;
	 }
	 }
	 //std::cout<<"3"<<std::endl;
	

       }
       if(setjet){
	 for(int o=0;o<liste.size();o++){
	   if(subjets[index-1].size()==0){
	   testjet.operator+=(clust_seqCA.jets()[liste[o]]);
	   subjets[index-1].push_back(clust_seqCA.jets()[liste[o]]);}
	   else if(true) {
	     testjet.operator+=(clust_seqCA.jets()[liste[o]]);
	     subjets[index-1].push_back(clust_seqCA.jets()[liste[o]]);
	   }
	 }
	 //std::cout<<"4"<<std::endl;
	 //index3++;
	 fatjets_comb.push_back(testjet);
	 fatjets_comb[fatjets_comb.size()-1].set_user_index(index);
	 subjets[fatjets_comb.size()-1]=sorted_by_pt(subjets[fatjets_comb.size()-1]);
       }
       // for(int o=0;o<liste.size();o++) std::cout<<"LISTE   "<<liste[o]<<std::endl;
       }*/

       /*index=0;
       for(int o=0;o<fatjets.size();o++){
	 //std::cout<<"TEST5"<<std::endl; 
	 if(fatjets[o].user_index()!=-99 && fatjets[o].pt()>ptmin){
	   index++;
	   fastjet::PseudoJet testjet=fatjets[o];
	   // std::cout<<"TEST2"<<std::endl;
	   subjets[index-1].push_back(clust_seqCA.jets()[jetindex[o].at(0)]);
	 for(int t=0;t<fatjets.size();t++) {
	   if(fatjets[o].user_index()==fatjets[t].user_index() && t!=o && fatjets[o].user_index()!=-1&& fatjets[o].pt()>ptmin){
	      testjet.operator+=(fatjets[t]);
	     //std::cout<<"TEST3"<<std::endl;
	     fatjets[t].set_user_index(-99);
	    
	      subjets[index-1].push_back(clust_seqCA.jets()[jetindex[t].at(0)]);
	   }
	 }
	 fatjets[o].set_user_index(-99);
	 fatjets_comb.push_back(testjet);
	  fatjets_comb[fatjets_comb.size()-1].set_user_index(index);
	  subjets[fatjets_comb.size()-1]=sorted_by_pt(subjets[fatjets_comb.size()-1]);
	 }
	 //std::cout<<"TEST4"<<std::endl;
	 }*/


 index=0;
 std::vector<fastjet::PseudoJet> jet_radiation, jet_beam;
       for(int o=0;o<fatjets.size();o++){
	 //std::cout<<"TEST5"<<std::endl; 
	 if(fatjets[o].user_index()!=-99 && fatjets[o].pt()>ptmin){
	   index++;
	   fastjet::PseudoJet testjet=fatjets[o];
	   // std::cout<<"TEST2"<<std::endl;
	   subjets[index-1].push_back(clust_seqCA.jets()[jetindex[o].at(0)]);
	 for(int t=0;t<fatjets.size();t++) {
	   if(fatjets[o].user_index()==fatjets[t].user_index() && t!=o && fatjets[o].user_index()!=-1&& fatjets[o].pt()>ptmin&& fatjets[o].user_index()!=-2){
	      testjet.operator+=(fatjets[t]);
	     //std::cout<<"TEST3"<<std::endl;
	     fatjets[t].set_user_index(-99);
	    
	      subjets[index-1].push_back(clust_seqCA.jets()[jetindex[t].at(0)]);
	   }
	 }
	
	 for(int k=0;k<fatjets.size();k++){ 
	   if(fatjets[k].user_index()/100.==fatjets[o].user_index()){ 
	     fatjets_comb.push_back(fatjets[k]);
	     fatjets[o].set_user_index(-99);
	     fatjets_comb[fatjets_comb.size()-1].set_user_index(index);
	     subjets[fatjets_comb.size()-1]=sorted_by_pt(subjets[fatjets_comb.size()-1]);
	   }
	   else{
	     // std::cout<<"USER INDEX"<<fatjets[k].user_index()<<std::endl;
	   if(fatjets[k].user_index()==-1) jet_beam.push_back(fatjets[k]);
	   if(fatjets[k].user_index()==-2) jet_radiation.push_back(fatjets[k]);
	   //std::cout<<"TEST4"<<std::endl;
	   }
	 }

	
	 }
       }
       Hist("NJets-1")->Fill(jet_beam.size(),weight);
       Hist("NJets-2")->Fill(jet_radiation.size(),weight);
       for(int y=0;y<jet_beam.size();y++) Hist("pT_beam")->Fill(jet_beam[y].pt(),weight);
       for(int y=0;y<jet_radiation.size();y++) Hist("pT_radiation")->Fill(jet_radiation[y].pt(),weight);
       for(int y=0;y<fatjets_comb.size();y++) Hist("pT_fatjets")->Fill(fatjets_comb[y].pt(),weight);








    std::vector<fastjet::PseudoJet> fatjet_constituents[fatjets_comb.size()];
   for(int o=0;o<fatjets_comb.size();o++){
   for(int p=0;p<subjets[fatjets_comb[o].user_index()-1].size();p++)
     for(int k=0;k<subjets[fatjets_comb[o].user_index()-1][p].constituents().size();k++)
       fatjet_constituents[o].push_back(subjets[fatjets_comb[o].user_index()-1][p].constituents().at(k));
 }
	     
   // std::cout<<" number of jets "<<fatjets_comb.size()<<std::endl;     
   //std::cout<<"--------"<<std::endl;
   /*
for(int o=0;o<fatjets_comb.size();o++)  std::cout<<"FATJETS comb "<<fatjets_comb[o].perp()<<" phi "<<fatjets_comb[o].phi()<<" user index "<<fatjets_comb[o].user_index()<<std::endl;
for(int o=0;o<fatjets.size();o++)  std::cout<<"FATJETS "<<fatjets[o].perp()<<" phi "<<fatjets[o].phi()<<" user index "<<fatjets[o].user_index()<<std::endl;
 for(int o=0;o<fatjets_comb.size();o++){
    std::cout<<"FATJET "<<fatjets_comb[o].perp()<<" phi "<<fatjets_comb[o].phi()<<" user index "<<fatjets_comb[o].user_index()<<std::endl;
    for(int k=0;k<subjets[fatjets_comb[o].user_index()-1].size();k++) std::cout<<"subjet "<<subjets[fatjets_comb[o].user_index()-1][k].perp()<<" phi "<<subjets[fatjets_comb[o].user_index()-1][k].phi()<<" user index "<<subjets[fatjets_comb[o].user_index()-1][k].user_index()<<std::endl;
 }

  for(int o=0;o<SortedSubJets.size();++o){
    std::cout<<SortedSubJets[o].perp()<<std::endl;
    }*/


  // SortedJets =  fatjets_comb;
  // cout << "Ran " << jet_defCA.description() << endl;

  //  std::cout<<"bla2"<<std::endl;
  

  //merge subjets to fatjets
  /* vector<fastjet::PseudoJet> inclusive_jets_varR;
  std::vector<fastjet::PseudoJet> SortedJets;
  VariableRPlugin pluginAKT2(rho, min_r,0.8, VariableRPlugin::AKTLIKE);
  fastjet::JetDefinition jet_defCA3(&pluginAKT2);
  //std::vector<fastjet::PseudoJet> jetpart_var=SortedSubJets;
  std::vector<fastjet::PseudoJet> jetpart_var=fatjets_comb;
  fastjet::ClusterSequence clust_seq_varR(jetpart_var, jet_defCA3);*/
  //inclusive_jets_varR = clust_seq_varR.inclusive_jets(ptmin);
  // inclusive_jets_varR.push_back(garbage);
  // std::cout<<"!!!!!!!!!!!!!"<<garbage.size()<<std::endl;
  //for(int o=0;o<garbage.size();o++) inclusive_jets_varR.push_back(garbage[o]); 
    std::vector<fastjet::PseudoJet> SortedJets;
    // SortedJets = sorted_by_pt(inclusive_jets_varR) ;
  SortedJets =  fatjets_comb;

  /*  if(algo=="massjump") {
    ClusteringVetoPlugin pluginAKT(mu, theta, max_r, ClusteringVetoPlugin::AKTLIKE);
     fastjet::JetDefinition jet_defCA(&pluginAKT);
    jet_defCA2=jet_defCA;
  }//mass jump

  if(algo=="hhtoptagger") {
    HHTopTagger pluginAKT(mu, theta,min_r, max_r,rho, HHTopTagger::AKTLIKE,fatjets);
     fastjet::JetDefinition jet_defCA(&pluginAKT);
    jet_defCA2=jet_defCA;
    //std::cout<<mu<<" "<<theta<<std::endl;
  }//mass jump
  
  if(algo=="akt") {
    // std::cout<<"akt"<<std::endl;
    fastjet::JetDefinition jet_defCA(fastjet::antikt_algorithm,akt_r);
    jet_defCA2=jet_defCA;
    //normal
    }*/
  //if(algo=="varR" || algo=="massjump")  fastjet::JetDefinition jet_defCA(&pluginAKT);
 






  for(int i=0;i<SortedJets.size();i++){
   
     std::vector<fastjet::PseudoJet> pfcands =  fatjet_constituents[i];
     double oldR=0;
     
     for(int j=0;j<pfcands.size();j++){
       double R=SortedJets[i].delta_R(pfcands[j]);
       // std::cout<<"pf distance "<<R<<std::endl;
	 if(R>oldR){
	  
	   oldR=R;
	 }
       }
     // std::cout<<"maxR "<<oldR<<std::endl;
     SortedJets[i].set_user_index(int(oldR*10));
     //  std::cout<<"maxR "<< SortedJets[i].user_index()<<std::endl;
     //  std::cout<<"pt "<< SortedJets[i].perp()<<std::endl;
     }
  // std::vector<fastjet::PseudoJet> pfcands = SortedJets[0].pieces();
  //std::cout<<"test2"<<std::endl;
  //  delete JetDef;

  varjets=SortedJets;
	
	
	//	std::cout<<"bla"<<std::endl;
        double minDeltaR2=10000;
	int bestjetindex2=-1;
	//	std::cout<<"Njets "<<varjets.size()<<std::endl;
	/*      for(unsigned int i=0; i<varjets.size(); ++i)
	{
	  double DeltaR2=sqrt(pow(Had_Tops[j].phi()-varjets[i].phi_std(),2)+pow(Had_Tops[j].eta()-varjets[i].pseudorapidity(),2));
	 
	  if(DeltaR2<minDeltaR2)
	  {
	    minDeltaR2=DeltaR2;
	    bestjetindex2=i;
	  }
	  }*/
	//	Hist("NJets")->Fill(varjets.size(),weight);
	//	Hist("NJetstop")->Fill(bcc->topjets->size(),weight);

	for(unsigned int j=0; j<genparticles->size();j++){
	  if (abs(genparticles->at(j).pdgId())<=6 || abs(genparticles->at(j).pdgId())==21){
	    if(genparticles->at(j).pt()>100) {
	      Hist("pT_s1_all")->Fill(genparticles->at(j).pt(),weight);
	      std::cout<<"particle"<<std::endl;}
	    if(genparticles->at(j).pt()>200) Hist("nsub_eff200_norm")->Fill(1,weight);
	    if(genparticles->at(j).pt()>400) Hist("nsub_eff400_norm")->Fill(1,weight);
	    if(genparticles->at(j).pt()>600) Hist("nsub_eff600_norm")->Fill(1,weight);
	    if(genparticles->at(j).pt()>800) Hist("nsub_eff800_norm")->Fill(1,weight);
	    for(int roc=0;roc<100;roc++)if(genparticles->at(j).pt()>100) {((TH2D*)Hist("nsub_eff_norm"))->Fill(genparticles->at(j).pt(),roc/100.,weight);}
	    if(genparticles->at(j).pt()>100) for(int roc=0;roc<250;roc++)for(int roc2=0;roc2<250;roc2++)  {((TH3D*)Hist("nsub_eff_mass_norm"))->Fill(genparticles->at(j).pt(),roc,roc2,weight); }
	  }
	}

	

	for(unsigned int i=0; i<bcc->topjets->size();i++) Hist("pT_topjets")->Fill(bcc->topjets->at(i).pt(),weight);
   for(unsigned int i=0; i<varjets.size(); ++i)
   {

     Hist("NJets")->Fill(varjets.size(),weight);
     Hist("NJetstop")->Fill(bcc->topjets->size(),weight);
     if(varjets.at(i).perp()>200 && varjets.at(i).perp()<400) {
       Hist("NJets200")->Fill(varjets.size(),weight);
     Hist("NJetstop200")->Fill(bcc->topjets->size(),weight);
     }
     if(varjets.at(i).perp()>400 && varjets.at(i).perp()<600) {
       Hist("NJets400")->Fill(varjets.size(),weight);
       Hist("NJetstop400")->Fill(bcc->topjets->size(),weight);
     } 
     if(varjets.at(i).perp()>600 && varjets.at(i).perp()<800) {
       Hist("NJets600")->Fill(varjets.size(),weight);
     Hist("NJetstop600")->Fill(bcc->topjets->size(),weight);
     }
     //minDeltaR=10000;
     double highestPt=-1;
     bestjetindex=-1;
     Hist("Njets_norm")->Fill(varjets.at(i).perp(),weight);
     for(int t=0;t<varjets.size();t++) /*if(varjets.at(t).perp()>varjets.at(i).perp())*/ Hist("Njets_var")->Fill(varjets.at(i).perp(),weight);
     Hist("pT_jets")->Fill(varjets[i].pt(),weight);
     for(unsigned int j=0; j<genparticles->size();j++)
     {
       if (abs(genparticles->at(j).pdgId())<=6 || abs(genparticles->at(j).pdgId())==21)
       {
	 double DeltaR2=sqrt(pow(genparticles->at(j).phi()-varjets[i].phi_std(),2)+pow(genparticles->at(j).eta()-varjets[i].pseudorapidity(),2));
	 if (DeltaR2<varjets[i].user_index()/10. && genparticles->at(j).pt()>100 /* heighestpt&& fatjets_comb[i].perp()>200*/)
	 {
	  bestjetindex=j;
	  highestPt=genparticles->at(j).pt();
	  //minDeltaR=bcc->toptagjets->at(i).deltaR(genparticles->at(j));
	 }
       }
     }


     if(calc->GetEventNum()==4251741){ //jetdisplay 4252236 4251318 4251364
       for(int o=0;o<fatjets_backup.size();o++) 
     if(fatjets_backup[o].user_index()!=-1)   ((TH2D*)Hist("JetDisplay"))->Fill(fatjets[o].phi_std(),fatjets[o].eta(),fatjets[o].perp());
     else ((TH2D*)Hist("JetDisplay1"))->Fill(fatjets[o].phi_std(),fatjets[o].eta(),fatjets[o].perp());
   for(int o=0;o<fatjets_comb.size();o++) {
      ((TH2D*)Hist("JetDisplay_fatjet"))->Fill(fatjets_comb[o].phi_std(),fatjets_comb[o].eta(),fatjets_comb[o].perp());
      for(int h=0;h<fatjet_constituents[o].size();h++) ((TH2D*)Hist("JetDisplay_pf"))->Fill(fatjet_constituents[o].at(h).phi_std(),fatjet_constituents[o].at(h).eta(),fatjet_constituents[o].at(h).perp());
      
   }
   // ((TH2D*)Hist("JetDisplay_top"))->Fill(Had_Tops[j].phi(),Had_Tops[j].eta(),Had_Tops[j].pt());
   //for(int o=0;o<decay_products.size();o++) ((TH2D*)Hist("JetDisplay_decay"))->Fill(decay_products[o].phi(),decay_products[o].eta(),decay_products[o].pt());
 }



     
     if (bestjetindex>-1)
     {
       if(subjets[fatjets_comb[i].user_index()-1].size()==1 && !event1) Hist("match")->Fill(1,weight);
       else Hist("match")->Fill(3,weight);
       Hist("nsubjets_massjump")->Fill(subjets[fatjets_comb[i].user_index()-1].size(),weight);
       if(genparticles->at(bestjetindex).pt()>200 && genparticles->at(bestjetindex).pt()<400)  Hist("nsubjets_massjump200")->Fill(subjets[fatjets_comb[i].user_index()-1].size(),weight);
       if(genparticles->at(bestjetindex).pt()>400 && genparticles->at(bestjetindex).pt()<600)  Hist("nsubjets_massjump400")->Fill(subjets[fatjets_comb[i].user_index()-1].size(),weight);
       if(genparticles->at(bestjetindex).pt()>600 && genparticles->at(bestjetindex).pt()<800)  Hist("nsubjets_massjump600")->Fill(subjets[fatjets_comb[i].user_index()-1].size(),weight);
       if(genparticles->at(bestjetindex).pt()>800 && genparticles->at(bestjetindex).pt()<1000)  Hist("nsubjets_massjump800")->Fill(subjets[fatjets_comb[i].user_index()-1].size(),weight);
       if(genparticles->at(bestjetindex).pt()>1000  && genparticles->at(bestjetindex).pt()<1200)  Hist("nsubjets_massjump1000")->Fill(subjets[fatjets_comb[i].user_index()-1].size(),weight); 
       SortedSubJets=sorted_by_pt(subjets[fatjets_comb[i].user_index()-1]);
       double mmin2=0;
	  double wmass_rec=0;
	  double m12=0;
	  if(SortedSubJets.size()>2){
	  double m01 = 0;
	  m01=(SortedSubJets[0]+SortedSubJets[1]).m();
	  double m02 = 0;
	  m02=(SortedSubJets[0]+SortedSubJets[2]).m();
	  double m12 = 0; 
	  m12 = (SortedSubJets[1]+SortedSubJets[2]).m();
	  Hist("subjet01_massjump")->Fill(m01,weight);
	  Hist("subjet02_massjump")->Fill(m02,weight);
	  Hist("subjet12_massjump")->Fill(m12,weight);
	  double m03=0;
	  double m13=0;
	  double m23=0;
	  if(SortedSubJets.size()>3){
	  m03=(SortedSubJets[0]+SortedSubJets[3]).m();
	  m13=(SortedSubJets[1]+SortedSubJets[3]).m();
	  m23=(SortedSubJets[2]+SortedSubJets[3]).m();
	  Hist("subjet03_massjump")->Fill(m03,weight);
	  Hist("subjet13_massjump")->Fill(m13,weight);
	  Hist("subjet23_massjump")->Fill(m23,weight);
	  double deltaW, deltaW1,deltaW2,deltaW3,deltaW4,deltaW5;
	  deltaW=abs(80.4-m01);
	  deltaW1=abs(80.4-m02);
	  deltaW2=abs(80.4-m12);
	  deltaW3=abs(80.4-m03);
	  deltaW4=abs(80.4-m13);
	  deltaW5=abs(80.4-m23);
	  if(deltaW<deltaW1 && deltaW<deltaW2 && deltaW<deltaW3 && deltaW<deltaW4 && deltaW<deltaW5) wmass_rec=m01;
	  if(deltaW1<deltaW && deltaW1<deltaW2 && deltaW1<deltaW3&& deltaW1<deltaW4 && deltaW1<deltaW5) wmass_rec=m02; 
	  if(deltaW2<deltaW && deltaW2<deltaW1&& deltaW2<deltaW3&& deltaW2<deltaW4 && deltaW2<deltaW5)  wmass_rec=m12;
	  if(deltaW3<deltaW  && deltaW3<deltaW1&& deltaW3<deltaW2&& deltaW3<deltaW4 && deltaW3<deltaW5)   wmass_rec=m03;
	  if(deltaW4<deltaW  && deltaW4<deltaW1&& deltaW4<deltaW2&& deltaW4<deltaW3 && deltaW4<deltaW5)   wmass_rec=m13;
	  if(deltaW5<deltaW  && deltaW5<deltaW1&& deltaW5<deltaW2&& deltaW5<deltaW4 && deltaW5<deltaW3)   wmass_rec=m23; 
	  Hist("Wmass")->Fill(wmass_rec,weight);
	  
	  }
	  else{
	  double deltaW, deltaW1,deltaW2;
	  deltaW=abs(80.4-m01);
	  deltaW1=abs(80.4-m02);
	  deltaW2=abs(80.4-m12);
	  if(deltaW<deltaW1 && deltaW<deltaW2) wmass_rec=m01;
	  if(deltaW1<deltaW && deltaW1<deltaW2) wmass_rec=m02;
	  if(deltaW2<deltaW && deltaW2<deltaW1) wmass_rec=m12;
	  Hist("Wmass")->Fill(wmass_rec,weight);
	  }
	  mmin2 = std::min(m01,std::min(m02,m12));
	  if(genparticles->at(bestjetindex).pt()>200 && genparticles->at(bestjetindex).pt()<400) Hist("massjump_mmin200")->Fill(mmin2,weight);
	  if(genparticles->at(bestjetindex).pt()>400 && genparticles->at(bestjetindex).pt()<600) Hist("massjump_mmin400")->Fill(mmin2,weight);
	  if(genparticles->at(bestjetindex).pt()>600 && genparticles->at(bestjetindex).pt()<800) Hist("massjump_mmin600")->Fill(mmin2,weight);
	  if(genparticles->at(bestjetindex).pt()>800 && genparticles->at(bestjetindex).pt()<1000) Hist("massjump_mmin800")->Fill(mmin2,weight);
	  if(genparticles->at(bestjetindex).pt()>1000 && genparticles->at(bestjetindex).pt()<1200) Hist("massjump_mmin1000")->Fill(mmin2,weight);
	  }
	  for (unsigned int bk =0; bk<=3; ++bk)
    {
      if (SortedSubJets.size()> bk)
	{
	  
	 
	  TString hname = TString::Format("pT_subjet%d", bk+1);
	  Hist(hname)->Fill(SortedSubJets.at(bk).pt(),weight);
	  hname = TString::Format("pT_subjetfrac%d", bk+1);
	  Hist(hname)->Fill(SortedSubJets.at(bk).pt()/varjets[i].pt(),weight);
	  TString hname_ly = TString::Format("pT_subjet%d_ly", bk+1);
	  Hist(hname_ly)->Fill(SortedSubJets.at(bk).pt(),weight);
	  TString hname_eta = TString::Format("eta_subjet%d", bk+1);
	  Hist(hname_eta)->Fill(SortedSubJets.at(bk).eta(),weight);
	  TString hname_eta_ly = TString::Format("eta_subjet%d_ly", bk+1);
	  Hist(hname_eta_ly)->Fill(SortedSubJets.at(bk).eta(),weight);
	  TString hname_phi = TString::Format("phi_subjet%d", bk+1);
	  Hist(hname_phi)->Fill(SortedSubJets.at(bk).phi(),weight);
	  TString hname_phi_ly = TString::Format("phi_subjet%d_ly", bk+1);
	  Hist(hname_phi_ly)->Fill(SortedSubJets.at(bk).phi(),weight);

	}
    }

	  if(SortedSubJets.size()>2)  Hist("pT_s1_tobi_tagged")->Fill(genparticles->at(bestjetindex).pt(),weight);
	  if(varjets[i].m()>mtopLow &&  varjets[i].m()<mtopHigh)  Hist("pT_s1_tobi2_tagged")->Fill(genparticles->at(bestjetindex).pt(),weight);

       /* vector<fastjet::PseudoJet> inclusive_subjetsCA;
       std::vector<fastjet::PseudoJet> jetpart2 = varjets[i].constituents();
       ClusteringVetoPlugin pluginAKT(mu, theta, max_r, ClusteringVetoPlugin::AKTLIKE);
       fastjet::JetDefinition jet_defCA2(&pluginAKT);
       fastjet::ClusterSequence clust_seqCA2(jetpart2, jet_defCA2);
       inclusive_subjetsCA = clust_seqCA2.inclusive_jets(ptmin);
       std::vector<fastjet::PseudoJet> SortedSubJets = sorted_by_pt(inclusive_subjetsCA);
       std::cout<<SortedSubJets.size()<<std::endl;
       //if(SortedSubJets.size()>0)if(SortedSubJets[0].perp()>500) Hist("mjet_massjump")->Fill(SortedSubJets[0].m(),weight);
       fastjet::PseudoJet sum=SortedSubJets[0];
       for(int mj=1;mj<SortedSubJets.size();mj++) {
	 sum.operator+=(SortedSubJets[mj]);
       }
       if(genparticles->at(bestjetindex).pt()>200) Hist("mjet_massjump200")->Fill(sum.m(),weight);
       if(genparticles->at(bestjetindex).pt()>500) Hist("mjet_massjump500")->Fill(sum.m(),weight);
       if(genparticles->at(bestjetindex).pt()>600) Hist("mjet_massjump600")->Fill(sum.m(),weight);
       if(genparticles->at(bestjetindex).pt()>800) Hist("mjet_massjump800")->Fill(sum.m(),weight);
       if(genparticles->at(bestjetindex).pt()>1000) Hist("mjet_massjump1000")->Fill(sum.m(),weight);
       std::cout<<sum.m()<<std::endl;
       Hist("nsubjets_massjump")->Fill(SortedSubJets.size(),weight);
       if(SortedSubJets.size()>2)  Hist("pT_s1_tobi_tagged")->Fill(genparticles->at(bestjetindex).pt(),weight);
       if(SortedSubJets.size()>2 && varjets[i].m()>150 &&  varjets[i].m()<250)  Hist("pT_s1_tobi2_tagged")->Fill(genparticles->at(bestjetindex).pt(),weight);
      
        	   //calculating mmin for new subjets
	  double mmin2=0;
	  double wmass_rec=0;
	  if(SortedSubJets.size()>2){
	  double m01 = 0;
	  m01=(SortedSubJets[0]+SortedSubJets[1]).m();
	  double m02 = 0;
	  m02=(SortedSubJets[0]+SortedSubJets[2]).m();
	  double m12 = 0; 
	  m12 = (SortedSubJets[1]+SortedSubJets[2]).m();
	  Hist("subjet01_massjump")->Fill(m01,weight);
	  Hist("subjet02_massjump")->Fill(m02,weight);
	  Hist("subjet12_massjump")->Fill(m12,weight);
	  double m03=0;
	  double m13=0;
	  double m23=0;
	  if(SortedSubJets.size()>3){
	  m03=(SortedSubJets[0]+SortedSubJets[3]).m();
	  m13=(SortedSubJets[1]+SortedSubJets[3]).m();
	  m23=(SortedSubJets[2]+SortedSubJets[3]).m();
	  Hist("subjet03_massjump")->Fill(m03,weight);
	  Hist("subjet13_massjump")->Fill(m13,weight);
	  Hist("subjet23_massjump")->Fill(m23,weight);
	  double deltaW, deltaW1,deltaW2,deltaW3,deltaW4,deltaW5;
	  deltaW=abs(80.4-m01);
	  deltaW1=abs(80.4-m02);
	  deltaW2=abs(80.4-m12);
	  deltaW3=abs(80.4-m03);
	  deltaW4=abs(80.4-m13);
	  deltaW5=abs(80.4-m23);
	  if(deltaW<deltaW1 && deltaW<deltaW2 && deltaW<deltaW3 && deltaW<deltaW4 && deltaW<deltaW5) wmass_rec=m01;
	  if(deltaW1<deltaW && deltaW1<deltaW2 && deltaW1<deltaW3&& deltaW1<deltaW4 && deltaW1<deltaW5) wmass_rec=m02; 
	  if(deltaW2<deltaW && deltaW2<deltaW1&& deltaW2<deltaW3&& deltaW2<deltaW4 && deltaW2<deltaW5)  wmass_rec=m12;
	  if(deltaW3<deltaW  && deltaW3<deltaW1&& deltaW3<deltaW2&& deltaW3<deltaW4 && deltaW3<deltaW5)   wmass_rec=m03;
	  if(deltaW4<deltaW  && deltaW4<deltaW1&& deltaW4<deltaW2&& deltaW4<deltaW3 && deltaW4<deltaW5)   wmass_rec=m13;
	  if(deltaW5<deltaW  && deltaW5<deltaW1&& deltaW5<deltaW2&& deltaW5<deltaW4 && deltaW5<deltaW3)   wmass_rec=m23; 
	  Hist("Wmass")->Fill(wmass_rec,weight);
	  
	  }
	  else{
	  double deltaW, deltaW1,deltaW2;
	  deltaW=abs(80.4-m01);
	  deltaW1=abs(80.4-m02);
	  deltaW2=abs(80.4-m12);
	  if(deltaW<deltaW1 && deltaW<deltaW2) wmass_rec=m01;
	  if(deltaW1<deltaW && deltaW1<deltaW2) wmass_rec=m02;
	  if(deltaW2<deltaW && deltaW2<deltaW1) wmass_rec=m12;
	  Hist("Wmass")->Fill(wmass_rec,weight);
	  }
	  mmin2 = std::min(m01,std::min(m02,m12));
	  Hist("massjump_mmin")->Fill(mmin2,weight);
	  }*/
	  if(genparticles->at(bestjetindex).pt()>200 && genparticles->at(bestjetindex).pt()<400)  Hist("pT_fraction1_200")->Fill(SortedSubJets.at(0).pt()/varjets[i].pt(),weight);
	  if(genparticles->at(bestjetindex).pt()>400 && genparticles->at(bestjetindex).pt()<600)  Hist("pT_fraction1_400")->Fill(SortedSubJets.at(0).pt()/varjets[i].pt(),weight);
	  if(genparticles->at(bestjetindex).pt()>600 && genparticles->at(bestjetindex).pt()<800)  Hist("pT_fraction1_600")->Fill(SortedSubJets.at(0).pt()/varjets[i].pt(),weight);
	  if(genparticles->at(bestjetindex).pt()>800 && genparticles->at(bestjetindex).pt()<1000)  Hist("pT_fraction1_800")->Fill(SortedSubJets.at(0).pt()/varjets[i].pt(),weight);
	   if(genparticles->at(bestjetindex).pt()>1000 && genparticles->at(bestjetindex).pt()<1200)  Hist("pT_fraction1_1000")->Fill(SortedSubJets.at(0).pt()/varjets[i].pt(),weight);
	  if(SortedSubJets.size()>2 && varjets[i].m()>mtopLow &&  varjets[i].m()<mtopHigh)  Hist("pT_s1_tobi3_tagged")->Fill(genparticles->at(bestjetindex).pt(),weight);
	  if(SortedSubJets.size()>2 && varjets[i].m()>mtopLow &&  varjets[i].m()<mtopHigh    &&SortedSubJets.at(0).pt()>30 &&SortedSubJets.at(1).pt()>30&&  SortedSubJets.at(0).pt()/varjets[i].pt()<0.8 /*&&mmin2>50*/)  Hist("pT_s1_tobi6_tagged")->Fill(genparticles->at(bestjetindex).pt(),weight);
       fastjet::PseudoJet jet=varjets.at(i);
       ((TH2D*)Hist("VariableR"))->Fill(jet.perp(),jet.user_index(),weight); 
       double mjet,mmin;
       int nsubjets;
       std::vector<fastjet::PseudoJet> subjets;
       fastjet::PseudoJet CMSjet;
       Hist("pT_s1")->Fill(genparticles->at(bestjetindex).pt(),weight);
       //  if(CMSTopTagFull_pseudo_CA(jet,3.0,0.05,0.4,0.0004,mjet, nsubjets,mmin,subjets,CMSjet)) Hist("pT_s1_cms_tagged400")->Fill(genparticles->at(bestjetindex).pt(),weight);
       Hist("mmin")->Fill(mmin,weight);
       Hist("nsubjets")->Fill(nsubjets,weight);
       mjet=SortedJets[i].m();
       if(genparticles->at(bestjetindex).pt()>200 && genparticles->at(bestjetindex).pt()<400)  Hist("mjet200")->Fill(mjet,weight);
       if(genparticles->at(bestjetindex).pt()>500 && genparticles->at(bestjetindex).pt()<600)  Hist("mjet400")->Fill(mjet,weight);
       if(genparticles->at(bestjetindex).pt()>600 && genparticles->at(bestjetindex).pt()<800)  Hist("mjet600")->Fill(mjet,weight);
       if(genparticles->at(bestjetindex).pt()>800 && genparticles->at(bestjetindex).pt()<1000)  Hist("mjet800")->Fill(mjet,weight);
       if(genparticles->at(bestjetindex).pt()>1000 && genparticles->at(bestjetindex).pt()<1200)  Hist("mjet1000")->Fill(mjet,weight);
       if(SortedSubJets.size()>2){
	 if(genparticles->at(bestjetindex).pt()>200 && genparticles->at(bestjetindex).pt()<400)  Hist("mjet200_1")->Fill(mjet,weight);
	 if(genparticles->at(bestjetindex).pt()>400 && genparticles->at(bestjetindex).pt()<600)  Hist("mjet400_1")->Fill(mjet,weight);
	 if(genparticles->at(bestjetindex).pt()>600 && genparticles->at(bestjetindex).pt()<800)  Hist("mjet600_1")->Fill(mjet,weight);
	 if(genparticles->at(bestjetindex).pt()>800 && genparticles->at(bestjetindex).pt()<1000)  Hist("mjet800_1")->Fill(mjet,weight);
	 if(genparticles->at(bestjetindex).pt()>1000 && genparticles->at(bestjetindex).pt()<1200)  Hist("mjet1000_1")->Fill(mjet,weight);
	   }
	  	  // std::cout<<"test2"<<std::endl;
       if(SortedSubJets.size()>3){
	 if(genparticles->at(bestjetindex).pt()>200 && genparticles->at(bestjetindex).pt()<400)  Hist("mjet200_2")->Fill(mjet,weight);
	 if(genparticles->at(bestjetindex).pt()>400 && genparticles->at(bestjetindex).pt()<600)  Hist("mjet400_2")->Fill(mjet,weight);
	 if(genparticles->at(bestjetindex).pt()>600 && genparticles->at(bestjetindex).pt()<800)  Hist("mjet600_2")->Fill(mjet,weight);
	 if(genparticles->at(bestjetindex).pt()>800 && genparticles->at(bestjetindex).pt()<1000)  Hist("mjet800_2")->Fill(mjet,weight);
	 if(genparticles->at(bestjetindex).pt()>1000 && genparticles->at(bestjetindex).pt()<1200)  Hist("mjet1000_2")->Fill(mjet,weight);
	    }
	   

       //cutting variables

       
       //nsubjettiness
        double tau1,tau2,tau3,tau4;
	 JetPropsPseudo jp(&jet);
       tau1 = jp.GetNsubjettiness(1, Njettiness::onepass_kt_axes, 1., varjets[i].user_index()/10.);
       tau2 = jp.GetNsubjettiness(2, Njettiness::onepass_kt_axes, 1., varjets[i].user_index()/10.);
       tau3 = jp.GetNsubjettiness(3, Njettiness::onepass_kt_axes, 1., varjets[i].user_index()/10.);
       tau4 = jp.GetNsubjettiness(4, Njettiness::onepass_kt_axes, 1., varjets[i].user_index()/10.);
        Hist("tau1")->Fill(tau1,weight);
	if(genparticles->at(bestjetindex).pt()>200) Hist("tau1_200")->Fill(tau1,weight);
	if(genparticles->at(bestjetindex).pt()>500) Hist("tau1_500")->Fill(tau1,weight);
	if(genparticles->at(bestjetindex).pt()>600) Hist("tau1_600")->Fill(tau1,weight);
	if(genparticles->at(bestjetindex).pt()>800) Hist("tau1_800")->Fill(tau1,weight);
	if(genparticles->at(bestjetindex).pt()>1000) Hist("tau1_1000")->Fill(tau1,weight);
	Hist("tau2")->Fill(tau2,weight);
	if(genparticles->at(bestjetindex).pt()>200) Hist("tau2_200")->Fill(tau2,weight);
	if(genparticles->at(bestjetindex).pt()>500) Hist("tau2_500")->Fill(tau2,weight);
	if(genparticles->at(bestjetindex).pt()>600) Hist("tau2_600")->Fill(tau2,weight);
	if(genparticles->at(bestjetindex).pt()>800) Hist("tau2_800")->Fill(tau2,weight);
	if(genparticles->at(bestjetindex).pt()>1000) Hist("tau2_1000")->Fill(tau2,weight);
	Hist("tau3")->Fill(tau3,weight);
	if(genparticles->at(bestjetindex).pt()>200) Hist("tau3_200")->Fill(tau3,weight);
	if(genparticles->at(bestjetindex).pt()>500) Hist("tau3_500")->Fill(tau3,weight);
	if(genparticles->at(bestjetindex).pt()>600) Hist("tau3_600")->Fill(tau3,weight);
	if(genparticles->at(bestjetindex).pt()>800) Hist("tau3_800")->Fill(tau3,weight);
	if(genparticles->at(bestjetindex).pt()>1000) Hist("tau3_1000")->Fill(tau3,weight);
	Hist("tau4")->Fill(tau4,weight);
	if(genparticles->at(bestjetindex).pt()>200) Hist("tau4_200")->Fill(tau4,weight);
	if(genparticles->at(bestjetindex).pt()>500) Hist("tau4_500")->Fill(tau4,weight);
	if(genparticles->at(bestjetindex).pt()>600) Hist("tau4_600")->Fill(tau4,weight);
	if(genparticles->at(bestjetindex).pt()>800) Hist("tau4_800")->Fill(tau4,weight);
	if(genparticles->at(bestjetindex).pt()>1000) Hist("tau4_1000")->Fill(tau4,weight);
	Hist("tau2tau1")->Fill(tau2/tau1,weight);
	if(genparticles->at(bestjetindex).pt()>200)  Hist("tau2tau1_200")->Fill(tau2/tau1,weight);
	if(genparticles->at(bestjetindex).pt()>500)  Hist("tau2tau1_500")->Fill(tau2/tau1,weight);
	if(genparticles->at(bestjetindex).pt()>600)  Hist("tau2tau1_600")->Fill(tau2/tau1,weight);
	if(genparticles->at(bestjetindex).pt()>800)  Hist("tau2tau1_800")->Fill(tau2/tau1,weight);
	if(genparticles->at(bestjetindex).pt()>1000)  Hist("tau2tau1_1000")->Fill(tau2/tau1,weight);
	Hist("tau3tau2")->Fill(tau3/tau2,weight);
	if(genparticles->at(bestjetindex).pt()>200 && genparticles->at(bestjetindex).pt()<400)  Hist("tau3tau2_200")->Fill(tau3/tau2,weight);
	if(genparticles->at(bestjetindex).pt()>400 && genparticles->at(bestjetindex).pt()<600)  Hist("tau3tau2_400")->Fill(tau3/tau2,weight);
	if(genparticles->at(bestjetindex).pt()>600 && genparticles->at(bestjetindex).pt()<800)  Hist("tau3tau2_600")->Fill(tau3/tau2,weight);
	if(genparticles->at(bestjetindex).pt()>800 &&genparticles->at(bestjetindex).pt()<1000)  Hist("tau3tau2_800")->Fill(tau3/tau2,weight);
	if(genparticles->at(bestjetindex).pt()>1000 &&genparticles->at(bestjetindex).pt()<1200)  Hist("tau3tau2_1000")->Fill(tau3/tau2,weight);
       


	/*	 if(SortedSubJets.size()>0){
	    double tau1_mj,tau2_mj,tau3_mj,tau4_mj;
	   JetPropsPseudo jp2(&sum);
	   tau1_mj = jp2.GetNsubjettiness(1, Njettiness::onepass_kt_axes, 1., varjets[i].user_index()/10.);
	   tau2_mj = jp2.GetNsubjettiness(2, Njettiness::onepass_kt_axes, 1., varjets[i].user_index()/10.);
	   tau3_mj = jp2.GetNsubjettiness(3, Njettiness::onepass_kt_axes, 1., varjets[i].user_index()/10.);
	   tau4_mj = jp2.GetNsubjettiness(4, Njettiness::onepass_kt_axes, 1., varjets[i].user_index()/10.);
	   Hist("tau1_massjump")->Fill(tau1_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>200) Hist("tau1_200_massjump")->Fill(tau1_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>500) Hist("tau1_500_massjump")->Fill(tau1_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>600) Hist("tau1_600_massjump")->Fill(tau1_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>800) Hist("tau1_800_massjump")->Fill(tau1_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>1000) Hist("tau1_1000_massjump")->Fill(tau1_mj,weight);
	  
	   Hist("tau2_massjump")->Fill(tau2_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>200) Hist("tau2_200_massjump")->Fill(tau2_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>500) Hist("tau2_500_massjump")->Fill(tau2_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>600) Hist("tau2_600_massjump")->Fill(tau2_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>800) Hist("tau2_800_massjump")->Fill(tau2_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>1000) Hist("tau2_1000_massjump")->Fill(tau2_mj,weight);
	   Hist("tau3_massjump")->Fill(tau3_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>200) Hist("tau3_200_massjump")->Fill(tau3_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>500) Hist("tau3_500_massjump")->Fill(tau3_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>600) Hist("tau3_600_massjump")->Fill(tau3_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>800) Hist("tau3_800_massjump")->Fill(tau3_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>1000) Hist("tau3_1000_massjump")->Fill(tau3_mj,weight);
	   Hist("tau4_massjump")->Fill(tau4_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>200) Hist("tau4_200_massjump")->Fill(tau4_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>500) Hist("tau4_500_massjump")->Fill(tau4_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>600) Hist("tau4_600_massjump")->Fill(tau4_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>800) Hist("tau4_800_massjump")->Fill(tau4_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>1000) Hist("tau4_1000_massjump")->Fill(tau4_mj,weight);
	   Hist("tau2tau1_massjump")->Fill(tau2_mj/tau1_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>200)  Hist("tau2tau1_200_massjump")->Fill(tau2_mj/tau1_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>500)  Hist("tau2tau1_500_massjump")->Fill(tau2_mj/tau1_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>600)  Hist("tau2tau1_600_massjump")->Fill(tau2_mj/tau1_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>800)  Hist("tau2tau1_800_massjump")->Fill(tau2_mj/tau1_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>1000)  Hist("tau2tau1_1000_massjump")->Fill(tau2_mj/tau1_mj,weight);
	   Hist("tau3tau2_massjump")->Fill(tau3_mj/tau2_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>200)  Hist("tau3tau2_200_massjump")->Fill(tau3_mj/tau2_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>500)  Hist("tau3tau2_500_massjump")->Fill(tau3_mj/tau2_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>600)  Hist("tau3tau2_600_massjump")->Fill(tau3_mj/tau2_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>800)  Hist("tau3tau2_800_massjump")->Fill(tau3_mj/tau2_mj,weight);
	   if(genparticles->at(bestjetindex).pt()>1000)  Hist("tau3tau2_1000_massjump")->Fill(tau3_mj/tau2_mj,weight);
	   }*/
	  


       //softdrop
       fastjet::PseudoJet groomed_jet;
       /* Softdrop->GetJet(jet,0.1,2.0,groomed_jet);
       Hist("sd_mass")->Fill(groomed_jet.m(),weight);
       if(genparticles->at(bestjetindex).pt()>200) Hist("sd_mass200")->Fill(groomed_jet.m(),weight);
       if(genparticles->at(bestjetindex).pt()>500) Hist("sd_mass500")->Fill(groomed_jet.m(),weight);
       if(genparticles->at(bestjetindex).pt()>600) Hist("sd_mass600")->Fill(groomed_jet.m(),weight);
       if(genparticles->at(bestjetindex).pt()>800) Hist("sd_mass800")->Fill(groomed_jet.m(),weight);
       if(genparticles->at(bestjetindex).pt()>1000) Hist("sd_mass1000")->Fill(groomed_jet.m(),weight);*/
       //if(SortedSubJets.size()>2 && groomed_jet.m()>150 &&  groomed_jet.m()<250 && mmin2>50)  Hist("pT_s1_tobi4_tagged")->Fill(genparticles->at(bestjetindex).pt(),weight);
       if(varjets[i].user_index()>5)  Hist("pT_s1_varR_tagged")->Fill(genparticles->at(bestjetindex).pt(),weight);
        if(SortedSubJets.size()>2 && SortedJets[i].m()>mtopLow &&  SortedJets[i].m()<mtopHigh && mmin2>50 && varjets.size()>2)  Hist("pT_s1_tobi4_tagged")->Fill(genparticles->at(bestjetindex).pt(),weight);
        if(SortedSubJets.size()>2 &&  varjets[i].m()>mtopLow &&   varjets[i].m()<mtopHigh &&tau3/tau2<0.7  &&SortedSubJets.at(0).pt()>30 &&SortedSubJets.at(1).pt()>30&&  SortedSubJets.at(0).pt()/varjets[i].pt()<0.8/*&&mmin2>50*/)  Hist("pT_s1_tobi5_tagged")->Fill(genparticles->at(bestjetindex).pt(),weight);
	if(SortedSubJets.size()>2 &&  varjets[i].m()>mtopLow &&   varjets[i].m()<mtopHigh   &&SortedSubJets.at(0).pt()>30 &&SortedSubJets.at(1).pt()>30&&  SortedSubJets.at(0).pt()/varjets[i].pt()<0.8/*&&mmin2>50*/) for(int roc=0;roc<100;roc++){
	  if(tau3/tau2<roc/100.){
	    ((TH2D*)Hist("nsub_eff"))->Fill(genparticles->at(bestjetindex).pt(),roc/100.,weight);
	       if(genparticles->at(bestjetindex).pt()>200) Hist("nsub_eff200")->Fill(roc/100.,weight);
	       if(genparticles->at(bestjetindex).pt()>400) Hist("nsub_eff400")->Fill(roc/100.,weight);
	       if(genparticles->at(bestjetindex).pt()>600) Hist("nsub_eff600")->Fill(roc/100.,weight);
	       if(genparticles->at(bestjetindex).pt()>800) Hist("nsub_eff800")->Fill(roc/100.,weight);
	  }
	  }
	if(SortedSubJets.size()>2 &&  SortedSubJets.at(0).pt()>30 &&SortedSubJets.at(1).pt()>30&&  SortedSubJets.at(0).pt()/varjets[i].pt()<0.8 && mmin2>50)  for(int roc=0;roc<250;roc++) for(int roc2=0;roc2<roc;roc2++){
	      if(varjets[i].m()<roc && varjets[i].m()>roc2)  ((TH3D*)Hist("nsub_eff_mass"))->Fill(genparticles->at(bestjetindex).pt(),roc,roc2,weight);
	  }
       //if(CMSTopTagFull_pseudo_CA(jet,3.0,0.05,0.4,0.0004,mjet, nsubjets,mmin,subjets,CMSjet) && tau3/tau2<0.7) Hist("pT_s1_cms_nsub_tagged")->Fill(genparticles->at(bestjetindex).pt(),weight);
       // if(groomed_jet.m()>150 && groomed_jet.m()<250)  Hist("pT_s1_tobi_tagged")->Fill(genparticles->at(bestjetindex).pt(),weight);
	  // std::cout<<"test2"<<std::endl;
     }
   }
  }
    
    

  
  
  
  


}

void RocHists2::Finish()
{
  // final calculations, like division and addition of certain histograms
  EventCalc* calc = EventCalc::Instance();
  bool IsRealData = calc->IsRealData();
  if (IsRealData){
    Hist("N_pv_perLumiBin")->Divide( Hist("N_pv_perLumiBin"), Hist("N_events_perLumiBin"));
    Hist( "N_pv_perLumiBin")->GetYaxis()->SetTitle("Events/Lumi");
  }

}

