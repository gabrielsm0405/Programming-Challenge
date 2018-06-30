#include <bits/stdc++.h>

using namespace std;

struct Vertex{
	int id;

	Vertex **conec;
	int qtdConec;

	bool visited;
};

Vertex *grafos;

bool bfs(int id, int firstId, int large){
	if(grafos[id-1].qtdConec>2) return false;

	if(id==firstId && large!=0) return true;

	if(grafos[id-1].visited) return false;

	grafos[id-1].visited=true;

	for(int c1=0; c1<grafos[id-1].qtdConec; c1++){
		if(bfs(grafos[id-1].conec[c1]->id, firstId, large+1)) return true;
	}

	return false;
}

int main(){
	int n, m;
	cin>>n>>m;

	grafos=(Vertex *)calloc(n, sizeof(Vertex));

	for(int c1=0; c1<m; c1++){
		int id1, id2;
		cin>>id1>>id2;		

		grafos[id1-1].id=id1;
		grafos[id1-1].conec=(Vertex **)realloc(grafos[id1-1].conec, (grafos[id1-1].qtdConec+1)*sizeof(Vertex *));
		grafos[id1-1].conec[grafos[id1-1].qtdConec]=&grafos[id2-1];
		grafos[id1-1].qtdConec++;
		grafos[id1-1].visited=false;

		grafos[id2-1].id=id2;
		grafos[id2-1].conec=(Vertex **)realloc(grafos[id2-1].conec, (grafos[id2-1].qtdConec+1)*sizeof(Vertex *));
		grafos[id2-1].conec[grafos[id2-1].qtdConec]=&grafos[id1-1];
		grafos[id1-1].qtdConec++;
		grafos[id2-1].visited=false;
	}

	int resp=0;

	for(int c1=1; c1<=n; c1++){
		if(bfs(c1, grafos[c1-1].id, 0)) resp++;
	}

	cout<<resp;

	return 0;
}
