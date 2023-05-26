//
// Created by spaul on 19/05/2023.
//
#include "anallat/ANALLAT_commandline_params.hpp"


BEGIN_ANALLAT_NAMESPACE

bool isValidFile(const std::string& filename) {
    std::ifstream const file(filename);
    return file.good();
}

OptionsManager::OptionsManager() {

    //Global Options
    GlobalOpt.Verbosity     = 0;
    GlobalOpt.Project       = "TestProject";
    GlobalOpt.ProjectYear   = 1;
    GlobalOpt.Description   = "Default Description";
    GlobalOpt.Theory        = "QCD";
    GlobalOpt.Dimensions    = 4;
    GlobalOpt.Lattice       = {1,1,1,1};
    GlobalOpt.AnalysisType  = "Test";
    GlobalOpt.Method        = "Test";
    GlobalOpt.InputPath     = "/test/";
    GlobalOpt.OutputPath    = "/test/";

    //MonteCarlo Options
    MonteCarloOpt.Ensemble          = "test";// Ensemble name (e.g. "A40.24")
    MonteCarloOpt.Action            = "Test";
    MonteCarloOpt.Boundary          = "PERIODIC";
    MonteCarloOpt.Collab            = "Mainz";
    MonteCarloOpt.NconfPerReplica   = {1, 1};
    MonteCarloOpt.SpecialConfigs    = {{1},{1}};
    MonteCarloOpt.NskipConfigs      = 1;

    //Spectrum Options
    SpectrumOpt.Isospin             = 0;
    SpectrumOpt.Spin                = 0;
    SpectrumOpt.AuthorName          = "SPAUL";
    SpectrumOpt.Particle            = "Test";
    SpectrumOpt.InputCorrFile       = {"/test"};
    SpectrumOpt.InputVecFile        = {"/test","/test"};
    SpectrumOpt.Irrep               = {"Test"};
    SpectrumOpt.Momenta             = {{0,0,0}, {0,-1,0}};
    SpectrumOpt.Nsrc                = 1;
    SpectrumOpt.ReweightingFacFile  = {{"rw1.dat"},{"rw2.dat"}};
    SpectrumOpt.Ninterp             = 4;
    SpectrumOpt.Tmin                = {1,2,3,4};
    SpectrumOpt.Tmax                = {2,3,4,5,};

}
const std::vector<size_t>& OptionsManager::getLattice() const {
    return GlobalOpt.Lattice;
}

const std::string& OptionsManager::getAnalysisType() const {
    return GlobalOpt.AnalysisType;
}
GlobalOptions OptionsManager::getGlobalOptions() {
    return GlobalOpt;
}
MonteCarloOptions OptionsManager::getMonteCarloOptions() {
    return MonteCarloOpt;
}
SpectrumOptions OptionsManager::getSpectrumOptions() {
    return SpectrumOpt;
}
//Default Shared Pointer
std::shared_ptr<option> OptionsManager::MakeOptions(const std::string &AppDescription, const std::string &AppName) {

    auto anallat_opt = std::make_shared<option>(AppDescription, AppName);
    anallat_opt->option_defaults()->always_capture_default();

    anallat_opt->add_option("--global-config", GlobalConfigPath, "Global configuration");
    anallat_opt->add_option("--montecarlo-config", MonteCarloConfigPath, "Monte Carlo configuration");
    anallat_opt->add_option("--spectrum-config", SpectrumConfigPath, "Spectrum configuration");

    return anallat_opt;
}
bool OptionsManager::ParseGlobalConfig() {
    std::ifstream file(GlobalConfigPath, std::ifstream::in);
    if(!file.is_open()) {
        std::cerr << "Failed to open config file: " << GlobalConfigPath << std::endl;
        return false;
    }
    try {
        file >> config_;
    } catch (const json::parse_error& e){
        std::cerr << "Failed to parse config file: " << e.what() << std::endl;
        return false;
    }
    std::cout<< "Global Json config read as: "<< config_ <<std::endl;
    GlobalOpt = config_.get<GlobalOptions>();
    return true;
}
bool OptionsManager::ParseMonteCarloConfig() {
    std::ifstream file(MonteCarloConfigPath, std::ifstream::in);
    if(!file.is_open()) {
        std::cerr << "Failed to open config file: " << MonteCarloConfigPath << std::endl;
        return false;
    }
    try {
        file >> config_;
    } catch (const json::parse_error& e){
        std::cerr << "Failed to parse config file: " << e.what() << std::endl;
        return false;
    }
    std::cout<< "MonteCarlo Json config read as: "<< config_ <<std::endl;
    MonteCarloOpt = config_.get<MonteCarloOptions>();
    return true;
}
bool OptionsManager::ParseSpectrumConfig() {
    std::ifstream file(SpectrumConfigPath, std::ifstream::in);
    if(!file.is_open()) {
        std::cerr << "Failed to open config file: " << SpectrumConfigPath << std::endl;
        return false;
    }
    try {
        file >> config_;
    } catch (const json::parse_error& e){
        std::cerr << "Failed to parse config file: " << e.what() << std::endl;
        return false;
    }
    std::cout<< "Spectrum Json config read as: "<< config_ <<std::endl;
    SpectrumOpt = config_.get<SpectrumOptions>();
    return true;
}

