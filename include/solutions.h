#ifndef SOLUTIONS_H
#define SOLUTIONS_H

#include <armadillo>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>

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
     * @brief Calcule les nœuds et poids de Gauss-Legendre sur [-1,1]
     * @param p : ordre de la quadrature
     * @param x : vecteur des nœuds (sortie)
     * @param w : vecteur des poids (sortie)
     */
    void gauss_legendre_nodes_weights(unsigned p, arma::vec& x, arma::vec& w);
    
    /**
     * @brief Calcule le produit scalaire via Gauss-Legendre sur [a,b]
     * @param n : premier niveau d'énergie
     * @param m : second niveau d'énergie
     * @param a : borne inférieure
     * @param b : borne supérieure
     * @param p : ordre de la quadrature
     * @return <ψ_n|ψ_m>
     */
    double produit_scalaire_gauss(int n, int m, double a, double b, unsigned p) const;
    
    /**
     * @brief Calcule le produit scalaire via Gauss-Legendre (déduit [a,b] de z)
     * @param n : premier niveau d'énergie
     * @param m : second niveau d'énergie
     * @param z : grille pour déduire [a,b]
     * @param p : ordre de la quadrature
     * @return <ψ_n|ψ_m>
     */
    double produit_scalaire_gauss(int n, int m, const arma::vec& z, unsigned p) const;
    
    /**
     * @brief Vérifie l'orthonormalité pour plusieurs états
     * @param n_max : nombre d'états à vérifier
     * @param z : axe de position
     * @param p : ordre de la quadrature Gauss-Legendre
     */
    void verifier_orthonormalite(int n_max, arma::vec z, unsigned p);



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