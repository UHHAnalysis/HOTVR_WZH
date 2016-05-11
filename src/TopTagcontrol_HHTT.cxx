#include "SFrameTools/include/EventCalc.h"
#include "include/TopTagcontrol_HHTT.h"
#include "../SFrameTools/include/TopFitCalc.h"
#include "fastjet/contrib/HHTopTagger.hh"
#include "NtupleWriter/include/JetProps.h"
#include <iostream>

using namespace std;
using namespace fastjet;
using namespace contrib;
TopTagcontrol_HHTT::TopTagcontrol_HHTT(const char* name) : BaseHists(name)
{
  // named default constructor

}

TopTagcontrol_HHTT::~TopTagcontrol_HHTT()
{
  // default destructor, does nothing
}

void TopTagcontrol_HHTT::Init()
{
  // book all histograms here
  Book(TH1F("MVA","MVA values after selection",400,-2,2));
  Book(TH1F("MVA_ly","MVA values after selection",400,-2,2));
  Book(TH1F("MVA350","MVA values after selection",1600,-2,2));
  Book(TH1F("MVA350_ly","MVA values after selection",1600,-2,2));
  Book(TH1F("MVA2","MVA values before selection",400,-2,2));
  Book(TH1F("MVA2_ly","MVA values before selection",400,-2,2));
 
  Book(TH1F("SD_fine","log(chi) (microjets) shower deconstruction PT>350",10000,-10,10));
  Book(TH1F("SD_fine500","log(chi) (microjets) shower deconstruction PT>500",10000,-10,10));
  Book(TH1F("SD_fine700","log(chi) (microjets) shower deconstruction PT>700",10000,-10,10));
 Book(TH1F("SD_fine800","log(chi) (microjets) shower deconstruction PT>800",10000,-10,10));
  Book(TH1F("SD_fine900","log(chi) (microjets) shower deconstruction PT>900",10000,-10,10));
  Book(TH1F("SD2","log(chi(subjets)) shower deconstruction",21,-10,10));
  Book( TH1F( "sd_fail", "events failing the requirement (microjet)", 11,-0.5,10.5) );
  Book( TH1F( "sd_failsub", "events failing the requirement(subjets)", 11,-0.5,10.5) );
 
 
 
  Book( TH1F( "Chi2", "chi2 top_lep",400,0,100));
  Book( TH1F( "Chi2_ly", "chi2 top_lep",400,0,100));
  Book( TH1F( "pT_toplep", "reconstructed leptonic top p_{T}", 100, 0, 2000));
  
  Book( TH1F( "pT_toplep_ly", "reconstructed leptonic top p_{T}", 100, 0, 2000));
  Book( TH1F( "NbJets", "number of b-jets", 8, -0.5, 7.5 ) );
  Book( TH1F( "NbJets_ly", "number of b-jets", 8, -0.5, 7.5 ) );
  Book( TH1F( "psi02_ly","Jetshapes #Psi (0.2)",140,0,1.4));
  Book( TH1F( "psi04_ly","Jetshapes #Psi (0.4)",140,0,1.4));
  Book( TH1F( "psi06_ly","Jetshapes #Psi (0.6)",140,0,1.4));
  Book( TH1F( "psi08_ly","Jetshapes #Psi (0.8)",140,0,1.4));
  Book( TH1F( "psi10_ly","Jetshapes #Psi (1.0)",140,0,1.4));
  Book( TH1F( "number_of_constituents","Number of constituents",400,0,400));
  Book( TH1F( "number_of_charged_constituents","Number of charged constituents",200,0,200));
  Book( TH1F( "jet_charge","charge of topjets",100,-50,50));
  Book( TH1F( "weighted_jet_charge","topjet weighted charge",220,-2,2));
  Book( TH1F( "weighted_jet_charge_02","topjet weighted charge k=0.2",820,-10,10));
  Book( TH1F( "weighted_jet_charge_04","topjet weighted charge k=0.4",420,-5,5));
  Book( TH1F( "weighted_jet_charge_06","topjet weighted charge k=0.6",210,-2,2));
  Book( TH1F( "weighted_jet_charge_08","topjet weighted charge k=0.8",210,-2,2));
  Book( TH1F( "first_jet_moment", "topjet first moment",200,0,1));
  Book( TH1F( "second_jet_moment", "topjet second moment",200,0,1));	
  Book( TH1F( "NTopJets", "number of topjets", 8, -0.5, 7.5 ) );
  Book( TH1F( "NTopJets_ly", "number of topjets", 8, -0.5, 7.5 ) );
  Book( TH1F( "pT"," p_{T} topjets",100,0,2000));
  Book( TH1F( "pT_ly"," p_{T} topjets",100,0,2000));
  Book( TH1F( "pT_s1_bk"," p_{T} jets [GeV]",25,0,1000));
  Book( TH1F( "pT_s1"," p_{T} jets",50,0,2000));
  Book( TH1F( "npv_s1"," npv topjets (selection)",50,0,50));
  Book( TH1F( "pT_s1_ly"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "nvtx_s1","number of primary vertices",51,0,50));
  Book( TH1F( "nvtx_s1_ly","number of primary vertices",51,0,50));
  Book( TH1F( "pT_s2"," p_{T} CA15 (selection)",50,0,2000));
  Book( TH1F( "pT_s2_ly"," p_{T} CA15 (selection)",50,0,2000));
  Book( TH1F( "pT_s1_cms_tagged"," p_{T} topjets (cms tagged)",50,0,2000));
  Book( TH1F( "npv_s1_cms_tagged"," npv topjets (cms tagged)",50,0,50));
  Book( TH1F( "pT_s1_hep_tagged_ly"," p_{T} topjets (hep tagged)",50,0,2000));
  Book( TH1F( "pT_s1_hep_tagged"," p_{T} topjets (hep tagged)",50,0,2000));
  Book( TH1F( "pT_s1_hep3_tagged_ly"," p_{T} topjets (hep tagged)",50,0,2000));
  Book( TH1F( "pT_s1_hep3_tagged"," p_{T} topjets (hep tagged)",50,0,2000));
  Book( TH1F( "npv_s1_hep3_tagged"," npv topjets (hep tagged)",50,0,50));
  Book( TH1F( "pT_s1_multi_tagged_ly"," p_{T} topjets (hep tagged)",50,0,2000));
  Book( TH1F( "pT_s1_multi_tagged"," p_{T} topjets (hep tagged)",50,0,2000));
  Book( TH1F( "pT_s1_multiWP0_tagged"," p_{T} topjets (hep tagged)",50,0,2000));
  Book( TH1F( "pT_s1_multiWP1_tagged"," p_{T} topjets (hep tagged)",50,0,2000));
  Book( TH1F( "pT_s1_multiWP2_tagged"," p_{T} topjets (hep tagged)",50,0,2000));
  Book( TH1F( "npv_s1_multiWP0_tagged","npv topjets (hep tagged)",50,0,50));
  Book( TH1F( "npv_s1_multiWP1_tagged"," npv topjets (hep tagged)",50,0,50));
  Book( TH1F( "npv_s1_multiWP2_tagged","npv topjets (hep tagged)",50,0,50));
  Book( TH1F( "pT_s2_hep2_tagged_ly"," p_{T} CA15 (hep tagged)",50,0,2000));
  Book( TH1F( "pT_s2_hep2_tagged"," p_{T} CA15 (hep tagged)",50,0,2000));
  Book( TH1F( "pT_s1_cms_tagged_ly"," p_{T} topjets (cms tagged)",50,0,2000));
  Book( TH1F( "pT_s1_arne_tagged"," p_{T} topjets (arne tagged)",50,0,2000));
  Book( TH1F( "pT_s1_arne_tagged_ly"," p_{T} topjets (arne tagged)",50,0,2000));
  Book( TH1F( "pT_s1_sd_tagged"," p_{T} topjets (sd tagged)",50,0,2000));
  Book( TH1F( "pT_s1_sdWP0_tagged"," p_{T} topjets (sd tagged)",50,0,2000));
  Book( TH1F( "pT_s1_sdWP1_tagged"," p_{T} topjets (sd tagged)",50,0,2000));
  Book( TH1F( "pT_s1_sdWP2_tagged"," p_{T} topjets (sd tagged)",50,0,2000));
  Book( TH1F( "npv_s1_sdWP0_tagged"," p_{T} topjets (sd tagged)",50,0,50));
  Book( TH1F( "npv_s1_sdWP1_tagged"," p_{T} topjets (sd tagged)",50,0,50));
  Book( TH1F( "npv_s1_sdWP2_tagged"," p_{T} topjets (sd tagged)",50,0,50));
  Book( TH1F( "pT_s1_sd_tagged_ly"," p_{T} topjets (sd tagged)",50,0,2000));
  Book( TH1F( "pT_s1_tobias_tagged"," p_{T} topjets (tobias tagged)",50,0,2000));
  Book( TH1F( "pT_s1_tobias_tagged_ly"," p_{T} topjets (tobias tagged)",50,0,2000));
  Book( TH1F( "eta"," #eta topjets",100,-3,3));
  Book( TH1F( "eta_ly"," #eta topjets",100,-3,3));
  Book( TH1F( "phi"," #phi topjets",100,-M_PI,M_PI));
  Book( TH1F( "phi_ly"," #phi topjets",100,-M_PI,M_PI));
 
  Book( TH1F( "pT_1"," p_{T} leading topjet",100,0,2000));
  Book( TH1F( "pT_1_ly"," p_{T} leading topjet",100,0,2000));
  Book( TH1F( "pT_2","p_{T} 2nd topjet",100,0,2000));
  Book( TH1F( "pT_2_ly","p_{T} 2nd topjet",100,0,2000));
  Book( TH1F( "pT_3","p_{T} 3rd topjet",100,0,1000));
  Book( TH1F( "pT_3_ly","p_{T} 3rd topjet",100,0,1000));
  Book( TH1F( "pT_4","p_{T} 4th topjet",100,0,800));
  Book( TH1F( "pT_4_ly","p_{T} 4th topjet",100,0,800));
 
  Book( TH1F( "eta_1","#eta leading topjet",100,-3,3));
  Book( TH1F( "eta_1_ly","#eta leading topjet",100,-3,3));
  Book( TH1F( "eta_2","#eta 2nd topjet",100,-3,3));
  Book( TH1F( "eta_2_ly","#eta 2nd topjet",100,-3,3));
  Book( TH1F( "eta_3","#eta 3rd topjet",100,-3,3));
  Book( TH1F( "eta_3_ly","#eta 3rd topjet",100,-3,3));
  Book( TH1F( "eta_4","#eta 4th topjet",100,-3,3));
  Book( TH1F( "eta_4_ly","#eta 4th topjet",100,-3,3));
  Book( TH1F( "phi_1","#phi leading topjet",100,-M_PI,M_PI));
  Book( TH1F( "phi_1_ly","#phi leading topjet",100,-M_PI,M_PI));
  Book( TH1F( "phi_2","#phi 2nd topjet",100,-M_PI,M_PI));
  Book( TH1F( "phi_2_ly","#phi 2nd topjet",100,-M_PI,M_PI));
  Book( TH1F( "phi_3","#phi 3rd topjet",100,-M_PI,M_PI));
  Book( TH1F( "phi_3_ly","#phi 3rd topjet",100,-M_PI,M_PI));
  Book( TH1F( "phi_4","#phi 4th topjet",100,-M_PI,M_PI));
  Book( TH1F( "phi_4_ly","#phi 4th topjet",100,-M_PI,M_PI));
  Book( TH1F( "MJet_1", "m_{jet} leading topjet", 100,0,400 ) );
  Book( TH1F( "MJet_1_ly", "m_{jet} leading topjet", 100,0,400 ) );
  Book( TH1F( "MJet_2", "m_{jet} 2nd topjet", 100,0,400 ) );
  Book( TH1F( "MJet_2_ly", "m_{jet} 2nd topjet", 100,0,400 ) );
  Book( TH1F( "MJet_3", "m_{jet} 3rd topjet", 100,0,400 ) );
  Book( TH1F( "MJet_3_ly", "m_{jet} 3rd topjet", 100,0,400 ) );
  Book( TH1F( "MJet_4", "m_{jet} 4th topjet", 100,0,400 ) );
  Book( TH1F( "MJet_4_ly", "m_{jet} 4th topjet", 100,0,400 ) );
  Book( TH1F( "Mmin_1", "m_{min} leading topjet", 100,0,160 ) );
  Book( TH1F( "Mmin_1_ly", "m_{min}, leading topjet", 100,0,160 ) );
  Book( TH1F( "Mmin_2", "m_{min} 2nd topjet", 100,0,160 ) );
  Book( TH1F( "Mmin_2_ly", "m_{min} 2nd topjet", 100,0,160 ) );
  Book( TH1F( "Mmin_3", "m_{min} 3rd topjet", 100,0,160 ) );
  Book( TH1F( "Mmin_3_ly", "m_{min} 3rd topjet", 100,0,160 ) );
  Book( TH1F( "Mmin_4", "m_{min} 4th topjet", 100,0,160 ) );
  Book( TH1F( "Mmin_4_ly", "m_{min} 4th topjet", 100,0,160 ) );
  Book( TH1F( "NSubjets_1", "number of subjets leading topjet", 6,-0.5,5.5) );
  Book( TH1F( "NSubjets_1_ly", "number of subjets leading topjet", 6,-0.5,5.5 ) );
  Book( TH1F( "NSubjets_2", "number of subjets 2nd topjet", 6,-0.5,5.5 ) );
  Book( TH1F( "NSubjets_2_ly", "number of subjets 2nd topjet", 6,-0.5,5.5 ) );
  Book( TH1F( "NSubjets_3", "number of subjets 3rd topjet", 6,-0.5,5.5 ) );
  Book( TH1F( "NSubjets_3_ly", "number of subjets 3rd topjet", 6,-0.5,5.5 ) );
  Book( TH1F( "NSubjets_4", "number of subjets 4th topjet", 6,-0.5,5.5 ) ); 
  Book( TH1F( "NSubjets_4_ly", "number of subjets 4th topjet", 6,-0.5,5.5 ) ); 

  Book( TH1F( "QjetsVol_1", "Qjets volatility leading topjet", 50, 0.0, 2.0) );
  Book( TH1F( "QjetsVol_1_ly", "Qjets volatility leading topjet", 50, 0.0, 2.0 ) );

  Book( TH1F( "Nsubjettiness1_1", "#tau_{1} leading topjet", 50, 0.0, 1.0) );
  Book( TH1F( "Nsubjettiness1_1_ly", "#tau_{1} leading topjet", 50, 0.0, 1.0 ) );

  Book( TH1F( "Nsubjettiness2_1", "#tau_{2} leading topjet", 50, 0.0, 1.0) );
  Book( TH1F( "Nsubjettiness2_1_ly", "#tau_{2} leading topjet", 50, 0.0, 1.0 ) );
  
  Book( TH1F( "Nsubjettiness3_1", "#tau_{3} leading topjet", 50, 0.0, 1.0) );
  Book( TH1F( "Nsubjettiness3_1_ly", "#tau_{3} leading topjet", 50, 0.0, 1.0 ) );

  Book( TH1F( "Nsubjettiness3_2_1", "#tau_{2}/#tau_{3} leading topjet", 50, 0.0, 1.0) );
  Book( TH1F( "Nsubjettiness3_2_1_ly", "#tau_{2}/#tau_{3} leading topjet", 50, 0.0, 1.0 ) );
  Book( TH2F( "MVA_pt","MVA vs pt",200,-1,1,50,0,2000));
  Book( TH1F( "MVA_eff", "efficiency of MVA",200,-1,1));

  //HEP Top Tagger control variables
  Book( TH1F( "hep_fw", "hep fw", 25,0,160 ) );
  Book( TH1F( "hep_m12", "hep m12", 25,0,160 ) );
  Book( TH1F( "hep_m13", "hep m13", 25,0,160 ) );
  Book( TH1F( "hep_m23", "hep m23", 25,0,160 ) );
  Book( TH1F( "hep_m123", "hep m_123", 25,0,400 ) );
 Book( TH1F( "hep_m_pruned", "hep m_pruned", 25,0,400 ) );
  Book( TH1F( "hep_m_unfiltered", "hep m_unfiltered", 25,0,400 ) );
  //MultiR control
  Book( TH1F( "multiR_Rmin", "OptimalR R_{min}", 21,-0.05,2.05 ) );
  Book( TH1F( "multiR_Rmin200", "OptimalR R_{min} pt>200", 21,-0.05,2.05 ) );
  Book( TH1F( "multiR_Rmin400", "OptimalR R_{min} pt>400 ", 21,-0.05,2.05 ) );
  Book( TH1F( "multiR_Rmin600", "OptimalR R_{min} pt>600 ", 21,-0.05,2.05 ) );
  Book( TH1F( "multiR_Rmin800", "OptimalR R_{min} pt>800 ", 21,-0.05,2.05 ) );
  Book( TH1F( "multiR_Rmin1000", "OptimalR R_{min} pt>1000 ", 21,-0.05,2.05 ) );
  Book( TH1F( "multiR_Rminexp", "OptimalR R_{min exp}", 21,-0.05,2.05 ) );
  Book( TH1F( "multiR_Rminexp200", "OptimalR R_{min exp} pt>200", 21,-0.05,2.05 ) );
  Book( TH1F( "multiR_Rminexp400", "OptimalR R_{min exp} pt>400 ", 21,-0.05,2.05 ) );
  Book( TH1F( "multiR_Rminexp600", "OptimalR R_{min exp} pt>600 ", 21,-0.05,2.05 ) );
  Book( TH1F( "multiR_Rminexp800", "OptimalR R_{min exp} pt>800 ", 21,-0.05,2.05 ) );
  Book( TH1F( "multiR_Rminexp1000", "OptimalR R_{min exp} pt>1000 ", 21,-0.05,2.05 ) );
  Book( TH1F( "multiR_massRmin", "OptimalR m(R_{min}) [GeV]", 40,0,400 ) );
  Book( TH1F( "multiR_massRmin400", "OptimalR m(R_{min}) [GeV]", 40,0,400 ) );
  Book( TH1F( "multiR_massRmin600", "OptimalR m(R_{min}) [GeV]", 40,0,400 ) );
  Book( TH1F( "multiR_ptRmin", "OptimalR pt(R_{min})", 25,0,1000 ) );
  Book(TH1F("multiR_mass_diff","OptimalR mass_difference",120,0,120));
  Book( TH1F( "multiR_ptRminexp", "OptimalR pt for R_{min exp}", 25,0,1000 ) );
  Book( TH1F( "multiR_Rmin-Rminexp", "OptimalR R_{min}-R_{min exp}", 41,-2.05,2.05 ) );
  //Shower deconstruction control
  Book(TH1F("SD","log(#chi)",21,-10,10));
  Book(TH1F("SD_350","log(#chi)",21,-10,10));
  Book(TH1F("SD_600","log(#chi)",21,-10,10));
  Book( TH1F( "NMicrojets", "number of microjets", 11,-0.5,10.5) );
  Book( TH1F( "NMicrojetspass", "number of microjets passed", 11,-0.5,10.5) );
  Book( TH1F( "MMicrojet", "leading m_{microjets}", 50,0,400 ) );
  Book( TH1F( "MMicrojet_chi", "leading m_{microjets} (after chi cut)", 50,0,400 ) );

  //pT Verteilungen der Microjets
  Book(TH1F("pT_micro"," p_{T} microjets",20,0,1000));
  Book(TH1F("pT_micro_1"," p_{T} leading microjet",20,0,600));
  Book(TH1F("pT_micro_2"," p_{T} subding microjet",20,0,200));
  Book(TH1F("pT_micro_3"," p_{T} 3rd microjet",20,0,100));
  Book(TH1F("pT_micro_4"," p_{T} 4th microjet",20,0,100));
  Book(TH1F("pT_micro_5"," p_{T} 5th microjet",20,0,100));
  Book(TH1F("pT_micro_6"," p_{T} 6th microjet",20,0,100));


  //cms
  Book( TH1F( "pT_1_cms"," p_{T} leading topjet",10,0,1000));
  Book( TH1F( "pT_1_cms_ly"," p_{T} leading topjet",10,0,1000));
  Book( TH1F( "pT_2_cms","p_{T} 2nd topjet",10,0,1000));
  Book( TH1F( "pT_2_cms_ly","p_{T} 2nd topjet",10,0,1000));
  Book( TH1F( "pT_3_cms","p_{T} 3rd topjet",50,0,1000));
  Book( TH1F( "pT_3_cms_ly","p_{T} 3rd topjet",50,0,1000));
  Book( TH1F( "pT_4_cms","p_{T} 4th topjet",50,0,1000));
  Book( TH1F( "pT_4_cms_ly","p_{T} 4th topjet",50,0,1000));
  Book( TH1F( "MJet", "m_{jet}", 50,0,400 ) );
  Book( TH1F( "MJet_ly", "m_{jet}", 50,0,400 ) );
  Book( TH1F( "Mmin", "m_{min}", 25,0,160 ) );
  Book( TH1F( "Mmin_ly", "m_{min}", 25,0,160 ) );
  Book( TH1F( "NSubjets", "number of subjets", 6,-0.5,5.5) );
  Book( TH1F( "NSubjets_ly", "number of subjets", 6,-0.5,5.5 ) );
  Book( TH1F( "Mmin_cms", "m_{min} cms", 25,0,160 ) );
  Book( TH1F( "Mmin_cms_ly", "m_{min} cms", 25,0,160 ) );
  Book( TH1F( "NSubjets_cms", "number of subjets cms", 6,-0.5,5.5) );
  Book( TH1F( "NSubjets_cms_ly", "number of subjets cms", 6,-0.5,5.5 ) );


  //SoftDrop
  Book(TH1F("softdrop_pT_jet","topjet pT",100,0,2000));
  Book(TH1F("softdrop_pT_softdrop","softdrop pT",100,0,2000));
  Book(TH1F("softdrop_mass_jet","topjet mass",50,0,400));
  Book(TH1F("softdrop_mass_softdrop","sofdrop mass",50,0,400));
  Book(TH1F("softdrop_mass_jet200","topjet mass",50,0,400));
  Book(TH1F("softdrop_mass_softdrop200","softdrop(z_{cut}=0.2,#beta=1.0) mass [GeV]",50,0,400));
  Book(TH1F("softdrop_mass_jet400","topjet mass",50,0,400));
  Book(TH1F("softdrop_mass_softdrop400","softdrop(z_{cut}=0.2,#beta=1.0) mass [GeV]",50,0,400));
  Book(TH1F("softdrop_mass_jet600","topjet mass",50,0,400));
  Book(TH1F("softdrop_mass_softdrop600","softdrop(z_{cut}=0.2,#beta=1.0) mass [GeV]",50,0,400));
  Book(TH1F("softdrop_pT_jet_tau","topjet pT",100,0,2000));
  Book(TH1F("softdrop_pT_softdrop_tau","softdrop pT",100,0,2000));
  Book(TH1F("softdrop_mass_jet_tau","topjet mass",50,0,400));
  Book(TH1F("softdrop_mass_softdrop_tau","sofdrop mass",50,0,400));
  Book(TH1F("softdrop_mass_jet200_tau","topjet mass",50,0,400));
  Book(TH1F("softdrop_mass_softdrop200_tau","softdrop(z_{cut}=0.2,#beta=1.0) mass [GeV]",50,0,400));
  Book(TH1F("softdrop_mass_jet400_tau","topjet mass",50,0,400));
  Book(TH1F("softdrop_mass_softdrop400_tau","softdrop(z_{cut}=0.2,#beta=1.0) mass [GeV]",50,0,400));
  Book(TH1F("softdrop_mass_jet600_tau","topjet mass",50,0,400));
  Book(TH1F("softdrop_mass_softdrop600_tau","softdrop(z_{cut}=0.2,#beta=1.0) mass [GeV]",50,0,400));
  Book( TH1F( "pT_s1_softdrop_tagged"," p_{T} topjets (softdrop tagged)",50,0,2000));
  Book( TH1F( "pT_s1_mass_tagged"," p_{T} topjets (jet mass tagged)",50,0,2000));
  Book( TH1F( "pT_s1_softdrop_tau_tagged"," p_{T} topjets (softdrop tagged)",50,0,2000));
  Book( TH1F( "pT_s1_mass_tau_tagged"," p_{T} topjets (jet mass tagged)",50,0,2000));
  Book( TH1F( "npv_s1_softdrop_tagged"," p_{T} topjets (softdrop tagged)",50,0,50));
  Book( TH1F( "npv_s1_mass_tagged"," p_{T} topjets (jet mass tagged)",50,0,50));


  // tmva_tagger=TMVA_tagger::Instance();
  // tmva_tagger=new TMVA_tagger();
  Showerdeconstruction_tagger= new Showerdeconstruction();
  softdrop = new SoftDrop();
  // tmva_tagger->Set_Reader("Uncorr+3");
  //  tmva_tagger->Set_Reader("NPVweight");
  //tmva_tagger->Set_Reader("bestown70");
  //tmva_tagger->Set_Reader("pT");
  /*TMVA::Reader *readerx=new TMVA::Reader();
  float Tmass;
  float S1mass;
  float S2mass;
  float S3mass;
  float N;
  float Q;
  float t3t2;
  reader->AddVariable( "TopJet_mass", &Tmass );
   reader->AddVariable( "Subjets12_mass", &S1mass);
    reader->AddVariable( "Subjets13_mass", &S2mass);
    reader->AddVariable( "Subjets23_mass", &S3mass);
    reader->AddVariable( "TopJet_Nsubjets", &N);
    reader->AddVariable( "TopJet_Qjets_volatility", &Q);
    reader->AddVariable("t3/t2 := TopJet_tau3/TopJet_tau2", &t3t2);
    reader->BookMVA("BDTG", "/nfs/dust/cms/user/tlapsien/TMVA/weights/Qref_weight_BDTG.weights.xml");
    Double_t mvaValue = reader->EvaluateMVA("BDTG");*/
     //HHTT
 Book(TH1F("pT_HHTT","p_{T} [GeV]",50,0,2000));
  Book(TH1F("mjet_HHTT","mass",50,0,300));
  Book(TH1F("mjet_HHTT200","mass [GeV]",50,0,300));
  Book(TH1F("mjet_HHTT400","mass [GeV]",50,0,300));
  Book(TH1F("mjet_HHTT600","mass [GeV]",50,0,300));
  Book(TH1F("mjet_HHTT800","mass [GeV]",50,0,300));
  Book(TH1F("Nmassjump_HHTT","Number of subjets", 6,-0.5,5.5));
  Book(TH1F("Nmassjump_HHTT200","Number of subjets", 6,-0.5,5.5));
  Book(TH1F("Nmassjump_HHTT400","Number of subjets", 6,-0.5,5.5));
   Book(TH1F("Nmassjump_HHTT600","Number of subjets", 6,-0.5,5.5));
    Book(TH1F("Nmassjump_HHTT800","Number of subjets", 6,-0.5,5.5));
      Book( TH1F( "pT_s1_hhtt_tagged"," p_{T} topjets (HHTT tagged)",50,0,2000));
       Book( TH1F( "pT_s1_hhtt"," p_{T} topjets",50,0,2000));
       Book( TH1F( "pT_1_hhtt","p_{T} [GeV]",50,0,2000));
       Book( TH1F( "pT_2_hhtt","p_{T} [GeV]",50,0,2000));
        Book( TH1F( "pT_3_hhtt","p_{T} [GeV]",50,0,2000));
	Book(TH1F("subjet_1_pT_hhtt","leading subjet p_{T} [GeV]",25,0,1000));
	Book(TH1F("subjet_2_pT_hhtt","2nd leading subjet p_{T} [GeV]",25,0,1000));
	Book(TH1F("subjet_3_pT_hhtt","3rd leading subjetp_{T} [GeV] ",25,0,1000));
	Book(TH1F("subjet_1_mass_hhtt","leading subjet mass [GeV]",25,0,100));
	Book(TH1F("subjet_2_mass_hhtt","2nd leading subjet mass [GeV]",25,0,100));
	Book(TH1F("subjet_3_mass_hhtt","3rd leading subjet mass [GeV]",25,0,100));
	Book(TH1F("subjet01_mass_hhtt","invariant mass subjet_{01} [GeV]",25,0,250));
	Book(TH1F("subjet02_mass_hhtt","invariant mass subjet_{02} [GeV]",25,0,250));
	Book(TH1F("subjet12_mass_hhtt","invariant mass subjet_{12} [GeV]",25,0,250));
	Book(TH1F("mmin_hhtt","minimum pairwise mass [GeV]",25,0,250));
	Book(TH1F("mmin_hhtt200","minimum pairwise mass [GeV]",25,0,250));
	Book(TH1F("mmin_hhtt400","minimum pairwise mass [GeV]",25,0,250));
	Book(TH1F("mmin_hhtt600","minimum pairwise mass [GeV]",25,0,250));
	Book(TH1F("mmin_hhtt800","minimum pairwise mass [GeV]",25,0,250));
	Book( TH1F( "npv_s1_hhtt_tagged"," npv topjets (cms tagged)",50,0,50));
	Book( TH1F(  "pt_fraction1_hhtt","p_{T,sub1}/p_{T,jet} [GeV]",20,0,1));
	Book( TH1F(  "pt_fraction1_hhtt200","p_{T,sub1}/p_{T,jet} [GeV]",20,0,1));
	Book( TH1F(  "pt_fraction1_hhtt400","p_{T,sub1}/p_{T,jet} [GeV]",20,0,1));
	Book( TH1F(  "pt_fraction1_hhtt600","p_{T,sub1}/p_{T,jet} [GeV]",20,0,1));
	Book( TH1F(  "pt_fraction1_hhtt800","p_{T,sub1}/p_{T,jet} [GeV]",20,0,1));
}


