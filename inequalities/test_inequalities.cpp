#include <iostream> 
using namespace std ;
#include "inequalities.hpp"

int main()
{
    double d1, d2;
    //Prompt the user for input : 
    cout << "Give the first number";
    cin >> d1 ; 
    cout << "Give the second number";
    cin >> d2;


    char function_to_use ; 
    cout << "What function du you want to use ? \n a) Max   b) Min " ;
    cin >> function_to_use ;
    if (function_to_use == 'a'){
        cout << "Max value is : " << Max(d1, d2) << endl ;

    }
    else{
        cout <<"Min value is : " << Min(d1, d2) <<endl ; 

    }
    return 0 ; 

}


// For compilation, we used : g++ -o test-inequalities test_inequalities.cpp inequalities.cpp


