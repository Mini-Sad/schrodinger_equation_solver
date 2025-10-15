#include "../include/solutions.h"

int main(int charc, char *argv[])
{
    Solutions solutions(1.0,1.0,1.0);

    arma::vec z = arma::linspace(0,10,100);
    int n=5;
    auto result =solutions.calc(n,z);
    result.print("Calcul de l'oscillateur harmonique 1D en fonction de z pour un n donné");
    return 0;
}