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
//   // DeclareProperty("Beta", m_beta);

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

//   int rho;
//   double theta;
//   int mu;
//   //  string sbeta = m_beta;
//   // cout << "BETA String: " << sbeta << endl;
 
//   //  int beta = atoi(sbeta.c_str());

//   //cout << "BETA int: " << beta << endl;





//  /*
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

//   /*
//   //11x
//   int rho = 190;
//   double theta = 0.5;
//   int mu = 15;
//   TTree * wtagtree111 = GetOutputMetadataTree("WTagTree111");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen111", wtagtree111, rho, theta, mu) );
//   InitHistos();
  
//   rho = 190;
//   theta = 0.5;
//   mu = 20;
//   TTree * wtagtree112 = GetOutputMetadataTree("WTagTree112");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen112", wtagtree112, rho, theta, mu) );
//   InitHistos();
  
//   rho = 190;
//   theta = 0.5;
//   mu = 25;
//   TTree * wtagtree113 = GetOutputMetadataTree("WTagTree113");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen113", wtagtree113, rho, theta, mu) );
//   InitHistos();
//   //check


//   //12x
//   rho = 190;
//   theta = 0.6;
//   mu = 15;
//   TTree * wtagtree121 = GetOutputMetadataTree("WTagTree121");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen121", wtagtree121, rho, theta, mu) );
//   InitHistos();
  
//   rho = 190;
//   theta = 0.6;
//   mu = 20;
//   TTree * wtagtree122 = GetOutputMetadataTree("WTagTree122");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen122", wtagtree122, rho, theta, mu) );
//   InitHistos();
  
//   rho = 190;
//   theta = 0.6;
//   mu = 25;
//   TTree * wtagtree123 = GetOutputMetadataTree("WTagTree123");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen123", wtagtree123, rho, theta, mu) );
//   InitHistos();
//   //check


//   //13x
//   rho = 190;
//   theta = 0.7;
//   mu = 15;
//   TTree * wtagtree131 = GetOutputMetadataTree("WTagTree131");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen131", wtagtree131, rho, theta, mu) );
//   InitHistos();
  
//   rho = 190;
//   theta = 0.7;
//   mu = 20;
//   TTree * wtagtree132 = GetOutputMetadataTree("WTagTree132");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen132", wtagtree132, rho, theta, mu) );
//   InitHistos();
  
//   rho = 190;
//   theta = 0.7;
//   mu = 25;
//   TTree * wtagtree133 = GetOutputMetadataTree("WTagTree133");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen133", wtagtree133, rho, theta, mu) );
//   InitHistos();
//   //check
//   */


//   ////2xx///////////////////////////////////////////////////////////////////////  ////2xx///////////////////////////////////////////////////////////////////////////
//   ////2xx///////////////////////////////////////////////////////////////////////////
//   ////2xx///////////////////////////////////////////////////////////////////////////
//   ////2xx///////////////////////////////////////////////////////////////////////////

//   /*

//   //21x
//   int rho = 200;
//   double theta = 0.5;
//   int mu = 15;
//   TTree * wtagtree211 = GetOutputMetadataTree("WTagTree211");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen211", wtagtree211, rho, theta, mu) );
//   InitHistos();
  
//   rho = 200;
//   theta = 0.5;
//   mu = 20;
//   TTree * wtagtree212 = GetOutputMetadataTree("WTagTree212");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen212", wtagtree212, rho, theta, mu) );
//   InitHistos();
  
//   rho = 200;
//   theta = 0.5;
//   mu = 25;
//   TTree * wtagtree213 = GetOutputMetadataTree("WTagTree213");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen213", wtagtree213, rho, theta, mu) );
//   InitHistos();
//   //check//


//   //22x
//   rho = 200;
//   theta = 0.6;
//   mu = 15;
//   TTree * wtagtree221 = GetOutputMetadataTree("WTagTree221");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen221", wtagtree221, rho, theta, mu) );
//   InitHistos();
  
//   rho = 200;
//   theta = 0.6;
//   mu = 20;
//   TTree * wtagtree222 = GetOutputMetadataTree("WTagTree222");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen222", wtagtree222, rho, theta, mu) );
//   InitHistos();
  
//   rho = 200;
//   theta = 0.6;
//   mu = 25;
//   TTree * wtagtree223 = GetOutputMetadataTree("WTagTree223");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen223", wtagtree223, rho, theta, mu) );
//   InitHistos();
//   //check


