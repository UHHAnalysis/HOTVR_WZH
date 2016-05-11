#include <time.h>
#include "include/Eugen.h"
#include "include/ZPrimeEugen.h"
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

Eugen::Eugen(const char* name) : BaseHists(name)                                                // named default constructor

// Eugen::Eugen(const char* name, int _rho, double _theta, int _mu) : BaseHists(name), rho(_rho), theta(_theta), mu(_mu)                                                // named default constructor
{}

Eugen::~Eugen()                                                                                                      // default destructor, does nothing
{}

void Eugen::Init()                                                                                                   // book all histograms here
{
  double jetpt_bbins[] = {20, 30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 500, 600, 800, 1600};
     
  //AllZPrime
  Book( TH1F( "AllZPrime",                  "P_{T}-Verteilung aller Zs", 75, 0, 3000));       
  Book( TH1F( "AllZPrime pT < 200",         "P_{T}-Verteilung aller Zs", 75,0, 210));       
  Book( TH1F( "AllZPrime 200 < pT < 400",   "P_{T}-Verteilung aller Zs", 75, 190, 410));       
  Book( TH1F( "AllZPrime 400 < pT < 600",   "P_{T}-Verteilung aller Zs", 75, 390, 610));       
  Book( TH1F( "AllZPrime 600 < pT < 800",   "P_{T}-Verteilung aller Zs", 75, 590, 810));       
  Book( TH1F( "AllZPrime pT > 800",         "P_{T}-Verteilung aller Zs", 75, 790, 3000));
    
  //ZPrimeMasse
  Book( TH1F( "ZPrimeMasse",                "Masse des ZPrime", 75, 0, 4500));       
  Book( TH1F( "ZPrimeMasse pT < 200",       "Masse des ZPrime", 75,0, 4500));       
  Book( TH1F( "ZPrimeMasse 200 < pT < 400", "Masse des ZPrime", 75, 0, 4500));       
  Book( TH1F( "ZPrimeMasse 400 < pT < 600", "Masse des ZPrime", 75, 0, 4500));       
  Book( TH1F( "ZPrimeMasse 600 < pT < 800", "Masse des ZPrime", 75, 0, 4500));       
  Book( TH1F( "ZPrimeMasse pT > 800",       "Masse des ZPrime", 75, 0, 4500));


 //Eta
  Book( TH1F( "Eta",                "Masse des Eta", 75, -3, 3));       
  Book( TH1F( "Eta pT < 200",       "Masse des Eta", 75, -3, 3));       
  Book( TH1F( "Eta 200 < pT < 400", "Masse des Eta", 75, -3, 3));       
  Book( TH1F( "Eta 400 < pT < 600", "Masse des Eta", 75, -3, 3));       
  Book( TH1F( "Eta 600 < pT < 800", "Masse des Eta", 75, -3, 3));       
  Book( TH1F( "Eta pT > 800",       "Masse des Eta", 75, -3, 3));


  //DeltaR
  Book( TH1F( "DeltaR_W1_W1Q1",             "DeltaR zwischen W1-Achse und zerf. Quark11", 75, -10, 10));       
  Book( TH1F( "DeltaR_W1_W1Q2",             "DeltaR zwischen W1-Achse und zerf. Quark12", 75, -10, 10));       
  Book( TH1F( "DeltaR_W1_W2Q1",             "DeltaR zwischen W1-Achse und zerf. Quark21", 75, -10, 10));       
  Book( TH1F( "DeltaR_W1_W2Q2",             "DeltaR zwischen W1-Achse und zerf. Quark22", 75, -10, 10));       
  Book( TH1F( "DeltaR_W1_W2",               "DeltaR zwischen W1-Achse und W2-Achse", 75, -10, 10));       

  Book( TH1F( "DeltaR_W2_W1Q1",             "DeltaR zwischen W2-Achse und zerf. Quark11", 75, -10, 10));       
  Book( TH1F( "DeltaR_W2_W1Q2",             "DeltaR zwischen W2-Achse und zerf. Quark12", 75, -10, 10));       
  Book( TH1F( "DeltaR_W2_W2Q1",             "DeltaR zwischen W2-Achse und zerf. Quark21", 75, -10, 10));       
  Book( TH1F( "DeltaR_W2_W2Q2",             "DeltaR zwischen W2-Achse und zerf. Quark22", 75, -10, 10)); 

  Book( TH2F( "DeltaR_pT",                  "DeltaR zwischen W1 und W2 in Abh. von pT; pT [GeV]; DeltaR", 75, 0, 1500, 75, -5.5, 10));       
  Book( TH2F( "DeltaR_pT pT < 200",         "DeltaR zwischen W1 und W2 in Abh. von pT; pT [GeV]; DeltaR", 75, 0, 200, 75, -5.5, 10));       
  Book( TH2F( "DeltaR_pT 200 < pT < 400",   "DeltaR zwischen W1 und W2 in Abh. von pT; pT [GeV]; DeltaR", 75, 200, 400, 75, -5.5, 10));       
  Book( TH2F( "DeltaR_pT 400 < pT < 600",   "DeltaR zwischen W1 und W2 in Abh. von pT; pT [GeV]; DeltaR", 75, 400, 600, 75, -5.5, 10));       
  Book( TH2F( "DeltaR_pT 600 < pT < 800",   "DeltaR zwischen W1 und W2 in Abh. von pT; pT [GeV]; DeltaR", 75, 600, 800, 75, -5.5, 10));       
  Book( TH2F( "DeltaR_pT pT > 800",         "DeltaR zwischen W1 und W2 in Abh. von pT; pT [GeV]; DeltaR", 75, 800, 1500, 75, -5.5, 10));  

  Book( TH1F( "W_pT_DeltaR_Cut",            "W_pT nach Schutz gegen zu grosse DeltaR", 75, 0, 1500));       

  //Alle W-Bosonen
  Book( TH1F( "Alle-Generator-W-Bosonen", "Alle Ws", 75, 0, 2000));  //Alle Ws    

  //Had_Ws 
  Book( TH1F( "Had_Ws"," P_{T}-Verteilung aller hadr. Ws", 75, 0, 3000));       
  Book( TH1F( "Had_Ws pT < 200"," P_{T}-Verteilung aller hadr. Ws", 75,0, 210));       
  Book( TH1F( "Had_Ws 200 < pT < 400", " P_{T}-Verteilung aller hadr. Ws", 75, 190, 410));       
  Book( TH1F( "Had_Ws 400 < pT < 600", " P_{T}-Verteilung aller hadr. Ws", 75, 390, 610));       
  Book( TH1F( "Had_Ws 600 < pT < 800", " P_{T}-Verteilung aller hadr. Ws", 75, 590, 810));       
  Book( TH1F( "Had_Ws pT > 800",       " P_{T}-Verteilung aller hadr. Ws", 75, 790, 3000));


  //AllJets                           
  Book( TH1F( "AllJets"," P_{T}-Verteilung alle Jets", 75, 0, 3000));       
  Book( TH1F( "AllJets pT < 200"," P_{T}-Verteilung alle Jets", 75,0, 210));       
  Book( TH1F( "AllJets 200 < pT < 400", " P_{T}-Verteilung alle Jets", 75, 190, 410));       
  Book( TH1F( "AllJets 400 < pT < 600", " P_{T}-Verteilung alle Jets", 75, 390, 610));       
  Book( TH1F( "AllJets 600 < pT < 800", " P_{T}-Verteilung alle Jets", 75, 590, 810));       
  Book( TH1F( "AllJets pT > 800",       " P_{T}-Verteilung alle Jets", 75, 790, 3000)); 
         
  //WTagged                      
  Book( TH1F( "WTagged","P_{T} W-Jets (Tagger #1: No cuts)", 75, 0, 3000));
  Book( TH1F( "WTagged pT < 200","P_{T} W-Jets (Tagger #1: No cuts)", 75, 0, 210));
  Book( TH1F( "WTagged 200 < pT < 400","P_{T} W-Jets (Tagger #1: No cuts)", 75, 190, 410));
  Book( TH1F( "WTagged 400 < pT < 600","P_{T} W-Jets (Tagger #1: No cuts)", 75, 390, 610));
  Book( TH1F( "WTagged 600 < pT < 800","P_{T} W-Jets (Tagger #1: No cuts)", 75, 590, 810));
  Book( TH1F( "WTagged pT > 800","P_{T} W-Jets (Tagger #1: No cuts)", 75, 790, 3000));


  //QCD
  Book( TH1F( "QCDGenparticles"," P_{T}-Verteilung aller QCDGenParticles", 75, 0, 3000));       
  Book( TH1F( "QCDGenparticles pT < 200"," P_{T}-Verteilung aller QCDGenParticles", 75,0, 210));       
  Book( TH1F( "QCDGenparticles 200 < pT < 400", " P_{T}-Verteilung aller QCDGenParticles", 75, 190, 410));       
  Book( TH1F( "QCDGenparticles 400 < pT < 600", " P_{T}-Verteilung aller QCDGenParticles", 75, 390, 610));       
  Book( TH1F( "QCDGenparticles 600 < pT < 800", " P_{T}-Verteilung aller QCDGenParticles", 75, 590, 810));       
  Book( TH1F( "QCDGenparticles pT > 800",       " P_{T}-Verteilung aller QCDGenParticles", 75, 790, 3000));


  //LastTagger
  Book( TH1F( "LastTagger"," P_{T} Top-Jets (Tagger #6: Cut on #Subjets, Mass-W, SubJet1-pt, SubJet2-pt, SubJet-pt/Jet-pt ,MMin)", 75, 0, 3000));
  Book( TH1F( "LastTagger pT < 200"," P_{T} Top-Jets (Tagger #6: Cut on Subjet size, mtop, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin)", 75, 0, 210));
  Book( TH1F( "LastTagger 200 < pT < 400"," P_{T} Top-Jets (Tagger #6: Cut on Subjet size, mtop, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin)", 75, 190, 410));
  Book( TH1F( "LastTagger 400 < pT < 600"," P_{T} Top-Jets (Tagger #6: Cut on Subjet size, mtop, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin)", 75, 390, 610));
  Book( TH1F( "LastTagger 600 < pT < 800"," P_{T} Top-Jets (Tagger #6: Cut on Subjet size, mtop, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin)", 75, 590, 810));
  Book( TH1F( "LastTagger pT > 800"," P_{T} Top-Jets (Tagger #6: Cut on Subjet size, mtop, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin)", 75, 790, 3000));




  //massW                     
  Book( TH1F( "massW" ," Masse des rekonstruierten W-Bosons", 75, 0, 250));    
  Book( TH1F( "massW pT < 200" ," Masse des rekonstruierten W-Bosons", 75, 0, 250));    
  Book( TH1F( "massW 200 < pT < 400" ," Masse des rekonstruierten W-Bosons", 75, 0, 250));    
  Book( TH1F( "massW 400 < pT < 600" ," Masse des rekonstruierten W-Bosons", 75, 0, 250));    
  Book( TH1F( "massW 600 < pT < 800" ," Masse des rekonstruierten W-Bosons", 75, 0, 250));    
  Book( TH1F( "massW pT > 800" ," Masse des rekonstruierten W-Bosons", 75, 0, 250));   


  /////////////////////////////////////////////Cutting Variables_Anfang  //////////////////////////////////////////////////////////////////////
  //#SubJets  
  Book( TH1F( "#SubJets" ," Anzahl der Subjets in Fatjets", 6, -0.5, 5.5));
  Book( TH1F( "#SubJets pT < 200" ," Anzahl der Subjets in Fatjets", 6, -0.5, 5.5));
  Book( TH1F( "#SubJets 200 < pT < 400" ," Anzahl der Subjets in Fatjets", 6, -0.5, 5.5));
  Book( TH1F( "#SubJets 400 < pT < 600" ," Anzahl der Subjets in Fatjets", 6, -0.5, 5.5));
  Book( TH1F( "#SubJets 600 < pT < 800" ," Anzahl der Subjets in Fatjets", 6, -0.5, 5.5));
  Book( TH1F( "#SubJets pT > 800" ," Anzahl der Subjets in Fatjets", 6, -0.5, 5.5));


  //tau3pertau2
  Book( TH1F( "tau3pertau2" ," Verhaeltnis von Tau3/Tau2", 75, 0, 1));                                 
  Book( TH1F( "tau3pertau2 pT < 200" ," Verhaeltnis von Tau3/Tau2", 75, 0, 1));                                 
  Book( TH1F( "tau3pertau2 200 < pT < 400" ," Verhaeltnis von Tau3/Tau2", 75, 0, 1));                                 
  Book( TH1F( "tau3pertau2 400 < pT < 600" ," Verhaeltnis von Tau3/Tau2", 75, 0, 1));                                 
  Book( TH1F( "tau3pertau2 600 < pT < 800" ," Verhaeltnis von Tau3/Tau2", 75, 0, 1));                                 
  Book( TH1F( "tau3pertau2 pT > 800" ," Verhaeltnis von Tau3/Tau2", 75, 0, 1));     


  //tau2pertau1
  Book( TH1F( "tau2pertau1" ," Verhaeltnis von Tau2/Tau1", 100, 0.1, 0.9));                                 
  Book( TH1F( "tau2pertau1 pT < 200" ," Verhaeltnis von Tau2/Tau1", 100, 0.1, 0.9));                                 
  Book( TH1F( "tau2pertau1 200 < pT < 400" ," Verhaeltnis von Tau2/Tau1", 100, 0.1, 1));                                 
  Book( TH1F( "tau2pertau1 400 < pT < 600" ," Verhaeltnis von Tau2/Tau1", 100, 0.1, 0.9));                                 
  Book( TH1F( "tau2pertau1 600 < pT < 800" ," Verhaeltnis von Tau2/Tau1", 100, 0.1, 0.9));                                 
  Book( TH1F( "tau2pertau1 pT > 800" ," Verhaeltnis von Tau2/Tau1", 100, 0.1, 0.9));  


  //SubJet1pT
  Book( TH1F( "SubJet1-pT1" ,"pT von SubJets subjets[fatjets_comb.size()-1].at(0).pt()", 75, 0, 500));
  Book( TH1F( "SubJet2-pT1" ,"pT von SubJets subjets[fatjets_comb.size()-1].at(1).pt()", 75, 0, 500));
  Book( TH1F( "SubJet3-pT1" ,"pT von SubJets subjets[fatjets_comb.size()-1].at(2).pt()", 75, 0, 500));
  Book( TH1F( "SubJet4-pT1" ,"pT von SubJets subjets[fatjets_comb.size()-1].at(3).pt()", 75, 0, 500));
  Book( TH1F( "SubJet5-pT1" ,"pT von SubJets subjets[fatjets_comb.size()-1].at(4).pt()", 75, 0, 500));
  Book( TH1F( "SubJet6-pT1" ,"pT von SubJets subjets[fatjets_comb.size()-1].at(5).pt()", 75, 0, 500));
  Book( TH1F( "SubJet7-pT1" ,"pT von SubJets subjets[fatjets_comb.size()-1].at(6).pt()", 75, 0, 500));
  Book( TH1F( "SubJet8-pT1" ,"pT von SubJets subjets[fatjets_comb.size()-1].at(7).pt()", 75, 0, 500));                        

  //SubJet1pT
  Book( TH1F( "SubJet1pT"," P_{T} vom 1.ten Subjet (nach DeltaR-Cut)", 75, 0, 1200));       
  Book( TH1F( "SubJet1pT pT < 200"," P_{T} vom 1.ten Subjet (nach DeltaR-Cut)", 75,0, 210));       
  Book( TH1F( "SubJet1pT 200 < pT < 400", " P_{T} vom 1.ten Subjet (nach DeltaR-Cut)", 75, 190, 410));       
  Book( TH1F( "SubJet1pT 400 < pT < 600", " P_{T} vom 1.ten Subjet (nach DeltaR-Cut)", 75, 390, 610));       
  Book( TH1F( "SubJet1pT 600 < pT < 800", " P_{T} vom 1.ten Subjet (nach DeltaR-Cut) ", 75, 590, 810));       
  Book( TH1F( "SubJet1pT pT > 800",       " P_{T} vom 1.ten Subjet (nach DeltaR-Cut)", 75, 790, 1200));

 //SubJet2pT
  Book( TH1F( "SubJet2pT"," P_{T} vom 2.ten Subjet (nach DeltaR-Cut)", 75, 0, 1000));       
  Book( TH1F( "SubJet2pT pT < 200"," P_{T} vom 2.ten Subjet (nach DeltaR-Cut)", 75,0, 210));       
  Book( TH1F( "SubJet2pT 200 < pT < 400", " P_{T} vom 2.ten Subjet (nach DeltaR-Cut)", 75, 190, 410));       
  Book( TH1F( "SubJet2pT 400 < pT < 600", " P_{T} vom 2.ten Subjet (nach DeltaR-Cut)", 75, 390, 610));       
  Book( TH1F( "SubJet2pT 600 < pT < 800", " P_{T} vom 2.ten Subjet (nach DeltaR-Cut)", 75, 590, 810));       
  Book( TH1F( "SubJet2pT pT > 800",       " P_{T} vom 2.ten Subjet (nach DeltaR-Cut)", 75, 790, 1000));

  //SubJet3pT
  Book( TH1F( "SubJet3pT"," P_{T} vom 3.ten Subjet (nach DeltaR-Cut)", 75, 0, 1000));       
  Book( TH1F( "SubJet3pT pT < 200"," P_{T} vom 3.ten Subjet (nach DeltaR-Cut)", 75,0, 210));       
  Book( TH1F( "SubJet3pT 200 < pT < 400", " P_{T} vom 3.ten Subjet (nach DeltaR-Cut)", 75, 190, 410));       
  Book( TH1F( "SubJet3pT 400 < pT < 600", " P_{T} vom 3.ten Subjet (nach DeltaR-Cut)", 75, 390, 610));       
  Book( TH1F( "SubJet3pT 600 < pT < 800", " P_{T} vom 3.ten Subjet (nach DeltaR-Cut)", 75, 590, 810));       
  Book( TH1F( "SubJet3pT pT > 800",       " P_{T} vom 3.ten Subjet (nach DeltaR-Cut)", 75, 790, 1000));

  //SubJetperJet
  Book( TH1F( "SubJetperJet-pT" ,"P_{T}-Verhaeltnis vom 1.ten Subjet zum Gesamtjet", 75, 0, 1));       
  Book( TH1F( "SubJetperJet-pT pT < 200" ,"P_{T}-Verhaeltnis vom 1.ten Subjet zum Gesamtjet", 75, 0, 1));       
  Book( TH1F( "SubJetperJet-pT 200 < pT < 400" ,"P_{T}-Verhaeltnis vom 1.ten Subjet zum Gesamtjet", 75, 0, 1));       
  Book( TH1F( "SubJetperJet-pT 400 < pT < 600" ,"P_{T}-Verhaeltnis vom 1.ten Subjet zum Gesamtjet", 75, 0, 1));       
  Book( TH1F( "SubJetperJet-pT 600 < pT < 800" ,"P_{T}-Verhaeltnis vom 1.ten Subjet zum Gesamtjet", 75, 0, 1));       
  Book( TH1F( "SubJetperJet-pT pT > 800" ,"P_{T}-Verhaeltnis vom 1.ten Subjet zum Gesamtjet", 75, 0, 1));
       

  //MMin
  Book( TH1F( "MMin" ,"MMin", 75, 0, 300));
  Book( TH1F( "MMin pT < 200" ,"MMin", 75, 0, 300));
  Book( TH1F( "MMin 200 < pT < 400" ,"MMin", 75, 0, 300));
  Book( TH1F( "MMin 400 < pT < 600" ,"MMin", 75, 0, 300));
  Book( TH1F( "MMin 600 < pT < 800" ,"MMin", 75, 0, 300));
  Book( TH1F( "MMin pT > 800" ,"MMin", 75, 0, 300));

  //MMax
  Book( TH1F( "MMax" ,"MMax", 100, 0.1, 250));
  Book( TH1F( "MMax pT < 200" ,"MMax", 100, 0.1, 250));
  Book( TH1F( "MMax 200 < pT < 400" ,"MMax", 100, 0.1, 250));
  Book( TH1F( "MMax 400 < pT < 600" ,"MMax", 100, 0.1, 250));
  Book( TH1F( "MMax 600 < pT < 800" ,"MMax", 100, 0.1, 250));
  Book( TH1F( "MMax pT > 800" ,"MMax", 100, 0.1, 250));









  /////////////////////////////////////////////Cutting Variables_Ende //////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////Cuts_Anfang
  //MassCutOnly
  Book( TH1F( "MassCutOnly"," P_{T} Top-Jets (Tagger #2: Mass cut)", 75, 0, 3000));
  Book( TH1F( "MassCutOnly pT < 200"," P_{T} Top-Jets (Tagger #2: Mass cut)", 75, 0, 210));
  Book( TH1F( "MassCutOnly 200 < pT < 400"," P_{T} Top-Jets (Tagger #2: Mass cut)", 75, 190, 410));
  Book( TH1F( "MassCutOnly 400 < pT < 600"," P_{T} Top-Jets (Tagger #2: Mass cut)", 75, 390, 610));
  Book( TH1F( "MassCutOnly 600 < pT < 800"," P_{T} Top-Jets (Tagger #2: Mass cut)", 75, 590, 810));
  Book( TH1F( "MassCutOnly pT > 800"," P_{T} Top-Jets (Tagger #2: Mass cut)", 75, 790, 3000));

  //MassAndSubJetSizeCut
  Book( TH1F( "MassAndSubJetSizeCut"," P_{T} Top-Jets (Tagger #3: Mass Subjet size cut)", 75, 0, 3000));
  Book( TH1F( "MassAndSubJetSizeCut pT < 200"," P_{T} Top-Jets (Tagger #3: Mass Subjet size cut)", 75, 0, 210));
  Book( TH1F( "MassAndSubJetSizeCut 200 < pT < 400"," P_{T} Top-Jets (Tagger #3: Mass Subjet size cut)", 75, 190, 410));
  Book( TH1F( "MassAndSubJetSizeCut 400 < pT < 600"," P_{T} Top-Jets (Tagger #3: Mass Subjet size cut)", 75, 390, 610));
  Book( TH1F( "MassAndSubJetSizeCut 600 < pT < 800"," P_{T} Top-Jets (Tagger #3: Mass Subjet size cut)", 75, 590, 810));
  Book( TH1F( "MassAndSubJetSizeCut pT > 800"," P_{T} Top-Jets (Tagger #3: Mass Subjet size cut)", 75, 790, 3000));

  //4Cuts
  Book( TH1F( "4Cuts"," P_{T} Top-Jets (Tagger #4: Cut on Subjet size, mtop, mmin, Varjets size)", 75, 0, 3000));
  Book( TH1F( "4Cuts pT < 200"," P_{T} Top-Jets (Tagger #4: Cut on Subjet size, mtop, mmin, Varjets size)", 75, 0, 210));
  Book( TH1F( "4Cuts 200 < pT < 400"," P_{T} Top-Jets (Tagger #4: Cut on Subjet size, mtop, mmin, Varjets size)", 75, 190, 410));
  Book( TH1F( "4Cuts 400 < pT < 600"," P_{T} Top-Jets (Tagger #4: Cut on Subjet size, mtop, mmin, Varjets size)", 75, 390, 610));
  Book( TH1F( "4Cuts 600 < pT < 800"," P_{T} Top-Jets (Tagger #4: Cut on Subjet size, mtop, mmin, Varjets size)", 75, 590, 810));
  Book( TH1F( "4Cuts pT > 800"," P_{T} Top-Jets (Tagger #4: Cut on Subjet size, mtop, mmin, Varjets size)", 75, 790, 3000));

  //7Cuts
  Book( TH1F( "7Cuts"," P_{T} Top-Jets (Tagger #5: Cut on Subjet size, mtop, tau3/tau2, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin)", 75, 0, 3000));
  Book( TH1F( "7Cuts pT < 200"," P_{T} Top-Jets (Tagger #5: Cut on Subjet size, mtop, tau3/tau2, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin)", 75, 0, 210));
  Book( TH1F( "7Cuts 200 < pT < 400"," P_{T} Top-Jets (Tagger #5: Cut on Subjet size, mtop, tau3/tau2, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin)", 75, 190, 410));
  Book( TH1F( "7Cuts 400 < pT < 600"," P_{T} Top-Jets (Tagger #5: Cut on Subjet size, mtop, tau3/tau2, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin)", 75, 390, 610));
  Book( TH1F( "7Cuts 600 < pT < 800"," P_{T} Top-Jets (Tagger #5: Cut on Subjet size, mtop, tau3/tau2, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin)", 75, 590, 810));
  Book( TH1F( "7Cuts pT > 800"," P_{T} Top-Jets (Tagger #5: Cut on Subjet size, mtop, tau3/tau2, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin)", 75, 790, 3000));

  /////////////////////////////////////////////Cuts_Ende

  
  //AllWs                           
  Book( TH1F( "AllWs"," P_{T}-Verteilung alle Ws", 75, 0, 3000));       
  Book( TH1F( "AllWs pT < 200"," P_{T}-Verteilung alle Ws", 75,0, 210));       
  Book( TH1F( "AllWs 200 < pT < 400", " P_{T}-Verteilung alle Ws", 75, 190, 410));       
  Book( TH1F( "AllWs 400 < pT < 600", " P_{T}-Verteilung alle Ws", 75, 390, 610));       
  Book( TH1F( "AllWs 600 < pT < 800", " P_{T}-Verteilung alle Ws", 75, 590, 810));       
  Book( TH1F( "AllWs pT > 800",       " P_{T}-Verteilung alle Ws", 75, 790, 3000));



  Book( TH1F( "ZuVieleSubJets", "Anzahl alle Events mit mehr als 4 SubJets", 75, 0, 100));       
  Book( TH1F( "DeltaR2", "DeltaR2 nach Jetfinding", 75, 0, 5));
  //Book( TH1F( "DeltaR2_2", "DeltaR2 nach Jetfinding", 75, 0, 5));

  Book( TH1F( "minDeltaR2", "minDeltaR2 nach Jetfinding", 75, 0, 5));

  Book( TH1F( "oldR", "minDeltaR2 nach Jetfinding", 75, 0, 5));       

  Book( TH2F( "NvonDeltaR",         "N(DeltaR) nach Jetfinding; DeltaR; N", 75, 0, 10, 75, 0, 200));  


  Book( TH2F( "DR1_pT",                  "DeltaR zwischen W1 und Zerfallsprodukt1 in Abh. von pT; pT [GeV]; DeltaR", 75, 0, 1500, 75, -5.5, 10));       
  Book( TH2F( "DR1_pT pT < 200",         "DeltaR zwischen W1 und Zerfallsprodukt1 in Abh. von pT; pT [GeV]; DeltaR", 75, 0, 200, 75, -5.5, 10));       
  Book( TH2F( "DR1_pT 200 < pT < 400",   "DeltaR zwischen W1 und Zerfallsprodukt1 in Abh. von pT; pT [GeV]; DeltaR", 75, 200, 400, 75, -5.5, 10));       
  Book( TH2F( "DR1_pT 400 < pT < 600",   "DeltaR zwischen W1 und Zerfallsprodukt1 in Abh. von pT; pT [GeV]; DeltaR", 75, 400, 600, 75, -5.5, 10));       
  Book( TH2F( "DR1_pT 600 < pT < 800",   "DeltaR zwischen W1 und Zerfallsprodukt1 in Abh. von pT; pT [GeV]; DeltaR", 75, 600, 800, 75, -5.5, 10));       
  Book( TH2F( "DR1_pT pT > 800",         "DeltaR zwischen W1 und Zerfallsprodukt1 in Abh. von pT; pT [GeV]; DeltaR", 75, 800, 1500, 75, -5.5, 10)); 

  Book( TH2F( "DR2_pT",                  "DeltaR zwischen W1 und Zerfallsprodukt2 in Abh. von pT; pT [GeV]; DeltaR", 75, 0, 1500, 75, -5.5, 10));       
  Book( TH2F( "DR2_pT pT < 200",         "DeltaR zwischen W1 und Zerfallsprodukt2 in Abh. von pT; pT [GeV]; DeltaR", 75, 0, 200, 75, -5.5, 10));       
  Book( TH2F( "DR2_pT 200 < pT < 400",   "DeltaR zwischen W1 und Zerfallsprodukt2 in Abh. von pT; pT [GeV]; DeltaR", 75, 200, 400, 75, -5.5, 10));       
  Book( TH2F( "DR2_pT 400 < pT < 600",   "DeltaR zwischen W1 und Zerfallsprodukt2 in Abh. von pT; pT [GeV]; DeltaR", 75, 400, 600, 75, -5.5, 10));       
  Book( TH2F( "DR2_pT 600 < pT < 800",   "DeltaR zwischen W1 und Zerfallsprodukt2 in Abh. von pT; pT [GeV]; DeltaR", 75, 600, 800, 75, -5.5, 10));       
  Book( TH2F( "DR2_pT pT > 800",         "DeltaR zwischen W1 und Zerfallsprodukt2 in Abh. von pT; pT [GeV]; DeltaR", 75, 800, 1500, 75, -5.5, 10)); 






  // Book( TH1F( "sd_mass" ,"Softdrop-Masse", 75, 0, 500));
  // Book( TH1F( "W0-Tagger" ,"W0-Tagger, 2 Cuts", 75, 0, 1000));

  double PT_bins[] = {0,40,80,120,160,200,240,280,320,360,400,500,600,1000};
  double roc_ptbins[] = {200,400,600,800,1000,10000};
  int nsteps = 50;
  double wmin = 0.0;
  double wmax = 0.5;
  double nsubmin = 0.0;
  double nsubmax = 1.0;
  double csvmin = 0.0;
  double csvmax = 1.0;
  
  tmva_tagger    = new TMVA_tagger();
  tmva_tagger2   = new TMVA_tagger();
  tmva_tagger300 = new TMVA_tagger();
  tmva_tagger500 = new TMVA_tagger();
  tmva_tagger700 = new TMVA_tagger();
  tmva_taggerInf = new TMVA_tagger();
  Showerdeconstruction_tagger = new Showerdeconstruction();
  Showerdeconstruction_taggerV2 = new ShowerdeconstructionV2();
  Softdrop = new SoftDrop();
  jwj = new Jetswithoutjets();
  ecf = new ECF();
  varR = new VariableR();
  IR_Saftey= new Infrared_Saftey();
}

