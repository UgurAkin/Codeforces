/*
Author: Ugur Akin
Brief problem description:
	We are given:
		- amount of pages in the book
		- an initial reading speed
		- a daily increment in reading speed
		- a reading speed limit
		- and a setback amount we have to re-read next day
	Goal: Calculate the days we need to read the book.
	Key Points: Once we read the last page, we are done.
				Consideration of edge cases where setback
				is counted even after reading the last page.

Full Description: http://codeforces.com/contest/820/problem/A
*/

#include <iostream>
using namespace std;

int main() {
	
	int amtPages, initV, limV, incV, setback;
	cin >> amtPages >> initV >> limV >> incV >> setback;

	int curV = initV; //current reading speed
	int amtRead = setback; //to compensate for the first day, set to "setback" 
	int daysPassed = 0;

	//by using do..while instead of while loop
	//we make sure our alg. works in cases setback>amtPages.
	do
	{
		amtRead -= setback;
		amtRead += curV;

		curV+= incV;
		curV = curV > limV ? limV : curV;
		daysPassed++;
	} while (amtRead < amtPages);

	cout << daysPassed;
}
