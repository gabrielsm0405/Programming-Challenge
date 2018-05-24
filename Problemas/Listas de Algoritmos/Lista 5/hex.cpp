#include <bits/stdc++.h>

using namespace std;

typedef struct{
	char val;

	bool visitado;
}CELULA;

CELULA matriz[510][510];
int n;

bool backtrack(int r, int c, char s, int *area){
	matriz[r][c].visitado=true;

	(*area)++;

	bool resp=false;

	if(c+1<n){
		if(matriz[r][c+1].val==s && !matriz[r][c+1].visitado){
			if(backtrack(r, c+1, s, area)) resp=true;
		}
	}

	if(r+1<n){
		if(matriz[r+1][c].val==s && !matriz[r+1][c].visitado){
			if(backtrack(r+1, c, s, area)) resp=true;
		}
	}

	if(r+1<n && c-1>=0){
		if(matriz[r+1][c-1].val==s && !matriz[r+1][c-1].visitado){
			if(backtrack(r+1, c-1, s, area)) resp=true;
		}
	}

	if(c-1>=0){
		if(matriz[r][c-1].val==s && !matriz[r][c-1].visitado){
			if(backtrack(r, c-1, s, area)) resp=true;
		}
	}

	if(r-1>=0){
		if(matriz[r-1][c].val==s && !matriz[r-1][c].visitado){
			if(backtrack(r-1, c, s, area)) resp=true;
		}
	}

	if(r-1>=0 && c+1<n){
		if(matriz[r-1][c+1].val==s && !matriz[r-1][c+1].visitado){
			if(backtrack(r-1, c+1, s, area)) resp=true;
		}
	}

	if(s=='B' && c==n-1) resp=true;
	if(s=='W' && r==n-1) resp=true;

	return resp;
}

bool verificaB(int *areaB){
	for(int c1=0; c1<n; c1++){
		if(matriz[c1][0].val=='B' && !matriz[c1][0].visitado){
			*areaB=0;
			if(backtrack(c1, 0, 'B', areaB)) return true;
		}
	}

	return false;
}

bool verificaW(int *areaW){
	for(int c1=0; c1<n; c1++){
		if(matriz[0][c1].val=='W' && !matriz[0][c1].visitado){
			*areaW=0;
			if(backtrack(0, c1, 'W', areaW)) return true;
		}
	}

	return false;
}

int main(){
	int cont=0;

	while(cin>>n){
		char s;
		cin>>s;

		string positions;
		getline(cin, positions);

		for(int c1=0; c1<n; c1++){
			for(int c2=0; c2<n; c2++){
				matriz[c1][c2].val='-';
				matriz[c1][c2].visitado=false;
			}
		}

		do{
			getline(cin, positions);

			if(!positions.empty()){
				int spaceId=positions.find(' ');

				int r=stoi(positions.substr(0, spaceId));
				int c=stoi(positions.substr(spaceId+1, positions.length()-(spaceId+1)));

				matriz[r][c].val=s;

				if(s=='B') s='W';
				else s='B';
			}
		}while(!positions.empty());

		int areaW, areaB;

		cout<<"caso "<<cont<<": ";

		if(verificaB(&areaB)) cout<<"B"<<" "<<areaB<<endl<<endl;
		else{
			verificaW(&areaW);
			cout<<"W"<<" "<<areaW<<endl<<endl;
		}

		cont++;
	}	

	return 0;
}