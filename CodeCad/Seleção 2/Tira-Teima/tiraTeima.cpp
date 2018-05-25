#include <iostream>

using namespace std;

int main(){
	int x, y;
	cin>>x>>y;

	if(x<0 || x>432 || y<0 || y>468) cout<<"fora";
	else cout<<"dentro";

	return 0;
}