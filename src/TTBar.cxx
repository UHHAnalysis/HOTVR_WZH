// #include <time.h>
// #include "include/Eugen.h"
// #include "include/TTBar.h"
// #include "SFrameTools/include/EventCalc.h"
// #include "include/ZprimeFullHadTools.h"
// #include "NtupleWriter/include/JetProps.h"
// #include "include/TopTagfunctions.h"
// #include "fastjet/PseudoJet.hh"
// #include "fastjet/ClusterSequenceArea.hh"
// #include "fastjet/ClusterSequencePassiveArea.hh"
// #include "NtupleWriter/include/JetPropsPseudo.h"
// #include "fastjet/contrib/ClusteringVetoPlugin.hh"
// #include "fastjet/contrib/HHTopTagger.hh"
// #include <iostream>
// #include "TH3.h"
// using namespace std;
// using namespace fastjet;
// using namespace contrib;


// Eugen::Eugen(const char* name, int _rho) : BaseHists(name), rho(_rho)                                                // named default constructor
// {}

// Eugen::~Eugen()                                                                                                      // default destructor, does nothing
// {}

// void Eugen::Init()                                                                                                   // book all histograms here
// {
//   double jetpt_bbins[] = {20, 30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 500, 600, 800, 1600};

//   //AllTops
//   Book( TH1F( "AllTops"," P_{T}-Verteilung alle Tops", 75, 0, 3000));       
//   Book( TH1F( "AllTops pT < 200"," P_{T}-Verteilung alle Tops", 75,0, 210));       
//   Book( TH1F( "AllTops 200 < pT < 400", " P_{T}-Verteilung alle Tops", 75, 190, 410));       
//   Book( TH1F( "AllTops 400 < pT < 600", " P_{T}-Verteilung alle Tops", 75, 390, 610));       
//   Book( TH1F( "AllTops 600 < pT < 800", " P_{T}-Verteilung alle Tops", 75, 590, 810));       
//   Book( TH1F( "AllTops pT > 800",       " P_{T}-Verteilung alle Tops", 75, 790, 3000));       

//   //AllJets                           
//   Book( TH1F( "AllJets"," P_{T}-Verteilung alle Jets", 75, 0, 3000));       
//   Book( TH1F( "AllJets pT < 200"," P_{T}-Verteilung alle Jets", 75,0, 210));       
//   Book( TH1F( "AllJets 200 < pT < 400", " P_{T}-Verteilung alle Jets", 75, 190, 410));       
//   Book( TH1F( "AllJets 400 < pT < 600", " P_{T}-Verteilung alle Jets", 75, 390, 610));       
//   Book( TH1F( "AllJets 600 < pT < 800", " P_{T}-Verteilung alle Jets", 75, 590, 810));       
//   Book( TH1F( "AllJets pT > 800",       " P_{T}-Verteilung alle Jets", 75, 790, 3000)); 
         
//   //TopTaggedTops                      
//   Book( TH1F( "TopTaggedTops","P_{T} Top-Jets (Tagger #1: No cuts)", 75, 0, 3000));
//   Book( TH1F( "TopTaggedTops pT < 200","P_{T} Top-Jets (Tagger #1: No cuts)", 75, 0, 210));
//   Book( TH1F( "TopTaggedTops 200 < pT < 400","P_{T} Top-Jets (Tagger #1: No cuts)", 75,190, 410));
//   Book( TH1F( "TopTaggedTops 400 < pT < 600","P_{T} Top-Jets (Tagger #1: No cuts)", 75, 390, 610));
//   Book( TH1F( "TopTaggedTops 600 < pT < 800","P_{T} Top-Jets (Tagger #1: No cuts)", 75, 590, 810));
//   Book( TH1F( "TopTaggedTops pT > 800","P_{T} Top-Jets (Tagger #1: No cuts)", 75, 790, 3000));

//   //MassCutOnly
//   Book( TH1F( "MassCutOnly"," P_{T} Top-Jets (Tagger #2: Mass cut)", 75, 0, 3000));
//   Book( TH1F( "MassCutOnly pT < 200"," P_{T} Top-Jets (Tagger #2: Mass cut)", 75, 0, 210));
//   Book( TH1F( "MassCutOnly 200 < pT < 400"," P_{T} Top-Jets (Tagger #2: Mass cut)", 75, 190, 410));
//   Book( TH1F( "MassCutOnly 400 < pT < 600"," P_{T} Top-Jets (Tagger #2: Mass cut)", 75, 390, 610));
//   Book( TH1F( "MassCutOnly 600 < pT < 800"," P_{T} Top-Jets (Tagger #2: Mass cut)", 75, 590, 810));
//   Book( TH1F( "MassCutOnly pT > 800"," P_{T} Top-Jets (Tagger #2: Mass cut)", 75, 790, 3000));

//   //MassAndSubJetSizeCut
//   Book( TH1F( "MassAndSubJetSizeCut"," P_{T} Top-Jets (Tagger #3: Mass Subjet size cut)", 75, 0, 3000));
//   Book( TH1F( "MassAndSubJetSizeCut pT < 200"," P_{T} Top-Jets (Tagger #3: Mass Subjet size cut)", 75, 0, 210));
//   Book( TH1F( "MassAndSubJetSizeCut 200 < pT < 400"," P_{T} Top-Jets (Tagger #3: Mass Subjet size cut)", 75, 190, 410));
//   Book( TH1F( "MassAndSubJetSizeCut 400 < pT < 600"," P_{T} Top-Jets (Tagger #3: Mass Subjet size cut)", 75, 390, 610));
//   Book( TH1F( "MassAndSubJetSizeCut 600 < pT < 800"," P_{T} Top-Jets (Tagger #3: Mass Subjet size cut)", 75, 590, 810));
//   Book( TH1F( "MassAndSubJetSizeCut pT > 800"," P_{T} Top-Jets (Tagger #3: Mass Subjet size cut)", 75, 790, 3000));

//   //4Cuts
//   Book( TH1F( "4Cuts"," P_{T} Top-Jets (Tagger #4: Cut on Subjet size, mtop, mmin2, Varjets size)", 75, 0, 3000));
//   Book( TH1F( "4Cuts pT < 200"," P_{T} Top-Jets (Tagger #4: Cut on Subjet size, mtop, mmin2, Varjets size)", 75, 0, 210));
//   Book( TH1F( "4Cuts 200 < pT < 400"," P_{T} Top-Jets (Tagger #4: Cut on Subjet size, mtop, mmin2, Varjets size)", 75, 190, 410));
//   Book( TH1F( "4Cuts 400 < pT < 600"," P_{T} Top-Jets (Tagger #4: Cut on Subjet size, mtop, mmin2, Varjets size)", 75, 390, 610));
//   Book( TH1F( "4Cuts 600 < pT < 800"," P_{T} Top-Jets (Tagger #4: Cut on Subjet size, mtop, mmin2, Varjets size)", 75, 590, 810));
//   Book( TH1F( "4Cuts pT > 800"," P_{T} Top-Jets (Tagger #4: Cut on Subjet size, mtop, mmin2, Varjets size)", 75, 790, 3000));

//   //7Cuts
//   Book( TH1F( "7Cuts"," P_{T} Top-Jets (Tagger #5: Cut on Subjet size, mtop, tau3/tau2, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin2)", 75, 0, 3000));
//   Book( TH1F( "7Cuts pT < 200"," P_{T} Top-Jets (Tagger #5: Cut on Subjet size, mtop, tau3/tau2, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin2)", 75, 0, 210));
//   Book( TH1F( "7Cuts 200 < pT < 400"," P_{T} Top-Jets (Tagger #5: Cut on Subjet size, mtop, tau3/tau2, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin2)", 75, 190, 410));
//   Book( TH1F( "7Cuts 400 < pT < 600"," P_{T} Top-Jets (Tagger #5: Cut on Subjet size, mtop, tau3/tau2, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin2)", 75, 390, 610));
//   Book( TH1F( "7Cuts 600 < pT < 800"," P_{T} Top-Jets (Tagger #5: Cut on Subjet size, mtop, tau3/tau2, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin2)", 75, 590, 810));
//   Book( TH1F( "7Cuts pT > 800"," P_{T} Top-Jets (Tagger #5: Cut on Subjet size, mtop, tau3/tau2, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin2)", 75, 790, 3000));

//   //LastTagger
//   Book( TH1F( "LastTagger"," P_{T} Top-Jets (Tagger #6: Cut on Subjet size, mtop, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin2)", 75, 0, 3000));
//   Book( TH1F( "LastTagger pT < 200"," P_{T} Top-Jets (Tagger #6: Cut on Subjet size, mtop, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin2)", 75, 0, 210));
//   Book( TH1F( "LastTagger 200 < pT < 400"," P_{T} Top-Jets (Tagger #6: Cut on Subjet size, mtop, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin2)", 75, 190, 410));
//   Book( TH1F( "LastTagger 400 < pT < 600"," P_{T} Top-Jets (Tagger #6: Cut on Subjet size, mtop, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin2)", 75, 390, 610));
//   Book( TH1F( "LastTagger 600 < pT < 800"," P_{T} Top-Jets (Tagger #6: Cut on Subjet size, mtop, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin2)", 75, 590, 810));
//   Book( TH1F( "LastTagger pT > 800"," P_{T} Top-Jets (Tagger #6: Cut on Subjet size, mtop, subjet1-pt, subjet2-pt, subjetpt/varjetpt ,mmin2)", 75, 790, 3000));


// ///////////////////////////////////    Cuts in Tagger #5    /////////////////////////////////////////////////////////////////////////////////////////////////////////

//   //#SubJets  
//   Book( TH1F( "#SubJets" ," Anzahl der Subjets in Fatjets", 6, -0.5, 5.5));
//   Book( TH1F( "#SubJets pT < 200" ," Anzahl der Subjets in Fatjets", 6, -0.5, 5.5));
//   Book( TH1F( "#SubJets 200 < pT < 400" ," Anzahl der Subjets in Fatjets", 6, -0.5, 5.5));
//   Book( TH1F( "#SubJets 400 < pT < 600" ," Anzahl der Subjets in Fatjets", 6, -0.5, 5.5));
//   Book( TH1F( "#SubJets 600 < pT < 800" ," Anzahl der Subjets in Fatjets", 6, -0.5, 5.5));
//   Book( TH1F( "#SubJets pT > 800" ," Anzahl der Subjets in Fatjets", 6, -0.5, 5.5));

//   //masstop                     
//   Book( TH1F( "masstop" ," Masse des rekonstruierten tops", 75, 0, 250));    
//   Book( TH1F( "masstop pT < 200" ," Masse des rekonstruierten tops", 75, 0, 250));    
//   Book( TH1F( "masstop 200 < pT < 400" ," Masse des rekonstruierten tops", 75, 0, 250));    
//   Book( TH1F( "masstop 400 < pT < 600" ," Masse des rekonstruierten tops", 75, 0, 250));    
//   Book( TH1F( "masstop 600 < pT < 800" ," Masse des rekonstruierten tops", 75, 0, 250));    
//   Book( TH1F( "masstop pT > 800" ," Masse des rekonstruierten tops", 75, 0, 250));    

//   //tau3pertau2
//   Book( TH1F( "tau3pertau2" ," Verhaeltnis von Tau3/Tau2", 75, 0, 1));                                 
//   Book( TH1F( "tau3pertau2 pT < 200" ," Verhaeltnis von Tau3/Tau2", 75, 0, 1));                                 
//   Book( TH1F( "tau3pertau2 200 < pT < 400" ," Verhaeltnis von Tau3/Tau2", 75, 0, 1));                                 
//   Book( TH1F( "tau3pertau2 400 < pT < 600" ," Verhaeltnis von Tau3/Tau2", 75, 0, 1));                                 
//   Book( TH1F( "tau3pertau2 600 < pT < 800" ," Verhaeltnis von Tau3/Tau2", 75, 0, 1));                                 
//   Book( TH1F( "tau3pertau2 pT > 800" ," Verhaeltnis von Tau3/Tau2", 75, 0, 1));                                 

