The code will tell the Call/Put Price of an Option depending on your input.

### Input format:

double S = 100.0;  // Stock Price
double K = 100.0;  // Strike Price
double T = 1;   // Years to maturity
double r = 0.05;  // Risk free interest rate
double d = 0.0;  //Devidend consideration for index it's zero
double v = 0.20;  // Yearly volatility or sigma
char OpType = 'C';  // 'C' for Call or 'P' for Put
