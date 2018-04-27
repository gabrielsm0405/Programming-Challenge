#include <iostream>

using namespace std;

int main(){
	int x;
	cin>>x;

	int achei1=0;
	for(int c1=1; c1<=x; c1++){
		if(x%c1==0){
			if(achei1==1) cout<<" ";
			
			cout<<c1;

			achei1=1;
		}
	}

	return 0;
}