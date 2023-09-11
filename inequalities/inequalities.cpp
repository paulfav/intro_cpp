#include "inequalities.hpp"

//Max and Min of two numbers

double Max (double x, double y)
{
    if (x > y )
        return x ;
    
    return y ; 

}

double Min (double x, double y)
{
    if (x < y )
        return x ;
    
    return y ; 

}

double Min (double x, double y, double z)
{
    double t = Min( x , y);
    if (t < z )
        return t ;
    
    return z ; 

}


double Max (double x, double y, double z)
{
    double t = Max( x , y);
    if (t > z )
        return t ;
    
    return z ; 

}