//   //SubJet1pT
//   Book( TH1F( "SubJet1pT"," P_{T} vom 1.ten Subjet", 75, 0, 1200));       
//   Book( TH1F( "SubJet1pT pT < 200"," P_{T} vom 1.ten Subjet", 75,0, 210));       
//   Book( TH1F( "SubJet1pT 200 < pT < 400", " P_{T} vom 1.ten Subjet", 75, 190, 410));       
//   Book( TH1F( "SubJet1pT 400 < pT < 600", " P_{T} vom 1.ten Subjet", 75, 390, 610));       
//   Book( TH1F( "SubJet1pT 600 < pT < 800", " P_{T} vom 1.ten Subjet", 75, 590, 810));       
//   Book( TH1F( "SubJet1pT pT > 800",       " P_{T} vom 1.ten Subjet", 75, 790, 1200));

//  //SubJet2pT
//   Book( TH1F( "SubJet2pT"," P_{T} vom 2.ten Subjet", 75, 0, 1000));       
//   Book( TH1F( "SubJet2pT pT < 200"," P_{T} vom 2.ten Subjet", 75,0, 210));       
//   Book( TH1F( "SubJet2pT 200 < pT < 400", " P_{T} vom 2.ten Subjet", 75, 190, 410));       
//   Book( TH1F( "SubJet2pT 400 < pT < 600", " P_{T} vom 2.ten Subjet", 75, 390, 610));       
//   Book( TH1F( "SubJet2pT 600 < pT < 800", " P_{T} vom 2.ten Subjet", 75, 590, 810));       
//   Book( TH1F( "SubJet2pT pT > 800",       " P_{T} vom 2.ten Subjet", 75, 790, 1000));

//   //SubJetperJet
//   Book( TH1F( "SubJetperJet-pT" ,"P_{T}-Verhaeltnis vom 1.ten Subjet zum Gesamtjet", 75, 0, 1));       
//   Book( TH1F( "SubJetperJet-pT pT < 200" ,"P_{T}-Verhaeltnis vom 1.ten Subjet zum Gesamtjet", 75, 0, 1));       
//   Book( TH1F( "SubJetperJet-pT 200 < pT < 400" ,"P_{T}-Verhaeltnis vom 1.ten Subjet zum Gesamtjet", 75, 0, 1));       
//   Book( TH1F( "SubJetperJet-pT 400 < pT < 600" ,"P_{T}-Verhaeltnis vom 1.ten Subjet zum Gesamtjet", 75, 0, 1));       
//   Book( TH1F( "SubJetperJet-pT 600 < pT < 800" ,"P_{T}-Verhaeltnis vom 1.ten Subjet zum Gesamtjet", 75, 0, 1));       
//   Book( TH1F( "SubJetperJet-pT pT > 800" ,"P_{T}-Verhaeltnis vom 1.ten Subjet zum Gesamtjet", 75, 0, 1));       

//   //MMin2
//   Book( TH1F( "MMin2" ,"", 75, 0, 300));
//   Book( TH1F( "MMin2 pT < 200" ,"", 75, 0, 300));
//   Book( TH1F( "MMin2 200 < pT < 400" ,"", 75, 0, 300));
//   Book( TH1F( "MMin2 400 < pT < 600" ,"", 75, 0, 300));
//   Book( TH1F( "MMin2 600 < pT < 800" ,"", 75, 0, 300));
//   Book( TH1F( "MMin2 pT > 800" ,"", 75, 0, 300));

// ////////////////////////////////////////////  Weitere Cuts       ///////////////////////////////////////////////////////////////////////////////////////////////////

//   Book( TH1F( "SubJet1-pT1" ,"pT von SubJets subjets[fatjets_comb.size()-1].at(0).pt()", 75, 0, 500));
//   Book( TH1F( "SubJet2-pT1" ,"pT von SubJets subjets[fatjets_comb.size()-1].at(1).pt()", 75, 0, 500));
//   Book( TH1F( "SubJet3-pT1" ,"pT von SubJets subjets[fatjets_comb.size()-1].at(2).pt()", 75, 0, 500));
//   Book( TH1F( "SubJet4-pT1" ,"pT von SubJets subjets[fatjets_comb.size()-1].at(3).pt()", 75, 0, 500));
//   Book( TH1F( "SubJet5-pT1" ,"pT von SubJets subjets[fatjets_comb.size()-1].at(4).pt()", 75, 0, 500));
//   Book( TH1F( "SubJet6-pT1" ,"pT von SubJets subjets[fatjets_comb.size()-1].at(5).pt()", 75, 0, 500));
//   Book( TH1F( "SubJet7-pT1" ,"pT von SubJets subjets[fatjets_comb.size()-1].at(6).pt()", 75, 0, 500));
//   Book( TH1F( "SubJet8-pT1" ,"pT von SubJets subjets[fatjets_comb.size()-1].at(7).pt()", 75, 0, 500));


//   // Book( TH1F( "sd_mass" ,"Softdrop-Masse", 75, 0, 500));
//   // Book( TH1F( "W0-Tagger" ,"W0-Tagger, 2 Cuts", 75, 0, 1000));

//   double PT_bins[] = {0,40,80,120,160,200,240,280,320,360,400,500,600,1000};
//   double roc_ptbins[] = {200,400,600,800,1000,10000};
//   int nsteps = 50;
//   double wmin = 0.0;
//   double wmax = 0.5;
//   double nsubmin = 0.0;
//   double nsubmax = 1.0;
//   double csvmin = 0.0;
//   double csvmax = 1.0;
  
//   tmva_tagger    = new TMVA_tagger();
//   tmva_tagger2   = new TMVA_tagger();
//   tmva_tagger300 = new TMVA_tagger();
//   tmva_tagger500 = new TMVA_tagger();
//   tmva_tagger700 = new TMVA_tagger();
//   tmva_taggerInf = new TMVA_tagger();
//   Showerdeconstruction_tagger = new Showerdeconstruction();
//   Showerdeconstruction_taggerV2 = new ShowerdeconstructionV2();
//   Softdrop = new SoftDrop();
//   jwj = new Jetswithoutjets();
//   ecf = new ECF();
//   varR = new VariableR();
//   IR_Saftey= new Infrared_Saftey();
// }

// void Eugen::SetIdVersion(TString s)
// {idVersion = s;}

// void Eugen::Fill()
// {
//   // fill the histograms
//   string algo = "hhtoptagger";
//   double akt_r = 0.8;
//   double mu(30.), theta(0.7), mw(0.), mtopLow(140.), mtopHigh(220.);
//   double min_r(0.1), max_r(1.5);
//   float minDeltaR = 10000;
//   int bestjetindex = -1;
//   int bestjetindex2 = -1;
//   int rho = 600;
//   int SubJetpTmin = 20;
    
//   int nsteps = 50;
//   double wmin = 0.0;
//   double wmax = 0.5;
//   double nsubmin = 0.0;
//   double nsubmax = 1.0;
//   double csvmin = 0.0;
//   double csvmax = 1.0;
  
//   double nsub_step = (nsubmax - nsubmin) / nsteps;
//   double w_step = (wmax - wmin) / nsteps;
//   double csv_step = (csvmax - csvmin) / nsteps;
//   double tstart = clock();
//   double time1 = 0;


//   EventCalc* calc = EventCalc::Instance();
//   BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
//   bool IsRealData = calc->IsRealData();
//   LuminosityHandler* lumih = calc->GetLumiHandler();
//   double weight = calc->GetWeight();
//   int run = calc->GetRunNum();



//   //EFFICIENCY

//   if(!IsRealData && (idVersion=="TTbarEff" || idVersion=="TTbarEff_1" || idVersion=="TTbarEff_gen" || idVersion=="TTbarEff_gen2" || idVersion.Contains("Zprime")))
//     {
//       std::vector<GenParticle>* genparticles = calc->GetGenParticles();
//       std::vector<fastjet::PseudoJet> genvector;

//       for(int tx = 0; tx < genparticles->size(); tx++)
// 	{
// 	  TLorentzVector particle;
// 	  particle.SetPtEtaPhiE(genparticles->at(tx).pt(), genparticles->at(tx).eta(), genparticles->at(tx).phi(), genparticles->at(tx).energy());
// 	  fastjet::PseudoJet gen_particle(particle.Px(), particle.Py(), particle.Pz(), particle.E());
// 	  if(genparticles->at(tx).status() == 1) genvector.push_back(gen_particle);
// 	}


//       TTbarGen2* Decay = calc->GetTTbarGen2();                                // top quarks finden 
//       std::vector<fastjet::PseudoJet> SortedSubJets;
//       std::vector<GenParticle> Had_Tops;
//       std::vector<GenParticle> decay_products;
//       bool isHadronic = false;


//       if (Decay->IsTopHadronicDecay())
//       	{
//       	  Had_Tops.push_back(Decay->Top());
//       	  decay_products.push_back(Decay->Wdecay1());
//       	  decay_products.push_back(Decay->Wdecay2());
//       	  decay_products.push_back(Decay->bTop());
//       	}

//       if (Decay->IsAntiTopHadronicDecay())
//       	{ 
//       	  Had_Tops.push_back(Decay->Antitop());
//       	  decay_products.push_back(Decay->WMinusdecay1());
//       	  decay_products.push_back(Decay->WMinusdecay2());
//       	  decay_products.push_back(Decay->bAntitop());
//       	}

//       if (Decay->IsTopHadronicDecay()) Had_Tops.push_back(Decay->Top());                      //Wieso nicht oben in if-Abfrage mit drin?
//       if (Decay->IsAntiTopHadronicDecay()) Had_Tops.push_back(Decay->Antitop());


//       TTbarGen2::E_DecayChannel decaymode = Decay->DecayChannel();                      // <Had_Tops vector aus top quarks
//       int oldbestjet  = -1;
//       int oldbestjet2 = -1;
                                         
//       for (unsigned int j = 2; j < Had_Tops.size(); j++)
//       	{
//       	  minDeltaR = 10000;
//       	  bestjetindex = -1;
       
//       	  fastjet::ClusterSequence clustersq;
//       	  fastjet::ClusterSequence clustersq2;
//       	  double subjetmass;
//       	  double mmin2;
//       	  double distance;
//       	  vector<fastjet::PseudoJet> varjets, fatjets, fatjets_backup, fatjets_comb2;

// 	  //Hists AllTops
//                                                                Hist("AllTops")->Fill(Had_Tops[j].pt(), weight);         
// 	  if(Had_Tops[j].pt() < 200)                           Hist("AllTops pT < 200")->Fill(Had_Tops[j].pt(), weight);         
// 	  if(Had_Tops[j].pt() > 200 && Had_Tops[j].pt() < 400) Hist("AllTops 200 < pT < 400")->Fill(Had_Tops[j].pt(), weight);                                                
// 	  if(Had_Tops[j].pt() > 400 && Had_Tops[j].pt() < 600) Hist("AllTops 400 < pT < 600")->Fill(Had_Tops[j].pt(), weight);                                                
// 	  if(Had_Tops[j].pt() > 600 && Had_Tops[j].pt() < 800) Hist("AllTops 600 < pT < 800")->Fill(Had_Tops[j].pt(), weight);                                                
// 	  if(Had_Tops[j].pt() > 800)                           Hist("AllTops pT > 800")->Fill(Had_Tops[j].pt(), weight);         


