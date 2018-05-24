#include <bits/stdc++.h>

using namespace std;

struct PAPEL{
	char cor;
	bool visitado;
};

int n, dp[1000][1000];

PAPEL **papel;

int backtrack(int l, int c){
	if(papel[l][c].visitado) return 1000000;

	if(papel[l][c].cor=='0') return 0;

	if(dp[l][c]!=-1) return dp[l][c];

	int dists[4];

	for(int c1=0; c1<4; c1++) dists[c1]=100000;

	papel[l][c].visitado=true;

	if(l>0) dists[0]=1+backtrack(l-1, c);
	if(c>0) dists[1]=1+backtrack(l, c-1);
	if(l<n-1) dists[2]=1+backtrack(l+1, c);
	if(c<n-1) dists[3]=1+backtrack(l, c+1);

	papel[l][c].visitado=false;

	sort(dists, dists+4);

	return dp[l][c]=dists[0];
}

int main(){
	cin>>n;

	papel=(PAPEL **)malloc(n*sizeof(PAPEL *));

	for(int l=0; l<n; l++){
		char *cores=(char *)malloc((n+1)*sizeof(char));
		cin>>cores;

		papel[l]=(PAPEL *)malloc(n*sizeof(PAPEL));
		for(int c=0; c<n; c++){
			papel[l][c].cor=cores[c];
			papel[l][c].visitado=false;
		}
	}

	memset(dp, -1, sizeof(dp));

	for(int l=0; l<n; l++){
		for(int c=0; c<n; c++){
			if(papel[l][c].cor=='*'){
				int menorDist=backtrack(l , c);

				papel[l][c].cor=(char)(menorDist+48);
			}

			cout<<papel[l][c].cor;
		}

		cout<<endl;
	}

	return 0;
}