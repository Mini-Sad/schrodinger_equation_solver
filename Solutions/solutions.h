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
    Solutions(double _m, double _h, double _w);
    const double pi = 3.14;



    /**
     * @brief Fonction de récurrence qui calcule la factorielle de int 
     * @param int :
     * @return factorielle de int
     */
    int factorielle(int);

    /**
     * @brief Fonction de récurrence qui calcule le polynôme d'Hermite sur l'axe vec z
     * @param int :
     * @param vec :
     * @return le polynôme d'Hermite
     */
    arma::vec hermite(int, arma::vec);


    /**
     * @brief Fonction qui calcule la solution de l'oscillateur harmonique à une dimension
     * @param int : 
     * @param vec : 
     * @return La solution of 1D-HO
     */
    arma::vec calc(int, arma::vec);



    private:
    // constante de Plank
    double h=1.0;
    // masse
    double m=1.0;
    // pulsation angulaire (angular frequence)
    double w=1.0;

};


#endif // SOLUTIONS_H