//   //23x
//   rho = 200;
//   theta = 0.7;
//   mu = 15;
//   TTree * wtagtree231 = GetOutputMetadataTree("WTagTree231");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen231", wtagtree231, rho, theta, mu) );
//   InitHistos();
  
//   rho = 200;
//   theta = 0.7;
//   mu = 20;
//   TTree * wtagtree232 = GetOutputMetadataTree("WTagTree232");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen232", wtagtree232, rho, theta, mu) );
//   InitHistos();
  
//   rho = 200;
//   theta = 0.7;
//   mu = 25;
//   TTree * wtagtree233 = GetOutputMetadataTree("WTagTree233");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen233", wtagtree233, rho, theta, mu) );
//   InitHistos();
//   //check


//   */
  


//   ///////3xx//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//   /*
  
//   //31x
//   int rho = 210;
//   double theta = 0.5;
//   int mu = 15;
//   TTree * wtagtree311 = GetOutputMetadataTree("WTagTree311");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen311", wtagtree311, rho, theta, mu) );
//   InitHistos();
  
//   rho = 210;
//   theta = 0.5;
//   mu = 20;
//   TTree * wtagtree312 = GetOutputMetadataTree("WTagTree312");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen312", wtagtree312, rho, theta, mu) );
//   InitHistos();
  
//   rho = 210;
//   theta = 0.5;
//   mu = 25;
//   TTree * wtagtree313 = GetOutputMetadataTree("WTagTree313");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen313", wtagtree313, rho, theta, mu) );
//   InitHistos();
//   //check//


//   //32x
//   rho = 210;
//   theta = 0.6;
//   mu = 15;
//   TTree * wtagtree321 = GetOutputMetadataTree("WTagTree321");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen321", wtagtree321, rho, theta, mu) );
//   InitHistos();
  
//   rho = 210;
//   theta = 0.6;
//   mu = 20;
//   TTree * wtagtree322 = GetOutputMetadataTree("WTagTree322");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen322", wtagtree322, rho, theta, mu) );
//   InitHistos();
  
//   rho = 210;
//   theta = 0.6;
//   mu = 25;
//   TTree * wtagtree323 = GetOutputMetadataTree("WTagTree323");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen323", wtagtree323, rho, theta, mu) );
//   InitHistos();
//   //check


//   //33x
//   rho = 210;
//   theta = 0.7;
//   mu = 15;
//   TTree * wtagtree331 = GetOutputMetadataTree("WTagTree331");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen331", wtagtree331, rho, theta, mu) );
//   InitHistos();
  
//   rho = 210;
//   theta = 0.7;
//   mu = 20;
//   TTree * wtagtree332 = GetOutputMetadataTree("WTagTree332");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen332", wtagtree332, rho, theta, mu) );
//   InitHistos();
  
//   rho = 210;
//   theta = 0.7;
//   mu = 25;
//   TTree * wtagtree333 = GetOutputMetadataTree("WTagTree333");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen333", wtagtree333, rho, theta, mu) );
//   InitHistos();
//   //check
  
//   */

//   /*
//   //34x
//   rho = 210;
//   theta = 0.8;
//   mu = 15;
//   TTree * wtagtree341 = GetOutputMetadataTree("WTagTree341");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen341", wtagtree341, rho, theta, mu) );
//   InitHistos();
  
//   rho = 210;
//   theta = 0.8;
//   mu = 20;
//   TTree * wtagtree342 = GetOutputMetadataTree("WTagTree342");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen342", wtagtree342, rho, theta, mu) );
//   InitHistos();
  
//   rho = 210;
//   theta = 0.8;
//   mu = 25;
//   TTree * wtagtree343 = GetOutputMetadataTree("WTagTree343");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen343", wtagtree343, rho, theta, mu) );
//   InitHistos();

//   rho = 210;
//   theta = 0.8;
//   mu = 30;
//   TTree * wtagtree344 = GetOutputMetadataTree("WTagTree344");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen344", wtagtree344, rho, theta, mu) );
//   InitHistos();

//   rho = 210;
//   theta = 0.8;
//   mu = 35;
//   TTree * wtagtree345 = GetOutputMetadataTree("WTagTree345");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen345", wtagtree345, rho, theta, mu) );
//   InitHistos();
  
//   */



  



//   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//  ///////4xx//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  
  
