#include <iostream>

using namespace std;

int main(){
	int max=0, num;

	do{
		cin>>num;


		if(num>max) max=num;
	}while(num!=0);

	cout<<max;

	return 0;
}