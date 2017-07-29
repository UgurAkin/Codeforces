#include <iostream>
using namespace std;

int findAmt(int k, int r){
	for(register int i = 1; i < 10; i++){
		int rem = k*i % 10;
		if(rem == r || rem == 0){
			return i;
		}
	}
	return 10;
}

int  main(){
	int k,r;
	cin >> k >> r;
	
	cout << findAmt(k,r);

}