//   //41x
//   rho = 220;
//   theta = 0.5;
//   mu = 15;
//   TTree * wtagtree411 = GetOutputMetadataTree("WTagTree411");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen411", wtagtree411, rho, theta, mu) );
//   InitHistos();
  
//   rho = 220;
//   theta = 0.5;
//   mu = 20;
//   TTree * wtagtree412 = GetOutputMetadataTree("WTagTree412");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen412", wtagtree412, rho, theta, mu) );
//   InitHistos();
  
//   rho = 220;
//   theta = 0.5;
//   mu = 25;
//   TTree * wtagtree413 = GetOutputMetadataTree("WTagTree413");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen413", wtagtree413, rho, theta, mu) );
//   InitHistos();
//   //check//


//   //42x
//   rho = 220;
//   theta = 0.6;
//   mu = 15;
//   TTree * wtagtree421 = GetOutputMetadataTree("WTagTree421");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen421", wtagtree421, rho, theta, mu) );
//   InitHistos();
  
//   rho = 220;
//   theta = 0.6;
//   mu = 20;
//   TTree * wtagtree422 = GetOutputMetadataTree("WTagTree422");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen422", wtagtree422, rho, theta, mu) );
//   InitHistos();
  
//   rho = 220;
//   theta = 0.6;
//   mu = 25;
//   TTree * wtagtree423 = GetOutputMetadataTree("WTagTree423");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen423", wtagtree423, rho, theta, mu) );
//   InitHistos();
//   //check


//   //43x
//   rho = 220;
//   theta = 0.7;
//   mu = 15;
//   TTree * wtagtree431 = GetOutputMetadataTree("WTagTree431");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen431", wtagtree431, rho, theta, mu) );
//   InitHistos();
  
//   rho = 220;
//   theta = 0.7;
//   mu = 20;
//   TTree * wtagtree432 = GetOutputMetadataTree("WTagTree432");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen432", wtagtree432, rho, theta, mu) );
//   InitHistos();
  
//   rho = 220;
//   theta = 0.7;
//   mu = 25;
//   TTree * wtagtree433 = GetOutputMetadataTree("WTagTree433");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen433", wtagtree433, rho, theta, mu) );
//   InitHistos();
//   //check

 

//   ////////ENDE4xx/////////////////////////////////////

 
//   ////////////////////33Mu/////////////////////////////
//   /*

//    rho = 210;
//    theta = 0.7;
//    mu = 5;
//   TTree * wtagtree33Mu5 = GetOutputMetadataTree("WTagTree33Mu5");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen33Mu5", wtagtree33Mu5, rho, theta, mu) );
//   InitHistos();
 

//    rho = 210;
//    theta = 0.7;
//    mu = 10;
//   TTree * wtagtree33Mu10 = GetOutputMetadataTree("WTagTree33Mu10");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen33Mu10", wtagtree33Mu10, rho, theta, mu) );
//   InitHistos();


//    rho = 210;
//    theta = 0.7;
//    mu = 15;
//   TTree * wtagtree33Mu15 = GetOutputMetadataTree("WTagTree33Mu15");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_gen33Mu15", wtagtree33Mu15, rho, theta, mu) );
//   InitHistos();

//   */
//   ////////////////////ENDE33Mu/////////////////////////////





//   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





//   /*
//   //constR
//   rho = 50000000000;
//   theta = 0.0;
//   mu = 20;
//   TTree * wtagtreeconstR = GetOutputMetadataTree("WTagTreeConstR");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_genConstR", wtagtreeconstR, rho, theta, mu) );
//   InitHistos();
//   */



 


  
//   /////RHO_150////////////////////////////////////////////////////////////
//   /*
//  //Rho150 == _1x
//   rho = 150;
//   theta = 0.5;
//   mu = 15;
//   TTree * wtagtreeRho150_11 = GetOutputMetadataTree("WTagTreeRho150_11");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_genRho150_11", wtagtreeRho150_11, rho, theta, mu) );
//   InitHistos();
//   */
//   /*
//   rho = 150;
//   theta = 0.5;
//   mu = 20;
//   TTree * wtagtreeRho150_12 = GetOutputMetadataTree("WTagTreeRho150_12");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_genRho150_12", wtagtreeRho150_12, rho, theta, mu) );
//   InitHistos();


//   rho = 150;
//   theta = 0.5;
//   mu = 25;
//   TTree * wtagtreeRho150_13 = GetOutputMetadataTree("WTagTreeRho150_13");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_genRho150_13", wtagtreeRho150_13, rho, theta, mu) );
//   InitHistos();



