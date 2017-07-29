#include <iostream>
using namespace std;

const int LIMIT = 505;

int wrap(int x){
	if (x < 0)
	{
		return 0;
	}
	return x;
}

int main(){
	int n,k;
	cin >> n >> k;
	int a[LIMIT] ={};
	int dist[LIMIT] = {};
	cin >> a[0];
	for (int i = 1; i < n; i++)
	{
		cin >> a[i];
		dist[i-1] = wrap(k - a[i] - a[i-1]);

	}
	int sum = 0;
	for (int i = 0; i < n-2; i++)
	{
		if (dist[i] != 0)
		{
			a[i+1] += dist[i];
			sum += dist[i];
			dist[i+1] = wrap(dist[i+1]-dist[i]);
		}

	}
	auto last = dist[n-2] > 0 ? dist[n-2] : 0;
	a[n-2] += last;
	sum += last;

	cout << sum << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}