#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	long long w;
	cin>>n>>w;

	long long ini=0, fim=w;

	int regis=0;

	for(int c1=0; c1<n; c1++){
		int a;
		cin>>a;

		regis+=a;

		if(regis*-1>ini) ini=regis*-1;

		if(w-regis<fim) fim=w-regis;
	}

	if(fim-ini>=0) cout<<fim-ini+1;
	else cout<<"0";

	return 0;
}