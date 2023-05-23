#ifndef ANALLAT_SPECTRUM_OPTIONS_HPP
#define ANALLAT_SPECTRUM_OPTIONS_HPP

#include <iostream>
#include <string>
#include <vector>
#include<variant>

//========= SpectrumOptions ============//
struct SpectrumOptions{

    int Isospin;
    float Spin;
    std::string                      Author_name;
    std::string                      Particle;
    std::vector<std::string>         Input_corrfile;
    std::vector<std::string>         Input_vecfile;
    std::vector<std::string>         Reweighting_facfile;
    std::vector<std::array<int, 3>>  Momenta;
 //   std::vector<std::array<int, 3>>  ratio_fit_momenta_1;
 //   std::vector<std::array<int, 3>>  ratio_fit_momenta_2;
 //   std::vector<std::string>         irrep;
//    extern std::vector<std::string>         ratio_fit_irreps_1;
//    extern std::vector<std::string>         ratio_fit_irreps_2;
//    extern size_t                           Tdim;
//    extern size_t                           Ninterp;
//    extern size_t                           Nsrc;
//    extern std::vector<size_t>              t_min;
//    extern std::vector<size_t>              t_max;
//    extern double                           mass_1;
//    extern double                           mass_2;
//    extern double                           err_mass_1;
//    extern double                           err_mass_2;
//    extern int                              L_box;
//    extern size_t                           mass_1_tmin;
//    extern size_t                           mass_2_tmin;
//    extern size_t                           mass_1_tmax;
//    extern size_t                           mass_2_tmax;
//    extern std::vector<size_t>              selected_tmin;
//    extern int                              selected_interp;

};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(SpectrumOptions, Isospin, Spin, Author_name, Particle, Input_corrfile, Input_vecfile, Reweighting_facfile, Momenta);
#endif