//       	  EventCalc* calc = EventCalc::Instance();
//       	  fastjet::JetDefinition *JetDef;
//       	  fastjet::JetDefinition jet_defCA2;
//       	  TopJet topjet;
//       	  std::vector<fastjet::PseudoJet> jetpart = genvector;
//       	  std::vector<fastjet::PseudoJet> inclusive_jetsCA;


//       	  double ptmin(10.);                                        //ptmin(10.) ist Anfangwert fuer Jets!!
	  

//       	  HHTopTagger pluginAKT(mu, theta, min_r, max_r, rho, mw, HHTopTagger::CALIKE, fatjets);                      // Aufruf Tagger
//       	  fastjet::JetDefinition jet_defCA(&pluginAKT);
//       	  jet_defCA2 = jet_defCA;
   
//       	  fastjet::ClusterSequence clust_seqCA(jetpart, jet_defCA2);
//       	  inclusive_jetsCA = clust_seqCA.inclusive_jets(ptmin);
    
//       	  SortedSubJets = sorted_by_pt(inclusive_jetsCA);
//       	  std::vector<fastjet::PseudoJet> constituents;
//       	  std::vector<double> deltaR, deltapT, mj_wmass;

//       	  fatjets = pluginAKT.get_fatjets();
//       	  deltaR = pluginAKT.get_deltaR();
//       	  deltapT = pluginAKT.get_deltapT();
//       	  mj_wmass = pluginAKT.get_mass();

//       	  fatjets_comb2 = pluginAKT.get_fatjets_comb();
//       	  fastjet::ClusterSequence cs2;
//       	  fatjets_backup = fatjets;


//       	  bool event1 = true;
//       	  for(int o = 0; o < fatjets.size(); o++) if(fatjets[o].user_index() != -1) event1 = false;
	
//       	  std::vector<fastjet::PseudoJet> fatjets_comb, garbage;
//       	  std::vector<fastjet::PseudoJet> subjets[fatjets.size()];
//       	  std::vector<int> jetindex[fatjets.size()];
//       	  int index = 0;


// 	  for(int o = 0; o < fatjets.size(); o++)
// 	    {
// 	      for(int L = 0; L < clust_seqCA.jets().size(); L++)
// 	  	{ 
// 	  	  if(clust_seqCA.jets()[L].pt() == fatjets[o].pt()) jetindex[o].push_back(L);
// 	  	}
// 	      jetindex[o].push_back(fatjets[o].user_index());
// 	    }

// 	  std::vector<fastjet::PseudoJet> jet_radiation, jet_beam;

// 	  for(int o = 0; o < fatjets.size(); o++)                                                                         //  Hier werden die Jets gefunden.
// 	    {
// 	      //Hists AllJets
// 	      Hist("AllJets")->Fill(fatjets[o].pt(), weight);         
// 	      if(fatjets[o].pt() < 200)                                   Hist("AllJets pT < 200")->Fill(fatjets[o].pt(), weight);         
// 	      if(fatjets[o].pt() > 200 && fatjets[o].pt() < 400)          Hist("AllJets 200 < pT < 400")->Fill(fatjets[o].pt(), weight);                                                
// 	      if(fatjets[o].pt() > 400 && fatjets[o].pt() < 600)          Hist("AllJets 400 < pT < 600")->Fill(fatjets[o].pt(), weight);                                                
// 	      if(fatjets[o].pt() > 600 && fatjets[o].pt() < 800)          Hist("AllJets 600 < pT < 800")->Fill(fatjets[o].pt(), weight);                                                
// 	      if(fatjets[o].pt() > 800)                                   Hist("AllJets pT > 800")->Fill(fatjets[o].pt(), weight);


// 	      if(fatjets[o].user_index() != -99 && fatjets[o].pt() > ptmin)
// 	  	{
// 	  	  index++;
// 	  	  fastjet::PseudoJet testjet = fatjets[o];
// 	  	  subjets[index-1].push_back(clust_seqCA.jets()[jetindex[o].at(0)]);

// 	  	  for(int t = 0; t < fatjets.size(); t++) 
// 	  	    {
// 	  	      if(fatjets[o].user_index() == fatjets[t].user_index() && t != o && fatjets[o].user_index() != -1 && fatjets[o].pt() > ptmin)  //ptmin = JETptmin
// 	  		{
// 	  		  testjet.operator+=(fatjets[t]);
// 	  		  fatjets[t].set_user_index(-99);
// 	  		  subjets[index-1].push_back(clust_seqCA.jets()[jetindex[t].at(0)]);                              
// 			}   
// 	  	    }
	       
// 	  	  for(int k = 0; k < fatjets.size(); k++)
// 	  	    {
// 	  	      if(fatjets[k].user_index() / 100. == fatjets[o].user_index())
// 	  		{
// 	  		  fatjets_comb.push_back(fatjets[k]);                 
// 	  		  fatjets[o].set_user_index(-99);                                                                  
// 	  		  fatjets_comb[fatjets_comb.size()-1].set_user_index(index);
// 	  		  subjets[fatjets_comb.size()-1] = sorted_by_pt(subjets[fatjets_comb.size()-1]);
// 	  		}
// 	  	      else 
// 	  		{
// 	  		  if(fatjets[o].user_index() == -1) jet_beam.push_back(fatjets[o]);
// 	  		  if(fatjets[o].user_index() == -2) jet_radiation.push_back(fatjets[o]);
// 	  		}
// 	  	    }
// 	  	}
// 	    }


// 	  //Eugen Anfang



// 	      std::vector<fastjet::PseudoJet> TempJets1;
// 	      std::vector<fastjet::PseudoJet> TempJets2;
// 	      for(int o = 0; o < fatjets_comb.size(); o++)	    
// 		{ 
		  

// 		  for(int i = 0; i < subjets[fatjets_comb.size()-1].size(); i++)
// 		    {
// 		      if(subjets[fatjets_comb.size()-1].at(i).pt() < SubJetpTmin)
// 			{
// 			  cout<<"fatjets_comb Px vorher = "<<fatjets_comb[o].four_mom()[0]<<endl;
// 			  cout<<"subjets Px vorher = "<<subjets[fatjets_comb.size()-1].at(i).four_mom()[0]<<endl;
// 			  cout<<" "<<endl;
// 			  cout<<"fatjets_comb Py vorher = "<<fatjets_comb[o].four_mom()[1]<<endl;
// 			  cout<<"subjets Py vorher = "<<subjets[fatjets_comb.size()-1].at(i).four_mom()[1]<<endl;
// 			  cout<<" "<<endl;
// 			  cout<<"fatjets_comb Pz vorher = "<<fatjets_comb[o].four_mom()[2]<<endl;
// 			  cout<<"subjets Pz vorher = "<<subjets[fatjets_comb.size()-1].at(i).four_mom()[2]<<endl;
// 			  cout<<" "<<endl;
// 			  cout<<"fatjets_comb Energie vorher = "<<fatjets_comb[o].four_mom()[3]<<endl;
// 			  cout<<"subjets Energie vorher = "<<subjets[fatjets_comb.size()-1].at(i).four_mom()[3]<<endl;
// 			  cout<<" "<<endl;
// 			  cout<<" "<<endl;

// 			  //  subjets[fatjets_comb.size()-1].at(0).four_mom().operator-=(fatjets_comb[o].four_mom());
// 		          fatjets_comb[o].operator-=(subjets[fatjets_comb.size()-1].at(i));


// 			  cout<<"fatjets_comb Px nachher = "<<fatjets_comb[o].four_mom()[0]<<endl;
// 			  cout<<"subjets Px nachher = "<<subjets[fatjets_comb.size()-1].at(i).four_mom()[0]<<endl;
// 			  cout<<" "<<endl;
// 			  cout<<"fatjets_comb Py nachher = "<<fatjets_comb[o].four_mom()[1]<<endl;
// 			  cout<<"subjets Py nachher = "<<subjets[fatjets_comb.size()-1].at(i).four_mom()[1]<<endl;
// 			  cout<<" "<<endl;
// 			  cout<<"fatjets_comb Pz nachher = "<<fatjets_comb[o].four_mom()[2]<<endl;
// 			  cout<<"subjets Pz nachher = "<<subjets[fatjets_comb.size()-1].at(i).four_mom()[2]<<endl;
// 			  cout<<" "<<endl;
// 			  cout<<"fatjets_comb Energie nachher = "<<fatjets_comb[o].four_mom()[3]<<endl;
// 			  cout<<"subjets Energie nachher = "<<subjets[fatjets_comb.size()-1].at(i).four_mom()[3]<<endl;
// 			  cout<<" "<<endl;
// 			  cout<<" "<<endl;


// 			}
// 		      // Hist("SubJet1-pT1")->Fill(subjets[fatjets_comb.size()-1].at(0).pt(), weight);
// 		    }


// 		  /*
// 		  if(subjets[fatjets_comb.size()-1].size() == 1)
// 		    {
// 		      if(subjets[fatjets_comb.size()-1].at(0).pt() < SubJetpTmin)
// 			{
// 			  cout<<"fatjets_comb Energie vorher = "<<fatjets_comb[o].four_mom()[3]<<endl;
// 			  cout<<"subjets Energie vorher = "<<subjets[fatjets_comb.size()-1].at(0).four_mom()[3]<<endl;
// 			  cout<<" "<<endl;
// 			  cout<<" "<<endl;
// 			  cout<<" "<<endl;

// 			  //  subjets[fatjets_comb.size()-1].at(0).four_mom().operator-=(fatjets_comb[o].four_mom());
// 		          fatjets_comb[o].four_mom().operator-=(subjets[fatjets_comb.size()-1].at(0).four_mom());
// 			  cout<<"fatjets_comb Energie nachher = "<<fatjets_comb[o].four_mom()[3]<<endl;
// 			  cout<<"subjets Energie nachher ="<<subjets[fatjets_comb.size()-1].at(0).four_mom()[3]<<endl;
			  
// 			}
// 		      Hist("SubJet1-pT1")->Fill(subjets[fatjets_comb.size()-1].at(0).pt(), weight);
// 		    }


// 		*/
		




// 		}
// 	      /*               
// 	      if(subjets[fatjets_comb.size()-1].size() == 1)
// 		{
// 		  if(subjets[fatjets_comb.size()-1].at(0).pt() > SubJetpTmin)
// 		    {
// 		      TempJets1.push_back(subjets[fatjets_comb.size()-1].at(0));
// 		    }
// 		}

// 	      if(subjets[fatjets_comb.size()-1].size() == 2)
// 		{
// 		  if(subjets[fatjets_comb.size()-1].at(1).pt() > SubJetpTmin)
// 		    {
// 		      TempJets1.push_back(subjets[fatjets_comb.size()-1].at(1));
// 		    }
// 		}

// 	      if(subjets[fatjets_comb.size()-1].size() == 3)
// 		{
// 		  if(subjets[fatjets_comb.size()-1].at(2).pt() > SubJetpTmin)
// 		    {
// 		      TempJets1.push_back(subjets[fatjets_comb.size()-1].at(2));
// 		    }
// 		}

// 	      if(subjets[fatjets_comb.size()-1].size() == 4)
// 		{
// 		  if(subjets[fatjets_comb.size()-1].at(3).pt() > SubJetpTmin)
// 		    {
// 		      TempJets1.push_back(subjets[fatjets_comb.size()-1].at(3));
// 		    }
// 		}

// 	      if(subjets[fatjets_comb.size()-1].size() == 5)
// 		{
// 		  if(subjets[fatjets_comb.size()-1].at(4).pt() > SubJetpTmin)
// 		    {
// 		      TempJets1.push_back(subjets[fatjets_comb.size()-1].at(4));
// 		    }
// 		}

