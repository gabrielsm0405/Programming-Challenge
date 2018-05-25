#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;

	vector<long long> rets;
	long long max=0;
	for(int c1=0; c1<n; c1++){
		long long num;
		cin>>num;

		rets.push_back(num);

		if(num>max) max=num;
	}

	int respMax=0;

	for(int c1=0; c1<n; c1++){
		int resp=0;
		bool acheiMaior=false;

		for(int c2=0; c2<n; c2++){
			if(rets[c2]>rets[c1]){
				if(!acheiMaior) resp++;

				acheiMaior=true;
			}
	 		else acheiMaior=false;
		}

		if(resp>respMax) respMax=resp;
	}

	cout<<respMax+1;

	return 0;
}