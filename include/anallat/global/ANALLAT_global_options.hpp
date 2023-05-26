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
//const size_t ALIGNMENT_SIZE = 128;
struct GlobalOptions{

    /*Common Parameters*/
    int                 Verbosity; // Verbosity level of the program
    std::string         Project; // Name of the project.
    int                 ProjectYear; // Year of the project: {"2018", "2019", "2020", "2021", "2022", "2023", "2024", "2025"}
    size_t              Dimensions; // Number of dimensions of the lattice: {1, 2, 3, 4}
    std::vector<size_t> Lattice;
    std::string         Theory; // Name of the theory:{"QCD", "QED", "QCD+QED", "Scalar", "XY"}
    std::string         Description;// Description of the project
    std::string         AnalysisType;// Analysis type:{"Spectrum", "DispersionRelation", "ScatteringPhaseShift", "ThreePointFunction", "TwoPointFunction", "AutoCorrelation"}
    std::string         Method;// Method:{"GEVP", "RotatedGEVP", "RatioMethod", "Bootstrap", "Jackknife", "Fit", "FitRatio", "FitDispersionRelation", "FitScatteringPhaseShift", "FitThreePointFunction", "FitTwoPointFunction", "FitAutoCorrelation"}
    std::string         InputPath;// Path to the input files
    std::string         OutputPath;// Path to the output files

};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(GlobalOptions, Verbosity, Project, ProjectYear, Dimensions, Lattice, Theory, Description,
                                   AnalysisType, Method, InputPath, OutputPath);

#endif //ANALLAT_ANALLAT_GLOBAL_OPTIONS_HPP
