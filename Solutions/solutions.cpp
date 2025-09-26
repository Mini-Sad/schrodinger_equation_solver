#include "solutions.h"


//Constructeur
Solutions::Solutions(double _m, double _h , double _w ) : m(_m), h(_h), w(_w)
{

}

int Solutions::factorielle(int n){
    if(n==0){
        return 1;
    }
    else {
        return factorielle(n-1)*n;
    }
}

arma::vec Solutions::hermite(int n, arma::vec z){
    //Initialisation 
    arma::vec H0=arma::ones(size(z));
    arma::vec H1=2*z;

    if(n==0){
        return H0;
    }
    else if (n==1){
        return H1;
    }
    else{
        return 2*hermite(n-1,z)-2*(n-1)*hermite(n-2,z);
    }
}

arma::vec Solutions::calc(int n, arma::vec z)
{
    arma::mat result;

    double factor_1=1.0/sqrt(pow(2,n)*factorielle(n));
    double factor_2=pow((m*w)/(pi*h),1/4);
    arma::vec factor_3=arma::exp(((-1)*w*arma::pow(z,3))/(2*h));
    arma::vec factor_4=hermite(n, sqrt((m*w/h)*z));
    result=factor_1*factor_2*factor_3;
    
    return result;
}