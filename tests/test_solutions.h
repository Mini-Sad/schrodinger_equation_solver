#include <cxxtest/TestSuite.h>
#include "../include/solutions.h"

class TestSolutions: public CxxTest::TestSuite
{
    public:
    //Vérifie si la fonction est correctement implémentée avec plusieurs valeurs différentes
    void testFactorielle(void)
    {
        Solutions solutions(1.0,1.0,1.0);
        // Vérifie si 5!=120
        TS_ASSERT_EQUALS(solutions.factorielle(5),120);
        // Vérifie si 7!=5040
        TS_ASSERT_EQUALS(solutions.factorielle(7),5040);
        // Vérifie si 9!=362880
        TS_ASSERT_EQUALS(solutions.factorielle(9),362880);
        
    }


};