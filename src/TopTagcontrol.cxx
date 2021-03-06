#include "SFrameTools/include/EventCalc.h"
#include "include/TopTagcontrol.h"
#include "include/TopTagfunctions.h"
#include "../SFrameTools/include/TopFitCalc.h"
#include <iostream>
#include "include/TopPtReweight.h"
using namespace std;

TopTagcontrol::TopTagcontrol(const char* name) : BaseHists(name)
{
  // named default constructor

}

TopTagcontrol::~TopTagcontrol()
{
  // default destructor, does nothing
}

void TopTagcontrol::Init()
{
  // book all histograms here
  Book(TH1F("MVA","MVA value",50,-2,2));
  Book(TH1F("MVA_ly","MVA value",50,-2,2));
  Book(TH1F("MVA350","MVA value p_{T}>350GeV",50,-2,2));
  Book(TH1F("MVA350_ly","MVA value",50,-2,2));
  Book(TH1F("MVA2","MVA value",400,-2,2));
  Book(TH1F("MVA2_ly","MVA value",400,-2,2));
 
  Book(TH1F("SD_fine","log(chi) (microjets) shower deconstruction PT>350",10000,-10,10));
  Book(TH1F("SD_fine500","log(chi) (microjets) shower deconstruction PT>500",10000,-10,10));
  Book(TH1F("SD_fine700","log(chi) (microjets) shower deconstruction PT>700",10000,-10,10));
 Book(TH1F("SD_fine800","log(chi) (microjets) shower deconstruction PT>800",10000,-10,10));
  Book(TH1F("SD_fine900","log(chi) (microjets) shower deconstruction PT>900",10000,-10,10));
  Book(TH1F("SD2","log(chi(subjets)) shower deconstruction",21,-10,10));
  Book( TH1F( "sd_fail", "events failing the requirement (microjet)", 11,-0.5,10.5) );
  Book( TH1F( "sd_failsub", "events failing the requirement(subjets)", 11,-0.5,10.5) );
  Book(TH1F("deltaR_lephad","#Delta R(t_{lep},jet)",20,0,10));
 
 
  Book( TH1F( "Chi2", "#chi^{2}",100,0,500));
   Book( TH1F( "Chi2_2", "#chi^{2}",40,0,20));
  Book( TH1F( "Chi2_ly", "#chi^{2}",50,0,500));
  Book( TH1F( "pT_toplep", "reconstructed leptonic top p_{T} [GeV]", 100, 0, 2000));
  
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
  // Book( TH1F( "pT_s1_had"," p_{T} jets",50,0,2000));
  //    Book( TH1F( "pT_s1_lep"," p_{T} jets",50,0,2000));
  Book( TH1F( "npv_s1"," npv topjets (selection)",50,0,50));
  Book( TH1F( "pT_s1_ly"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "nvtx_s1","number of primary vertices",51,0,50));
  Book( TH1F( "nvtx_s1_ly","number of primary vertices",51,0,50));
  Book( TH1F( "pT_s2"," p_{T} CA15 (selection)",50,0,2000));
  Book( TH1F( "pT_s2_ly"," p_{T} CA15 (selection)",50,0,2000));
  Book( TH1F( "pT_s1_cms_tagged"," p_{T} topjets (cms tagged)",50,0,2000));
  Book( TH1F( "npv_s1_cms_tagged"," npv topjets (cms tagged)",50,0,50));
  Book( TH1F( "eta_s1_cms_tagged"," #eta topjets",50,-3,3));
  Book( TH1F( "pT_s1_hep_tagged_ly"," p_{T} topjets (hep tagged)",50,0,2000));
  Book( TH1F( "pT_s1_hep_tagged"," p_{T} topjets (hep tagged)",50,0,2000));
   Book( TH1F( "eta_s1_hep_tagged"," #eta topjets",50,-3,3));
  Book( TH1F( "pT_s1_hep3_tagged_ly"," p_{T} topjets (hep tagged)",50,0,2000));
  Book( TH1F( "pT_s1_hep3_tagged"," p_{T} topjets (hep tagged)",50,0,2000));
  
  Book( TH1F( "npv_s1_hep3_tagged"," npv topjets (hep tagged)",50,0,50));
   Book( TH1F( "eta_s1_hep3_tagged"," #eta topjets",50,-3,3));
  Book( TH1F( "pT_s1_multi_tagged_ly"," p_{T} topjets (hep tagged)",50,0,2000));
  Book( TH1F( "pT_s1_multi_tagged"," p_{T} topjets (hep tagged)",50,0,2000));
   Book( TH1F( "eta_s1_multi_taggerd"," #eta topjets",50,-3,3));
  Book( TH1F( "pT_s1_multiWP0_tagged"," p_{T} topjets (hep tagged)",50,0,2000));
  Book( TH1F( "pT_s1_multiWP1_tagged"," p_{T} topjets (hep tagged)",50,0,2000));
  Book( TH1F( "pT_s1_multiWP2_tagged"," p_{T} topjets (hep tagged)",50,0,2000));
   Book( TH1F( "eta_s1_multiWP0_tagged"," #eta topjets",50,-3,3));
    Book( TH1F( "eta_s1_multiWP1_tagged"," #eta topjets",50,-3,3));
     Book( TH1F( "eta_s1_multiWP2_tagged"," #eta topjets",50,-3,3));
  Book( TH1F( "npv_s1_multiWP0_tagged","npv topjets (hep tagged)",50,0,50));
  Book( TH1F( "npv_s1_multiWP1_tagged"," npv topjets (hep tagged)",50,0,50));
  Book( TH1F( "npv_s1_multiWP2_tagged","npv topjets (hep tagged)",50,0,50));
  Book( TH1F( "pT_s2_hep2_tagged_ly"," p_{T} CA15 (hep tagged)",50,0,2000));
  Book( TH1F( "pT_s2_hep2_tagged"," p_{T} CA15 (hep tagged)",50,0,2000));
  Book( TH1F( "pT_s1_cms_tagged_ly"," p_{T} topjets (cms tagged)",50,0,2000));
  Book( TH1F( "pT_s1_arne_tagged"," p_{T} topjets (arne tagged)",50,0,2000));
  Book( TH1F( "pT_s1_arne_tagged_ly"," p_{T} topjets (arne tagged)",50,0,2000));
  Book( TH1F( "npv_s1_arne_tagged"," npv topjets (bdt tagged)",50,0,50));
  Book( TH1F( "pT_s1_sd_tagged"," p_{T} topjets (sd tagged)",50,0,2000));
  Book( TH1F( "pT_s1_sdWP0_tagged"," p_{T} topjets (sd tagged)",50,0,2000));
  Book( TH1F( "pT_s1_sdWP1_tagged"," p_{T} topjets (sd tagged)",50,0,2000));
  Book( TH1F( "pT_s1_sdWP2_tagged"," p_{T} topjets (sd tagged)",50,0,2000));
  Book( TH1F( "npv_s1_sdWP0_tagged"," p_{T} topjets (sd tagged)",50,0,50));
  Book( TH1F( "npv_s1_sdWP1_tagged"," p_{T} topjets (sd tagged)",50,0,50));
  Book( TH1F( "npv_s1_sdWP2_tagged"," p_{T} topjets (sd tagged)",50,0,50));
   Book( TH1F( "eta_s1_sdWP0_tagged"," #eta topjets",50,-3,3));
    Book( TH1F( "eta_s1_sdWP1_tagged"," #eta topjets",50,-3,3));
     Book( TH1F( "eta_s1_sdWP2_tagged"," #eta topjets",50,-3,3));
  Book( TH1F( "pT_s1_sd_tagged_ly"," p_{T} topjets (sd tagged)",50,0,2000));
  Book( TH1F( "pT_s1_tobias_tagged"," p_{T} topjets (tobias tagged)",50,0,2000));
  Book( TH1F( "pT_s1_tobias_tagged_ly"," p_{T} topjets (tobias tagged)",50,0,2000));
  Book( TH1F( "eta"," #eta topjets",100,-3,3));
  Book( TH1F( "eta_s1"," #eta topjets",50,-3,3));
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
  Book( TH1F( "hep_m12", "m_{12} [GeV]", 25,0,160 ) );
  Book( TH1F( "hep_m13", "m_{13} [GeV]", 25,0,160 ) );
  Book( TH1F( "hep_m23", "m_{23} [GeV]", 25,0,160 ) );
  Book( TH1F( "hep_m123", "m_{123}[GeV]", 25,0,400 ) );
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
  Book( TH1F( "multiR_ptRmin", "OptimalR p_{T}(R_{min}) [GeV]", 25,0,1000 ) );
  Book(TH1F("multiR_mass_diff","OptimalR mass_difference",120,0,120));
  Book( TH1F( "multiR_ptRminexp", "OptimalR pt for R_{min exp}", 25,0,1000 ) );
  Book( TH1F( "multiR_Rmin-Rminexp", "OptimalR R_{min}-R_{min exp}", 41,-2.05,2.05 ) );
  //Shower deconstruction control
   Book(TH1F("SD","log(#chi)",21,-10,10));
  Book(TH1F("SD_350","log(#chi)",21,-10,10));
  Book(TH1F("SD_600","log(#chi)",21,-10,10));
  Book( TH1F( "NMicrojets", "number of microjets", 11,-0.5,10.5) );
  Book( TH1F( "NMicrojetspass", "number of microjets passed", 11,-0.5,10.5) );
  Book( TH1F( "MMicrojet", "invariant mass m_{microjets} [GeV]", 50,0,400 ) );
  Book( TH1F( "MMicrojet_chi", "invariant mass m_{microjets} (after chi cut)", 50,0,400 ) );

  //pT Verteilungen der Microjets
  Book(TH1F("pT_micro","microjets p_{T} [GeV]",20,0,1000));
  Book(TH1F("pT_micro_1","leading microjet p_{T} [GeV]",20,0,600));
  Book(TH1F("pT_micro_2","subding microjet p_{T} [GeV]",20,0,200));
  Book(TH1F("pT_micro_3","3rd microjet p_{T} [GeV]",20,0,100));
  Book(TH1F("pT_micro_4","4th microjet p_{T} [GeV]",20,0,100));
  Book(TH1F("pT_micro_5","5th microjet p_{T} [GeV]",20,0,100));
  Book(TH1F("pT_micro_6","6th microjet p_{T} [GeV]",20,0,100));


  //cms
  Book( TH1F( "pT_1_cms"," p_{T} leading topjet",10,0,1000));
  Book( TH1F( "pT_1_cms_ly"," p_{T} leading topjet",10,0,1000));
  Book( TH1F( "pT_2_cms","p_{T} 2nd topjet",10,0,1000));
  Book( TH1F( "pT_2_cms_ly","p_{T} 2nd topjet",10,0,1000));
  Book( TH1F( "pT_3_cms","p_{T} 3rd topjet",50,0,1000));
  Book( TH1F( "pT_3_cms_ly","p_{T} 3rd topjet",50,0,1000));
  Book( TH1F( "pT_4_cms","p_{T} 4th topjet",50,0,1000));
  Book( TH1F( "pT_4_cms_ly","p_{T} 4th topjet",50,0,1000));
  Book( TH1F( "MJet", "m_{jet} [GeV]", 50,0,400 ) );
   Book( TH1F( "MJet350", "m_{jet} [GeV]", 50,0,400 ) );
  Book( TH1F( "MJet_ly", "m_{jet}", 50,0,400 ) );
  Book( TH1F( "Mmin", "m_{min} [GeV]", 25,0,160 ) );
   Book( TH1F( "Mmin350", "m_{min} [GeV]", 25,0,160 ) );
  Book( TH1F( "Mmin_ly", "m_{min}", 25,0,160 ) );
  Book( TH1F( "NSubjets", "number of subjets", 6,-0.5,5.5) );
   Book( TH1F( "NSubjets350", "number of subjets", 6,-0.5,5.5) );
  Book( TH1F( "NSubjets_ly", "number of subjets", 6,-0.5,5.5 ) );
  Book( TH1F( "Mmin_cms", "m_{min} cms", 25,0,160 ) );
  Book( TH1F( "Mmin_cms_ly", "m_{min} cms", 25,0,160 ) );
  Book( TH1F( "NSubjets_cms", "number of subjets cms", 6,-0.5,5.5) );
  Book( TH1F( "NSubjets_cms_ly", "number of subjets cms", 6,-0.5,5.5 ) );


  //SoftDrop
  Book(TH1F("softdrop_pT_jet","topjet pT",100,0,2000));
  Book(TH1F("softdrop_pT_softdrop","p_{T} [GeV]",100,0,2000));
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
  Book(TH1F("softdrop_mass_softdrop_tau","softdrop(z_{cut}=0.2,#beta=1.0) mass [GeV]",50,0,400));
  Book(TH1F("softdrop_mass_jet200_tau","topjet mass",50,0,400));
  Book(TH1F("softdrop_mass_softdrop200_tau","softdrop(z_{cut}=0.2,#beta=1.0) mass [GeV]",50,0,400));
  Book(TH1F("softdrop_mass_jet400_tau","topjet mass",50,0,400));
  Book(TH1F("softdrop_mass_softdrop400_tau","softdrop(z_{cut}=0.2,#beta=1.0) mass [GeV]",50,0,400));
  Book(TH1F("softdrop_mass_jet600_tau","topjet mass",50,0,400));
  Book(TH1F("softdrop_mass_softdrop600_tau","softdrop(z_{cut}=0.2,#beta=1.0) mass [GeV]",50,0,400));
  Book(TH1F("softdrop2_pT_jet","topjet pT",100,0,2000));
  Book(TH1F("softdrop2_pT_softdrop","p_{T} [GeV]",100,0,2000));
  Book(TH1F("softdrop2_mass_jet","topjet mass",50,0,400));
  Book(TH1F("softdrop2_mass_softdrop","sofdrop mass",50,0,400));
  Book(TH1F("softdrop2_mass_jet200","topjet mass",50,0,400));
  Book(TH1F("softdrop2_mass_softdrop200","softdrop(z_{cut}=0.2,#beta=1.0) mass [GeV]",50,0,400));
  Book(TH1F("softdrop2_mass_jet400","topjet mass",50,0,400));
  Book(TH1F("softdrop2_mass_softdrop400","softdrop(z_{cut}=0.2,#beta=1.0) mass [GeV]",50,0,400));
  Book(TH1F("softdrop2_mass_jet600","topjet mass",50,0,400));
  Book(TH1F("softdrop2_mass_softdrop600","softdrop(z_{cut}=0.2,#beta=1.0) mass [GeV]",50,0,400));
  Book(TH1F("softdrop2_pT_jet_tau","topjet pT",100,0,2000));
  Book(TH1F("softdrop2_pT_softdrop_tau","softdrop pT",100,0,2000));
  Book(TH1F("softdrop2_mass_jet_tau","topjet mass",50,0,400));
  Book(TH1F("softdrop2_mass_softdrop_tau","softdrop(z_{cut}=0.2,#beta=1.0) mass [GeV]",50,0,400));
  Book(TH1F("softdrop2_mass_jet200_tau","topjet mass",50,0,400));
  Book(TH1F("softdrop2_mass_softdrop200_tau","softdrop(z_{cut}=0.2,#beta=1.0) mass [GeV]",50,0,400));
  Book(TH1F("softdrop2_mass_jet400_tau","topjet mass",50,0,400));
  Book(TH1F("softdrop2_mass_softdrop400_tau","softdrop(z_{cut}=0.2,#beta=1.0) mass [GeV]",50,0,400));
  Book(TH1F("softdrop2_mass_jet600_tau","topjet mass",50,0,400));
  Book(TH1F("softdrop2_mass_softdrop600_tau","softdrop(z_{cut}=0.2,#beta=1.0) mass [GeV]",50,0,400));
 Book( TH1F( "pT_s1_softdrop_tagged"," p_{T} topjets (softdrop tagged)",50,0,2000));
 Book( TH1F( "pT_s1_softdrop2_tagged"," p_{T} topjets (softdrop tagged)",50,0,2000));
  Book( TH1F( "pT_s1_mass_tagged"," p_{T} topjets (jet mass tagged)",50,0,2000));
  Book( TH1F( "pT_s1_softdrop_tau_tagged"," p_{T} topjets (softdrop tagged)",50,0,2000));
    Book( TH1F( "pT_s1_softdrop2_tau_tagged"," p_{T} topjets (softdrop tagged)",50,0,2000));
  Book( TH1F( "pT_s1_mass_tau_tagged"," p_{T} topjets (jet mass tagged)",50,0,2000));
  Book( TH1F( "npv_s1_softdrop_tagged"," p_{T} topjets (softdrop tagged)",50,0,50));
   Book( TH1F( "npv_s1_softdrop2_tagged"," p_{T} topjets (softdrop tagged)",50,0,50));
  Book( TH1F( "npv_s1_mass_tagged"," p_{T} topjets (jet mass tagged)",50,0,50));
 Book( TH1F( "eta_s1_softdrop_tagged"," #eta topjets",50,-3,3));
  Book( TH1F( "eta_s1_softdrop_tau_tagged"," #eta topjets",50,-3,3));
   Book( TH1F( "eta_s1_softdrop2_tagged"," #eta topjets",50,-3,3));
  Book( TH1F( "eta_s1_softdrop2_tau_tagged"," #eta topjets",50,-3,3));


  //ARC questions
  
  // Book(TH1F("deltaR_bjet","#Delta R(t_{lep},jet)",20,0,10));//CA15

  // Book(TH1F("MET","MET",50,0,200));//CA15
/*
   Book(TH1F("m_s1","softdrop mass",50,0,2000));
  Book(TH1F("m_s1_match_tagged","softdrop mass",50,0,2000));
  Book(TH1F("decay","decay",11,-0.5,10.5));
  Book(TH1F("decay700","decay",11,-0.5,10.5));*/
  //  tmva_tagger=TMVA_tagger::Instance();
  //  tmva_tagger=new TMVA_tagger();
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
    

}


