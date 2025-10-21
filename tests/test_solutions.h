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
    // Vérifie si le polynome d'Hermite est correctement implémentée 
    void testHermite(void)
    {
       Solutions solutions(1.0,1.0,1.0);
       arma::vec x={-1,0,1,2};
       // Vérification pour n=0
       arma::vec H0=solutions.hermite(0,x);
       arma::vec H0_expected=arma::ones(x.n_elem);
       TS_ASSERT(arma::approx_equal(H0,H0_expected,"absdiff",1e-10));

       // Vérification pour n=1
       arma::vec H1=solutions.hermite(1,x);
       arma::vec H1_expected=2*x;
       TS_ASSERT(arma::approx_equal(H1,H1_expected,"absdiff",1e-10));

       // Vérification pour n=1
       arma::vec H2=solutions.hermite(1,x);
       arma::vec H2_expected=4*pow(x,2)-2;
       TS_ASSERT(arma::approx_equal(H1,H1_expected,"absdiff",1e-10));

       
    }


};