// 	      if(subjets[fatjets_comb.size()-1].size() == 6)
// 		{
// 		  if(subjets[fatjets_comb.size()-1].at(5).pt() > SubJetpTmin)
// 		    {
// 		      TempJets1.push_back(subjets[fatjets_comb.size()-1].at(5));
// 		    }
// 		}

// 	      if(subjets[fatjets_comb.size()-1].size() == 7)
// 		{
// 		  if(subjets[fatjets_comb.size()-1].at(6).pt() > SubJetpTmin)
// 		    {
// 		      TempJets1.push_back(subjets[fatjets_comb.size()-1].at(6));
// 		    }
// 		}

// 	      if(subjets[fatjets_comb.size()-1].size() == 8)
// 		{
// 		  if(subjets[fatjets_comb.size()-1].at(7).pt() > SubJetpTmin)
// 		    {
// 		      TempJets1.push_back(subjets[fatjets_comb.size()-1].at(7));
// 		    }
// 		}

// 	      if(subjets[fatjets_comb.size()-1].size() == 9)
// 		{
// 		  if(subjets[fatjets_comb.size()-1].at(8).pt() > SubJetpTmin)
// 		    {
// 		      TempJets1.push_back(subjets[fatjets_comb.size()-1].at(8));
// 		    }
// 		}
// */

// 	      //     fatjets_comb[o].operator-=(TempJets1[o]);
	      
      
// 	      //    fatjets_comb[o].operator-=(TempJets1[o]);


   	 
// 	      // Testhistogramme
// 	      /*
// 	      if(subjets[fatjets_comb.size()-1].size() == 1)
// 		{
// 		  Hist("SubJet1-pT1")->Fill(subjets[fatjets_comb.size()-1].at(0).pt(), weight);
// 		}
	      
	      
// 	      if(subjets[fatjets_comb.size()-1].size() == 2)
// 		{
// 		  Hist("SubJet2-pT1")->Fill(subjets[fatjets_comb.size()-1].at(1).pt(), weight);
// 		}

// 	      if(subjets[fatjets_comb.size()-1].size() == 3)
// 		{
// 		  Hist("SubJet3-pT1")->Fill(subjets[fatjets_comb.size()-1].at(2).pt(), weight);
// 		}

// 	      if(subjets[fatjets_comb.size()-1].size() == 4)
// 		{
// 		  Hist("SubJet4-pT1")->Fill(subjets[fatjets_comb.size()-1].at(3).pt(), weight);
// 		}
// 	      if(subjets[fatjets_comb.size()-1].size() == 5)
// 		{
// 		  Hist("SubJet5-pT1")->Fill(subjets[fatjets_comb.size()-1].at(4).pt(), weight);
// 		}
// 	      if(subjets[fatjets_comb.size()-1].size() == 6)
// 		{
// 		  Hist("SubJet6-pT1")->Fill(subjets[fatjets_comb.size()-1].at(5).pt(), weight);
// 		}
// 	      if(subjets[fatjets_comb.size()-1].size() == 7)
// 		{
// 		  Hist("SubJet7-pT1")->Fill(subjets[fatjets_comb.size()-1].at(6).pt(), weight);

// 		}
// 	      if(subjets[fatjets_comb.size()-1].size() == 8)
// 		{
// 		  Hist("SubJet8-pT1")->Fill(subjets[fatjets_comb.size()-1].at(7).pt(), weight);
// 		}
// 	      */

	    


// 	      //Eugen Ende
                                                   
// 	  for(int o = 0; o < fatjets_comb.size(); o++)                            //**************hier werden die jets gefunden. fatjets_comb, gefundenen topjets;  subjets[fatjets_comb.size()-1] gibt subjets zurueck
// 	    {	     
// 	      for(int t = o; t < fatjets_comb.size(); t++)
// 	  	{
// 		                                                              Hist("#SubJets")->Fill(subjets[fatjets_comb[t].user_index() - 1].size(), weight);         
// 		  if(fatjets[o].pt() < 200)                                   Hist("#SubJets pT < 200")->Fill(subjets[fatjets_comb[t].user_index() - 1].size(), weight);         
// 		  if(fatjets[o].pt() > 200 && fatjets[o].pt() < 400)          Hist("#SubJets 200 < pT < 400")->Fill(subjets[fatjets_comb[t].user_index() - 1].size(), weight);                                                
// 		  if(fatjets[o].pt() > 400 && fatjets[o].pt() < 600)          Hist("#SubJets 400 < pT < 600")->Fill(subjets[fatjets_comb[t].user_index() - 1].size(), weight);                                                
// 		  if(fatjets[o].pt() > 600 && fatjets[o].pt() < 800)          Hist("#SubJets 600 < pT < 800")->Fill(subjets[fatjets_comb[t].user_index() - 1].size(), weight);                                                
// 		  if(fatjets[o].pt() > 800)                                   Hist("#SubJets pT > 800")->Fill(subjets[fatjets_comb[t].user_index() - 1].size(), weight);
// 	  	}
// 	    }

// 	  std::vector<fastjet::PseudoJet> fatjet_constituents[fatjets_comb.size()];
// 	  for(int o = 0; o < fatjets_comb.size(); o++)
// 	    {
// 	      for(int p = 0; p < subjets[fatjets_comb[o].user_index()-1].size(); p++)
// 	  	{
// 	  	  for(int k = 0; k < subjets[fatjets_comb[o].user_index()-1][p].constituents().size(); k++)
// 	  	    {
// 	  	      fatjet_constituents[o].push_back(subjets[fatjets_comb[o].user_index()-1][p].constituents().at(k));  
// 	  	    }             
// 	  	}
// 	    }
	  
// 	  std::vector<fastjet::PseudoJet> SortedJets;
// 	  SortedJets =  fatjets_comb; 
	 
// 	  for(int i = 0; i < SortedJets.size(); i++)
// 	    {    
// 	      double mjet = SortedJets[i].m();
// 	      double oldR = 0;
// 	      std::vector<fastjet::PseudoJet> pfcands = SortedJets[i].constituents();
	     
// 	      for(int j = 0; j < pfcands.size(); j++)
// 	  	{
// 	  	  double R;
// 	  	  R = SortedJets[i].delta_R(pfcands[j]);

// 	  	  if(R > oldR)
// 	  	    {
// 	  	      oldR = R;
// 	  	    }
// 	  	}
//     	      SortedJets[i].set_user_index(int(oldR*10));
// 	    }

// 	  varjets = SortedJets;
  	
// 	  double minDeltaR2 = 10000;
// 	  int bestjetindex2 = -1;
        
// 	  for(unsigned int i = 0; i < varjets.size(); ++i)
// 	    {
// 	      double DeltaR2 = sqrt(pow(Had_Tops[j].phi() - varjets[i].phi_std(), 2) + pow(Had_Tops[j].eta() - varjets[i].pseudorapidity(), 2));
		
// 	      if(DeltaR2 < minDeltaR2)
// 	  	{
// 	  	  minDeltaR2 = DeltaR2;
// 	  	  bestjetindex2 = i;
// 	  	}
// 	    }
	  
// 	  if(bestjetindex2 > -1)  if(minDeltaR2 > varjets[bestjetindex2].user_index()) bestjetindex2 =- 1;     //  protect against large deltaR
// 	  if(bestjetindex2 > -1)  if(varjets[bestjetindex2].user_index() / 10. == 0)   bestjetindex2 =- 1;      // varjets[bestjetindex2].user_index() / 10. == 0 geht nur fuer varjets[bestjetindex2].user_index() = 0 ?

// 	  if(bestjetindex2 > -1)
// 	    {
// 	      double mmin2 = 0;
// 	      double wmass_rec = 0;    
// 	      std::vector<fastjet::PseudoJet> SortedSubJets2 = sorted_by_pt(subjets[fatjets_comb[bestjetindex2].user_index()-1]);

// 	      if(SortedSubJets2.size() > 2)                                                //Hier wird das W rekonstruiert
// 	      	{
// 	      	  double m01 = 0;
// 	      	  double m02 = 0;
// 	       	  double m03 = 0;
// 	      	  double m12 = 0; 
// 	      	  double m13 = 0;
// 	      	  double m23 = 0;

// 	      	  m01 = (SortedSubJets2[0] + SortedSubJets2[1]).m();
// 	      	  m02 = (SortedSubJets2[0] + SortedSubJets2[2]).m();
// 	      	  m12 = (SortedSubJets2[1] + SortedSubJets2[2]).m();

// 	      	  if(SortedSubJets2.size() > 3)
// 	      	    {
// 	      	      m03 = (SortedSubJets2[0] + SortedSubJets2[3]).m();   
// 	      	      m13 = (SortedSubJets2[1] + SortedSubJets2[3]).m();
// 	      	      m23 = (SortedSubJets2[2] + SortedSubJets2[3]).m();


// 	      	      double deltaW, deltaW1, deltaW2, deltaW3, deltaW4, deltaW5;

// 	      	      deltaW  = abs(80.4 - m01);
// 	      	      deltaW1 = abs(80.4 - m02);
// 	      	      deltaW2 = abs(80.4 - m12);
// 	      	      deltaW3 = abs(80.4 - m03);
// 	      	      deltaW4 = abs(80.4 - m13);
// 	      	      deltaW5 = abs(80.4 - m23);

// 	      	      if(deltaW  < deltaW1 && deltaW  < deltaW2 && deltaW  < deltaW3 && deltaW  < deltaW4 && deltaW  < deltaW5)   wmass_rec = m01;
// 	      	      if(deltaW1 < deltaW  && deltaW1 < deltaW2 && deltaW1 < deltaW3 && deltaW1 < deltaW4 && deltaW1 < deltaW5)   wmass_rec = m02; 
// 	      	      if(deltaW2 < deltaW  && deltaW2 < deltaW1 && deltaW2 < deltaW3 && deltaW2 < deltaW4 && deltaW2 < deltaW5)   wmass_rec = m12;
// 	      	      if(deltaW3 < deltaW  && deltaW3 < deltaW1 && deltaW3 < deltaW2 && deltaW3 < deltaW4 && deltaW3 < deltaW5)   wmass_rec = m03;
// 	      	      if(deltaW4 < deltaW  && deltaW4 < deltaW1 && deltaW4 < deltaW2 && deltaW4 < deltaW3 && deltaW4 < deltaW5)   wmass_rec = m13;
// 	      	      if(deltaW5 < deltaW  && deltaW5 < deltaW1 && deltaW5 < deltaW2 && deltaW5 < deltaW4 && deltaW5 < deltaW3)   wmass_rec = m23; 
// 	      	    }

// 	      	  else
// 	      	    {
// 	      	      double deltaW, deltaW1, deltaW2;
// 	      	      deltaW  = abs(80.4 - m01);
// 	      	      deltaW1 = abs(80.4 - m02);
// 	      	      deltaW2 = abs(80.4 - m12);

// 	      	      if(deltaW  < deltaW1 && deltaW  < deltaW2) wmass_rec = m01;
// 	      	      if(deltaW1 < deltaW  && deltaW1 < deltaW2) wmass_rec = m02;
// 	      	      if(deltaW2 < deltaW  && deltaW2 < deltaW1) wmass_rec = m12;
// 	      	    }
		
// 	      	  mmin2 = std::min(m01, std::min(m02, m12));


		  
// 		                                                          Hist("MMin2")->Fill(mmin2, weight); 
// 		  if(Had_Tops[j].pt() < 200)                              Hist("MMin2 pT < 200")->Fill(mmin2, weight); 
// 		  if(Had_Tops[j].pt() > 200 && Had_Tops[j].pt() < 400)    Hist("MMin2 200 < pT < 400")->Fill(mmin2, weight); 
// 		  if(Had_Tops[j].pt() > 400 && Had_Tops[j].pt() < 600)    Hist("MMin2 400 < pT < 600")->Fill(mmin2, weight); 
// 		  if(Had_Tops[j].pt() > 600 && Had_Tops[j].pt() < 800)    Hist("MMin2 600 < pT < 800")->Fill(mmin2, weight); 
// 		  if(Had_Tops[j].pt() > 800)                   	      	  Hist("MMin2 pT > 800")->Fill(mmin2, weight);           
		                                                                        
