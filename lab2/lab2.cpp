// Filename : lab2.cpp
//
// Description : This code defines and tests the following 4
// functions:
//
// 	(1) count_vowels(s) which accepts a string s formed by the
// 	lettersof the English alphabet, returns the total number
// 	of vowels in s (regardless of the letter
// 	being an uppercase or lowercase).
//
// 	This function uses the decomposition method where n is
// 	decreased by 1 and the last element is left out.
//      +---------------+   +----+
//  A = |               | + |    |
//      +---------------+   +----+
//         A[0:n-1]          A[n]
//  
// 	Using this method, the array is split into two: 
//			1: The array from the first element to n - 1 element
// 			2: The last element
//	
//	This function uses the following mathematical recurrence:
//		
//	count_vowels(s) = {0 - if the last letter or only letter is not a vowel (base case)
// 					  {1 - if the last letter or only letter is a vowel (base case)
// 					  {0 + count_vowels(s - 1) if there are more than 
//												one letter and it is not a vowel (recurring case)
// 					  {1 + count_vowels(s - 1) if there are more than 
//												one letter and it is a vowel (recurring case)
//
//
//	(2) binary_to_decimal(n) given an integer whose digits are either zero 
//	or one, returns the number whose binary representation is precisely the
//	sequence of zeros and ones in b.
//
// 	This function uses the decomposition method where n is
// 	decreased by 1 and the last element is left out.
//      +---------------+   +----+
//  A = |               | + |    |
//      +---------------+   +----+
//         A[0:n-1]          A[n]
//
//  Using this method, the array is split into two: 
//			1: The array from the first element to n - 1 element
// 			2: The last element
//
// 	This function uses the following mathematical recurrence:
//
// 	binary_to_decimal(b) {0 if b == 0 (base case)
// 						 {0 + 2 * binary_to_decimal(b / 10) if the current last digit is 0 (recurring case)
// 						 {1 + 2 * binary_to_decimal(b / 10) if the current last digit is 1 (recurring case)
//
//
// 	(3) search(A, n, x) given an integer array A containing n elements, returns 
//  the index or position number of the first occurrence of the integer x if x is
//  in A or  -1 otherwise.
//
//	This function uses the decomposition method where n is
// 	decreased but the first element in the array is left out
//      +----+   +--------------+
//  A = |    | + |              |
//      +----+   +--------------+
//       A[0]       A[1:n]
//
//  Using this method, the array is split into two: 
//			1: The first element of the array
// 			2: The subarray from the second element down to the last element   
//   
// 	This function uses the following mathematical recurrence:
//
// 	search(A, n, x) {-1 if the element is not in the array (base case)
// 					{0 if the element is the first element (base case)
// 					{k where k is the index of the first occurence of the
//						element in the array through the recursion of
//						search(A + 1, n - 1, x) (recurring case)
// 	
// 	
// 	(4) search_sorted(A, n, x)given an integer array A containing n elements 
//	which are sorted in increasing order, returns the index or position
//	number of any occurrence of the integer x if x is in A or -1 otherwise.
// 	
//	This function uses the decomposition method where n is
// 	roughly split in half
//	    +--------+     +--------+
//  A = |        |  +  |        |
//      +--------+     +--------+
//       A[0:n/2]		A[n/2:n]
// 	
// 	This function uses the following mathematical recurrence:
// 	
// 	search_sorted(A, n, x) {-1 if n == -1 (base case)
// 						   {-1 if x is greater than the last element (base case)
// 						   {-1 if x is less than the first element (base case)
// 						   {k where k is the index of the first occurence
//									of the array whether it be on the
//									upper or lower half through
//									the recurrence of search_sorted(A, n - i, x)
//									where i = n / 2 if n < A[i] else the recurrence
//									of search_sorted(A, n - 1, x) (recurring case)
//
//
// Author : Eugene Lance V. Aspe
// easpe@gbox.adnu.edu.ph
//
// Honor Code : I have not received nor given any unauthorized help
//


#include <iostream>
#include <string>
using namespace std;

