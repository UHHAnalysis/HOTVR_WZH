// Specification file for classes etc.
// used for shower deconstruction code
// D.E. Soper, C. Newby, C. Jackson, S. Bharadwaj
// 6 November 2011
// 17 August 2013

namespace DES{
  
const int maxsize = 12;   

inline double pow2(const double x){return x*x;}  // x^2
inline double pow3(const double x){return x*x*x;}  // x^3
inline double pow4(const double x){return x*x*x*x;}  // x^4

class LRsets
{
// Uses arrays of integers of size maxsize+1 to represent sets of integers.
// set[0] = N is the size of the set,
// {set[1],...,set[N]} are the elements.
// Class LRsets returns subsets setA and setB of set, where setA U setB = set.
public:
  LRsets(int (&set)[maxsize+1]);          // Constructor.  Use given initial set.
  void reset(int (&set)[maxsize+1]);      // Resets data according to set, as in constructor.
  bool next(int (&setA)[maxsize+1],int (&setB)[maxsize+1]);
  // Returns next division of set into setA and setB.
  // Call 0 of s.next(setA,setB) gives setA = set, setB = {}.
  // But we start with call 1, which gives nonempty sets (unless
  // the starting set had only one element and thus no nontrivial subsets).
  // Further calls give each subset of "set" for setA, the complement for setB.
  // Call 2^N would return returns setA = {}, setB = set,
  // but we end with call 2^(N-1), which returns sets A and B with countend = true.
  // Further calls are in error and return countend = true, setA = setB = {}.
private:
  int len;                // Length of the whole set.
  int intset[maxsize];    // Initial set which is either given or set by the default constructor.
  unsigned long count;    // A count of which step in the splitting the class is at.
  unsigned long countmax; // When we get to here, we are done
  bool countend;          // Boolian for when the count is done
};

class fourvector
{
public:
  fourvector();				             // Default constructor, sets all values to 0.
  fourvector(double invec[4]);     // Constructor which sets the vector to v(i)=invec[i].
  fourvector(double t, double x, double y, double z); // Sets the vector to v(i)=(t,x,y,z)
  double& in(const int& mu);						              // v.in(mu) for input, v.in(mu) = r
  const double operator()(const int& mu) const;	      // v(mu) for output,  r = v(mu)
  fourvector operator+ (const fourvector& v2) const;  // Sum of two vectors: v3 = v1 + v2
  fourvector operator- (const fourvector& v2) const;  // Difference: v3 = v1 - v2
  fourvector operator* (const double& a) const;		    // Vector times scalar: v2 = v1*c
  fourvector operator- () const;		                  // -1 times vector: v2 = - v1
private:
  double vector[4];				                            // The vector, v[0], v[1], v[2], v[3]
};

// Scalar times vector: v2 = c*v1
fourvector operator*(const double& a, const fourvector& v);
// Dot product of two 4-vectors: dot(v1,v2)
double dot(const fourvector& v1, const fourvector& v2);
// Square of one 4-vector: square(v) = dot(v,v)
double square(const fourvector& v);

// Enumerated data type for the flavor of the jet
enum flavor {gluon,quark,qbar,top,Wplus,none};
// Enumerated data type signal vs background
enum model {Signal,Background};

class microjet
{
public:
  microjet();                           // Default constructor, sets p to (0,0,0,0) and btag to 0.
  microjet(fourvector pinit);           // Constructor that sets p to pinit and btag to 0.
  microjet(double t, double x, double y, double z); // Sets p to (t,x,y,z)  and btag to 0.
  microjet(double invec[4]);  // Constructor sets p to fourvector form of invec and btag to 0.
                              // Use jet.btag = ... to set the btag if needed.
  fourvector p;     // Momentum of the microjet.
  int btag;         // Whether the microjet was labeled as a b or not:
                    //      btag = 0 means not even attempted to tag
                    //      btag = -1 : tagged as not b
                    //      btag = 1  : tagged as b
};

class jetdata
{
public:
  jetdata(const microjet *mList0, int length);// Constructor for first call of jetdata.
  jetdata(jetdata jK, int s1[maxsize+1]);     // Constructor for later calls of jetdata.
  int set[maxsize+1];     // List of indices of microjet constituents of the jet.
                          // set[0] is the length of the list; 0 <= set[i] < maxsize.
  const microjet *mList;  // Pointer to list of all microjets in jet
                          // (starting from i = 0 to maxsize - 1).
  fourvector p;           // Momentum of the jet.
  fourvector pmother;     // For W-bosons, we need the momentum of the mother top quark.
  flavor f;               // Flavor of the jet.
  double yccL;            // Rapidity of the left color connected partner of the jet.
  double phiccL;          // Azimuthal angle of the left color connected partner of the jet.
  double yccR;            // Rapidity of the right color connected partner of the jet.
  double phiccR;          // Azimuthal angle of the right color connected partner of the jet.
  double kappaK;          // Hardness measure of the mother of the jet (pK^2 - mK^2)/kTK.
  double m,mccL,mccR;     // (On-shell) mass of jet and its left and right cc partners.
  double kTccL,kTccR;     // Absolute value of transverse momentum of left and right cc partners.
  bool bdescendants;      // The b-quark from a top quark decay, or its descendants.
  bool firstgluon;        // Gluon emitted from the hard interaction or incoming partons.
// Parameters calculated by SetParams().
  double kT,kTsq;           // Absolute value of transverse momentum, squared kT.
  double psq;               // Covariant square of momentum of jet.
  double y;                 // Rapidity.
  double phi;               // Azimuthal angle.
private:
  void SetParams();         //Calculates kT, kTsq, psq, y, and phi.
};

class parameters
{
public:
  parameters();
  double pi;              // 3.141592653589793.
  double massZ;           // Mass of Z-boson, 91.1876 GeV.
  double massW;           // Mass of W-boson, 80.403 GeV.
  double massWsq;
  double massTop;         // Mass of top quark, 174.2 GeV.
  double massTopsq;
  double GammaW;          // Effective width of W-boson.
  double GammaTop;        // Effective width of top quark.
  double DeltaW;          // Cut parameter for W decay.
  double ArcTanW;         // ArcTan(DeltaW/GammaW).
  double DeltaTop;        // Cut parameter for top decay.
  double ArcTanTop;       // ArcTan(DeltaTop/GammaTop).
  double asMZ;            // Alpha_s at MZ = 0.118;
  double cA;              // SU(3) group theory parameter, = 3.
  double cF;              // SU(3) group theory parameter, = 4/3.
  double TR;              // SU(3) group theory parameter, = 1/2.
  int Nf;                 // Number of quark flavors, normally 5.
  double b0;              // Coefficient in beta function, (33 - 2*Nf)/12/pi.
  double verybig;         // A large number.
  double big;             // A not quite so large number.
  double tiny;            // A tiny number.
  double Rfatjet;         // Radius of the fat jet, default 1.2.
  double Rfatjetsq;       // Square of Rfatjet.
  double pTmin;           // Smallest pT of Z-boson allowed, default 400.0.
  double npdfg;           // Power from pdfs for hard scattering, background; default 2.0.
  double npdfT;           // Power from pdfs for hard scattering, signal; default 2.0.
  double kappapsq;        // Cutoff parameter for perturbative IS radiaton; default 4.0;
  double kappanpsq;       // Cutoff parameter for non-erturbative IS radiaton; default 4.0;
  double cR;              // Scale parameter for perturbative IS radiation, default 2.0.
  double nR;              // Denominator power for perturbative IS radiation, default 1.0.
  double cnp;             // Coefficient for non-perturbative IS radiation, default 1.0.
  double nnp;             // Denominator power for non-perturbative IS radiation, default 1.5.
  double pTtagcut;        // Minimum pT of microjets that can carry b-tags, default 15 GeV
  double PTb;             // Probability for positive b-tag of a b-quark; default 0.6.
  double PTnotb;          // Probability for positive b-tag of non-b-quark; default 0.02.
  bool reportcounts;      // Whether to report number of splittings calculated.
};

double alphas(double Qsq); // Alpha_s as a function of the scale.

double Sudakov(const jetdata& jJ);          // Sudakov exponent.

// Angle factor g(y,phi)
double anglefactor(const jetdata& jL, const jetdata& jR, const jetdata& jK);  

// Calculates the difference between two phi's and returns a value between -pi and pi.
double Dphi(const double& phi1, const double& phi2);
                                                       
// The observable chi for an initial list of microjets, also reports Psignal and Pbackground
// and pTop, the average momentum of the top quark.
double Chi(microjet inMjet[maxsize], int length, double& Psignal, double& Pbackground, fourvector& pTop);

// Returns the probability for microjets jJ assuming themodel (Signal or Background).
// Also returns pHard, the average momentum of the hard parton.
double ModelProbability(const jetdata& jJ, const model& themodel, fourvector& pHard);

// Splits the jet given to it and returns the probability.
double SplitJet(const jetdata& jJ);

// Returns probability for initial state radiation.
double InitStateRad(const jetdata& jJ, double& Qsq);

} // End of namespace DES
