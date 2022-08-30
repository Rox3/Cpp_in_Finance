
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// N(0,1) density

double f(double x)
{
    double pi = 4.0 * atan (1.0);
    return exp (-x * x * 0.5) / sqrt (2 * pi);
}



// Boole's Rule

double Boole(double StartPoint, double EndPoint, int n)
{
    vector < double >X (n + 1, 0.0);
    vector < double >Y (n + 1, 0.0);
    double delta_x = (EndPoint - StartPoint) / double (n);
    for (int i = 0; i <= n; i++)
    {
        X[i] = StartPoint + i * delta_x;
        Y[i] = f (X[i]);
    }

    double sum = 0;
    for (int t = 0; t <= (n - 1) / 4; t++)
    {
        int ind = 4 * t;
        sum +=
        (1 / 45.0) * (14 * Y[ind] + 64 * Y[ind + 1] + 24 * Y[ind + 2] +
        64 * Y[ind + 3] + 14 * Y[ind + 4]) * delta_x;

    }
    return sum;
}



// N(0,1) cdf by Boole's Rule

double N(double x)
{
    return Boole (-10.0, x, 240);
}



// Black-Scholes Call Price

double BSPrice(double S, double K, double T, double r,double d, double v, char OpType)

{

    double d1= (log (S / K) + T * (r - d + 0.5 * v * v)) / (v * sqrt (T));
    double d2=d1- v*sqrt (T);
    double call = S *exp(-d*T)* N (d1) - exp (-r * T) * K * N (d2);
    if (OpType == 'C')
        return call;
    else
        return call - S*exp (-d * T) + K * exp (-r * T); // Put Parity

}



int main()
{
    double S = 100.0;  // Stock Price
    double K = 100.0;  // Strike Price
    double T = 1;   // Years to maturity
    double r = 0.05;  // Risk free interest rate
    double d = 0.0;  //Devidend consideration for index it's zero
    double v = 0.20;  // Yearly volatility or sigma
    char OpType = 'C';  // 'C'all or 'P'ut
    cout<<"Enter Underlying Price :\n";
    cin>>S;
    cout<<"Enter Strike Price :\n";
    cin>>K;
    cout<<"Enter Time to Expiration :\n";
    cin>>T;
    cout<<"Enter Current risk free rate :\n";
    cin>>r;
    cout<<"Enter 'C' to get Call Option Price or 'P' to get Put Option Price : \n";
    cin>>OpType;


    cout << "Black Scholes Price for "<<OpType<<"E is : "<< BSPrice (S, K, T, r, d, v, OpType) << endl;
};