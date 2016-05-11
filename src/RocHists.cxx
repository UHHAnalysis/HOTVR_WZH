#include "include/RocHists.h"
#include "SFrameTools/include/EventCalc.h"
#include "include/ZprimeFullHadTools.h"
#include "NtupleWriter/include/JetProps.h"
#include <iostream>
#include "TH3.h"
using namespace std;

RocHists::RocHists(const char* name) : BaseHists(name)
{
  // named default constructor
   
}

RocHists::~RocHists()
{
  // default destructor, does nothing
}

void RocHists::Init()
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
  Book( TH1F( "pT_s1"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "pT_s1_mis"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "pT_s1400"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "pT_s1_cms_tagged400"," p_{T} topjets (cms tagged)",50,0,2000));
  Book( TH1F( "pT_s1_mis400"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "pT_s1_cms_tagged_mis400"," p_{T} topjets (cms tagged)",50,0,2000));
  Book( TH1F( "pT_s1600"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "pT_s1_cms_tagged600"," p_{T} topjets (cms tagged)",50,0,2000));
  Book( TH1F( "pT_s1_mis600"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "pT_s1_cms_tagged_mis600"," p_{T} topjets (cms tagged)",50,0,2000));
  Book( TH1F( "pT_s1800"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "pT_s1_cms_tagged800"," p_{T} topjets (cms tagged)",50,0,2000));
  Book( TH1F( "pT_s1_mis800"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "pT_s1_cms_tagged_mis800"," p_{T} topjets (cms tagged)",50,0,2000));
  Book( TH1F( "pT_s1hep"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "pT_s1_mishep"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "pT_s1400hep"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "pT_s1_cms_tagged400hep"," p_{T} topjets (cms tagged)",50,0,2000));
  Book( TH1F( "pT_s1_mis400hep"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "pT_s1_cms_tagged_mis400hep"," p_{T} topjets (cms tagged)",50,0,2000));
  Book( TH1F( "pT_s1600hep"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "pT_s1_cms_tagged600hep"," p_{T} topjets (cms tagged)",50,0,2000));
  Book( TH1F( "pT_s1_mis600hep"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "pT_s1_cms_tagged_mis600hep"," p_{T} topjets (cms tagged)",50,0,2000));
  Book( TH1F( "pT_s1800hep"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "pT_s1_cms_tagged800hep"," p_{T} topjets (cms tagged)",50,0,2000));
  Book( TH1F( "pT_s1_mis800hep"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "pT_s1_cms_tagged_mis800hep"," p_{T} topjets (cms tagged)",50,0,2000));
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
  Book( TH1D( "weight", ";weight;Events", 400, 0., 2.));
  
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
  Book( TH1D( "Jetmass2", ";Top jet mass (GeV);Events", 50, 0, 500));
  Book( TH1D( "Subjetmass2", ";subjet mass (GeV);Events", 50, 0, 500));
  Book( TH1D( "mmin2", ";Top jet mass (GeV);Events", 50, 0, 200));
   Book( TH1D( "mmin3", ";Top jet mass (GeV);Events", 50, 0, 200));
   Book(TH1D("rho","rho",60,-10,200));
   Book(TH1D("CMS_pt","cms",50,0,2000));
   Book(TH1D("TL_pt","tl",50,0,2000));
   Book(TH2F("VariableR","VariableR",1000,0,2000,20,0,20));


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
}

void RocHists::SetIdVersion(TString s)
{
  idVersion=s;
}

