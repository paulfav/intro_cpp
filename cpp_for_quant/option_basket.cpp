
// Pricing the derivative Max(S1_T, S2_T) where S1 and S2 are two correlated processes.



# include "random.h"
# include <iostream>
# include <cmath>
# include <algorithm>

using namespace std ; 

int main()
{
    cout << "\n ** Start Monte Carlo Option Basket ** \n" << endl ;

    // STEP 1 : INPUT PARAMETERS

    double T = 1 ; 
    double K = 100; //strike price
    double S0_barclays = 120; // initial price barclays
    double S0_rolls = 100; // initial price rolls-royce
    double vol_barclays = 0.1 ; // 
    double vol_rolls = 0.15 ; //
    int number_sim = 10000 ; 
    int number_steps = 300 ;
    double S_barclays[number_steps +1] ; 
    double S_rolls[number_steps +1] ;
    double r = 0.05 ;  // interest rate
    double dt = T / number_steps ;
    double sumpayoff = 0 ; 
    double premium = 0 ; 
    double rho = 0.5 ; 


    // Simulation loop

    for (int j = 0 ; j < number_sim ; j++)
    {
        S_barclays[0] = S0_barclays ; 
        S_rolls[0] = S0_rolls ; 

        for (int t = 0 ; t < number_steps ; t++)
        {
            double epsi_barc1 = SampleBoxMuller() ; 
            double epsi_rolls1 = SampleBoxMuller() ; 

            double epsi_barc = epsi_barc1 ; 
            double epsi_rolls = rho * epsi_barc + sqrt(1- rho * rho) * epsi_rolls1 ; 

            S_rolls[t+1] = S_rolls[t] * (1 + r * dt + vol_rolls * sqrt(dt) * epsi_rolls);
            S_barclays[t+1] = S_barclays[t] * (1 + r * dt + vol_barclays * sqrt(dt) * epsi_barc);

        }

        sumpayoff += max(S_rolls[number_steps], S_barclays[number_steps]);
    }

    premium =  exp(-r*T)*(sumpayoff / number_sim);  


    // STEP 6: OUTPUT RESULTS  
    cout <<"premium =  " << premium << "\n";  
    cout << "\n *** END EQ2: Monte Carlo Option Basket *** \n";  
    return 0;

}



