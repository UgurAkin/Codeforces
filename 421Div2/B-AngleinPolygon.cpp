/*
Author: Ugur Akin
Brief Problem Description:
	We are given:
		- A regular polygon with "n" edges
		- An arbitrary angle between 1 and 180 inclusive
		- Vertices of the polygon are named starting from 1 to n, rotating clockwise.
	Goal: Find a vertix trio (distinct vertices) such that
		  the angle they define is the closest to the given angle.
	Key points:
		 - An interior angle of a polygon with "n" edges is: (n-2) * 180/n
		 - A unit interior angle is the smallest angle between any distinct 3 vertices 
			(the angle between an edge and the closest diagonal to it)
		 - It can be shown that with each next diagonal, the angle is increased by a unit interior angle
			(an edge and the closest diagonal is 1 uia, 2nd closest is 2 u.i.a.'s... last is (n-2)u.i.a.'s.
		 - Therefore, the unit interior angle of a polygon with n edges is: 180/n
		 - We find how many interior angles makes up the closest angle to the given angle
Full Problem: http://codeforces.com/contest/820/problem/B
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	int n, angle;
	cin >> n >> angle;

	float unitInteriorAngle = 180.0 / n;

	//find the lowerbound to how many u.i.a's we need
	//upperbound naturally is lowerbound+1
	int minUnitInteriorAngles = angle / unitInteriorAngle; 

	int amtUnitInteriorAngles = 0; 
	if (minUnitInteriorAngles >= n - 2)// note that we can at most have "n-2" u.i.a's
	{
		amtUnitInteriorAngles = n - 2;
	}
	else
	{
		//check which of the bounds is closer to the given angle
		amtUnitInteriorAngles =
					abs(unitInteriorAngle*minUnitInteriorAngles - angle)
					< abs(unitInteriorAngle*(minUnitInteriorAngles + 1) - angle)
					? minUnitInteriorAngles : minUnitInteriorAngles + 1;

		//we can't have 0 as an angle since that would require two of the vertices to be the same
		amtUnitInteriorAngles = amtUnitInteriorAngles == 0 ? 1 : amtUnitInteriorAngles;
	}

	cout << "2 1 " << amtUnitInteriorAngles + 2;
}