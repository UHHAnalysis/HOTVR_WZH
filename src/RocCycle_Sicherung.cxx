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
//    : AnalysisCycle() 
// {
//   SetIntLumiPerBin(500.);
// }

// RocCycle::~RocCycle() 
// {}

// void RocCycle::BeginCycle() throw( SError ) 
// {
//   AnalysisCycle::BeginCycle();
//   return;
// }

// void RocCycle::EndCycle() throw( SError ) 
// {
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

//    int rhos[3] = {190, 200, 210};
//    for(int i = 0; i < 3; i++)
//      {
//        string s_rhos = std::to_string(rhos[i]); 
//        string s_name = "NoCutsHistosGen" + s_rhos;
//        const char* c_name = s_name.c_str();
//        RegisterHistCollection( new Eugen(c_name));
//      }
   
//    InitHistos();
//   // RegisterHistCollection( new RocHistsGen("NoCutsHistosGenRho190"));
//   // RegisterHistCollection( new RocHistsGen("NoCutsHistosGenRho200"));
//   // RegisterHistCollection( new RocHistsGen("NoCutsHistosGenRho210"));




    
//       // important: initialise histogram collections after their definition
//        InitHistos();

// }

// void RocCycle::EndInputData( const SInputData& id ) throw( SError ) 
// {
//   AnalysisCycle::EndInputData( id );
// }

// void RocCycle::BeginInputFile( const SInputData& id ) throw( SError ) 
// {
//   AnalysisCycle::BeginInputFile( id );
// }

// void RocCycle::ExecuteEvent( const SInputData& id, Double_t weight) throw( SError ) 
// {
//   AnalysisCycle::ExecuteEvent( id, weight );
  
//   //  VERSCHIEDENE RHO:
//   int rhos[3] = {190, 200, 210};
//   for(int i = 0; i < 3; i++)
//     {
//       string s_rhos = std::to_string(rhos[i]); 
//       string s_name = "NoCutsHistosGen" + s_rhos;
//       const char* c_name = s_name.c_str();
           
//       BaseHists* NoCutsHistosGen = GetHistCollection(c_name);

//       EventCalc* calc = EventCalc::Instance();
//       BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
//       bool IsRealData = calc->IsRealData();
 
//       ((RocHists*)NoCutsHistosGen)->SetIdVersion(id.GetVersion());

//       NoCutsHistosGen->Fill();

//     }
  


  
   
//   // string s_name = "NoCutsHistosGen";
//   // BaseHists* NoCutsHistosGen = GetHistCollection(s_name);
//   // EventCalc* calc = EventCalc::Instance();
//   //  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
//   // bool IsRealData = calc->IsRealData();
//   // ((RocHists*)NoCutsHistosGen)->SetIdVersion(id.GetVersion());
//   //  NoCutsHistosGen->Fill();
  
//   return;
  
// }