//  //Rho150 == _2x

//   rho = 150;
//   theta = 0.6;
//   mu = 15;
//   TTree * wtagtreeRho150_21 = GetOutputMetadataTree("WTagTreeRho150_21");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_genRho150_21", wtagtreeRho150_21, rho, theta, mu) );
//   InitHistos();
  
  
//   rho = 150;
//   theta = 0.6;
//   mu = 20;
//   TTree * wtagtreeRho150_22 = GetOutputMetadataTree("WTagTreeRho150_22");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_genRho150_22", wtagtreeRho150_22, rho, theta, mu) );
//   InitHistos();


//   rho = 150;
//   theta = 0.6;
//   mu = 25;
//   TTree * wtagtreeRho150_23 = GetOutputMetadataTree("WTagTreeRho150_23");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_genRho150_23", wtagtreeRho150_23, rho, theta, mu) );
//   InitHistos();


//  //Rho150 == _3x

//   rho = 150;
//   theta = 0.7;
//   mu = 15;
//   TTree * wtagtreeRho150_31 = GetOutputMetadataTree("WTagTreeRho150_31");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_genRho150_31", wtagtreeRho150_31, rho, theta, mu) );
//   InitHistos();
  
  
//   rho = 150;
//   theta = 0.7;
//   mu = 20;
//   TTree * wtagtreeRho150_32 = GetOutputMetadataTree("WTagTreeRho150_32");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_genRho150_32", wtagtreeRho150_32, rho, theta, mu) );
//   InitHistos();
//   */
//   /*

//   rho = 150;
//   theta = 0.7;
//   mu = 25;
//   TTree * wtagtreeRho150_33 = GetOutputMetadataTree("WTagTreeRho150_33");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_genRho150_33", wtagtreeRho150_33, rho, theta, mu) );
//   InitHistos();

//   */
//   ////////////////////ENDE RHO_150///////////////////////////////////
  


 

  
//  /////RHO_250////////////////////////////////////////////////////////////
//   /*
//  //Rho250 == _1x
//   rho = 250;
//   theta = 0.5;
//   mu = 15;
//   TTree * wtagtreeRho250_11 = GetOutputMetadataTree("WTagTreeRho250_11");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_genRho250_11", wtagtreeRho250_11, rho, theta, mu) );
//   InitHistos();
  
  
//   rho = 250;
//   theta = 0.5;
//   mu = 20;
//   TTree * wtagtreeRho250_12 = GetOutputMetadataTree("WTagTreeRho250_12");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_genRho250_12", wtagtreeRho250_12, rho, theta, mu) );
//   InitHistos();


//   rho = 250;
//   theta = 0.5;
//   mu = 25;
//   TTree * wtagtreeRho250_13 = GetOutputMetadataTree("WTagTreeRho250_13");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_genRho250_13", wtagtreeRho250_13, rho, theta, mu) );
//   InitHistos();



//  //Rho250 == _2x

//   rho = 250;
//   theta = 0.6;
//   mu = 15;
//   TTree * wtagtreeRho250_21 = GetOutputMetadataTree("WTagTreeRho250_21");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_genRho250_21", wtagtreeRho250_21, rho, theta, mu) );
//   InitHistos();
  
  
//   rho = 250;
//   theta = 0.6;
//   mu = 20;
//   TTree * wtagtreeRho250_22 = GetOutputMetadataTree("WTagTreeRho250_22");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_genRho250_22", wtagtreeRho250_22, rho, theta, mu) );
//   InitHistos();


//   rho = 250;
//   theta = 0.6;
//   mu = 25;
//   TTree * wtagtreeRho250_23 = GetOutputMetadataTree("WTagTreeRho250_23");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_genRho250_23", wtagtreeRho250_23, rho, theta, mu) );
//   InitHistos();


//  //Rho250 == _3x

//   rho = 250;
//   theta = 0.7;
//   mu = 15;
//   TTree * wtagtreeRho250_31 = GetOutputMetadataTree("WTagTreeRho250_31");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_genRho250_31", wtagtreeRho250_31, rho, theta, mu) );
//   InitHistos();
  
  
//   rho = 250;
//   theta = 0.7;
//   mu = 20;
//   TTree * wtagtreeRho250_32 = GetOutputMetadataTree("WTagTreeRho250_32");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_genRho250_32", wtagtreeRho250_32, rho, theta, mu) );
//   InitHistos();


