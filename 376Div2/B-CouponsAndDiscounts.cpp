#include <iostream>
using namespace std;

int LIMIT = 200000;

int main(){
	int n;
	cin >> n;
	
	int numTeams[LIMIT];
	for(int i = 0; i < n; i++){
		cin >> numTeams[i];
	}
	
	string result = "YES";
	for(int i = 0; i < n; i++){
		if(numTeams[i] < 0){
			result = "NO";
			break;
		}
		if(numTeams[i] % 2 != 0){
			if(i == n-1){
				result = "NO";
			}
			else{
				numTeams[i+1]--;
			}
		}
	}
	
	cout << result;
}
