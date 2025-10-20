#include "../include/solutions.h"



//Constructeur
Solutions::Solutions(double _m, double _h, double _w ) : m(_m), h(_h), w(_w)
{

}

int Solutions::factorielle(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return factorielle(n-1)*n;
    }
}

arma::vec Solutions::hermite(int n, arma::vec z)
{
    //Initialisation
    arma::vec H0=arma::ones(size(z));
    arma::vec H1=2*z;

    if(n==0)
    {
        return H0;
    }
    else if (n==1)
    {
        return H1;
    }
    else
    {
        return 2*z%hermite(n-1,z)-2*(n-1)*hermite(n-2,z);
    }
}

arma::vec Solutions::calc(int n, arma::vec z)
{
    arma::vec result;

    double factor_1=1.0/sqrt(pow(2,n)*factorielle(n));
    double factor_2=pow((m*w)/(pi*h),1/4);
    arma::vec factor_3=arma::exp(-(m*w/(2*h))*arma::pow(z,2));  // Correction: z^2 au lieu de z^3
    arma::vec factor_4=hermite(n, sqrt((m*w/h))*z);
    result=factor_1*factor_2*factor_3%factor_4;

    return result;
}

double Solutions::energie_theorique(int n)
{
    // E_n = ℏω(n + 1/2)
    return h * w * (n + 0.5);
}

double Solutions::energie_numerique(int n, arma::vec z)
{
    // Calculer ψ_n(z)
    arma::vec psi = calc(n, z);
    
    // Calculer la dérivée seconde numériquement
    int N = z.n_elem;
    double dz = z(1) - z(0);  // pas de discrétisation
    arma::vec d2psi_dz2(N);
    
    // Dérivée seconde par différences finies centrées
    // d²ψ/dz² ≈ (ψ(z+dz) - 2ψ(z) + ψ(z-dz)) / dz²
    for(int i = 1; i < N-1; i++)
    {
        d2psi_dz2(i) = (psi(i+1) - 2*psi(i) + psi(i-1)) / (dz*dz);
    }
    
    // Énergie cinétique + potentielle
    arma::vec E_cinetique = -(h*h/(2*m)) * (d2psi_dz2 / psi);
    arma::vec E_potentielle = 0.5 * m * w * w * arma::pow(z, 2);
    arma::vec E_totale = E_cinetique + E_potentielle;
    
    // Prendre la moyenne (éviter les bords)
    int debut = N/4;
    int fin = 3*N/4;
    double energie_moy = arma::mean(E_totale.subvec(debut, fin));
    
    return energie_moy;
}