//   rho = 250;
//   theta = 0.7;
//   mu = 25;
//   TTree * wtagtreeRho250_33 = GetOutputMetadataTree("WTagTreeRho250_33");
//   RegisterHistCollection( new TMVATreeFiller_hhtt_gen("WTagFiller_genRho250_33", wtagtreeRho250_33, rho, theta, mu) );
//   InitHistos();


//   ////////////////////ENDE RHO_250///////////////////////////////////
//   */ 






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



//   int rho;
//   double theta;
//   int mu;
//   int beta;
//   //////////////// 1xx


//   //11x.////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//   /*
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


//   */

//   /////2xx////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
//   /*

//   //21x
//   int rho = 200;
//   double theta = 0.5;
//   int mu = 15;
//   BaseHists* TreeFiller_gen211 = GetHistCollection("WTagFiller_gen211");
//   ((RocHists*)TreeFiller_gen211)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen211->Fill();
 
//   rho = 200;
//   theta = 0.5;
//   mu = 20;
//   BaseHists* TreeFiller_gen212 = GetHistCollection("WTagFiller_gen212");
//   ((RocHists*)TreeFiller_gen212)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen212->Fill();

//   rho = 200;
//   theta = 0.5;
//   mu = 25;
//   BaseHists* TreeFiller_gen213 = GetHistCollection("WTagFiller_gen213");
//   ((RocHists*)TreeFiller_gen213)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen213->Fill();
//   //check


//   //22x
//   rho = 200;
//   theta = 0.6;
//   mu = 15;
//   BaseHists* TreeFiller_gen221 = GetHistCollection("WTagFiller_gen221");
//   ((RocHists*)TreeFiller_gen221)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen221->Fill();
 
//   rho = 200;
//   theta = 0.6;
//   mu = 20;
//   BaseHists* TreeFiller_gen222 = GetHistCollection("WTagFiller_gen222");
//   ((RocHists*)TreeFiller_gen222)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen222->Fill();

//   rho = 200;
//   theta = 0.6;
//   mu = 25;
//   BaseHists* TreeFiller_gen223 = GetHistCollection("WTagFiller_gen223");
//   ((RocHists*)TreeFiller_gen223)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen223->Fill();
//   //check


//   //23x
//   rho = 200;
//   theta = 0.7;
//   mu = 15;
//   BaseHists* TreeFiller_gen231 = GetHistCollection("WTagFiller_gen231");
//   ((RocHists*)TreeFiller_gen231)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen231->Fill();
 
//   rho = 200;
//   theta = 0.7;
//   mu = 20;
//   BaseHists* TreeFiller_gen232 = GetHistCollection("WTagFiller_gen232");
//   ((RocHists*)TreeFiller_gen232)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen232->Fill();

//   rho = 200;
//   theta = 0.7;
//   mu = 25;
//   BaseHists* TreeFiller_gen233 = GetHistCollection("WTagFiller_gen233");
//   ((RocHists*)TreeFiller_gen233)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen233->Fill();
//   //check

//   */


//   ////3xx////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//   /*

//   //31x
//   int rho = 210;
//   double theta = 0.5;
//   int mu = 15;
//   BaseHists* TreeFiller_gen311 = GetHistCollection("WTagFiller_gen311");
//   ((RocHists*)TreeFiller_gen311)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen311->Fill();
 
//   rho = 210;
//   theta = 0.5;
//   mu = 20;
//   BaseHists* TreeFiller_gen312 = GetHistCollection("WTagFiller_gen312");
//   ((RocHists*)TreeFiller_gen312)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen312->Fill();

//   rho = 210;
//   theta = 0.5;
//   mu = 25;
//   BaseHists* TreeFiller_gen313 = GetHistCollection("WTagFiller_gen313");
//   ((RocHists*)TreeFiller_gen313)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen313->Fill();
//   //check


//   //32x
//   rho = 210;
//   theta = 0.6;
//   mu = 15;
//   BaseHists* TreeFiller_gen321 = GetHistCollection("WTagFiller_gen321");
//   ((RocHists*)TreeFiller_gen321)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen321->Fill();
 
//   rho = 210;
//   theta = 0.6;
//   mu = 20;
//   BaseHists* TreeFiller_gen322 = GetHistCollection("WTagFiller_gen322");
//   ((RocHists*)TreeFiller_gen322)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen322->Fill();

