#include "black_scholes.h"

using namespace std;

int main(int argc,char **argv){
    double S=100.0;  // Underlying Spot Price
    double K=100.0; // Strke Price
    double r=0.05;  // Risk-free rate (5%)
    double v=0.2;   // Volatility of the underlying (20%)
    double T=1.0;   // Time to expiration (one year)

    cout<<"Enter Underlying Spot Price          : ";
    cin>>S;
    cout<<"Enter Strike Price                   : ";
    cin>>K;
    cout<<"Enter Risk_free rate (as 0.02 == 2%) : ";
    cin>>r;
    cout<<"Enter Volatility of underlying       : ";
    cin>>v;
    cout<<"Enter Time to expiration (in Year)   : ";
    cin>>T;

    double call=call_preice(S,K,r,v,T);
    double call_delta_value=call_delta(S,K,r,v,T);
    double call_gamma_value=call_gamma(S,K,r,v,T);
    double call_vega_value=call_vega(S,K,r,v,T);
    double call_theta_value=call_theta(S,K,r,v,T);
    double call_rho_value=call_rho(S,K,r,v,T);

    double put=call_preice(S,K,r,v,T);
    double put_delta_value=put_delta(S,K,r,v,T);
    double put_gamma_value=put_gamma(S,K,r,v,T);
    double put_vega_value=put_vega(S,K,r,v,T);
    double put_theta_value=put_theta(S,K,r,v,T);
    double put_rho_value=put_rho(S,K,r,v,T);


    // Output 
    cout<<"\n";
    cout<<"Underlying          : "<<S<<"\n";
    cout<<"Strike              : "<<K<<"\n";
    cout<<"Risk-Free Rate      : "<<r<<"\n";
    cout<<"Volatility          : "<<v<<"\n";
    cout<<"Maturity            : "<<T<<"\n";

    cout<<"Call Price          : "<<call<<"\n";
    cout<<"Call Delta          : "<<call_delta_value<<"\n";
    cout<<"Call Gamma          : "<<call_gamma_value<<"\n";
    cout<<"Call Vega           : "<<call_vega_value<<"\n";
    cout<<"Call Theta          : "<<call_theta_value<<"\n";
    cout<<"Call Rho            : "<<call_rho_value<<"\n";

    cout<<"Put Price           : "<<put<<"\n";
    cout<<"Put Delta           : "<<put_delta_value<<"\n";
    cout<<"Put Gamma           : "<<put_gamma_value<<"\n";
    cout<<"Put Vega            : "<<put_vega_value<<"\n";
    cout<<"Put Theta           : "<<put_theta_value<<"\n";
    cout<<"Put Rho             : "<<put_rho_value<<"\n";

    return 0;
}