
//===================//
// ANALLAT_enum      //
//===================//

// Common Parameters Need to be Set by the User
enum class Theory {QCD, QED, QCD_QED, Scalar, XY};
enum class Collaboration {Cyprus, Mainz, Edinburgh, USQCD, LHPC_Cyprus};
enum class Action {Wilson_Clover, Mobius, Twisted_Mass, Staggered, Overlap, Wilson};
enum class AnalysisType {Spectrum, DispersionRelation, ScatteringPhaseShift, ThreePointFunction, TwoPointFunction, AutoCorrelation};
enum class Method {GEVP, RotatedGEVP, RatioMethod, Bootstrap, Jackknife, Fit, FitRatio, FitDispersionRelation, FitScatteringPhaseShift, FitThreePointFunction, FitTwoPointFunction, FitAutoCorrelation};
enum class FileFormat { ASCII_FORMAT, HDF5_FORMAT, DEFAULT_FORMAT};

// Analysis Specific Parameters Need to be Set by the User
enum class CorrType { CORR_SINGLE, CORR_MAT, CORR_THREEPT};
enum class CREATOR{ SPAUL, JGREEN, GSILVI, FPITTLER};
enum class WHICHPARTICLE{PROTON, NEUTRON, BARYON, DIBARYON, PION, CURRENT};
enum class RESAMPLE_TYPE{BOOTSTRAP, JACKKNIFE};
enum class FITMODEL{LINEAR, LOGLINEAR, EXPONENTIAL, TWO_EXPONENTIAL};
enum class FITTYPE{RATIO, DISPERSION, SCATTERING, THREEPT, TWOPT, AUTOCORRELATION};