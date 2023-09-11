// Main file for Monte Carlo Simulation


#include "random.h"
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main ()
{
    cout << "\n ** Start Monte Carlo European Call ** \n" << endl ;

    // STEP 1 : INPUT PARAMETERS

    double T = 1 ; 
    double K = 100; //strike price
    double S0 = 100; // initial price
    double sigma = 0.3 ; // sqrt(volatility)
    int number_sim = 100000 ; 
    int number_steps = 1000 ;
    double S[number_steps +1] ; 
    double r = 0.05 ;  // interest rate
    double dt = T / number_steps ; 
    double sigmatimesinc = sigma * sqrt(dt);
    double sumpayoff = 0 ; 
    double premium = 0 ; 



    // Main simulation loop : 
    for (int j = 0 ; j <= number_sim ;  j++)
    {
        S[0] = S0 ; 
        // Time Loop
        for (int t = 0 ; t < number_steps ; t++)
        {
            double epsilon = SampleBoxMuller();
            S[t+1] = S[t]*(1 + r*dt + epsilon * sigmatimesinc);
        }

        sumpayoff += max(S[number_steps] - K, 0.0); // compute and ad payoff

    }
    premium =  exp(-r*T)*(sumpayoff / number_sim);  


    // STEP 6: OUTPUT RESULTS  
    cout <<"premium =  " << premium << "\n";  
    cout << "\n *** END EQ1: Monte Carlo single asset *** \n";  
    return 0;


}