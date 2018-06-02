#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; k;
	cin>>n>>k

	bool nums[110];	
	memset(nums, false, sizeof(nums));

	int time[110], int cont=0;

	for(int c1=0; c1<n; c1++){
		int num;
		cin>>num;

		if(!nums[num]){
			time[cont]=c1+1;

			cont++;
		}

		nums[num]=true;
	}

	if(cont==k){
		cout<<"YES"<<endl;

		for(int c1=0; c1<cont; c1++) cout<<time[c1]<<" ";
	}
	else cout<<"NO";

	return 0;
}