// 	      	}
	  
// 	         if(SortedSubJets2.size() > 2) 
// 		{
		  
// 		                                                          Hist("TopTaggedTops")->Fill(Had_Tops[j].pt(), weight); 
// 		  if(Had_Tops[j].pt() < 200)                              Hist("TopTaggedTops pT < 200")->Fill(Had_Tops[j].pt(), weight); 
// 		  if(Had_Tops[j].pt() > 200 && Had_Tops[j].pt() < 400)    Hist("TopTaggedTops 200 < pT < 400")->Fill(Had_Tops[j].pt(), weight); 
// 		  if(Had_Tops[j].pt() > 400 && Had_Tops[j].pt() < 600)    Hist("TopTaggedTops 400 < pT < 600")->Fill(Had_Tops[j].pt(), weight); 
// 		  if(Had_Tops[j].pt() > 600 && Had_Tops[j].pt() < 800)    Hist("TopTaggedTops 600 < pT < 800")->Fill(Had_Tops[j].pt(), weight); 
// 		  if(Had_Tops[j].pt() > 800)                              Hist("TopTaggedTops pT > 800")->Fill(Had_Tops[j].pt(), weight); 
  

// 		                                                          Hist("masstop")->Fill(SortedJets[bestjetindex2].m(), weight); 
// 		  if(Had_Tops[j].pt() < 200)                              Hist("masstop pT < 200")->Fill(SortedJets[bestjetindex2].m(), weight); 
// 		  if(Had_Tops[j].pt() > 200 && Had_Tops[j].pt() < 400)    Hist("masstop 200 < pT < 400")->Fill(SortedJets[bestjetindex2].m(), weight); 
// 		  if(Had_Tops[j].pt() > 400 && Had_Tops[j].pt() < 600)    Hist("masstop 400 < pT < 600")->Fill(SortedJets[bestjetindex2].m(), weight); 
// 		  if(Had_Tops[j].pt() > 600 && Had_Tops[j].pt() < 800)    Hist("masstop 600 < pT < 800")->Fill(SortedJets[bestjetindex2].m(), weight); 
// 		  if(Had_Tops[j].pt() > 800)                              Hist("masstop pT > 800")->Fill(SortedJets[bestjetindex2].m(), weight); 
		  

// 		                                                          Hist("SubJet1pT")->Fill(SortedSubJets2.at(0).pt(), weight); 
// 		  if(Had_Tops[j].pt() < 200)                              Hist("SubJet1pT pT < 200")->Fill(SortedSubJets2.at(0).pt(), weight); 
// 		  if(Had_Tops[j].pt() > 200 && Had_Tops[j].pt() < 400)    Hist("SubJet1pT 200 < pT < 400")->Fill(SortedSubJets2.at(0).pt(), weight); 
// 		  if(Had_Tops[j].pt() > 400 && Had_Tops[j].pt() < 600)    Hist("SubJet1pT 400 < pT < 600")->Fill(SortedSubJets2.at(0).pt(), weight); 
// 		  if(Had_Tops[j].pt() > 600 && Had_Tops[j].pt() < 800)    Hist("SubJet1pT 600 < pT < 800")->Fill(SortedSubJets2.at(0).pt(), weight);
// 		  if(Had_Tops[j].pt() > 800)                              Hist("SubJet1pT pT > 800")->Fill(SortedSubJets2.at(0).pt(), weight);
                                                     
// 		                                                          Hist("SubJet2pT")->Fill(SortedSubJets2.at(1).pt(), weight); 
// 		  if(Had_Tops[j].pt() < 200)                              Hist("SubJet2pT pT < 200")->Fill(SortedSubJets2.at(1).pt(), weight); 
// 		  if(Had_Tops[j].pt() > 200 && Had_Tops[j].pt() < 400)    Hist("SubJet2pT 200 < pT < 400")->Fill(SortedSubJets2.at(1).pt(), weight); 
// 		  if(Had_Tops[j].pt() > 400 && Had_Tops[j].pt() < 600)    Hist("SubJet2pT 400 < pT < 600")->Fill(SortedSubJets2.at(1).pt(), weight); 
// 		  if(Had_Tops[j].pt() > 600 && Had_Tops[j].pt() < 800)    Hist("SubJet2pT 600 < pT < 800")->Fill(SortedSubJets2.at(1).pt(), weight);
// 		  if(Had_Tops[j].pt() > 800)                              Hist("SubJet2pT pT > 800")->Fill(SortedSubJets2.at(1).pt(), weight);
			  
                                                
// 		                                                          Hist("SubJetperJet-pT")->Fill(SortedSubJets2.at(0).pt() / SortedJets[bestjetindex2].pt(), weight); 
// 		  if(Had_Tops[j].pt() < 200)                              Hist("SubJetperJet-pT pT < 200")->Fill(SortedSubJets2.at(0).pt() / SortedJets[bestjetindex2].pt(), weight); 
// 		  if(Had_Tops[j].pt() > 200 && Had_Tops[j].pt() < 400)    Hist("SubJetperJet-pT 200 < pT < 400")->Fill(SortedSubJets2.at(0).pt() / SortedJets[bestjetindex2].pt(), weight); 
// 		  if(Had_Tops[j].pt() > 400 && Had_Tops[j].pt() < 600)    Hist("SubJetperJet-pT 400 < pT < 600")->Fill(SortedSubJets2.at(0).pt() / SortedJets[bestjetindex2].pt(), weight); 
// 		  if(Had_Tops[j].pt() > 600 && Had_Tops[j].pt() < 800)    Hist("SubJetperJet-pT 600 < pT < 800")->Fill(SortedSubJets2.at(0).pt() / SortedJets[bestjetindex2].pt(), weight);
// 		  if(Had_Tops[j].pt() > 800)                              Hist("SubJetperJet-pT pT > 800")->Fill(SortedSubJets2.at(0).pt() / SortedJets[bestjetindex2].pt(), weight);

//  		}
	      
// 	      if(SortedJets[bestjetindex2].m() > mtopLow && SortedJets[bestjetindex2].m() < mtopHigh)   
// 	  	{
// 		                                                          Hist("MassCutOnly")->Fill(Had_Tops[j].pt(), weight); 
// 		  if(Had_Tops[j].pt() < 200)                              Hist("MassCutOnly pT < 200")->Fill(Had_Tops[j].pt(), weight); 
// 		  if(Had_Tops[j].pt() > 200 && Had_Tops[j].pt() < 400)    Hist("MassCutOnly 200 < pT < 400")->Fill(Had_Tops[j].pt(), weight); 
// 		  if(Had_Tops[j].pt() > 400 && Had_Tops[j].pt() < 600)    Hist("MassCutOnly 400 < pT < 600")->Fill(Had_Tops[j].pt(), weight); 
// 		  if(Had_Tops[j].pt() > 600 && Had_Tops[j].pt() < 800)    Hist("MassCutOnly 600 < pT < 800")->Fill(Had_Tops[j].pt(), weight);
// 		  if(Had_Tops[j].pt() > 800)                              Hist("MassCutOnly pT > 800")->Fill(Had_Tops[j].pt(), weight);

// 	  	  if(SortedSubJets2.size() > 2) 
// 	  	    { 
// 		                                                              Hist("MassAndSubJetSizeCut")->Fill(Had_Tops[j].pt(), weight); 
// 		      if(Had_Tops[j].pt() < 200)                              Hist("MassAndSubJetSizeCut pT < 200")->Fill(Had_Tops[j].pt(), weight); 
// 		      if(Had_Tops[j].pt() > 200 && Had_Tops[j].pt() < 400)    Hist("MassAndSubJetSizeCut 200 < pT < 400")->Fill(Had_Tops[j].pt(), weight); 
// 		      if(Had_Tops[j].pt() > 400 && Had_Tops[j].pt() < 600)    Hist("MassAndSubJetSizeCut 400 < pT < 600")->Fill(Had_Tops[j].pt(), weight); 
// 		      if(Had_Tops[j].pt() > 600 && Had_Tops[j].pt() < 800)    Hist("MassAndSubJetSizeCut 600 < pT < 800")->Fill(Had_Tops[j].pt(), weight);
// 		      if(Had_Tops[j].pt() > 800)                              Hist("MassAndSubJetSizeCut pT > 800")->Fill(Had_Tops[j].pt(), weight);

		      
// 	  	      if(SortedSubJets2.at(0).pt() > 30 && SortedSubJets2.at(1).pt() > 30 && SortedSubJets2.at(0).pt() / SortedJets[bestjetindex2].pt() < 0.8 && mmin2 > 50)
// 			{
// 		                                                                                                                      Hist("LastTagger")->Fill(Had_Tops[j].pt(), weight); 
// 									      if(Had_Tops[j].pt() < 200)                              Hist("LastTagger pT < 200")->Fill(Had_Tops[j].pt(), weight); 
// 									      if(Had_Tops[j].pt() > 200 && Had_Tops[j].pt() < 400)    Hist("LastTagger 200 < pT < 400")->Fill(Had_Tops[j].pt(), weight); 
// 									      if(Had_Tops[j].pt() > 400 && Had_Tops[j].pt() < 600)    Hist("LastTagger 400 < pT < 600")->Fill(Had_Tops[j].pt(), weight); 
// 									      if(Had_Tops[j].pt() > 600 && Had_Tops[j].pt() < 800)    Hist("LastTagger 600 < pT < 800")->Fill(Had_Tops[j].pt(), weight);
// 									      if(Had_Tops[j].pt() > 800)                              Hist("LastTagger pT > 800")->Fill(Had_Tops[j].pt(), weight);

// 			}
// 		    }
// 	  	}
// 	      fastjet::PseudoJet jet = varjets.at(bestjetindex2);
// 	      fastjet::PseudoJet probejet = varjets.at(bestjetindex2);

// 	      bool collimated   = false;
// 	      bool collimated01 = false;	
// 	      bool collimated02 = false;
// 	      bool collimated03 = false;
// 	      bool collimated04 = false;
// 	      bool collimated05 = false;
// 	      bool collimated06 = false;
// 	      bool collimated07 = false;

// 	      double microjet_cone = varjets[bestjetindex2].user_index() / 10.;

// 	      if(Decay->IsTopHadronicDecay())
// 	  	{
// 	  	  double distanceW1, distanceW2, distanceb;
		
// 	  	  if(probejet.phi() > PI) distanceW1 = sqrt(pow(Decay->Wdecay1().phi() - (probejet.phi() - 2*PI), 2) + pow(Decay->Wdecay1().eta() - probejet.eta(), 2));
// 	  	  else distanceW1 = sqrt(pow(Decay->Wdecay1().phi() - probejet.phi(), 2) + pow(Decay->Wdecay1().eta() - probejet.eta(), 2));
		
// 	  	  if(probejet.phi() > PI) distanceW2 = sqrt(pow(Decay->Wdecay2().phi() - (probejet.phi() - 2*PI), 2) + pow(Decay->Wdecay2().eta() - probejet.eta(), 2));
// 	  	  else distanceW2 = sqrt(pow(Decay->Wdecay2().phi() - probejet.phi(), 2) + pow(Decay->Wdecay2().eta() - probejet.eta(), 2));

