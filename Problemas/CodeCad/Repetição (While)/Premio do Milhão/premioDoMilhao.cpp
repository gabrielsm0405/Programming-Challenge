#include <iostream>

using namespace std;

int main(){
	int N;
	cin>>N;

	int soma=0, resp=0;

	for(int c1=0; c1<N; c1++){
		int A;
		cin>>A;

		if(soma<1000000){
			soma+=A;

			resp++;
		}
	}

	cout<<resp;

	return 0;
}