void OptionsManager::InitializeOptions(int argc, char** argv) {

    auto opt = this->MakeOptions();
    try {
        opt->parse(argc, argv);
    }
    catch (const CLI::ParseError &e) {
        opt->exit(e);
    }
    std::cout<<opt->config_to_str(true, true);
    this->ParseGlobalConfig();
    this->ParseMonteCarloConfig();
    if(isValidFile(this->getSpectrumConfigPath())) {
        this->ParseSpectrumConfig();
    }
    // Read command-line arguments and set the variables accordingly
    // Example:
    // myData.variable1 = ...;
    // myData.variable2 = ...;
}

//ConfigParser::ConfigParser() {
//    std::cout<<"Constructor for the ConfigParser with default"<<std::endl;
//}
//
//template<>
//void ConfigParser::SetOptions<OptionsType::GLOBAL_OPT>() {
//    _GlobalOpt = config_.get<GlobalOptions>();
//    std::cout<<_GlobalOpt.dimensions<<std::endl;
//
//}
//
//template<>
//void ConfigParser::SetOptions<OptionsType::MONTECARLO_OPT>() {
//    MCOpt = config_.get<MonteCarloOptions>();
//}
//
//template<>
//void ConfigParser::SetOptions<OptionsType::SPECTRUM_OPT>() {
//    SpectrumOpt = config_.get<SpectrumOptions>();
//}
//
//bool ConfigParser::ParseGlobalConfig() {
//    std::ifstream file(GlobalConfigPath, std::ifstream::in);
//    if(!file.is_open()) {
//        std::cerr << "Failed to open config file: " << GlobalConfigPath << std::endl;
//        return false;
//    }
//    try {
//        file >> config_;
//    } catch (const json::parse_error& e){
//        std::cerr << "Failed to parse config file: " << e.what() << std::endl;
//        return false;
//    }
//    std::cout<< "Global Json config read as: "<< config_ <<std::endl;
//    _GlobalOpt = config_.get<GlobalOptions>();
//    std::cout<<_GlobalOpt.dimensions<<std::endl;
//
//    //this->SetOptions<OptionsType::GLOBAL_OPT>();
//    return true;
//}
//bool ConfigParser::ParseMonteCarloConfig() {
//    std::ifstream file(MonteCarloConfigPath, std::ifstream::in);
//    if(!file.is_open()) {
//        std::cerr << "Failed to open config file: " << MonteCarloConfigPath << std::endl;
//        return false;
//    }
//    try {
//        file >> config_;
//    } catch (const json::parse_error& e){
//        std::cerr << "Failed to parse config file: " << e.what() << std::endl;
//        return false;
//    }
//    std::cout<< "MonteCarlo Json config read as: "<< config_ <<std::endl;
//    this->SetOptions<OptionsType::MONTECARLO_OPT>();
//    return true;
//}
//bool ConfigParser::ParseSpectrumConfig() {
//    std::ifstream file(SpectrumConfigPath, std::ifstream::in);
//    if(!file.is_open()) {
//        std::cerr << "Failed to open config file: " << SpectrumConfigPath << std::endl;
//        return false;
//    }
//    try {
//        file >> config_;
//    } catch (const json::parse_error& e){
//        std::cerr << "Failed to parse config file: " << e.what() << std::endl;
//        return false;
//    }
//    std::cout<< "Spectrum Json config read as: "<< config_ <<std::endl;
//    this->SetOptions<OptionsType::SPECTRUM_OPT>();
//    return true;
//}
//
////Default Shared Pointer
//std::shared_ptr<option> ConfigParser::MakeOptions(const std::string &AppDescription, const std::string &AppName) {
//
//    auto anallat_opt = std::make_shared<option>(AppDescription, AppName);
//    anallat_opt->option_defaults()->always_capture_default();
//
//    anallat_opt->add_option("--global-config", GlobalConfigPath, "Global configuration");
//    anallat_opt->add_option("--montecarlo-config", MonteCarloConfigPath, "Monte Carlo configuration");
//    anallat_opt->add_option("--spectrum-config", SpectrumConfigPath, "Spectrum configuration");
//
//    return anallat_opt;
//}

END_ANALLAT_NAMESPACE

