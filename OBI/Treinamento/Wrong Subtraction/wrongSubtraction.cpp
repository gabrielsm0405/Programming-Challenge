#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n;
	int k;

	cin>>n>>k;

	for(int c1=0; c1<k; c1++){

		if(n%10==0) n/=10;
		else n--;
	}

	cout<<n;

	return  0;
}