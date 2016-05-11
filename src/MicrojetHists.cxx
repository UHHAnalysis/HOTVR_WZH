#include "SFrameTools/include/EventCalc.h"
#include "include/MicrojetHists.h"
#include "include/TopFitCalc.h"
#include "NtupleWriter/include/JetProps.h"
#include "include/TopTagfunctions.h"
#include <iostream>

using namespace std;

MicrojetHists::MicrojetHists(const char* name) : BaseHists(name)
{
  // named default constructor

}

MicrojetHists::~MicrojetHists()
{
  // default destructor, does nothing
}

void MicrojetHists::Init()
{
  // book all histograms here
  Book(TH1D("nmicrojets01","number of microjets conesize=0.1",11,0,10));
  Book(TH1D("Mmicrojets01","invariant mass of microjets conesize=0.1",100,0,400));
  Book(TH1D("Mmicrojets01_chi","invariant mass of microjets conesize=0.1 after chi",100,0,400));
  Book(TH1D("Fraction01","Nconstituents_micro/Nconstituents_CA 0.1",100,0,2));
  Book(TH1D("FractionpT01","pT_micro/pT_CA 0.1",100,0,2));
  Book(TH1D("pT1_micro01","pT of 1. microjet conesize=01",70,0,500));
  Book(TH1D("pT1_micro01_ly","pT of 1. microjet conesize=01",70,0,500));
  Book(TH1D("pT2_micro01","pT of 2. microjet conesize=01",70,0,500));
  Book(TH1D("pT2_micro01_ly","pT of 2. microjet conesize=01",70,0,500));
  Book(TH1D("pT3_micro01","pT of 3. microjet conesize=01",70,0,500));
  Book(TH1D("pT3_micro01_ly","pT of 3. microjet conesize=01",70,0,500));
  Book(TH1D("pT4_micro01","pT of 4. microjet conesize=01",70,0,500));
  Book(TH1D("pT4_micro01_ly","pT of 4. microjet conesize=01",70,0,500));
  Book(TH1D("pT5_micro01","pT of 5. microjet conesize=01",70,0,500));
  Book(TH1D("pT5_micro01_ly","pT of 5. microjet conesize=01",70,0,500));
  Book(TH1D("pT6_micro01","pT of 6. microjet conesize=01",70,0,500));
  Book(TH1D("pT6_micro01_ly","pT of 6. microjet conesize=01",70,0,500));
  Book(TH1D("pT7_micro01","pT of 7. microjet conesize=01",70,0,500));
  Book(TH1D("pT7_micro01_ly","pT of 7. microjet conesize=01",70,0,500));
  Book(TH1D("pT8_micro01","pT of 8. microjet conesize=01",70,0,500));
  Book(TH1D("pT8_micro01_ly","pT of 8. microjet conesize=01",70,0,500));
  Book(TH1D("pT9_micro01","pT of 9. microjet conesize=01",70,0,500));
  Book(TH1D("pT9_micro01_ly","pT of 9. microjet conesize=01",70,0,500));
  Book(TH1D("nconst1_micro01","number of 1. jet constituents conesize =0.1",31,0,30));
  Book(TH1D("nconst2_micro01","number of 2. jet constituents conesize =0.1",31,0,30));
  Book(TH1D("nconst3_micro01","number of 3. jet constituents conesize =0.1",31,0,30));
  Book(TH1D("nconst4_micro01","number of 4. jet constituents conesize =0.1",31,0,30));
  Book(TH1D("nconst5_micro01","number of 5. jet constituents conesize =0.1",31,0,30));
  Book(TH1D("nconst6_micro01","number of 6. jet constituents conesize =0.1",31,0,30));
  Book(TH1D("nconst7_micro01","number of 7. jet constituents conesize =0.1",31,0,30));
  Book(TH1D("nconst8_micro01","number of 8. jet constituents conesize =0.1",31,0,30));
  Book(TH1D("nconst9_micro01","number of 9. jet constituents conesize =0.1",31,0,30));
 
  Book(TH1D("nmicrojets02","number of microjets conesize=0.2",11,0,10));
  Book(TH1D("Mmicrojets02","invariant mass of microjets conesize=0.2",100,0,400));
  Book(TH1D("Mmicrojets02_chi","invariant mass of microjets conesize=0.2 after chi",100,0,400));
  Book(TH1D("Fraction02","Nconstituents_micro/Nconstituents_CA 0.2",100,0,2)); 
  Book(TH1D("FractionpT02","pT_micro/pT_CA 0.2",100,0,2));
  Book(TH1D("pT1_micro02","pT of 1. microjet conesize=02",70,0,500));
  Book(TH1D("pT1_micro02_ly","pT of 1. microjet conesize=02",70,0,500));
  Book(TH1D("pT2_micro02","pT of 2. microjet conesize=02",70,0,500));
  Book(TH1D("pT2_micro02_ly","pT of 2. microjet conesize=02",70,0,500));
  Book(TH1D("pT3_micro02","pT of 3. microjet conesize=02",70,0,500));
  Book(TH1D("pT3_micro02_ly","pT of 3. microjet conesize=02",70,0,500));
  Book(TH1D("pT4_micro02","pT of 4. microjet conesize=02",70,0,500));
  Book(TH1D("pT4_micro02_ly","pT of 4. microjet conesize=02",70,0,500));
  Book(TH1D("pT5_micro02","pT of 5. microjet conesize=02",70,0,500));
  Book(TH1D("pT5_micro02_ly","pT of 5. microjet conesize=02",70,0,500));
  Book(TH1D("pT6_micro02","pT of 6. microjet conesize=02",70,0,500));
  Book(TH1D("pT6_micro02_ly","pT of 6. microjet conesize=02",70,0,500));
  Book(TH1D("pT7_micro02","pT of 7. microjet conesize=02",70,0,500));
  Book(TH1D("pT7_micro02_ly","pT of 7. microjet conesize=02",70,0,500));
  Book(TH1D("pT8_micro02","pT of 8. microjet conesize=02",70,0,500));
  Book(TH1D("pT8_micro02_ly","pT of 8. microjet conesize=02",70,0,500));
  Book(TH1D("pT9_micro02","pT of 9. microjet conesize=02",70,0,500));
  Book(TH1D("pT9_micro02_ly","pT of 9. microjet conesize=02",70,0,500));
  Book(TH1D("nconst1_micro02","number of 1. jet constituents conesize =0.2",31,0,30));
  Book(TH1D("nconst2_micro02","number of 2. jet constituents conesize =0.2",31,0,30));
  Book(TH1D("nconst3_micro02","number of 3. jet constituents conesize =0.2",31,0,30));
  Book(TH1D("nconst4_micro02","number of 4. jet constituents conesize =0.2",31,0,30));
  Book(TH1D("nconst5_micro02","number of 5. jet constituents conesize =0.2",31,0,30));
  Book(TH1D("nconst6_micro02","number of 6. jet constituents conesize =0.2",31,0,30));
  Book(TH1D("nconst7_micro02","number of 7. jet constituents conesize =0.2",31,0,30));
  Book(TH1D("nconst8_micro02","number of 8. jet constituents conesize =0.2",31,0,30));
  Book(TH1D("nconst9_micro02","number of 9. jet constituents conesize =0.2",31,0,30));
  

  Book(TH1D("nmicrojets03","number of microjets conesize=0.3",11,0,10));
  Book(TH1D("Mmicrojets03","invariant mass of microjets conesize=0.3",100,0,400));
  Book(TH1D("Mmicrojets03_chi","invariant mass of microjets conesize=0.3 after chi",100,0,400));
  Book(TH1D("Fraction03","Nconstituents_micro/Nconstituents_CA 0.3",100,0,2)); 
  Book(TH1D("FractionpT03","pT_micro/pT_CA 0.3",100,0,2));
  Book(TH1D("pT1_micro03","pT of 1. microjet conesize=03",70,0,500));
  Book(TH1D("pT1_micro03_ly","pT of 1. microjet conesize=03",70,0,500));
  Book(TH1D("pT2_micro03","pT of 2. microjet conesize=03",70,0,500));
  Book(TH1D("pT2_micro03_ly","pT of 2. microjet conesize=03",70,0,500));
  Book(TH1D("pT3_micro03","pT of 3. microjet conesize=03",70,0,500));
  Book(TH1D("pT3_micro03_ly","pT of 3. microjet conesize=03",70,0,500));
  Book(TH1D("pT4_micro03","pT of 4. microjet conesize=03",70,0,500));
  Book(TH1D("pT4_micro03_ly","pT of 4. microjet conesize=03",70,0,500));
  Book(TH1D("pT5_micro03","pT of 5. microjet conesize=03",70,0,500));
  Book(TH1D("pT5_micro03_ly","pT of 5. microjet conesize=03",70,0,500));
  Book(TH1D("pT6_micro03","pT of 6. microjet conesize=03",70,0,500));
  Book(TH1D("pT6_micro03_ly","pT of 6. microjet conesize=03",70,0,500));
  Book(TH1D("pT7_micro03","pT of 7. microjet conesize=03",70,0,500));
  Book(TH1D("pT7_micro03_ly","pT of 7. microjet conesize=03",70,0,500));
  Book(TH1D("pT8_micro03","pT of 8. microjet conesize=03",70,0,500));
  Book(TH1D("pT8_micro03_ly","pT of 8. microjet conesize=03",70,0,500));
  Book(TH1D("pT9_micro03","pT of 9. microjet conesize=03",70,0,500));
  Book(TH1D("pT9_micro03_ly","pT of 9. microjet conesize=03",70,0,500));
  Book(TH1D("nconst1_micro03","number of 1. jet constituents conesize =0.3",31,0,30));
  Book(TH1D("nconst2_micro03","number of 2. jet constituents conesize =0.3",31,0,30));
  Book(TH1D("nconst3_micro03","number of 3. jet constituents conesize =0.3",31,0,30));
  Book(TH1D("nconst4_micro03","number of 4. jet constituents conesize =0.3",31,0,30));
  Book(TH1D("nconst5_micro03","number of 5. jet constituents conesize =0.3",31,0,30));
  Book(TH1D("nconst6_micro03","number of 6. jet constituents conesize =0.3",31,0,30));
  Book(TH1D("nconst7_micro03","number of 7. jet constituents conesize =0.3",31,0,30));
  Book(TH1D("nconst8_micro03","number of 8. jet constituents conesize =0.3",31,0,30));
  Book(TH1D("nconst9_micro03","number of 9. jet constituents conesize =0.3",31,0,30));

  Book(TH1D("nmicrojets04","number of microjets conesize=0.4",11,0,10));
  Book(TH1D("Mmicrojets04","invariant mass of microjets conesize=0.4",100,0,400));
  Book(TH1D("Mmicrojets04_chi","invariant mass of microjets conesize=0.4 after chi",100,0,400));
  Book(TH1D("Fraction04","Nconstituents_micro/Nconstituents_CA 0.4",100,0,2)); 
  Book(TH1D("FractionpT04","pT_micro/pT_CA 0.4",100,0,2));
  Book(TH1D("pT1_micro04","pT of 1. microjet conesize=04",70,0,500));
  Book(TH1D("pT1_micro04_ly","pT of 1. microjet conesize=04",70,0,500));
  Book(TH1D("pT2_micro04","pT of 2. microjet conesize=04",70,0,500));
  Book(TH1D("pT2_micro04_ly","pT of 2. microjet conesize=04",70,0,500));
  Book(TH1D("pT3_micro04","pT of 3. microjet conesize=04",70,0,500));
  Book(TH1D("pT3_micro04_ly","pT of 3. microjet conesize=04",70,0,500));
  Book(TH1D("pT4_micro04","pT of 4. microjet conesize=04",70,0,500));
  Book(TH1D("pT4_micro04_ly","pT of 4. microjet conesize=04",70,0,500));
  Book(TH1D("pT5_micro04","pT of 5. microjet conesize=04",70,0,500));
  Book(TH1D("pT5_micro04_ly","pT of 5. microjet conesize=04",70,0,500));
  Book(TH1D("pT6_micro04","pT of 6. microjet conesize=04",70,0,500));
  Book(TH1D("pT6_micro04_ly","pT of 6. microjet conesize=04",70,0,500));
  Book(TH1D("pT7_micro04","pT of 7. microjet conesize=04",70,0,500));
  Book(TH1D("pT7_micro04_ly","pT of 7. microjet conesize=04",70,0,500));
  Book(TH1D("pT8_micro04","pT of 8. microjet conesize=04",70,0,500));
  Book(TH1D("pT8_micro04_ly","pT of 8. microjet conesize=04",70,0,500));
  Book(TH1D("pT9_micro04","pT of 9. microjet conesize=04",70,0,500));
  Book(TH1D("pT9_micro04_ly","pT of 9. microjet conesize=04",70,0,500));
  Book(TH1D("nconst1_micro04","number of 1. jet constituents conesize =0.4",31,0,30));
  Book(TH1D("nconst2_micro04","number of 2. jet constituents conesize =0.4",31,0,30));
  Book(TH1D("nconst3_micro04","number of 3. jet constituents conesize =0.4",31,0,30));
  Book(TH1D("nconst4_micro04","number of 4. jet constituents conesize =0.4",31,0,30));
  Book(TH1D("nconst5_micro04","number of 5. jet constituents conesize =0.4",31,0,30));
  Book(TH1D("nconst6_micro04","number of 6. jet constituents conesize =0.4",31,0,30));
  Book(TH1D("nconst7_micro04","number of 7. jet constituents conesize =0.4",31,0,30));
  Book(TH1D("nconst8_micro04","number of 8. jet constituents conesize =0.4",31,0,30));
  Book(TH1D("nconst9_micro04","number of 9. jet constituents conesize =0.4",31,0,30));

  

 
  Book( TH1F( "number_of_constituents","Number of constituents",100,0,400));
  /*  Book(TH1F("MVA","MVA values after selection",400,-2,2));
  Book(TH1F("MVA_ly","MVA values after selection",400,-2,2));
  Book(TH1F("MVA350","MVA values after selection",400,-2,2));
  Book(TH1F("MVA350_ly","MVA values after selection",400,-2,2));
  Book(TH1F("MVA2","MVA values before selection",400,-2,2));
  Book(TH1F("MVA2_ly","MVA values before selection",400,-2,2));
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
  Book( TH1F( "pT_s1"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "pT_s1_ly"," p_{T} topjets (selection)",50,0,2000));
  Book( TH1F( "pT_s1_cms_tagged"," p_{T} topjets (cms tagged)",50,0,2000));
  Book( TH1F( "pT_s1_cms_tagged_ly"," p_{T} topjets (cms tagged)",50,0,2000));
   Book( TH1F( "pT_s1_arne_tagged"," p_{T} topjets (arne tagged)",50,0,2000));
  Book( TH1F( "pT_s1_arne_tagged_ly"," p_{T} topjets (arne tagged)",50,0,2000));
  Book( TH1F( "eta"," #eta topjets",100,-3,3));
  Book( TH1F( "eta_ly"," #eta topjets",100,-3,3));
  Book( TH1F( "phi"," #phi topjets",100,-M_PI,M_PI));
  Book( TH1F( "phi_ly"," #phi topjets",100,-M_PI,M_PI));
  Book( TH1F( "MJet", "m_{jet}", 100,0,400 ) );
  Book( TH1F( "MJet_ly", "m_{jet}", 100,0,400 ) );
  Book( TH1F( "Mmin", "m_{min}", 100,0,160 ) );
  Book( TH1F( "Mmin_ly", "m_{min}", 100,0,160 ) );
  Book( TH1F( "NSubjets", "number of subjets", 6,-0.5,5.5) );
  Book( TH1F( "NSubjets_ly", "number of subjets", 6,-0.5,5.5 ) );
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
  Book( TH1F( "MVA_eff", "efficiency of MVA",200,-1,1));*/
   Showerdeconstruction_tagger= new Showerdeconstruction();

}