void TopTagcontrol_HHTT::Fill()
{




  
   // important: get the event weight
  EventCalc* calc = EventCalc::Instance();
  double weight = calc -> GetWeight();

    //parameters for HHTT
  double rho(600.);
  double mu(30.), theta(0.7), mw(0.),mtopLow(140.),mtopHigh(220.);
  double min_r(0.1), max_r(1.5);//double mu(30.), theta(0.7);
  vector<fastjet::PseudoJet> varjets,fatjets,fatjets_backup,fatjets_comb, SortedSubJets;
  TopJet topjet2;
  JetProps jp(&topjet2,calc->GetPFParticles());
  std::vector<fastjet::PseudoJet> jetpart = jp.Get_all_pfparticles();
  double ptmin(10.);
  vector<fastjet::PseudoJet> inclusive_jetsCA;
  fastjet::JetDefinition jet_defCA2;
  HHTopTagger pluginAKT(mu, theta,min_r, max_r,rho,mw, HHTopTagger::CALIKE,fatjets);
  fastjet::JetDefinition jet_defCA(&pluginAKT);
  jet_defCA2=jet_defCA;
  fastjet::ClusterSequence clust_seqCA(jetpart, jet_defCA2);
  inclusive_jetsCA = clust_seqCA.inclusive_jets(ptmin);
  SortedSubJets = sorted_by_pt(inclusive_jetsCA);
  fatjets=pluginAKT.get_fatjets();

  int index=0;
  std::vector<fastjet::PseudoJet> subjets[fatjets.size()];
  std::vector<int> jetindex[fatjets.size()];




  for(int o=0;o<fatjets.size();o++){
    for(int L=0;L<clust_seqCA.jets().size();L++)  if(clust_seqCA.jets()[L].pt()==fatjets[o].pt()) jetindex[o].push_back(L);
    jetindex[o].push_back(fatjets[o].user_index());
	}


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
       //  Hist("NJets-1")->Fill(jet_beam.size(),weight);
       // Hist("NJets-2")->Fill(jet_radiation.size(),weight);
       /*  for(int y=0;y<jet_beam.size();y++) Hist("pT_beam")->Fill(jet_beam[y].pt(),weight);
       for(int y=0;y<jet_radiation.size();y++) Hist("pT_radiation")->Fill(jet_radiation[y].pt(),weight);
       for(int y=0;y<fatjets_comb.size();y++) Hist("pT_fatjets")->Fill(fatjets_comb[y].pt(),weight);*/



   // important: get the event weight
       fatjets_comb=sorted_by_pt(fatjets_comb);



  if(/*!IsRealData && (idVersion=="TTbarPF" || idVersion=="TTbarEff_1" || idVersion=="TTbarEff_2" || idVersion=="TTbarEff_3")*/true)
    {
      /*   TTbarGen* Decay = calc->GetTTbarGen();
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
    TTbarGen::E_DecayChannel decaymode= Decay->DecayChannel();*/


    
  TopFitCalc* topfit = TopFitCalc::Instance();
  std::vector<PrimaryVertex> *primaryvertices=calc->GetPrimaryVertices();
  int nprimaryvertices=primaryvertices->size();
  int Npvs = calc->GetPrimaryVertices()->size();
  //TMVA_tagger* tmva_tagger=TMVA_tagger::Instance();
  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
  //  bcc->recoHyps->clear();
  //  topfit->CalculateSelection(); 
   tagchi2discr = new Chi2Discriminator();
   //tagchi2discr->FillDiscriminatorValues();
  ReconstructionHypothesis *discr = tagchi2discr->GetBestHypothesis();
  LorentzVector top_lep = discr->toplep_v4();
  double chi2 = discr->discriminator("Chi2_tlep");
  Hist("Chi2")->Fill(chi2,weight);
  Hist("Chi2_ly")->Fill(chi2,weight);
  Hist("pT_toplep")->Fill(top_lep.pt(),weight);
  Hist("pT_toplep_ly")->Fill(top_lep.pt(),weight);
  int NTopJets = bcc-> topjets -> size();
  Hist("NTopJets")->Fill(NTopJets, weight);
  Hist("NTopJets_ly")->Fill(NTopJets, weight);
  int nbtags=0;
  for(unsigned int i =0; i<bcc->jets->size();++i){
    Jet jet = bcc->jets->at(i);
    if(IsTagged(jet,e_CSVT)) nbtags++;
  }
  Hist("NbJets")->Fill(nbtags,weight);
  Hist("NbJets_ly")->Fill(nbtags,weight); 

  //TMVA
  Double_t mva_value;
  
  //TMVA::Reader *r=new TMVA::Reader();
  //tmva_tagger->Set_Reader("Qref_weight");
  
	for(int g=0;g<fatjets_comb.size();g++){
	 if(g==0) Hist("pT_1_hhtt")->Fill(fatjets_comb[g].perp(),weight);
	 if(g==1) Hist("pT_2_hhtt")->Fill(fatjets_comb[g].perp(),weight);
	 if(g==2) Hist("pT_3_hhtt")->Fill(fatjets_comb[g].perp(),weight);
       }

  sort(bcc->topjets->begin(), bcc->topjets->end(), HigherPt());
  bool tagged=false;
  for (unsigned int i =0; i<1; ++i)
    {
      /* if(!tagged){
      TopJet topjet =  bcc->topjets->at(i);
      double distanceW1, distanceW2, distanceb;
      if(Decay->IsTopHadronicDecay()){
      distanceW1=topjet.deltaR(Decay->Wdecay1());
      distanceW2=topjet.deltaR(Decay->Wdecay2());
      distanceb=topjet.deltaR(Decay->bTop());
      }
      else if(Decay->IsAntiTopHadronicDecay()){
       distanceW1=topjet.deltaR(Decay->WMinusdecay1());
      distanceW2=topjet.deltaR(Decay->WMinusdecay2());
      distanceb=topjet.deltaR(Decay->WAntitop());
      }
      if(!(distanceW1<0.8 && distanceW2<0.8 && distanceb<0.8)){*/



     






      TopJet topjet =  bcc->topjets->at(i);
      //calculate Jetshapes
             double m_psi_02 = calc->IntegratedJetShape( &topjet, 0.2, 0.0 , e_CA8);
       double m_psi_04 = calc->IntegratedJetShape( &topjet, 0.4, 0.0 , e_CA8);
       double m_psi_06 = calc->IntegratedJetShape( &topjet, 0.6, 0.0 , e_CA8);
       double m_psi_08 = calc->IntegratedJetShape( &topjet, 0.8, 0.0 , e_CA8);
       double m_psi_10 = calc->IntegratedJetShape( &topjet, 1.0, 0.0 , e_CA8);
       Hist("psi02_ly")->Fill(m_psi_02,weight);
       Hist("psi04_ly")->Fill(m_psi_04,weight);
       Hist("psi06_ly")->Fill(m_psi_06,weight);
       Hist("psi08_ly")->Fill(m_psi_08,weight);
       Hist("psi10_ly")->Fill(m_psi_10,weight);
        
       //calculate jet properties
       std::vector<PFParticle> jetconsts = calc->GetJetPFParticles(&topjet);
       int m_number_of_constituents = jetconsts.size();
       int m_number_of_charged_constituents = 0;
       double m_jet_charge = calc->JetCharge(&topjet);
       Hist("number_of_constituents")->Fill(m_number_of_constituents,weight);
       Hist("jet_charge")->Fill(m_jet_charge,weight);
       for(int j=0; j< m_number_of_constituents; ++j){
    if( fabs(jetconsts[j].charge())>0.01) {
      m_number_of_charged_constituents ++;
    }
       }
       Hist("number_of_charged_constituents")->Fill(m_number_of_charged_constituents,weight);
        double m_weighted_jet_charge = calc->EnergyWeightedJetCharge(&topjet);
  double m_weighted_jet_charge_02 = calc->EnergyWeightedJetCharge(&topjet, 0.2);
  double m_weighted_jet_charge_04 = calc->EnergyWeightedJetCharge(&topjet, 0.4);
  double m_weighted_jet_charge_06 = calc->EnergyWeightedJetCharge(&topjet, 0.6);
  double m_weighted_jet_charge_08 = calc->EnergyWeightedJetCharge(&topjet, 0.8);
   Hist("weighted_jet_charge")->Fill(m_weighted_jet_charge,weight);
  Hist("weighted_jet_charge_02")->Fill(m_weighted_jet_charge_02,weight);
  Hist("weighted_jet_charge_04")->Fill(m_weighted_jet_charge_04,weight);
  Hist("weighted_jet_charge_06")->Fill(m_weighted_jet_charge_06,weight);
  Hist("weighted_jet_charge_08")->Fill(m_weighted_jet_charge_08,weight);

  double m_first_jet_moment = calc->JetMoment(&topjet,1);
  double m_second_jet_moment = calc->JetMoment(&topjet,2);
   Hist("first_jet_moment")->Fill(m_first_jet_moment,weight);
     Hist("second_jet_moment")->Fill(m_second_jet_moment,weight);
  
      
      Hist("pT") -> Fill(topjet.pt(), weight);
      Hist("pT_ly") -> Fill(topjet.pt(), weight);

      //selection to test efficiency
      bool jet_distance=true;
      bool selection_thad=true;
      if(fatjets_comb.size()<1)  selection_thad = false;
      // if(sqrt(pow(topjet.phi()-top_lep.phi(),2)+pow(topjet.eta()-top_lep.eta(),2))<2.7 ||  sqrt(pow(topjet.phi()-top_lep.phi(),2)+pow(topjet.eta()-top_lep.eta(),2))>3.5) selection_thad = false;
          if(fatjets_comb.size()>0)  if(abs(fatjets_comb[0].phi_std()-top_lep.phi())<2.1) selection_thad = false;
      if(selection_thad/*sqrt(pow(topjet.phi()-top_lep.phi(),2)+pow(topjet.eta()-top_lep.eta(),2))<2.7 ||  sqrt(pow(topjet.phi()-top_lep.phi(),2)+pow(topjet.eta()-top_lep.eta(),2))>3.5*/) {
	for(unsigned t=0;t<bcc->jets->size();++t){
	     Jet jet = bcc->jets->at(t);
	     // if((sqrt(pow(topjet.phi()-jet.phi(),2)+pow(topjet.eta()-jet.eta(),2))>0.8 &&sqrt(pow(topjet.phi()-jet.phi(),2)+pow(topjet.eta()-jet.eta(),2))<1.8) ) jet_distance=false;
	    if((sqrt(pow(top_lep.phi()-jet.phi(),2)+pow(top_lep.eta()-jet.eta(),2))>1 &&sqrt(pow(top_lep.phi()-jet.phi(),2)+pow(top_lep.eta()-jet.eta(),2))<2.2)) jet_distance=false;            
	    if((sqrt(pow(top_lep.phi()-jet.phi(),2)+pow(top_lep.eta()-jet.eta(),2))>4)) jet_distance=false;
	    }
	//jet_distance=true;
	if(nbtags>0 && jet_distance) {
	     Hist("pT_s1")->Fill(topjet.pt(),weight);
	     Hist("pT_s1_bk")->Fill(topjet.pt(),weight);
	     if(topjet.pt()>350) Hist("npv_s1")->Fill(Npvs,weight);
	     Hist("pT_s1_ly")->Fill(topjet.pt(),weight);
	     Hist("nvtx_s1")->Fill(nprimaryvertices,weight);
	     Hist("nvtx_s1_ly")->Fill(nprimaryvertices,weight);
	     tagged=true;
	     //fill pt histos

	if (bcc->topjets->size()> i && i<4)
	{
	   double mmin=0;
	  double mjet=0;
	  int nsubjets=0;
	  //  TopJet topjet =  bcc->topjets->at(i); 
	  TString hname = TString::Format("pT_%d", i+1);
	  Hist(hname)->Fill(topjet.pt(),weight);
	  TString hname_ly = TString::Format("pT_%d_ly", i+1);
	  Hist(hname_ly)->Fill(topjet.pt(),weight);
	  if( TopTag(topjet,mjet,nsubjets,mmin)){
	  TString hname = TString::Format("pT_%d_cms", i+1);
	  Hist(hname)->Fill(topjet.pt(),weight);
	  TString hname_ly = TString::Format("pT_%d_cms_ly", i+1);
	  Hist(hname_ly)->Fill(topjet.pt(),weight);
	  }
	  TString hname_eta = TString::Format("eta_%d", i+1);
	  Hist(hname_eta)->Fill(topjet.eta(),weight);
	  TString hname_eta_ly = TString::Format("eta_%d_ly", i+1);
	  Hist(hname_eta_ly)->Fill(topjet.eta(),weight);
	  TString hname_phi = TString::Format("phi_%d", i+1);
	  Hist(hname_phi)->Fill(topjet.phi(),weight);
	  TString hname_phi_ly = TString::Format("phi_%d_ly", i+1);
	  Hist(hname_phi_ly)->Fill(topjet.phi(),weight);
	  
	
	  TopTag(topjet,mjet,nsubjets,mmin);
	  TString hname_MJet = TString::Format("MJet_%d", i+1);
	  Hist(hname_MJet )->Fill( mjet, weight );
	  TString hname_MJet_ly = TString::Format("MJet_%d_ly", i+1);
	  Hist(hname_MJet_ly )->Fill( mjet, weight );
	  if(nsubjets>=3) 
	    {
	      TString hname_Mmin = TString::Format("Mmin_%d", i+1);
	      Hist(hname_Mmin  )->Fill( mmin, weight );
	      TString hname_Mmin_ly = TString::Format("Mmin_%d_ly", i+1);
	      Hist( hname_Mmin_ly )->Fill( mmin, weight );
	    }
	  TString hname_NSubjets = TString::Format("NSubjets_%d", i+1);
	  Hist( hname_NSubjets )->Fill( nsubjets, weight ); 
	  TString hname_NSubjets_ly = TString::Format("NSubjets_%d_ly", i+1);
	  Hist( hname_NSubjets_ly )->Fill( nsubjets, weight ); 


	    if (i==0){
	    
	    Hist("QjetsVol_1")->Fill(topjet.qjets_volatility(), weight);
	    Hist("QjetsVol_1_ly")->Fill(topjet.qjets_volatility(), weight);

	    Hist( "Nsubjettiness1_1")->Fill(topjet.tau1(), weight);
	    Hist( "Nsubjettiness1_1_ly")->Fill(topjet.tau1(), weight);

	    Hist( "Nsubjettiness2_1")->Fill(topjet.tau2(), weight);
	    Hist( "Nsubjettiness2_1_ly")->Fill(topjet.tau2(), weight);

	    Hist( "Nsubjettiness3_1")->Fill(topjet.tau3(), weight);
	    Hist( "Nsubjettiness3_1_ly")->Fill(topjet.tau3(), weight);

	    if (topjet.tau2()>0){
	      Hist( "Nsubjettiness3_2_1")->Fill(topjet.tau3()/topjet.tau2(), weight);
	      Hist( "Nsubjettiness3_2_1_ly")->Fill(topjet.tau3()/topjet.tau2(), weight);
	    }	  
	  }
	
	  
	}

	     

	

	Hist("pT_s1_hhtt")->Fill(fatjets_comb[0].perp(),weight);
	
	std::vector<fastjet::PseudoJet> SubJets_HHTT=sorted_by_pt(subjets[fatjets_comb[0].user_index()-1]);
	Hist("pT_HHTT")->Fill(fatjets_comb[0].perp(),weight);
	Hist("mjet_HHTT")->Fill(fatjets_comb[0].m(),weight);
	if(fatjets_comb[0].perp()>200) Hist("mjet_HHTT200")->Fill(fatjets_comb[0].m(),weight);
	if(fatjets_comb[0].perp()>400)	Hist("mjet_HHTT400")->Fill(fatjets_comb[0].m(),weight);
	if(fatjets_comb[0].perp()>600)	Hist("mjet_HHTT600")->Fill(fatjets_comb[0].m(),weight);
	if(fatjets_comb[0].perp()>800)	Hist("mjet_HHTT800")->Fill(fatjets_comb[0].m(),weight);
	if(fatjets_comb[0].perp()>200)	Hist("Nmassjump_HHTT")->Fill(SubJets_HHTT.size(),weight);
	if(fatjets_comb[0].perp()>200) 	Hist("Nmassjump_HHTT200")->Fill(SubJets_HHTT.size(),weight);
	if(fatjets_comb[0].perp()>400) 	Hist("Nmassjump_HHTT400")->Fill(SubJets_HHTT.size(),weight);
	if(fatjets_comb[0].perp()>600) 	Hist("Nmassjump_HHTT600")->Fill(SubJets_HHTT.size(),weight);
	if(fatjets_comb[0].perp()>800) 	Hist("Nmassjump_HHTT800")->Fill(SubJets_HHTT.size(),weight);
	for(int g=0;g<SubJets_HHTT.size();g++){
	  if(g==0) Hist("subjet_1_pT_hhtt")->Fill(SubJets_HHTT[g].perp(),weight);
	  if(g==1) Hist("subjet_2_pT_hhtt")->Fill(SubJets_HHTT[g].perp(),weight);
	  if(g==2) Hist("subjet_3_pT_hhtt")->Fill(SubJets_HHTT[g].perp(),weight);
	  if(g==0) Hist("subjet_1_mass_hhtt")->Fill(SubJets_HHTT[g].m(),weight);
	  if(g==1) Hist("subjet_2_mass_hhtt")->Fill(SubJets_HHTT[g].m(),weight);
	  if(g==2) Hist("subjet_3_mass_hhtt")->Fill(SubJets_HHTT[g].m(),weight);
	
	}
  double m12=0;
 double mmin3;
	  if(SubJets_HHTT.size()>2){
	    //   std::cout<<"CIRCLE2"<<std::endl;
	  double m01 = 0;
	  m01=(SubJets_HHTT[0]+SubJets_HHTT[1]).m();
	  double m02 = 0;
	  m02=(SubJets_HHTT[0]+SubJets_HHTT[2]).m();
	 m12 = 0; 
	  m12 = (SubJets_HHTT[1]+SubJets_HHTT[2]).m();
	   Hist("subjet01_mass_hhtt")->Fill(m01,weight);
	  Hist("subjet02_mass_hhtt")->Fill(m02,weight);
	  Hist("subjet12_mass_hhtt")->Fill(m12,weight);
	
	 
	 
	  
	  mmin3 = std::min(m01,std::min(m02,m12));
	  }
	  
	  
	  Hist("mmin_hhtt")->Fill(mmin3,weight);
	  if(fatjets_comb[0].perp()>200) Hist("mmin_hhtt200")->Fill(mmin3,weight);
	  if(fatjets_comb[0].perp()>400)  Hist("mmin_hhtt400")->Fill(mmin3,weight);
	  if(fatjets_comb[0].perp()>600)   Hist("mmin_hhtt600")->Fill(mmin3,weight);
	  if(fatjets_comb[0].perp()>800)   Hist("mmin_hhtt800")->Fill(mmin3,weight);
	  Hist("pt_fraction1_hhtt")->Fill(SubJets_HHTT.at(0).pt()/fatjets_comb[0].pt(),weight);
	  if(fatjets_comb[0].perp()>200)  Hist("pt_fraction1_hhtt200")->Fill(SubJets_HHTT.at(0).pt()/fatjets_comb[0].pt(),weight);
	  if(fatjets_comb[0].perp()>400)  Hist("pt_fraction1_hhtt400")->Fill(SubJets_HHTT.at(0).pt()/fatjets_comb[0].pt(),weight);
	  if(fatjets_comb[0].perp()>600)    Hist("pt_fraction1_hhtt600")->Fill(SubJets_HHTT.at(0).pt()/fatjets_comb[0].pt(),weight);
	  if(fatjets_comb[0].perp()>800)   Hist("pt_fraction1_hhtt800")->Fill(SubJets_HHTT.at(0).pt()/fatjets_comb[0].pt(),weight);
	  if(SubJets_HHTT.size()>2 && fatjets_comb[0].m()>mtopLow &&  fatjets_comb[0].m()<mtopHigh  &&SubJets_HHTT.at(0).pt()>30 && SubJets_HHTT.at(1).pt()>30 &&   SubJets_HHTT.at(0).pt()/fatjets_comb[0].pt()<0.8 &&mmin3>50  ){
	    Hist("pT_s1_hhtt_tagged")->Fill(fatjets_comb[0].perp(),weight);
	    if(fatjets_comb[0].perp()>350) Hist("npv_s1_hhtt_tagged")->Fill(Npvs,weight);
	  }
	 






	     
       //std::cout<<mva_value<<std::endl;
	     /*  Hist("MVA")->Fill(mva_value,weight);
      Hist("MVA_ly")->Fill(mva_value,weight);
      if(topjet.pt()>350){
      Hist("MVA350")->Fill(mva_value,weight);
      Hist("MVA350_ly")->Fill(mva_value,weight);}
      Hist("MVA_pt")->Fill(mva_value,topjet.pt());*/
      double mmin=0;
      double mjet=0;
      int nsubjets=0;
      if(TopTag(topjet,mjet,nsubjets,mmin)) {
	Hist("pT_s1_cms_tagged")->Fill(topjet.pt(),weight);
      	if(topjet.pt()>350) Hist("npv_s1_cms_tagged")->Fill(Npvs,weight);
	Hist("pT_s1_cms_tagged_ly")->Fill(topjet.pt(),weight);
	//	Hist("nvtx_s1_cms_tagged")->Fill(nprimaryvertices,weight);
	//	Hist("nvtx_s1_cns_tagged_ly")->Fill(nprimaryvertices,weight);
      }
      /* if(HepTopTagFull(topjet,calc->GetPFParticles())) {
	Hist("pT_s1_hep_tagged")->Fill(topjet.pt(),weight);
	Hist("pT_s1_hep_tagged_ly")->Fill(topjet.pt(),weight);
	}*/
      
      


      //  for (unsigned int k =0; k<bcc->higgstagjets->size(); ++k){
      //   TopJet CA15jet =  bcc->higgstagjets->at(k);
      //   if((sqrt(pow(topjet.phi()-CA15jet.phi(),2)+pow(topjet.eta()-CA15jet.eta(),2))<1.5)){
	 if(HepTopTag(topjet)){
	   	 Hist("pT_s1_hep_tagged")->Fill(topjet.pt(),weight);
	    Hist("pT_s1_hep_tagged_ly")->Fill(topjet.pt(),weight);
	 }
	 	 double m13,m23,fw,m123,m_pruned,m_unfiltered;
	 	 if(HepTopTagFull(topjet, calc->GetPFParticles(), m12,m13,m23,fw,m123,m_pruned,m_unfiltered)){
	    Hist("pT_s1_hep3_tagged")->Fill(topjet.pt(),weight);
	    if(topjet.pt()>350) Hist("npv_s1_hep3_tagged")->Fill(Npvs,weight);
	    Hist("pT_s1_hep3_tagged_ly")->Fill(topjet.pt(),weight);
	    Hist("hep_fw")->Fill(fw,weight);
	   Hist("hep_m12")->Fill(m12,weight);
	    Hist("hep_m13")->Fill(m13,weight);
	    Hist("hep_m23")->Fill(m23,weight);
	    Hist("hep_m123")->Fill(m123,weight);
	    Hist("hep_m_pruned")->Fill(m_pruned,weight);
	    Hist("hep_m_unfiltered")->Fill(m_unfiltered,weight);
		 }
		 double Rmin,mass_Rmin,pt_Rmin,mass_diff,pt_for_exp,Rmin_exp;
		 if(MultiRTopTag(topjet, calc->GetPFParticles(), Rmin,mass_Rmin,pt_Rmin,mass_diff,pt_for_exp,Rmin_exp)){
	     //MultiRTopTag(CA15jet, calc->GetPFParticles(), Rmin,mass_Rmin,pt_Rmin);
	   //std::cout<<"Fill multiR"<<k<<std::endl;
		 
	   Hist("pT_s1_multi_tagged")->Fill(topjet.pt(),weight);
	   Hist("pT_s1_multi_tagged_ly")->Fill(topjet.pt(),weight);
	   Hist("multiR_Rmin")->Fill(Rmin,weight);
	   if(topjet.pt()>200 )  Hist("multiR_Rmin200")->Fill(Rmin,weight);
	   if(topjet.pt()>400 )  Hist("multiR_Rmin400")->Fill(Rmin,weight);
	   if(topjet.pt()>600)  Hist("multiR_Rmin600")->Fill(Rmin,weight);
	   if(topjet.pt()>800 )  Hist("multiR_Rmin800")->Fill(Rmin,weight);
	   if(topjet.pt()>1000)  Hist("multiR_Rmin1000")->Fill(Rmin,weight);
	   
	   Hist("multiR_Rminexp")->Fill(Rmin_exp,weight);
	   if(topjet.pt()>200 )  Hist("multiR_Rminexp200")->Fill(Rmin_exp,weight);
	   if(topjet.pt()>400 )  Hist("multiR_Rminexp400")->Fill(Rmin_exp,weight);
	   if(topjet.pt()>600)  Hist("multiR_Rminexp600")->Fill(Rmin_exp,weight);
	   if(topjet.pt()>800 )  Hist("multiR_Rminexp800")->Fill(Rmin_exp,weight);
	   if(topjet.pt()>1000)  Hist("multiR_Rminexp1000")->Fill(Rmin_exp,weight);
	   Hist("multiR_massRmin")->Fill(mass_Rmin,weight);
	   if(topjet.pt()>400 ) Hist("multiR_massRmin400")->Fill(mass_Rmin,weight);
	   if(topjet.pt()>600) Hist("multiR_massRmin600")->Fill(mass_Rmin,weight);
	   Hist("multiR_ptRmin")->Fill(pt_Rmin,weight);
	   Hist("multiR_mass_diff")->Fill(mass_diff,weight);
	   Hist("multiR_ptRminexp")->Fill(pt_for_exp,weight);
	   Hist("multiR_Rmin-Rminexp")->Fill(Rmin-Rmin_exp,weight);
	   
	   if(Rmin-Rmin_exp<1.0 && mass_Rmin>140 && mass_Rmin<250)  Hist("pT_s1_multiWP1_tagged")->Fill(topjet.pt(),weight);
	   if(topjet.pt()>350) if(Rmin-Rmin_exp<1.0 && mass_Rmin>140 && mass_Rmin<250 )  Hist("npv_s1_multiWP1_tagged")->Fill(Npvs,weight);
	   if(Rmin-Rmin_exp<0.07 && mass_Rmin>140 && mass_Rmin<250 )  Hist("pT_s1_multiWP0_tagged")->Fill(topjet.pt(),weight);
	   if(topjet.pt()>350) if(Rmin-Rmin_exp<0.07 && mass_Rmin>140 && mass_Rmin<250 )  Hist("npv_s1_multiWP0_tagged")->Fill(Npvs,weight);
	   if(Rmin-Rmin_exp<0.5 /*&& mass_Rmin>140 && mass_Rmin<500*/ )  Hist("pT_s1_multiWP2_tagged")->Fill(topjet.pt(),weight);
	   if(topjet.pt()>350) if(Rmin-Rmin_exp<0.5 /*&& mass_Rmin>100 && mass_Rmin<250*/ )  Hist("npv_s1_multiWP2_tagged")->Fill(Npvs,weight);
		   
		    
		 }
		 //softdrop
		 fastjet::PseudoJet groomed_jet;
		 softdrop->GetJet(topjet, calc->GetPFParticles(),0.2,1.0,groomed_jet);
		 // std::cout<<"soft drop "<<groomed_jet.perp()<<"orginal jet "<<topjet.pt()<<std::endl;
	    Hist("softdrop_pT_jet")->Fill(topjet.pt(),weight);
	    Hist("softdrop_mass_jet")->Fill(topjet.v4().M(),weight);
	    Hist("softdrop_pT_softdrop")->Fill(groomed_jet.perp(),weight);
	    Hist("softdrop_mass_softdrop")->Fill(groomed_jet.m(),weight);
	    if(topjet.pt()>200){
	     Hist("softdrop_mass_jet200")->Fill(topjet.v4().M(),weight);
	     Hist("softdrop_mass_softdrop200")->Fill(groomed_jet.m(),weight);
	    }
	    if(topjet.pt()>400){
	     Hist("softdrop_mass_jet400")->Fill(topjet.v4().M(),weight);
	     Hist("softdrop_mass_softdrop400")->Fill(groomed_jet.m(),weight);
	    }
	    if(topjet.pt()>600){
	     Hist("softdrop_mass_jet600")->Fill(topjet.v4().M(),weight);
	     Hist("softdrop_mass_softdrop600")->Fill(groomed_jet.m(),weight);
	    }
	    if(groomed_jet.m()>140 && groomed_jet.m()<250) Hist("pT_s1_softdrop_tagged")->Fill(topjet.pt(),weight);
	    if(topjet.v4().M()>140 && topjet.v4().M()<250) Hist("pT_s1_mass_tagged")->Fill(topjet.pt(),weight);
	    if(topjet.pt()>350) if(groomed_jet.m()>140 && groomed_jet.m()<250) Hist("npv_s1_softdrop_tagged")->Fill(Npvs,weight);
	    if(topjet.pt()>350) if(topjet.v4().M()>140 && topjet.v4().M()<250) Hist("npv_s1_mass_tagged")->Fill(Npvs,weight);

	     if(topjet.tau3()/topjet.tau2()<0.6){
	    Hist("softdrop_pT_jet_tau")->Fill(topjet.pt(),weight);
	    Hist("softdrop_mass_jet_tau")->Fill(topjet.v4().M(),weight);
	    Hist("softdrop_pT_softdrop_tau")->Fill(groomed_jet.perp(),weight);
	    Hist("softdrop_mass_softdrop_tau")->Fill(groomed_jet.m(),weight);
	    if(topjet.pt()>200){
	     Hist("softdrop_mass_jet200_tau")->Fill(topjet.v4().M(),weight);
	     Hist("softdrop_mass_softdrop200_tau")->Fill(groomed_jet.m(),weight);
	    }
	    if(topjet.pt()>400){
	     Hist("softdrop_mass_jet400_tau")->Fill(topjet.v4().M(),weight);
	     Hist("softdrop_mass_softdrop400_tau")->Fill(groomed_jet.m(),weight);
	    }
	    if(topjet.pt()>600){
	     Hist("softdrop_mass_jet600_tau")->Fill(topjet.v4().M(),weight);
	     Hist("softdrop_mass_softdrop600_tau")->Fill(groomed_jet.m(),weight);
	    }
	    if(groomed_jet.m()>140 && groomed_jet.m()<250) Hist("pT_s1_softdrop_tau_tagged")->Fill(topjet.pt(),weight);
	    if(topjet.v4().M()>140 && topjet.v4().M()<250) Hist("pT_s1_mass_tau_tagged")->Fill(topjet.pt(),weight);
	    }


	 //shower deconstruction
	 double Mmicrojet=0;
	 std::vector<fastjet::PseudoJet> microjets;
	 int Nmicrojets=0;
	 double chi_2;
	 double chi;
	 /*	 double microconesize=-0.0005122*topjet.pt()+0.503;
		 if(microconesize<0.01) microconesize=0.01;*/
	 //first idea of varibale microjet cone
	 double microconesize=0.3;
	 if(topjet.pt()>500) microconesize=0.2;
	 if(topjet.pt()>700) microconesize=0.1;
	 //	 if(topjet.pt()>800) microconesize=0.05;
	 
	 //second idea:
	 /* double microconesize=0.4;
	    if(TopTag(topjet,mjet,nsubjets,mmin)) microconesize=0.3;*/
	 
	 if(topjet.pt()>500){
	   // chi_2 = Showerdeconstruction_tagger->Chi(topjet);
	    chi = Showerdeconstruction_tagger->ChiMicro(topjet,Nmicrojets,Mmicrojet,microconesize,microjets);
	   //  chi = Showerdeconstruction_tagger->ChiPF(topjet,Nmicrojets,Mmicrojet);
	 }
	 else {
	   //  chi_2= Showerdeconstruction_tagger->Chi(CA15jet);
	    chi= Showerdeconstruction_tagger->ChiMicro(topjet,Nmicrojets,Mmicrojet,microconesize,microjets);
	   //chi= Showerdeconstruction_tagger->ChiPF(CA15jet,Nmicrojets,Mmicrojet);
	 }
	 Hist("SD")->Fill(log(chi),weight);
	 for(int y=0;y<microjets.size();y++){
	   TString hname_micro = TString::Format("pT_micro_%d", y+1);
	   //std::cout<<hname_micro<<std::endl;
	   if(y<6) Hist(hname_micro)->Fill(microjets[y].perp(),weight);
	   Hist("pT_micro")->Fill(microjets[y].perp(),weight);
	 }
	 if(topjet.pt()>350) Hist("SD_fine")->Fill(log(chi));
	 if(topjet.pt()>500) Hist("SD_fine500")->Fill(log(chi));
	 if(topjet.pt()>350) Hist("SD_350")->Fill(log(chi),weight);
	 if(topjet.pt()>600) Hist("SD_600")->Fill(log(chi),weight);
	 if(topjet.pt()>700) Hist("SD_fine700")->Fill(log(chi));
	 if(topjet.pt()>800) Hist("SD_fine800")->Fill(log(chi));
	 if(topjet.pt()>900) Hist("SD_fine900")->Fill(log(chi));
	 if(chi==0) Hist("sd_fail")->Fill(0.,weight);
	 else Hist("sd_fail")->Fill(5.,weight);
	 if(chi_2==0) Hist("sd_failsub")->Fill(0.,weight);
	 else Hist("sd_failsub")->Fill(5.,weight);
	 Hist("SD2")->Fill(log(chi_2),weight);
	 Hist("NMicrojets")->Fill(Nmicrojets,weight);
	 if(chi!=0) Hist("NMicrojetspass")->Fill(Nmicrojets,weight);
	 Hist("MMicrojet")->Fill(Mmicrojet,weight);
	 if(log(chi)>3.5) {
	   Hist("pT_s1_sd_tagged")->Fill(topjet.pt(),weight);
	   Hist("pT_s1_sd_tagged_ly")->Fill(topjet.pt(),weight);
	   Hist("MMicrojet_chi")->Fill(Mmicrojet,weight);
	 }
	 if(log(chi)>2)  Hist("pT_s1_sdWP0_tagged")->Fill(topjet.pt(),weight);
	 if(log(chi)>3.5)  Hist("pT_s1_sdWP1_tagged")->Fill(topjet.pt(),weight);
	 if(log(chi)>5)  Hist("pT_s1_sdWP2_tagged")->Fill(topjet.pt(),weight);
	 if(topjet.pt()>350){
	 if(log(chi)>2)  Hist("npv_s1_sdWP0_tagged")->Fill(Npvs,weight);
	 if(log(chi)>3.5)  Hist("npv_s1_sdWP1_tagged")->Fill(Npvs,weight);
	 if(log(chi)>5)  Hist("npv_s1_sdWP2_tagged")->Fill(Npvs,weight);
	 }
       }
	
      
      
	/* if(tmva_tagger->IsTagged("TLflat",topjet,0.766,mva_value)){
	Hist("pT_s1_arne_tagged")->Fill(topjet.pt(),weight);
	Hist("pT_s1_arne_tagged_ly")->Fill(topjet.pt(),weight);  
      }
      if(tmva_tagger->IsTobiasTagged(topjet)){
	Hist("pT_s1_tobias_tagged")->Fill(topjet.pt(),weight);
	Hist("pT_s1_tobias_tagged_ly")->Fill(topjet.pt(),weight);  
	}*/
      

     
      Hist("MVA")->Fill(mva_value,weight);
      Hist("MVA_ly")->Fill(mva_value,weight);
  //     if(topjet.pt()>350){
  // 	Hist("MVA350")->Fill(mva_value,weight);
  // 	Hist("MVA350_ly")->Fill(mva_value,weight);}
  //     Hist("MVA_pt")->Fill(mva_value,topjet.pt());
  //     }
	   	
      
    
     
  //     Hist("eta") -> Fill(topjet.eta(), weight);
  //     Hist("eta_ly") -> Fill(topjet.eta(), weight);
  //     Hist("phi") -> Fill(topjet.phi(), weight);
  //     Hist("phi_ly") -> Fill(topjet.phi(), weight);
      
  //     double mmin=0;
  //     double mjet=0;
  //     int nsubjets=0;
  //     TopTag(topjet,mjet,nsubjets,mmin);
     
  //     Hist( "MJet" )->Fill( mjet, weight );
  //     Hist( "MJet_ly" )->Fill( mjet, weight );
      
  //     if(nsubjets>=3) 
  // 	{
  // 	  Hist( "Mmin" )->Fill( mmin, weight );
  // 	  Hist( "Mmin_ly" )->Fill( mmin, weight );
	  
  // 	}
  //     Hist( "NSubjets" )->Fill( nsubjets, weight ); 
  //     Hist( "NSubjets_ly" )->Fill( nsubjets, weight ); 
  //     if(TopTag(topjet,mjet,nsubjets,mmin)){

  //     if(nsubjets>=3) 
  // 	{
  // 	  Hist( "Mmin_cms" )->Fill( mmin, weight );
  // 	  Hist( "Mmin_cms_ly" )->Fill( mmin, weight );
	  
  // 	}
  //     Hist( "NSubjets_cms" )->Fill( nsubjets, weight ); 
  //     Hist( "NSubjets_cms_ly" )->Fill( nsubjets, weight ); 

  //     }
      
  //     // tmva_tagger->push_variables(topjet);
  //     // mva_value=tmva_tagger->GetMVA_value("NPVweight",topjet);
  //     Hist("MVA2")->Fill(mva_value,weight);
  //     Hist("MVA2_ly")->Fill(mva_value,weight);
     
  //     }
  //   }
  // //CA15 selection
  //   for (unsigned int i =0; i<bcc->higgstagjets->size(); ++i){
  //     TopJet CA15jet =  bcc->higgstagjets->at(i);
  //     //if(sqrt(pow(CA15jet.phi()-top_lep.phi(),2)+pow(CA15jet.eta()-top_lep.eta(),2))<2.7 ||  sqrt(pow(CA15jet.phi()-top_lep.phi(),2)+pow(CA15jet.eta()-top_lep.eta(),2))>3.5){
  //     if(abs(CA15jet.phi()-top_lep.phi())>2.1){
  // 	Hist("pT_s2")->Fill(CA15jet.pt(),weight);
  // 	Hist("pT_s2_ly")->Fill(CA15jet.pt(),weight);
  // 	if(HepTopTag(CA15jet)) {
  // 	  Hist("pT_s2_hep2_tagged")->Fill(CA15jet.pt(),weight);
  // 	  Hist("pT_s2_hep2_tagged_ly")->Fill(CA15jet.pt(),weight);
  // 	} 
  //     }
  //   }

    
  //   /*  sort(bcc->topjets->begin(), bcc->topjets->end(), HigherPt());
  // for (unsigned int i =0; i<=3; ++i)
  //   {
  //     if (bcc->topjets->size()> i)
  // 	{
  // 	   double mmin=0;
  // 	  double mjet=0;
  // 	  int nsubjets=0;
  // 	  TopJet topjet =  bcc->topjets->at(i); 
  // 	  TString hname = TString::Format("pT_%d", i+1);
  // 	  Hist(hname)->Fill(topjet.pt(),weight);
  // 	  TString hname_ly = TString::Format("pT_%d_ly", i+1);
  // 	  Hist(hname_ly)->Fill(topjet.pt(),weight);
  // 	  if( TopTag(topjet,mjet,nsubjets,mmin)){
  // 	  TString hname = TString::Format("pT_%d_cms", i+1);
  // 	  Hist(hname)->Fill(topjet.pt(),weight);
  // 	  TString hname_ly = TString::Format("pT_%d_cms_ly", i+1);
  // 	  Hist(hname_ly)->Fill(topjet.pt(),weight);
  // 	  }
  // 	  TString hname_eta = TString::Format("eta_%d", i+1);
  // 	  Hist(hname_eta)->Fill(topjet.eta(),weight);
  // 	  TString hname_eta_ly = TString::Format("eta_%d_ly", i+1);
  // 	  Hist(hname_eta_ly)->Fill(topjet.eta(),weight);
  // 	  TString hname_phi = TString::Format("phi_%d", i+1);
  // 	  Hist(hname_phi)->Fill(topjet.phi(),weight);
  // 	  TString hname_phi_ly = TString::Format("phi_%d_ly", i+1);
  // 	  Hist(hname_phi_ly)->Fill(topjet.phi(),weight);
	  
	
  // 	  TopTag(topjet,mjet,nsubjets,mmin);
  // 	  TString hname_MJet = TString::Format("MJet_%d", i+1);
  // 	  Hist(hname_MJet )->Fill( mjet, weight );
  // 	  TString hname_MJet_ly = TString::Format("MJet_%d_ly", i+1);
  // 	  Hist(hname_MJet_ly )->Fill( mjet, weight );
  // 	  if(nsubjets>=3) 
  // 	    {
  // 	      TString hname_Mmin = TString::Format("Mmin_%d", i+1);
  // 	      Hist(hname_Mmin  )->Fill( mmin, weight );
  // 	      TString hname_Mmin_ly = TString::Format("Mmin_%d_ly", i+1);
  // 	      Hist( hname_Mmin_ly )->Fill( mmin, weight );
  // 	    }
  // 	  TString hname_NSubjets = TString::Format("NSubjets_%d", i+1);
  // 	  Hist( hname_NSubjets )->Fill( nsubjets, weight ); 
  // 	  TString hname_NSubjets_ly = TString::Format("NSubjets_%d_ly", i+1);
  // 	  Hist( hname_NSubjets_ly )->Fill( nsubjets, weight ); 


  // 	  if (i==0){
	    
  // 	    Hist("QjetsVol_1")->Fill(topjet.qjets_volatility(), weight);
  // 	    Hist("QjetsVol_1_ly")->Fill(topjet.qjets_volatility(), weight);

  // 	    Hist( "Nsubjettiness1_1")->Fill(topjet.tau1(), weight);
  // 	    Hist( "Nsubjettiness1_1_ly")->Fill(topjet.tau1(), weight);

  // 	    Hist( "Nsubjettiness2_1")->Fill(topjet.tau2(), weight);
  // 	    Hist( "Nsubjettiness2_1_ly")->Fill(topjet.tau2(), weight);

  // 	    Hist( "Nsubjettiness3_1")->Fill(topjet.tau3(), weight);
  // 	    Hist( "Nsubjettiness3_1_ly")->Fill(topjet.tau3(), weight);

  // 	    if (topjet.tau2()>0){
  // 	      Hist( "Nsubjettiness3_2_1")->Fill(topjet.tau3()/topjet.tau2(), weight);
  // 	      Hist( "Nsubjettiness3_2_1_ly")->Fill(topjet.tau3()/topjet.ta2(), weight);
      /* }	  
      }

	  
}
      
    }*/
      }
      }
    }}
 
