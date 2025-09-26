#include "solutions.h"

int main(int, char**)
{
    Solutions solutions(1.0,1.0,1.0);

    arma::vec z = arma::linspace(0,10,100);
    int n=5;
    int m=solutions.factorielle(n);
    auto hermite=solutions.hermite(n,z);
    auto result =solutions.calc(n,z);
    result.print("result");
    hermite.print("Polynome d'Hermite d'axe z");


    
    
}