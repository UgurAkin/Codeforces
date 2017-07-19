#include <iostream>
#include <math.h>
using namespace std;

int main(){
	string name;
	cin >> name;
	
	int sum = 0;
	char pointer = 'a';
	for(int i = 0; i < name.length(); i++){
		int dif = abs(pointer - name[i]);
		sum += dif < 26 - dif ? dif : 26 - dif;
		pointer = name[i];
	}
	
	cout << sum;
}