void TopTagcontrol::Fill()
{




  
   // important: get the event weight
  EventCalc* calc = EventCalc::Instance();
  double weight = calc -> GetWeight();
  MET *met = calc->GetMET();
  std::vector<Muon> * muons=calc->GetMuons();
  // TopPtReweight* weight2 = new TopPtReweight();
  //weight2->GetScaleWeight();
  if(/*!IsRealData && (idVersion=="TTbarPF" || idVersion=="TTbarEff_1" || idVersion=="TTbarEff_2" || idVersion=="TTbarEff_3")*/true)
    {
      /*      TTbarGen* Decay = calc->GetTTbarGen();
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
    TTbarGen::E_DecayChannel decaymode= Decay->DecayChannel();
    //   std::cout<<decaymode<<std::endl;
    */
      //  std::cout<<"test1"<<std::endl;
    
  TopFitCalc* topfit = TopFitCalc::Instance();
  std::vector<PrimaryVertex> *primaryvertices=calc->GetPrimaryVertices();
  int nprimaryvertices=primaryvertices->size();
  int Npvs = calc->GetPrimaryVertices()->size();
  TMVA_tagger* tmva_tagger=TMVA_tagger::Instance();
  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
  //  bcc->recoHyps->clear();
  //  topfit->CalculateSelection(); 
   tagchi2discr = new Chi2Discriminator();
   //tagchi2discr->FillDiscriminatorValues();
  ReconstructionHypothesis *discr = tagchi2discr->GetBestHypothesis();
  LorentzVector top_lep = discr->toplep_v4();
  double chi2 = discr->discriminator("Chi2_tlep");
  Hist("Chi2")->Fill(chi2,weight);
   Hist("Chi2_2")->Fill(chi2,weight);
  Hist("Chi2_ly")->Fill(chi2,weight);
  Hist("pT_toplep")->Fill(top_lep.pt(),weight);
  Hist("pT_toplep_ly")->Fill(top_lep.pt(),weight);
  int NTopJets = bcc-> topjets -> size();
  Hist("NTopJets")->Fill(NTopJets, weight);
  Hist("NTopJets_ly")->Fill(NTopJets, weight);
  int nbtags=0;
  for(unsigned int i =0; i<bcc->jets->size();++i){
    Jet jet = bcc->jets->at(i);
    // std::cout<<"jet ak5"<<jet.pt()<<std::endl;
    if(IsTagged(jet,e_CSVT)) nbtags++;
  }
  Hist("NbJets")->Fill(nbtags,weight);
  Hist("NbJets_ly")->Fill(nbtags,weight); 

  //TMVA
  Double_t mva_value;
  
  //TMVA::Reader *r=new TMVA::Reader();
  //tmva_tagger->Set_Reader("Qref_weight");
  
  // std::cout<<"test2"<<std::endl;


  sort(bcc->topjets->begin(), bcc->topjets->end(), HigherPt());
  sort(muons->begin(),muons->end(), HigherPt());
  bool tagged=false;
  for (unsigned int i =0; i< 1; ++i)
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
  
     // std::cout<<"test3"<<std::endl;
      
      Hist("pT") -> Fill(topjet.pt(), weight);
      Hist("pT_ly") -> Fill(topjet.pt(), weight);

      //selection to test efficiency
      bool jet_distance=true;
      bool selection_thad=true;
     
      // if(sqrt(pow(topjet.phi()-top_lep.phi(),2)+pow(topjet.eta()-top_lep.eta(),2))<2.7 ||  sqrt(pow(topjet.phi()-top_lep.phi(),2)+pow(topjet.eta()-top_lep.eta(),2))>3.5) selection_thad = false;
      //if(fabs(topjet.phi()-top_lep.phi())<2.1) selection_thad = false;
      if(fabs(topjet.phi()-top_lep.phi())<2.1) selection_thad = false;
      if(selection_thad/*sqrt(pow(topjet.phi()-top_lep.phi(),2)+pow(topjet.eta()-top_lep.eta(),2))<2.7 ||  sqrt(pow(topjet.phi()-top_lep.phi(),2)+pow(topjet.eta()-top_lep.eta(),2))>3.5*/) {
	for(unsigned t=0;t<bcc->jets->size();++t){
	     Jet jet = bcc->jets->at(t);
	     // if((sqrt(pow(topjet.phi()-jet.phi(),2)+pow(topjet.eta()-jet.eta(),2))>0.8 &&sqrt(pow(topjet.phi()-jet.phi(),2)+pow(topjet.eta()-jet.eta(),2))<1.8) ) jet_distance=false;
	    if((sqrt(pow(top_lep.phi()-jet.phi(),2)+pow(top_lep.eta()-jet.eta(),2))>1 &&sqrt(pow(top_lep.phi()-jet.phi(),2)+pow(top_lep.eta()-jet.eta(),2))<2.2)) jet_distance=false;            
	    if((sqrt(pow(top_lep.phi()-jet.phi(),2)+pow(top_lep.eta()-jet.eta(),2))>4)) jet_distance=false;
	    }
	//jet_distance=true;
	
	if(nbtags>0 && jet_distance) {
	  /*	  Hist("decay")->Fill(decaymode,weight);
		  if(topjet.pt()>700)  Hist("decay700")->Fill(decaymode,weight);*/



	  /* GenParticle top;
   GenParticle atop;
   bool btop=false;
   bool btop2=false;
	  
	  if (Decay->IsTopHadronicDecay()) {
	    top=Decay->Top();
     // if(topjet.pt()>700) std::cout<<"1"<<std::endl;
	    btop=true;
}
   if (Decay->IsAntiTopHadronicDecay()) {
     atop=Decay->Antitop();
     // if(topjet.pt()>700) std::cout<<"2"<<std::endl;
     btop2=true;
     }*/


       
	     fastjet::PseudoJet groomed_jet3;
	     //  softdrop->GetJet(topjet, calc->GetPFParticles(),0.1,0.0,groomed_jet3);
	     /*   if(btop) Hist("m_s1")->Fill(top.pt(),weight);
	     if(btop2)  Hist("m_s1")->Fill(atop.pt(),weight);
    if(btop && topjet.deltaR(top)<0.6)  Hist("m_s1_match_tagged")->Fill(top.pt(),weight);
    if(btop2 && topjet.deltaR(atop)<0.6)  Hist("m_s1_match_tagged")->Fill(atop.pt(),weight);*/
	     /*  Hist("m_s1")->Fill(topjet.pt(),weight);
	     if(jet_decays_hadronic(topjet,0.6))  Hist("m_s1_match_tagged")->Fill(topjet.pt(),weight);
	     if(false) {*/
	     if(topjet.pt()>350) Hist("eta_s1")->Fill(topjet.eta(),weight);
	     //  if(jet_decays_hadronic(topjet,4.0)) Hist("pT_s1_had")->Fill(topjet.pt(),weight);
	     //  if(jet_decays_leptonic(topjet,4.0))	Hist("pT_s1_lep")->Fill(topjet.pt(),weight);
	     
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
	  //	  std::cout<<"mass "<<topjet.pt()<<" "<<mjet<<std::endl;
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

	     




	//  std::cout<<"test4"<<std::endl;



	     
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
      Hist("deltaR_lephad")->Fill(sqrt(pow(topjet.phi()-top_lep.phi(),2)+pow(topjet.eta()-top_lep.eta(),2)),weight);
      Jet bjet;
      for(unsigned int i =0; i<bcc->jets->size();++i){
    Jet jet = bcc->jets->at(i);
    // std::cout<<"jet ak5"<<jet.pt()<<std::endl;
    if(IsTagged(jet,e_CSVT)) bjet=jet;
  }
      //Hist("deltaR_bjet")->Fill(sqrt(pow(bjet.phi()-top_lep.phi(),2)+pow(bjet.eta()-top_lep.eta(),2)),weight);
      // Hist("MET")->Fill(met->pt(),weight);
      if(TopTag(topjet,mjet,nsubjets,mmin)) {
	Hist("pT_s1_cms_tagged")->Fill(topjet.pt(),weight);
      	if(topjet.pt()>350){
	  Hist("npv_s1_cms_tagged")->Fill(Npvs,weight);
	   Hist("eta_s1_cms_tagged")->Fill(topjet.eta(),weight);
	}
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
	 	 double m12,m13,m23,fw,m123,m_pruned,m_unfiltered;
	 	 if(HepTopTagFull(topjet, calc->GetPFParticles(), m12,m13,m23,fw,m123,m_pruned,m_unfiltered)){
	    Hist("pT_s1_hep3_tagged")->Fill(topjet.pt(),weight);
	    if(topjet.pt()>350) {
	      Hist("npv_s1_hep3_tagged")->Fill(Npvs,weight);
	        Hist("eta_s1_hep3_tagged")->Fill(topjet.eta(),weight);
	    }
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
	   if(topjet.pt()>350) if(Rmin-Rmin_exp<1.0 && mass_Rmin>140 && mass_Rmin<250 ) {
	       Hist("npv_s1_multiWP1_tagged")->Fill(Npvs,weight);
	         Hist("eta_s1_multiWP1_tagged")->Fill(topjet.eta(),weight);
	     }
	   if(Rmin-Rmin_exp<0.07 && mass_Rmin>140 && mass_Rmin<250 )  Hist("pT_s1_multiWP0_tagged")->Fill(topjet.pt(),weight);
	   if(topjet.pt()>350) if(Rmin-Rmin_exp<0.07 && mass_Rmin>140 && mass_Rmin<250 ) {
	       Hist("npv_s1_multiWP0_tagged")->Fill(Npvs,weight);
	        Hist("eta_s1_multiWP0_tagged")->Fill(topjet.eta(),weight);
	     }
	   if(Rmin-Rmin_exp<0.5 /*&& mass_Rmin>140 && mass_Rmin<500*/ )  Hist("pT_s1_multiWP2_tagged")->Fill(topjet.pt(),weight);
	   if(topjet.pt()>350) if(Rmin-Rmin_exp<0.5 /*&& mass_Rmin>100 && mass_Rmin<250*/ ) {
	       Hist("npv_s1_multiWP2_tagged")->Fill(Npvs,weight);
	       Hist("eta_s1_multiWP2_tagged")->Fill(topjet.eta(),weight);
	     }	   
		    
		 }

		 //  std::cout<<"test5"<<std::endl;
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
	    if(groomed_jet.m()>110 && groomed_jet.m()<210) Hist("pT_s1_softdrop_tagged")->Fill(topjet.pt(),weight);
	    if(topjet.v4().M()>110 && topjet.v4().M()<210) Hist("pT_s1_mass_tagged")->Fill(topjet.pt(),weight);
	    if(topjet.pt()>350) if(groomed_jet.m()>110 && groomed_jet.m()<210){
		Hist("npv_s1_softdrop_tagged")->Fill(Npvs,weight);
			Hist("eta_s1_softdrop_tagged")->Fill(topjet.eta(),weight);
	      }
	    if(topjet.pt()>350) if(topjet.v4().M()>110 && topjet.v4().M()<210){
		Hist("npv_s1_mass_tagged")->Fill(Npvs,weight);
		//	Hist("eta_s1_mass_tagged")->Fill(topjet.eta(),weight);
	      }

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
	    if(groomed_jet.m()>110 && groomed_jet.m()<210) Hist("pT_s1_softdrop_tau_tagged")->Fill(topjet.pt(),weight);
	    if(groomed_jet.m()>110 && groomed_jet.m()<210 && topjet.pt()>350) {
	       Hist("eta_s1_softdrop_tau_tagged")->Fill(topjet.eta(),weight);
	    }
	    if(topjet.v4().M()>110 && topjet.v4().M()<210) Hist("pT_s1_mass_tau_tagged")->Fill(topjet.pt(),weight);
	    
	    }





	      fastjet::PseudoJet groomed_jet2;
		 softdrop->GetJet(topjet, calc->GetPFParticles(),0.1,0.0,groomed_jet2);
		 // std::cout<<"soft drop "<<groomed_jet.perp()<<"orginal jet "<<topjet.pt()<<std::endl;
	    Hist("softdrop2_pT_jet")->Fill(topjet.pt(),weight);
	    Hist("softdrop2_mass_jet")->Fill(topjet.v4().M(),weight);
	    Hist("softdrop2_pT_softdrop")->Fill(groomed_jet2.perp(),weight);
	    Hist("softdrop2_mass_softdrop")->Fill(groomed_jet2.m(),weight);
	    if(topjet.pt()>200){
	     Hist("softdrop2_mass_jet200")->Fill(topjet.v4().M(),weight);
	     Hist("softdrop2_mass_softdrop200")->Fill(groomed_jet2.m(),weight);
	    }
	    if(topjet.pt()>400){
	     Hist("softdrop2_mass_jet400")->Fill(topjet.v4().M(),weight);
	     Hist("softdrop2_mass_softdrop400")->Fill(groomed_jet2.m(),weight);
	    }
	    if(topjet.pt()>600){
	     Hist("softdrop2_mass_jet600")->Fill(topjet.v4().M(),weight);
	     Hist("softdrop2_mass_softdrop600")->Fill(groomed_jet2.m(),weight);
	    }
	    if(groomed_jet2.m()>110 && groomed_jet2.m()<210) Hist("pT_s1_softdrop2_tagged")->Fill(topjet.pt(),weight);
	  
	    if(topjet.pt()>350) if(groomed_jet2.m()>110 && groomed_jet2.m()<210){
		Hist("npv_s1_softdrop2_tagged")->Fill(Npvs,weight);
			Hist("eta_s1_softdrop2_tagged")->Fill(topjet.eta(),weight);
	      }
	   

	     if(topjet.tau3()/topjet.tau2()<0.5){
	    Hist("softdrop2_pT_jet_tau")->Fill(topjet.pt(),weight);
	    Hist("softdrop2_mass_jet_tau")->Fill(topjet.v4().M(),weight);
	    Hist("softdrop2_pT_softdrop_tau")->Fill(groomed_jet2.perp(),weight);
	    Hist("softdrop2_mass_softdrop_tau")->Fill(groomed_jet2.m(),weight);
	    if(topjet.pt()>200){
	     Hist("softdrop2_mass_jet200_tau")->Fill(topjet.v4().M(),weight);
	     Hist("softdrop2_mass_softdrop200_tau")->Fill(groomed_jet2.m(),weight);
	    }
	    if(topjet.pt()>400){
	     Hist("softdrop2_mass_jet400_tau")->Fill(topjet.v4().M(),weight);
	     Hist("softdrop2_mass_softdrop400_tau")->Fill(groomed_jet2.m(),weight);
	    }
	    if(topjet.pt()>600){
	     Hist("softdrop2_mass_jet600_tau")->Fill(topjet.v4().M(),weight);
	     Hist("softdrop2_mass_softdrop600_tau")->Fill(groomed_jet2.m(),weight);
	    }
	    if(groomed_jet2.m()>110 && groomed_jet2.m()<210) Hist("pT_s1_softdrop2_tau_tagged")->Fill(topjet.pt(),weight);
	    if(groomed_jet2.m()>110 && groomed_jet2.m()<210 && topjet.pt()>350) {
	       Hist("eta_s1_softdrop2_tau_tagged")->Fill(topjet.eta(),weight);
	    }
	 

	     }
	



	     //  std::cout<<"test6"<<std::endl;

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
	   if(log(chi)>2) {
	     Hist("npv_s1_sdWP0_tagged")->Fill(Npvs,weight);
	     Hist("eta_s1_sdWP0_tagged")->Fill(topjet.eta(),weight);
	   }
	   if(log(chi)>3.5) { 
	     Hist("npv_s1_sdWP1_tagged")->Fill(Npvs,weight);
	       Hist("eta_s1_sdWP1_tagged")->Fill(topjet.eta(),weight);
	   }
	   if(log(chi)>5)  {
	       Hist("eta_s1_sdWP2_tagged")->Fill(topjet.eta(),weight);
	     Hist("npv_s1_sdWP2_tagged")->Fill(Npvs,weight);
	   }
	 }
	
	
	
      
	if(tmva_tagger->IsTagged("TLflat",topjet,0.766,mva_value)){
	Hist("pT_s1_arne_tagged")->Fill(topjet.pt(),weight);
	Hist("pT_s1_arne_tagged_ly")->Fill(topjet.pt(),weight);  
	if(topjet.pt()>350)  Hist("npv_s1_arne_tagged")->Fill(Npvs,weight);
	}
	//	std::cout<<"MVA "<<mva_value<<std::endl;
       /*
      if(tmva_tagger->IsTobiasTagged(topjet)){
	Hist("pT_s1_tobias_tagged")->Fill(topjet.pt(),weight);
	Hist("pT_s1_tobias_tagged_ly")->Fill(topjet.pt(),weight);  
	}*/
      

     
      Hist("MVA")->Fill(mva_value,weight);
      Hist("MVA_ly")->Fill(mva_value,weight);
     if(topjet.pt()>350){
  	Hist("MVA350")->Fill(mva_value,weight);
  // 	Hist("MVA350_ly")->Fill(mva_value,weight);}
  //     Hist("MVA_pt")->Fill(mva_value,topjet.pt());
      }
	   	
	}
     //  std::cout<<"test7"<<std::endl;
    
     
  //     Hist("eta") -> Fill(topjet.eta(), weight);
  //     Hist("eta_ly") -> Fill(topjet.eta(), weight);
  //     Hist("phi") -> Fill(topjet.phi(), weight);
  //     Hist("phi_ly") -> Fill(topjet.phi(), weight);
      
       double mmin=0;
      double mjet=0;
      int nsubjets=0;
      TopTag(topjet,mjet,nsubjets,mmin);
     
       Hist( "MJet" )->Fill( mjet, weight );
       if(topjet.pt()>350)   Hist( "MJet350" )->Fill( mjet, weight );
      Hist( "MJet_ly" )->Fill( mjet, weight );
      //   std::cout<<"test8"<<std::endl;
      if(nsubjets>=3) 
  	{
  	  Hist( "Mmin" )->Fill( mmin, weight );
	 if(topjet.pt()>350)  Hist( "Mmin350" )->Fill( mmin, weight );
   	  Hist( "Mmin_ly" )->Fill( mmin, weight );
	  
 	}
      Hist( "NSubjets" )->Fill( nsubjets, weight ); 
 if(topjet.pt()>350) Hist( "NSubjets350" )->Fill( nsubjets, weight ); 
      Hist( "NSubjets_ly" )->Fill( nsubjets, weight );
      //   std::cout<<"test9"<<std::endl;
      //    if(TopTag(topjet,mjet,nsubjets,mmin)){

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
      
}*/}
    }
    }
    }
 
