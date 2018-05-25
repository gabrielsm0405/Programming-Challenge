#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;

	int resp=0;

	for(int c1=1; c1<=n; c1++){
		if(n%c1==0) resp++;
	}

	cout<<resp;

	return 0;
}