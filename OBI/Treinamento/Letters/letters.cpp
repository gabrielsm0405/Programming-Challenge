#include <bits/stdc++.h>

using namespace std;

typedef struct{
	long long valOri, valAlt;
}DORM;

int main(){
	int n, m;
	cin>>n>>m;

	DORM dorm[1000000], regis=0;
	for(int c1=0; c1<n; c1++){
		cin>>dorm[c1].valOri;

		dorm[c1].valAlt=dorm[c1].valOri;

		dorm[c1].valAlt+=regis;

		regis+=dorm[c1].valAlt;
	}

	//Tem que colocar tudo em uma minheap a partir de valAlt e qaundo for ler os números nas cartas
	//Verifica se cada numero é menor do que a raiz da min_heap, se for, massa achei o dormintório, se não
	//Extrai a raiz e faz de novo
	//Pesquisar como implementar min_heap no c++

	for(int c1=0; c1<m; c1++){

	}

	return 0;
}