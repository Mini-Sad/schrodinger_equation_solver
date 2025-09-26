#ifndef SOLUTIONS_H
#define SOLUTIONS_H

#include <armadillo>
#include <iostream>
#include <cmath>

using namespace std;


class Solutions
{
    public:
    Solutions(double _m, double _h, double _w);
    const double pi = 3.14;


    arma::vec calc(int, arma::vec);
    //Test à effectuer
    int factorielle(int);

    //Test à effectuer
    arma::vec hermite(int, arma::vec);
    private:
    // constante de Plank
    double h=1.0;
    // masse
    double m=1.0;
    // pulsation angulaire (angular frequence)
    double w=1.0;

};


#endif // SOLUTIONS_H