#include <iostream>

using namespace std;

int main(){
	int P1, C1, P2, C2;
	cin>>P1>>C1;
	cin>>P2>>C2;

	int t1=P1*C1, t2=P2*C2;

	if(t1>t2) cout<<"-1";
	else if(t2>t1) cout<<"1";
	else cout<<"0";

	return 0;
}