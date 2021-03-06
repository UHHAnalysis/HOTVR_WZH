// // $Id: TopTagTMVACycle.cxx,v 1.1 2013/05/21 14:40:03 rkogler Exp $

// #include <iostream>

// using namespace std;

// // Local include(s):
// #include "include/HHTT_TMVACycle.h"
// #include "include/TMVATreeFiller_hhtt.h"
// #include "include/TMVATreeFiller_hhtt_gen.h"
// #include "include/TMVATreeFiller_cms.h"
// #include "include/TMVATreeFiller_cms_gen.h"
// #include "include/TMVATreeFiller_optimalR.h"
// #include "include/TMVATreeFiller_optimalR_gen.h"
// #include "include/SelectionModules.h"
// #include "include/HypothesisHists.h"
// #include "include/RocHists.h"
// ClassImp( HHTT_TMVACycle );

// HHTT_TMVACycle::HHTT_TMVACycle()
//    : AnalysisCycle() {

//   // constructor, declare additional variables that should be 
//   // obtained from the steering-xml file
  
//   // set the integrated luminosity per bin for the lumi-yield control plots
//   SetIntLumiPerBin(250.);

// }

// HHTT_TMVACycle::~HHTT_TMVACycle() 
// {
//   // destructor
// }

// void HHTT_TMVACycle::BeginCycle() throw( SError ) 
// {
//   // Start of the job, general set-up and definition of 
//   // objects are done here

//   // Important: first call BeginCycle of base class
//   AnalysisCycle::BeginCycle();

//   return;

// }

// void HHTT_TMVACycle::EndCycle() throw( SError ) 
// {
//   // clean-up, info messages and final calculations after the analysis

  
//   // call the base cycle class for all standard methods
//   AnalysisCycle::EndCycle();

//   return;

// }

// void HHTT_TMVACycle::BeginInputData( const SInputData& id ) throw( SError ) 
// {
//   // declaration of histograms and selections

//   // Important: first call BeginInputData of base class
//   AnalysisCycle::BeginInputData( id );

//   // create one selection: select CA-jets
//   /*  Selection* CAJetSel = new Selection("CAJetSelection");
//   CAJetSel->addSelectionModule(new NTopJetSelection(1,int_infinity(),200,2.5));
//   RegisterSelection(CAJetSel);
//   */
//   // this class fills the tree for the TMVA analysis
//   TTree * wtagtree = GetOutputMetadataTree("WTagTree");
//   //RegisterHistCollection( new TMVATreeFiller_hhtt("TopTagFiller", toptagtree) );
//    RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen", wtagtree) );
//   //  RegisterHistCollection( new TMVATreeFiller_cms("TopTagFiller_cms", toptagtree) );
//   //   RegisterHistCollection( new TMVATreeFiller_cms_gen("TopTagFiller_cms_gen", toptagtree) );
//   //     RegisterHistCollection( new TMVATreeFiller_optimalR("TopTagFiller_optimalR", toptagtree) );
//   // RegisterHistCollection( new TMVATreeFiller_optimalR_gen("TopTagFiller_optimalR_gen", toptagtree) );
//   // important: initialise histogram collections after their definition
//   InitHistos();

//   return;

// }

// void HHTT_TMVACycle::EndInputData( const SInputData& id ) throw( SError ) 
// {
//   AnalysisCycle::EndInputData( id );

//   return;

// }

// void HHTT_TMVACycle::BeginInputFile( const SInputData& id ) throw( SError ) 
// {
//   // Connect all variables from the Ntuple file with the ones needed for the analysis
//   // The variables are commonly stored in the BaseCycleContaincer

//   // important: call to base function to connect all variables to Ntuples from the input tree
//   AnalysisCycle::BeginInputFile( id );

//   return;

// }

// void HHTT_TMVACycle::ExecuteEvent( const SInputData& id, Double_t weight) throw( SError ) 
// {
//   // this is the most important part: here the full analysis happens
//   // user should implement selections, filling of histograms and results

//   // first step: call Execute event of base class to perform basic consistency checks
//   // also, the good-run selection is performed there and the calculator is reset
//   AnalysisCycle::ExecuteEvent( id, weight );

//   //static Selection* CAJetSel = GetSelection("CAJetSelection");

//   // BaseHists* TreeFiller = GetHistCollection("TopTagFiller");
//   BaseHists* TreeFiller_gen = GetHistCollection("WTagFiller_gen");
//   //BaseHists* TreeFiller_cms = GetHistCollection("TopTagFiller_cms");
//   // BaseHists* TreeFiller_cms_gen = GetHistCollection("TopTagFiller_cms_gen");
//   //BaseHists* TreeFiller_optimalR = GetHistCollection("TopTagFiller_optimalR");
//   //  BaseHists* TreeFiller_optimalR_gen = GetHistCollection("TopTagFiller_optimalR_gen");
//   //if(!CAJetSel->passSelection())  throw SError( SError::SkipEvent );
//   //((RocHists*)TreeFiller)->SetIdVersion(id.GetVersion());
//    ((RocHists*)TreeFiller_gen)->SetIdVersion(id.GetVersion());
//    //((RocHists*)TreeFiller_cms)->SetIdVersion(id.GetVersion());
//    // ((RocHists*)TreeFiller_cms_gen)->SetIdVersion(id.GetVersion());
//    // ((RocHists*)TreeFiller_optimalR)->SetIdVersion(id.GetVersion());
//   //((RocHists*)TreeFiller_optimalR_gen)->SetIdVersion(id.GetVersion());
//   //  std::cout<<"?"<<std::endl;
//   //TreeFiller->Fill();
//    TreeFiller_gen->Fill();
//    //TreeFiller_cms->Fill();
//    // TreeFiller_cms_gen->Fill();
// //  TreeFiller_optimalR->Fill();
//    //  TreeFiller_optimalR_gen->Fill();
//   return;
  
// }

