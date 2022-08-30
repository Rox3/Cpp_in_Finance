#define USE MATH DEFINES


#include <iostream>
#include <cmath>
#include <algorithm> // useful for min and max function

double norm_pdf(const double x){
    return (1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x);
}

double norm_cdf(const double x){
    double k=1.0/(1.0+0.2316419*x);
    double k_sum=k*(0.319381530+k*(-0.356563782+k*(1.781477937+k*(-1.821255978+k*1.330274429))));
    if(x>=0.0){
        return (1.0-(1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x)*k_sum);
    }
    else{
        return 1.0-norm_cdf(-x);
    }
}

double d_j(const int j, const double S, const double K, const double r, const double v, const double T){
    return (log(S/K)+(r+(pow(-1,j-1))*0.5*v*v)*T)/(v*(pow(T,0.5))); 
}

//S*exp(-d*T)norm_cdf(d_j(1,S,K,r,v,T))-K*exp(-r*T)*norm_cdf(d_j(2,S,K,r,v,T));
// We are not considering devident of underlying 
double call_preice(const double S, const double K, const double r, const double v, const double T){
    return S*norm_cdf(d_j(1,S,K,r,v,T))-K*exp(-r*T)*norm_cdf(d_j(2,S,K,r,v,T));
}

double call_delta(const double S, const double K, const double r, const double v, const double T){
    return norm_cdf(d_j(1,S,K,r,v,T));
}

double call_gamma(const double S, const double K, const double r, const double v, const double T){
    return norm_pdf(d_j(1,S,K,r,v,T))/(S*v*sqrt(T));
}

double call_vega(const double S, const double K, const double r, const double v, const double T){
    return S*norm_pdf(d_j(1,S,K,r,v,T))*sqrt(T);
}

double call_theta(const double S, const double K, const double r, const double v, const double T){
    return -(S*norm_pdf(d_j(1,S,K,r,v,T))*v)/(2*sqrt(T)) - r*K*exp(-r*T)*norm_cdf(d_j(2,S,K,r,v,T));
}

double call_rho(const double S, const double K, const double r, const double v, const double T){
    return K*T*exp(-r*T)*norm_cdf(d_j(2,S,K,r,v,T));
}

double put_preice(const double S, const double K, const double r, const double v, const double T){
    return -S*norm_cdf(-d_j(1,S,K,r,v,T))+K*exp(-r*T)*norm_cdf(-d_j(2,S,K,r,v,T));
}

double put_delta(const double S, const double K, const double r, const double v, const double T){
    return norm_cdf(d_j(1,S,K,r,v,T))-1;
}

double put_gamma(const double S, const double K, const double r, const double v, const double T){
    return call_gamma(S,K,r,v,T);
    // Identical to call by put-call parity
}

double put_vega(const double S, const double K, const double r, const double v, const double T){
    return call_vega(S,K,r,v,T);
    // Identical to call by put-call parity
}

double put_theta(const double S, const double K, const double r, const double v, const double T){
    return -(S*norm_pdf(d_j(1,S,K,r,v,T))*v)/(2*sqrt(T)) + r*K*exp(-r*T)*norm_cdf(-d_j(2,S,K,r,v,T));
}

double put_rho(const double S, const double K, const double r, const double v, const double T){
    return - K*T*exp(-r*T)*norm_cdf(-d_j(2,S,K,r,v,T));
}

double gaussian_box_muller(){
    double x=0.0;
    double y=0.0;
    double euclid_sq=0.0;

    do{
        x=2.0*rand();
        y=2.0*rand();
        euclid_sq=x*x+y*y;
    }while(euclid_sq>=1.0);

    return x*sqrt(-2*log(euclid_sq)/euclid_sq);
}

