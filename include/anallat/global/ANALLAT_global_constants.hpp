#ifndef ANALLAT_GLOBAL_INCLUDES_H_
#define ANALLAT_GLOBAL_INCLUDES_H_

#include <iostream>
#include <array>

//Common Parameters
extern const int          verbosity;
extern const std::string  project;
extern const size_t       dimensions;
extern const std::string  theory;
extern const std::string  description;
extern const std::string  collab;
extern const std::string  action;
extern const std::string  analysis_type;
extern const std::string  method;
extern const std::string  input_path;
extern const std::string  output_path;

// //Lattice specific parameters
// extern const std::string  ensemble;
// extern const std::string  boundary;
// extern const int          isospin;
// extern const int          spin;

// //Spectrum Extraction / Dispersion Relation specific parameters
// extern const std::string                      author_name;
// extern const std::string                      particle;
// extern const std::vector<size_t>              replica;
// extern const std::vector<std::string>         input_corrfile;
// extern const std::vector<std::string>         input_vecfile;
// extern const std::vector<std::string>         reweighting_facfile;
// extern const std::vector<size_t>              Nconf_per_replica;
// extern const std::vector<std::vector<size_t>> special_configs;
// extern const int                              nstep_configs;
// extern const std::vector<std::array<int, 3>>  momenta;
// extern const std::vector<std::array<int, 3>>  ratio_fit_momenta_1;
// extern const std::vector<std::array<int, 3>>  ratio_fit_momenta_2;
// extern const std::vector<std::string>         irrep;
// extern const std::vector<std::string>         ratio_fit_irreps_1;
// extern const std::vector<std::string>         ratio_fit_irreps_2;
// extern const size_t                           Tdim;
// extern const size_t                           Ninterp;
// extern const size_t                           Nsrc;
// extern const std::vector<size_t>              t_min;
// extern const std::vector<size_t>              t_max;
// extern const double                           mass_1;
// extern const double                           mass_2;
// extern const double                           err_mass_1;
// extern const double                           err_mass_2;
// extern const int                              L_box;
// extern const size_t                           mass_1_tmin;
// extern const size_t                           mass_2_tmin;
// extern const size_t                           mass_1_tmax;
// extern const size_t                           mass_2_tmax;
// extern const std::vector<size_t>              selected_tmin;
// extern const int                              selected_interp;

#endif