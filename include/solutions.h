#ifndef SOLUTIONS_H
#define SOLUTIONS_H

#include <armadillo>
#include <iostream>
#include <cmath>

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



    private:
    // constante de Plank
    double h;
    // masse
    double m;
    // pulsation angulaire (angular frequence)
    double w;
    //pi
    const double pi = 3.14;

};


#endif // SOLUTIONS_H