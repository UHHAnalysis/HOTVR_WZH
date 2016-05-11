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


//   /*
//   int rho[3] = {190, 200, 210};
//   for(int i = 0; i < 3; i++)
//     {
//       string s_rho = std::to_string(rho[i]);

//       double theta[3] = {0.5, 0.6, 0.7};
//       for(int j = 0; j < 3; j++)
// 	{
// 	  string s_theta = std::to_string(theta[j]);

// 	  int mu[3] = {15, 20, 25};
// 	  for(int k = 0; k < 3; k++)
// 	    {
// 	      string s_mu = std::to_string(mu[k]);

// 	      string s_name = "WTagTree" + s_rho + s_theta + s_mu;
// 	      const char* c_name = s_name.c_str();
// 	      TTree* wtagtree = GetOutputMetadataTree(c_name);
// 	      //RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen", wtagtree, rho[i], theta[j], mu[k]) );
// 	      RegisterHistCollection( new TMVATreeFiller_hhtt_gen(c_name, wtagtree, rho[i], theta[j], mu[k]) );
// 	      InitHistos();
// 	      return;
// 	    }
// 	}
//     }
//   */

 
//   //Funktioniert fuer zwei Trees!!!!:

//   int rho = 200;
//   double theta = 0.6;
//   int mu = 15;
//   TTree * wtagtree = GetOutputMetadataTree("WTagTree");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen", wtagtree, rho, theta, mu) );
//   InitHistos();
  


   
//   rho = 190;
//   theta = 0.5;
//   mu = 15;
//   TTree * wtagtree2 = GetOutputMetadataTree("WTagTree_rho190_theta05_mu15");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen2", wtagtree2, rho, theta, mu) );
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






//   //Funktioniert fuer zwei Trees!!!!:
  
  
//   int rho = 200;
//   double theta = 0.6;
//   int mu = 15;

//   BaseHists* TreeFiller_gen = GetHistCollection("WTagFiller_gen");
//   ((RocHists*)TreeFiller_gen)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen->Fill();
  


//   rho = 190;
//   theta = 0.5;
//   mu = 15;

//   BaseHists* TreeFiller_gen2 = GetHistCollection("WTagFiller_gen2");
//   ((RocHists*)TreeFiller_gen2)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen2->Fill();
//   return;








//   /*
//   int rho[3] = {190, 200, 210};
//   for(int i = 0; i < 3; i++)
//     {
//       string s_rho = std::to_string(rho[i]);

//       double theta[3] = {0.5, 0.6, 0.7};
//       for(int j = 0; j < 3; j++)
// 	{
// 	  string s_theta = std::to_string(theta[j]);

// 	  int mu[3] = {15, 20, 25};
// 	  for(int k = 0; k < 3; k++)
// 	    {
// 	      string s_mu = std::to_string(mu[k]);

// 	      string s_name = "WTagTree" + s_rho + s_theta + s_mu;
// 	      const char* c_name = s_name.c_str();

// 	      //BaseHists* TreeFiller_gen = GetHistCollection("WTagFiller_gen");
// 	      BaseHists* TreeFiller_gen = GetHistCollection(c_name);
// 	      ((RocHists*)TreeFiller_gen)->SetIdVersion(id.GetVersion());
// 	      TreeFiller_gen->Fill();
// 	      return;

// 	    }
// 	}
//     }
//   */

  






  
// }

