#include <cxxtest/TestSuite.h>
#include "../src/main.cpp"

class TestSolutions: public CxxTest::TestSuite
{
    public:
    void testFactorielle(void)
    {
        Solutions solutions(1.0,1.0,1.0);
        TS_ASSERT_EQUALS(solutions.factorielle(5),120);
    }
};