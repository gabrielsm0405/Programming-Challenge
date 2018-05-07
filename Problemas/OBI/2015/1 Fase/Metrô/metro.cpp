#include <bits/stdc++.h>

using namespace std;

struct ESTACAO{
	int qtdLig;

	ESTACAO **ligacoes;
}* estacoes;

int getLigacoes(int);

int main(){
	int n, m;
	cin>>n>>m;

	estacoes=(ESTACAO *)calloc(n, sizeof(ESTACAO));

	int estCentral=getLigacoes(m);

	return 0;
}

int getLigacoes(int m){
	int qtdLigMax=0;
	int estCentral;

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

		if(estacoes[val1-1].qtdLig>qtdLigMax && estacoes[val1-1].qtdLig<=100){
			qtdLigMax=estacoes[val1-1].qtdLig;

			estCentral=val1;
		}

		if(estacoes[val2-1].qtdLig>qtdLigMax && estacoes[val2-1].qtdLig<=100){
			qtdLigMax=estacoes[val2-1].qtdLig;

			estCentral=val2;
		}		
	}

	return estCentral;
}