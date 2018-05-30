i#nclude <bits/stdc++.h>

using namespace std;

int particiona(int A[10], int ini, int fim){
	int esq=ini;
	int dir=fim;

	int pivo=A[ini];
	while(esq<dir){
		while(A[esq]<=pivo) esq++;
		while(A[dir]>pivo) dir--;

		if(esq<dir){
			int aux=A[esq];

			A[esq]=A[dir];
			A[dir]=aux;
		}
	}

	A[ini]=A[dir];
	A[dir]=pivo;

	return dir;
}

void quicksort(int A[10], int ini, int fim){
	if(ini<fim){
		int pivo=particiona(A, ini, fim);

		quicksort(A, ini, pivo-1);
		quicksort(A, pivo+1, fim);
	}
}

int main(){
	int A[10];

	for(int c1=0; c1<10; c1++) 	cout<<A[c1]<<" ";

	cout<<"\n";

	quicksort(A, 0, 9);

	getchar();
	getchar();

	for(int c1=0; c1<10; c1++) 	cout<<A[c1]<<" ";

	cout<<"\n";

	getchar();
	getchar();

	return 0;
}