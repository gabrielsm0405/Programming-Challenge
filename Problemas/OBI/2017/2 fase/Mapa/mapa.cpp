#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> mapa;

int L, C;

void backtrack(int *l, int *c){
	if(*l>0){
		if(mapa[*l-1][*c]=='H'){
			mapa[*l-1][*c]='h';
			*(l)--;
			backtrack(l, c);
		}
	}

	if(*c>0){
		if(mapa[*l][*c-1]=='H'){
			mapa[*l][*c-1]='h';
			*(c)--;
			backtrack(l, c);
		}
	}

	if(*l<L-1){
		if(mapa[*l+1][*c]=='H'){
			mapa[*l+1][*c]='h';
			*(l)++;
			backtrack(l, c);
		}
	}

	if(*c<C-1){
		if(mapa[*l][*c+1]=='H'){
			mapa[*l][*c+1]='h';
			*(c)++;
			backtrack(l, c);
		}
	}
}

int main(){
	cin>>L>>C;

	int lIni, cIni;

	for(int c1=0; c1<L; c1++){
		vector<char> letras;
		for(int c2=0; c2<C; c2++){
			char letra;
			cin>>letra;

			if(letra=='o'){
				lIni=c1;
				cIni=c2;
			}

			letras.push_back(letra);
		}

		mapa.push_back(letras);
	}

	backtrack(&lIni, &cIni);

	cout<<lIni<<" "<<cIni;

	return 0;
}