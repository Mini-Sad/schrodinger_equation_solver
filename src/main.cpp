#include "../include/solutions.h"
#include <fstream>

int main(int charc, char *argv[])
{
    Solutions solutions(1.0,1.0,1.0);

    // Domaine étendu pour mieux capturer la fonction d'onde
    arma::vec z = arma::linspace(-10,10,2000);
    int n_max = 5;  // Calculer jusqu'à n=5
    
    // Générer les fichiers individuels pour chaque n
    for(int n = 0; n <= n_max; n++)
    {
        std::ofstream file("src/resultat_n" + std::to_string(n) + ".csv");
        file << "Calcul de l'oscillateur harmonique 1D pour n=" << n << "\n";
        
        auto result = solutions.calc(n, z);
        for(size_t i = 0; i < result.n_elem; i++)
        {
            file << result(i) << "\n";
        }
        file.close();
        std::cout << "✓ Fichier resultat_n" << n << ".csv généré" << std::endl;
    }
    
    // Créer aussi le fichier resultat.csv avec n_max pour plot.py
    std::ofstream file_main("src/resultat.csv");
    file_main << "Calcul de l'oscillateur harmonique 1D\n";
    file_main << n_max << "\n";
    auto result = solutions.calc(n_max, z);
    for(size_t i = 0; i < result.n_elem; i++)
    {
        file_main << result(i) << "\n";
    }
    file_main.close();
    
    // Test de l'énergie
    cout << "\n=== Vérification de l'énergie ===" << endl;
    
    for(int n = 0; n <= n_max; n++)
    {
        double E_theo = solutions.energie_theorique(n);
        double E_num = solutions.energie_numerique(n, z);
        double erreur_relative = abs(E_num - E_theo) / E_theo * 100;
        
        cout << "n = " << n << endl;
        cout << "  E théorique  = " << E_theo << endl;
        cout << "  E numérique  = " << E_num << endl;
        cout << "  Erreur rel.  = " << erreur_relative << " %" << endl;
    }
    
    // Vérification de l'orthonormalité avec Gauss-Legendre
    solutions.verifier_orthonormalite(n_max+1, z, 50);
    
    return 0;
}