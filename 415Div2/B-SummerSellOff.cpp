#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

auto compareFunc = [](pair<int,int> a , pair<int,int> b)
{
	if (a.second < b.second)
	{
		return true;
	}
	return false;
};

int main(){
	int numDays, numSales;
	cin >> numDays >> numSales;
	vector<pair<int,int>> prod_cust; 
	vector<pair<int,int>> index_CVal;
	for (int i = 0; i < numDays; i++)
	{
		int numCust,numProd;
		cin >> numProd >> numCust;
		prod_cust.push_back(make_pair(numProd,numCust));
		int CVal = numProd*2 > numCust ? numCust : numProd*2 ; 
		index_CVal.push_back(make_pair(i,CVal));
	}

	priority_queue<pair<int,int>, vector<pair<int,int>> ,decltype(compareFunc)> list(compareFunc,index_CVal);

	for (int i = 0; i < numSales; i++)
	{
		prod_cust[list.top().first].first *= 2;
		list.pop();
	}
	
	long long sum = 0;
	for (int i = 0; i < numDays; i++)
	{
		pair<int,int> val = prod_cust[i];
		sum += val.first < val.second ? val.first : val.second;
	}

	cout << sum;
	

}


