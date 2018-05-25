#include <bits/stdc++.h>

using namespace std;

struct ESTACAO{
	int qtdLig;

	int val;

	ESTACAO **ligacoes;

	bool visitada;
}* estacoes;

ESTACAO *estCentral;

ESTACAO *getLigacoes(int);

int findCircle(ESTACAO *);

int main(){
	int n, m;
	cin>>n>>m;

	estacoes=(ESTACAO *)calloc(n, sizeof(ESTACAO));

	estCentral=getLigacoes(m);

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
	//cout<<"Estacao="<<curEst->val<<endl;

	//getchar();
	//getchar();

	if(curEst==estCentral) return -1000000;

	if(curEst->qtdLig<2) return -1000000;

	if(curEst->visitada) return -1000000;

	int circleMax=0;

	curEst->visitada=true;

	for(int c1=0; c1<curEst->qtdLig; c1++){

		int circle=1+findCircle(curEst->ligacoes[c1]);

		if(circle>circleMax) circleMax=circle;
	}

	//cout<<"Est"<<curEst->val<<" Dist="<<circleMax<<endl;

	//getchar();
	//getchar();

	curEst->visitada=false;

	return circleMax;
}

ESTACAO *getLigacoes(int m){
	int maxQtdLig=0;
	ESTACAO *curEstCentral;

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

		estacoes[val1-1].val=val1;
		estacoes[val2-1].val=val2;

		if(estacoes[val1-1].qtdLig>maxQtdLig){
			maxQtdLig=estacoes[val1-1].qtdLig;

			curEstCentral=&estacoes[val1-1];
		}

		if(estacoes[val2-1].qtdLig>maxQtdLig){
			maxQtdLig=estacoes[val2-1].qtdLig;

			curEstCentral=&estacoes[val2-1];
		}
	}

	return curEstCentral;
}