// 	  	  if(probejet.phi() > PI) distanceb = sqrt(pow(Decay->bTop().phi() - (probejet.phi() - 2*PI), 2) + pow(Decay->bTop().eta()-probejet.eta(), 2));
// 	  	  else distanceb = sqrt(pow(Decay->bTop().phi() - probejet.phi(), 2) + pow(Decay->bTop().eta() - probejet.eta(), 2));

// 	  	  if(distanceW1 < microjet_cone && distanceW2 < microjet_cone && distanceb < microjet_cone) collimated = true; 
// 	  	  if(distanceW1 < 0.9 * microjet_cone && distanceW2 < 0.9 * microjet_cone && distanceb < 0.9 * microjet_cone) collimated01 = true;
// 	  	  if(distanceW1 < 0.8 * microjet_cone && distanceW2 < 0.8 * microjet_cone && distanceb < 0.8 * microjet_cone) collimated02 = true;
// 	  	  if(distanceW1 < 0.7 * microjet_cone && distanceW2 < 0.7 * microjet_cone && distanceb < 0.7 * microjet_cone) collimated03 = true;
// 	  	  if(distanceW1 < 0.6 * microjet_cone && distanceW2 < 0.6 * microjet_cone && distanceb < 0.6 * microjet_cone) collimated04 = true;
// 	  	  if(distanceW1 < 0.5 * microjet_cone && distanceW2 < 0.5 * microjet_cone && distanceb < 0.5 * microjet_cone) collimated05 = true;
// 	  	  if(distanceW1 < 0.4 * microjet_cone && distanceW2 < 0.4 * microjet_cone && distanceb < 0.4 * microjet_cone) collimated06 = true;
// 	  	  if(distanceW1 < 0.3 * microjet_cone && distanceW2 < 0.3 * microjet_cone && distanceb < 0.3 * microjet_cone) collimated07 = true;
// 	  	}

// 	      if(Decay->IsAntiTopHadronicDecay())
// 	  	{
// 	  	  double distanceW1, distanceW2, distanceb;

// 	  	  if(probejet.phi() > PI) distanceW1 = sqrt(pow(Decay->WMinusdecay1().phi() - (probejet.phi() - 2*PI), 2) + pow(Decay->WMinusdecay1().eta() - probejet.eta(), 2));
// 	  	  else distanceW1 = sqrt(pow(Decay->WMinusdecay1().phi() - probejet.phi(), 2) + pow(Decay->WMinusdecay1().eta() - probejet.eta(), 2));

// 	  	  if(probejet.phi() > PI) distanceW2 = sqrt(pow(Decay->WMinusdecay2().phi() - (probejet.phi() - 2*PI), 2) + pow(Decay->WMinusdecay2().eta() - probejet.eta(), 2));
// 	  	  else distanceW2 = sqrt(pow(Decay->WMinusdecay2().phi() - probejet.phi(), 2) + pow(Decay->WMinusdecay2().eta() - probejet.eta(), 2));

// 	  	  if(probejet.phi() > PI) distanceb = sqrt(pow(Decay->bAntitop().phi() - (probejet.phi() - 2*PI), 2) + pow(Decay->bAntitop().eta() - probejet.eta(), 2));
// 	  	  else distanceb = sqrt(pow(Decay->bAntitop().phi() - probejet.phi(), 2) + pow(Decay->bAntitop().eta() - probejet.eta(), 2));

// 	  	  if(distanceW1 < microjet_cone   && distanceW2 < microjet_cone && distanceb<microjet_cone) collimated=true; 
// 	  	  if(distanceW1 < 0.9 * microjet_cone && distanceW2 < 0.9 * microjet_cone && distanceb < 0.9 * microjet_cone) collimated01 = true;
// 	  	  if(distanceW1 < 0.8 * microjet_cone && distanceW2 < 0.8 * microjet_cone && distanceb < 0.8 * microjet_cone) collimated02 = true;
// 	  	  if(distanceW1 < 0.7 * microjet_cone && distanceW2 < 0.7 * microjet_cone && distanceb < 0.7 * microjet_cone) collimated03 = true;
// 	  	  if(distanceW1 < 0.6 * microjet_cone && distanceW2 < 0.6 * microjet_cone && distanceb < 0.6 * microjet_cone) collimated04 = true;
// 	  	  if(distanceW1 < 0.5 * microjet_cone && distanceW2 < 0.5 * microjet_cone && distanceb < 0.5 * microjet_cone) collimated05 = true;
// 	  	  if(distanceW1 < 0.4 * microjet_cone && distanceW2 < 0.4 * microjet_cone && distanceb < 0.4 * microjet_cone) collimated06 = true;
// 	  	  if(distanceW1 < 0.3 * microjet_cone && distanceW2 < 0.3 * microjet_cone && distanceb < 0.3 * microjet_cone) collimated07 = true;
// 	  	}


// 	      oldbestjet2 = bestjetindex2;
//        	      double mjet, mmin;
// 	      int nsubjets;
// 	      std::vector<fastjet::PseudoJet> subjets;
// 	      fastjet::PseudoJet CMSjet; 
// 	      int index;
// 	      bool taken[6] = {true,true,true,true,true,true};                                  
// 	      double olddistance = 1000.;
// 	      double distance = 100.;

// 	      for(int t = 0; t < subjets.size(); t++)
// 	  	{
// 	  	  for(int L = 0; L < decay_products.size(); L++)
// 	  	    {
// 	  	      if(subjets[t].phi() > PI)  distance = sqrt(pow(decay_products[L].phi() - (subjets[t].phi() - 2*PI), 2) + pow(decay_products[L].eta() - subjets[t].eta(), 2));
// 	  	      else                       distance = sqrt(pow(decay_products[L].phi() - subjets[t].phi(), 2) + pow(decay_products[L].eta() - subjets[t].eta(), 2));
		   
//  	  	      if(distance < olddistance && taken[L])                
// 	  		{ 
// 	  		  index = L;
// 	  		  olddistance = distance;
// 	  		}
// 	  	    }
// 	  	  taken[index] = false;             
// 	  	}
	      
// 	      mjet = SortedJets[bestjetindex2].m();                                                                               
// 	      double tau1, tau2, tau3, tau4;

// 	      if(jet.constituents().size() > 0)                                                  
// 	  	{ 
// 	  	  JetPropsPseudo jp(&jet);
// 	  	  tau1 = jp.GetNsubjettiness(1, Njettiness::onepass_kt_axes, 1., varjets[bestjetindex2].user_index() / 10.);
// 	  	  tau2 = jp.GetNsubjettiness(2, Njettiness::onepass_kt_axes, 1., varjets[bestjetindex2].user_index() / 10.);
// 	  	  tau3 = jp.GetNsubjettiness(3, Njettiness::onepass_kt_axes, 1., varjets[bestjetindex2].user_index() / 10.);
// 	  	  tau4 = jp.GetNsubjettiness(4, Njettiness::onepass_kt_axes, 1., varjets[bestjetindex2].user_index() / 10.);
// 	  	}

// 	    	                                                      Hist("tau3pertau2")->Fill(tau3 / tau2, weight); 
// 	      if(Had_Tops[j].pt() < 200)                              Hist("tau3pertau2 pT < 200")->Fill(tau3 / tau2, weight); 
// 	      if(Had_Tops[j].pt() > 200 && Had_Tops[j].pt() < 400)    Hist("tau3pertau2 200 < pT < 400")->Fill(tau3 / tau2, weight); 
// 	      if(Had_Tops[j].pt() > 400 && Had_Tops[j].pt() < 600)    Hist("tau3pertau2 400 < pT < 600")->Fill(tau3 / tau2, weight); 
// 	      if(Had_Tops[j].pt() > 600 && Had_Tops[j].pt() < 800)    Hist("tau3pertau2 600 < pT < 800")->Fill(tau3 / tau2, weight);
// 	      if(Had_Tops[j].pt() > 800)                              Hist("tau3pertau2 pT > 800")->Fill(tau3 / tau2, weight);

// 	      fastjet::PseudoJet groomed_jet;
// 	      //	      Hist("sd_mass")->Fill(groomed_jet.m(), weight);

// 	      if(groomed_jet.m() > 65 && groomed_jet.m() < 135 && tau2 / tau1 < 0.6)
// 	  	{
// 		  // 	  Hist("W0-Tagger")->Fill(Had_Tops[j].pt(), weight);
// 	  	}

// 	      if(SortedSubJets2.size() > 2 && SortedJets[bestjetindex2].m() > mtopLow && SortedJets[bestjetindex2].m() < mtopHigh && mmin2 > 50 && varjets.size() > 2)
// 		{
// 		                                                              Hist("4Cuts")->Fill(Had_Tops[j].pt(), weight); 
// 		      if(Had_Tops[j].pt() < 200)                              Hist("4Cuts pT < 200")->Fill(Had_Tops[j].pt(), weight); 
// 		      if(Had_Tops[j].pt() > 200 && Had_Tops[j].pt() < 400)    Hist("4Cuts 200 < pT < 400")->Fill(Had_Tops[j].pt(), weight); 
// 		      if(Had_Tops[j].pt() > 400 && Had_Tops[j].pt() < 600)    Hist("4Cuts 400 < pT < 600")->Fill(Had_Tops[j].pt(), weight); 
// 		      if(Had_Tops[j].pt() > 600 && Had_Tops[j].pt() < 800)    Hist("4Cuts 600 < pT < 800")->Fill(Had_Tops[j].pt(), weight);
// 		      if(Had_Tops[j].pt() > 800)                              Hist("4Cuts pT > 800")->Fill(Had_Tops[j].pt(), weight);
// 		}

// 	      if(SortedSubJets2.size() > 2 && SortedJets[bestjetindex2].m() > mtopLow && SortedJets[bestjetindex2].m() < mtopHigh && SortedSubJets2.at(0).pt() > 30 && SortedSubJets2.at(1).pt() > 30 &&                                         SortedSubJets2.at(0).pt() / SortedJets[bestjetindex2].pt() < 0.8 && tau3 / tau2 < 0.7 && mmin2 > 50) 	         
// 		{    
// 		                                                              Hist("7Cuts")->Fill(Had_Tops[j].pt(), weight); 
// 		      if(Had_Tops[j].pt() < 200)                              Hist("7Cuts pT < 200")->Fill(Had_Tops[j].pt(), weight); 
// 		      if(Had_Tops[j].pt() > 200 && Had_Tops[j].pt() < 400)    Hist("7Cuts 200 < pT < 400")->Fill(Had_Tops[j].pt(), weight); 
// 		      if(Had_Tops[j].pt() > 400 && Had_Tops[j].pt() < 600)    Hist("7Cuts 400 < pT < 600")->Fill(Had_Tops[j].pt(), weight); 
// 		      if(Had_Tops[j].pt() > 600 && Had_Tops[j].pt() < 800)    Hist("7Cuts 600 < pT < 800")->Fill(Had_Tops[j].pt(), weight);
// 		      if(Had_Tops[j].pt() > 800)                              Hist("7Cuts pT > 800")->Fill(Had_Tops[j].pt(), weight);
// 		}					     


// 	    }
// 	  time1 += clock() - tstart;            // Wozu eigentlich???
// 	}
//     }

	    



// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// //          Ab Hier beginnt das Skript fuer QCD-samples!!!!!!!!!!!!!!!!!!!!
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






//   if(!IsRealData && idVersion.Contains("QCD15to3000") || idVersion.Contains("QCD") )   
//     {
//       std::vector<GenParticle>* genparticles = calc->GetGenParticles();
//       std::vector<fastjet::PseudoJet> genvector;
	     
//       for(int tx = 0; tx < genparticles->size(); tx++)
// 	{
// 	  TLorentzVector particle;
// 	  particle.SetPtEtaPhiE(genparticles->at(tx).pt(), genparticles->at(tx).eta(), genparticles->at(tx).phi(), genparticles->at(tx).energy());
// 	  fastjet::PseudoJet gen_particle(particle.Px(), particle.Py(), particle.Pz(), particle.E());
// 	  if(genparticles->at(tx).status() == 1) genvector.push_back(gen_particle);
// 	}
	     
