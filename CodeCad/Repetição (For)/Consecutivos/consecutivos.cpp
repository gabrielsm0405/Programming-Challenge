
#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;

	long long ant;
	int valAt=1, valMax=0;
	for(int c1=0; c1<n; c1++){
		long long num;
		cin>>num;

		if(num==ant && c1>0) valAt++;
		else{
			if(valAt>valMax) valMax=valAt;

			valAt=1;

			ant=num;
		}
	}

	if(valAt>valMax) valMax=valAt;

	cout<<valMax;

	return 0;
}