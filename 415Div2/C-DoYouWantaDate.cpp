//Only partially correct, can't pass all the test cases.
//I suspect it has something to do with overflow/binary problems.

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
const int BASE = 1E9 + 7;
vector<int> list;

int nthPower2(int n){
	if(n <= 0){
		return 1;
	}
	long long result = 1;
	while (n > 20)
	{
		result = (result * ((1 << 30) % BASE)) % BASE;
		n -= 20;
	}
	result = (result * ((1 << n) % BASE)) % BASE;
	return result;
}


int main(){
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		list.push_back(x);
	}
	//for (int i = 0; i < 200; i++)
	//{
	//	cout << "i = " << i << ",\t2^i = " << nthPower2(i) << endl;
	//}

	sort(list.begin(),list.end(), greater<int>());

	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum =  (sum + ((nthPower2(n-1-i) - nthPower2(i)) * list[i]) % BASE) % BASE;
	}
	cout << sum;
}