//   rho = 210;
//   theta = 0.6;
//   mu = 25;
//   BaseHists* TreeFiller_gen323 = GetHistCollection("WTagFiller_gen323");
//   ((RocHists*)TreeFiller_gen323)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen323->Fill();
//   //check


//   //33x
//   rho = 210;
//   theta = 0.7;
//   mu = 15;
//   BaseHists* TreeFiller_gen331 = GetHistCollection("WTagFiller_gen331");
//   ((RocHists*)TreeFiller_gen331)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen331->Fill();
 
//   rho = 210;
//   theta = 0.7;
//   mu = 20;
//   BaseHists* TreeFiller_gen332 = GetHistCollection("WTagFiller_gen332");
//   ((RocHists*)TreeFiller_gen332)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen332->Fill();

//   rho = 210;
//   theta = 0.7;
//   mu = 25;
//   BaseHists* TreeFiller_gen333 = GetHistCollection("WTagFiller_gen333");
//   ((RocHists*)TreeFiller_gen333)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen333->Fill();
  
//   */

  
  
//  ////////////////////////////////////////////////////////////////34x//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//   /*

//   rho = 210;
//   theta = 0.8;
//   mu = 15;
//   BaseHists* TreeFiller_gen341 = GetHistCollection("WTagFiller_gen341");
//   ((RocHists*)TreeFiller_gen341)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen341->Fill();
 
//   rho = 210;
//   theta = 0.8;
//   mu = 20;
//   BaseHists* TreeFiller_gen342 = GetHistCollection("WTagFiller_gen342");
//   ((RocHists*)TreeFiller_gen342)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen342->Fill();

//   rho = 210;
//   theta = 0.8;
//   mu = 25;
//   BaseHists* TreeFiller_gen343 = GetHistCollection("WTagFiller_gen343");
//   ((RocHists*)TreeFiller_gen343)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen343->Fill();

//   rho = 210;
//   theta = 0.8;
//   mu = 30;
//   BaseHists* TreeFiller_gen344 = GetHistCollection("WTagFiller_gen344");
//   ((RocHists*)TreeFiller_gen344)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen344->Fill();

//   rho = 210;
//   theta = 0.8;
//   mu = 35;
//   BaseHists* TreeFiller_gen345 = GetHistCollection("WTagFiller_gen345");
//   ((RocHists*)TreeFiller_gen345)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen345->Fill();

//   */

//  ////////////////////////////////////////////////////////////////ENDE34x//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  

//  ////4xx////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  

//   //41x
//   rho = 220;
//   theta = 0.5;
//   mu = 15;
//   BaseHists* TreeFiller_gen411 = GetHistCollection("WTagFiller_gen411");
//   ((RocHists*)TreeFiller_gen411)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen411->Fill();
 
//   rho = 220;
//   theta = 0.5;
//   mu = 20;
//   BaseHists* TreeFiller_gen412 = GetHistCollection("WTagFiller_gen412");
//   ((RocHists*)TreeFiller_gen412)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen412->Fill();

//   rho = 220;
//   theta = 0.5;
//   mu = 25;
//   BaseHists* TreeFiller_gen413 = GetHistCollection("WTagFiller_gen413");
//   ((RocHists*)TreeFiller_gen413)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen413->Fill();
//   //check


//   //42x
//   rho = 220;
//   theta = 0.6;
//   mu = 15;
//   BaseHists* TreeFiller_gen421 = GetHistCollection("WTagFiller_gen421");
//   ((RocHists*)TreeFiller_gen421)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen421->Fill();
 
//   rho = 220;
//   theta = 0.6;
//   mu = 20;
//   BaseHists* TreeFiller_gen422 = GetHistCollection("WTagFiller_gen422");
//   ((RocHists*)TreeFiller_gen422)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen422->Fill();

//   rho = 220;
//   theta = 0.6;
//   mu = 25;
//   BaseHists* TreeFiller_gen423 = GetHistCollection("WTagFiller_gen423");
//   ((RocHists*)TreeFiller_gen423)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen423->Fill();
//   //check


//   //43x
//   rho = 220;
//   theta = 0.7;
//   mu = 15;
//   BaseHists* TreeFiller_gen431 = GetHistCollection("WTagFiller_gen431");
//   ((RocHists*)TreeFiller_gen431)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen431->Fill();
 
