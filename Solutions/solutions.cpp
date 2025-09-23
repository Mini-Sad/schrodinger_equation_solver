#include "solutions.h"

Solutions::Solutions(double _m, double _h , double _w ) : m(_m), h(_h), w(_w)
{

}

arma::mat Solutions::calc(int n, arma::vec z)
{
    arma::mat result;

    double factor_1=1.0;
    double factor_2=pow((m*w)/(pi*h),1/4);
    arma::vec factor_3=arma::exp(((-1)*w*arma::pow(z,3))/(2*h));
    result=factor_2*factor_3;
    




    return result;
}