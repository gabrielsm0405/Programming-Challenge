#include <bits/stdc++.h>

using namespace std;

string s;

int verPali(int c1, int c2){
	if(c1>c2 || c1==c2) return 1;

	if(s[c1]!=s[c2]) return 0;

	return verPali(c1+1, c2-1);
}

int main(){
	cin>>s;

	int n=s.length();

	for(int c1=0; c1<n; c1++){
		for(int c2=n-1; c2>=c1; c2--){
			if(verPali(c1, c2)==0){
				cout<<c2-c1+1;

				return 0;
			}
		}
	}

	cout<<"0";

	return 0;
}