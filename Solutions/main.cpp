#include "solutions.h"

int main(int, char**)
{
    Solutions solutions(1.0,1.0,1.0);

    arma::vec z = arma::linspace(0,10,100);
    auto result =solutions.calc(5,z);
    result.print("result");
}