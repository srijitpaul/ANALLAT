#ifndef ANALLAT_COMMANDLINE_PARAMS_HPP
#define ANALLAT_COMMANDLINE_PARAMS_HPP

#include <iostream>
#include <string>
#include <array>
#include <utility>
#include "anallat/ANALLAT_global_includes.hpp"

using json = nlohmann::json;
using option = CLI::App;

BEGIN_ANALLAT_NAMESPACE
bool isValidFile(const std::string& filename);

template<typename Derived>
class DependencyInjector {
protected:
    DependencyInjector() = default;
    ~DependencyInjector() = default;  // Add virtual destructor

public:
    DependencyInjector(const DependencyInjector&) = delete;
    DependencyInjector& operator=(const DependencyInjector&) = delete;
    DependencyInjector(DependencyInjector&&)  noexcept = default;
    DependencyInjector& operator=(DependencyInjector&&)  noexcept = default;

    static Derived& getInstance() {
        static Derived instance;
        return instance;
    }
};

class OptionsManager : public DependencyInjector<OptionsManager> {

private:
    GlobalOptions       GlobalOpt;
    MonteCarloOptions   MonteCarloOpt;
    SpectrumOptions     SpectrumOpt;

    json config_;
    std::string GlobalConfigPath        = "DefaultConfigPath";
    std::string MonteCarloConfigPath    = "DefaultMCConfigPath";
    std::string SpectrumConfigPath      = "DefaultSpectrumConfigPath";
    std::string OptionName;
    std::string OptionDescription;

    bool ParseGlobalConfig();
    bool ParseMonteCarloConfig();
    bool ParseSpectrumConfig();

public:
    OptionsManager();//Default Constructor

    ~OptionsManager()  = default;
    OptionsManager(const OptionsManager&) = delete;
    OptionsManager& operator=(const OptionsManager&) = delete;
    OptionsManager(OptionsManager&&) = default;  // Add move constructor
    OptionsManager& operator=(OptionsManager&&) noexcept = default;  // Add noexcept to move assignment operator

    [[nodiscard]] const std::vector<size_t>&    getLattice() const ;
    [[nodiscard]] const std::string&            getAnalysisType() const;
    [[nodiscard]] GlobalOptions                 getGlobalOptions();
    [[nodiscard]] MonteCarloOptions             getMonteCarloOptions();
    [[nodiscard]] SpectrumOptions               getSpectrumOptions();

    std::string getSpectrumConfigPath(){return SpectrumConfigPath;};

    std::shared_ptr<option> MakeOptions(const std::string &AppDescription="ANALLAT Options to start the analysis",
                                        const std::string &AppName="ANALLAT Options");

    void InitializeOptions(int argc, char** argv);
};

//    class ConfigParser {
//
//    private:
//        json config_;
//        std::string GlobalConfigPath        = "DefaultConfigPath";
//        std::string MonteCarloConfigPath    = "DefaultMCConfigPath";
//        std::string SpectrumConfigPath      = "DefaultSpectrumConfigPath";
//        std::string OptionName;
//        std::string OptionDescription;
//        //anallat_options::anallat_param_t anallat_param;
//
//        //Templated function to Set Options
//        template<OptionsType Opt> void SetOptions();
//
//    public:
//        ConfigParser();
//        //static inline GlobalOptions _GlobalOpt;
//
//        //Parse Compulsory Configs
//        bool ParseGlobalConfig();
//        bool ParseMonteCarloConfig();
//        bool ParseSpectrumConfig();
//        std::shared_ptr<option> MakeOptions(const std::string &AppDescription="ANALLAT Common Options which is global to sub-projects", const std::string &AppName="ANALLAT Common Options");
//
//        //accessors
//        //static anallat_param_t GetAnallatParam(){return anallat_param;}
//        std::string getSpectrumConfigPath(){return SpectrumConfigPath;}
//    };

END_ANALLAT_NAMESPACE
#endif // ANALLAT_COMMANDLINE_PARAMS_HPP