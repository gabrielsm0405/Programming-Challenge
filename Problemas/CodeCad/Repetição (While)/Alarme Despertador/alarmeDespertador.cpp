#include <iostream>

using namespace std;

int main(){
	int h1, m1, h2, m2;

	do{
		cin>>h1>>m1;
		cin>>h2>>m2;

		int resp;

		if(h1!=0 || m1!=0 || h2!=0 || m2!=0){
			if(h1>h2 || (h1==h2 && m1>m2)) resp=(1440+h2*60+m2)-(60*h1+m1);
			else resp=(60*h2+m2)-(60*h1+m1);

			cout<<resp<<endl;
		}

	}while(h1!=0 || m1!=0 || h2!=0 || m2!=0);

	return 0;
}