//   rho = 220;
//   theta = 0.7;
//   mu = 20;
//   BaseHists* TreeFiller_gen432 = GetHistCollection("WTagFiller_gen432");
//   ((RocHists*)TreeFiller_gen432)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen432->Fill();

//   rho = 220;
//   theta = 0.7;
//   mu = 25;
//   BaseHists* TreeFiller_gen433 = GetHistCollection("WTagFiller_gen433");
//   ((RocHists*)TreeFiller_gen433)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen433->Fill();
//   //check
  
  
//   ////////////ENDE 4xx/////////////////
//   //////////////////33Mu///////////////////////
//   /*

//   rho = 210;
//   theta = 0.7;
//   mu = 5;
//   BaseHists* TreeFiller_gen33Mu5 = GetHistCollection("WTagFiller_gen33Mu5");
//   ((RocHists*)TreeFiller_gen33Mu5)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen33Mu5->Fill();

//   rho = 210;
//   theta = 0.7;
//   mu = 10;
//   BaseHists* TreeFiller_gen33Mu10 = GetHistCollection("WTagFiller_gen33Mu10");
//   ((RocHists*)TreeFiller_gen33Mu10)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen33Mu10->Fill();

//   rho = 210;
//   theta = 0.7;
//   mu = 15;
//   BaseHists* TreeFiller_gen33Mu15 = GetHistCollection("WTagFiller_gen33Mu15");
//   ((RocHists*)TreeFiller_gen33Mu15)->SetIdVersion(id.GetVersion());
//   TreeFiller_gen33Mu15->Fill();



//   */
//   //////////////////ENDE 33Mu///////////////////////












//   /////////////////////////////////////////////////////////////////////////////////////////////
  



//   /*
//   ////constR
//   rho = 50000000000;
//   theta = 0.0;
//   mu = 20;
//   BaseHists* TreeFiller_genconstR = GetHistCollection("WTagFiller_genConstR");
//   ((RocHists*)TreeFiller_genconstR)->SetIdVersion(id.GetVersion());
//   TreeFiller_genconstR->Fill();
//   */




//   /*
  
//   //RHO_150/////////////////////////////////////////////////
//   //Rho150_1x
//   rho = 150;
//   theta = 0.5;
//   mu = 15;
//   BaseHists* TreeFiller_genRho150_11 = GetHistCollection("WTagFiller_genRho150_11");
//   ((RocHists*)TreeFiller_genRho150_11)->SetIdVersion(id.GetVersion());
//   TreeFiller_genRho150_11->Fill();
//   */

//   /*
//   rho = 150;
//   theta = 0.5;
//   mu = 20;
//   BaseHists* TreeFiller_genRho150_12 = GetHistCollection("WTagFiller_genRho150_12");
//   ((RocHists*)TreeFiller_genRho150_12)->SetIdVersion(id.GetVersion());
//   TreeFiller_genRho150_12->Fill();

//   rho = 150;
//   theta = 0.5;
//   mu = 25;
//   BaseHists* TreeFiller_genRho150_13 = GetHistCollection("WTagFiller_genRho150_13");
//   ((RocHists*)TreeFiller_genRho150_13)->SetIdVersion(id.GetVersion());
//   TreeFiller_genRho150_13->Fill();


//   //Rho150_2x
//   rho = 150;
//   theta = 0.6;
//   mu = 15;
//   BaseHists* TreeFiller_genRho150_21 = GetHistCollection("WTagFiller_genRho150_21");
//   ((RocHists*)TreeFiller_genRho150_21)->SetIdVersion(id.GetVersion());
//   TreeFiller_genRho150_21->Fill();
 
//   rho = 150;
//   theta = 0.6;
//   mu = 20;
//   BaseHists* TreeFiller_genRho150_22 = GetHistCollection("WTagFiller_genRho150_22");
//   ((RocHists*)TreeFiller_genRho150_22)->SetIdVersion(id.GetVersion());
//   TreeFiller_genRho150_22->Fill();

//   rho = 150;
//   theta = 0.6;
//   mu = 25;
//   BaseHists* TreeFiller_genRho150_23 = GetHistCollection("WTagFiller_genRho150_23");
//   ((RocHists*)TreeFiller_genRho150_23)->SetIdVersion(id.GetVersion());
//   TreeFiller_genRho150_23->Fill();


