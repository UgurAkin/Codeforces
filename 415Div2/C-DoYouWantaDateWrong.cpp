//This was my first try, wrong idea... 
//Data storage is too much, works for smaller sizes.
//True solution should be using math to reduce relevant data...


#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

const int BASE = 1E9 + 7;
const int LIMIT = 50;
vector<tuple<int,int,int,int> > list;
int x[LIMIT];
int nthPower2( int n){
	int result = 1;
	if (n <= 0)
	{
		return result;
	}
	while( n > 30){
		result = (((1 << 30) % BASE) * result) % BASE;
		n -= 30;
	}
	result = (((1 << n)% BASE) * result) % BASE;
	return result;
}

int main(){
	int n;
	cin >> n;
	
	
	
	for(int i = 0; i < n; i++){
		cin >> x[i];
		for(int k = 0; k < i; k++){
			list.push_back(make_tuple(i,k,abs(x[i]-x[k]),0));
		}
	}
	
	sort(list.begin(),list.end(),[](const tuple<int,int,int,int> &a,const tuple<int,int,int,int> &b){
						return get<2>(a) > get<2>(b);});

	for(int i = 0; i<list.size(); i++){
		for(int k = 0; k < i; k++){
			if(get<0>(list[k]) == get<0>(list[i]) || get<0>(list[k]) == get<1>(list[i])
			|| get<1>(list[k]) == get<0>(list[i]) ||get<1>(list[k]) == get<1>(list[i]) ){
				get<3>(list[i])++;
			}
		}
	}
	int result = 0;
	for(int i = 0; i<list.size(); i++){
		result = (result + (get<2>(list[i]) * nthPower2(n - 2 - get<3>(list[i]))) % BASE) % BASE;
	}
	
	cout << result;
}