void Eugen::SetIdVersion(TString s)
{idVersion = s;}


void Eugen::Fill()
{
  // fill the histograms
  string algo = "hhtoptagger";
  double akt_r = 0.8;
  double mw(0.), mWlow(78.), mWhigh(82.); // Alte Originalwerte
  // double mw(0.), mWlow(30.), mWhigh(180.);
  int mu(15.);
  double theta(0.5);
  double min_r(0.1), max_r(1.5);
  float minDeltaR = 10000;
  int bestjetindex = -1;
  int bestjetindex2 = -1;
  int SubJetpTmin = 5;
     

  int rho = 210;
  // double mu(30.), theta(0.7),




  int nsteps = 50;
  double wmin = 0.0;
  double wmax = 0.5;
  double nsubmin = 0.0;
  double nsubmax = 1.0;
  double csvmin = 0.0;
  double csvmax = 1.0;
  
  double nsub_step = (nsubmax - nsubmin) / nsteps;
  double w_step = (wmax - wmin) / nsteps;
  double csv_step = (csvmax - csvmin) / nsteps;
  double tstart = clock();
  double time1 = 0;


  EventCalc* calc = EventCalc::Instance();
  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
  bool IsRealData = calc->IsRealData();
  LuminosityHandler* lumih = calc->GetLumiHandler();
  double weight = calc->GetWeight();
  int run = calc->GetRunNum();


  
  //EFFICIENCY
  if(!IsRealData && (idVersion=="WW_500_Gen" || idVersion=="WW_1000_Gen" || idVersion=="WW_1500_Gen" || idVersion=="WW_2000_Gen" || idVersion.Contains("WW_")))
    {

      std::vector<GenParticle>* genparticles = calc->GetGenParticles();  //Liefert alle generierten Particles zurueck
      std::vector<fastjet::PseudoJet> genvector;
      std::vector<fastjet::PseudoJet> genWW;
      TLorentzVector particle;
      TLorentzVector W1;
      TLorentzVector W2;
      TLorentzVector W1Q1;
      TLorentzVector W1Q2;
      TLorentzVector W2Q1;
      TLorentzVector W2Q2;
	  
      for(int tx = 0; tx < genparticles->size(); tx++)
	{
	  if(genparticles->at(tx).pdgId() == 32)
	    { 
	      if(abs(genparticles->at(tx).daughter(genparticles, 1)->pdgId())  ==  24)
		{if(-(genparticles->at(tx).daughter(genparticles, 2)->pdgId()) == genparticles->at(tx).daughter(genparticles, 1)->pdgId())
		    {if(genparticles->at(tx).daughter(genparticles,1)->daughter(genparticles,1)->pdgId() <= 8)
			{if(genparticles->at(tx).daughter(genparticles,1)->daughter(genparticles,2)->pdgId() <= 8)
			    {if(genparticles->at(tx).daughter(genparticles,2)->daughter(genparticles,1)->pdgId() <= 8)
				{if(genparticles->at(tx).daughter(genparticles,2)->daughter(genparticles,2)->pdgId() <= 8)   
				    {				   
				      W1.SetPtEtaPhiE(genparticles->at(tx).daughter(genparticles,1)->pt(),   genparticles->at(tx).daughter(genparticles,1)->eta(),     genparticles->at(tx).daughter(genparticles,1)->phi(),                                             genparticles->at(tx).daughter(genparticles,1)->energy());

	  
				      W2.SetPtEtaPhiE(genparticles->at(tx).daughter(genparticles,2)->pt(),   genparticles->at(tx).daughter(genparticles,2)->eta(),     genparticles->at(tx).daughter(genparticles,2)->phi(),                                             genparticles->at(tx).daughter(genparticles,2)->energy());


				      W1Q1.SetPtEtaPhiE(genparticles->at(tx).daughter(genparticles,1)->daughter(genparticles,1)->pt(), genparticles->at(tx).daughter(genparticles,1)->daughter(genparticles,1)->eta(),                                                   genparticles->at(tx).daughter(genparticles,1)->daughter(genparticles,1)->phi(),                  genparticles->at(tx).daughter(genparticles,1)->daughter(genparticles,1)->energy());          

				      W1Q2.SetPtEtaPhiE(genparticles->at(tx).daughter(genparticles,1)->daughter(genparticles,2)->pt(), genparticles->at(tx).daughter(genparticles,1)->daughter(genparticles,2)->eta(),                                                   genparticles->at(tx).daughter(genparticles,1)->daughter(genparticles,2)->phi(),                  genparticles->at(tx).daughter(genparticles,1)->daughter(genparticles,2)->energy());

      
				      W2Q1.SetPtEtaPhiE(genparticles->at(tx).daughter(genparticles,2)->daughter(genparticles,1)->pt(), genparticles->at(tx).daughter(genparticles,2)->daughter(genparticles,1)->eta(),                                                   genparticles->at(tx).daughter(genparticles,2)->daughter(genparticles,1)->phi(),                  genparticles->at(tx).daughter(genparticles,1)->daughter(genparticles,1)->energy());


				      W2Q2.SetPtEtaPhiE(genparticles->at(tx).daughter(genparticles,2)->daughter(genparticles,2)->pt(), genparticles->at(tx).daughter(genparticles,2)->daughter(genparticles,2)->eta(),                                                   genparticles->at(tx).daughter(genparticles,2)->daughter(genparticles,2)->phi(),   	           genparticles->at(tx).daughter(genparticles,2)->daughter(genparticles,2)->energy());


				                                                                               Hist("DeltaR_W1_W2")->Fill(W1.DeltaR(W2));
													       Hist("DeltaR_W1_W1Q1")->Fill(W1.DeltaR(W1Q1));
													       Hist("DeltaR_W1_W1Q2")->Fill(W1.DeltaR(W1Q2));
													       Hist("DeltaR_W1_W2Q1")->Fill(W1.DeltaR(W1Q1));
													       Hist("DeltaR_W1_W2Q2")->Fill(W1.DeltaR(W1Q1));

													       Hist("DeltaR_W2_W1Q1")->Fill(W1.DeltaR(W1Q1));
													       Hist("DeltaR_W2_W1Q2")->Fill(W1.DeltaR(W1Q2));
													       Hist("DeltaR_W2_W2Q1")->Fill(W1.DeltaR(W1Q1));
													       Hist("DeltaR_W2_W2Q2")->Fill(W1.DeltaR(W1Q1));   


				                                                                               Hist("DeltaR_pT")->Fill(genparticles->at(tx).pt(), W1.DeltaR(W2));   
				      if(genparticles->at(tx).pt() < 200)                                      Hist("DeltaR_pT pT < 200")->Fill(genparticles->at(tx).pt(), W1.DeltaR(W2));   
				      if(genparticles->at(tx).pt() > 200 && genparticles->at(tx).pt() < 400)   Hist("DeltaR_pT 200 < pT < 400")->Fill(genparticles->at(tx).pt(), W1.DeltaR(W2));
				      if(genparticles->at(tx).pt() > 400 && genparticles->at(tx).pt() < 600)   Hist("DeltaR_pT 400 < pT < 600")->Fill(genparticles->at(tx).pt(), W1.DeltaR(W2));
				      if(genparticles->at(tx).pt() > 600 && genparticles->at(tx).pt() < 800)   Hist("DeltaR_pT 600 < pT < 800")->Fill(genparticles->at(tx).pt(), W1.DeltaR(W2));
				      if(genparticles->at(tx).pt() > 800)                                      Hist("DeltaR_pT pT > 800")->Fill(genparticles->at(tx).pt(), W1.DeltaR(W2)); 




				                                                                               Hist("DR1_pT")->Fill(genparticles->at(tx).pt(), W1.DeltaR(W1Q1));   
				      if(genparticles->at(tx).pt() < 200)                                      Hist("DR1_pT pT < 200")->Fill(genparticles->at(tx).pt(), W1.DeltaR(W1Q1));   
				      if(genparticles->at(tx).pt() > 200 && genparticles->at(tx).pt() < 400)   Hist("DR1_pT 200 < pT < 400")->Fill(genparticles->at(tx).pt(), W1.DeltaR(W1Q1));
				      if(genparticles->at(tx).pt() > 400 && genparticles->at(tx).pt() < 600)   Hist("DR1_pT 400 < pT < 600")->Fill(genparticles->at(tx).pt(), W1.DeltaR(W1Q1));
				      if(genparticles->at(tx).pt() > 600 && genparticles->at(tx).pt() < 800)   Hist("DR1_pT 600 < pT < 800")->Fill(genparticles->at(tx).pt(), W1.DeltaR(W1Q1));
				      if(genparticles->at(tx).pt() > 800)                                      Hist("DR1_pT pT > 800")->Fill(genparticles->at(tx).pt(), W1.DeltaR(W1Q1)); 

                                                                                                               Hist("DR2_pT")->Fill(genparticles->at(tx).pt(), W1.DeltaR(W1Q2));   
				      if(genparticles->at(tx).pt() < 200)                                      Hist("DR2_pT pT < 200")->Fill(genparticles->at(tx).pt(), W1.DeltaR(W1Q2));   
				      if(genparticles->at(tx).pt() > 200 && genparticles->at(tx).pt() < 400)   Hist("DR2_pT 200 < pT < 400")->Fill(genparticles->at(tx).pt(), W1.DeltaR(W1Q2));
				      if(genparticles->at(tx).pt() > 400 && genparticles->at(tx).pt() < 600)   Hist("DR2_pT 400 < pT < 600")->Fill(genparticles->at(tx).pt(), W1.DeltaR(W1Q2));
				      if(genparticles->at(tx).pt() > 600 && genparticles->at(tx).pt() < 800)   Hist("DR2_pT 600 < pT < 800")->Fill(genparticles->at(tx).pt(), W1.DeltaR(W1Q2));
				      if(genparticles->at(tx).pt() > 800)                                      Hist("DR2_pT pT > 800")->Fill(genparticles->at(tx).pt(), W1.DeltaR(W1Q2)); 
						      
				    }
				}
			    }
			}
		    }
		}
	    }
	}
   

      for(int tx = 0; tx < genparticles->size(); tx++)
	{
	  fastjet::PseudoJet gen_particle(particle.Px(), particle.Py(), particle.Pz(), particle.E());          // pt:= gen_particle.perp()	 
	  
	  particle.SetPtEtaPhiE(genparticles->at(tx).pt(), genparticles->at(tx).eta(), genparticles->at(tx).phi(), genparticles->at(tx).energy());         
	  
	  if(genparticles->at(tx).pdgId() == 32  &&  genparticles->at(tx).daughter(genparticles,1)->pdgId() != 32  &&  genparticles->at(tx).daughter(genparticles,2)->pdgId() != 32)   
	    {
	                                                                               Hist("AllZPrime")->Fill(genparticles->at(tx).pt(), weight); 
	      if(genparticles->at(tx).pt() < 200)                                      Hist("AllZPrime pT < 200")->Fill(genparticles->at(tx).pt(), weight);         
	      if(genparticles->at(tx).pt() > 200 && genparticles->at(tx).pt() < 400)   Hist("AllZPrime 200 < pT < 400")->Fill(genparticles->at(tx).pt(), weight);                                                
	      if(genparticles->at(tx).pt() > 400 && genparticles->at(tx).pt() < 600)   Hist("AllZPrime 400 < pT < 600")->Fill(genparticles->at(tx).pt(), weight);                                                
	      if(genparticles->at(tx).pt() > 600 && genparticles->at(tx).pt() < 800)   Hist("AllZPrime 600 < pT < 800")->Fill(genparticles->at(tx).pt(), weight);                                                
	      if(genparticles->at(tx).pt() > 800)                                      Hist("AllZPrime pT > 800")->Fill(genparticles->at(tx).pt(), weight);    


	                                                                               Hist("ZPrimeMasse")->Fill(particle.Mt(), weight); 
	      if(genparticles->at(tx).pt() < 200)                                      Hist("ZPrimeMasse pT < 200")->Fill(particle.Mt(), weight);         
	      if(genparticles->at(tx).pt() > 200 && genparticles->at(tx).pt() < 400)   Hist("ZPrimeMasse 200 < pT < 400")->Fill(particle.Mt(), weight);                                                
	      if(genparticles->at(tx).pt() > 400 && genparticles->at(tx).pt() < 600)   Hist("ZPrimeMasse 400 < pT < 600")->Fill(particle.Mt(), weight);                                               
	      if(genparticles->at(tx).pt() > 600 && genparticles->at(tx).pt() < 800)   Hist("ZPrimeMasse 600 < pT < 800")->Fill(particle.Mt(), weight);                               
	      if(genparticles->at(tx).pt() > 800)                                      Hist("ZPrimeMasse pT > 800")->Fill(particle.Mt(), weight); 
	    }	  

	  if(genparticles->at(tx).status() == 1)  genvector.push_back(gen_particle);
	}
      
 TTbarGen2* Decay = calc->GetTTbarGen2();                             
 std::vector<fastjet::PseudoJet> SortedSubJets;
 std::vector<GenParticle> Had_Ws;                                       
 std::vector<GenParticle> decay_products;
 

 for(int i = 0; i < bcc->genparticles->size(); ++i)
   {
     int m_pdgId1 = 0;
     int m_pdgId2 = 0;
     int m_WPlusDecayIndex1, m_WPlusDecayIndex2;
     int m_WMinusDecayIndex1, m_WMinusDecayIndex2;
     GenParticle m_ZPrime, m_WPlusDecay1, m_WPlusDecay2; 
     GenParticle m_WMinusDecay1, m_WMinusDecay2; 

     GenParticle genp = bcc->genparticles->at(i);

     if(abs(genp.pdgId() == 32))
       {
	 bool end1 = false;
	 while(!end1)
	   {
	     if(genp.daughter(bcc->genparticles,1)) if(genp.daughter(bcc->genparticles,1)->pdgId() == 32)  genp = bcc->genparticles->at(genp.daughter(bcc->genparticles,1)->index() -1); //Schutz gegen Gluonen
	       else end1=true;
	     else end1=true;
	   }
	     
	 if(genp.daughter(bcc->genparticles,1) && genp.daughter(bcc->genparticles,2)) // Hat das ZPrime zwei Toechter?
	   {           
	     //--------------------------------------    W+   -----------------------------------------------------//
	     if(genp.daughter(bcc->genparticles,1)->pdgId() == 24) // Ist das W+ die erste Tochter?
	       {
		 GenParticle genp2 = bcc->genparticles->at(genp.daughter(bcc->genparticles,1)->index() -1); //genp2 ist W+
		 Hist("Alle-Generator-W-Bosonen")->Fill(genp2.pt(), weight);
		     
		 if(genp2.daughter(bcc->genparticles,1) && genp2.daughter(bcc->genparticles,2)) // Hat das W+ zwei Toechter?
		   {	
		     if(abs(genp2.daughter(bcc->genparticles,1)->pdgId()) <= 6  && abs(genp2.daughter(bcc->genparticles,2)->pdgId()) <= 6) // Sind beide Toechter des W+ in Quark-Antiquark zerfallen?
		       {
			 m_WPlusDecayIndex1 = genp2.daughter(bcc->genparticles,1)->index();
			 m_WPlusDecay1      = bcc->genparticles->at(m_WPlusDecayIndex1 - 1);  
			  
			 m_WPlusDecayIndex2 = genp2.daughter(bcc->genparticles,2)->index();
			 m_WPlusDecay2 = bcc->genparticles->at(m_WPlusDecayIndex2 -1);
			  
			 Had_Ws.push_back(genp2);
			 decay_products.push_back(m_WPlusDecay1);
			 decay_products.push_back(m_WPlusDecay2);


		                                                    Hist("Had_Ws")->Fill(genp2.pt(), weight);                         // Nur Ws die in Quark-antiQuark zerfallen sind
			 if(genp2.pt() < 200)                       Hist("Had_Ws pT < 200")->Fill(genp2.pt(), weight);         
			 if(genp2.pt() > 200 && genp2.pt() < 400)   Hist("Had_Ws 200 < pT < 400")->Fill(genp2.pt(), weight);                                                
			 if(genp2.pt() > 400 && genp2.pt() < 600)   Hist("Had_Ws 400 < pT < 600")->Fill(genp2.pt(), weight);                                               
			 if(genp2.pt() > 600 && genp2.pt() < 800)   Hist("Had_Ws 600 < pT < 800")->Fill(genp2.pt(), weight);                               
			 if(genp2.pt() > 800)                       Hist("Had_Ws pT > 800")->Fill(genp2.pt(), weight); 





		       }	      
		   }
	       }


	     //--------------------------------------    W-   -----------------------------------------------------//
	     if(genp.daughter(bcc->genparticles,2)->pdgId() == -24)  // Ist das W- die zweite Tochter?
	       {                              		   		
		 GenParticle genp2 = bcc->genparticles->at(genp.daughter(bcc->genparticles,2)->index()-1); //genp2 ist W-
		 Hist("Alle-Generator-W-Bosonen")->Fill(genp2.pt(), weight); //Alle Ws
	 
		 if(genp2.daughter(bcc->genparticles,1) && genp2.daughter(bcc->genparticles,2)) // Hat das W- zwei Toechter?
		   {
		     if(abs(genp2.daughter(bcc->genparticles,1)->pdgId()) <= 6  && abs(genp2.daughter(bcc->genparticles,2)->pdgId()) <= 6) // Sind beide Toechter des W- in Quark-Antiquark zerfallen?
		       {
			 m_WMinusDecayIndex1 = genp2.daughter(bcc->genparticles,1)->index();
			 m_WMinusDecay1      = bcc->genparticles->at(m_WMinusDecayIndex1 - 1);
			  
			 m_WMinusDecayIndex2 = genp2.daughter(bcc->genparticles,2)->index();
			 m_WMinusDecay2 = bcc->genparticles->at(m_WMinusDecayIndex2 -1);
			  
			 Had_Ws.push_back(genp2);
			 decay_products.push_back(m_WMinusDecay1);
			 decay_products.push_back(m_WMinusDecay2);

			                                            Hist("Had_Ws")->Fill(genp2.pt(), weight);// Nur Ws die ind Quark-antiQuark zerfallen sind
			 if(genp2.pt() < 200)                       Hist("Had_Ws pT < 200")->Fill(genp2.pt(), weight);         
			 if(genp2.pt() > 200 && genp2.pt() < 400)   Hist("Had_Ws 200 < pT < 400")->Fill(genp2.pt(), weight);                                                
			 if(genp2.pt() > 400 && genp2.pt() < 600)   Hist("Had_Ws 400 < pT < 600")->Fill(genp2.pt(), weight);                                               
			 if(genp2.pt() > 600 && genp2.pt() < 800)   Hist("Had_Ws 600 < pT < 800")->Fill(genp2.pt(), weight);                               
			 if(genp2.pt() > 800)                       Hist("Had_Ws pT > 800")->Fill(genp2.pt(), weight);
		       }
		   }
	       }
	   } 
	 break;}
   }
 

      int oldbestjet  = -1;
      int oldbestjet2 = -1;      

      for (unsigned int j = 0; j < Had_Ws.size(); j++)
      	{   
      	  minDeltaR = 10000;
      	  bestjetindex = -1;
       
      	  fastjet::ClusterSequence clustersq;
      	  fastjet::ClusterSequence clustersq2;
     	  fastjet::JetDefinition *JetDef;
      	  fastjet::JetDefinition jet_defCA2;
      	  vector<fastjet::PseudoJet> varjets;
	  vector<fastjet::PseudoJet> fatjets;
	  vector<fastjet::PseudoJet> fatjets_backup;
	  vector<fastjet::PseudoJet> fatjets_comb2;
      	  std::vector<fastjet::PseudoJet> jetpart = genvector;
      	  std::vector<fastjet::PseudoJet> inclusive_jetsCA;
      	  EventCalc* calc = EventCalc::Instance();
      	  TopJet Topjet;
      	  double subjetmass;
      	  double mmin;
      	  double distance;

      	  double ptmin(10.);                                        //ptmin(10.) ist Anfangwert fuer Jets!!
	  HHTopTagger pluginAKT(mu, theta, min_r, max_r, rho, mw, HHTopTagger::CALIKE, fatjets);                      // Aufruf Tagger


      	  fastjet::JetDefinition jet_defCA(&pluginAKT);
      	  jet_defCA2 = jet_defCA;
   
      	  fastjet::ClusterSequence clust_seqCA(jetpart, jet_defCA2);
      	  inclusive_jetsCA = clust_seqCA.inclusive_jets(ptmin);
    
      	  SortedSubJets = sorted_by_pt(inclusive_jetsCA);
      	  std::vector<fastjet::PseudoJet> constituents;
      	  std::vector<double> deltaR, deltapT, mj_wmass;

      	  fatjets = pluginAKT.get_fatjets();
      	  deltaR = pluginAKT.get_deltaR();
      	  deltapT = pluginAKT.get_deltapT();
      	  mj_wmass = pluginAKT.get_mass();

      	  fatjets_comb2 = pluginAKT.get_fatjets_comb();
      	  fastjet::ClusterSequence cs2;
      	  fatjets_backup = fatjets;
      	  bool event1 = true;

      	  for(int o = 0; o < fatjets.size(); o++) if(fatjets[o].user_index() != -1) event1 = false;
	
      	  std::vector<fastjet::PseudoJet> fatjets_comb, garbage;
      	  std::vector<fastjet::PseudoJet> subjets[fatjets.size()];
      	  std::vector<int> jetindex[fatjets.size()];
      	  int index = 0;


	  for(int o = 0; o < fatjets.size(); o++)
	    {
	      for(int L = 0; L < clust_seqCA.jets().size(); L++)
	  	{ 
	  	  if(clust_seqCA.jets()[L].pt() == fatjets[o].pt()) jetindex[o].push_back(L);
	  	}
	      jetindex[o].push_back(fatjets[o].user_index());
	    }

	  std::vector<fastjet::PseudoJet> jet_radiation, jet_beam;

	  for(int o = 0; o < fatjets.size(); o++)                                                                         //  Hier werden die Jets gefunden.
	    {
	      //Hists AllJets
	      Hist("AllJets")->Fill(fatjets[o].pt(), weight);         
	      if(fatjets[o].pt() < 200)                                   Hist("AllJets pT < 200")->Fill(fatjets[o].pt(), weight);         
	      if(fatjets[o].pt() > 200 && fatjets[o].pt() < 400)          Hist("AllJets 200 < pT < 400")->Fill(fatjets[o].pt(), weight);                                                
	      if(fatjets[o].pt() > 400 && fatjets[o].pt() < 600)          Hist("AllJets 400 < pT < 600")->Fill(fatjets[o].pt(), weight);                                                
	      if(fatjets[o].pt() > 600 && fatjets[o].pt() < 800)          Hist("AllJets 600 < pT < 800")->Fill(fatjets[o].pt(), weight);                                                
	      if(fatjets[o].pt() > 800)                                   Hist("AllJets pT > 800")->Fill(fatjets[o].pt(), weight);


	      if(fatjets[o].user_index() != -99 && fatjets[o].pt() > ptmin)
	  	{
	  	  index++;
	  	  fastjet::PseudoJet testjet = fatjets[o];
	  	  subjets[index-1].push_back(clust_seqCA.jets()[jetindex[o].at(0)]);

	  	  for(int t = 0; t < fatjets.size(); t++) 
	  	    {
	  	      if(fatjets[o].user_index() == fatjets[t].user_index() && t != o && fatjets[o].user_index() != -1 && fatjets[o].pt() > ptmin)  //ptmin = JETptmin
	  		{
	  		  testjet.operator+=(fatjets[t]);
	  		  fatjets[t].set_user_index(-99);
	  		  subjets[index-1].push_back(clust_seqCA.jets()[jetindex[t].at(0)]);                              
			}   
	  	    }
	       
	  	  for(int k = 0; k < fatjets.size(); k++)
	  	    {
	  	      if(fatjets[k].user_index() / 100. == fatjets[o].user_index())
	  		{
	  		  fatjets_comb.push_back(fatjets[k]);                 
	  		  fatjets[o].set_user_index(-99);                                                                  
	  		  fatjets_comb[fatjets_comb.size()-1].set_user_index(index);
	  		  subjets[fatjets_comb.size()-1] = sorted_by_pt(subjets[fatjets_comb.size()-1]);
			  //	  cout<<"subjets[fatjets_comb.size()-1].size = "<<subjets[fatjets_comb.size()-1].size()  <<endl;


	  		}
	  	      else 
	  		{
	  		  if(fatjets[o].user_index() == -1) jet_beam.push_back(fatjets[o]);
	  		  if(fatjets[o].user_index() == -2) jet_radiation.push_back(fatjets[o]);
	  		}
	  	    }
	  	}
	    }

	  std::vector<fastjet::PseudoJet> TempJets1;
	  std::vector<fastjet::PseudoJet> TempJets2;
	 

	      if(subjets[fatjets_comb.size()-1].size() == 1)
		{
		  if(subjets[fatjets_comb.size()-1].at(0).pt() > SubJetpTmin)
		    {
		      TempJets1.push_back(subjets[fatjets_comb.size()-1].at(0));
		    }
		}

	      if(subjets[fatjets_comb.size()-1].size() == 2)
		{
		  if(subjets[fatjets_comb.size()-1].at(1).pt() > SubJetpTmin)
		    {
		      TempJets1.push_back(subjets[fatjets_comb.size()-1].at(1));
		    }
		}

	      if(subjets[fatjets_comb.size()-1].size() == 3)
		{
		  if(subjets[fatjets_comb.size()-1].at(2).pt() > SubJetpTmin)
		    {
		      TempJets1.push_back(subjets[fatjets_comb.size()-1].at(2));
		    }
		}

	      if(subjets[fatjets_comb.size()-1].size() == 4)
		{
		  if(subjets[fatjets_comb.size()-1].at(3).pt() > SubJetpTmin)
		    {
		      TempJets1.push_back(subjets[fatjets_comb.size()-1].at(3));
		    }
		}

	      if(subjets[fatjets_comb.size()-1].size() == 5)
		{
		  if(subjets[fatjets_comb.size()-1].at(4).pt() > SubJetpTmin)
		    {
		      TempJets1.push_back(subjets[fatjets_comb.size()-1].at(4));
		    }
		}

	      if(subjets[fatjets_comb.size()-1].size() == 6)
		{
		  if(subjets[fatjets_comb.size()-1].at(5).pt() > SubJetpTmin)
		    {
		      TempJets1.push_back(subjets[fatjets_comb.size()-1].at(5));
		    }
		}

	      if(subjets[fatjets_comb.size()-1].size() == 7)
		{
		  if(subjets[fatjets_comb.size()-1].at(6).pt() > SubJetpTmin)
		    {
		      TempJets1.push_back(subjets[fatjets_comb.size()-1].at(6));
		    }
		}

	      if(subjets[fatjets_comb.size()-1].size() == 8)
		{
		  if(subjets[fatjets_comb.size()-1].at(7).pt() > SubJetpTmin)
		    {
		      TempJets1.push_back(subjets[fatjets_comb.size()-1].at(7));
		    }
		}

	      if(subjets[fatjets_comb.size()-1].size() == 9)
		{
		  if(subjets[fatjets_comb.size()-1].at(8).pt() > SubJetpTmin)
		    {
		      TempJets1.push_back(subjets[fatjets_comb.size()-1].at(8));
		    }
		}


	      //     fatjets_comb[o].operator-=(TempJets1[o]);
	      
      
	      //    fatjets_comb[o].operator-=(TempJets1[o]);


   	 
	      // Testhistogramme
	      
	      if(subjets[fatjets_comb.size()-1].size() >= 1)
		{
		  Hist("SubJet1-pT1")->Fill(subjets[fatjets_comb.size()-1].at(0).pt(), weight);
		}
	      
	      
	      if(subjets[fatjets_comb.size()-1].size() >= 2)
		{
		  Hist("SubJet2-pT1")->Fill(subjets[fatjets_comb.size()-1].at(1).pt(), weight);
		}

	      if(subjets[fatjets_comb.size()-1].size() >= 3)
		{
		  Hist("SubJet3-pT1")->Fill(subjets[fatjets_comb.size()-1].at(2).pt(), weight);
		}

	      if(subjets[fatjets_comb.size()-1].size() >= 4)
		{
		  Hist("SubJet4-pT1")->Fill(subjets[fatjets_comb.size()-1].at(3).pt(), weight);
		}
	      if(subjets[fatjets_comb.size()-1].size() >= 5)
		{
		  Hist("SubJet5-pT1")->Fill(subjets[fatjets_comb.size()-1].at(4).pt(), weight);
		}
	      if(subjets[fatjets_comb.size()-1].size() >= 6)
		{
		  Hist("SubJet6-pT1")->Fill(subjets[fatjets_comb.size()-1].at(5).pt(), weight);
		}
	      if(subjets[fatjets_comb.size()-1].size() >= 7)
		{
		  Hist("SubJet7-pT1")->Fill(subjets[fatjets_comb.size()-1].at(6).pt(), weight);

		}
	      if(subjets[fatjets_comb.size()-1].size() >= 8)
		{
		  Hist("SubJet8-pT1")->Fill(subjets[fatjets_comb.size()-1].at(7).pt(), weight);
		}
	      

	      //**************hier werden die jets gefunden. fatjets_comb, gefundenen W-jets;  subjets[fatjets_comb.size()-1] gibt subjets zurueck
	      for(int o = 0; o < fatjets_comb.size(); o++)                         
		{	     
		  for(int t = o; t < fatjets_comb.size(); t++)
		    {
		      Hist("#SubJets")->Fill(subjets[fatjets_comb[t].user_index() - 1].size(), weight);         
		      if(fatjets[o].pt() < 200)                                   Hist("#SubJets pT < 200")->Fill(subjets[fatjets_comb[t].user_index() - 1].size(), weight);         
		      if(fatjets[o].pt() > 200 && fatjets[o].pt() < 400)          Hist("#SubJets 200 < pT < 400")->Fill(subjets[fatjets_comb[t].user_index() - 1].size(), weight);                                                
		      if(fatjets[o].pt() > 400 && fatjets[o].pt() < 600)          Hist("#SubJets 400 < pT < 600")->Fill(subjets[fatjets_comb[t].user_index() - 1].size(), weight);                                                
		      if(fatjets[o].pt() > 600 && fatjets[o].pt() < 800)          Hist("#SubJets 600 < pT < 800")->Fill(subjets[fatjets_comb[t].user_index() - 1].size(), weight);                                                
		      if(fatjets[o].pt() > 800)                                   Hist("#SubJets pT > 800")->Fill(subjets[fatjets_comb[t].user_index() - 1].size(), weight);
		    }




		}

	      std::vector<fastjet::PseudoJet> fatjet_constituents[fatjets_comb.size()];
	      for(int o = 0; o < fatjets_comb.size(); o++)
		{
		  for(int p = 0; p < subjets[fatjets_comb[o].user_index()-1].size(); p++)
		    {
		      for(int k = 0; k < subjets[fatjets_comb[o].user_index()-1][p].constituents().size(); k++)
			{
			  fatjet_constituents[o].push_back(subjets[fatjets_comb[o].user_index()-1][p].constituents().at(k));  
			}             
		    }
		}
	  
	      std::vector<fastjet::PseudoJet> SortedJets;
	      SortedJets =  fatjets_comb; 
	 
	      for(int i = 0; i < SortedJets.size(); i++)
		{    
		  double mjet = SortedJets[i].m();
		  double oldR = 0;
		  std::vector<fastjet::PseudoJet> pfcands = SortedJets[i].constituents();
	     
		  for(int j = 0; j < pfcands.size(); j++)
		    {
		      double R;
		      R = SortedJets[i].delta_R(pfcands[j]);

		      if(R > oldR)
			{
			  oldR = R;
			}
		    }
		  SortedJets[i].set_user_index(int(oldR*10));
		}

	      varjets = SortedJets;
  	
	      double minDeltaR2 = 10000;
	      int bestjetindex2 = -1;
        
	      for(unsigned int i = 0; i < varjets.size(); ++i)
		{
		  double DeltaR2 = sqrt(pow(Had_Ws[j].phi() - varjets[i].phi_std(), 2) + pow(Had_Ws[j].eta() - varjets[i].pseudorapidity(), 2));

		  if(DeltaR2 < minDeltaR2)
		    {
		      minDeltaR2 = DeltaR2;                            
		      bestjetindex2 = i;
		    }
		}
 
	      if(bestjetindex2 > -1)  if(minDeltaR2 > varjets[bestjetindex2].user_index()) bestjetindex2 =- 1;     //  protect against large deltaR
	      if(bestjetindex2 > -1)  if(varjets[bestjetindex2].user_index() / 10. == 0)   bestjetindex2 =- 1;      // varjets[bestjetindex2].user_index() / 10. == 0 geht nur fuer varjets[bestjetindex2].user_index() = 0 ?

	      if(bestjetindex2 > -1)
		{

		  Hist("W_pT_DeltaR_Cut")->Fill(Had_Ws[j].pt(), weight); 
		  Hist("minDeltaR2")->Fill(minDeltaR2, weight); 
		  Hist("NvonDeltaR")->Fill(minDeltaR2, 1); 




		  double mmin = 0;
		  double mmax = 0;
		  int m01 = 0;
		  int m02 = 0;
		  int m03 = 0;
		  int m12 = 0;
		  int m13 = 0;
		  int m23 = 0;

		  std::vector<fastjet::PseudoJet> SortedSubJets2 = sorted_by_pt(subjets[fatjets_comb[bestjetindex2].user_index()-1]);
		      //	      cout<<"subjets[fatjets_comb.size()-1].at(0).pt() ="<<subjets[fatjets_comb.size()-1].at(0).pt()<<endl;
		      //	      cout<<"SortedSubJets2.at(0).pt() = "<<SortedSubJets2.at(0).pt()<<endl;



		  if(SortedSubJets2.size() == 2)                                            
		    {
		      mmin = (SortedSubJets2[0] + SortedSubJets2[1]).m();

		                                                            Hist("MMin")->Fill(mmin, weight); 
		      if(Had_Ws[j].pt() < 200)                              Hist("MMin pT < 200")->Fill(mmin, weight); 
		      if(Had_Ws[j].pt() > 200 && Had_Ws[j].pt() < 400)      Hist("MMin 200 < pT < 400")->Fill(mmin, weight); 
		      if(Had_Ws[j].pt() > 400 && Had_Ws[j].pt() < 600)      Hist("MMin 400 < pT < 600")->Fill(mmin, weight); 
		      if(Had_Ws[j].pt() > 600 && Had_Ws[j].pt() < 800)      Hist("MMin 600 < pT < 800")->Fill(mmin, weight); 
		      if(Had_Ws[j].pt() > 800)                   	    Hist("MMin pT > 800")->Fill(mmin, weight);


		      mmax = (SortedSubJets2[0] + SortedSubJets2[1]).m();

		                                                            Hist("MMax")->Fill(mmax, weight); 
		      if(Had_Ws[j].pt() < 200)                              Hist("MMax pT < 200")->Fill(mmax, weight); 
		      if(Had_Ws[j].pt() > 200 && Had_Ws[j].pt() < 400)      Hist("MMax 200 < pT < 400")->Fill(mmax, weight); 
		      if(Had_Ws[j].pt() > 400 && Had_Ws[j].pt() < 600)      Hist("MMax 400 < pT < 600")->Fill(mmax, weight); 
		      if(Had_Ws[j].pt() > 600 && Had_Ws[j].pt() < 800)      Hist("MMax 600 < pT < 800")->Fill(mmax, weight); 
		      if(Had_Ws[j].pt() > 800)                   	    Hist("MMax pT > 800")->Fill(mmax, weight);

		    }


		  if(SortedSubJets2.size() == 3)                                            
		    {	
		      m01 = (SortedSubJets2[0] + SortedSubJets2[1]).m();
		      m02 = (SortedSubJets2[0] + SortedSubJets2[2]).m();
		      m12 = (SortedSubJets2[1] + SortedSubJets2[2]).m();
		      mmin = std::min(m01,std::min(m02, m12));

		                                                            Hist("MMin")->Fill(mmin, weight); 
		      if(Had_Ws[j].pt() < 200)                              Hist("MMin pT < 200")->Fill(mmin, weight); 
		      if(Had_Ws[j].pt() > 200 && Had_Ws[j].pt() < 400)      Hist("MMin 200 < pT < 400")->Fill(mmin, weight); 
		      if(Had_Ws[j].pt() > 400 && Had_Ws[j].pt() < 600)      Hist("MMin 400 < pT < 600")->Fill(mmin, weight); 
		      if(Had_Ws[j].pt() > 600 && Had_Ws[j].pt() < 800)      Hist("MMin 600 < pT < 800")->Fill(mmin, weight); 
		      if(Had_Ws[j].pt() > 800)                   	    Hist("MMin pT > 800")->Fill(mmin, weight);

		      mmax = std::max(m01,std::max(m02, m12));

		                                                            Hist("MMax")->Fill(mmax, weight); 
		      if(Had_Ws[j].pt() < 200)                              Hist("MMax pT < 200")->Fill(mmax, weight); 
		      if(Had_Ws[j].pt() > 200 && Had_Ws[j].pt() < 400)      Hist("MMax 200 < pT < 400")->Fill(mmax, weight); 
		      if(Had_Ws[j].pt() > 400 && Had_Ws[j].pt() < 600)      Hist("MMax 400 < pT < 600")->Fill(mmax, weight); 
		      if(Had_Ws[j].pt() > 600 && Had_Ws[j].pt() < 800)      Hist("MMax 600 < pT < 800")->Fill(mmax, weight); 
		      if(Had_Ws[j].pt() > 800)                   	    Hist("MMax pT > 800")->Fill(mmax, weight);

		    }

		  if(SortedSubJets2.size() == 4)
		    {
		      m01 = (SortedSubJets2[0] + SortedSubJets2[1]).m();
		      m02 = (SortedSubJets2[0] + SortedSubJets2[2]).m();
		      m03 = (SortedSubJets2[0] + SortedSubJets2[3]).m();   
		      m12 = (SortedSubJets2[1] + SortedSubJets2[2]).m();
		      m13 = (SortedSubJets2[1] + SortedSubJets2[3]).m();
		      m23 = (SortedSubJets2[2] + SortedSubJets2[3]).m();

		      mmin = std::min(m01, std::min(m02, std::min(m03, std::min(m12, std::min(13, 23)))));   

		                                                            Hist("MMin")->Fill(mmin, weight); 
		      if(Had_Ws[j].pt() < 200)                              Hist("MMin pT < 200")->Fill(mmin, weight); 
		      if(Had_Ws[j].pt() > 200 && Had_Ws[j].pt() < 400)      Hist("MMin 200 < pT < 400")->Fill(mmin, weight); 
		      if(Had_Ws[j].pt() > 400 && Had_Ws[j].pt() < 600)      Hist("MMin 400 < pT < 600")->Fill(mmin, weight); 
		      if(Had_Ws[j].pt() > 600 && Had_Ws[j].pt() < 800)      Hist("MMin 600 < pT < 800")->Fill(mmin, weight); 
		      if(Had_Ws[j].pt() > 800)                   	    Hist("MMin pT > 800")->Fill(mmin, weight);  


		      mmax = std::max(m01, std::max(m02, std::max(m03, std::max(m12, std::max(13, 23)))));   

		                                                            Hist("MMax")->Fill(mmax, weight); 
		      if(Had_Ws[j].pt() < 200)                              Hist("MMax pT < 200")->Fill(mmax, weight); 
		      if(Had_Ws[j].pt() > 200 && Had_Ws[j].pt() < 400)      Hist("MMax 200 < pT < 400")->Fill(mmax, weight); 
		      if(Had_Ws[j].pt() > 400 && Had_Ws[j].pt() < 600)      Hist("MMax 400 < pT < 600")->Fill(mmax, weight); 
		      if(Had_Ws[j].pt() > 600 && Had_Ws[j].pt() < 800)      Hist("MMax 600 < pT < 800")->Fill(mmax, weight); 
		      if(Had_Ws[j].pt() > 800)                   	    Hist("MMax pT > 800")->Fill(mmax, weight);   
                                                               
		    }

       
		  // Hist("MMin")->Fill(mmin, weight); 
		  // if(Had_Ws[j].pt() < 200)                              Hist("MMin pT < 200")->Fill(mmin, weight); 
		  // if(Had_Ws[j].pt() > 200 && Had_Ws[j].pt() < 400)      Hist("MMin 200 < pT < 400")->Fill(mmin, weight); 
		  // if(Had_Ws[j].pt() > 400 && Had_Ws[j].pt() < 600)      Hist("MMin 400 < pT < 600")->Fill(mmin, weight); 
		  // if(Had_Ws[j].pt() > 600 && Had_Ws[j].pt() < 800)      Hist("MMin 600 < pT < 800")->Fill(mmin, weight); 
		  // if(Had_Ws[j].pt() > 800)                   	        Hist("MMin pT > 800")->Fill(mmin, weight);
	  
		  if(SortedSubJets2.size() > 1) 
		    {		  
		                                                            Hist("WTagged")->Fill(Had_Ws[j].pt(), weight); 
		      if(Had_Ws[j].pt() < 200)                              Hist("WTagged pT < 200")->Fill(Had_Ws[j].pt(), weight); 
		      if(Had_Ws[j].pt() > 200 && Had_Ws[j].pt() < 400)      Hist("WTagged 200 < pT < 400")->Fill(Had_Ws[j].pt(), weight); 
		      if(Had_Ws[j].pt() > 400 && Had_Ws[j].pt() < 600)      Hist("WTagged 400 < pT < 600")->Fill(Had_Ws[j].pt(), weight); 
		      if(Had_Ws[j].pt() > 600 && Had_Ws[j].pt() < 800)      Hist("WTagged 600 < pT < 800")->Fill(Had_Ws[j].pt(), weight); 
		      if(Had_Ws[j].pt() > 800)                              Hist("WTagged pT > 800")->Fill(Had_Ws[j].pt(), weight); 
		    

		                                                            Hist("massW")->Fill(SortedJets[bestjetindex2].m(), weight); 
		      if(Had_Ws[j].pt() < 200)                              Hist("massW pT < 200")->Fill(SortedJets[bestjetindex2].m(), weight); 
		      if(Had_Ws[j].pt() > 200 && Had_Ws[j].pt() < 400)      Hist("massW 200 < pT < 400")->Fill(SortedJets[bestjetindex2].m(), weight); 
		      if(Had_Ws[j].pt() > 400 && Had_Ws[j].pt() < 600)      Hist("massW 400 < pT < 600")->Fill(SortedJets[bestjetindex2].m(), weight); 
		      if(Had_Ws[j].pt() > 600 && Had_Ws[j].pt() < 800)      Hist("massW 600 < pT < 800")->Fill(SortedJets[bestjetindex2].m(), weight); 
		      if(Had_Ws[j].pt() > 800)                              Hist("massW pT > 800")->Fill(SortedJets[bestjetindex2].m(), weight); 
		    }

		  if(SortedSubJets2.size() >= 1)
		    {
		                                                            Hist("SubJet1pT")->Fill(SortedSubJets2.at(0).pt(), weight); 
		      if(Had_Ws[j].pt() < 200)                              Hist("SubJet1pT pT < 200")->Fill(SortedSubJets2.at(0).pt(), weight); 
		      if(Had_Ws[j].pt() > 200 && Had_Ws[j].pt() < 400)      Hist("SubJet1pT 200 < pT < 400")->Fill(SortedSubJets2.at(0).pt(), weight); 
		      if(Had_Ws[j].pt() > 400 && Had_Ws[j].pt() < 600)      Hist("SubJet1pT 400 < pT < 600")->Fill(SortedSubJets2.at(0).pt(), weight); 
		      if(Had_Ws[j].pt() > 600 && Had_Ws[j].pt() < 800)      Hist("SubJet1pT 600 < pT < 800")->Fill(SortedSubJets2.at(0).pt(), weight);
		      if(Had_Ws[j].pt() > 800)                              Hist("SubJet1pT pT > 800")->Fill(SortedSubJets2.at(0).pt(), weight);


		      //	      cout<<"subjets[fatjets_comb.size()-1].at(0).pt() ="<<subjets[fatjets_comb.size()-1].at(0).pt()<<endl;
		      //	      cout<<"SortedSubJets2.at(0).pt() = "<<SortedSubJets2.at(0).pt()<<endl;



		    }
		  
		  if(SortedSubJets2.size() >= 2)
		    {
		                                                            Hist("SubJet2pT")->Fill(SortedSubJets2.at(1).pt(), weight); 
		      if(Had_Ws[j].pt() < 200)                              Hist("SubJet2pT pT < 200")->Fill(SortedSubJets2.at(1).pt(), weight); 
		      if(Had_Ws[j].pt() > 200 && Had_Ws[j].pt() < 400)      Hist("SubJet2pT 200 < pT < 400")->Fill(SortedSubJets2.at(1).pt(), weight); 
		      if(Had_Ws[j].pt() > 400 && Had_Ws[j].pt() < 600)      Hist("SubJet2pT 400 < pT < 600")->Fill(SortedSubJets2.at(1).pt(), weight); 
		      if(Had_Ws[j].pt() > 600 && Had_Ws[j].pt() < 800)      Hist("SubJet2pT 600 < pT < 800")->Fill(SortedSubJets2.at(1).pt(), weight);
		      if(Had_Ws[j].pt() > 800)                              Hist("SubJet2pT pT > 800")->Fill(SortedSubJets2.at(1).pt(), weight);
		    }

		  if(SortedSubJets2.size() >= 3)
		    {		      		                            
		                                                            Hist("SubJet3pT")->Fill(SortedSubJets2.at(2).pt(), weight); 
		      if(Had_Ws[j].pt() < 200)                              Hist("SubJet3pT pT < 200")->Fill(SortedSubJets2.at(2).pt(), weight); 
		      if(Had_Ws[j].pt() > 200 && Had_Ws[j].pt() < 400)      Hist("SubJet3pT 200 < pT < 400")->Fill(SortedSubJets2.at(2).pt(), weight); 
		      if(Had_Ws[j].pt() > 400 && Had_Ws[j].pt() < 600)      Hist("SubJet3pT 400 < pT < 600")->Fill(SortedSubJets2.at(2).pt(), weight); 
		      if(Had_Ws[j].pt() > 600 && Had_Ws[j].pt() < 800)      Hist("SubJet3pT 600 < pT < 800")->Fill(SortedSubJets2.at(2).pt(), weight);
		      if(Had_Ws[j].pt() > 800)                              Hist("SubJet3pT pT > 800")->Fill(SortedSubJets2.at(2).pt(), weight);
		    }
          
		                                                            Hist("SubJetperJet-pT")->Fill(SortedSubJets2.at(0).pt() / SortedJets[bestjetindex2].pt(), weight); 
		      if(Had_Ws[j].pt() < 200)                              Hist("SubJetperJet-pT pT < 200")->Fill(SortedSubJets2.at(0).pt() / SortedJets[bestjetindex2].pt(), weight); 
		      if(Had_Ws[j].pt() > 200 && Had_Ws[j].pt() < 400)      Hist("SubJetperJet-pT 200 < pT < 400")->Fill(SortedSubJets2.at(0).pt() / SortedJets[bestjetindex2].pt(), weight); 
		      if(Had_Ws[j].pt() > 400 && Had_Ws[j].pt() < 600)      Hist("SubJetperJet-pT 400 < pT < 600")->Fill(SortedSubJets2.at(0).pt() / SortedJets[bestjetindex2].pt(), weight); 
		      if(Had_Ws[j].pt() > 600 && Had_Ws[j].pt() < 800)      Hist("SubJetperJet-pT 600 < pT < 800")->Fill(SortedSubJets2.at(0).pt() / SortedJets[bestjetindex2].pt(), weight);
		      if(Had_Ws[j].pt() > 800)                              Hist("SubJetperJet-pT pT > 800")->Fill(SortedSubJets2.at(0).pt() / SortedJets[bestjetindex2].pt(), weight);
		    
		    
	      
		  if(SortedJets[bestjetindex2].m() > mWlow && SortedJets[bestjetindex2].m() < mWhigh)   
		    {
		                                                              Hist("MassCutOnly")->Fill(Had_Ws[j].pt(), weight); 
		      if(Had_Ws[j].pt() < 200)                                Hist("MassCutOnly pT < 200")->Fill(Had_Ws[j].pt(), weight); 
		      if(Had_Ws[j].pt() > 200 && Had_Ws[j].pt() < 400)        Hist("MassCutOnly 200 < pT < 400")->Fill(Had_Ws[j].pt(), weight); 
		      if(Had_Ws[j].pt() > 400 && Had_Ws[j].pt() < 600)        Hist("MassCutOnly 400 < pT < 600")->Fill(Had_Ws[j].pt(), weight); 
		      if(Had_Ws[j].pt() > 600 && Had_Ws[j].pt() < 800)        Hist("MassCutOnly 600 < pT < 800")->Fill(Had_Ws[j].pt(), weight);
		      if(Had_Ws[j].pt() > 800)                                Hist("MassCutOnly pT > 800")->Fill(Had_Ws[j].pt(), weight);

		      if(SortedSubJets2.size() > 1) 
			{ 
		                                                              Hist("MassAndSubJetSizeCut")->Fill(Had_Ws[j].pt(), weight); 
			  if(Had_Ws[j].pt() < 200)                            Hist("MassAndSubJetSizeCut pT < 200")->Fill(Had_Ws[j].pt(), weight); 
			  if(Had_Ws[j].pt() > 200 && Had_Ws[j].pt() < 400)    Hist("MassAndSubJetSizeCut 200 < pT < 400")->Fill(Had_Ws[j].pt(), weight); 
			  if(Had_Ws[j].pt() > 400 && Had_Ws[j].pt() < 600)    Hist("MassAndSubJetSizeCut 400 < pT < 600")->Fill(Had_Ws[j].pt(), weight); 
			  if(Had_Ws[j].pt() > 600 && Had_Ws[j].pt() < 800)    Hist("MassAndSubJetSizeCut 600 < pT < 800")->Fill(Had_Ws[j].pt(), weight);
			  if(Had_Ws[j].pt() > 800)                            Hist("MassAndSubJetSizeCut pT > 800")->Fill(Had_Ws[j].pt(), weight);

		      		  Hist("minDeltaR2")->Fill(minDeltaR2, weight); 

				//   if(SortedSubJets2.at(0).pt() > 30 && SortedSubJets2.at(1).pt() > 30 && SortedSubJets2.at(0).pt() / SortedJets[bestjetindex2].pt() < 0.8 && mmin > 50 && abs(minDeltaR2) < 3.5)
			    // {
		            //                                                         Hist("LastTagger")->Fill(Had_Ws[j].pt(), weight); 
			    //   if(Had_Ws[j].pt() < 200)                              Hist("LastTagger pT < 200")->Fill(Had_Ws[j].pt(), weight); 
			    //   if(Had_Ws[j].pt() > 200 && Had_Ws[j].pt() < 400)      Hist("LastTagger 200 < pT < 400")->Fill(Had_Ws[j].pt(), weight); 
			    //   if(Had_Ws[j].pt() > 400 && Had_Ws[j].pt() < 600)      Hist("LastTagger 400 < pT < 600")->Fill(Had_Ws[j].pt(), weight); 
			    //   if(Had_Ws[j].pt() > 600 && Had_Ws[j].pt() < 800)      Hist("LastTagger 600 < pT < 800")->Fill(Had_Ws[j].pt(), weight);
			    //   if(Had_Ws[j].pt() > 800)                              Hist("LastTagger pT > 800")->Fill(Had_Ws[j].pt(), weight);

			    // }
			}
		    }
		  fastjet::PseudoJet jet = varjets.at(bestjetindex2);
		  fastjet::PseudoJet probejet = varjets.at(bestjetindex2);

		  bool collimated   = false;
		  bool collimated01 = false;	
		  bool collimated02 = false;
		  bool collimated03 = false;
		  bool collimated04 = false;
		  bool collimated05 = false;
		  bool collimated06 = false;
		  bool collimated07 = false;

		  double microjet_cone = varjets[bestjetindex2].user_index() / 10.;

	      //  if(Decay->IsTopHadronicDecay())
	      //	{
	  	  // double distanceW1, distanceW2, distanceb;
		
	  	  // if(probejet.phi() > PI) distanceW1 = sqrt(pow(Decay->Wdecay1().phi() - (probejet.phi() - 2*PI), 2) + pow(Decay->Wdecay1().eta() - probejet.eta(), 2));
	  	  // else distanceW1 = sqrt(pow(Decay->Wdecay1().phi() - probejet.phi(), 2) + pow(Decay->Wdecay1().eta() - probejet.eta(), 2));
		
	  	  // if(probejet.phi() > PI) distanceW2 = sqrt(pow(Decay->Wdecay2().phi() - (probejet.phi() - 2*PI), 2) + pow(Decay->Wdecay2().eta() - probejet.eta(), 2));
	  	  // else distanceW2 = sqrt(pow(Decay->Wdecay2().phi() - probejet.phi(), 2) + pow(Decay->Wdecay2().eta() - probejet.eta(), 2));

	  	  // if(probejet.phi() > PI) distanceb = sqrt(pow(Decay->bTop().phi() - (probejet.phi() - 2*PI), 2) + pow(Decay->bTop().eta()-probejet.eta(), 2));
	  	  // else distanceb = sqrt(pow(Decay->bTop().phi() - probejet.phi(), 2) + pow(Decay->bTop().eta() - probejet.eta(), 2));

	  	  // if(distanceW1 < microjet_cone && distanceW2 < microjet_cone && distanceb < microjet_cone) collimated = true; 
	  	  // if(distanceW1 < 0.9 * microjet_cone && distanceW2 < 0.9 * microjet_cone && distanceb < 0.9 * microjet_cone) collimated01 = true;
	  	  // if(distanceW1 < 0.8 * microjet_cone && distanceW2 < 0.8 * microjet_cone && distanceb < 0.8 * microjet_cone) collimated02 = true;
	  	  // if(distanceW1 < 0.7 * microjet_cone && distanceW2 < 0.7 * microjet_cone && distanceb < 0.7 * microjet_cone) collimated03 = true;
	  	  // if(distanceW1 < 0.6 * microjet_cone && distanceW2 < 0.6 * microjet_cone && distanceb < 0.6 * microjet_cone) collimated04 = true;
	  	  // if(distanceW1 < 0.5 * microjet_cone && distanceW2 < 0.5 * microjet_cone && distanceb < 0.5 * microjet_cone) collimated05 = true;
	  	  // if(distanceW1 < 0.4 * microjet_cone && distanceW2 < 0.4 * microjet_cone && distanceb < 0.4 * microjet_cone) collimated06 = true;
	  	  // if(distanceW1 < 0.3 * microjet_cone && distanceW2 < 0.3 * microjet_cone && distanceb < 0.3 * microjet_cone) collimated07 = true;
		  // //	}

		  // //   if(Decay->IsAntiTopHadronicDecay())
		  //   // 	{
		  // //	  double distanceW1, distanceW2, distanceb;

	  	  // if(probejet.phi() > PI) distanceW1 = sqrt(pow(Decay->WMinusdecay1().phi() - (probejet.phi() - 2*PI), 2) + pow(Decay->WMinusdecay1().eta() - probejet.eta(), 2));
	  	  // else distanceW1 = sqrt(pow(Decay->WMinusdecay1().phi() - probejet.phi(), 2) + pow(Decay->WMinusdecay1().eta() - probejet.eta(), 2));

	  	  // if(probejet.phi() > PI) distanceW2 = sqrt(pow(Decay->WMinusdecay2().phi() - (probejet.phi() - 2*PI), 2) + pow(Decay->WMinusdecay2().eta() - probejet.eta(), 2));
	  	  // else distanceW2 = sqrt(pow(Decay->WMinusdecay2().phi() - probejet.phi(), 2) + pow(Decay->WMinusdecay2().eta() - probejet.eta(), 2));

	  	  // if(probejet.phi() > PI) distanceb = sqrt(pow(Decay->bAntitop().phi() - (probejet.phi() - 2*PI), 2) + pow(Decay->bAntitop().eta() - probejet.eta(), 2));
	  	  // else distanceb = sqrt(pow(Decay->bAntitop().phi() - probejet.phi(), 2) + pow(Decay->bAntitop().eta() - probejet.eta(), 2));

	  	  // if(distanceW1 < microjet_cone   && distanceW2 < microjet_cone && distanceb<microjet_cone) collimated=true; 
	  	  // if(distanceW1 < 0.9 * microjet_cone && distanceW2 < 0.9 * microjet_cone && distanceb < 0.9 * microjet_cone) collimated01 = true;
	  	  // if(distanceW1 < 0.8 * microjet_cone && distanceW2 < 0.8 * microjet_cone && distanceb < 0.8 * microjet_cone) collimated02 = true;
	  	  // if(distanceW1 < 0.7 * microjet_cone && distanceW2 < 0.7 * microjet_cone && distanceb < 0.7 * microjet_cone) collimated03 = true;
	  	  // if(distanceW1 < 0.6 * microjet_cone && distanceW2 < 0.6 * microjet_cone && distanceb < 0.6 * microjet_cone) collimated04 = true;
	  	  // if(distanceW1 < 0.5 * microjet_cone && distanceW2 < 0.5 * microjet_cone && distanceb < 0.5 * microjet_cone) collimated05 = true;
	  	  // if(distanceW1 < 0.4 * microjet_cone && distanceW2 < 0.4 * microjet_cone && distanceb < 0.4 * microjet_cone) collimated06 = true;
	  	  // if(distanceW1 < 0.3 * microjet_cone && distanceW2 < 0.3 * microjet_cone && distanceb < 0.3 * microjet_cone) collimated07 = true;
		  //	}


	      oldbestjet2 = bestjetindex2;
       	      double mjet;
	      int nsubjets;
	      std::vector<fastjet::PseudoJet> subjets;
	      fastjet::PseudoJet CMSjet; 
	      int index;
	      bool taken[6] = {true,true,true,true,true,true};                                  
	      double olddistance = 1000.;
	      double distance = 100.;

	      for(int t = 0; t < subjets.size(); t++)
	  	{
	  	  for(int L = 0; L < decay_products.size(); L++)
	  	    {
	  	      if(subjets[t].phi() > PI)  distance = sqrt(pow(decay_products[L].phi() - (subjets[t].phi() - 2*PI), 2) + pow(decay_products[L].eta() - subjets[t].eta(), 2));
	  	      else                       distance = sqrt(pow(decay_products[L].phi() - subjets[t].phi(), 2) + pow(decay_products[L].eta() - subjets[t].eta(), 2));
		   
 	  	      if(distance < olddistance && taken[L])                
	  		{ 
	  		  index = L;
	  		  olddistance = distance;
	  		}
	  	    }
	  	  taken[index] = false;             
	  	}
	      
	      mjet = SortedJets[bestjetindex2].m();                                                                               
	      double tau1, tau2, tau3, tau4;

	      if(jet.constituents().size() > 0)                                                  
	  	{ 
	  	  JetPropsPseudo jp(&jet);
	  	  tau1 = jp.GetNsubjettiness(1, Njettiness::onepass_kt_axes, 1., varjets[bestjetindex2].user_index() / 10.);
	  	  tau2 = jp.GetNsubjettiness(2, Njettiness::onepass_kt_axes, 1., varjets[bestjetindex2].user_index() / 10.);
	  	  tau3 = jp.GetNsubjettiness(3, Njettiness::onepass_kt_axes, 1., varjets[bestjetindex2].user_index() / 10.);
	  	  tau4 = jp.GetNsubjettiness(4, Njettiness::onepass_kt_axes, 1., varjets[bestjetindex2].user_index() / 10.);
	  	}

	    	                                                      Hist("tau3pertau2")->Fill(tau3 / tau2, weight); 
	      if(Had_Ws[j].pt() < 200)                                Hist("tau3pertau2 pT < 200")->Fill(tau3 / tau2, weight); 
	      if(Had_Ws[j].pt() > 200 && Had_Ws[j].pt() < 400)        Hist("tau3pertau2 200 < pT < 400")->Fill(tau3 / tau2, weight); 
	      if(Had_Ws[j].pt() > 400 && Had_Ws[j].pt() < 600)        Hist("tau3pertau2 400 < pT < 600")->Fill(tau3 / tau2, weight); 
	      if(Had_Ws[j].pt() > 600 && Had_Ws[j].pt() < 800)        Hist("tau3pertau2 600 < pT < 800")->Fill(tau3 / tau2, weight);
	      if(Had_Ws[j].pt() > 800)                                Hist("tau3pertau2 pT > 800")->Fill(tau3 / tau2, weight);


	    	                                                      Hist("tau2pertau1")->Fill(tau2 / tau1, weight); 
	      if(Had_Ws[j].pt() < 200)                                Hist("tau2pertau1 pT < 200")->Fill(tau2 / tau1, weight); 
	      if(Had_Ws[j].pt() > 200 && Had_Ws[j].pt() < 400)        Hist("tau2pertau1 200 < pT < 400")->Fill(tau2 / tau1, weight); 
	      if(Had_Ws[j].pt() > 400 && Had_Ws[j].pt() < 600)        Hist("tau2pertau1 400 < pT < 600")->Fill(tau2 / tau1, weight); 
	      if(Had_Ws[j].pt() > 600 && Had_Ws[j].pt() < 800)        Hist("tau2pertau1 600 < pT < 800")->Fill(tau2 / tau1, weight);
	      if(Had_Ws[j].pt() > 800)                                Hist("tau2pertau1 pT > 800")->Fill(tau2 / tau1, weight);







	      // fastjet::PseudoJet groomed_jet;
	      // //	      Hist("sd_mass")->Fill(groomed_jet.m(), weight);

	      // if(groomed_jet.m() > 65 && groomed_jet.m() < 135 && tau2 / tau1 < 0.6)
	      // 	{
	      // 	  // 	  Hist("W0-Tagger")->Fill(Had_Ws[j].pt(), weight);
	      // 	}

	      if(SortedSubJets2.size() > 1 && SortedJets[bestjetindex2].m() > mWlow && SortedJets[bestjetindex2].m() < mWhigh && mmin > 50)
		{
		                                                              Hist("4Cuts")->Fill(Had_Ws[j].pt(), weight); 
		      if(Had_Ws[j].pt() < 200)                                Hist("4Cuts pT < 200")->Fill(Had_Ws[j].pt(), weight); 
		      if(Had_Ws[j].pt() > 200 && Had_Ws[j].pt() < 400)        Hist("4Cuts 200 < pT < 400")->Fill(Had_Ws[j].pt(), weight); 
		      if(Had_Ws[j].pt() > 400 && Had_Ws[j].pt() < 600)        Hist("4Cuts 400 < pT < 600")->Fill(Had_Ws[j].pt(), weight); 
		      if(Had_Ws[j].pt() > 600 && Had_Ws[j].pt() < 800)        Hist("4Cuts 600 < pT < 800")->Fill(Had_Ws[j].pt(), weight);
		      if(Had_Ws[j].pt() > 800)                                Hist("4Cuts pT > 800")->Fill(Had_Ws[j].pt(), weight);
		} 

	      if(SortedSubJets2.size() > 1 && SortedJets[bestjetindex2].m() > mWlow && SortedJets[bestjetindex2].m() < mWhigh && SortedSubJets2.at(0).pt() > 30 && SortedSubJets2.at(1).pt() > 30 &&                                         SortedSubJets2.at(0).pt() / SortedJets[bestjetindex2].pt() < 0.8 && mmin > 50 && abs(minDeltaR2) < 3.5 && mmax > 50 && tau2 / tau1 < 0.5) 	         
		{    
		                                                              Hist("LastTagger")->Fill(Had_Ws[j].pt(), weight); 
		      if(Had_Ws[j].pt() < 200)                                Hist("LastTagger pT < 200")->Fill(Had_Ws[j].pt(), weight); 
		      if(Had_Ws[j].pt() > 200 && Had_Ws[j].pt() < 400)        Hist("LastTagger 200 < pT < 400")->Fill(Had_Ws[j].pt(), weight); 
		      if(Had_Ws[j].pt() > 400 && Had_Ws[j].pt() < 600)        Hist("LastTagger 400 < pT < 600")->Fill(Had_Ws[j].pt(), weight); 
		      if(Had_Ws[j].pt() > 600 && Had_Ws[j].pt() < 800)        Hist("LastTagger 600 < pT < 800")->Fill(Had_Ws[j].pt(), weight);
		      if(Had_Ws[j].pt() > 800)                                Hist("LastTagger pT > 800")->Fill(Had_Ws[j].pt(), weight);
		      

		      //ETA:

		                                                              Hist("Eta")->Fill(Had_Ws[j].eta(), weight); 
		      if(Had_Ws[j].pt() < 200)                                Hist("Eta pT < 200")->Fill(Had_Ws[j].eta(), weight); 
		      if(Had_Ws[j].pt() > 200 && Had_Ws[j].pt() < 400)        Hist("Eta 200 < pT < 400")->Fill(Had_Ws[j].eta(), weight); 
		      if(Had_Ws[j].pt() > 400 && Had_Ws[j].pt() < 600)        Hist("Eta 400 < pT < 600")->Fill(Had_Ws[j].eta(), weight); 
		      if(Had_Ws[j].pt() > 600 && Had_Ws[j].pt() < 800)        Hist("Eta 600 < pT < 800")->Fill(Had_Ws[j].eta(), weight);
		      if(Had_Ws[j].pt() > 800)                                Hist("Eta pT > 800")->Fill(Had_Ws[j].eta(), weight);



		}					     


	    }
	  time1 += clock() - tstart;            // Wozu eigentlich???
	}
    }

  



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//          Ab Hier beginnt das Skript fuer QCD-samples!!!!!!!!!!!!!!!!!!!!
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  




  if(!IsRealData && idVersion.Contains("QCD15to3000") || idVersion.Contains("QCD") )   
    {
      std::vector<GenParticle>* genparticles = calc->GetGenParticles();
      std::vector<fastjet::PseudoJet> genvector;
	     
      for(int tx = 0; tx < genparticles->size(); tx++)
	{
	  TLorentzVector particle;
	  particle.SetPtEtaPhiE(genparticles->at(tx).pt(), genparticles->at(tx).eta(), genparticles->at(tx).phi(), genparticles->at(tx).energy());
	  fastjet::PseudoJet gen_particle(particle.Px(), particle.Py(), particle.Pz(), particle.E());
	  if(genparticles->at(tx).status() == 1) genvector.push_back(gen_particle);
	  
	  if(abs(genparticles->at(tx).pdgId()) <= 6 || abs(genparticles->at(tx).pdgId()) == 21)
	    {
	      if(genparticles->at(tx).pt() > 100)

	                                                                                      Hist("QCDGenparticles")->Fill(genparticles->at(tx).pt(), weight);         
	      if(genparticles->at(tx).pt() < 200)                                             Hist("QCDGenparticles pT < 200")->Fill(genparticles->at(tx).pt(), weight);         
	      if(genparticles->at(tx).pt() > 200 && genparticles->at(tx).pt() < 400)          Hist("QCDGenparticles 200 < pT < 400")->Fill(genparticles->at(tx).pt(), weight);                                                
	      if(genparticles->at(tx).pt() > 400 && genparticles->at(tx).pt() < 600)          Hist("QCDGenparticles 400 < pT < 600")->Fill(genparticles->at(tx).pt(), weight);                                                
	      if(genparticles->at(tx).pt() > 600 && genparticles->at(tx).pt() < 800)          Hist("QCDGenparticles 600 < pT < 800")->Fill(genparticles->at(tx).pt(), weight);                                                
	      if(genparticles->at(tx).pt() > 800)                                             Hist("QCDGenparticles pT > 800")->Fill(genparticles->at(tx).pt(), weight); 
	    }

	}
	     
      fastjet::ClusterSequence clustersq, clustersq2;
      double subjetmass, mmin;
      double distance;
      vector<fastjet::PseudoJet> varjets, fatjets, fatjets_backup;
      EventCalc* calc = EventCalc::Instance();
      fastjet::JetDefinition *JetDef ;
      std::vector<fastjet::PseudoJet> SortedSubJets;
      TopJet Topjet;
      JetProps jp(&Topjet, calc->GetPFParticles());
      std::vector<fastjet::PseudoJet> jetpart = genvector;
      double ptmin(10.);
      vector<fastjet::PseudoJet> inclusive_jetsCA;
      fastjet::JetDefinition jet_defCA2;
 
      HHTopTagger pluginAKT(mu, theta,min_r, max_r,rho,mw, HHTopTagger::CALIKE,fatjets);
      fastjet::JetDefinition jet_defCA(&pluginAKT);
      jet_defCA2 = jet_defCA;
      fastjet::ClusterSequence clust_seqCA(jetpart, jet_defCA2);
      inclusive_jetsCA = clust_seqCA.inclusive_jets(ptmin);
      SortedSubJets = sorted_by_pt(inclusive_jetsCA);
      fatjets = pluginAKT.get_fatjets();
      std::vector<double> deltaR, deltapT, mj_wmass;
      deltaR = pluginAKT.get_deltaR();
      deltapT = pluginAKT.get_deltapT();
      mj_wmass = pluginAKT.get_mass();
      fatjets_backup = fatjets;

      bool event1 = true;      
      for(int o = 0; o < fatjets.size(); o++)  if(fatjets[o].user_index() != -1) event1 = false;
    

      std::vector<fastjet::PseudoJet> fatjets_comb, garbage;
      fastjet::PseudoJet testjet;
      std::vector<int> jetindex[fatjets.size()];

      for(int o = 0; o < fatjets.size(); o++)
	{
	  for(int L = 0; L < clust_seqCA.jets().size(); L++)  if(clust_seqCA.jets()[L].pt() == fatjets[o].pt()) jetindex[o].push_back(L);
	  jetindex[o].push_back(fatjets[o].user_index());
	}

      int index = 0;
      std::vector<fastjet::PseudoJet> subjets[fatjets.size()];
      std::vector<fastjet::PseudoJet> jet_radiation, jet_beam;

      for(int o = 0; o < fatjets.size(); o++)
      	{
	  //Hists AllJets
	                                                              Hist("AllJets")->Fill(fatjets[o].pt(), weight);         
	  if(fatjets[o].pt() < 200)                                   Hist("AllJets pT < 200")->Fill(fatjets[o].pt(), weight);         
	  if(fatjets[o].pt() > 200 && fatjets[o].pt() < 400)          Hist("AllJets 200 < pT < 400")->Fill(fatjets[o].pt(), weight);                                                
	  if(fatjets[o].pt() > 400 && fatjets[o].pt() < 600)          Hist("AllJets 400 < pT < 600")->Fill(fatjets[o].pt(), weight);                                                
	  if(fatjets[o].pt() > 600 && fatjets[o].pt() < 800)          Hist("AllJets 600 < pT < 800")->Fill(fatjets[o].pt(), weight);                                                
	  if(fatjets[o].pt() > 800)                                   Hist("AllJets pT > 800")->Fill(fatjets[o].pt(), weight); 


      	  if(fatjets[o].user_index() != -99 && fatjets[o].pt() > ptmin)
      	    {
      	      index++;
      	      fastjet::PseudoJet testjet = fatjets[o];
      	      subjets[index-1].push_back(clust_seqCA.jets()[jetindex[o].at(0)]);

      	      for(int t = 0; t < fatjets.size(); t++) 
      		{
      		  if(fatjets[o].user_index() == fatjets[t].user_index() && t != o && fatjets[o].user_index() != -1 && fatjets[o].pt() > ptmin && fatjets[o].user_index() != -2)
      		    {
      		      testjet.operator+=(fatjets[t]);
      		      fatjets[t].set_user_index(-99);
      		      subjets[index-1].push_back(clust_seqCA.jets()[jetindex[t].at(0)]);
      		    }
      		}
		     
      	      for(int k = 0; k < fatjets.size(); k++)
      		{ 
      		  if(fatjets[k].user_index() / 100. == fatjets[o].user_index())
      		    { 
      		      fatjets_comb.push_back(fatjets[k]);
      		      fatjets[o].set_user_index(-99);
      		      fatjets_comb[fatjets_comb.size()-1].set_user_index(index);
      		      subjets[fatjets_comb.size()-1] = sorted_by_pt(subjets[fatjets_comb.size()-1]);
      		    }
      		  else
      		    {
      		      if(fatjets[k].user_index() == -1) jet_beam.push_back(fatjets[k]);
      		      if(fatjets[k].user_index() == -2) jet_radiation.push_back(fatjets[k]);
      		    }
      		}
      	    }
      	}
       
      std::vector<fastjet::PseudoJet> fatjet_constituents[fatjets_comb.size()];
      
      for(int o = 0; o < fatjets_comb.size(); o++)
      	{
      	  for(int p = 0; p < subjets[fatjets_comb[o].user_index()-1].size(); p++)
      	    for(int k = 0; k < subjets[fatjets_comb[o].user_index()-1][p].constituents().size(); k++)
      	      fatjet_constituents[o].push_back(subjets[fatjets_comb[o].user_index()-1][p].constituents().at(k));
      	}
	     
      std::vector<fastjet::PseudoJet> SortedJets;
      SortedJets =  fatjets_comb;

      for(int i = 0; i < SortedJets.size(); i++)
      	{
      	  std::vector<fastjet::PseudoJet> pfcands = fatjet_constituents[i];      
      	  double oldR = 0;
     
      	  for(int j = 0; j < pfcands.size(); j++)
      	    {
      	      double R = SortedJets[i].delta_R(pfcands[j]);                     //DeltaR durch Jetfinding
      	      if(R > oldR)   oldR = R;
	      // Hist("oldR")->Fill(oldR, weight);           
      	    }
      	  SortedJets[i].set_user_index(int(oldR*10));
 

      	}
	     
      varjets = SortedJets;
      double minDeltaR2 = 10000;
      int bestjetindex2 = -1;
	     
      // for(unsigned int j = 0; j < genparticles->size(); j++)
	//	{
	  //  if(abs(genparticles->at(j).pdgId()) <= 6 || abs(genparticles->at(j).pdgId()) == 21)
	    // {
                            
	      //   }
	  //	}


      for(unsigned int i = 0; i < varjets.size(); ++i)
      	{
	                                                                   Hist("#SubJets")->Fill(subjets[varjets[i].user_index() - 1].size(), weight); 
          if(varjets[i].pt() < 200)                                        Hist("#SubJets pT < 200")->Fill(subjets[varjets[i].user_index() - 1].size(), weight); 
	  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)               Hist("#SubJets 200 < pT < 400")->Fill(subjets[varjets[i].user_index() - 1].size(), weight);   
	  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)               Hist("#SubJets 400 < pT < 600")->Fill(subjets[varjets[i].user_index() - 1].size(), weight);              
	  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)               Hist("#SubJets 600 < pT < 800")->Fill(subjets[varjets[i].user_index() - 1].size(), weight);                 
	  if(varjets[i].pt() > 800)                                        Hist("#SubJets pT > 800")->Fill(subjets[varjets[i].user_index() - 1].size(), weight); 
	  
      	  double highestPt = -1;
      	  bestjetindex = -1;
	  double DeltaRCut;
	  double DeltaR2;
		 
      	  for(unsigned int j = 0; j < genparticles->size(); j++)
      	    {
      	      if (abs(genparticles->at(j).pdgId()) <= 6 || abs(genparticles->at(j).pdgId()) == 21)
      		{
      		  // double DeltaR2 = sqrt(pow(genparticles->at(j).phi() - varjets[i].phi_std(), 2) + pow(genparticles->at(j).eta() - varjets[i].pseudorapidity(), 2));
		            DeltaR2 = sqrt(pow(genparticles->at(j).phi() - varjets[i].phi_std(), 2) + pow(genparticles->at(j).eta() - varjets[i].pseudorapidity(), 2));
      		  if (DeltaR2 < varjets[i].user_index() / 10. && genparticles->at(j).pt() > 100)
      		    {
      		      bestjetindex = j;
      		      highestPt = genparticles->at(j).pt();
		      DeltaRCut = DeltaR2;

      		    }
      		}
      	    }
	  Hist("DeltaR2")->Fill(DeltaR2, weight);         //DeltaR durch genparticle-Info

		
	  if(bestjetindex >- 1)
	    {
	      if(varjets[i].user_index() / 10. == 0)  bestjetindex =- 1;
		 
	      SortedSubJets = sorted_by_pt(subjets[fatjets_comb[i].user_index() - 1]);

	      double mmin = 0;
	      double mmax = 0;
	      int m01 = 0;
	      int m02 = 0;
	      int m03 = 0;
	      int m12 = 0;
	      int m13 = 0;
	      int m23 = 0;

	      if(SortedSubJets.size() == 2)                                            
		{
		  mmin = (SortedSubJets[0] + SortedSubJets[1]).m();

		  Hist("MMin")->Fill(mmin, weight); 
		  if(varjets[i].pt() < 200)                               Hist("MMin pT < 200")->Fill(mmin, weight); 
		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)      Hist("MMin 200 < pT < 400")->Fill(mmin, weight); 
		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)      Hist("MMin 400 < pT < 600")->Fill(mmin, weight); 
		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)      Hist("MMin 600 < pT < 800")->Fill(mmin, weight); 
		  if(varjets[i].pt() > 800)                   	          Hist("MMin pT > 800")->Fill(mmin, weight);


		  mmax = (SortedSubJets[0] + SortedSubJets[1]).m();

		  Hist("MMax")->Fill(mmax, weight); 
		  if(varjets[i].pt() < 200)                               Hist("MMax pT < 200")->Fill(mmax, weight); 
		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)      Hist("MMax 200 < pT < 400")->Fill(mmax, weight); 
		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)      Hist("MMax 400 < pT < 600")->Fill(mmax, weight); 
		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)      Hist("MMax 600 < pT < 800")->Fill(mmax, weight); 
		  if(varjets[i].pt() > 800)                   	          Hist("MMax pT > 800")->Fill(mmax, weight);

		}

	      if(SortedSubJets.size() == 3)                                            
		{	
		  m01 = (SortedSubJets[0] + SortedSubJets[1]).m();
		  m02 = (SortedSubJets[0] + SortedSubJets[2]).m();
		  m12 = (SortedSubJets[1] + SortedSubJets[2]).m();
		  mmin = std::min(m01,std::min(m02, m12));

		                                                          Hist("MMin")->Fill(mmin, weight); 
		  if(varjets[i].pt() < 200)                               Hist("MMin pT < 200")->Fill(mmin, weight); 
		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)      Hist("MMin 200 < pT < 400")->Fill(mmin, weight); 
		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)      Hist("MMin 400 < pT < 600")->Fill(mmin, weight); 
		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)      Hist("MMin 600 < pT < 800")->Fill(mmin, weight); 
		  if(varjets[i].pt() > 800)                   	          Hist("MMin pT > 800")->Fill(mmin, weight);

		  mmax = std::max(m01,std::max(m02, m12));

		                                                          Hist("MMax")->Fill(mmax, weight); 
		  if(varjets[i].pt() < 200)                               Hist("MMax pT < 200")->Fill(mmax, weight); 
		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)      Hist("MMax 200 < pT < 400")->Fill(mmax, weight); 
		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)      Hist("MMax 400 < pT < 600")->Fill(mmax, weight); 
		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)      Hist("MMax 600 < pT < 800")->Fill(mmax, weight); 
		  if(varjets[i].pt() > 800)                   	          Hist("MMax pT > 800")->Fill(mmax, weight);

		}

	      if(SortedSubJets.size() == 4)
		{
		  m01 = (SortedSubJets[0] + SortedSubJets[1]).m();
		  m02 = (SortedSubJets[0] + SortedSubJets[2]).m();
		  m03 = (SortedSubJets[0] + SortedSubJets[3]).m();   
		  m12 = (SortedSubJets[1] + SortedSubJets[2]).m();
		  m13 = (SortedSubJets[1] + SortedSubJets[3]).m();
		  m23 = (SortedSubJets[2] + SortedSubJets[3]).m();

		  mmin = std::min(m01, std::min(m02, std::min(m03, std::min(m12, std::min(13, 23)))));   

	                                                           	  Hist("MMin")->Fill(mmin, weight); 
		  if(varjets[i].pt() < 200)                               Hist("MMin pT < 200")->Fill(mmin, weight); 
		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)      Hist("MMin 200 < pT < 400")->Fill(mmin, weight); 
		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)      Hist("MMin 400 < pT < 600")->Fill(mmin, weight); 
		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)      Hist("MMin 600 < pT < 800")->Fill(mmin, weight); 
		  if(varjets[i].pt() > 800)                   	          Hist("MMin pT > 800")->Fill(mmin, weight);    

		  
		  mmax = std::max(m01, std::max(m02, std::max(m03, std::max(m12, std::max(13, 23)))));   
		  
	                                                                  Hist("MMax")->Fill(mmax, weight); 
		  if(varjets[i].pt() < 200)                               Hist("MMax pT < 200")->Fill(mmax, weight); 
		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)      Hist("MMax 200 < pT < 400")->Fill(mmax, weight); 
		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)      Hist("MMax 400 < pT < 600")->Fill(mmax, weight); 
		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)      Hist("MMax 600 < pT < 800")->Fill(mmax, weight); 
		  if(varjets[i].pt() > 800)                   	          Hist("MMax pT > 800")->Fill(mmax, weight);                                                               
		}


	      if(SortedSubJets.size() > 1)  
	      	{

		                                                                   Hist("WTagged")->Fill(genparticles->at(bestjetindex).pt(),weight);        
 		  if(varjets[i].pt() < 200)                                        Hist("WTagged pT < 200")->Fill(genparticles->at(bestjetindex).pt(),weight);   
		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)               Hist("WTagged 200 < pT < 400")->Fill(genparticles->at(bestjetindex).pt(),weight);   
		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)               Hist("WTagged 400 < pT < 600")->Fill(genparticles->at(bestjetindex).pt(),weight);              
		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)               Hist("WTagged 600 < pT < 800")->Fill(genparticles->at(bestjetindex).pt(),weight);                 
		  if(varjets[i].pt() > 800)                                        Hist("WTagged pT > 800")->Fill(genparticles->at(bestjetindex).pt(),weight); 


		                                                                   Hist("massW")->Fill(varjets[i].m(), weight);      
    		  if(varjets[i].pt() < 200)                                        Hist("massW pT < 200")->Fill(varjets[i].m(), weight);   
		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)               Hist("massW 200 < pT < 400")->Fill(varjets[i].m(), weight);   
		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)               Hist("massW 400 < pT < 600")->Fill(varjets[i].m(), weight);              
		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)               Hist("massW 600 < pT < 800")->Fill(varjets[i].m(), weight);                 
		  if(varjets[i].pt() > 800)                                        Hist("massW pT > 800")->Fill(varjets[i].m(), weight);


		                                                                   Hist("SubJet1pT")->Fill(SortedSubJets.at(0).pt(), weight);      
    		  if(varjets[i].pt() < 200)                                        Hist("SubJet1pT pT < 200")->Fill(SortedSubJets.at(0).pt(), weight);   
		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)               Hist("SubJet1pT 200 < pT < 400")->Fill(SortedSubJets.at(0).pt(), weight);   
		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)               Hist("SubJet1pT 400 < pT < 600")->Fill(SortedSubJets.at(0).pt(), weight);              
		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)               Hist("SubJet1pT 600 < pT < 800")->Fill(SortedSubJets.at(0).pt(), weight);                 
		  if(varjets[i].pt() > 800)                                        Hist("SubJet1pT pT > 800")->Fill(SortedSubJets.at(0).pt(), weight);


		                                                                   Hist("SubJet2pT")->Fill(SortedSubJets.at(1).pt(), weight);      
    		  if(varjets[i].pt() < 200)                                        Hist("SubJet2pT pT < 200")->Fill(SortedSubJets.at(1).pt(), weight);   
		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)               Hist("SubJet2pT 200 < pT < 400")->Fill(SortedSubJets.at(1).pt(), weight);   
		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)               Hist("SubJet2pT 400 < pT < 600")->Fill(SortedSubJets.at(1).pt(), weight);              
		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)               Hist("SubJet2pT 600 < pT < 800")->Fill(SortedSubJets.at(1).pt(), weight);                 
		  if(varjets[i].pt() > 800)                                        Hist("SubJet2pT pT > 800")->Fill(SortedSubJets.at(1).pt(), weight);


		                                                                   Hist("SubJetperJet-pT")->Fill(SortedSubJets.at(0).pt() / varjets[i].pt(), weight);      
    		  if(varjets[i].pt() < 200)                                        Hist("SubJetperJet-pT pT < 200")->Fill(SortedSubJets.at(0).pt() / varjets[i].pt(), weight);   
		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)               Hist("SubJetperJet-pT 200 < pT < 400")->Fill(SortedSubJets.at(0).pt() / varjets[i].pt(), weight);   
		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)               Hist("SubJetperJet-pT 400 < pT < 600")->Fill(SortedSubJets.at(0).pt() / varjets[i].pt(), weight);              
		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)               Hist("SubJetperJet-pT 600 < pT < 800")->Fill(SortedSubJets.at(0).pt() / varjets[i].pt(), weight);                 
		  if(varjets[i].pt() > 800)                                        Hist("SubJetperJet-pT pT > 800")->Fill(SortedSubJets.at(0).pt() / varjets[i].pt(), weight);
		}

	      std::vector<fastjet::PseudoJet> subjets;
	      fastjet::PseudoJet jet = varjets.at(i);
	      fastjet::PseudoJet CMSjet;
	      double mjet;
	      int nsubjets;

		                                                                   Hist("AllWs")->Fill(genparticles->at(bestjetindex).pt(), weight);      
    		  if(varjets[i].pt() < 200)                                        Hist("AllWs pT < 200")->Fill(genparticles->at(bestjetindex).pt(), weight);   
		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)               Hist("AllWs 200 < pT < 400")->Fill(genparticles->at(bestjetindex).pt(), weight);   
		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)               Hist("AllWs 400 < pT < 600")->Fill(genparticles->at(bestjetindex).pt(), weight);              
		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)               Hist("AllWs 600 < pT < 800")->Fill(genparticles->at(bestjetindex).pt(), weight);                 
		  if(varjets[i].pt() > 800)                                        Hist("AllWs pT > 800")->Fill(genparticles->at(bestjetindex).pt(), weight);


	      mjet = SortedJets[i].m();
	      double tau1,tau2,tau3,tau4;
	      JetPropsPseudo jp(&jet);
	      tau1 = jp.GetNsubjettiness(1, Njettiness::onepass_kt_axes, 1., varjets[i].user_index() / 10.);
	      tau2 = jp.GetNsubjettiness(2, Njettiness::onepass_kt_axes, 1., varjets[i].user_index() / 10.);
	      tau3 = jp.GetNsubjettiness(3, Njettiness::onepass_kt_axes, 1., varjets[i].user_index() / 10.);
	      tau4 = jp.GetNsubjettiness(4, Njettiness::onepass_kt_axes, 1., varjets[i].user_index() / 10.);


		                                                                   Hist("tau3pertau2")->Fill(tau3 / tau2, weight);      
    		  if(varjets[i].pt() < 200)                                        Hist("tau3pertau2 pT < 200")->Fill(tau3 / tau2, weight);   
		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)               Hist("tau3pertau2 200 < pT < 400")->Fill(tau3 / tau2, weight);   
		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)               Hist("tau3pertau2 400 < pT < 600")->Fill(tau3 / tau2, weight);              
		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)               Hist("tau3pertau2 600 < pT < 800")->Fill(tau3 / tau2, weight);                 
		  if(varjets[i].pt() > 800)                                        Hist("tau3pertau2 pT > 800")->Fill(tau3 / tau2, weight);
                             

		                                                                   Hist("tau2pertau1")->Fill(tau2 / tau1, weight);      
    		  if(varjets[i].pt() < 200)                                        Hist("tau2pertau1 pT < 200")->Fill(tau2 / tau1, weight);   
		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)               Hist("tau2pertau1 200 < pT < 400")->Fill(tau2 / tau1, weight);   
		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)               Hist("tau2pertau1 400 < pT < 600")->Fill(tau2 / tau1, weight);              
		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)               Hist("tau2pertau1 600 < pT < 800")->Fill(tau2 / tau1, weight);                 
		  if(varjets[i].pt() > 800)                                        Hist("tau2pertau1 pT > 800")->Fill(tau2 / tau1, weight);










	      fastjet::PseudoJet groomed_jet;
	      //	      Hist("sd_mass")->Fill(groomed_jet.m(), weight);

	      if(groomed_jet.m() > 65 && groomed_jet.m() < 135 && tau2 / tau1 < 0.6)
	    	{
		  //   	  Hist("W0-Tagger")->Fill(genparticles->at(bestjetindex).pt(), weight); /// SortedJets[i].m() =  varjets[i].m()
	    	}

	      if(SortedSubJets.size() > 1 && SortedJets[i].m() > mWlow && SortedJets[i].m() < mWhigh && mmin > 50) 
		{
		                                                                   Hist("4Cuts")->Fill(genparticles->at(bestjetindex).pt(), weight);      
    		  if(varjets[i].pt() < 200)                                        Hist("4Cuts pT < 200")->Fill(genparticles->at(bestjetindex).pt(), weight);   
		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)               Hist("4Cuts 200 < pT < 400")->Fill(genparticles->at(bestjetindex).pt(), weight);   
		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)               Hist("4Cuts 400 < pT < 600")->Fill(genparticles->at(bestjetindex).pt(), weight);              
		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)               Hist("4Cuts 600 < pT < 800")->Fill(genparticles->at(bestjetindex).pt(), weight);                 
		  if(varjets[i].pt() > 800)                                        Hist("4Cuts pT > 800")->Fill(genparticles->at(bestjetindex).pt(), weight);
		}
	      

	      if(SortedSubJets.size() > 1 && varjets[i].m() > mWlow && varjets[i].m() < mWhigh  && SortedSubJets.at(0).pt() > 30 && SortedSubJets.at(1).pt() > 30 && SortedSubJets.at(0).pt() / varjets[i].pt() < 0.8 && mmin > 50                   && abs(DeltaRCut) < 3.5 && mmax > 50 && tau2 / tau1 < 0.5)      
		{
		                                                                   Hist("LastTagger")->Fill(genparticles->at(bestjetindex).pt(), weight);      
    		  if(varjets[i].pt() < 200)                                        Hist("LastTagger pT < 200")->Fill(genparticles->at(bestjetindex).pt(), weight);   
		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)               Hist("LastTagger 200 < pT < 400")->Fill(genparticles->at(bestjetindex).pt(), weight);   
		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)               Hist("LastTagger 400 < pT < 600")->Fill(genparticles->at(bestjetindex).pt(), weight);              
		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)               Hist("LastTagger 600 < pT < 800")->Fill(genparticles->at(bestjetindex).pt(), weight);                 
		  if(varjets[i].pt() > 800)                                        Hist("LastTagger pT > 800")->Fill(genparticles->at(bestjetindex).pt(), weight);




		      //ETA:

		                                                                Hist("Eta")->Fill(genparticles->at(bestjetindex).eta(), weight); 
		      if(varjets[i].pt() < 200)                                 Hist("Eta pT < 200")->Fill(genparticles->at(bestjetindex).eta(), weight); 
		      if(varjets[i].pt() > 200 && varjets[i].pt() < 400)        Hist("Eta 200 < pT < 400")->Fill(genparticles->at(bestjetindex).eta(), weight); 
		      if(varjets[i].pt() > 400 && varjets[i].pt() < 600)        Hist("Eta 400 < pT < 600")->Fill(genparticles->at(bestjetindex).eta(), weight); 
		      if(varjets[i].pt() > 600 && varjets[i].pt() < 800)        Hist("Eta 600 < pT < 800")->Fill(genparticles->at(bestjetindex).eta(), weight);
		      if(varjets[i].pt() > 800)                                 Hist("Eta pT > 800")->Fill(genparticles->at(bestjetindex).eta(), weight);



		}
	    }
	}
    }
}







void Eugen::Finish()
{
//   // EventCalc* calc = EventCalc::Instance();
//   // bool IsRealData = calc->IsRealData();
//   // /*
//   //   if(IsRealData)
//   //   {
//   //   Hist("N_pv_perLumiBin")->Divide(Hist("N_pv_perLumiBin"), Hist("N_events_perLumiBin"));
//   //   Hist( "N_pv_perLumiBin")->GetYaxis()->SetTitle("Events/Lumi");
//   //   }
//   // */
}

