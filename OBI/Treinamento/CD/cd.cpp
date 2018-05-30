#include <bits/stdc++.h>

using namespace std;

int main(){
	int n=1, m=1;

	while(n!=0 || m!=0){
		cin>>n>>m;

		if(n!=0 || m!=0){
			unsigned int vetor[1000010];

			for(int c1=0; c1<n; c1++){
				unsigned int num;
				cin>>num;

				vetor[c1]=num;
			}

			int resp=0;

			for(int c1=0; c1<m; c1++){
				unsigned int num;
				cin>>num;

				if(binary_search(vetor, vetor+n, num)) resp++;

			}

			cout<<resp<<endl;
		}
	}

	return 0;
}