//       fastjet::ClusterSequence clustersq, clustersq2;
//       double subjetmass, mmin2;
//       double distance;
//       vector<fastjet::PseudoJet> varjets, fatjets, fatjets_backup;
//       EventCalc* calc = EventCalc::Instance();
//       fastjet::JetDefinition *JetDef ;
//       std::vector<fastjet::PseudoJet> SortedSubJets;
//       TopJet topjet;
//       JetProps jp(&topjet, calc->GetPFParticles());
//       std::vector<fastjet::PseudoJet> jetpart = genvector;
//       double ptmin(10.);
//       vector<fastjet::PseudoJet> inclusive_jetsCA;
//       fastjet::JetDefinition jet_defCA2;
 
//       HHTopTagger pluginAKT(mu, theta,min_r, max_r,rho,mw, HHTopTagger::CALIKE,fatjets);
//       fastjet::JetDefinition jet_defCA(&pluginAKT);
//       jet_defCA2 = jet_defCA;
//       fastjet::ClusterSequence clust_seqCA(jetpart, jet_defCA2);
//       inclusive_jetsCA = clust_seqCA.inclusive_jets(ptmin);
//       SortedSubJets = sorted_by_pt(inclusive_jetsCA);
//       fatjets = pluginAKT.get_fatjets();
//       std::vector<double> deltaR, deltapT, mj_wmass;
//       deltaR = pluginAKT.get_deltaR();
//       deltapT = pluginAKT.get_deltapT();
//       mj_wmass = pluginAKT.get_mass();
//       fatjets_backup = fatjets;

//       bool event1 = true;      
//       for(int o = 0; o < fatjets.size(); o++)  if(fatjets[o].user_index() != -1) event1 = false;
	

//       std::vector<fastjet::PseudoJet> fatjets_comb, garbage;
//       fastjet::PseudoJet testjet;
//       std::vector<int> jetindex[fatjets.size()];

//       for(int o = 0; o < fatjets.size(); o++)
// 	{
// 	  for(int L = 0; L < clust_seqCA.jets().size(); L++)  if(clust_seqCA.jets()[L].pt() == fatjets[o].pt()) jetindex[o].push_back(L);
// 	  jetindex[o].push_back(fatjets[o].user_index());
// 	}

//       int index = 0;
//       std::vector<fastjet::PseudoJet> subjets[fatjets.size()];
//       std::vector<fastjet::PseudoJet> jet_radiation, jet_beam;

//       for(int o = 0; o < fatjets.size(); o++)
//       	{
// 	  //Hists AllJets
// 	                                                              Hist("AllJets")->Fill(fatjets[o].pt(), weight);         
// 	  if(fatjets[o].pt() < 200)                                   Hist("AllJets pT < 200")->Fill(fatjets[o].pt(), weight);         
// 	  if(fatjets[o].pt() > 200 && fatjets[o].pt() < 400)          Hist("AllJets 200 < pT < 400")->Fill(fatjets[o].pt(), weight);                                                
// 	  if(fatjets[o].pt() > 400 && fatjets[o].pt() < 600)          Hist("AllJets 400 < pT < 600")->Fill(fatjets[o].pt(), weight);                                                
// 	  if(fatjets[o].pt() > 600 && fatjets[o].pt() < 800)          Hist("AllJets 600 < pT < 800")->Fill(fatjets[o].pt(), weight);                                                
// 	  if(fatjets[o].pt() > 800)                                   Hist("AllJets pT > 800")->Fill(fatjets[o].pt(), weight); 


//       	  if(fatjets[o].user_index() != -99 && fatjets[o].pt() > ptmin)
//       	    {
//       	      index++;
//       	      fastjet::PseudoJet testjet = fatjets[o];
//       	      subjets[index-1].push_back(clust_seqCA.jets()[jetindex[o].at(0)]);

//       	      for(int t = 0; t < fatjets.size(); t++) 
//       		{
//       		  if(fatjets[o].user_index() == fatjets[t].user_index() && t != o && fatjets[o].user_index() != -1 && fatjets[o].pt() > ptmin && fatjets[o].user_index() != -2)
//       		    {
//       		      testjet.operator+=(fatjets[t]);
//       		      fatjets[t].set_user_index(-99);
//       		      subjets[index-1].push_back(clust_seqCA.jets()[jetindex[t].at(0)]);
//       		    }
//       		}
		     
//       	      for(int k = 0; k < fatjets.size(); k++)
//       		{ 
//       		  if(fatjets[k].user_index() / 100. == fatjets[o].user_index())
//       		    { 
//       		      fatjets_comb.push_back(fatjets[k]);
//       		      fatjets[o].set_user_index(-99);
//       		      fatjets_comb[fatjets_comb.size()-1].set_user_index(index);
//       		      subjets[fatjets_comb.size()-1] = sorted_by_pt(subjets[fatjets_comb.size()-1]);
//       		    }
//       		  else
//       		    {
//       		      if(fatjets[k].user_index() == -1) jet_beam.push_back(fatjets[k]);
//       		      if(fatjets[k].user_index() == -2) jet_radiation.push_back(fatjets[k]);
//       		    }
//       		}
//       	    }
//       	}
       
//       std::vector<fastjet::PseudoJet> fatjet_constituents[fatjets_comb.size()];
      
//       for(int o = 0; o < fatjets_comb.size(); o++)
//       	{
//       	  for(int p = 0; p < subjets[fatjets_comb[o].user_index()-1].size(); p++)
//       	    for(int k = 0; k < subjets[fatjets_comb[o].user_index()-1][p].constituents().size(); k++)
//       	      fatjet_constituents[o].push_back(subjets[fatjets_comb[o].user_index()-1][p].constituents().at(k));
//       	}
	     
//       std::vector<fastjet::PseudoJet> SortedJets;
//       SortedJets =  fatjets_comb;

//       for(int i = 0; i < SortedJets.size(); i++)
//       	{
//       	  std::vector<fastjet::PseudoJet> pfcands = fatjet_constituents[i];
//       	  double oldR = 0;
     
//       	  for(int j = 0; j < pfcands.size(); j++)
//       	    {
//       	      double R = SortedJets[i].delta_R(pfcands[j]);
//       	      if(R > oldR)   oldR = R;	
//       	    }
//       	  SortedJets[i].set_user_index(int(oldR*10));
//       	}
	     
//       varjets = SortedJets;
//       double minDeltaR2 = 10000;
//       int bestjetindex2 = -1;
	     
//       // for(unsigned int j = 0; j < genparticles->size(); j++)
// 	//	{
// 	  //  if(abs(genparticles->at(j).pdgId()) <= 6 || abs(genparticles->at(j).pdgId()) == 21)
// 	    // {
                            
// 	      //   }
// 	  //	}


//       for(unsigned int i = 0; i < varjets.size(); ++i)
//       	{
// 	                                                                   Hist("#SubJets")->Fill(subjets[varjets[i].user_index() - 1].size(), weight); 
//           if(varjets[i].pt() < 200)                                        Hist("#SubJets pT < 200")->Fill(subjets[varjets[i].user_index() - 1].size(), weight); 
// 	  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)               Hist("#SubJets 200 < pT < 400")->Fill(subjets[varjets[i].user_index() - 1].size(), weight);   
// 	  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)               Hist("#SubJets 400 < pT < 600")->Fill(subjets[varjets[i].user_index() - 1].size(), weight);              
// 	  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)               Hist("#SubJets 600 < pT < 800")->Fill(subjets[varjets[i].user_index() - 1].size(), weight);                 
// 	  if(varjets[i].pt() > 800)                                        Hist("#SubJets pT > 800")->Fill(subjets[varjets[i].user_index() - 1].size(), weight); 
	  
//       	  double highestPt = -1;
//       	  bestjetindex = -1;
		 
//       	  for(unsigned int j = 0; j < genparticles->size(); j++)
//       	    {
//       	      if (abs(genparticles->at(j).pdgId()) <= 6 || abs(genparticles->at(j).pdgId()) == 21)
//       		{
//       		  double DeltaR2 = sqrt(pow(genparticles->at(j).phi() - varjets[i].phi_std(), 2) + pow(genparticles->at(j).eta() - varjets[i].pseudorapidity(), 2));
//       		  if (DeltaR2 < varjets[i].user_index() / 10. && genparticles->at(j).pt() > 100)
//       		    {
//       		      bestjetindex = j;
//       		      highestPt = genparticles->at(j).pt();
//       		    }
//       		}
//       	    }

		
// 	  if(bestjetindex >- 1)
// 	    {
// 	      if(varjets[i].user_index() / 10. == 0)  bestjetindex =- 1;

// 	      SortedSubJets = sorted_by_pt(subjets[fatjets_comb[i].user_index() - 1]);

// 	      double mmin2 = 0;
// 	      double wmass_rec = 0;
// 	      double m12 = 0;
	      
// 	      if(SortedSubJets.size() > 2)
// 	      	{
// 	      	  double m01 = 0;
// 	      	  double m02 = 0;
// 	      	  double m12 = 0; 
// 	      	  double m03 = 0;
// 	      	  double m13 = 0;
// 	      	  double m23 = 0;

// 	      	  m01 = (SortedSubJets[0] + SortedSubJets[1]).m();
// 	      	  m02 = (SortedSubJets[0] + SortedSubJets[2]).m();
// 	      	  m12 = (SortedSubJets[1] + SortedSubJets[2]).m();

// 	      	  if(SortedSubJets.size() > 3)
// 	      	    {
// 	      	      m03 = (SortedSubJets[0] + SortedSubJets[3]).m();
// 	      	      m13 = (SortedSubJets[1] + SortedSubJets[3]).m();
// 	      	      m23 = (SortedSubJets[2] + SortedSubJets[3]).m();

// 	      	      double deltaW, deltaW1,deltaW2,deltaW3,deltaW4,deltaW5;
// 	      	      deltaW  = abs(80.4 - m01);
// 	      	      deltaW1 = abs(80.4 - m02);
// 	      	      deltaW2 = abs(80.4 - m12);
// 	      	      deltaW3 = abs(80.4 - m03);
// 	      	      deltaW4 = abs(80.4 - m13);
// 	      	      deltaW5 = abs(80.4 - m23);

// 	      	      if(deltaW  < deltaW1 && deltaW  < deltaW2 && deltaW  < deltaW3 && deltaW  < deltaW4 && deltaW  < deltaW5)   wmass_rec = m01;
// 	      	      if(deltaW1 < deltaW  && deltaW1 < deltaW2 && deltaW1 < deltaW3 && deltaW1 < deltaW4 && deltaW1 < deltaW5)   wmass_rec = m02; 
// 	      	      if(deltaW2 < deltaW  && deltaW2 < deltaW1 && deltaW2 < deltaW3 && deltaW2 < deltaW4 && deltaW2 < deltaW5)   wmass_rec = m12;
// 	      	      if(deltaW3 < deltaW  && deltaW3 < deltaW1 && deltaW3 < deltaW2 && deltaW3 < deltaW4 && deltaW3 < deltaW5)   wmass_rec = m03;
// 	      	      if(deltaW4 < deltaW  && deltaW4 < deltaW1 && deltaW4 < deltaW2 && deltaW4 < deltaW3 && deltaW4 < deltaW5)   wmass_rec = m13;
// 	      	      if(deltaW5 < deltaW  && deltaW5 < deltaW1 && deltaW5 < deltaW2 && deltaW5 < deltaW4 && deltaW5 < deltaW3)   wmass_rec = m23; 
// 	      	    }
			 
