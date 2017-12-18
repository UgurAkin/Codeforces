/*
* Author: Ugur Akin
* Brief Problem Description:
*  - 2n people, n-1 double kayaks, 2 single kayaks
*  - Instability of a double kayak is the difference between weights of the people occupying it
*  - Instability of a single kayak is 0
*  - Goal: Minimize total instability
* Key Points:
*  - If there are two people of the same weight, optimal action is to put them together
*  - Given an ordered list of people with distinct weights, optimal action is to pair them in order
*  - [Wrong approach for picking sinle kayakers]: Put the most instable pair in single kayaks. (Ctr Ex: 3,6,7,15: opt:3,15; my apr: 7,15 )

*/

#include <iostream>
#include <vector>
using namespace std;

const int MAX_WEIGHT = 1000;

int main() {

	vector<bool> amt_weight_map(MAX_WEIGHT, 0);
	short amtKayaks;
	cin >> amtKayaks;

	for (size_t i = 0; i < 2 * amtKayaks; i++)
	{
		int nextWeight;
		cin >> nextWeight;

		amt_weight_map[nextWeight] = amt_weight_map[nextWeight] ^ 1;
	}

	bool semiPair = 0;
	size_t firstWeight = 0;
	int maxInstability = 0;
	int totalInstability = 0;
	for (size_t weight = 1; weight < MAX_WEIGHT; weight++)
	{
		if (amt_weight_map[weight])
		{
			if (semiPair)
			{
				int curDiff = weight - firstWeight;
				totalInstability += curDiff;
				if (curDiff > maxInstability)
				{
					maxInstability = curDiff;
				}
				firstWeight = 0;
				semiPair = false;
			}
			else
			{
				firstWeight = weight;
				semiPair = true;
			}
		}
	}
	totalInstability -= maxInstability;

	cout << totalInstability;
}