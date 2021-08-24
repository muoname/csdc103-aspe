// Filename        : approx.cpp
// Description     : This source file contains the implementation of the 
//                   function to approximate the value of PI.
// Author          : 
// Honor Code      : I have not asked nor given any aunthorized help
//                   in completing this exercise.

#include "approx.h"
using namespace std;

long double approx_pi(int n){
  
    long double approx;
    long double sequence = 1;
    
    if (n == 1) 
    {
        approx = 4 * sequence;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
			long double temp = ( 1.0 / ((i * 2.0) - 1.0));
            if ((i % 2) == 0)
            {
                sequence = sequence - temp;  
            }
            else  if ((i % 2) == 1)
            {
                sequence = sequence + temp;
            }
        }

        approx = 4 * sequence;
    }

    return approx;

}