//   //Rho150_3x
//   rho = 150;
//   theta = 0.7;
//   mu = 15;
//   BaseHists* TreeFiller_genRho150_31 = GetHistCollection("WTagFiller_genRho150_31");
//   ((RocHists*)TreeFiller_genRho150_31)->SetIdVersion(id.GetVersion());
//   TreeFiller_genRho150_31->Fill();
 
//   rho = 150;
//   theta = 0.7;
//   mu = 20;
//   BaseHists* TreeFiller_genRho150_32 = GetHistCollection("WTagFiller_genRho150_32");
//   ((RocHists*)TreeFiller_genRho150_32)->SetIdVersion(id.GetVersion());
//   TreeFiller_genRho150_32->Fill();

//   */

//   /*
//   rho = 150;
//   theta = 0.7;
//   mu = 25;
//   BaseHists* TreeFiller_genRho150_33 = GetHistCollection("WTagFiller_genRho150_33");
//   ((RocHists*)TreeFiller_genRho150_33)->SetIdVersion(id.GetVersion());
//   TreeFiller_genRho150_33->Fill();
//   */
//   /////////////////////ENDE RHO150////////////////

  

//   /*
//   //RHO_250/////////////////////////////////////////////////
//   //Rho250_1x
//   rho = 250;
//   theta = 0.5;
//   mu = 15;
//   BaseHists* TreeFiller_genRho250_11 = GetHistCollection("WTagFiller_genRho250_11");
//   ((RocHists*)TreeFiller_genRho250_11)->SetIdVersion(id.GetVersion());
//   TreeFiller_genRho250_11->Fill();
 
//   rho = 250;
//   theta = 0.5;
//   mu = 20;
//   BaseHists* TreeFiller_genRho250_12 = GetHistCollection("WTagFiller_genRho250_12");
//   ((RocHists*)TreeFiller_genRho250_12)->SetIdVersion(id.GetVersion());
//   TreeFiller_genRho250_12->Fill();

//   rho = 250;
//   theta = 0.5;
//   mu = 25;
//   BaseHists* TreeFiller_genRho250_13 = GetHistCollection("WTagFiller_genRho250_13");
//   ((RocHists*)TreeFiller_genRho250_13)->SetIdVersion(id.GetVersion());
//   TreeFiller_genRho250_13->Fill();


//   //Rho250_2x
//   rho = 250;
//   theta = 0.6;
//   mu = 15;
//   BaseHists* TreeFiller_genRho250_21 = GetHistCollection("WTagFiller_genRho250_21");
//   ((RocHists*)TreeFiller_genRho250_21)->SetIdVersion(id.GetVersion());
//   TreeFiller_genRho250_21->Fill();
 
//   rho = 250;
//   theta = 0.6;
//   mu = 20;
//   BaseHists* TreeFiller_genRho250_22 = GetHistCollection("WTagFiller_genRho250_22");
//   ((RocHists*)TreeFiller_genRho250_22)->SetIdVersion(id.GetVersion());
//   TreeFiller_genRho250_22->Fill();

//   rho = 250;
//   theta = 0.6;
//   mu = 25;
//   BaseHists* TreeFiller_genRho250_23 = GetHistCollection("WTagFiller_genRho250_23");
//   ((RocHists*)TreeFiller_genRho250_23)->SetIdVersion(id.GetVersion());
//   TreeFiller_genRho250_23->Fill();


//   //Rho250_3x
//   rho = 250;
//   theta = 0.7;
//   mu = 15;
//   BaseHists* TreeFiller_genRho250_31 = GetHistCollection("WTagFiller_genRho250_31");
//   ((RocHists*)TreeFiller_genRho250_31)->SetIdVersion(id.GetVersion());
//   TreeFiller_genRho250_31->Fill();
 
//   rho = 250;
//   theta = 0.7;
//   mu = 20;
//   BaseHists* TreeFiller_genRho250_32 = GetHistCollection("WTagFiller_genRho250_32");
//   ((RocHists*)TreeFiller_genRho250_32)->SetIdVersion(id.GetVersion());
//   TreeFiller_genRho250_32->Fill();

//   rho = 250;
//   theta = 0.7;
//   mu = 25;
//   BaseHists* TreeFiller_genRho250_33 = GetHistCollection("WTagFiller_genRho250_33");
//   ((RocHists*)TreeFiller_genRho250_33)->SetIdVersion(id.GetVersion());
//   TreeFiller_genRho250_33->Fill();
//   */



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

