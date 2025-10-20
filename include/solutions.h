#ifndef SOLUTIONS_H
#define SOLUTIONS_H

#include <armadillo>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


class Solutions
{
    public:
    /**
     * @brief Constructeur
     */
    Solutions(double _m=1, double _h=1, double _w=1);

    /**
     * @brief Fonction de récurrence qui calcule la factorielle de int
     * @param int : entier
     * @return factorielle de int
     */
    int factorielle(int);

    /**
     * @brief Fonction de récurrence qui calcule le polynôme d'Hermite sur l'axe vec z
     * @param int : entier
     * @param vec : correpond à l'axe z
     * @return le polynôme d'Hermite
     */
    arma::vec hermite(int, arma::vec);


    /**
     * @brief Fonction qui calcule la solution de l'oscillateur harmonique à une dimension
     * @param int : entier
     * @param vec : correspond à l'axe z
     * @return La solution of 1D-HO
     */
    arma::vec calc(int, arma::vec);

    /**
     * @brief Calcule l'énergie théorique de l'état n
     * @param n : niveau d'énergie
     * @return Énergie théorique En = ℏω(n + 1/2)
     */
    double energie_theorique(int n);

    /**
     * @brief Calcule l'énergie de l'état n numériquement
     * @param n : niveau d'énergie
     * @param z : axe de position
     * @return Énergie calculée numériquement
     */
    double energie_numerique(int n, arma::vec z);

    /**
     * @brief Calcule le produit scalaire entre deux états
     * @param n : premier niveau d'énergie
     * @param m : second niveau d'énergie
     * @param z : axe de position
     * @return <ψ_n|ψ_m> (devrait être δ_nm)
     */
    double produit_scalaire(int n, int m, arma::vec z);
    
    /**
     * @brief Vérifie l'orthonormalité pour plusieurs états
     * @param n_max : nombre d'états à vérifier
     * @param z : axe de position
     */
    void verifier_orthonormalite(int n_max, arma::vec z);



    private:
    // masse
    double m;
    // constante de Plank
    double h;
    // pulsation angulaire (angular frequence)
    double w;
    //pi
    const double pi = M_PI;  // Utiliser la constante mathématique précise

};


#endif // SOLUTIONS_H