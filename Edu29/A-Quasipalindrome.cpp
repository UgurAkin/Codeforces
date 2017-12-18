/*
* Author: Ugur Akin
* Brief Problem Description:
*  - We are asked whether or not a given string (e.g. 02010200) is quasi-palindrome or not.
*  - A string is quasi-palindrome if it is palindrome when leading and tailing zeros are ignored.
*  - Full problem available at: http://codeforces.com/contest/863/problem/A
* Approach:
*  - Two iterators pointing at both ends of the string, skip leading and tailing 0s and check if 
*/

#include <iostream>
#include <string>
using namespace std;

int main() {

	string isPali;
	getline(cin, isPali);

	//point one iterator at the beginning and one at the end
	size_t head = 0, tail = isPali.length() - 1;
	
	// a flag to indicate a given input consits only of 0s
	bool allZero = false; 
	
	//skip leading 0s, stop if reach the end (all chars are 0s)
	while (!allZero && !(isPali[head]-'0'))
	{
		if (head = tail)
		{
			allZero = true;
		}
		head++;
	}

	//skip all the tailing 0s
	while (!allZero && !(isPali[tail] - '0'))
	{
		tail--;
	}

	//check if remaining string is palindrome
	string ans = "YES";
	while (!allZero && tail > head )
	{
		if (isPali[head] != isPali[tail])
		{
			ans = "NO";
			break;
		}
		tail--;
		head++;
	}

	cout << ans;
}