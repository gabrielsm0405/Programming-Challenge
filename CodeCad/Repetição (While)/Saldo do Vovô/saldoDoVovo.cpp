#include <iostream>

using namespace std;

int main(){
	int N, S;
	cin>>N>>S;

	int resp=1000000;

	for(int c1=0; c1<N; c1++){
		int val;
		cin>>val;

		S+=val;

		if(S<resp) resp=S;
	}

	cout<<resp;

	return 0;
}