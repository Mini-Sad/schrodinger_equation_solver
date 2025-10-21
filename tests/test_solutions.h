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

    // Test de l'énergie théorique
    void testEnergieTheorique(void)
    {
        Solutions solutions(1.0, 1.0, 1.0);  // m=1, h=1, w=1
        
        // Vérification pour plusieurs niveaux d'énergie
        // E_n = ℏω(n + 1/2) = 1.0 * 1.0 * (n + 0.5)
        TS_ASSERT_DELTA(solutions.energie_theorique(0), 0.5, 1e-10);
        TS_ASSERT_DELTA(solutions.energie_theorique(1), 1.5, 1e-10);
        TS_ASSERT_DELTA(solutions.energie_theorique(2), 2.5, 1e-10);
        TS_ASSERT_DELTA(solutions.energie_theorique(3), 3.5, 1e-10);
        TS_ASSERT_DELTA(solutions.energie_theorique(5), 5.5, 1e-10);
        
        TS_TRACE("Test énergie théorique validé ✓");
    }

    // Test de l'énergie numérique
    void testEnergieNumerique(void)
    {
        Solutions solutions(1.0, 1.0, 1.0);  // m=1, h=1, w=1
        
        // Créer un domaine suffisamment grand
        arma::vec z = arma::linspace(-10, 10, 2000);
        
        // Vérifier que l'énergie numérique est proche de la théorique
        // avec une tolérance de 1% (les calculs numériques ne sont pas parfaits)
        for(int n = 0; n <= 3; n++) {
            double E_theorique = solutions.energie_theorique(n);
            double E_numerique = solutions.energie_numerique(n, z);
            double erreur_relative = std::abs(E_numerique - E_theorique) / E_theorique;
            
            TS_ASSERT_LESS_THAN(erreur_relative, 0.01);  // Moins de 1% d'erreur
        }
        
        TS_TRACE("Test énergie numérique validé ✓");
    }

    // Test du produit scalaire et orthogonalité
    void testProduitScalaire(void)
    {
        Solutions solutions(1.0, 1.0, 1.0);
        arma::vec z = arma::linspace(-10, 10, 1000);
        unsigned p = 50;  // Ordre de la quadrature
        
        // Test 1: Produit scalaire d'une fonction avec elle-même doit être ~1
        double ps_00 = solutions.produit_scalaire_gauss(0, 0, z, p);
        TS_ASSERT_DELTA(ps_00, 1.0, 0.01);
        
        double ps_11 = solutions.produit_scalaire_gauss(1, 1, z, p);
        TS_ASSERT_DELTA(ps_11, 1.0, 0.01);
        
        // Test 2: Produit scalaire entre fonctions différentes doit être ~0
        double ps_01 = solutions.produit_scalaire_gauss(0, 1, z, p);
        TS_ASSERT_DELTA(ps_01, 0.0, 0.01);
        
        double ps_02 = solutions.produit_scalaire_gauss(0, 2, z, p);
        TS_ASSERT_DELTA(ps_02, 0.0, 0.01);
        
        double ps_12 = solutions.produit_scalaire_gauss(1, 2, z, p);
        TS_ASSERT_DELTA(ps_12, 0.0, 0.01);
        
        TS_TRACE("Test produit scalaire et orthogonalité validé ✓");
    }

    // Test de vérification de l'orthonormalité
    void testVerifierOrthonormalite(void)
    {
        Solutions solutions(1.0, 1.0, 1.0);
        arma::vec z = arma::linspace(-10, 10, 1000);
        unsigned p = 50;  // Ordre de la quadrature
        
        // Ce test vérifie que la fonction ne plante pas
        // et affiche les résultats corrects
        TS_TRACE("Vérification de l'orthonormalité pour n_max=4:");
        
        // On ne peut pas facilement tester la sortie console,
        // mais on peut vérifier que la fonction s'exécute sans erreur
        TS_ASSERT_THROWS_NOTHING(solutions.verifier_orthonormalite(4, z, p));
        
        TS_TRACE("Test vérification orthonormalité validé ✓");
    }


};