// 	      	  else
// 	      	    {
// 	      	      double deltaW, deltaW1, deltaW2;
// 	      	      deltaW  = abs(80.4 - m01);
// 	      	      deltaW1 = abs(80.4 - m02);
// 	      	      deltaW2 = abs(80.4 - m12);

// 	      	      if(deltaW  < deltaW1 && deltaW  < deltaW2) wmass_rec = m01;
// 	      	      if(deltaW1 < deltaW  && deltaW1 < deltaW2) wmass_rec = m02;
// 	      	      if(deltaW2 < deltaW  && deltaW2 < deltaW1) wmass_rec = m12;
// 	      	    }
			 
// 	      	  mmin2 = std::min(m01, std::min(m02, m12));
// 		                                                                   Hist("MMin2")->Fill(mmin2, weight);  
//        		  if(varjets[i].pt() < 200)                                        Hist("MMin2 pT < 200")->Fill(mmin2, weight);   
// 		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)               Hist("MMin2 200 < pT < 400")->Fill(mmin2, weight);   
// 		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)               Hist("MMin2 400 < pT < 600")->Fill(mmin2, weight);              
// 		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)               Hist("MMin2 600 < pT < 800")->Fill(mmin2, weight);                 
// 		  if(varjets[i].pt() > 800)                                        Hist("MMin2 pT > 800")->Fill(mmin2, weight); 
// 	      	}
		 
// 	      if(SortedSubJets.size() > 2)  
// 	      	{

// 		                                                                   Hist("TopTaggedTops")->Fill(genparticles->at(bestjetindex).pt(),weight);        
//  		  if(varjets[i].pt() < 200)                                        Hist("TopTaggedTops pT < 200")->Fill(genparticles->at(bestjetindex).pt(),weight);   
// 		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)               Hist("TopTaggedTops 200 < pT < 400")->Fill(genparticles->at(bestjetindex).pt(),weight);   
// 		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)               Hist("TopTaggedTops 400 < pT < 600")->Fill(genparticles->at(bestjetindex).pt(),weight);              
// 		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)               Hist("TopTaggedTops 600 < pT < 800")->Fill(genparticles->at(bestjetindex).pt(),weight);                 
// 		  if(varjets[i].pt() > 800)                                        Hist("TopTaggedTops pT > 800")->Fill(genparticles->at(bestjetindex).pt(),weight); 


// 		                                                                   Hist("masstop")->Fill(varjets[i].m(), weight);      
//     		  if(varjets[i].pt() < 200)                                        Hist("masstop pT < 200")->Fill(varjets[i].m(), weight);   
// 		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)               Hist("masstop 200 < pT < 400")->Fill(varjets[i].m(), weight);   
// 		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)               Hist("masstop 400 < pT < 600")->Fill(varjets[i].m(), weight);              
// 		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)               Hist("masstop 600 < pT < 800")->Fill(varjets[i].m(), weight);                 
// 		  if(varjets[i].pt() > 800)                                        Hist("masstop pT > 800")->Fill(varjets[i].m(), weight);


// 		                                                                   Hist("SubJet1pT")->Fill(SortedSubJets.at(0).pt(), weight);      
//     		  if(varjets[i].pt() < 200)                                        Hist("SubJet1pT pT < 200")->Fill(SortedSubJets.at(0).pt(), weight);   
// 		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)               Hist("SubJet1pT 200 < pT < 400")->Fill(SortedSubJets.at(0).pt(), weight);   
// 		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)               Hist("SubJet1pT 400 < pT < 600")->Fill(SortedSubJets.at(0).pt(), weight);              
// 		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)               Hist("SubJet1pT 600 < pT < 800")->Fill(SortedSubJets.at(0).pt(), weight);                 
// 		  if(varjets[i].pt() > 800)                                        Hist("SubJet1pT pT > 800")->Fill(SortedSubJets.at(0).pt(), weight);


// 		                                                                   Hist("SubJet2pT")->Fill(SortedSubJets.at(1).pt(), weight);      
//     		  if(varjets[i].pt() < 200)                                        Hist("SubJet2pT pT < 200")->Fill(SortedSubJets.at(1).pt(), weight);   
// 		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)               Hist("SubJet2pT 200 < pT < 400")->Fill(SortedSubJets.at(1).pt(), weight);   
// 		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)               Hist("SubJet2pT 400 < pT < 600")->Fill(SortedSubJets.at(1).pt(), weight);              
// 		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)               Hist("SubJet2pT 600 < pT < 800")->Fill(SortedSubJets.at(1).pt(), weight);                 
// 		  if(varjets[i].pt() > 800)                                        Hist("SubJet2pT pT > 800")->Fill(SortedSubJets.at(1).pt(), weight);


// 		                                                                   Hist("SubJetperJet-pT")->Fill(SortedSubJets.at(0).pt() / varjets[i].pt(), weight);      
//     		  if(varjets[i].pt() < 200)                                        Hist("SubJetperJet-pT pT < 200")->Fill(SortedSubJets.at(0).pt() / varjets[i].pt(), weight);   
// 		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)               Hist("SubJetperJet-pT 200 < pT < 400")->Fill(SortedSubJets.at(0).pt() / varjets[i].pt(), weight);   
// 		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)               Hist("SubJetperJet-pT 400 < pT < 600")->Fill(SortedSubJets.at(0).pt() / varjets[i].pt(), weight);              
// 		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)               Hist("SubJetperJet-pT 600 < pT < 800")->Fill(SortedSubJets.at(0).pt() / varjets[i].pt(), weight);                 
// 		  if(varjets[i].pt() > 800)                                        Hist("SubJetperJet-pT pT > 800")->Fill(SortedSubJets.at(0).pt() / varjets[i].pt(), weight);
// 		}

// 	      std::vector<fastjet::PseudoJet> subjets;
// 	      fastjet::PseudoJet jet = varjets.at(i);
// 	      fastjet::PseudoJet CMSjet;
// 	      double mjet, mmin;
// 	      int nsubjets;

// 		                                                                   Hist("AllTops")->Fill(genparticles->at(bestjetindex).pt(), weight);      
//     		  if(varjets[i].pt() < 200)                                        Hist("AllTops pT < 200")->Fill(genparticles->at(bestjetindex).pt(), weight);   
// 		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)               Hist("AllTops 200 < pT < 400")->Fill(genparticles->at(bestjetindex).pt(), weight);   
// 		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)               Hist("AllTops 400 < pT < 600")->Fill(genparticles->at(bestjetindex).pt(), weight);              
// 		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)               Hist("AllTops 600 < pT < 800")->Fill(genparticles->at(bestjetindex).pt(), weight);                 
// 		  if(varjets[i].pt() > 800)                                        Hist("AllTops pT > 800")->Fill(genparticles->at(bestjetindex).pt(), weight);


// 	      mjet = SortedJets[i].m();
// 	      double tau1,tau2,tau3,tau4;
// 	      JetPropsPseudo jp(&jet);
// 	      tau1 = jp.GetNsubjettiness(1, Njettiness::onepass_kt_axes, 1., varjets[i].user_index() / 10.);
// 	      tau2 = jp.GetNsubjettiness(2, Njettiness::onepass_kt_axes, 1., varjets[i].user_index() / 10.);
// 	      tau3 = jp.GetNsubjettiness(3, Njettiness::onepass_kt_axes, 1., varjets[i].user_index() / 10.);
// 	      tau4 = jp.GetNsubjettiness(4, Njettiness::onepass_kt_axes, 1., varjets[i].user_index() / 10.);


// 		                                                                   Hist("tau3pertau2")->Fill(tau3 / tau2, weight);      
//     		  if(varjets[i].pt() < 200)                                        Hist("tau3pertau2 pT < 200")->Fill(tau3 / tau2, weight);   
// 		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)               Hist("tau3pertau2 200 < pT < 400")->Fill(tau3 / tau2, weight);   
// 		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)               Hist("tau3pertau2 400 < pT < 600")->Fill(tau3 / tau2, weight);              
// 		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)               Hist("tau3pertau2 600 < pT < 800")->Fill(tau3 / tau2, weight);                 
// 		  if(varjets[i].pt() > 800)                                        Hist("tau3pertau2 pT > 800")->Fill(tau3 / tau2, weight);
                             

// 	      fastjet::PseudoJet groomed_jet;
// 	      //	      Hist("sd_mass")->Fill(groomed_jet.m(), weight);

// 	      if(groomed_jet.m() > 65 && groomed_jet.m() < 135 && tau2 / tau1 < 0.6)
// 	    	{
// 		  //   	  Hist("W0-Tagger")->Fill(genparticles->at(bestjetindex).pt(), weight); /// SortedJets[i].m() =  varjets[i].m()
// 	    	}

// 	      if(SortedSubJets.size() > 2 && SortedJets[i].m() > mtopLow && SortedJets[i].m() < mtopHigh && mmin2 > 50 && varjets.size() > 2) 
// 		{
// 		                                                                   Hist("4Cuts")->Fill(genparticles->at(bestjetindex).pt(), weight);      
//     		  if(varjets[i].pt() < 200)                                        Hist("4Cuts pT < 200")->Fill(genparticles->at(bestjetindex).pt(), weight);   
// 		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)               Hist("4Cuts 200 < pT < 400")->Fill(genparticles->at(bestjetindex).pt(), weight);   
// 		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)               Hist("4Cuts 400 < pT < 600")->Fill(genparticles->at(bestjetindex).pt(), weight);              
// 		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)               Hist("4Cuts 600 < pT < 800")->Fill(genparticles->at(bestjetindex).pt(), weight);                 
// 		  if(varjets[i].pt() > 800)                                        Hist("4Cuts pT > 800")->Fill(genparticles->at(bestjetindex).pt(), weight);
// 		}
	      

// 	      if(SortedSubJets.size() > 2 && varjets[i].m() > mtopLow && varjets[i].m() < mtopHigh && tau3 / tau2 < 0.7 && SortedSubJets.at(0).pt() > 30 && SortedSubJets.at(1).pt() > 30 &&                                                     SortedSubJets.at(0).pt() / varjets[i].pt() < 0.8 && mmin2 > 50)      
// 		{
// 		                                                                   Hist("7Cuts")->Fill(genparticles->at(bestjetindex).pt(), weight);      
//     		  if(varjets[i].pt() < 200)                                        Hist("7Cuts pT < 200")->Fill(genparticles->at(bestjetindex).pt(), weight);   
// 		  if(varjets[i].pt() > 200 && varjets[i].pt() < 400)               Hist("7Cuts 200 < pT < 400")->Fill(genparticles->at(bestjetindex).pt(), weight);   
// 		  if(varjets[i].pt() > 400 && varjets[i].pt() < 600)               Hist("7Cuts 400 < pT < 600")->Fill(genparticles->at(bestjetindex).pt(), weight);              
// 		  if(varjets[i].pt() > 600 && varjets[i].pt() < 800)               Hist("7Cuts 600 < pT < 800")->Fill(genparticles->at(bestjetindex).pt(), weight);                 
// 		  if(varjets[i].pt() > 800)                                        Hist("7Cuts pT > 800")->Fill(genparticles->at(bestjetindex).pt(), weight);

// 		}
// 	    }
// 	}
//     }
// }


// void Eugen::Finish()
// {
//   // EventCalc* calc = EventCalc::Instance();
//   // bool IsRealData = calc->IsRealData();
//   // /*
//   //   if(IsRealData)
//   //   {
//   //   Hist("N_pv_perLumiBin")->Divide(Hist("N_pv_perLumiBin"), Hist("N_events_perLumiBin"));
//   //   Hist( "N_pv_perLumiBin")->GetYaxis()->SetTitle("Events/Lumi");
//   //   }
//   // */
// }

