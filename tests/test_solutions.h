#include <cxxtest/TestSuite.h>
#include "../include/solutions.h"

class TestSolutions: public CxxTest::TestSuite
{
    public:
    void testFactorielle(void)
    {
        Solutions solutions(1.0,1.0,1.0);
        TS_ASSERT_EQUALS(solutions.factorielle(5),120);
        TS_ASSERT_EQUALS(solutions.factorielle(7),5040);
        TS_TRACE("Test sur la fonction factorielle validé");
    }

    void testHermite(void)
    {
        arma::vec z =arma::linspace(0,10,100);
        Solutions solutions(1.0,1.0,1.0);
        TS_ASSERT_EQUALS(solutions.hermite(5,z),arma::ones(size(z))));

    }
};