void RocHists::Fill()
{
  // fill the histograms


    EventCalc* calc = EventCalc::Instance();
    BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
  bool IsRealData = calc->IsRealData();
  LuminosityHandler* lumih = calc->GetLumiHandler();

  // important: get the event weight
  double weight = calc->GetWeight();

  int run = calc->GetRunNum();
  int lumiblock = calc->GetLumiBlock();
  int Npvs = calc->GetPrimaryVertices()->size();


  /*

  //Filling generator-level information for semi-leptonic ttbar events
  TTbarGen* Decay = calc->GetTTbarGen();

  GenParticle topgen=Decay->Top();
  GenParticle antitopgen=Decay->Antitop();
  GenParticle btop=Decay->bTop();
  GenParticle bantitop=Decay->bAntitop();
  int decaytop=abs(Decay->Wdecay1().pdgId());
  int decayantitop=abs(Decay->WMinusdecay1().pdgId());
  int semileptop=0;
  int semilepantitop=0;
  GenParticle muongen;

  if((decaytop==13||decaytop==14)&&decayantitop>0&&decayantitop<=5){
    semileptop=1;
    if(decaytop==13){
      muongen=Decay->Wdecay1();
    }
    if(decaytop==14){
      muongen=Decay->Wdecay2();
    }
  }
  if((decayantitop==13||decayantitop==14)&&decaytop>0&&decaytop<=5){
    semilepantitop=1;
    if(decayantitop==13){
      muongen=Decay->WMinusdecay1();
    }
    if(decaytop==14){
      muongen=Decay->WMinusdecay2();
    }
  }

  if(semileptop){
    Hist("DR_Mub")->Fill(muongen.deltaR(btop),weight);
    Hist("DPhi_Mub")->Fill(muongen.deltaPhi(btop),weight);
    Hist("DR_Mutop")->Fill(muongen.deltaR(antitopgen),weight);
    Hist("DPhi_Mutop")->Fill(muongen.deltaPhi(antitopgen),weight);
    Hist("DR_btop")->Fill(btop.deltaR(antitopgen),weight);
    Hist("DPhi_btop")->Fill(btop.deltaPhi(antitopgen),weight);
  }

  if(semilepantitop){
    Hist("DR_Mub")->Fill(muongen.deltaR(bantitop),weight);
    Hist("DPhi_Mub")->Fill(muongen.deltaPhi(bantitop),weight);
    Hist("DR_Mutop")->Fill(muongen.deltaR(topgen),weight);
    Hist("DPhi_Mutop")->Fill(muongen.deltaPhi(topgen),weight);
    Hist("DR_btop")->Fill(bantitop.deltaR(topgen),weight);
    Hist("DPhi_btop")->Fill(bantitop.deltaPhi(topgen),weight);
  }

  */

  Hist("N_pv")->Fill(Npvs, weight);
  if(calc->IsRealData()){  
    Hist( "N_pv_perLumiBin")->Fill( lumih->GetLumiBin(run, lumiblock), Npvs*weight);
  Hist( "N_events_perLumiBin")->Fill( lumih->GetLumiBin(run, lumiblock), weight);
  }

  //double npu = bcc.genInfo->pileup_TrueNumInteractions();
  //if(npu>50) npu=49.9999;
  //Hist( "N_pileup_hist" )->Fill( npu, weight );

  //MET* met = calc->GetMET();
  //Hist("MET_lx")->Fill(met->pt(), weight);

  //double HT = calc->GetHT();
  //Hist("HT_lx")->Fill(HT, weight);

  //double HTlep = calc->GetHTlep();
  //Hist("HTlep_lx")->Fill(HTlep, weight);

  int Ntopjets = bcc->toptagjets->size();
  Hist("N_topjets")->Fill(Ntopjets, weight);

  std::vector<Muon>* muons = calc->GetMuons();
  int Nmuons = muons->size();
  Hist("N_mu")->Fill(Nmuons, weight);

  
  float minDeltaR=10000;
  int bestjetindex=-1;
  int bestjetindex2=-1;
  
  /*
 //
  if (!IsRealData)
  { 
    TopPtReweight m_tpr;
    double ptreweight=m_tpr.GetScaleWeight();
    Hist( "TopPtWeightHisto")->Fill(ptreweight,1.);
    Hist( "TopPtFullWeightHisto")->Fill(ptreweight,weight);
    
    
    TTbarGen* Decay = calc->GetTTbarGen();
    GenParticle HadTop;
    bool isHadronic=false;
    if (Decay->IsTopHadronicDecay())
    {
      HadTop=Decay->Top();
      isHadronic=true;
    }
    else
    {
      if(Decay->IsAntiTopHadronicDecay())
      {
	HadTop=Decay->Antitop();
	isHadronic=true;
      }
    }
    if (isHadronic)
    {
      ((TH2F*)Hist( "TopWeightVsGenPtHisto2"))->Fill(ptreweight,HadTop.pt(),1.);
      minDeltaR=10000;
      bestjetindex=-1;
      for(unsigned int i=0; i<bcc->toptagjets->size(); ++i)
      {
	if(HadTop.deltaR(bcc->toptagjets->at(i))<minDeltaR)
	{
	  minDeltaR=HadTop.deltaR(bcc->toptagjets->at(i));
	  bestjetindex=i;
	}
      }
      if(bestjetindex>-1)
      {
	((TH2F*)Hist( "TopWeightVsPtHisto"))->Fill(ptreweight,bcc->toptagjets->at(bestjetindex).pt(),1.);
	((TH2F*)Hist( "TopWeightVsGenPtHisto"))->Fill(ptreweight,HadTop.pt(),1.);
      }
    }
    
  }
  */
  
  
  
  
  
  
  
  
  
  
  /*
  
  
  if(!IsRealData && (idVersion=="TTbarEff" || idVersion=="TTbarEff_1" || idVersion=="TTbarEff_2" || idVersion=="TTbarEff_3"))
  {
    TTbarGen* Decay = calc->GetTTbarGen();
    GenParticle HadTop;
    bool isHadronic=false;
    if (Decay->IsTopHadronicDecay())
    {
      HadTop=Decay->Top();
      isHadronic=true;
    }
    else
    {
      if(Decay->IsAntiTopHadronicDecay())
      {
	HadTop=Decay->Antitop();
	isHadronic=true;
      }
    }
    if (isHadronic)
    {
      minDeltaR=10000;
      bestjetindex=-1;
      for(unsigned int i=0; i<bcc->toptagjets->size(); ++i)
      {
	if(HadTop.deltaR(bcc->toptagjets->at(i))<minDeltaR && bcc->toptagjets->at(i).deltaR(Decay->BHad())<1.5 && bcc->toptagjets->at(i).deltaR(Decay->WHad())<1.5 && bcc->toptagjets->at(i).deltaR(Decay->Q1())<1.5 && bcc->toptagjets->at(i).deltaR(Decay->Q2())<1.5)
	{
	  minDeltaR=HadTop.deltaR(bcc->toptagjets->at(i));
	  bestjetindex=i;
	}
      }
      minDeltaR=10000;
      bestjetindex2=-1;
      for(unsigned int i=0; i<bcc->jets->size(); ++i)
      {
	if(HadTop.deltaR(bcc->jets->at(i))<minDeltaR && bcc->jets->at(i).deltaR(Decay->BHad())<1.5 && bcc->jets->at(i).deltaR(Decay->WHad())<1.5 && bcc->jets->at(i).deltaR(Decay->Q1())<1.5 && bcc->jets->at(i).deltaR(Decay->Q2())<1.5)
	{
	  minDeltaR=HadTop.deltaR(bcc->jets->at(i));
	  bestjetindex2=i;
	}
      }
      if(bestjetindex>-1 && bestjetindex2>-1)
      {
	float MassTopUnfiltered=0;
	if (bcc->jets->at(bestjetindex2).v4().isTimelike()) MassTopUnfiltered=bcc->jets->at(bestjetindex2).v4().M();
	LorentzVector allsubjets(0,0,0,0);
	for(unsigned int j=0; j < 3; ++j){
	  allsubjets += bcc->toptagjets->at(bestjetindex).subjets()[j].v4();
	}
	float MassTop=0;
	if (allsubjets.isTimelike()) MassTop=allsubjets.M();
	if (MassTop>0 && MassTopUnfiltered>0)
	{
	  Hist("MassTop")->Fill(MassTop);
	  Hist("MassTopUnfiltered")->Fill(MassTopUnfiltered);
	}
      }
    }
  }
  
  
  
  
  
  */
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

  //for (int i=0; i<Nmuons; ++i){
  //Muon thismu = muons->at(i);
  //Hist("pt_mu_lx")->Fill(thismu.pt(), weight);
  //Hist("eta_mu")->Fill(thismu.eta(), weight);
  //Hist("reliso_mu")->Fill(thismu.relIso(), weight);
  //}

  /*

  double limpt=0;
  int indexjet=-99999;

  int countjets=0;

  std::vector<Particle> subjets_top;
  std::vector<float> btagsub_combinedSecondaryVertex_top;
  std::vector<int> flavorsub_top;
*/
  
  
//####################################################################  
  
  
  int nsteps=50;
  double wmin=0.0;
  double wmax=0.5;
  double nsubmin=0.0;
  double nsubmax=1.0;
  double csvmin=0.0;
  double csvmax=1.0;
  
//   double mwl_step=(1.0-0.5)/nsteps;
//   double mwu_step=(1.5-1.0)/nsteps;
//   double rsa_step=(0.5-0.0)/nsteps;
//   double rsb_step=(0.5-0.0)/nsteps;
//   double tml_step=(160.0-90.0)/nsteps;
//   double tmu_step=(260.0-190.0)/nsteps;
//   double nsub_step=(1.0-0.5)/nsteps;
//   double w_step=(0.5-0.0)/nsteps;
  
  double nsub_step=(nsubmax-nsubmin)/nsteps;
  double w_step=(wmax-wmin)/nsteps;
  double csv_step=(csvmax-csvmin)/nsteps;

//EFFICIENCY
  if(!IsRealData && (idVersion=="TTbarEff" || idVersion=="TTbarEff_1" || idVersion=="TTbarEff_2" || idVersion=="TTbarEff_3"))
  {
    TTbarGen* Decay = calc->GetTTbarGen();
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
	sort(bcc->topjets->begin(), bcc->topjets->end(), HigherPt());
        double minDeltaR2=10000;
	int bestjetindex2=-1;
        for(unsigned int i=0; i<bcc->topjets->size(); ++i)
	{
	  double DeltaR2=Had_Tops[j].deltaR(bcc->topjets->at(i));
	  if(DeltaR2<minDeltaR2)
	  {
	    minDeltaR2=DeltaR2;
	    bestjetindex2=i;
	  }
	}


	if (minDeltaR>1.0) bestjetindex=-1;//protect against large deltaR
	if (minDeltaR2>1.0) bestjetindex2=-1;//protect against large deltaR
	if((bestjetindex>-1) && (bestjetindex!=oldbestjet))
	{
	  oldbestjet=bestjetindex;
	  ((TH2D*)Hist("PtGenVsRecoEff"))->Fill(Had_Tops[j].pt(),bcc->toptagjets->at(bestjetindex).pt(),1);
// 	  Hist("eff_all")->Fill(bcc->toptagjets->at(bestjetindex).pt(),1);
// 	  Hist("TopPt_Eff")->Fill(bcc->toptagjets->at(bestjetindex).pt(),1);
          Hist("eff_all")->Fill(Had_Tops[j].pt(),1);
	  Hist("TopPt_Eff")->Fill(Had_Tops[j].pt(),1);
	  if (Had_Tops[j].pt()>400.0) Hist("pT_s1400hep")->Fill(Had_Tops[j].pt(),1);
	  if (Had_Tops[j].pt()>600.0) Hist("pT_s1600hep")->Fill(Had_Tops[j].pt(),1);
	  if (Had_Tops[j].pt()>800.0) Hist("pT_s1800hep")->Fill(Had_Tops[j].pt(),1);
	  /* if (Had_Tops[j].pt()>400.0) Hist("pT_s1400")->Fill(Had_Tops[j].pt(),1);
	  if (Had_Tops[j].pt()>600.0) Hist("pT_s1600")->Fill(Had_Tops[j].pt(),1);
	  if (Had_Tops[j].pt()>800.0) Hist("pT_s1800")->Fill(Had_Tops[j].pt(),1);*/
	  
	  
	  
	  //TL taggers

	  //  std::cout<<"test"<<std::endl;
	 
	  
	
	
	
	  
	  bool iscsvl=false;
	  bool iscsvm=false;
	  if(bcc->toptagjets->at(bestjetindex).subCSV().at(0)>0.244 ||
	      bcc->toptagjets->at(bestjetindex).subCSV().at(1)>0.244 ||
	      bcc->toptagjets->at(bestjetindex).subCSV().at(2)>0.244)
	    {iscsvl=true;}
	    if(bcc->toptagjets->at(bestjetindex).subCSV().at(0)>0.679 ||
	      bcc->toptagjets->at(bestjetindex).subCSV().at(1)>0.679 ||
	      bcc->toptagjets->at(bestjetindex).subCSV().at(2)>0.679)
	    {iscsvm=true;}
	  double bestcsv=0;
	  if (bcc->toptagjets->at(bestjetindex).subCSV().at(0)>bestcsv) bestcsv=bcc->toptagjets->at(bestjetindex).subCSV().at(0);
	  if (bcc->toptagjets->at(bestjetindex).subCSV().at(1)>bestcsv) bestcsv=bcc->toptagjets->at(bestjetindex).subCSV().at(1);
	  if (bcc->toptagjets->at(bestjetindex).subCSV().at(2)>bestcsv) bestcsv=bcc->toptagjets->at(bestjetindex).subCSV().at(2);

	  // if(MassHepTopTag(bcc->toptagjets->at(bestjetindex),140.0,250.0))
	  if(variableMassHepTopTag(bcc->toptagjets->at(bestjetindex),200,0.505,1.495,0.35,0.35,140,250))
	  {
	   
// 	    Hist("eff_tagged")->Fill(bcc->toptagjets->at(bestjetindex).pt(),1);
// 	    if(iscsvl) {Hist("eff_tagged_cvsl")->Fill(bcc->toptagjets->at(bestjetindex).pt(),1);}
// 	    if(iscsvm) {Hist("eff_tagged_cvsm")->Fill(bcc->toptagjets->at(bestjetindex).pt(),1);}
	    
            /* if (Had_Tops[j].pt()>400.0)  Hist("pT_s1_cms_tagged400")->Fill(Had_Tops[j].pt(),1);
	    if (Had_Tops[j].pt()>600.0)  Hist("pT_s1_cms_tagged600")->Fill(Had_Tops[j].pt(),1);
	    if (Had_Tops[j].pt()>800.0)  Hist("pT_s1_cms_tagged800")->Fill(Had_Tops[j].pt(),1);*/
	    Hist("eff_tagged")->Fill(Had_Tops[j].pt(),1);
	    if (Had_Tops[j].pt()>400.0)  Hist("pT_s1_cms_tagged400hep")->Fill(Had_Tops[j].pt(),1);
	    if (Had_Tops[j].pt()>600.0)  Hist("pT_s1_cms_tagged600hep")->Fill(Had_Tops[j].pt(),1);
	    if (Had_Tops[j].pt()>800.0)  Hist("pT_s1_cms_tagged800hep")->Fill(Had_Tops[j].pt(),1);
	    /* if (Had_Tops[j].pt()>400.0)  Hist("pT_s1_cms_tagged400")->Fill(Had_Tops[j].pt(),1);
	    if (Had_Tops[j].pt()>600.0)  Hist("pT_s1_cms_tagged600")->Fill(Had_Tops[j].pt(),1);
	    if (Had_Tops[j].pt()>800.0)  Hist("pT_s1_cms_tagged800")->Fill(Had_Tops[j].pt(),1);*/
	    if(iscsvl) {Hist("eff_tagged_cvsl")->Fill(Had_Tops[j].pt(),1);}
	    if(iscsvm) {Hist("eff_tagged_cvsm")->Fill(Had_Tops[j].pt(),1);}
	  }
	  
	  double nsub = getNsub(bcc,bestjetindex);
	  
	  for (unsigned int var_w_count=0; var_w_count<nsteps; var_w_count++)
	  {
	    bool isheptoptagged=variableMassHepTopTag(bcc->toptagjets->at(bestjetindex), 
		200.0, 
		1.0-w_step*var_w_count-w_step/2.0,//0.85, 
		1.0+w_step*var_w_count+w_step/2.0,//1.15,
		0.35, 
		0.35,
		140.0,
		250.0);
	    for (unsigned int var_nsub_count=0; var_nsub_count<nsteps; var_nsub_count++)
	    {
	      for (unsigned int var_csv_count=0; var_csv_count<nsteps; var_csv_count++)
	      {
		
		if(
		  isheptoptagged&&
		  (nsub<(nsubmin+nsub_step*var_nsub_count+nsub_step/2.0))&&
		  (bestcsv>(csvmin+csv_step*var_csv_count+csv_step/2.0))
		) 
		{
// ((TH3D*)Hist("eff_roc_tagged"))->Fill( w_step*var_w_count+w_step/2.0 , 0.5+nsub_step*var_nsub_count+nsub_step/2.0 , bcc->toptagjets->at(bestjetindex).pt() , 1 );
// if (iscsvl) {((TH3D*)Hist("eff_roc_tagged_cvsl"))->Fill( w_step*var_w_count+w_step/2.0 , 0.5+nsub_step*var_nsub_count+nsub_step/2.0 , bcc->toptagjets->at(bestjetindex).pt() , 1 );}
// if (iscsvm) {((TH3D*)Hist("eff_roc_tagged_cvsm"))->Fill( w_step*var_w_count+w_step/2.0 , 0.5+nsub_step*var_nsub_count+nsub_step/2.0 , bcc->toptagjets->at(bestjetindex).pt() , 1 );}
//                 ((TH3D*)Hist("eff_roc_tagged"))->Fill( w_step*var_w_count+w_step/2.0 , 0.5+nsub_step*var_nsub_count+nsub_step/2.0 , Had_Tops[j].pt() , 1 );
// 		if (iscsvl) {((TH3D*)Hist("eff_roc_tagged_cvsl"))->Fill( w_step*var_w_count+w_step/2.0 , 0.5+nsub_step*var_nsub_count+nsub_step/2.0 , Had_Tops[j].pt() , 1 );}
// 		if (iscsvm) {((TH3D*)Hist("eff_roc_tagged_cvsm"))->Fill( w_step*var_w_count+w_step/2.0 , 0.5+nsub_step*var_nsub_count+nsub_step/2.0 , Had_Tops[j].pt() , 1 );}
		if (Had_Tops[j].pt()>200.0) ((TH3D*)Hist("eff_roc_tagged200"))->Fill( w_step*var_w_count+w_step/2.0 , nsubmin+nsub_step*var_nsub_count+nsub_step/2.0 , csvmin+csv_step*var_csv_count+csv_step/2.0 , 1 );
		if (Had_Tops[j].pt()>400.0) ((TH3D*)Hist("eff_roc_tagged400"))->Fill( w_step*var_w_count+w_step/2.0 , nsubmin+nsub_step*var_nsub_count+nsub_step/2.0 , csvmin+csv_step*var_csv_count+csv_step/2.0 , 1 );
		if (Had_Tops[j].pt()>600.0) ((TH3D*)Hist("eff_roc_tagged600"))->Fill( w_step*var_w_count+w_step/2.0 , nsubmin+nsub_step*var_nsub_count+nsub_step/2.0 , csvmin+csv_step*var_csv_count+csv_step/2.0 , 1 );
		if (Had_Tops[j].pt()>800.0) ((TH3D*)Hist("eff_roc_tagged800"))->Fill( w_step*var_w_count+w_step/2.0 , nsubmin+nsub_step*var_nsub_count+nsub_step/2.0 , csvmin+csv_step*var_csv_count+csv_step/2.0 , 1 );
	
	
		}
	      }
	    }
	  }
	  
	  

	}
	if((bestjetindex2>-1) && (bestjetindex2!=oldbestjet2)){
	  // std::cout<<bestjetindex<<std::endl;
	  oldbestjet2=bestjetindex2;
	  TopJet Ca8jet=bcc->topjets->at(bestjetindex2);
	  if(Ca8jet.pt()>300) std::cout<<"--------------------------"<<std::endl;
	  if(Ca8jet.pt()>300) 
	  for(int t=0; t<decay_products.size(); t++){
	    if(decay_products[t].pt()<30)  throw SError( SError::SkipEvent );
	  }
	  if(Ca8jet.pt()>300) for(int t=0; t<decay_products.size(); t++){
	    std::cout<<"decay "<<t<<" "<<decay_products[t].pt()<<" "<<decay_products[t].eta()<<"delta R "<<Ca8jet.deltaR(decay_products[t])<<std::endl;
	  } 
	  if(Ca8jet.pt()>0 && bestjetindex2<2){
	   double mva_value=100;
	  //BDT
	   for (unsigned int k =0; k<bcc->higgstagjets->size(); ++k){
	   TopJet CA15jet =  bcc->higgstagjets->at(k);
	   if(true/*(sqrt(pow(Ca8jet.phi()-CA15jet.phi(),2)+pow(Ca8jet.eta()-CA15jet.eta(),2))<1.5)*/){
	     double Rmin,mass_Rmin,pt_Rmin,mass_diff,pt_for_exp,Rmin_exp;
	      if(MultiRTopTag(CA15jet, calc->GetPFParticles(), Rmin,mass_Rmin,pt_Rmin,mass_diff,pt_for_exp,Rmin_exp)){
	     //MultiRTopTag(CA15jet, calc->GetPFParticles(), Rmin,mass_Rmin,pt_Rmin);
		//	Hist("pT_s1_multi_tagged")->Fill(Ca8jet.pt(),weight);
		//	Hist("pT_s1_multi_tagged_ly")->Fill(Ca8jet.pt(),weight);
		Hist("multiR_Rmin")->Fill(Rmin,weight);
		Hist("multiR_massRmin")->Fill(mass_Rmin,weight);
		Hist("multiR_ptRmin")->Fill(pt_Rmin,weight);
		if(CA15jet.pt()>200 )  Hist("multiR_Rmin200")->Fill(Rmin,weight);
		if(CA15jet.pt()>400 )  Hist("multiR_Rmin400")->Fill(Rmin,weight);
		if(CA15jet.pt()>600)  Hist("multiR_Rmin600")->Fill(Rmin,weight);
		if(CA15jet.pt()>800 )  Hist("multiR_Rmin800")->Fill(Rmin,weight);
		if(CA15jet.pt()>1000)  Hist("multiR_Rmin1000")->Fill(Rmin,weight);
	   }
	    }
	   }
	   //tmva_tagger->IsTagged("TLflat",Ca8jet,0.766,mva_value);
	   /*  tmva_tagger->IsTagged("TLflat",Ca8jet,0.766,mva_value);
	  if (Had_Tops[j].pt()>200.0) Hist("MVA200")->Fill(mva_value,weight);
	  if (Had_Tops[j].pt()>400.0) Hist("MVA400")->Fill(mva_value,weight);
	  if (Had_Tops[j].pt()>600.0) Hist("MVA600")->Fill(mva_value,weight);
	  if (Had_Tops[j].pt()>800.0) Hist("MVA800")->Fill(mva_value,weight);*/
	   //tmva_tagger2->IsTagged("simple_cuts",Ca8jet,0.9,mva_value);
	    if(Had_Tops[j].pt()>350)  Hist("MVA_pT")->Fill(Had_Tops[j].pt(),weight);
	    //  if(Had_Tops[j].pt()>350)  tmva_tagger2->push_variables(Ca8jet);
	    //  if(Had_Tops[j].pt()>350) if(tmva_tagger2->IsTagged("simple_cuts",Ca8jet,0.9,mva_value))  Hist("MVA_2")->Fill(Had_Tops[j].pt(),weight);
	    /* if (Had_Tops[j].pt()<300.0) Hist("MVA300_2")->Fill(mva_value,weight);
	  if (Had_Tops[j].pt()>300.0 && Had_Tops[j].pt()<500.0) Hist("MVA500_2")->Fill(mva_value,weight);
	  if (Had_Tops[j].pt()>500.0 && Had_Tops[j].pt()<700.0) Hist("MVA700_2")->Fill(mva_value,weight);
	  if (Had_Tops[j].pt()>700.0) Hist("MVA700inf_2")->Fill(mva_value,weight);
	  std::cout<<"MVA value "<<mva_value<<std::endl; */
	    /*  	   if(Had_Tops[j].pt()>350){
	  if (Had_Tops[j].pt()<300.0 &&   tmva_tagger2->IsTagged("simple_cuts300",Ca8jet,0.9,mva_value)) Hist("MVAsingle_2")->Fill(Had_Tops[j].pt(),weight);
	  if (Had_Tops[j].pt()>300.0 && Had_Tops[j].pt()<500.0  &&   tmva_tagger2->IsTagged("simple_cuts500",Ca8jet,0.9,mva_value)) Hist("MVAsingle_2")->Fill(Had_Tops[j].pt(),weight);
	  if (Had_Tops[j].pt()>500.0 && Had_Tops[j].pt()<700.0  &&   tmva_tagger2->IsTagged("simple_cuts700",Ca8jet,0.9,mva_value)) Hist("MVAsingle_2")->Fill(Had_Tops[j].pt(),weight);
	  if (Had_Tops[j].pt()>700.0  &&   tmva_tagger2->IsTagged("simple_cutsInf",Ca8jet,0.9,mva_value)) Hist("MVAsingle_2")->Fill(Had_Tops[j].pt(),weight);
	  }
	  tmva_tagger2->reset_variables();*/
	    double mmin_jet=0;
	  double mjet2=0;
	  int nsubjets2=0;
	  //TopTag(Ca8jet,mjet,nsubjets,mmin);
	  TopTag(Ca8jet,mjet2,nsubjets2,mmin_jet);


	    //variableR
	  fastjet::ClusterSequence clustersq,clustersq2;
		 double subjetmass, mmin2,rho;
		 double distance;
		 vector<fastjet::PseudoJet> varjets;
		 varjets=varR->Get_varRJet(clustersq2);
		 for(int jets=0;jets<varjets.size();jets++){
		   ((TH2D*)Hist("VariableR"))->Fill(varjets[jets].perp(),varjets[jets].user_index(),weight);
		   // if(CMSTopTagFull_pseudo_CA(varjets[jets],3.0,0.05,0.4,0.0004,mjet, nsubjets,mmin,subjets,CMSjet) && varjets[jets].perp()>350) ;//Hist("pT_s1_cms_tagged400")->Fill(Had_Tops[j].pt(),weight);
		 }
		 //	 distance=varR->Get_Jetsize(varjets[0],clustersq2);
		 if(Ca8jet.pt()>300) fastjet::PseudoJet varRJet= varR->Get_varRSubJet(Ca8jet, calc->GetPFParticles(), 0, 3.0, clustersq, subjetmass, mmin2,rho);
		 if(Ca8jet.pt()>600)  Hist("Jetmass2")->Fill(Ca8jet.v4().M(),weight);
		 if(Ca8jet.pt()>600) Hist("Subjetmass2")->Fill(subjetmass,weight); 
		 if(Ca8jet.pt()>600) Hist("mmin2")->Fill(mmin2,weight);
		 if(Ca8jet.pt()>600) Hist("mmin3")->Fill(mmin_jet,weight);
		 if(Ca8jet.pt()>600) Hist("rho")->Fill(rho,weight);
		 if(rho>50 && mmin2>50 && subjetmass>140 && subjetmass<250) Hist("TL_pt")->Fill(Had_Tops[j].pt(),weight);
		 if( TopTag(Ca8jet,mjet2,nsubjets2,mmin_jet)) Hist("CMS_pt")->Fill(Had_Tops[j].pt(),weight);


	  double bestcsv2=0;
	  if (bcc->topjets->at(bestjetindex2).subCSV().at(0)>bestcsv2) bestcsv2=bcc->topjets->at(bestjetindex2).subCSV().at(0);
          if(Ca8jet.numberOfDaughters()>1) if (bcc->topjets->at(bestjetindex2).subCSV().at(1)>bestcsv2) bestcsv2=bcc->topjets->at(bestjetindex2).subCSV().at(1);
          if(Ca8jet.numberOfDaughters()>2) if (bcc->topjets->at(bestjetindex2).subCSV().at(2)>bestcsv2) bestcsv2=bcc->topjets->at(bestjetindex2).subCSV().at(2);

	  if(subJetBTag(Ca8jet,e_CSVM)>=1){
	     if (Had_Tops[j].pt()>200.0) Hist("MVA200btag")->Fill(mva_value,weight);
	     if (Had_Tops[j].pt()>400.0) Hist("MVA400btag")->Fill(mva_value,weight);
	     if (Had_Tops[j].pt()>600.0) Hist("MVA600btag")->Fill(mva_value,weight);
	     if (Had_Tops[j].pt()>800.0) Hist("MVA800btag")->Fill(mva_value,weight);
	  }
	 
	  //jetshapes
	  double m_psi_02 = calc->IntegratedJetShape( &Ca8jet, 0.2, 0.0 , e_CA8);
	  double m_psi_04 = calc->IntegratedJetShape( &Ca8jet, 0.4, 0.0 , e_CA8);
	  double m_psi_06 = calc->IntegratedJetShape( &Ca8jet, 0.6, 0.0 , e_CA8);
	  double m_psi_08 = calc->IntegratedJetShape( &Ca8jet, 0.8, 0.0 , e_CA8);
	  double m_psi_10 = calc->IntegratedJetShape( &Ca8jet, 1.0, 0.0 , e_CA8);
	  Hist("psi02_ly")->Fill(m_psi_02,weight);
	  Hist("psi04_ly")->Fill(m_psi_04,weight);
	  Hist("psi06_ly")->Fill(m_psi_06,weight);
	  Hist("psi08_ly")->Fill(m_psi_08,weight);
	  Hist("psi10_ly")->Fill(m_psi_10,weight);


	  //helicity angles
	  
	  double subjet1pt;
	  double subjet2pt;
	  double subjet3pt;
	  double HelAng12;
	  double HelAng13;
	  double HelAng23;
	  std::vector<Particle> subjet = Ca8jet.subjets();
	  int Nsubjets=subjet.size();
	  sort(subjet.begin(),subjet.end(),HigherPt());
	  if(Nsubjets>0) subjet1pt=sqrt(pow(subjet[0].v4().Px(),2)+pow(subjet[0].v4().Py(),2));
	  if(Nsubjets>1){
	    TLorentzVector subjet1(subjet[0].v4().Px(),subjet[0].v4().Py(),subjet[0].v4().Pz(),subjet[0].v4().E());
	    TLorentzVector subjet2(subjet[1].v4().Px(),subjet[1].v4().Py(),subjet[1].v4().Pz(),subjet[1].v4().E());
	    subjet1pt=sqrt(pow(subjet[0].v4().Px(),2)+pow(subjet[0].v4().Py(),2));
	    subjet2pt=sqrt(pow(subjet[1].v4().Px(),2)+pow(subjet[1].v4().Py(),2));
	    HelAng12= HelicityAngle(subjet1,subjet2);
	  }
	  if(Nsubjets>2){
	    TLorentzVector subjet1(subjet[0].v4().Px(),subjet[0].v4().Py(),subjet[0].v4().Pz(),subjet[0].v4().E());
	    TLorentzVector subjet2(subjet[1].v4().Px(),subjet[1].v4().Py(),subjet[1].v4().Pz(),subjet[1].v4().E());
	    TLorentzVector subjet3(subjet[2].v4().Px(),subjet[2].v4().Py(),subjet[2].v4().Pz(),subjet[2].v4().E());
	    subjet1pt=sqrt(pow(subjet[0].v4().Px(),2)+pow(subjet[0].v4().Py(),2));
	    subjet2pt=sqrt(pow(subjet[1].v4().Px(),2)+pow(subjet[1].v4().Py(),2));
	    subjet3pt=sqrt(pow(subjet[2].v4().Px(),2)+pow(subjet[2].v4().Py(),2));
	    HelAng12= HelicityAngle(subjet1,subjet2);
	    HelAng13= HelicityAngle(subjet1,subjet3);
	    HelAng23= HelicityAngle(subjet2,subjet3);
	  }
	  if(HelAng12!=0) Hist("HelAng12")->Fill(HelAng12,weight);
	  if(HelAng13!=0) Hist("HelAng13")->Fill(HelAng13,weight);
	  if(HelAng23!=0) Hist("HelAng23")->Fill(HelAng23,weight);



	  //ecf
	  /* double c3=ecf->Get_C(Ca8jet,calc->GetPFParticles(), 3, 1.0);
	  double d3=ecf->Get_D3(Ca8jet,calc->GetPFParticles(),2.,0.8,0.6);
	  if(Ca8jet.pt()>500) Hist("ecf_c3")->Fill(c3,weight);
	  if(Ca8jet.pt()>500) Hist("ecf_d3")->Fill(d3,weight);
	  if(Ca8jet.pt()>500 && mjet2>140 && mjet2<250) {
	    Hist("ecf_c3_mass")->Fill(c3,weight);
	    Hist("ecf_d3_mass")->Fill(d3,weight);
	    }*/


	  //qjet volatility
	  /*  JetProps jp(&Ca8jet, calc->GetPFParticles() );
	    double qjet_mmin=jp.GetQjetVolatility_mmin(calc->GetEventNum(),0.8);
	    double qjet_mass=jp.GetQjetVolatility(calc->GetEventNum(),0.8);
	    double qjet_nsubjets=jp.GetQjetVolatility_nsubjets(calc->GetEventNum(),0.8);
	    double qjet_nsubjettiness1= jp.GetQjetVolatility_Nsubjettiness(calc->GetEventNum(), 0.8, 1, Njettiness::onepass_kt_axes , 1.);
	    double qjet_nsubjettiness2= jp.GetQjetVolatility_Nsubjettiness(calc->GetEventNum(), 0.8, 2, Njettiness::onepass_kt_axes , 1.);
	    double qjet_nsubjettiness3= jp.GetQjetVolatility_Nsubjettiness(calc->GetEventNum(), 0.8, 3, Njettiness::onepass_kt_axes , 1.);
	    
	      //std::cout<<"volatility "<<qjet_mmin<<std::endl;
	    Hist("Qvolatility_mmin")->Fill(qjet_mmin,weight);
	    Hist("Qvolatility_mass")->Fill(qjet_mass,weight);
	    Hist("Qvolatility_nsubjets")->Fill(qjet_nsubjets,weight);
	    Hist("Qvolatility_nsubjettiness1")->Fill(qjet_nsubjettiness1,weight);
	    Hist("Qvolatility_nsubjettiness2")->Fill(qjet_nsubjettiness2,weight);
	    Hist("Qvolatility_nsubjettiness3")->Fill(qjet_nsubjettiness3,weight);
	  */
	   
	  /*  if(TopTag(Ca8jet,mjet2,nsubjets2,mmin_jet)){
	    Hist("Qvolatility_mmin_cms")->Fill(qjet_mmin,weight);
	    Hist("Qvolatility_mass_cms")->Fill(qjet_mass,weight);
	    Hist("Qvolatility_nsubjets_cms")->Fill(qjet_nsubjets,weight);
	    Hist("Qvolatility_nsubjettiness1_cms")->Fill(qjet_nsubjettiness1,weight);
	    Hist("Qvolatility_nsubjettiness2_cms")->Fill(qjet_nsubjettiness2,weight);
	    Hist("Qvolatility_nsubjettiness3_cms")->Fill(qjet_nsubjettiness3,weight);
	  }
	    
	  */


	  //SD
	  if(Ca8jet.pt()>300){
	  std::cout<<"jet pt "<<Ca8jet.pt()<<std::endl;
	   std::cout<<"Jet multiplicity01 "<<jwj->SubjetMultiplicity(Ca8jet, calc->GetPFParticles(),0.05,0.1)<<std::endl;
	  std::cout<<"Jet multiplicity02 "<<jwj->SubjetMultiplicity(Ca8jet, calc->GetPFParticles(),0.05,0.2)<<std::endl;
	  std::cout<<"Jet multiplicity03 "<<jwj->SubjetMultiplicity(Ca8jet, calc->GetPFParticles(),0.05,0.3)<<std::endl;
	  std::cout<<"Jet multiplicity04 "<<jwj->SubjetMultiplicity(Ca8jet, calc->GetPFParticles(),0.05,0.4)<<std::endl;
	  
	  double jetm01,jetm02,jetm03,jetm04;
	  std::vector<fastjet::PseudoJet> subjets= jwj->Get_subjets(Ca8jet, calc->GetPFParticles(),0.05,0.3);
	  std::vector<fastjet::PseudoJet> subjets2= jwj->Get_subjets(Ca8jet, calc->GetPFParticles(),0.05,0.2);
	       std::cout<<"subjets without subjets "<<subjets.size()<<std::endl;
	       std::cout<<"phi1 "<<subjets[0].phi_02pi()<<"eta "<<subjet[0].eta()<<std::endl;
	        std::cout<<"phi2 "<<subjets[1].phi_02pi()<<"eta "<<subjet[1].eta()<<std::endl;
		std::cout<<"phi3 "<<subjets[2].phi_02pi()<<"eta "<<subjet[2].eta()<<std::endl;
		std::cout<<"--"<<std::endl;
		std::cout<<"phi1 "<<subjets[0].phi_02pi()<<"eta "<<subjet[0].eta()<<std::endl;
	        std::cout<<"phi2 "<<subjets[1].phi_02pi()<<"eta "<<subjet[1].eta()<<std::endl;
		std::cout<<"phi3 "<<subjets[2].phi_02pi()<<"eta "<<subjet[2].eta()<<std::endl;
}
	       /*
	       if(subjets.size()>2){
	       double m01 = 0;
	       m01=(subjets[0]+subjets[1]).m();
	       double m02 = 0;
	       m02=(subjets[0]+subjets[2]).m();
	       double m12 = 0; 
	       m12 = (subjets[1]+subjets[2]).m();
	       double mmin_jwj = std::min(m01,std::min(m02,m12));
	       std::cout<<mmin_jwj<<std::endl;
	       
	       }

	             


	       jetm01=jwj->SubjetMultiplicity(Ca8jet, calc->GetPFParticles(),0.05,0.1);
	       jetm02=jwj->SubjetMultiplicity(Ca8jet, calc->GetPFParticles(),0.05,0.2);
	       jetm03=jwj->SubjetMultiplicity(Ca8jet, calc->GetPFParticles(),0.05,0.3);
	       jetm04=jwj->SubjetMultiplicity(Ca8jet, calc->GetPFParticles(),0.05,0.4);
	       std::cout<<"01 "<<jetm01<<std::endl;
	       std::cout<<"02 "<<jetm02<<std::endl;
	       std::cout<<"03 "<<jetm03<<std::endl;
	       std::cout<<"04 "<<jetm04<<std::endl;
	   Hist("Jetm00")->Fill(nsubjets2,weight);
	   Hist("Jetm01")->Fill(jetm01,weight);
	    Hist("Jetm02")->Fill(jetm02,weight);
	     Hist("Jetm03")->Fill(jetm03,weight);
	      Hist("Jetm04")->Fill(jetm04,weight);

	      if(Ca8jet.pt()>400){
	         Hist("Jetm00_400")->Fill(nsubjets2,weight);
	   Hist("Jetm01_400")->Fill(jetm01,weight);
	    Hist("Jetm02_400")->Fill(jetm02,weight);
	     Hist("Jetm03_400")->Fill(jetm03,weight);
	      Hist("Jetm04_400")->Fill(jetm04,weight);
	      }

	       if(Ca8jet.pt()>600){
	         Hist("Jetm00_600")->Fill(nsubjets2,weight);
	   Hist("Jetm01_600")->Fill(jetm01,weight);
	    Hist("Jetm02_600")->Fill(jetm02,weight);
	     Hist("Jetm03_600")->Fill(jetm03,weight);
	      Hist("Jetm04_600")->Fill(jetm04,weight);
	      }*/
	       /*

 if(Ca8jet.pt()>800){
	         Hist("Jetm00_800")->Fill(nsubjets2,weight);
	   Hist("Jetm01_800")->Fill(jwj->SubjetMultiplicity(Ca8jet, calc->GetPFParticles(),10,0.1),weight);
	    Hist("Jetm02_800")->Fill(jwj->SubjetMultiplicity(Ca8jet, calc->GetPFParticles(),10,0.2),weight);
	     Hist("Jetm03_800")->Fill(jwj->SubjetMultiplicity(Ca8jet, calc->GetPFParticles(),10,0.3),weight);
	      Hist("Jetm04_800")->Fill(jwj->SubjetMultiplicity(Ca8jet, calc->GetPFParticles(),10,0.4),weight);
	      }
	       */

	  double Mmicrojet=0;
	  int Nmicrojets=0;
	  std::vector<fastjet::PseudoJet> microjets;
	  double chi=0;
	  double microconesize=0.3;
	  if(Had_Tops[j].pt()>500) microconesize=0.2;
	  if(Had_Tops[j].pt()>700) microconesize=0.1;
	  //if(Ca8jet.pt()>800) microconesize=0.05;
	  // if(Had_Tops[j].pt()>500) chi = Showerdeconstruction_taggerV2->ChiMicro_btag(Ca8jet,Nmicrojets,Mmicrojet,microconesize,microjets);
	  //else chi= Showerdeconstruction_taggerV2->ChiMicro_btag(Ca8jet,Nmicrojets,Mmicrojet,microconesize,microjets);
	  if (Had_Tops[j].pt()>200.0) Hist("SD_fine200")->Fill(log(chi));
	  if (Had_Tops[j].pt()>400.0)  Hist("SD_fine400")->Fill(log(chi));
	  if (Had_Tops[j].pt()>600.0)  Hist("SD_fine600")->Fill(log(chi));
	  if (Had_Tops[j].pt()>800.0)  Hist("SD_fine800")->Fill(log(chi));
	  //std::cout<<subJetBTag(Ca8jet,e_CSVM)<<" "<<subJetBTag(Ca8jet,e_CSVM)<<std::endl;
	  double tau3=Ca8jet.tau3();	  
	  double tau2=Ca8jet.tau2();
	  //std::cout<<"tau3"<<tau3<<"tau2"<<tau2<<std::endl;
	  //	  double tau3=0;
	  //double tau2=0;
	  //------nsubjettiness--------
	  for(unsigned int c=0;c<50;c++){
	    double nsub=(double)c/50.;
	    if(tau3/tau2<nsub){
	    if (Had_Tops[j].pt()>200.0) Hist("SD_fine200nsub")->Fill(log(chi),nsub);
	    if (Had_Tops[j].pt()>400.0)  Hist("SD_fine400nsub")->Fill(log(chi),nsub);
	    if (Had_Tops[j].pt()>600.0)  Hist("SD_fine600nsub")->Fill(log(chi),nsub);
	    if (Had_Tops[j].pt()>800.0)  Hist("SD_fine800nsub")->Fill(log(chi),nsub);
	    }
	  }
	  //----mmin-------
	
	  for(unsigned int c=0;c<50;c++){
	    double mmin_var=(double)c/50.*150.;
	    if(mmin_jet>mmin_var){
	      if (Had_Tops[j].pt()>200.0) Hist("SD_fine200mmin")->Fill(log(chi),mmin_var);
	      if (Had_Tops[j].pt()>400.0)  Hist("SD_fine400mmin")->Fill(log(chi),mmin_var);
	      if (Had_Tops[j].pt()>600.0)  Hist("SD_fine600mmin")->Fill(log(chi),mmin_var);
	      if (Had_Tops[j].pt()>800.0)  Hist("SD_fine800mmin")->Fill(log(chi),mmin_var);
	    }
	  }
	  for(unsigned int c=0;c<50;c++){
	    double bdt;
	    /*if(c<25) bdt=(double)c/(-25.);
	      else bdt=(double)(c-24)/25.;*/
	    bdt=(double)c/25.;
	    //  std::cout<<"MVA"<<mva_value<<"bdt"<<bdt<<std::endl;
	    if(mva_value+1<bdt){
	      if (Had_Tops[j].pt()>200.0) ((TH2D*)Hist("SD_fine200bdt"))->Fill(log(chi),bdt-1,weight);
	      if (Had_Tops[j].pt()>400.0)  ((TH2D*)Hist("SD_fine400bdt"))->Fill(log(chi),bdt-1),weight;
	      if (Had_Tops[j].pt()>600.0) ((TH2D*)Hist("SD_fine600bdt"))->Fill(log(chi),bdt-1,weight);
	      if (Had_Tops[j].pt()>800.0)  ((TH2D*)Hist("SD_fine800bdt"))->Fill(log(chi),bdt-1,weight);
	    }
	  }
	  // if(subJetBTag(Ca8jet,e_CSVM)>=1){
	  for(unsigned int c=0;c<50;c++){
	    double csv=(double)c/50.;
	    // std::cout<<"bestcsv"<<bestcsv2<<" csv"<<c<<std::endl;
		 if(bestcsv2>csv){
		   //	   std::cout<<"csv"<<csv<<std::endl;
		   if (Had_Tops[j].pt()>200.0) Hist("SD_fine200btag")->Fill(log(chi),csv);
		   if (Had_Tops[j].pt()>400.0)  Hist("SD_fine400btag")->Fill(log(chi),csv);
		   if (Had_Tops[j].pt()>600.0)  Hist("SD_fine600btag")->Fill(log(chi),csv);
		   if (Had_Tops[j].pt()>800.0)  Hist("SD_fine800btag")->Fill(log(chi),csv);
		 }
	  }
		 //}
	     
	       //}
	       //}
	  double mmin=0;
	  double mjet=0;
	  int nsubjets=0;
	  //TopTag(Ca8jet,mjet,nsubjets,mmin);
	   if(TopTag(Ca8jet,mjet,nsubjets,mmin) && Ca8jet.pt()>350) {
	  //if(mjet>140 && mjet<250 && Ca8jet.pt()>350 && mmin>50){
	  //if(variableMassHepTopTag(bcc->toptagjets->at(bestjetindex2),200,0.505,1.495,0.35,0.35,140,250)){  
	    if (Had_Tops[j].pt()>400.0)  Hist("pT_s1_cms_tagged400")->Fill(Had_Tops[j].pt(),weight);
	    if (Had_Tops[j].pt()>600.0)  Hist("pT_s1_cms_tagged600")->Fill(Had_Tops[j].pt(),weight);
	    if (Had_Tops[j].pt()>800.0)  Hist("pT_s1_cms_tagged800")->Fill(Had_Tops[j].pt(),weight);
	    
	  }
	  Hist("pT_s1")->Fill(Had_Tops[j].pt(),1);
	  if(Ca8jet.pt()>350){
	  if (Had_Tops[j].pt()>400.0) Hist("pT_s1400")->Fill(Had_Tops[j].pt(),weight);
	  if (Had_Tops[j].pt()>600.0) Hist("pT_s1600")->Fill(Had_Tops[j].pt(),weight);
	  if (Had_Tops[j].pt()>800.0) Hist("pT_s1800")->Fill(Had_Tops[j].pt(),weight);
	  }
	  
	  }
	}

	   

    }
  }

  if(!IsRealData && idVersion=="QCD15to3000")
  {
    
    
    std::vector<GenParticle>* genparticles = calc->GetGenParticles();
   for(unsigned int i=0; i<bcc->toptagjets->size(); ++i)
   {
     //minDeltaR=10000;
     double highestPt=-1;
     bestjetindex=-1;
     for(unsigned int j=0; j<genparticles->size();j++)
     {
       if (abs(genparticles->at(j).pdgId())<=6 || abs(genparticles->at(j).pdgId())==21)
       {
	 if (bcc->toptagjets->at(i).deltaR(genparticles->at(j))<1.0 && genparticles->at(j).pt()>highestPt)
	 {
	  bestjetindex=j;
	  highestPt=genparticles->at(j).pt();
	  //minDeltaR=bcc->toptagjets->at(i).deltaR(genparticles->at(j));
	 }
       }
     }
     if (bestjetindex>-1)
     {
    
   /*for(unsigned int i=0; i<bcc->toptagjets->size(); ++i)
   {*/       
         
       //TL
       // std::cout<<"test"<<bcc->higgstagjets->size()<<std::endl;
     
       
       
       ((TH2D*)Hist("PtGenVsRecoMistag"))->Fill(genparticles->at(bestjetindex).pt(),bcc->toptagjets->at(i).pt(),weight);
//        Hist("mistag_all")->Fill(bcc->toptagjets->at(i).pt(),weight);
//        Hist("TopPt_Mistag")->Fill(bcc->toptagjets->at(i).pt(),weight);
       Hist("mistag_all")->Fill(genparticles->at(bestjetindex).pt(),weight);
       if (genparticles->at(bestjetindex).pt()>400.0) Hist("pT_s1_mis400hep")->Fill(genparticles->at(bestjetindex).pt(),weight);
       if (genparticles->at(bestjetindex).pt()>600.0) Hist("pT_s1_mis600hep")->Fill(genparticles->at(bestjetindex).pt(),weight);
       if (genparticles->at(bestjetindex).pt()>800.0) Hist("pT_s1_mis800hep")->Fill(genparticles->at(bestjetindex).pt(),weight);
       
       /* if (genparticles->at(bestjetindex).pt()>400.0) Hist("pT_s1_mis400")->Fill(genparticles->at(bestjetindex).pt(),weight);
       if (genparticles->at(bestjetindex).pt()>600.0) Hist("pT_s1_mis600")->Fill(genparticles->at(bestjetindex).pt(),weight);
       if (genparticles->at(bestjetindex).pt()>800.0) Hist("pT_s1_mis800")->Fill(genparticles->at(bestjetindex).pt(),weight);*/
       
       Hist("TopPt_Mistag")->Fill(genparticles->at(bestjetindex).pt(),weight);

       bool iscsvl=false;
       bool iscsvm=false;
       if(bcc->toptagjets->at(i).subCSV().at(0)>0.244 ||
	 bcc->toptagjets->at(i).subCSV().at(1)>0.244 ||
	 bcc->toptagjets->at(i).subCSV().at(2)>0.244)
       {iscsvl=true;}
       if(bcc->toptagjets->at(i).subCSV().at(0)>0.679 ||
	 bcc->toptagjets->at(i).subCSV().at(1)>0.679 ||
	 bcc->toptagjets->at(i).subCSV().at(2)>0.679)
       {iscsvm=true;}
       double bestcsv=0;
       if (bcc->toptagjets->at(i).subCSV().at(0)>bestcsv) bestcsv=bcc->toptagjets->at(i).subCSV().at(0);
       if (bcc->toptagjets->at(i).subCSV().at(1)>bestcsv) bestcsv=bcc->toptagjets->at(i).subCSV().at(1);
       if (bcc->toptagjets->at(i).subCSV().at(2)>bestcsv) bestcsv=bcc->toptagjets->at(i).subCSV().at(2);
       
       // if(MassHepTopTag(bcc->toptagjets->at(i),140.0,250.0))
       if(variableMassHepTopTag(bcc->toptagjets->at(i),200,0.505,1.495,0.35,0.35,140,250))
       {
// 	 Hist("mistag_tagged")->Fill(bcc->toptagjets->at(i).pt(),weight);
// 	 if(iscsvl) {Hist("mistag_tagged_cvsl")->Fill(bcc->toptagjets->at(i).pt(),weight);}
// 	 if(iscsvm) {Hist("mistag_tagged_cvsm")->Fill(bcc->toptagjets->at(i).pt(),weight);}
	  if (genparticles->at(bestjetindex).pt()>400.0) Hist("pT_s1_cms_tagged_mis400hep")->Fill(genparticles->at(bestjetindex).pt(),weight);
	  if (genparticles->at(bestjetindex).pt()>600.0) Hist("pT_s1_cms_tagged_mis600hep")->Fill(genparticles->at(bestjetindex).pt(),weight);
	  if (genparticles->at(bestjetindex).pt()>800.0) Hist("pT_s1_cms_tagged_mis800hep")->Fill(genparticles->at(bestjetindex).pt(),weight);

	 Hist("mistag_tagged")->Fill(genparticles->at(bestjetindex).pt(),weight);
	 /*  if (genparticles->at(bestjetindex).pt()>400.0) Hist("pT_s1_cms_tagged_mis400")->Fill(genparticles->at(bestjetindex).pt(),weight);
	 if (genparticles->at(bestjetindex).pt()>600.0) Hist("pT_s1_cms_tagged_mis600")->Fill(genparticles->at(bestjetindex).pt(),weight);
	 if (genparticles->at(bestjetindex).pt()>800.0) Hist("pT_s1_cms_tagged_mis800")->Fill(genparticles->at(bestjetindex).pt(),weight);*/
	     
	 if(iscsvl) {Hist("mistag_tagged_cvsl")->Fill(genparticles->at(bestjetindex).pt(),weight);}
	 if(iscsvm) {Hist("mistag_tagged_cvsm")->Fill(genparticles->at(bestjetindex).pt(),weight);}
       }
  
  double nsub = getNsub(bcc,i);
  
  for (unsigned int var_w_count=0; var_w_count<nsteps; var_w_count++)
  {
    bool isheptoptagged = variableMassHepTopTag(bcc->toptagjets->at(i), 
	200.0, 
	1.0-w_step*var_w_count-w_step/2.0,//0.85, 
	1.0+w_step*var_w_count+w_step/2.0,//1.15,
	0.35, 
	0.35,
	140.0,
	250.0);
    for (unsigned int var_nsub_count=0; var_nsub_count<nsteps; var_nsub_count++)
    {
      for (unsigned int var_csv_count=0; var_csv_count<nsteps; var_csv_count++)
      {
	if(
	  isheptoptagged&&
	  (nsub<(nsubmin+nsub_step*var_nsub_count+nsub_step/2.0))&&
	  (bestcsv>(csvmin+csv_step*var_csv_count+csv_step/2.0))
	) 
	{
	  if (genparticles->at(bestjetindex).pt()>200.0) ((TH3D*)Hist("mistag_roc_tagged200"))->Fill( w_step*var_w_count+w_step/2.0 , nsubmin+nsub_step*var_nsub_count+nsub_step/2.0 , csvmin+csv_step*var_csv_count+csv_step/2.0 , weight );
	  if (genparticles->at(bestjetindex).pt()>400.0) ((TH3D*)Hist("mistag_roc_tagged400"))->Fill( w_step*var_w_count+w_step/2.0 , nsubmin+nsub_step*var_nsub_count+nsub_step/2.0 , csvmin+csv_step*var_csv_count+csv_step/2.0 , weight );
	  if (genparticles->at(bestjetindex).pt()>600.0) ((TH3D*)Hist("mistag_roc_tagged600"))->Fill( w_step*var_w_count+w_step/2.0 , nsubmin+nsub_step*var_nsub_count+nsub_step/2.0 , csvmin+csv_step*var_csv_count+csv_step/2.0 , weight );
	  if (genparticles->at(bestjetindex).pt()>800.0) ((TH3D*)Hist("mistag_roc_tagged800"))->Fill( w_step*var_w_count+w_step/2.0 , nsubmin+nsub_step*var_nsub_count+nsub_step/2.0 , csvmin+csv_step*var_csv_count+csv_step/2.0 , weight );
	  
	
		
// 	((TH3D*)Hist("mistag_roc_tagged"))->Fill( w_step*var_w_count+w_step/2.0 , 0.5+nsub_step*var_nsub_count+nsub_step/2.0 , bcc->toptagjets->at(i).pt() , weight );
// 	if (iscsvl) {((TH3D*)Hist("mistag_roc_tagged_cvsl"))->Fill( w_step*var_w_count+w_step/2.0 , 0.5+nsub_step*var_nsub_count+nsub_step/2.0 , bcc->toptagjets->at(i).pt() , weight );}
// 	if (iscsvm) {((TH3D*)Hist("mistag_roc_tagged_cvsm"))->Fill( w_step*var_w_count+w_step/2.0 , 0.5+nsub_step*var_nsub_count+nsub_step/2.0 , bcc->toptagjets->at(i).pt() , weight );}
//         ((TH3D*)Hist("mistag_roc_tagged"))->Fill( w_step*var_w_count+w_step/2.0 , 0.5+nsub_step*var_nsub_count+nsub_step/2.0 , genparticles->at(bestjetindex).pt() , weight );
// 	if (iscsvl) {((TH3D*)Hist("mistag_roc_tagged_cvsl"))->Fill( w_step*var_w_count+w_step/2.0 , 0.5+nsub_step*var_nsub_count+nsub_step/2.0 , genparticles->at(bestjetindex).pt() , weight );}
// 	if (iscsvm) {((TH3D*)Hist("mistag_roc_tagged_cvsm"))->Fill( w_step*var_w_count+w_step/2.0 , 0.5+nsub_step*var_nsub_count+nsub_step/2.0 , genparticles->at(bestjetindex).pt() , weight );}
	}
      }
    }
  }
  

     
     }   ////
   }
   //TL
   sort(bcc->topjets->begin(), bcc->topjets->end(), HigherPt());
     for(unsigned int i=0; i<bcc->topjets->size(); ++i)
   {
     //minDeltaR=10000;
     double highestPt=-1;
     bestjetindex=-1;
     for(unsigned int j=0; j<genparticles->size();j++)
     {
       if (abs(genparticles->at(j).pdgId())<=6 || abs(genparticles->at(j).pdgId())==21)
       {
	 if (bcc->topjets->at(i).deltaR(genparticles->at(j))<1.0 && genparticles->at(j).pt()>highestPt)
	 {
	  bestjetindex=j;
	  highestPt=genparticles->at(j).pt();
	  //minDeltaR=bcc->toptagjets->at(i).deltaR(genparticles->at(j));
	  }
       }
       }
     //  bestjetindex=-1;
	   if (bestjetindex>-1){
      	 double mva_value=100;
	  TopJet Ca8jet=bcc->topjets->at(i);
	  if(Ca8jet.pt()>350 && i<2){ 
	    //for (unsigned int k =0; k<bcc->higgstagjets->size(); ++k){
	      //TopJet CA15jet =  bcc->higgstagjets->at(k);
	      //if((sqrt(pow(Ca8jet.phi()-CA15jet.phi(),2)+pow(Ca8jet.eta()-CA15jet.eta(),2))<1.5)){
	    //  tmva_tagger->IsTagged("TLflat",Ca8jet,0.766,mva_value);
	    
	    /*  tmva_tagger->IsTagged("TLflat",Ca8jet,0.766,mva_value);
	  if (genparticles->at(bestjetindex).pt()>200.0) Hist("MVA200")->Fill(mva_value,weight);
	  if (genparticles->at(bestjetindex).pt()>400.0) Hist("MVA400")->Fill(mva_value,weight);
	  if (genparticles->at(bestjetindex).pt()>600.0) Hist("MVA600")->Fill(mva_value,weight);
	  if (genparticles->at(bestjetindex).pt()>800.0) Hist("MVA800")->Fill(mva_value,weight);*/
	
	 
	  if(genparticles->at(bestjetindex).pt()>350)  Hist("MVA_pT")->Fill(genparticles->at(bestjetindex).pt(),weight);
	  // if(genparticles->at(bestjetindex).pt()>350) tmva_tagger2->push_variables(Ca8jet);
	  // if(genparticles->at(bestjetindex).pt()>350) if(tmva_tagger2->IsTagged("simple_cuts",Ca8jet,0.9,mva_value))  Hist("MVA_2")->Fill(genparticles->at(bestjetindex).pt(),weight);
	    /* if (Had_Tops[j].pt()<300.0) Hist("MVA300_2")->Fill(mva_value,weight);
	  if (Had_Tops[j].pt()>300.0 && Had_Tops[j].pt()<500.0) Hist("MVA500_2")->Fill(mva_value,weight);
	  if (Had_Tops[j].pt()>500.0 && Had_Tops[j].pt()<700.0) Hist("MVA700_2")->Fill(mva_value,weight);
	  if (Had_Tops[j].pt()>700.0) Hist("MVA700inf_2")->Fill(mva_value,weight);
	  std::cout<<"MVA value "<<mva_value<<std::endl; */
	  /*   if(genparticles->at(bestjetindex).pt()>350){
	  if (genparticles->at(bestjetindex).pt()<300.0 &&   tmva_tagger2->IsTagged("simple_cuts300",Ca8jet,0.9,mva_value)) Hist("MVAsingle_2")->Fill(genparticles->at(bestjetindex).pt(),weight);
	  if (genparticles->at(bestjetindex).pt()>300.0 && genparticles->at(bestjetindex).pt()<500.0  &&   tmva_tagger2->IsTagged("simple_cuts500",Ca8jet,0.9,mva_value)) Hist("MVAsingle_2")->Fill(genparticles->at(bestjetindex).pt(),weight);
	  if (genparticles->at(bestjetindex).pt()>500.0 && genparticles->at(bestjetindex).pt()<700.0  &&   tmva_tagger2->IsTagged("simple_cuts700",Ca8jet,0.9,mva_value)) Hist("MVAsingle_2")->Fill(genparticles->at(bestjetindex).pt(),weight);
	  if (genparticles->at(bestjetindex).pt()>700.0  &&   tmva_tagger2->IsTagged("simple_cutsInf",Ca8jet,0.9,mva_value)) Hist("MVAsingle_2")->Fill(genparticles->at(bestjetindex).pt(),weight);
	   }
	  
	   
	   tmva_tagger2->reset_variables();*/
	 double mmin_jet=0;
	 double mjet2=0;
	 int nsubjets2=0;
	  //TopTag(Ca8jet,mjet,nsubjets,mmin);
	       
	       TopTag(Ca8jet,mjet2,nsubjets2,mmin_jet);	

	 //variableR
	fastjet::ClusterSequence clustersq;
	double subjetmass,mmin2,rho;
	if(Ca8jet.pt()>400) fastjet::PseudoJet varRJet= varR->Get_varRSubJet(Ca8jet, calc->GetPFParticles(), 0, 3.0, clustersq,subjetmass,mmin2,rho);
	 if(Ca8jet.pt()>400) Hist("Jetmass2")->Fill(Ca8jet.v4().M(),weight);
	 if(Ca8jet.pt()>400) Hist("Subjetmass2")->Fill(subjetmass,weight);
	 if(Ca8jet.pt()>400) Hist("mmin2")->Fill(mmin2,weight);
	 if(Ca8jet.pt()>400) Hist("mmin3")->Fill(mmin_jet,weight);
	 if(Ca8jet.pt()>400) Hist("rho")->Fill(rho,weight);
	 if(rho>50 && mmin2>50 && subjetmass>140 && subjetmass<250) Hist("TL_pt")->Fill(genparticles->at(bestjetindex).pt(),weight);
	 if( TopTag(Ca8jet,mjet2,nsubjets2,mmin_jet)) Hist("CMS_pt")->Fill(genparticles->at(bestjetindex).pt(),weight);
	
	 //jetshapes
	  double m_psi_02 = calc->IntegratedJetShape( &Ca8jet, 0.2, 0.0 , e_CA8);
	  double m_psi_04 = calc->IntegratedJetShape( &Ca8jet, 0.4, 0.0 , e_CA8);
	  double m_psi_06 = calc->IntegratedJetShape( &Ca8jet, 0.6, 0.0 , e_CA8);
	  double m_psi_08 = calc->IntegratedJetShape( &Ca8jet, 0.8, 0.0 , e_CA8);
	  double m_psi_10 = calc->IntegratedJetShape( &Ca8jet, 1.0, 0.0 , e_CA8);
	  Hist("psi02_ly")->Fill(m_psi_02,weight);
	  Hist("psi04_ly")->Fill(m_psi_04,weight);
	  Hist("psi06_ly")->Fill(m_psi_06,weight);
	  Hist("psi08_ly")->Fill(m_psi_08,weight);
	  Hist("psi10_ly")->Fill(m_psi_10,weight);


	  //helicity angles
	  
	  double subjet1pt;
	  double subjet2pt;
	  double subjet3pt;
	  double HelAng12;
	  double HelAng13;
	  double HelAng23;
	  std::vector<Particle> subjet = Ca8jet.subjets();
	  int Nsubjets=subjet.size();
	  sort(subjet.begin(),subjet.end(),HigherPt());
	  if(Nsubjets>0) subjet1pt=sqrt(pow(subjet[0].v4().Px(),2)+pow(subjet[0].v4().Py(),2));
	  if(Nsubjets>1){
	    TLorentzVector subjet1(subjet[0].v4().Px(),subjet[0].v4().Py(),subjet[0].v4().Pz(),subjet[0].v4().E());
	    TLorentzVector subjet2(subjet[1].v4().Px(),subjet[1].v4().Py(),subjet[1].v4().Pz(),subjet[1].v4().E());
	    subjet1pt=sqrt(pow(subjet[0].v4().Px(),2)+pow(subjet[0].v4().Py(),2));
	    subjet2pt=sqrt(pow(subjet[1].v4().Px(),2)+pow(subjet[1].v4().Py(),2));
	    HelAng12= HelicityAngle(subjet1,subjet2);
	  }
	  if(Nsubjets>2){
	    TLorentzVector subjet1(subjet[0].v4().Px(),subjet[0].v4().Py(),subjet[0].v4().Pz(),subjet[0].v4().E());
	    TLorentzVector subjet2(subjet[1].v4().Px(),subjet[1].v4().Py(),subjet[1].v4().Pz(),subjet[1].v4().E());
	    TLorentzVector subjet3(subjet[2].v4().Px(),subjet[2].v4().Py(),subjet[2].v4().Pz(),subjet[2].v4().E());
	    subjet1pt=sqrt(pow(subjet[0].v4().Px(),2)+pow(subjet[0].v4().Py(),2));
	    subjet2pt=sqrt(pow(subjet[1].v4().Px(),2)+pow(subjet[1].v4().Py(),2));
	    subjet3pt=sqrt(pow(subjet[2].v4().Px(),2)+pow(subjet[2].v4().Py(),2));
	    HelAng12= HelicityAngle(subjet1,subjet2);
	    HelAng13= HelicityAngle(subjet1,subjet3);
	    HelAng23= HelicityAngle(subjet2,subjet3);
	  }
	  if(HelAng12!=0) Hist("HelAng12")->Fill(HelAng12,weight);
	  if(HelAng13!=0) Hist("HelAng13")->Fill(HelAng13,weight);
	  if(HelAng23!=0) Hist("HelAng23")->Fill(HelAng23,weight);



	  /* tmva_tagger->IsTagged("pf_bdt",Ca8jet,0.766,mva_value);
	 
	   if (genparticles->at(bestjetindex).pt()>200.0)  Hist("MVA200")->Fill(mva_value,weight);
	   if (genparticles->at(bestjetindex).pt()>400.0)   Hist("MVA400")->Fill(mva_value,weight);
	   if (genparticles->at(bestjetindex).pt()>600.0)  Hist("MVA600")->Fill(mva_value,weight);
	   if (genparticles->at(bestjetindex).pt()>800.0)  Hist("MVA800")->Fill(mva_value,weight);*/
	   if(subJetBTag(Ca8jet,e_CSVM)>=1)
	     {
	        if (genparticles->at(bestjetindex).pt()>200.0)  Hist("MVA200btag")->Fill(mva_value,weight);
		if (genparticles->at(bestjetindex).pt()>400.0)   Hist("MVA400btag")->Fill(mva_value,weight);
		if (genparticles->at(bestjetindex).pt()>600.0)  Hist("MVA600btag")->Fill(mva_value,weight);
		if (genparticles->at(bestjetindex).pt()>800.0)  Hist("MVA800btag")->Fill(mva_value,weight);
	     }
	 
	   //sd
	   double bestcsv2=0;
	   if (bcc->topjets->at(i).subCSV().at(0)>bestcsv2) bestcsv2=bcc->topjets->at(i).subCSV().at(0);
	   if(Ca8jet.numberOfDaughters()>1) if (bcc->topjets->at(i).subCSV().at(1)>bestcsv2) bestcsv2=bcc->topjets->at(i).subCSV( \
																			 ).at(1);
	   if(Ca8jet.numberOfDaughters()>2) if (bcc->topjets->at(i).subCSV().at(2)>bestcsv2) bestcsv2=bcc->topjets->at(i).subCSV(\
																																 ).at(2);

	       /*	       double jetm01,jetm02,jetm03,jetm04;
	       jetm01=jwj->SubjetMultiplicity(Ca8jet, calc->GetPFParticles(),0.05,0.1);
	       jetm02=jwj->SubjetMultiplicity(Ca8jet, calc->GetPFParticles(),0.05,0.2);
	       jetm03=jwj->SubjetMultiplicity(Ca8jet, calc->GetPFParticles(),0.05,0.3);
	       jetm04=jwj->SubjetMultiplicity(Ca8jet, calc->GetPFParticles(),0.05,0.4);
	   Hist("Jetm00bkg")->Fill(nsubjets2,weight);
	   Hist("Jetm01bkg")->Fill(jetm01,weight);
	   Hist("Jetm02bkg")->Fill(jetm01,weight);
	   Hist("Jetm03bkg")->Fill(jetm01,weight);
	   Hist("Jetm04bkg")->Fill(jetm01,weight);

	   if(Ca8jet.pt()>400){
	     Hist("Jetm00bkg_400")->Fill(nsubjets2,weight);
	   Hist("Jetm01bkg_400")->Fill(jetm01,weight);
	   Hist("Jetm02bkg_400")->Fill(jetm02,weight);
	   Hist("Jetm03bkg_400")->Fill(jetm03,weight);
	   Hist("Jetm04bkg_400")->Fill(jetm04,weight);
	   }

	    if(Ca8jet.pt()>600){
	     Hist("Jetm00bkg_600")->Fill(nsubjets2,weight);
	   Hist("Jetm01bkg_600")->Fill(jetm01,weight);
	   Hist("Jetm02bkg_600")->Fill(jetm02,weight);
	   Hist("Jetm03bkg_600")->Fill(jetm03,weight);
	   Hist("Jetm04bkg_600")->Fill(jetm04,weight);
	   }

	     if(Ca8jet.pt()>800){
	     Hist("Jetm00bkg_800")->Fill(nsubjets2,weight);
	   Hist("Jetm01bkg_800")->Fill(jetm01,weight);
	   Hist("Jetm02bkg_800")->Fill(jetm02,weight);
	   Hist("Jetm03bkg_800")->Fill(jetm03,weight);
	   Hist("Jetm04bkg_800")->Fill(jetm04,weight);
	   }

	     //ecf
	  double c3=ecf->Get_C(Ca8jet,calc->GetPFParticles(), 3, 1.0);
	  double d3=ecf->Get_D3(Ca8jet,calc->GetPFParticles(),2.,0.8,0.6);
	  if(Ca8jet.pt()>500) Hist("ecf_c3_bkg")->Fill(c3,weight);
	  if(Ca8jet.pt()>500) Hist("ecf_d3_bkg")->Fill(d3,weight);
	  if(Ca8jet.pt()>500 && mjet2>140 && mjet2<250) {
	    Hist("ecf_c3_mass_bkg")->Fill(c3,weight);
	    Hist("ecf_d3_mass_bkg")->Fill(d3,weight);
	  }
	       */

 //qjet volatility
	  /*    JetProps jp(&Ca8jet, calc->GetPFParticles() );
	    double qjet_mmin=jp.GetQjetVolatility_mmin(calc->GetEventNum(),0.8);
	    double qjet_mass=jp.GetQjetVolatility(calc->GetEventNum(),0.8);
	    double qjet_nsubjets=jp.GetQjetVolatility_nsubjets(calc->GetEventNum(),0.8);
	    double qjet_nsubjettiness1= jp.GetQjetVolatility_Nsubjettiness(calc->GetEventNum(), 0.8, 1, Njettiness::onepass_kt_axes , 1.);
	    double qjet_nsubjettiness2= jp.GetQjetVolatility_Nsubjettiness(calc->GetEventNum(), 0.8, 2, Njettiness::onepass_kt_axes , 1.);
	    double qjet_nsubjettiness3= jp.GetQjetVolatility_Nsubjettiness(calc->GetEventNum(), 0.8, 3, Njettiness::onepass_kt_axes , 1.);
	    
	      //std::cout<<"volatility "<<qjet_mmin<<std::endl;
	    Hist("Qvolatility_mmin_bkg")->Fill(qjet_mmin,weight);
	    Hist("Qvolatility_mass_bkg")->Fill(qjet_mass,weight);
	    Hist("Qvolatility_nsubjets_bkg")->Fill(qjet_nsubjets,weight);
	    Hist("Qvolatility_nsubjettiness1_bkg")->Fill(qjet_nsubjettiness1,weight);
	    Hist("Qvolatility_nsubjettiness2_bkg")->Fill(qjet_nsubjettiness2,weight);
	    Hist("Qvolatility_nsubjettiness3_bkg")->Fill(qjet_nsubjettiness3,weight);
	  */
	 
	  //TopTag(Ca8jet,mjet,nsubjets,mmin);
	  TopTag(Ca8jet,mjet2,nsubjets2,mmin_jet);
	  /* if(TopTag(Ca8jet,mjet2,nsubjets2,mmin_jet)){
	    Hist("Qvolatility_mmin_cms_bkg")->Fill(qjet_mmin,weight);
	    Hist("Qvolatility_mass_cms_bkg")->Fill(qjet_mass,weight);
	    Hist("Qvolatility_nsubjets_cms_bkg")->Fill(qjet_nsubjets,weight);
	    Hist("Qvolatility_nsubjettiness1_cms_bkg")->Fill(qjet_nsubjettiness1,weight);
	    Hist("Qvolatility_nsubjettiness2_cms_bkg")->Fill(qjet_nsubjettiness2,weight);
	    Hist("Qvolatility_nsubjettiness3_cms_bkg")->Fill(qjet_nsubjettiness3,weight);
	  }
	    
	  */						   



	   double Mmicrojet=0;
	       std::vector<fastjet::PseudoJet> microjets;
	       int Nmicrojets=0;
	       double chi=0;
	       double microconesize=0.3;
	       if(genparticles->at(bestjetindex).pt()>500) microconesize=0.2;
	       if(genparticles->at(bestjetindex).pt()>700) microconesize=0.1;
	       //if(Ca8jet.pt()>800) microconesize=0.05;
	       // if(genparticles->at(bestjetindex).pt()>500) chi = Showerdeconstruction_taggerV2->ChiMicro_btag(Ca8jet,Nmicrojets,Mmicrojet,microconesize,microjets);
	       //else chi= Showerdeconstruction_taggerV2->ChiMicro_btag(Ca8jet,Nmicrojets,Mmicrojet,microconesize,microjets);
	       if (genparticles->at(bestjetindex).pt()>200.0) Hist("SD_fine200mis")->Fill(log(chi));
	       if (genparticles->at(bestjetindex).pt()>400.0)  Hist("SD_fine400mis")->Fill(log(chi));
	       if (genparticles->at(bestjetindex).pt()>600.0)  Hist("SD_fine600mis")->Fill(log(chi));
	       if (genparticles->at(bestjetindex).pt()>800.0)  Hist("SD_fine800mis")->Fill(log(chi));
	       //if(subJetBTag(Ca8jet,e_CSVM)>=1){
	       double tau3=Ca8jet.tau3();
	       double tau2=Ca8jet.tau2();
	       for(unsigned int c=0;c<50;c++){
		 double nsub=(double)c/50.;
		 if(tau3/tau2<nsub){
		   if (genparticles->at(bestjetindex).pt()>200.0) Hist("SD_fine200misnsub")->Fill(log(chi),nsub);
		   if (genparticles->at(bestjetindex).pt()>400.0)  Hist("SD_fine400misnsub")->Fill(log(chi),nsub);
		   if (genparticles->at(bestjetindex).pt()>600.0)  Hist("SD_fine600misnsub")->Fill(log(chi),nsub);
		   if (genparticles->at(bestjetindex).pt()>800.0)  Hist("SD_fine800misnsub")->Fill(log(chi),nsub);
		 }
	       }
	        //----mmin-------
	       
	       for(unsigned int c=0;c<50;c++){
		 double mmin_var=(double)c/50.*150.;
		 if(mmin_jet>mmin_var){
		   if (genparticles->at(bestjetindex).pt()>200.0) Hist("SD_fine200mismmin")->Fill(log(chi),mmin_var);
		   if (genparticles->at(bestjetindex).pt()>400.0)  Hist("SD_fine400mismmin")->Fill(log(chi),mmin_var);
		   if (genparticles->at(bestjetindex).pt()>600.0)  Hist("SD_fine600mismmin")->Fill(log(chi),mmin_var);
		   if (genparticles->at(bestjetindex).pt()>800.0)  Hist("SD_fine800mismmin")->Fill(log(chi),mmin_var);
		 }
	       }
	       for(unsigned int c=0;c<50;c++){
		  double bdt;
		  /* if(c<25) bdt=(double)c/(-25.);
		     else bdt=(double)(c-24)/25.;*/
		  bdt=(double)c/25.;
		  std::cout<<bdt<<std::endl;
		  if(mva_value+1<bdt){
		    if (genparticles->at(bestjetindex).pt()>200.0) ((TH2D*)Hist("SD_fine200misbdt"))->Fill(log(chi),bdt-1,weight);
		    if (genparticles->at(bestjetindex).pt()>400.0)  ((TH2D*)Hist("SD_fine400misbdt"))->Fill(log(chi),bdt-1,weight);
		    if (genparticles->at(bestjetindex).pt()>600.0) ((TH2D*) Hist("SD_fine600misbdt"))->Fill(log(chi),bdt-1,weight);
		    if (genparticles->at(bestjetindex).pt()>800.0)  ((TH2D*)Hist("SD_fine800misbdt"))->Fill(log(chi),bdt-1,weight);
		 }
	       }
	       for(unsigned int c=0;c<50;c++){
		 double csv=(double)c/50.;
		 std::cout<<"bestcsv"<<bestcsv2<<" csv"<<c<<std::endl;
                 if(bestcsv2>csv){
		   if (genparticles->at(bestjetindex).pt()>200.0)  Hist("SD_fine200misbtag")->Fill(log(chi),csv);
		   if (genparticles->at(bestjetindex).pt()>400.0)  Hist("SD_fine400misbtag")->Fill(log(chi),csv);
		   if (genparticles->at(bestjetindex).pt()>600.0)  Hist("SD_fine600misbtag")->Fill(log(chi),csv);
		   if (genparticles->at(bestjetindex).pt()>800.0)  Hist("SD_fine800misbtag")->Fill(log(chi),csv);
		 }
	       }
		  //}
	       // }
	     
	       //}
	 
	     double mmin=0;
	   double mjet=0;
	   int nsubjets=0;
	   //TopTag(Ca8jet,mjet,nsubjets,mmin);
	   if(TopTag(Ca8jet,mjet,nsubjets,mmin) && Ca8jet.pt()>350 && i<2) {
	   // if(mjet>140 && mjet<250 && Ca8jet.pt()>350 && mmin>50 && i<2){
	   //  if(variableMassHepTopTag(Ca8jet,200,0.505,1.495,0.35,0.35,140,250)){
	     if (genparticles->at(bestjetindex).pt()>400.0) Hist("pT_s1_cms_tagged_mis400")->Fill(genparticles->at(bestjetindex).pt(),weight);
	    if (genparticles->at(bestjetindex).pt()>600.0) Hist("pT_s1_cms_tagged_mis600")->Fill(genparticles->at(bestjetindex).pt(),weight);
	    if (genparticles->at(bestjetindex).pt()>800.0) Hist("pT_s1_cms_tagged_mis800")->Fill(genparticles->at(bestjetindex).pt(),weight);
	     
	    }
	   // Hist("pT_s1_mis")->Fill(genparticles->at(bestjetindex).pt(),weight);
	   if(Ca8jet.pt()>350 && i<2){
	     //  std::cout<<i<<std::endl;
	      if (genparticles->at(bestjetindex).pt()>400.0) Hist("pT_s1_mis400")->Fill(genparticles->at(bestjetindex).pt(),weight);
	     if (genparticles->at(bestjetindex).pt()>600.0) Hist("pT_s1_mis600")->Fill(genparticles->at(bestjetindex).pt(),weight);
	     if (genparticles->at(bestjetindex).pt()>800.0) Hist("pT_s1_mis800")->Fill(genparticles->at(bestjetindex).pt(),weight);

	   
	   }
	  }
	   
	   }
   
       
	 }
  
  
    
    
  }
  
  
  
  
  //##########################################################
  
  
  
  
  
  
  
  
  
  
  
    /*subjets_top=bcc->toptagjets->at(i).subjets();
    btagsub_combinedSecondaryVertex_top=bcc->toptagjets->at(i).btagsub_combinedSecondaryVertex();
    
    for(unsigned int j=0; j < btagsub_combinedSecondaryVertex_top.size(); ++j){
      
      float test=btagsub_combinedSecondaryVertex_top[j];

      //if(test>0.244) jettagged=1;
      if(test>0.679) jettagged=1;
      //if(test>0.898) jettagged=1;
      
    }

    jettagged=0;
*/
    
    
    //#####################
    if(!IsRealData && idVersion=="QCD15to3000")
    {    
      for(unsigned int i=0; i<bcc->toptagjets->size(); ++i) {
	//int jettagged=0;
	
	bool is_csv=false;
	if(bcc->toptagjets->at(i).subCSV().at(0)>0.679 ||
	  bcc->toptagjets->at(i).subCSV().at(1)>0.679 ||
	  bcc->toptagjets->at(i).subCSV().at(2)>0.679)
	{is_csv=true;}
	bool is_httagged=variableMassHepTopTag(bcc->toptagjets->at(i), 200.0, 0.85, 1.15, 0.35, 0.35, 0.0 , 100000.0);
	double nsubjettiness=getNsub(bcc,i);
	bool is_nsub = nsubjettiness<0.7;
	if (bcc->toptagjets->at(i).pt()>200.0)
	{
	  Hist("Nsub")->Fill(nsubjettiness,1);
	  Hist("Jetmass")->Fill(TopJetMass(bcc->toptagjets->at(i)),1);
	  Hist("JetmassW")->Fill(TopJetMass(bcc->toptagjets->at(i)),weight);
	  double m_m=0.0;
	  if (bcc->toptagjets->at(i).v4().isTimelike()) m_m=bcc->toptagjets->at(i).v4().M();
	  Hist("Jetmass_m")->Fill(m_m,1);
	  int mca15i=getMatchedCA15Index(bcc,i);
	  if (mca15i>=0)
	  {
	    Hist("JetmassCA15")->Fill(TopJetMass(bcc->topjets->at(mca15i)),1);
	    m_m=0.0;
	    if (bcc->topjets->at(mca15i).v4().isTimelike()) m_m=bcc->topjets->at(mca15i).v4().M();
	    Hist("JetmassCA15_m")->Fill(m_m,1);
	  }
	  if (is_httagged)
	  {
	    Hist("Nsub_tagged")->Fill(nsubjettiness,weight);
	    Hist("Jetmass_tagged")->Fill(TopJetMass(bcc->toptagjets->at(i)),1);
	    Hist("Jetmass_taggedW")->Fill(TopJetMass(bcc->toptagjets->at(i)),weight);
	    Hist("weight")->Fill(weight);
	  }
	}
// 	if (bcc->toptagjets->at(i).pt()>200.0)
// 	{
// 	  Hist("Npv200_all")->Fill(Npvs,1);
// 	  if (is_httagged) Hist("Npv200_htt_tagged")->Fill(Npvs,1);
// 	  if (is_httagged && is_nsub) Hist("Npv200_httnsub_tagged")->Fill(Npvs,1);
// 	  if (is_httagged && is_csv) Hist("Npv200_httcsv_tagged")->Fill(Npvs,1);
// 	  if (is_httagged && is_nsub && is_csv) Hist("Npv200_httnsubcsv_tagged")->Fill(Npvs,1);
// 	  if (bcc->toptagjets->at(i).pt()>300.0)
// 	  {
// 	    Hist("Npv300_all")->Fill(Npvs,1);
// 	    if (is_httagged) Hist("Npv300_htt_tagged")->Fill(Npvs,1);
// 	    if (is_httagged && is_nsub) Hist("Npv300_httnsub_tagged")->Fill(Npvs,1);
// 	    if (is_httagged && is_csv) Hist("Npv300_httcsv_tagged")->Fill(Npvs,1);
// 	    if (is_httagged && is_nsub && is_csv) Hist("Npv300_httnsubcsv_tagged")->Fill(Npvs,1);
// 	    if (bcc->toptagjets->at(i).pt()>400.0)
// 	    {
// 	      Hist("Npv400_all")->Fill(Npvs,1);
// 	      if (is_httagged) Hist("Npv400_htt_tagged")->Fill(Npvs,1);
// 	      if (is_httagged && is_nsub) Hist("Npv400_httnsub_tagged")->Fill(Npvs,1);
// 	      if (is_httagged && is_csv) Hist("Npv400_httcsv_tagged")->Fill(Npvs,1);
// 	      if (is_httagged && is_nsub && is_csv) Hist("Npv400_httnsubcsv_tagged")->Fill(Npvs,1);
// 	      if (bcc->toptagjets->at(i).pt()>500.0)
// 	      {
// 		Hist("Npv500_all")->Fill(Npvs,1);
// 		if (is_httagged) Hist("Npv500_htt_tagged")->Fill(Npvs,1);
// 		if (is_httagged && is_nsub) Hist("Npv500_httnsub_tagged")->Fill(Npvs,1);
// 		if (is_httagged && is_csv) Hist("Npv500_httcsv_tagged")->Fill(Npvs,1);
// 		if (is_httagged && is_nsub && is_csv) Hist("Npv500_httnsubcsv_tagged")->Fill(Npvs,1);
// 		if (bcc->toptagjets->at(i).pt()>600.0)
// 		{
// 		  Hist("Npv600_all")->Fill(Npvs,1);
// 		  if (is_httagged) Hist("Npv600_htt_tagged")->Fill(Npvs,1);
// 		  if (is_httagged && is_nsub) Hist("Npv600_httnsub_tagged")->Fill(Npvs,1);
// 		  if (is_httagged && is_csv) Hist("Npv600_httcsv_tagged")->Fill(Npvs,1);
// 		  if (is_httagged && is_nsub && is_csv) Hist("Npv600_httnsubcsv_tagged")->Fill(Npvs,1);
// 		}
// 	      }
// 	    }
// 	  }
// 	}
      }
    }
    
    if(!IsRealData && (idVersion=="TTbarEff" || idVersion=="TTbarEff_1" || idVersion=="TTbarEff_2" || idVersion=="TTbarEff_3"))
    {
      TTbarGen* Decay = calc->GetTTbarGen();
      std::vector<GenParticle> Had_Tops;
      bool isHadronic=false;
      if (Decay->IsTopHadronicDecay()) Had_Tops.push_back(Decay->Top());
      if (Decay->IsAntiTopHadronicDecay()) Had_Tops.push_back(Decay->Antitop());
      int oldbestjet=-1;
      int  oldbestjet2=-1;
      for (unsigned int j=0; j<Had_Tops.size(); j++)
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
	if (minDeltaR>1.0) bestjetindex=-1;//protect against large deltaR
	if((bestjetindex>-1) && (bestjetindex!=oldbestjet))
	{
	  oldbestjet=bestjetindex;
	  bool is_csv=false;
	  if(bcc->toptagjets->at(bestjetindex).subCSV().at(0)>0.679 ||
	    bcc->toptagjets->at(bestjetindex).subCSV().at(1)>0.679 ||
	    bcc->toptagjets->at(bestjetindex).subCSV().at(2)>0.679)
	  {is_csv=true;}
	  bool is_httagged=variableMassHepTopTag(bcc->toptagjets->at(bestjetindex), 200.0, 0.85, 1.15, 0.35, 0.35, 0.0 , 100000.0);
	  double nsubjettiness=getNsub(bcc,bestjetindex);
	  bool is_nsub = nsubjettiness<0.7;
	  if (bcc->toptagjets->at(bestjetindex).pt()>200.0)
	  {
	    Hist("Nsub")->Fill(nsubjettiness,1);
	    Hist("Jetmass")->Fill(TopJetMass(bcc->toptagjets->at(bestjetindex)),1);
	    if (is_httagged)
	    {
	      Hist("Nsub_tagged")->Fill(nsubjettiness,1);
	      Hist("Jetmass_tagged")->Fill(TopJetMass(bcc->toptagjets->at(bestjetindex)),1);
	    }
	  }
/*	  if (bcc->toptagjets->at(bestjetindex).pt()>200.0)
	  {
	    Hist("Npv200_all")->Fill(Npvs,1);
	    if (is_httagged) Hist("Npv200_htt_tagged")->Fill(Npvs,1);
	    if (is_httagged && is_nsub) Hist("Npv200_httnsub_tagged")->Fill(Npvs,1);
	    if (is_httagged && is_csv) Hist("Npv200_httcsv_tagged")->Fill(Npvs,1);
	    if (is_httagged && is_nsub && is_csv) Hist("Npv200_httnsubcsv_tagged")->Fill(Npvs,1);
	    if (bcc->toptagjets->at(bestjetindex).pt()>300.0)
	    {
	      Hist("Npv300_all")->Fill(Npvs,1);
	      if (is_httagged) Hist("Npv300_htt_tagged")->Fill(Npvs,1);
	      if (is_httagged && is_nsub) Hist("Npv300_httnsub_tagged")->Fill(Npvs,1);
	      if (is_httagged && is_csv) Hist("Npv300_httcsv_tagged")->Fill(Npvs,1);
	      if (is_httagged && is_nsub && is_csv) Hist("Npv300_httnsubcsv_tagged")->Fill(Npvs,1);
	      if (bcc->toptagjets->at(bestjetindex).pt()>400.0)
	      {
		Hist("Npv400_all")->Fill(Npvs,1);
		if (is_httagged) Hist("Npv400_htt_tagged")->Fill(Npvs,1);
		if (is_httagged && is_nsub) Hist("Npv400_httnsub_tagged")->Fill(Npvs,1);
		if (is_httagged && is_csv) Hist("Npv400_httcsv_tagged")->Fill(Npvs,1);
		if (is_httagged && is_nsub && is_csv) Hist("Npv400_httnsubcsv_tagged")->Fill(Npvs,1);
		if (bcc->toptagjets->at(bestjetindex).pt()>500.0)
		{
		  Hist("Npv500_all")->Fill(Npvs,1);
		  if (is_httagged) Hist("Npv500_htt_tagged")->Fill(Npvs,1);
		  if (is_httagged && is_nsub) Hist("Npv500_httnsub_tagged")->Fill(Npvs,1);
		  if (is_httagged && is_csv) Hist("Npv500_httcsv_tagged")->Fill(Npvs,1);
		  if (is_httagged && is_nsub && is_csv) Hist("Npv500_httnsubcsv_tagged")->Fill(Npvs,1);
		  if (bcc->toptagjets->at(bestjetindex).pt()>600.0)
		  {
		    Hist("Npv600_all")->Fill(Npvs,1);
		    if (is_httagged) Hist("Npv600_htt_tagged")->Fill(Npvs,1);
		    if (is_httagged && is_nsub) Hist("Npv600_httnsub_tagged")->Fill(Npvs,1);
		    if (is_httagged && is_csv) Hist("Npv600_httcsv_tagged")->Fill(Npvs,1);
		    if (is_httagged && is_nsub && is_csv) Hist("Npv600_httnsubcsv_tagged")->Fill(Npvs,1);
		  }
		}
	      }
	    }
	  }*/ 
	}
      }
    }
