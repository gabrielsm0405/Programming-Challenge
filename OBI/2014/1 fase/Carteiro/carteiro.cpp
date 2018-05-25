#include <bits/stdc++.h>

using namespace std;

int binarySearch(long long cas[], long long enc, int n){
	int ini=0, fim=n-1, meio;

	while(ini<=fim){
		meio=(ini+fim)/2;

		if(cas[meio]==enc) return meio;
		else if(cas[meio]>enc) fim=meio-1;
		else ini=meio+1;
	}

	return 0;
}

int main(){
	int n, m;

	cin>>n>>m;

	long long cas[50000];
	for(int c1=0; c1<n; c1++) cin>>cas[c1];

	int ind=0, resp=0;

	for(int c1=0; c1<m; c1++){
		long long enc;
		cin>>enc;

		int search=binarySearch(cas, enc, n);

		resp+=(abs(search-ind));

		ind=search;
	}

	cout<<resp;

	return 0;
}