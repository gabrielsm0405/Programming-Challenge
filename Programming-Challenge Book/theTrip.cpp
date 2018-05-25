#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;

	do{
		cin>>n;

		if(n!=0){
			double pays[n], media=0.0;

			for(int c1=0; c1<n; c1++){
				cin>>pays[c1];

				media=(double)media+pays[c1];
			}

			media=media/n;

			double resp=0.0;

			for(int c1=0; c1<n; c1++){
				if(pays[c1]>media) resp=(double)resp+pays[c1]-media;
			}

			cout.precision(2);
  			cout.setf(ios::fixed);

			cout<<resp<<"\n";
		}

	}while(n!=0);

	return 0;
}