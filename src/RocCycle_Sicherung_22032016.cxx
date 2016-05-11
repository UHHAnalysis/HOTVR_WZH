// // $Id: RocCycle.cxx,v 1.10 2012/12/07 14:21:51 peiffer Exp $

// #include <iostream>

// using namespace std;
// #include <string>

// #include "include/RocCycle.h"
// #include "include/RocHists.h"
// #include "include/RocHists2.h"
// #include "include/Eugen.h"
// #include "include/RocHists3.h"
// #include "include/RocHists3Gen.h"
// #include "include/RocHistsComb.h"

// #include "SFrameAnalysis/include/SelectionModules.h"
// //#include "SFrameAnalysis/include/HypothesisHists.h"

// ClassImp( RocCycle );

// RocCycle::RocCycle()
//    : AnalysisCycle() {
  
//   SetIntLumiPerBin(500.);// set the integrated luminosity per bin for the lumi-yield control plots

// }

// RocCycle::~RocCycle() // destructor
// {
// }

// void RocCycle::BeginCycle() throw( SError ) 
// {
//   AnalysisCycle::BeginCycle();
//   return;
// }

// void RocCycle::EndCycle() throw( SError ) 
// {
//   // clean-up, info messages and final calculations after the analysis

  
//   // call the base cycle class for all standard methods
//   AnalysisCycle::EndCycle();

//   return;

// }

// void RocCycle::BeginInputData( const SInputData& id ) throw( SError ) 
// {
//   AnalysisCycle::BeginInputData( id );

//   // -------------------- set up the selections ---------------------------
//   //DO NOT use trigger selection in PROOF mode at the moment
//   //TopSel->addSelectionModule(new TriggerSelection("HLT_PFJet320_v"));
//   //TriggerSel = new Selection("TriggerSel");
//   //TriggerSel->addSelectionModule(new TriggerSelection("HLT_DiJet80Eta2p6_BTagIP3DFastPVLoose"));

//   // ---------------- set up the histogram collections --------------------
//   // RegisterHistCollection( new RocHistsGen("NoCutsHistosGen"));
//   //RegisterHistCollection( new RocHistsGen("NoCutsHistosGen", 610.));
//   // RegisterHistCollection( new RocHists2("NoCutsHistos2"));
//   // RegisterHistCollection( new RocHists3("NoCutsHistos3"));
//   //  RegisterHistCollection( new RocHists3Gen("NoCutsHistos3Gen"));
//   // RegisterHistCollection( new RocHistsComb("NoCutsHistosComb"));
//   // RegisterHistCollection( new SubstructureHists("before_cms_Tag_pt400"));
//   // RegisterHistCollection( new SubstructureHists("after_cms_Tag_pt400"));
//   // RegisterHistCollection( new SubstructureHists("before_cms_Tag_pt600"));
//   // RegisterHistCollection( new SubstructureHists("after_cms_Tag_pt600"));
//   // RegisterHistCollection( new SubstructureHists("before_cms_Tag_pt800"));
//   // RegisterHistCollection( new SubstructureHists("after_cms_Tag_pt800"));


//      string s_name = "NoCutsHistosGen";
//      const char* c_name = s_name.c_str();
//      RegisterHistCollection( new Eugen(c_name));
      
    
//       // important: initialise histogram collections after their definition
//       InitHistos();

// }

// void RocCycle::EndInputData( const SInputData& id ) throw( SError ) 
// {
//   AnalysisCycle::EndInputData( id );
// }

// void RocCycle::BeginInputFile( const SInputData& id ) throw( SError ) 
// {
//   // Connect all variables from the Ntuple file with the ones needed for the analysis
//   // The variables are commonly stored in the BaseCycleContaincer
//   // important: call to base function to connect all variables to Ntuples from the input tree
//   AnalysisCycle::BeginInputFile( id );
// }

// void RocCycle::ExecuteEvent( const SInputData& id, Double_t weight) throw( SError ) 
// {
//   // this is the most important part: here the full analysis happens
//   // user should implement selections, filling of histograms and results

//   // first step: call Execute event of base class to perform basic consistency checks
//   // also, the good-run selection is performed there and the calculator is reset
//   AnalysisCycle::ExecuteEvent( id, weight );

//   // get the histogram collections. NOTE: this could be done more performant by making
//   // all thse BaseHists* vairables private member variables of RocCycle and
//   // setting them in BeginInputData. Then, there is no need here to call GetHistColletion ...

  
//   //   VERSCHIEDENE RHO:
//   /*  int rhos[5] = {110, 120, 130, 140, 150};
//   for(int i = 0; i < 5; i++)
//     {
//       string s_rhos = std::to_string(rhos[i]); 
//       string s_name = "NoCutsHistosGen" + s_rhos;
//       const char* c_name = s_name.c_str();
           
//       BaseHists* NoCutsHistosGen = GetHistCollection(c_name);
//       //BaseHists* NoCutsHistosGen = GetHistCollection("NoCutsHistosGen");
//       // BaseHists* NoCutsHistos = GetHistCollection("NoCutsHistos2");
//       // BaseHists* NoCutsHistos3 = GetHistCollection("NoCutsHistos3");
//       //  BaseHists* NoCutsHistos3Gen = GetHistCollection("NoCutsHistos3Gen");
//       // BaseHists* NoCutsHistosComb = GetHistCollection("NoCutsHistosComb");
//       // BaseHists* cms400 = GetHistCollection("before_cms_Tag_pt400");
//       // BaseHists* cms400tag = GetHistCollection("after_cms_Tag_pt400");
//       // BaseHists* cms600 = GetHistCollection("before_cms_Tag_pt600");
//       // BaseHists* cms600tag = GetHistCollection("after_cms_Tag_pt600");
//       // BaseHists* cms800 = GetHistCollection("before_cms_Tag_pt800");
//       // BaseHists* cms800tag = GetHistCollection("after_cms_Tag_pt800");

//       EventCalc* calc = EventCalc::Instance();
//       BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
//       bool IsRealData = calc->IsRealData();
//       //  ((RocHists*)NoCutsHistos)->SetIdVersion(id.GetVersion());
//       // ((RocHists*)NoCutsHistos3)->SetIdVersion(id.GetVersion());
//       //((RocHists*)NoCutsHistosComb)->SetIdVersion(id.GetVersion());
//       ((RocHists*)NoCutsHistosGen)->SetIdVersion(id.GetVersion());
//       //  ((RocHists*)NoCutsHistos3Gen)->SetIdVersion(id.GetVersion());
//       //  NoCutsHistos->Fill();
//       //  NoCutsHistos3->Fill();
//       // NoCutsHistosComb->Fill();
//          NoCutsHistosGen->Fill();
//       //   NoCutsHistos3Gen->Fill();

//     }
  
//   */
   
//   string s_name = "NoCutsHistosGen";

//   BaseHists* NoCutsHistosGen = GetHistCollection(s_name);
//   EventCalc* calc = EventCalc::Instance();
//   BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
//   bool IsRealData = calc->IsRealData();
//   ((RocHists*)NoCutsHistosGen)->SetIdVersion(id.GetVersion());
//   NoCutsHistosGen->Fill();
  
//   return;
  
// }


