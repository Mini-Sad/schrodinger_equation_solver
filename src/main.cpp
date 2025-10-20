#include "../include/solutions.h"

int main(int charc, char *argv[])
{
    Solutions solutions(1.0,1.0,1.0);

    // Domaine étendu pour mieux capturer la fonction d'onde
    arma::vec z = arma::linspace(-10,10,2000);
    int n=5;
    auto result =solutions.calc(n,z);
    result.print("Calcul de l'oscillateur harmonique 1D en fonction de z pour un n donné");
    
    // Test de l'énergie
    cout << "\n=== Vérification de l'énergie ===" << endl;
    
    for(int n = 0; n < 5; n++)
    {
        double E_theo = solutions.energie_theorique(n);
        double E_num = solutions.energie_numerique(n, z);
        double erreur_relative = abs(E_num - E_theo) / E_theo * 100;
        
        cout << "n = " << n << endl;
        cout << "  E théorique  = " << E_theo << endl;
        cout << "  E numérique  = " << E_num << endl;
        cout << "  Erreur rel.  = " << erreur_relative << " %" << endl;
    }
    
    // Test de l'orthonormalité
    solutions.verifier_orthonormalite(5, z);
    
    return 0;
}