#include <bits/stdc++.h>

using namespace std;

string seq;

int verPali(int c1, int c2){
	if(c1>c2 || c1==c2) return 1;

	if(seq[c1]!=seq[c2]) return 0;

	return verPali(c1+1, c2-1);
}

int main(){
	int N;
	cin>>N;

	cin>>seq;

	int c3=1, resp=0;

	for(int c1=0; c1<N;){
		for(int c2=N-1; c2>=c1; c2--){
			if(verPali(c1, c2)==1){
				resp++;

				c1=c2+1;

				break;
			}
		}
	}

	cout<<resp;

	return 0;
}