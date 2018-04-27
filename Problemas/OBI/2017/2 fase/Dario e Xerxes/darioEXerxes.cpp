#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;

	int pD=0, pX=0;

	for(int c1=0; c1<n; c1++){
		int d, x;
		cin>>d>>x;

		int resp=10*d+x;

		switch(resp){
			case 1:
			case 2:
			case 12:
			case 13:
			case 23:
			case 24:
			case 30:
			case 34:
			case 40:
			case 41:
				pD++;
			break;
			default:
				pX++;
			break;
		}
	}

	if(pD>pX) cout<<"dario";
	else cout<<"xerxes";

	return 0;
}