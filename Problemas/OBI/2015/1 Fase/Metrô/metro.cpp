#include <bits/stdc++.h>

using namespace std;

struct ESTACAO{
	int qtdLig;

	ESTACAO **ligacoes;

	bool visitada;
}* estacoes;

void getLigacoes(int);

int findCircle(ESTACAO *);

int main(){
	int n, m;
	cin>>n>>m;

	estacoes=(ESTACAO *)calloc(n, sizeof(ESTACAO));

	getLigacoes(m);

	int respMax=0;

	for(int c1=0; c1<n; c1++){
		int resp=findCircle(&estacoes[c1]);

		if(resp>respMax) respMax=resp;
	}

	cout<<respMax<<endl;

	getchar();
	getchar();

	return 0;
}

int findCircle(ESTACAO *curEst){
	if(curEst->qtdLig<2) return -1;

	if(curEst->visitada) return 0;

	int circleMax=0;

	curEst->visitada=true;

	for(int c1=0; c1<curEst->qtdLig; c1++){

		int circle=1+findCircle(curEst->ligacoes[c1]);

		if(circle>circleMax) circleMax=circle;
	}

	curEst->visitada=false;

	return circleMax;
}

void getLigacoes(int m){
	for(int c1=0; c1<m; c1++){
		int val1, val2;
		cin>>val1>>val2;

		estacoes[val1-1].ligacoes=(ESTACAO **)realloc(estacoes[val1-1].ligacoes, (estacoes[val1-1].qtdLig+1)*sizeof(ESTACAO *));

		estacoes[val2-1].ligacoes=(ESTACAO **)realloc(estacoes[val2-1].ligacoes, (estacoes[val2-1].qtdLig+1)*sizeof(ESTACAO *));

		estacoes[val1-1].ligacoes[estacoes[val1-1].qtdLig]=(ESTACAO *)malloc(sizeof(ESTACAO));
		estacoes[val1-1].ligacoes[estacoes[val1-1].qtdLig]=&estacoes[val2-1];

		estacoes[val2-1].ligacoes[estacoes[val2-1].qtdLig]=(ESTACAO *)malloc(sizeof(ESTACAO));
		estacoes[val2-1].ligacoes[estacoes[val2-1].qtdLig]=&estacoes[val1-1];

		estacoes[val1-1].qtdLig++;
		estacoes[val2-1].qtdLig++;
	}
}
