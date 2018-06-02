#include <bits/stdc++.h>

using namespace std;

struct Stave{
	long long vol;

	bool used;
};

Stave staves[100010];
long long volMax=-1, volMin=-1;
int n, k;
long long l;

long long knapsack(long long volTotal, long long barrilVol, int num){
	if(volMax-volMin>l) return 0;

	long long maxVol=0;

	bool found=false;

	for(int c1=0; c1<n*k; c1++){
		if(!staves[c1].used){
			/*cout<<staves[c1].vol<<endl;
			getchar();
			getchar();*/

			staves[c1].used=true;

			long long curVol;

			barrilVol=min(barrilVol, staves[c1].vol);

			if(num==k){
				if(barrilVol>volMax || volMax==-1) volMax=barrilVol;

				if(barrilVol<volMin || volMin==-1) volMin=barrilVol;

				curVol=knapsack(volTotal+barrilVol, 1000000001, 1);
			}
			else curVol=knapsack(volTotal, barrilVol, num+1);

			if(curVol>maxVol) maxVol=curVol;

			staves[c1].used=false;

			found=true;
		}
	}

	if(!found) return volTotal;

	return maxVol;
}

int main(){
	cin>>n>>k>>l;

	for(int c1=0; c1<n*k; c1++){
		long long vol;
		cin>>vol;

		staves[c1].vol=vol;
		staves[c1].used=false;
	}

	cout<<knapsack(0, 1000000001, 1);

	return 0;
}