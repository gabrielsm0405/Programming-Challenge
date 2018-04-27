#include <iostream>

using namespace std;

int main(){
	int N, P;
	cin>>N>>P;

	int resp=0;

	for(int c1=0; c1<N; c1++){
		int x, y;
		cin>>x>>y;

		if(x+y>=P) resp++;
	}

	cout<<resp;

	return 0;
}