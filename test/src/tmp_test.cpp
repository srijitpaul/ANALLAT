#include "anallat/ANALLAT.hpp"
#include <gtest/gtest.h>

TEST(CommonOptions, CheckCommandLineValues)
{
    //size_t const dim = anallat_param.GlobalOpt.dimensions;
    ASSERT_EQ(OptionsManager::getInstance().getGlobalOptions().Dimensions, 4);
    ASSERT_EQ(OptionsManager::getInstance().getMonteCarloOptions().Ensemble, "E250");
    ASSERT_EQ(OptionsManager::getInstance().getSpectrumOptions().Particle, "PION");
    //ASSERT_EQ(anallat_options::dim_test, 4);
    ASSERT_EQ(tmp::add(1, 2), 3);
    //ASSERT_EQ(Nresamples, 100);
    EXPECT_TRUE(true);
}

int main(int argc, char **argv)
{
    //InitializeOptions(argc, argv);
    OptionsManager::getInstance().InitializeOptions(argc, argv);
    //std::cout<<GlobalOpt.dimensions<<std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}