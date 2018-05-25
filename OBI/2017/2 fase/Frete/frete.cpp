#include <bits/stdc++.h>

using namespace std;

int dp[1000000];

struct CIDADE{
	int numCid;
	int nCidVis;
	CIDADE **cidVis;
	int *custos;
	bool visitado;
};

int n;

int backtrack(CIDADE *cid){
	if(dp[cid->numCid]!=-1) return dp[cid->numCid];

	if(cid->numCid==n) return 0;

	if(cid->visitado) return -1;

	cid->visitado=true;

	int min=1000000;
	for(int c1=0; c1<cid->nCidVis; c1++){
		int cam=backtrack(cid->cidVis[c1]);

		if(cam!=-1){
			cam+=cid->custos[c1];

			if(cam<min) min=cam;
		}
	}

	cid->visitado=false;

	return dp[cid->numCid]=min;
}

int main(){
	int m;
	cin>>n>>m;

	CIDADE *cidades=(CIDADE *)calloc(n, sizeof(CIDADE));

	memset(dp, -1, sizeof(dp));

	for(int c1=0; c1<m; c1++){
		int a, b, c;
		cin>>a>>b>>c;

		a--;
		b--;

		cidades[a].numCid=a+1;
		cidades[b].numCid=b+1;

		cidades[a].visitado=false;
		cidades[b].visitado=false;

		cidades[a].cidVis=(CIDADE **)realloc(cidades[a].cidVis, (cidades[a].nCidVis+1)*sizeof(CIDADE *));
		cidades[a].cidVis[cidades[a].nCidVis]=&cidades[b];

		cidades[b].cidVis=(CIDADE **)realloc(cidades[b].cidVis, (cidades[b].nCidVis+1)*sizeof(CIDADE *));
		cidades[b].cidVis[cidades[b].nCidVis]=&cidades[a];

		cidades[a].custos=(int *)realloc(cidades[a].custos, (cidades[a].nCidVis+1)*sizeof(int));
		cidades[a].custos[cidades[a].nCidVis]=c;

		cidades[b].custos=(int *)realloc(cidades[b].custos, (cidades[b].nCidVis+1)*sizeof(int));
		cidades[b].custos[cidades[b].nCidVis]=c;

		cidades[a].nCidVis++;		
		cidades[b].nCidVis++;
	}

	cout<<backtrack(&cidades[0]);

	return 0;
}