//       if (bcc->toptagjets->at(i).pt()>500.0)
//       {
// 	Hist("Toppt_all")->Fill(bcc->toptagjets->at(i).pt(),1);
// 	Hist("Npv_all")->Fill(Npvs,1);
// 	// Hist("Toppt_all_2")->Fill(bcc->toptagjets->at(i).pt(),1);
// 	if(variableMassHepTopTag(bcc->toptagjets->at(i), 200.0, 0.85, 1.15, 0.35, 0.35, 140.0 , 250.0)  ){
// 	  Hist("Toppt_tagged")->Fill(bcc->toptagjets->at(i).pt(),1);
// 	  Hist("Npv_tagged")->Fill(Npvs,1);
// 	  //   Hist("Toppt_tagged_2")->Fill(bcc->toptagjets->at(i).pt(),1);
// 	}
// 	/*  if(HepTopTagNoMassCut(bcc->toptagjets->at(i)))
// 	 * {
// 	 *  Hist("Toppt_tagged_nomass")->Fill(bcc->toptagjets->at(i).pt(),1);
//       }*/
//       }

  
  
  
  
   /*   
    if(bcc->muons->size()>0){
      double deltaphi=bcc->toptagjets->at(i).deltaPhi(bcc->muons->at(0));
    
      if(jettagged&&(deltaphi>(2*PI/3))&&(bcc->toptagjets->at(i).pt()>150.)&&(fabs(bcc->toptagjets->at(i).eta())<2.5)){
	
	countjets=countjets+1;

	if(bcc->toptagjets->at(i).pt()>limpt){

	  indexjet=i;
	  limpt=bcc->toptagjets->at(i).pt();

	}
    
      }
    }
    
  }//loop over top jets
  
  if(indexjet!=-99999){
  
    LorentzVector allsubjets(0,0,0,0);

    double mjet=0;

    for(unsigned int j=0; j < 3; ++j){

        allsubjets += bcc->toptagjets->at(indexjet).subjets()[j].v4();
    }
  
    if(!allsubjets.isTimelike()) {
        mjet=0;
    }
    else{
      mjet = allsubjets.M();
    }

    Hist("MassTop")->Fill(mjet,weight);

    Hist("Toppt")->Fill(bcc->toptagjets->at(indexjet).pt(),weight);

    subjets_top=bcc->toptagjets->at(indexjet).subjets();
    btagsub_combinedSecondaryVertex_top=bcc->toptagjets->at(indexjet).btagsub_combinedSecondaryVertex();
    flavorsub_top=bcc->toptagjets->at(indexjet).flavorsub();

    for(unsigned int j=0; j < btagsub_combinedSecondaryVertex_top.size(); ++j){
      
      if(abs(flavorsub_top[j])==5) Hist("Pt_b_sub")->Fill(subjets_top[j].pt(),weight);
       
    }
  
  }
  
  */

}

void RocHists::Finish()
{
  // final calculations, like division and addition of certain histograms
  EventCalc* calc = EventCalc::Instance();
  bool IsRealData = calc->IsRealData();
  if (IsRealData){
    Hist("N_pv_perLumiBin")->Divide( Hist("N_pv_perLumiBin"), Hist("N_events_perLumiBin"));
    Hist( "N_pv_perLumiBin")->GetYaxis()->SetTitle("Events/Lumi");
  }

}

