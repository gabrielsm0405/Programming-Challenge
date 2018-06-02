#include <bits/stdc++.h>

using namespace std;

string strs[110];

bool compare(string a, string b){
	return a.size()<b.size();
}

int main(){
	int n;
	cin>>n;

	for(int c1=0; c1<n; c1++) cin>>strs[c1];

	sort(strs, strs+n, compare);
	
	bool ndeu=false;

	for(int c1=0; c1<n-1; c1++){
		if(strs[c1+1].find(strs[c1])==string::npos){
			ndeu=true;

			cout<<"NO";

			break;
		}
	}

	if(!ndeu){
		cout<<"YES"<<endl;
		for(int c1=0; c1<n; c1++) cout<<strs[c1]<<endl;
	}


	return 0;
}
