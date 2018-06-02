#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;
	cin>>str;

	int resp=0;

	int c1;

	bool found=false;

	for(c1=str.size()-1; c1>=0; c1--){
		if(str[c1]=='0' || str[c1]=='5'){
			resp+=(str.size()-c1);
			found=true;
			break;
		}
	}

	if(found){
		char cur=str[c1];
		found=false;
		for(c1=c1+1; c1>=0; c1--){
			if(cur=='0' && (str[c1]=='0' || str[c1]=='5')){
				resp+=(str.size()-c1);
				found=true;
				break;
			}

			if(cur=='5' && (str[c1]=='2' || str[c1]=='7')){
				resp+=(str.size()-c1);
				found=true;

				break;
			}
		}
	}

	if(found) cout<<resp;
	else cout<<"-1";

	return 0;
}
