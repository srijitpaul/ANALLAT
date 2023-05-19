#ifndef ANALLAT_UTILS_HPP
#define ANALLAT_UTILS_HPP

#include "ANALLAT_commandline_params.hpp"

BEGIN_ANALLAT_NAMESPACE

class CommonOptions : ConfigParser {
public:
    //Common Parameters
    static const int verbosity; // Verbosity level of the program
    static const std::string project; // Name of the project.
    static const int project_year; // Year of the project: {"2018", "2019", "2020", "2021", "2022", "2023", "2024", "2025"}
    static const size_t dimensions; // Number of dimensions of the lattice: {1, 2, 3, 4}
    static const std::string theory; // Name of the theory:{"QCD", "QED", "QCD+QED", "Scalar", "XY"}
    static const std::string description;// Description of the project
    static const std::string analysis_type;// Analysis type:{"Spectrum", "DispersionRelation", "ScatteringPhaseShift", "ThreePointFunction", "TwoPointFunction", "AutoCorrelation"}
    static const std::string method;// Method:{"GEVP", "RotatedGEVP", "RatioMethod", "Bootstrap", "Jackknife", "Fit", "FitRatio", "FitDispersionRelation", "FitScatteringPhaseShift", "FitThreePointFunction", "FitTwoPointFunction", "FitAutoCorrelation"}
    static const std::string input_path;// Path to the input files
    static const std::string output_path;// Path to the output files
};

//----------ANALLAT_utils.cpp---------------//


void initializeCommonOptions(int argc, char **argv);

//void rotatedGEVPOptions(int argc, char **argv);

//void dispersionrelOptions(int argc, char **argv);

//void resamplingOptions(int argc, char **argv);

//void initializeANALLAT();

//void finalizeANALLAT();

END_ANALLAT_NAMESPACE

#endif  // ANALLAT_UTILS_HPP