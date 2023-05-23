//
// Created by spaul3 on 22/05/2023.
//

#ifndef ANALLAT_ANALLAT_GLOBAL_OPTIONS_HPP
#define ANALLAT_ANALLAT_GLOBAL_OPTIONS_HPP

#include <iostream>
#include <string>
#include <cstddef>
#include "../externals/nlohmann/json.hpp"

//=======Global Constants==============//
struct GlobalOptions{
    //Common Parameters

    int verbosity; // Verbosity level of the program
    std::string project; // Name of the project.
    int project_year; // Year of the project: {"2018", "2019", "2020", "2021", "2022", "2023", "2024", "2025"}
    size_t dimensions; // Number of dimensions of the lattice: {1, 2, 3, 4}
    std::vector<size_t> lattice;
    std::string theory; // Name of the theory:{"QCD", "QED", "QCD+QED", "Scalar", "XY"}
    std::string description;// Description of the project
    std::string analysis_type;// Analysis type:{"Spectrum", "DispersionRelation", "ScatteringPhaseShift", "ThreePointFunction", "TwoPointFunction", "AutoCorrelation"}
    std::string method;// Method:{"GEVP", "RotatedGEVP", "RatioMethod", "Bootstrap", "Jackknife", "Fit", "FitRatio", "FitDispersionRelation", "FitScatteringPhaseShift", "FitThreePointFunction", "FitTwoPointFunction", "FitAutoCorrelation"}
    std::string input_path;// Path to the input files
    std::string output_path;// Path to the output files

};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(GlobalOptions, verbosity, project, project_year, dimensions, lattice, theory, description, analysis_type, method, input_path, output_path);

#endif //ANALLAT_ANALLAT_GLOBAL_OPTIONS_HPP
