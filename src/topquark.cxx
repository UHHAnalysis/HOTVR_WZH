#include "include/topquark.h"
#include <bitset>
#include <cmath>
#include <iostream>
#include <fstream>

namespace DES{
  
using std::cout;
using std::endl;
using std::max;
using std::bitset;
using std::abs;
using std::atan;

//////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// LRsets ////////////////////////////////////////////////
///////////////////////////////// 30 July 2013 DES ///////////////////////////////////////////

// This class divides the initial set into two subsets, setA and setB, in all possible ways
// such that setA U setB is the whole initial set.

// Constructor.  Use initial set passed to the constructor.
// Here set[0] is the length of the set.
LRsets::LRsets(int (&set)[maxsize+1])
{
  len = set[0];
  
  // countmax = int(pow(2,len)) - 1;
  countmax = 2;
  for (int i = 1; i < len; i++)
  {
    countmax *= 2;
  }
  countmax -= 1;
  
  count = 1;
  countend = false;

  for(int i = 1;i <= maxsize; i++)
  {
    if(i <= len) intset[i] = set[i];
    else intset[i] = 0;
  }
}

// Resets initial set according to set, as in constructor.
void LRsets::reset(int (&set)[maxsize+1])
{
  len = set[0];
  count = 1;
  countend = false;

  for(int i = 1;i <= maxsize; i++)
  {
    if(i <= len) intset[i] = set[i];
    else intset[i] = 0;
  }
}//end of reset

// Returns next division of set into setA and setB.
// Call 0 of s.next(setA,setB) gives setA = set, setB = {}.
// But we start with call 1, which gives nonempty sets (unless
// the starting set had only one element and thus no nontrivial subsets).
// Further calls give each subset of "set" for setA, the complement for setB.
// Call 2^N would return returns setA = {}, setB = set,
// but we end with call 2^(N-1), which returns sets A and B with countend = true.
// Further calls are in error and return countend = true, setA = setB = {}.

bool LRsets::next(int (&setA)[maxsize+1],int (&setB)[maxsize+1])
{
  for(int i = 0; i <= maxsize; i++)
  {
    setA[i] = 0;
    setB[i] = 0;
  }
  if(!countend)
  {
    int lenL,lenR;
    bitset<maxsize> b(count);       // Turns the count into a binary number

    lenL = 1;
    lenR = 1;

    for(int i = 0; i < len; i++)
    {
      if(b[i]==0)
      {
        setA[lenL] = intset[i+1];
        lenL++;
      }
      else
      {
        setB[lenR] = intset[i+1];
        lenR++;
      }
    }

    setA[0] = lenL - 1;
    setB[0] = lenR - 1;
      
    count++;
    if(count == countmax)
      countend = true;
    else
      countend = false;
    }
  else // If we are at the end of the splitting subsets, then return a set of length 0
  {
    setA[0] = 0;
    setB[0] = 0;
  }
      
  return countend;

}//end of LRsets.next

////////////////////////////////////// End LRSets ////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// fourvector /////////////////////////////////////////////
////////////////////////////////// (old code by DES) /////////////////////////////////////////

fourvector::fourvector()
// Default constructor, sets all values to 0
{
  for(int i = 0;i < 4; i++) vector[i] = 0;
}

// Constructor that sets vector v(i)=invec[i]
fourvector::fourvector(double invec[4])
{
  for(int i = 0; i < 4; i++) vector[i] = invec[i];
}

// Constructor that sets the vector v(i)=(t,x,y,z)
fourvector::fourvector(double t, double x, double y, double z)
{
  vector[0] = t;
  vector[1] = x;
  vector[2] = y;
  vector[3] = z;
}

// v.in(mu) for input, v.in(mu) = r
double& fourvector::in(const int& mu)
{
    return vector[mu];
}

// v(mu) for output,  r = v(mu)
const double fourvector::operator()(const int& mu) const
{
    return vector[mu];
}

// Sum of two vectors: v3 = v1 + v2
fourvector fourvector::operator+ (const fourvector& v2) const
{
  double hold[4];

  for(int i = 0; i < 4; i++) hold[i] = vector[i] + v2(i);

  return fourvector(hold);
}

// Difference of two vectors: v3 = v1 - v2
fourvector fourvector::operator- (const fourvector& v2) const
{
  double hold[4];

  for(int i = 0; i < 4; i++) hold[i] = vector[i] - v2(i);

  return fourvector(hold);
}

// Vector times scalar: v2 = v1*c
fourvector fourvector::operator* (const double& a) const
{
  double hold[4];

  for(int i = 0; i < 4; i++) hold[i] = vector[i]*a;

  return fourvector(hold);
}

// -1 times vector: v2 = - v1
fourvector fourvector::operator- () const
{
  double hold[4];

  for(int i = 0; i < 4; i++) hold[i] = -1.0*vector[i];

  return fourvector(hold);
}

// Scalar times vector: v2 = c*v1
fourvector operator*(const double& a, const fourvector& v)
{
  double hold[4];

  for(int i = 0;i < 4; i++) hold[i] = a*v(i);

  fourvector h(hold);

  return h;
}

// Dot product of two 4-vectors: dot(v1,v2)
double dot(const fourvector& v1, const fourvector& v2)
{
  double hold = 0;

  hold+=v1(0)*v2(0);

  for(int i = 1; i < 4; i++) hold -= v1(i)*v2(i);

  return hold;
}

// Square of one 4-vector: square(v) = dot(v,v)
double square(const fourvector& v)
{
  double hold = 0;

  hold += v(0)*v(0);

  for(int i = 1; i < 4; i++) hold -= v(i)*v(i);

  return hold;
}
///////////////////////////////////// End of fourvector //////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////   Dphi  ///////////////////////////////////////////////
///////////////////////////////// 30 June 2013 DES ///////////////////////////////////////////

// Calculates the difference between two phis and returns a value between -pi and pi.
double Dphi(const double& phi1, const double& phi2)
{
  double deltaphi = 0;
  parameters para;
  
  // Beware! We could have dummy values for phi1 or phi2.
  if ((abs(phi1) > 7.0) || (abs(phi2) > 7.0)) return para.verybig;
  
  deltaphi = phi1 - phi2;

  while (deltaphi > para.pi)   deltaphi -= 2.0*para.pi;
  while (deltaphi < - para.pi) deltaphi += 2.0*para.pi;
  return deltaphi;
}
/////////////////////////////////////// End of Dphi //////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// microjet ///////////////////////////////////////////////
///////////////////////////////// 17 June 2013 DES ///////////////////////////////////////////

// Default constructor which sets p to (0,0,0,0) and btag to 0
microjet::microjet()
{
  fourvector hold(0.0,0.0,0.0,0.0);
  p = hold;
  btag = 0;
}

// Constructor that sets p to pinit and btag to 0
microjet::microjet(fourvector pinit)
{
    p=pinit;
    btag = 0;
}

// Constructor that sets p to (t,x,y,z) and btag to 0
microjet::microjet(double t, double x, double y, double z)
{
    fourvector hold(t,x,y,z);
    p = hold;
    btag = 0;
}

// Constructor that sets btag to btinit and p to invec (with invec[0]=t,...)
microjet::microjet(double invec[4])
{
    fourvector hold(invec);
    p = hold;
    btag = 0;
}

///////////////////////////////////// End of microjet ////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// jetdata ////////////////////////////////////////////////
///////////////////////////////// 19 June 2013 DES ///////////////////////////////////////////

// Constructor for first call of jetdata.
// Sets mList to given mstart and sets total momentum,
// kT, kTsq, psq, y, and phi of the jet, with no flavor.
// No mother and no color connected partners.
// The parton masses all vanish.
jetdata::jetdata(const microjet *mList0, int length)
{
  mList = mList0;
  fourvector zerop(0.0,0.0,0.0,0.0);
  p = zerop;
  for(int i = 0; i < length; i++)
  {
    p = p + mList[i].p;
  }
  for(int i = 1;i <= maxsize; i++) set[i] = 0;
  set[0] = length;
  for(int i = 1; i <= set[0]; i++) set[i] = i - 1;
  
  for (int mu = 0; mu <= 3; mu++) pmother.in(mu) = 0.0;
  parameters para;
  f = none;          // flavor
  yccL=para.verybig;
  phiccL=para.verybig;
  yccR=para.verybig;
  phiccR=para.verybig;
  kappaK = para.verybig;
	m    = 0.0;
  mccL = 0.0;
	mccR = 0.0;
  kTccL=para.verybig;
	kTccR=para.verybig;
  bdescendants = false;
  firstgluon = false;
  SetParams();        // Calculates kT, kTsq, psq, y, and phi
}

// Initializes a jetdata object for a daughter jet.
// The jet data in jK has everything about the mother jet.
// The set s1 tells us what to include in the new jet.
// This does not set data about the color connected partners
// or about masses or the jet flavor.
jetdata::jetdata(jetdata jK, int s1[maxsize+1])
{
  mList = jK.mList;
  fourvector zerop(0.0,0.0,0.0,0.0);
  p = zerop;
  for(int i = 1; i <= maxsize; i++) set[i] = 0;
  set[0] = s1[0];
  for(int i = 1; i <= s1[0];i++)
  {
    set[i] = s1[i];
    p = p + mList[set[i]].p;
  }
  pmother = jK.p;

  parameters para;
  yccL   = para.verybig;
  phiccL = para.verybig;
  yccR   = para.verybig;
  phiccR = para.verybig;
  kappaK = abs(jK.psq - pow2(jK.m))/jK.kT; // Set kappaK from its definition.
  m    = 0.0;
  mccL = 0.0;
	mccR = 0.0;
  kTccL=para.verybig;
	kTccR=para.verybig;
  bdescendants = jK.bdescendants;
  firstgluon = false;
  SetParams();       // Calculates kT, kTsq, psq, y, and phi.
}

void jetdata::SetParams()   // Calculates kT, kTsq, psq, y, and phi.
{
  kTsq = pow2(p(1))+pow2(p(2));
  kT   = sqrt(kTsq);
  psq  = pow2(p(0))-pow2(p(3))-kTsq;
  y    = 0.5*log((p(0)+p(3))/(p(0)-p(3)));
  phi  = atan2(p(1),p(2));
}
///////////////////////////////////// End of jetdata ///////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// parameters /////////////////////////////////////////////
///////////////////////////////// 12 July 2013 DES ///////////////////////////////////////////

// Default (and only) constructor.
parameters::parameters()
{
  pi      = 3.141592653589793;  // Pi
  big     = 1.0e10;
  verybig = 1.0e11;
  tiny    = 1.0e-10;

  massW = 79;              //80.403 Mass of W-boson
  massWsq = pow2(massW);
  massTop = 160;             //172.3 Mass of top quark
  massTopsq = pow2(massTop);
  double NBreitWigner = 2.0;
  double Wwindow = 12.0; //changed from 10 to 12
  double Topwindow = 25.0;//changed from 25 to 40
  // Effective width of W-boson  GammaW=10.621867343258337;
  GammaW = (pow2(massW + Wwindow) - massWsq)/NBreitWigner/massW;
  // Effective width of top quark GammaT=26.793915040183688;
  GammaTop = (pow2(massTop + Topwindow) - massTopsq)/NBreitWigner/massTop;
  // Cutoff parameters
	DeltaTop = NBreitWigner*GammaTop;  // Approximately 2 * Twindow
	DeltaW = NBreitWigner*GammaW;      // Approximately 2 * Window
  // Parameter for Sudakov:
  ArcTanTop = atan(DeltaTop/GammaTop);
  ArcTanW = atan(DeltaW/GammaW);
    
  asMZ  = 0.118;            // Strong coupling alpha_s at Z mass.
  massZ = 91.1876;          // Mass of Z-boson (for alpha_s)
  
  cA = 3.0;
  cF = 4.0/3.0;
  TR = 1.0/2.0;
  Nf = 5;
  b0 = (33.0 - double(2*Nf))/(12.0*pi);
  
  Rfatjet   = 1.5;//changed from 1.0 to 0.8
  Rfatjetsq = pow2(Rfatjet);
  pTmin     = 200.0;         // Smallest pT of top quark allowed. changed from 400 to 200
  
  npdfg     = 2.0;  // Power from pdfs for hard scattering.
  npdfT     = 2.0;  // Power from pdfs for hard scattering.
  kappapsq  = 4.0;  // Cutoff parameter for IS radiation.
  kappanpsq = 4.0;  // Scale parameter for non-perturbative IS radiation.
  cR        = 2.0;  // Scale parameter for IS radiation.
  nR        = 1.0;  // Denominator power for IS radiation.
  cnp       = 1.0;  // Coefficient for non-perturbative IS radiation.
  nnp       = 1.5;  // Denominator power for non-perturbative IS radiation.

  // Parameters for b-tagging, if desired.
  pTtagcut  = 15.0; //15
  PTb       = 0.6;
  PTnotb    = 0.02;
  
  // Whether to report how many splittings were calculated.
  // Beware: setting this to true produces a lot of output.
  reportcounts = false;
}

// Alpha_s as a function of the scale.
double alphas(double Qsq)
{
    parameters para;
    double hold,MZsq;
    MZsq=pow2(para.massZ);
    hold=para.asMZ/(1.0+para.asMZ*para.b0*log(abs(Qsq)/MZsq));

    return hold;
}

/////////////////////////////////// End of parameters ////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////// Chi //////////////////////////////////////////////////
///////////////////////////////// 1 August 2013 DES //////////////////////////////////////////

// Returns the observable Chi for an initial list of microjets.
// Also reports Psignal and Pbackground that it found.
double Chi(microjet inMjet[maxsize],int length, double &Psignal, double &Pbackground,
           fourvector& pTop)
{
  double chireturn = 0.0;
  if (length < 3)
  {
    Psignal = 0.0;     // Need at least 3 microjets to have a top quark signal.
    Pbackground = 1.0; // Don't calculate it if we don't need it.
    return chireturn;
  }
  fourvector pDummy;
  parameters para;
  jetdata jInit(inMjet,length);  // Create starting jetdata object, using pointer to inMjet.
  if (para.reportcounts) cout << endl << "Calculate Signal." << endl;
  Psignal = ModelProbability(jInit, Signal, pTop);
  if (para.reportcounts) cout << "Calculate Background." << endl;
  if (Psignal > 0) Pbackground = ModelProbability(jInit, Background, pDummy);
  else Pbackground = 1.0; // Don't calculate it if we don't need it.
  chireturn = Psignal/Pbackground;

  return chireturn;
}
//////////////////////////////////// End of Chi //////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// ModelProbability ///////////////////////////////////////////
///////////////////////////////// 15 July 2013 DES ///////////////////////////////////////////

// Returns the probability for microjets jJ assuming themodel (Signal or Background).
double ModelProbability(const jetdata& jJ, const model& themodel, fourvector& pHard)
{
  int INset[maxsize+1],sIS[maxsize+1],sHard[maxsize+1];
  double probability = 0.0;
  double probabilityIS = 0.0;
  double probabilityHard = 0.0;
  double cfactor = 0.0;
  parameters para;
  
  double Qsq = jJ.kTsq + jJ.psq;
  for(int i = 0; i <= maxsize; i++) INset[i] = jJ.set[i];
  for (int mu = 0; mu < 4; mu++) pHard.in(mu) = 0.0;   // We initialize pTop to zero.
  LRsets LR1(INset);
  
  //While loop for splitting the inital set of jets into a hard and initial state sets
  bool NoMoreSplits = false;
  bool FirstSplit = true;
  while (!NoMoreSplits)
  {
    //sIS is the set of initial state microjets and
    //sHard is the set of microjets in the hard jet
    if (FirstSplit)
    {
      for (int i = 0; i <= maxsize; i++)
      {
        sIS[i] = 0;          // Empty set.
        sHard[i] = INset[i]; // The complete starting set.
      }
      FirstSplit = false;
      NoMoreSplits = false;
    }
    else NoMoreSplits = LR1.next(sIS,sHard);
    
    jetdata jHard(jJ,sHard);
    
    if (themodel == Signal)
    {
      jHard.f = top;
      jHard.m = para.massTop;
      jHard.kappaK = 2.0*(jHard.kTsq + para.massTopsq)/jHard.kT; // Starting value.
      double temp = (pow2(para.pTmin) + para.massTopsq)/(jHard.kTsq + para.massTopsq);
      cfactor = para.npdfT/(jHard.kTsq + para.massTopsq)*pow(temp, para.npdfT);
    }
    else if (themodel == Background)
    {
      jHard.f = gluon;
      jHard.firstgluon = true;
      jHard.m = 0.0;
      jHard.kappaK = 2.0*jHard.kT;    // Starting value.
      cfactor = para.npdfg/jHard.kTsq
                *pow(pow2(para.pTmin)/jHard.kTsq, para.npdfg);
    }
    else cout << "Error in ModelProbability: themodel is " << themodel << endl;
    jHard.bdescendants = false;
    
    // Use the cut pHsq < kTsqH for background, but not signal. (Why?)
    bool psqHOK = true;
    if (themodel == Background && jHard.psq > jHard.kTsq) psqHOK = false;

    if (sIS[0] == 0) // The IS set is empty.
    {
      probabilityIS = 1.0;
      if (psqHOK)
      {
        probabilityHard = SplitJet(jHard);
      }
      else
      {
        probabilityHard = 0.0;
      }
    }
    else // The IS set is not empty.
    {
      jetdata jIS(jJ,sIS);
      jIS.f = none;
      jIS.m = 0;
      jIS.kappaK = para.verybig;
      jIS.bdescendants = false;
      
      if(jIS.kTsq < Qsq/4.0 && psqHOK) //Kinematic checks
      {
        probabilityIS = InitStateRad(jIS, Qsq);
        probabilityHard = SplitJet(jHard);
      }
      else
      {
        probabilityIS = 0;
        probabilityHard = 0;
        cfactor = 0.0;
      }
    }//End of else for non-empty initial state radiation
    double weight = probabilityIS*probabilityHard*cfactor;
    pHard = pHard + weight*jHard.p; // jHard.p is the momentum of the starting hard parton.
    probability += weight; // So at the end, probability is the sum of the weights.
  }//End of while loop through possible combinations of Hard and IS radiation
  pHard = (1.0/probability)*pHard; // This gives the average of the hard parton momenta.
	return probability;
}
/////////////////////////////// End of ModelProbability //////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// InitStateRad /////////////////////////////////////////////
///////////////////////////////// 17 August 2013 DES /////////////////////////////////////////

//Returns probability for initial state radiation.
double InitStateRad(const jetdata& jJ, double& Qsq)
{
  double Q = sqrt(Qsq);
  int sL[maxsize+1],sR[maxsize+1];
  bool NoMoreSplits = false;
  parameters para;

  // The set sJ is just the parton index set for jJ.
  int sJ[maxsize+1];
  for(int i = 0; i<= maxsize; i++) sJ[i] = jJ.set[i];
  
  LRsets LR1(sJ);
  
  double prob = 0.0; // The result to be returned.
  
  // Loop for generating all possible decompositions of sJ into sL and sR.
  // We need to include the case that sL is empty.

  NoMoreSplits = false;
  bool FirstSplit = true;
  while(!NoMoreSplits)
  {
    // sL is the set to be divided into further IS emissions and
    // sR is the set of microjets from an IS gluon emission
    if (FirstSplit)
    {
      for (int i = 0; i <= maxsize; i++)
      {
        sL[i] = 0;           // Empty set.
        sR[i] = sJ[i];       // The complete starting set.
      }
      FirstSplit = false;
      NoMoreSplits = false;
      if (sJ[0] == 1) NoMoreSplits = true;
    }
    else NoMoreSplits = LR1.next(sL,sR);
    
    if (sL[0] > 0)
    {
      if (sR[1] > sL[1]) continue;
    }
    // The ordering of the initial state emitted gluons is irrelevant so
    // we want to include each ordering only once. We do that by ordering
    // them right to left according to increasing values of the smallest
    // index of microjets in the sets. Assuming that the initial index
    // set is {0,1,2,3,...}, the subsequent subsets all have increasing
    // index values. Thus sR[1] is the lowest index value in sR and sL[1]
    // is the lowest index value in sL. Therefore we simply compare sR[1]
    // to sL[1] to see if we have a split that we want to keep.
    
    jetdata jR(jJ,sR); // Create R jet.

    jR.f = gluon;
    jR.m = 0.0;
    jR.bdescendants = false;
    jR.firstgluon = true;

    jR.yccL = para.verybig;
    jR.phiccL = para.verybig;
    jR.yccR = para.verybig;
    jR.phiccR = para.verybig;
    jR.kappaK = 2.0 * jR.kT;  // Starting value.
    jR.mccL = 0.0;
    jR.mccR = 0.0;
    jR.kTccL = para.verybig;
    jR.kTccR = para.verybig;
        
    double h = 0.0;
    if (jR.psq < jR.kTsq) // Required for an allowed IS emission.
    {
      h = 8.0 * para.pi * para.cA * alphas(jR.kTsq+para.kappapsq);
      h /= (jR.kTsq+para.kappapsq);
      h /= pow(1 + para.cR * jR.kT/Q, para.nR);
      h += 16.0 * para.pi * para.cnp * pow(para.kappanpsq, para.nnp - 1.0)
          /pow(jR.kTsq + para.kappanpsq, para.nnp);
      // Multiply by the splitting factor h and the probability for further
      // splitting of the jL partons.
      h *= SplitJet(jR);
      if (sL[0] > 0 && h > 0.0) // Non-empty sL and nonzero h so far.
      {
        jetdata jL(jJ,sL);  // Create L jet.
        jL.f = none;
        jL.m = 0;
        jL.kappaK = para.verybig;
        jL.bdescendants = false;

        h *= InitStateRad(jL, Qsq);
      }
    }
    prob += h;
    } // End of while(!NoMoreSplits).
  return prob;  
}
///////////////////////////////// End of InitStateRad ////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// SplitJet ///////////////////////////////////////////////
///////////////////////////////// 17 August 2013 DES /////////////////////////////////////////

//Splits the final state jet given to it and returns the probability.
double SplitJet(const jetdata& jJ)
{
  int sL[maxsize+1],sR[maxsize+1];
  bool EndofSets;
  parameters para;

  double sudakov = Sudakov(jJ);
  
  // The set sJ is just the parton index set for jJ.
  int sJ[maxsize+1];
  for(int i = 0; i<= maxsize; i++) sJ[i] = jJ.set[i];
  
  double splitresult = 0.0;  // To be returned;
  
  // If there is only one parton in the jet and it is not a top quark or W-boson,
  // we just return the probability as given by the Sudakov factor. If it is a
  // top or W-boson, we have made a mistake because it should have decayed. Return 0.
  if (sJ[0] == 1)
  {
    if (jJ.f == Wplus || jJ.f == top) return 0.0;
    // else
    splitresult = exp(- sudakov);
    return splitresult;
  }
  // Now we know that there are two or more constituents in the jet, so we need
  // either a splitting or a decay. We need a loop over possible splittings.
  LRsets LRsets(sJ);
  EndofSets = false;
  while (!EndofSets)
  {
    EndofSets = LRsets.next(sL,sR); // Generate sets sL and sR.
    
    if (jJ.firstgluon && sL[1] < sR[1]) continue;
    // Just use half of the set splits; we then multiply by two below.
    
    jetdata jL(jJ,sL);              // Create L and R jets.
    jetdata jR(jJ,sR);
    // Now look for decays.
    if (jJ.f == top)  // Decay of a top quark.
    {
      double absmuJsq = abs(jJ.psq - para.massTopsq);
      double absmuRsq = abs(jR.psq - pow2(para.massW));
      if (absmuJsq < para.massTop*para.DeltaTop && absmuRsq < para.massW*para.DeltaW)
      { // Top decay is OK, so we do it.
        jL.f = quark;
        jL.m = 0.0;
        jL.mccR = para.massTop;
        jL.kTccR = jJ.kT;
        jL.yccR = jJ.y;
        jL.phiccR = jJ.phi;
        jL.kappaK = 2.0 * (para.massTopsq - para.massWsq)/jJ.kT;
        jL.bdescendants = true;  // The b-quark. Its descendants will inherit this tag.
        jR.f = Wplus;
        jR.m = para.massW;
        
        double decayfactor = exp(- sudakov);
        decayfactor *= 8.0*para.pi*para.massTopsq/(para.massTopsq - para.massWsq);
        decayfactor *= para.pi*para.massTop*para.GammaTop;
        decayfactor /= atan(absmuJsq/para.massTop/para.GammaTop);
        decayfactor /= pow2(absmuJsq) + para.massTopsq*pow2(para.GammaTop);
        
        // Now set h = decayfactor*SplitJet(jL,iL)*SplitJet(jR,iR);
        // but if one factor vanishes, we don't calculate the other.
        // Start with the factor that should be quickest to calculate.
        double h = decayfactor;
        if (jL.set[0] < jR.set[0])
        {
          h *= SplitJet(jL);
          if (h > 0.0) h *= SplitJet(jR);
        }
        else
        {
          h *= SplitJet(jR);
          if (h > 0.0) h *= SplitJet(jL);
        }
        splitresult += h;
      }
    } // Done with decay of top quark.
    else if (jJ.f == Wplus)   // Decay of a W-boson.
    {
      // The decay kinematics for the W were guaranteed to be OK when
      // we generated the top decay to W + quark, so we can just do the splitting.
      jL.f = quark;
      jL.kTccR = jR.kT;
      jL.yccR = jR.y;
      jL.phiccR = jR.phi;
      jL.kappaK = 2*para.massWsq/jJ.kT;
      jR.f = qbar;
      jR.kTccL = jL.kT;
      jR.yccL = jL.y;
      jR.phiccL = jL.phi;
      jR.kappaK = 2*para.massWsq/jJ.kT;

      double absmuJsq = abs(jJ.psq - para.massWsq);
      // We don't need a Sudakov factor for this case.
      double h = 8.0*pow2(para.pi)*para.massW*para.GammaW;
      h /= para.ArcTanW;
      h /= pow2(absmuJsq) + para.massWsq*pow2(para.GammaW);
      double anglefactor = 12.0*dot(jJ.pmother, jR.p)*square(jJ.pmother - jR.p);
      anglefactor /= (para.massTopsq - para.massWsq)*(para.massTopsq + 2.0 * para.massWsq);
      h *= anglefactor;
      // Now set h *= SplitJet(jL,iL)*SplitJet(jR,iR);
      // but if one factor vanishes, we don't calculate the other.
      // Start with the factor that should be quickest to calculate.
      if (jL.set[0] < jR.set[0])
      {
        h *= SplitJet(jL);
        if (h > 0.0) h *= SplitJet(jR);
      }
      else
      {
        h *= SplitJet(jR);
        if (h > 0.0) h *= SplitJet(jL);
      }
      splitresult += h;
    } // Done with decay of W-boson.
    // Done with decays, now do splittings.
    // Splitting is OK only if the hardness of the daughters is small enough.
    // For a top splitting, we also need jJ.psq to be not too small, else
    // the descendant top quark will not be allowed to decay.
    bool splittingOK = false;
    if (jJ.f == top)
         splittingOK = (2.0*abs(jL.psq - para.massTopsq)/jL.kT
                          < (jJ.psq - para.massTopsq)/jJ.kT &&
                        2.0*jR.psq/jR.kT < (jJ.psq - para.massTopsq)/jJ.kT) &&
                        para.massTop*para.DeltaTop < jJ.psq;
    else splittingOK = (2.0*jL.psq/jL.kT < jJ.psq/jJ.kT &&
                        2.0*jR.psq/jR.kT < jJ.psq/jJ.kT);
    
    if (splittingOK)
    {
      if (jJ.f == gluon)
      {
        // First case: g -> g + g.
        {
          jL.f = gluon;
          jL.yccL = jJ.yccL;
          jL.phiccL = jJ.phiccL;
          jL.kTccL = jJ.kTccL;
          jL.mccL = jJ.mccL;
          jL.yccR = jR.y;
          jL.phiccR = jR.phi;
          jL.kTccR = jR.kT;
          
          jR.f = gluon;
          jR.yccL = jL.y;
          jR.phiccL = jL.phi;
          jR.kTccL = jL.kT;
          jR.yccR = jJ.yccR;
          jR.phiccR = jJ.phiccR;
          jR.kTccR = jJ.kTccR;
          jR.mccR = jJ.mccR;
          
          double z1mz = jL.kT*jR.kT/jJ.kTsq;
          double h = 8.0*para.pi*para.cA*alphas(jJ.psq)/jJ.psq;
          if (jJ.firstgluon) h *= 2.0; // We only used half the splits.
          h *= pow2(1 - z1mz)/z1mz;
          h *= anglefactor(jL, jR, jJ);
          h *= exp(- sudakov);
          // Now set h *= SplitJet(jL,iL)*SplitJet(jR,iR);
          // but if one factor vanishes, we don't calculate the other.
          // Start with the factor that should be quickest to calculate.
          if (jL.set[0] < jR.set[0])
          {
            h *= SplitJet(jL);
            if (h > 0.0) h *= SplitJet(jR);
          }
          else
          {
            h *= SplitJet(jR);
            if (h > 0.0) h *= SplitJet(jL);
          }
          splitresult += h;
        }
        
        // Second case: g -> q + qbar.
        {
          jL.f = qbar;
          jL.yccL = jJ.yccL;
          jL.phiccL = jJ.phiccL;
          jL.kTccL = jJ.kTccL;
          jL.mccL = jJ.mccL;
          
          jR.f = quark;
          jR.yccR = jJ.yccR;
          jR.phiccR = jJ.phiccR;
          jR.kTccR = jJ.kTccR;
          jR.mccR = jJ.mccR;
          
          double zsq = jR.kTsq/jJ.kTsq;
          double onemzsq = jL.kTsq/jJ.kTsq;
          double h = 8.0*para.pi*para.TR*alphas(jJ.psq)/jJ.psq;
          if (jJ.firstgluon) h *= 2.0; // We only used half the splits.
          h *= zsq + onemzsq;
          h *= exp(- sudakov);
          h *= para.Nf;
          // Now set h *= SplitJet(jL,iL)*SplitJet(jR,iR);
          // but if one factor vanishes, we don't calculate the other.
          // Start with the factor that should be quickest to calculate.
          if (jL.set[0] < jR.set[0])
          {
            h *= SplitJet(jL);
            if (h > 0.0) h *= SplitJet(jR);
          }
          else
          {
            h *= SplitJet(jR);
            if (h > 0.0) h *= SplitJet(jL);
          }
          splitresult += h;
        }
      } // End if (jJ.f == gluon).
      else if(jJ.f == quark)
      {
        jL.f = quark;
        jL.yccR = jR.y;
        jL.phiccR = jR.phi;
        jL.kTccR = jR.kT;

        jR.f = gluon;
        jR.yccL = jL.y;
        jR.phiccL = jL.phi;
        jR.kTccL = jL.kT;
        jR.yccR = jJ.yccR;
        jR.phiccR = jJ.phiccR;
        jR.kTccR = jJ.kTccR;
        jR.mccR = jJ.mccR;

        double onemz = jR.kT/jJ.kT;
        double zsq = jL.kTsq/jJ.kTsq;
        double h = 8.0*para.pi*para.cF*alphas(jJ.psq)/jJ.psq;
        h *= (1.0 + zsq)/onemz;
        h *= anglefactor(jL, jR, jJ);
        h *= exp(- sudakov);
        // Now set h *= SplitJet(jL,iL)*SplitJet(jR,iR);
        // but if one factor vanishes, we don't calculate the other.
        // Start with the factor that should be quickest to calculate.
        if (jL.set[0] < jR.set[0])
        {
          h *= SplitJet(jL);
          if (h > 0.0) h *= SplitJet(jR);
        }
        else
        {
          h *= SplitJet(jR);
          if (h > 0.0) h *= SplitJet(jL);
        }
        splitresult += h;
      } // End else if(jJ.f == quark).
      else if(jJ.f == qbar)
      {
        jL.f = gluon;
        jL.yccL = jJ.yccL;
        jL.phiccL = jJ.phiccL;
        jL.kTccL = jJ.kTccL;
        jL.mccL = jJ.mccL;
        jL.yccR = jR.y;
        jL.phiccR = jR.phi;
        jL.kTccR = jR.kT;
        
        jR.f = qbar;
        jR.yccL = jL.y;
        jR.phiccL = jL.phi;
        jR.kTccL = jL.kT;

        double onemz = jL.kT/jJ.kT;
        double zsq = jR.kTsq/jJ.kTsq;
        double h = 8.0*para.pi*para.cF*alphas(jJ.psq)/jJ.psq;
        h *= (1.0 + zsq)/onemz;
        h *= anglefactor(jL, jR, jJ);
        h *= exp(- sudakov);
        // Now set h *= SplitJet(jL,iL)*SplitJet(jR,iR);
        // but if one factor vanishes, we don't calculate the other.
        // Start with the factor that should be quickest to calculate.
        if (jL.set[0] < jR.set[0])
        {
          h *= SplitJet(jL);
          if (h > 0.0) h *= SplitJet(jR);
        }
        else
        {
          h *= SplitJet(jR);
          if (h > 0.0) h *= SplitJet(jL);
        }
        splitresult += h;
      } // End else if(jJ.f == qbar).
      else if(jJ.f == top)
      {
        jL.f = top;
        jL.m = para.massTop;
        jL.yccR = jR.y;
        jL.phiccR = jR.phi;
        jL.kTccR = jR.kT;
        
        jR.f = gluon;
        jR.yccL = jL.y;
        jR.phiccL = jL.phi;
        jR.kTccL = jL.kT;
        jR.mccL = para.massTop;
        jR.yccR = jJ.yccR;
        jR.phiccR = jJ.phiccR;
        jR.kTccR = jJ.kTccR;
        jR.mccR = jJ.mccR;
        
        double onemz = jR.kT/jJ.kT;
        double zsq = jL.kTsq/jJ.kTsq;
        double muJsq = jJ.psq - para.massTopsq;
        // Note that the splittingOK condition requires that muJsq > 0.
        double h = 8.0*para.pi*para.cF*alphas(muJsq)/muJsq;
        h *= (1.0 + zsq)/onemz;
        h *= anglefactor(jL, jR, jJ);
        h *= exp(- sudakov);
        // Now set h *= SplitJet(jL,iL)*SplitJet(jR,iR);
        // but if one factor vanishes, we don't calculate the other.
        // Start with the factor that should be quickest to calculate.
        if (jL.set[0] < jR.set[0])
        {
          h *= SplitJet(jL);
          if (h > 0.0) h *= SplitJet(jR);
        }
        else
        {
          h *= SplitJet(jR);
          if (h > 0.0) h *= SplitJet(jL);
        }
        splitresult += h;
      } // End else if(jJ.f == top).
      // Other flavors, like W, do not split.
    } // End if (splittingOK).
  } // End of loop over LR sets.
  return splitresult;
}
///////////////////////////////////// End of SplitJet ////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Sudakov  ///////////////////////////////////////////////
///////////////////////////////// 25 August 2013 DES /////////////////////////////////////////

// Returns the Sudakov exponent.
double Sudakov(const jetdata& jJ)
{
  double sudakov = 0.0;
  parameters para;

  double sIL = 0.0; // Starting value for left part of the Sudakov exponent.
  double sIR = 0.0; // Starting value for right part of the Sudakov exponent.
  
  double asmujetsq;
  if (jJ.f != top) asmujetsq = alphas(jJ.psq);
  else asmujetsq = alphas(abs(jJ.psq - para.massTopsq));
  double mumaxsq = jJ.kT*jJ.kappaK/2.0;
  double asmumaxsq = alphas(mumaxsq);
  
  // Almost everything is the same for quarks, antiquarks, and gluons
  // except that gluons have both left and right parts of the Sudakov exponent
  // and two constants, which we can call color factor and splitting term,
  // are different.
  double colorfactor, splittingterm;
  if (jJ.f == gluon)
  {
    colorfactor = para.cA/2.0;
    splittingterm = 11.0/12.0 - log(2.0);
  }
  else // Flavor is quark or antiquark.
  {
    colorfactor = para.cF;
    splittingterm = 3.0/4.0;
  }

  // Left part of the Sudakov exponent.
  if (jJ.f == gluon || jJ.f == qbar)
  {
    double rhoccL = pow2(jJ.mccL/jJ.kTccL);
    
    double thetakLsq;
    if (abs(jJ.yccL) < para.big)
    {
      thetakLsq = pow2(jJ.yccL - jJ.y) + pow2(Dphi(jJ.phiccL, jJ.phi));
    }
    else thetakLsq = para.Rfatjetsq; // No color connected partner.
    
    double paramAL = pow2(rhoccL + thetakLsq)/(2.0*rhoccL + thetakLsq);
    double paramBL = 0.0;
    if (rhoccL > 0.0)
    {
      paramBL = rhoccL/(rhoccL + thetakLsq);
      paramBL *= log(rhoccL/(2.0*rhoccL + thetakLsq));
    }
    // Change parameters in case the right cc partner is the top antiquark before decay.
    // We don't include anti-tops at the moment, so this is not really needed.
    if (jJ.bdescendants && jJ.mccL > para.tiny) {
      paramAL = pow2(rhoccL + thetakLsq)/rhoccL;
      paramBL = - 1.0;
    }
    double mustarsqL = paramAL*jJ.kTsq*exp(paramBL - splittingterm);
    double asmustarsqL = alphas(mustarsqL);
    double temp = colorfactor/para.pi/pow2(para.b0)/alphas(paramAL*jJ.kTsq);
    temp += colorfactor/para.pi/para.b0*(paramBL - splittingterm);
    if (jJ.psq < mustarsqL)
    {
      sIL = temp*log(asmujetsq/asmustarsqL);
      sIL -= colorfactor/para.pi/pow2(para.b0)*(1.0/asmustarsqL - 1.0/asmujetsq);
    }
    if (mumaxsq < mustarsqL)
    {
      sIL -= temp*log(asmumaxsq/asmustarsqL);
      sIL += colorfactor/para.pi/pow2(para.b0)*(1.0/asmustarsqL - 1.0/asmumaxsq);
    }
  }
  
  // Right part of the Sudakov exponent.
  if (jJ.f == gluon || jJ.f == quark)
  {
    double rhoccR = pow2(jJ.mccR/jJ.kTccR);
    
    double thetakRsq;
    if (abs(jJ.yccR) < para.big)
    {
      thetakRsq = pow2(jJ.yccR - jJ.y) + pow2(Dphi(jJ.phiccR, jJ.phi));
    }
    else thetakRsq = para.Rfatjetsq; // No color connected partner.
    
    double paramAR = pow2(rhoccR + thetakRsq)/(2.0*rhoccR + thetakRsq);
    double paramBR = 0.0;
    if (rhoccR > 0.0)
    {
      paramBR = rhoccR/(rhoccR + thetakRsq);
      paramBR *= log(rhoccR/(2.0*rhoccR + thetakRsq));
    }
    // Change parameters in case the right cc partner is the top quark before decay.
    if (jJ.bdescendants && jJ.mccR > para.tiny) {
      paramAR = pow2(rhoccR + thetakRsq)/rhoccR;
      paramBR = - 1.0;
    }
    double mustarsqR = paramAR*jJ.kTsq*exp(paramBR - splittingterm);
    double asmustarsqR = alphas(mustarsqR);
    double temp = colorfactor/para.pi/pow2(para.b0)/alphas(paramAR*jJ.kTsq);
    temp += colorfactor/para.pi/para.b0*(paramBR - splittingterm);
    if (jJ.psq < mustarsqR)
    {
      sIR = temp*log(asmujetsq/asmustarsqR);
      sIR -= colorfactor/para.pi/pow2(para.b0)*(1.0/asmustarsqR - 1.0/asmujetsq);
    }
    if (mumaxsq < mustarsqR)
    {
      sIR -= temp*log(asmumaxsq/asmustarsqR);
      sIR += colorfactor/para.pi/pow2(para.b0)*(1.0/asmustarsqR - 1.0/asmumaxsq);
    }
  }
  sudakov = max(sIL + sIR,0.0);
  
  if (jJ.f == gluon)
  {
    double sqqbar = para.Nf*para.TR/3.0/para.pi/para.b0*log(asmujetsq/asmumaxsq);
    sudakov += sqqbar;
  }
  
  if (jJ.f == top)
  {
    double thetakRsq;
    if (abs(jJ.yccR) < para.big)
    {
      thetakRsq = pow2(jJ.yccR - jJ.y) + pow2(Dphi(jJ.phiccR, jJ.phi));
    }
    else thetakRsq = para.Rfatjetsq; // No color connected partner.
    
    double i0 = (thetakRsq*jJ.kTsq + 2.0*para.massTopsq);
    i0 /= (thetakRsq*jJ.kTsq + para.massTopsq);
    i0 *= log(2.0 + thetakRsq*jJ.kTsq/para.massTopsq);
    i0 -= 1.0;
    i0 *= 2.0*para.cF;
    
    double temp = thetakRsq*jJ.kTsq + para.massTopsq;
    double x0 = 2.0  - thetakRsq*jJ.kTsq/temp + 0.1*log(para.massTopsq/temp);
    double x1 = -3.0 - thetakRsq*jJ.kTsq/temp + 0.4*log(para.massTopsq/temp);
    double tscale0 = temp*exp(x0);
    double astscale0 = alphas(tscale0);
    double tscale1 = temp*exp(x1);
    double astscale1 = alphas(tscale1);
    
    double absmujetsq = abs(jJ.psq - para.massTopsq);
    
    double sImu = 0.0;
    if (tscale0 < absmujetsq) sImu = 0.0;
    else if (tscale1 < absmujetsq) // tscale1 < absmujetsq < tscale0
    {
      sImu = log(asmujetsq/astscale0);
      sImu *= 1.0/astscale0 + x0*para.b0;
      sImu += 1.0/asmujetsq - 1.0/astscale0;
      sImu *= i0/2.0/para.pi/(x0 - x1)/pow2(para.b0);
    }
    else if (absmujetsq < tscale1) // absmujetsq < tscale0 and tscale1
    {
      sImu = log(astscale1/astscale0);
      sImu *= 1.0/astscale0 + x0*para.b0;
      sImu += 1.0/astscale1 - 1.0/astscale0;
      sImu *= i0/2.0/para.pi/(x0 - x1)/pow2(para.b0);
      sImu += i0/2.0/para.pi/para.b0*log(asmujetsq/astscale1);
    }
    
    double sImumax = 0.0;
    if (tscale0 < mumaxsq) sImumax = 0.0;
    else if (tscale1 < mumaxsq) // tscale1 < mumaxsq < tscale0
    {
      sImumax = log(asmumaxsq/astscale0);
      sImumax *= 1.0/astscale0 + x0*para.b0;
      sImumax += 1.0/asmumaxsq - 1.0/astscale0;
      sImumax *= i0/2.0/para.pi/(x0 - x1)/pow2(para.b0);
    }
    else if (mumaxsq < tscale1) // mumaxsq < tscale0 and tscale1
    {
      sImumax = log(astscale1/astscale0);
      sImumax *= 1.0/astscale0 + x0*para.b0;
      sImumax += 1.0/astscale1 - 1.0/astscale0;
      sImumax *= i0/2.0/para.pi/(x0 - x1)/pow2(para.b0);
      sImumax += i0/2.0/para.pi/para.b0*log(asmumaxsq/astscale1);
    }
    
    double sudakovttg = sImu - sImumax;
    
    double sudakovtdecay = 0.0;
    if (absmujetsq < para.massTop*para.DeltaTop)
    {
      if (jJ.kappaK/2.0*jJ.kT < para.massTop*para.DeltaTop)
      {
        sudakovtdecay = log(atan(jJ.kappaK/2.0*jJ.kT/para.massTop/para.GammaTop));
      }
      else sudakovtdecay = log(para.ArcTanTop);
      sudakovtdecay -= log(atan(absmujetsq/para.massTop/para.GammaTop));
    }
    sudakov = max(sudakovttg,0.0) + sudakovtdecay;
  } // End flavor == top.
  return sudakov;
}

///////////////////////////////////// End of Sudakov /////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// anglefactor  /////////////////////////////////////////////
///////////////////////////////// 12 July 2013 DES ///////////////////////////////////////////

// Angle factor g(y,phi) with jets.
double anglefactor(const jetdata& jL, const jetdata& jR, const jetdata& jJ)
{
  double ys,yh,yk,phis,phih,phik,rhok;
  double thetaSHsq,thetaSKsq,thetaHKsq;
  double hold = 1.0;
  bool ccExists = true;     // Is there a color connected partner?
  parameters para;
  if(jJ.f == gluon || jJ.f == quark || jJ.f == qbar)
	{
    if(jJ.f==gluon)// Set variables for a gluon parent.
    {
		   if(jL.kT > jR.kT) // Test for which jet is harder.
		   {
         if(abs(jJ.yccR) < para.big)
         {
           ys   = jR.y;
           yh   = jL.y;
           yk   = jJ.yccR;
           phis = jR.phi;
           phih = jL.phi;
           phik = jJ.phiccR;
           rhok = pow2(jJ.mccR/jJ.kTccR);
         }
         else ccExists = false;
       }
		   else // jL.kT < jR.kT
		   {
         if(abs(jJ.yccL) < para.big)
         {
           ys    = jL.y;
           yh    = jR.y;
           yk    = jJ.yccL;
           phis  = jL.phi;
           phih  = jR.phi;
           phik  = jJ.phiccL;
           rhok = pow2(jJ.mccL/jJ.kTccL);			
         }
         else ccExists = false;
		   }
    } // Variables for a gluon parent have been set.
    else if(jJ.f == quark)// Set variables for a quark parent.
    {
      if(abs(jJ.yccR) < para.big)
      {
        ys    = jR.y;
        yh    = jL.y;
        yk    = jJ.yccR;
        phis  = jR.phi;
        phih  = jL.phi;
        phik  = jJ.phiccR;
        rhok = pow2(jJ.mccR/jJ.kTccR);
      }
      else ccExists = false;
    } // Variables for a quark parent have been set.
    else if(jJ.f == qbar)// Set variables for a qbar parent.
    {
      if(abs(jJ.yccL) < para.big)
      {
        ys    = jL.y;
        yh    = jR.y;
        yk    = jJ.yccL;
        phis  = jL.phi;
        phih  = jR.phi;
        phik  = jJ.phiccL;
        rhok = pow2(jJ.mccL/jJ.kTccL);
      }
      else ccExists = false;
    } // Variables for a qbar parent have been set.
    
    if (ccExists)  // There is a color connected partner.
    {
      thetaSHsq = pow2(ys-yh) + pow2(Dphi(phis,phih));
      thetaSKsq = pow2(ys-yk) + pow2(Dphi(phis,phik));
      thetaHKsq = pow2(yh-yk) + pow2(Dphi(phih,phik));
      // We check jJ.stag. If it is true, then we are looking at the b-quark
      // from a top decay or its descendents. Then if rhok != 0, the cc-partner
      // is the top quark before the decay and we have an antenna dipole splitting.
      if(!jJ.bdescendants) // Normal case.
        hold = ((thetaSKsq + rhok)*(thetaHKsq + rhok) - thetaSHsq*rhok)
               /(thetaSKsq + rhok)/(thetaSHsq + thetaSKsq + rhok);
      else if(jJ.bdescendants && rhok > para.tiny)
        // g-t or q-t dipole, t is the right cc partner.
				hold = ((thetaSKsq + rhok)*(thetaHKsq + rhok) - thetaSHsq*rhok)
               /pow2(thetaSKsq + rhok);
      else if(jJ.bdescendants && rhok <= para.tiny) // Also normal case, with rhok == 0.
				hold = thetaHKsq/(thetaSHsq + thetaSKsq);
    }
    else hold = 1.0; // There is no color connected partner.
	}
	else if(jJ.f == top)
	{
		if(abs(jJ.yccR) < para.big)
		{
      thetaSHsq = pow2(jR.y - jL.y) + pow2(Dphi(jR.phi,jL.phi));
      thetaSKsq = pow2(jR.y - jJ.yccR) + pow2(Dphi(jR.phi,jJ.phiccR));
      thetaHKsq = pow2(jL.y - jJ.yccR) + pow2(Dphi(jL.phi,jJ.phiccR));
      double msqratio = pow2(jL.m/jL.kT);
			hold = (thetaSHsq + msqratio)*(thetaHKsq + msqratio);
      hold -= thetaSKsq*msqratio;
      hold /= (thetaSHsq + msqratio);
      hold /= (thetaSKsq + thetaSHsq + msqratio);
		}
		else
    {
      thetaSHsq = pow2(jR.y-jL.y) + pow2(Dphi(jR.phi,jL.phi));
      hold = thetaSHsq/(thetaSHsq + pow2(jL.m/jL.kT));
    }
	}
	return hold;
}
/////////////////////////////////// End of anglefactor ///////////////////////////////////////


} // End of namespace DES
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
