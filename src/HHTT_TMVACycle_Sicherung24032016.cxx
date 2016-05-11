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

 
//   //11x
//   int rho = 190;
//   double theta = 0.5;
//   int mu = 15;
//   TTree * wtagtree111 = GetOutputMetadataTree("WTagTree111");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen", wtagtree111, rho, theta, mu) );
//   InitHistos();
  
//   rho = 190;
//   theta = 0.5;
//   mu = 20;
//   TTree * wtagtree112 = GetOutputMetadataTree("WTagTree112");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen", wtagtree112, rho, theta, mu) );
//   InitHistos();
  
//   rho = 190;
//   theta = 0.5;
//   mu = 25;
//   TTree * wtagtree113 = GetOutputMetadataTree("WTagTree113");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen", wtagtree113, rho, theta, mu) );
//   InitHistos();
//   //check


//   //12x
//   rho = 190;
//   theta = 0.6;
//   mu = 15;
//   TTree * wtagtree121 = GetOutputMetadataTree("WTagTree121");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen", wtagtree121, rho, theta, mu) );
//   InitHistos();
  
//   rho = 190;
//   theta = 0.6;
//   mu = 20;
//   TTree * wtagtree122 = GetOutputMetadataTree("WTagTree122");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen", wtagtree122, rho, theta, mu) );
//   InitHistos();
  
//   rho = 190;
//   theta = 0.6;
//   mu = 25;
//   TTree * wtagtree123 = GetOutputMetadataTree("WTagTree123");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen", wtagtree123, rho, theta, mu) );
//   InitHistos();
//   //check


//   //13x
//   rho = 190;
//   theta = 0.7;
//   mu = 15;
//   TTree * wtagtree131 = GetOutputMetadataTree("WTagTree131");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen", wtagtree131, rho, theta, mu) );
//   InitHistos();
  
//   rho = 190;
//   theta = 0.7;
//   mu = 20;
//   TTree * wtagtree132 = GetOutputMetadataTree("WTagTree132");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen", wtagtree132, rho, theta, mu) );
//   InitHistos();
  
//   rho = 190;
//   theta = 0.7;
//   mu = 25;
//   TTree * wtagtree133 = GetOutputMetadataTree("WTagTree133");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen", wtagtree133, rho, theta, mu) );
//   InitHistos();
//   //check

















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
  
//   //11x
//   int rho = 190;
//   double theta = 0.5;
//   int mu = 15;
//   BaseHists* TreeFiller_gen111 = GetHistCollection("WTagFiller_gen111");
//   ((RocHists*)TreeFiller_gen111)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen111->Fill();
 
//   rho = 190;
//   theta = 0.5;
//   mu = 20;
//   BaseHists* TreeFiller_gen112 = GetHistCollection("WTagFiller_gen112");
//   ((RocHists*)TreeFiller_gen112)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen112->Fill();

//   rho = 190;
//   theta = 0.5;
//   mu = 25;
//   BaseHists* TreeFiller_gen113 = GetHistCollection("WTagFiller_gen113");
//   ((RocHists*)TreeFiller_gen113)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen113->Fill();
//   //check


//   //12x
//   rho = 190;
//   theta = 0.6;
//   mu = 15;
//   BaseHists* TreeFiller_gen121 = GetHistCollection("WTagFiller_gen121");
//   ((RocHists*)TreeFiller_gen121)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen121->Fill();
 
//   rho = 190;
//   theta = 0.6;
//   mu = 20;
//   BaseHists* TreeFiller_gen122 = GetHistCollection("WTagFiller_gen122");
//   ((RocHists*)TreeFiller_gen122)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen122->Fill();

//   rho = 190;
//   theta = 0.6;
//   mu = 25;
//   BaseHists* TreeFiller_gen123 = GetHistCollection("WTagFiller_gen123");
//   ((RocHists*)TreeFiller_gen123)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen123->Fill();
//   //check

//   //13x
//   rho = 190;
//   theta = 0.7;
//   mu = 15;
//   BaseHists* TreeFiller_gen131 = GetHistCollection("WTagFiller_gen131");
//   ((RocHists*)TreeFiller_gen131)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen131->Fill();
 
//   rho = 190;
//   theta = 0.7;
//   mu = 20;
//   BaseHists* TreeFiller_gen132 = GetHistCollection("WTagFiller_gen132");
//   ((RocHists*)TreeFiller_gen132)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen132->Fill();

//   rho = 190;
//   theta = 0.7;
//   mu = 25;
//   BaseHists* TreeFiller_gen133 = GetHistCollection("WTagFiller_gen133");
//   ((RocHists*)TreeFiller_gen133)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen133->Fill();
//   //check












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

  






//     return;

// }

