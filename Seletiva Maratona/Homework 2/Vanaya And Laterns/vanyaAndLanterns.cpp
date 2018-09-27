#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	long long l;
	cin>>n>>l;

	long long luz[1010];
	for(int c1=0; c1<n; c1++) cin>>luz[c1];

	sort(luz, luz+n);
	
	double maior = luz[0];

	for(int c1=0; c1<n; c1++){
		if(c1>0 && (double)abs(luz[c1] - luz[c1-1])/2 > maior){
			maior = (double)abs(luz[c1] - luz[c1-1])/2;
		}

		if(c1<n-1 && (double)abs(luz[c1] - luz[c1+1])/2 > maior){
			maior = (double)abs(luz[c1] - luz[c1+1])/2;
		}

		if(c1 == n-1 && abs(luz[c1] - l) > maior){
			maior = (double)abs(luz[c1] - l);
		}
	}
	
	printf("%f\n", maior);

	return 0;
}