void MicrojetHists::Fill2(TopJet topjet, double mva_value)
{
  EventCalc* calc = EventCalc::Instance();
  double weight = calc->GetWeight();
  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
 
  for (unsigned int k =0; k<bcc->higgstagjets->size(); ++k){
      
       TopJet CA15jet =  bcc->higgstagjets->at(k);
       if((sqrt(pow(topjet.phi()-CA15jet.phi(),2)+pow(topjet.eta()-CA15jet.eta(),2))<1.5)){
	  int nconstituentsCAjet=0;
	 std::vector<PFParticle> jetconsts3;
	 if(topjet.pt()>500) jetconsts3 = calc->GetJetPFParticles(&topjet);
	 else jetconsts3= calc->GetJetPFParticles(&CA15jet);
	 //std::cout<<jetconsts3.size()<<std::endl;
	 nconstituentsCAjet=jetconsts3.size();
	 //PFParticle sumparticle(0,0,0,0);
	 LorentzVector sumparticle(0.,0.,0.,0.);
	 for(unsigned int h=0;h<nconstituentsCAjet;h++){
	   PFParticle particle = jetconsts3.at(h);
	   sumparticle+=particle.v4();
	 }
	 //std::cout<<topjet.pt()<<" "<<CA15jet.pt()<<" "<<sumparticle.pt()<<std::endl;
	 //shower deconstruction
	 double Mmicrojet=0;
	 int Nmicrojets=0;
	 double chi_2;
	 double chi;
	 std::vector<fastjet::PseudoJet> microjets;

	 //double microconesize=0.2;
	
	 for(unsigned int g=1;g<5;g++){
	    int nconstituents_sum=0;
	    LorentzVector sumparticle2(0.,0.,0.,0.);
	   double microconesize=0.1*g;
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
	   chi= Showerdeconstruction_tagger->ChiMicro(CA15jet,Nmicrojets,Mmicrojet,microconesize,microjets);
	   //chi= Showerdeconstruction_tagger->ChiPF(CA15jet,Nmicrojets,Mmicrojet);
	 }
	
	 std::vector<PFParticle> jetconsts2;
	 if(topjet.pt()>500) jetconsts2= calc->GetJetPFParticles(&topjet);
	 else jetconsts2= calc->GetJetPFParticles(&CA15jet);
	 TString hname5=TString::Format("Mmicrojets0%d_chi",g); 
	 Hist(hname5)->Fill(Mmicrojet,weight);
	 //LorentzVector sumparticle2;
	 if(chi>0){
	    TString hname4=TString::Format("Mmicrojets0%d",g); 
	    Hist(hname4)->Fill(Mmicrojet,weight);
	    TString hname3 = TString::Format("nmicrojets0%d",g); 
	    Hist(hname3)->Fill(Nmicrojets,weight);
	      if(Nmicrojets>9) Nmicrojets=9;
	   for(unsigned int t=0; t<Nmicrojets;++t){
	    fastjet::PseudoJet microjet=microjets[t];
	    TString hname = TString::Format("pT%d_micro0%d", t+1,g); 
	    TString hname2 = TString::Format("pT%d_micro0%d_ly", t+1,g); 
	    //std::cout<<hname<<std::endl;  
	      Hist(hname)->Fill(microjet.pt(),weight);
	      Hist(hname2)->Fill(microjet.pt(),weight);
	    int nconstituents=0;
	     
	    //std::cout<<jetconsts2.size()<<std::endl;
	    for(unsigned int p=0;p<jetconsts2.size();p++){
	      PFParticle particle2 = jetconsts2.at(p);
	      if(sqrt(pow(microjet.phi()-particle2.phi(),2)+pow(microjet.eta()-particle2.eta(),2))<g*0.1) {
		nconstituents++;
		nconstituents_sum++;
		sumparticle2+=particle2.v4();
		//std::cout<<sumparticle2.pt()<<std::endl;
	      }
	    }
	     TString hname4 = TString::Format("nconst%d_micro0%d",t+1,g);
	    if (nconstituents>0) Hist(hname4)->Fill(nconstituents,weight);
	   
	   }
	   double fraction;
	   double fraction2;
	   if(nconstituentsCAjet!=0) fraction=(double)nconstituents_sum/(double)nconstituentsCAjet;
	    if(sumparticle.pt()!=0) fraction2=sumparticle2.pt()/sumparticle.pt();
	    std::cout<<sumparticle2.pt()<<" "<<sumparticle.pt()<<" "<<fraction2<<std::endl;
	    TString hnamex = TString::Format("Fraction0%d",g);
	    TString hnamey = TString::Format("FractionpT0%d",g);
	    // std::cout<<"Nconst "<<nconstituents_sum<<" "<<nconstituentsCAjet<<" "<<nconstituents_sum/nconstituentsCAjet<<std::endl;
	    // std::cout<<fraction<<std::endl;
	    if(nconstituentsCAjet!=0) Hist(hnamex)->Fill(fraction,weight);
	     if(sumparticle.pt()!=0) Hist(hnamey)->Fill(fraction2,weight);
	 }
	 } 
	
	 }
       
	 
       }
  
	

  
  
 
 
 
  
  
   
 
 
       
  //calculate jet properties
  std::vector<PFParticle> jetconsts = calc->GetJetPFParticles(&topjet);
  int m_number_of_constituents = jetconsts.size();
  int m_number_of_charged_constituents = 0;
  double m_jet_charge = calc->JetCharge(&topjet);
  Hist("number_of_constituents")->Fill(m_number_of_constituents,weight);
  for(int j=0; j< m_number_of_constituents; ++j){
    if( fabs(jetconsts[j].charge())>0.01) {
      m_number_of_charged_constituents ++;
    }
  }
 
 

 
 
 
}

void MicrojetHists::Fill()
{
}
 
