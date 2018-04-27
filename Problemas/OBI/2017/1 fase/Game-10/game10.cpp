#include <bits/stdc++.h>

using namespace std;

int main(){
	int N, D, A;

	cin>>N>>D>>A;

	int resp=0;

	while(A!=D){
		resp++;

		A++;

		if(A>N) A=1;
	}

	cout<<resp;

	return 0;
}