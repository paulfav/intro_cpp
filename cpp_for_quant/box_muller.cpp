// Computing Gaussian deviates using Box_muller method : from uniform to normal 

#include "random.h"
#include <cstdlib>
#include <cmath>
using namespace std ;

double SampleBoxMuller()
{
    double result ; 
    double x ;
    double y;

    double xy; 

    double xysquare ;

    do
    { 
        x = 2.0 * rand()/ static_cast<double>(RAND_MAX) - 1 ;
        y = 2.0 * rand()/ static_cast<double>(RAND_MAX) - 1 ;
        xysquare = x*x + y*y ; 

    } while (xysquare >= 1.0);

    result = x*sqrt(-2*log(xysquare)/xysquare) ; 

    return result;
    
}
