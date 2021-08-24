// Filename        : main.cpp
// Description     : This program tests the implementation of the 
//                   function to approximate the value of PI.
// Author          : 
// Honor Code      : I have not asked nor given any aunthorized help
//                   in completing this exercise.

#include <iostream>
#include <iomanip>
#include "approx.h"
using namespace std;

int main(){
    
	int inputs;
    cin >> inputs;
	for (int i = 1; i <= inputs; i++)
	{
		int n;
		cin >> n;
		cout << fixed << setprecision(15) << "CASE " << i << ": " << approx_pi(n) << endl;
	}
    
    return 0;
}