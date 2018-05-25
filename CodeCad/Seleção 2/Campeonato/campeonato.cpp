#include <iostream>

using namespace std;

int main(){
	int Cv, Ce, Cs, Fv, Fe, Fs;
	cin>>Cv>>Ce>>Cs;
	cin>>Fv>>Fe>>Fs;

	int pC=3*Cv+Ce, pF=3*Fv+Fe;

	if(pC>pF) cout<<"C";
	else if(pF>pC) cout<<"F";
	else if(Cs>Fs) cout<<"C";
	else if(Fs>Cs) cout<<"F";
	else cout<<"=";

	return 0;
}