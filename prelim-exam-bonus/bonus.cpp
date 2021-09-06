
// Filename     : bonus.cpp
// Description  : This program checks whether digit d is found in digit n
// Author       : Eugene Lance Aspe
// Honor Code   : I have not asked nor given any aunthorized help
//                in completing this exercise.

#include <iostream>
using namespace std;

bool contains_digit(int n, int d)
{
	bool ans = false; // initiates the default answer to false
	while (n > 0) // starts the loop as long as n is not 0
	{
		if (n % 10 == d) // checks whether the ones digit is equal to d
		{
			ans = true; // if the ones digit is equal to d then the ans variable is updated to true
			break; // it then breaks the loop
		}
		else n = n / 10; //if not, this line of code will divide the number by 10, making shifting the decimal place to the left
		
		
	}
	
	return ans; //return the ans
}

int main()
{
	int t;
	cin >> t; //checks how many test cases are there
	for (int i = 0;i < t; i++)
	{
		int n, d; 
		cin >> n >> d; //takes the input for n and d
		
		if (contains_digit(n, d)) //checks whether the function returns true or false
		{
			cout << "CASE " << i + 1 << " : FOUND" << endl; //if it is true, then the program will output "FOUND"
		}
		else cout << "CASE " << i + 1 << " : NOT FOUND" << endl; //else, it will output NOT FOUND
	}
	
	return 0;
}