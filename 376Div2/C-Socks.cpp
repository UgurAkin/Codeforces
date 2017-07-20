/*
	This problem was a bit over my head, i tried to solve it by myself.
	Even though i had the theory right, i couldn't implement the solution.
	As a last resort, i checked out succesful submissions to educate myself.
	Once understanding the logic behind a few solutions i came across, i implemented my own version.
	Credit to fellow competitors for implementation.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int LIMIT = 200009; // It's time consuming to use dynamic memory allocation.
vector<int> graph[LIMIT];
int colorsOfSocks[LIMIT];
bool markForConnection[LIMIT] = {};
unordered_map<int,int> amtSocksInColor;
int colorMax = 0, countAll = 0;

void depthFirstSearch(int node){
	/*depthFirstSearch the graph starting from node
	  mark all visited nodes to assert connectivity
	  count all the nodes in the connected component(countAll)
	  track the color which has the highest amount of socks(colorMax)
	*/

	markForConnection[node] = 1;							//mark the node as visited.
	amtSocksInColor[colorsOfSocks[node]]++;					// increase the amt of socks in this sock's color
	countAll++;												//increase the total count of nodes in the connected component

	//check if the color with highest amt of socks has changed after the counts are updated:
	if (amtSocksInColor[colorsOfSocks[node]] > amtSocksInColor[colorsOfSocks[colorMax]]) 
	{
		colorMax = node;
	}
	
	//move no to the next node, depth first.
	for (int i = 0; i < graph[node].size(); i++)
	{
		if (!markForConnection[graph[node][i]])
		{
			depthFirstSearch(graph[node][i]);
		}
		
	}
}


int main(){
	int amtSocks, amtDays, amtColors;
	cin >> amtSocks >> amtDays >> amtColors;

	for (int i = 0; i < amtSocks; i++)
	{
		cin >> colorsOfSocks[i]; 
	}
	for (int i = 0,left,right; i < amtDays; i++)
	{
		cin >> left >> right;
		graph[--left].push_back(--right);
		graph[right].push_back(left);
	}
	//solution:
	int total = 0;
	for (int i = 0; i < amtSocks; i++)
	{
		if (!markForConnection[i]) //if current node is not a part of any of the previous connected components.
		{
			//default all necessary values:
			colorMax = i, countAll = 0;
			amtSocksInColor.clear();
			
			//Key algorithm
			depthFirstSearch(i);

			total += countAll - amtSocksInColor[colorsOfSocks[colorMax]];
		}
	}

	cout << total;

}