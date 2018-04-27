#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;

	while(scanf("%d", &n)!=EOF){
		int botas[61][2];

		for(int c1=30; c1<=60; c1++){
			for(int c2=0; c2<2; c2++) botas[c1][c2]=0;
		}

		for(int c1=0; c1<n; c1++){
			int tam;
			char lado;
			cin>>tam>>lado;

			if(lado=='D') botas[tam][0]++;
			else botas[tam][1]++;
		}

		int resp=0;

		for(int c1=30; c1<=60; c1++){
			if(botas[c1][0]!=0 && botas[c1][1]!=0) resp+=(botas[c1][0]+botas[c1][1])/2;
		}

		cout<<resp<<endl;
	}

	return 0;
}