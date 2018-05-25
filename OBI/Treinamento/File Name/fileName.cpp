#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;

	string fileName;
	cin>>fileName;

	int num=0, resp=0;

	for(int c1=0; c1<n; c1++){
		if(fileName[c1]!='x') num=0;
		else{
			num++;

			if(num>=3) resp++;
		}
	}

	cout<<resp;

	return 0;
}