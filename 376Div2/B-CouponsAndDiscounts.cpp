#include <iostream>
using namespace std;

int LIMIT = 10000;

int main(){
	int n;
	cin >> n;
	
	int numTeams[LIMIT];
	for(int i = 0; i < n; i++){
		cin >> numTeams[i];
	}
	
	string result = "YES";
	for(int i = 0; i < n; i++){
		if(numTeams[i] % 2 != 0){
			if(i == n){
				result = "NO";
			}
			else{
				numTeams[i+1]--;
			}
		}
	}
	
	cout << result;
}
