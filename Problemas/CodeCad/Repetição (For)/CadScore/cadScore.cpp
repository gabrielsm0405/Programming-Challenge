#include <iostream>

using namespace std;

int main(){
	int p, n;
	cin>>p>>n;

	for(int c1=0; c1<n; c1++){
		int f;
		cin>>f;

		p+=f;

		if(p>100) p=100;

		if(p<0) p=0;
	}

	cout<<p;

	return 0;
}