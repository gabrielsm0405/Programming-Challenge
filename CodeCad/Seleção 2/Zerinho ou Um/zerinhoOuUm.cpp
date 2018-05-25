#include <iostream>

using namespace std;

int main(){
	int A, B, C;
	cin>>A>>B>>C;

	int resp=100*A+10*B+C;

	switch(resp){
		case 100: 
		case 11:
			cout<<"A";
		break;
		case 10:
		case 101:
			cout<<"B";
		break;
		case 1:
		case 110:
			cout<<"C";
		break;
		default:
			cout<<"*";
		break;
	}

	return 0;
}