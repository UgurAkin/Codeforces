#include <iostream>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int grade;
		cin >> grade;
		sum += grade;
	}
	int eqSol = (n*(2*k - 1) - 2*sum);
	eqSol = eqSol > 0 ? eqSol : 0;
	cout << eqSol;
	return 0;
}