bool check_vowel(char x) // a function to check if the given parameter is a vowel, used in count_vowels(s) function
{
	if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'
		|| x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
		return true;
	else return false;
}

int count_vowels(string s)
{
	if (s.length() == 1) return check_vowel(s.at(0)); // since the string is a single letter, it's either a vowel or not
	return (check_vowel(s.at(s.length() - 1)) ? 1 : 0) + count_vowels(s.substr(0, s.length() - 1)); 
	// if it is not a single vowel, it then proceeds to the recurring case
	// the recurring case checks whether if the last letter on the string is a vowel
	// return 0 or 1 accordingly, it then proceeds to remove the last letter
	// in the string.
}

int binary_to_decimal(int b)
{
	if (b == 0) return 0; //base case, this executes when the binary reaches the farthest digit
	return b % 10 + 2 * binary_to_decimal(b / 10); //checks whether the digit is a 1 or 0
												   //then that is added to 2 multiplied by the next digit
}

int search(int A[], int n, int x)
{
	if (n < 1) return -1; //base case, if n is less than 1, then it is done checking the array
	if (A[0] == x) return 0; //base case, if the first element is the target, then it returns the index 0
	else
	{
		int k = search(A + 1, n - 1, x); //gives k the value of the function search while adding 1 to the pointer pointing to A
										 //while subtracting 1 to n
		
		return k == - 1 ? k : k + 1;	 //checks whether the function returned -1 or not
	}
}

int search_sorted(int A[], int n, int x)
{
	if (n == -1) return -1; //base case, if n is -1, then it is done checking the array
	if (x > A[n - 1]) return - 1; //base case, if x is greater than the last element, then it is not within the array
	if (x < A[0]) return -1; //base case, if x is less than the first element, then it is not within the array
	else
	{
		int k = n/2;   //roughly splits the number of elements into two
		if (A[k] >= x) //checks whether x is in the upper or lower half
			return A[k] == x ? k : search_sorted(A, n - k, x); //recurrence if x is in the lower half and checks the rest of the array
		else return A[n - 1] == x ? n - 1  : search_sorted(A, n - 1, x); //recurrence if x is in the upper half and checks the rest of the array
	}
}

int main()
{
	cout << "count_vowels() function:" << endl;
	cout << count_vowels("Test") << endl; //prints "1"
	cout << count_vowels("AEIOU") << endl; //prints "5"
	cout << count_vowels("Ransu Desu") << endl; //prints "4"
	cout << count_vowels("aDAFbf aEmbnFur") << endl; //prints "5"
	
	cout << "binary_to_decimal() function:" << endl;
	cout << binary_to_decimal(100) << endl; //prints "4"
	cout << binary_to_decimal(1010101) << endl; //prints "85"
	cout << binary_to_decimal(11111) << endl; //prints "31"
	cout << binary_to_decimal(0) << endl; //prints "0"
	cout << binary_to_decimal(1) << endl; //prints "1"
	
	int A[9] {5,5,4,6,2,1,8,9,10};
	
	cout << "search() function:" << endl;
	cout << search(A, 9, 10) << endl; //prints "8"
	cout << search(A, 9, 5) << endl; //prints "0"
	cout << search(A, 9, 4) << endl; //prints "2"
	cout << search(A, 9, 8) << endl; //prints "6"
	cout << search(A, 9, 1) << endl; //prints "5"
	cout << search(A, 9, -20) << endl; //prints "-1"
	cout << search(A, 9, 0) << endl; //prints "-1"
	
	int A1[9] {1,2,4,5,5,6,8,9,10};
	cout << "search_sorted() function:" << endl;
	cout << search(A1, 9, 10) << endl; //prints "8"
	cout << search(A1, 9, 5) << endl; //prints "3"
	cout << search(A1, 9, 4) << endl; //prints "2"
	cout << search(A1, 9, 8) << endl; //prints "6"
	cout << search(A1, 9, 1) << endl; //prints "0"
	cout << search(A1, 9, -20) << endl; //prints "-1"
	cout << search(A1, 9, 0) << endl; //prints "-1"
	
}
