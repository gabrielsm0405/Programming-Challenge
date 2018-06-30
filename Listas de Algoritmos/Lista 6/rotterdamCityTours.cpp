#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adj[100000];
int dist[100000], qtd[100000];

void dijkstra(int s){
	memset(dist, 0x3f, sizeof(dist));

	dist[s]=0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
	heap.push({0, s});

	while(!heap.empty()){
		int d=heap.top().first;
		s=heap.top().second;

		heap.pop();

		if(d>dist[s]) continue;

		for(auto& p:adj[s]){
			int x=p.first, y=p.second;

			if(dist[s]+x<dist[y]){
				dist[y]=dist[s]+x;
				heap.push({dist[y], y});
			}
		}
	}
}

int main(){
	int N, M, cont=0;
	while(cin>>N>>M){
		for(int c1=0; c1<=N; c1++) adj[c1].clear();

		memset(qtd, 0, sizeof(qtd));

		int s;

		for(int c1=1; c1<=M; c1++){
			int x, y, dist;
			cin>>x>>y>>dist;

			adj[x].push_back({dist, y});
			adj[y].push_back({dist, x});

			qtd[x]++;
			qtd[y]++;
		}

		for(int c1=0; c1<=N; c1++){
			if(qtd[c1]==1 || qtd[c1]>2){
				s=c1;
				break;
			}
		}

		dijkstra(s);

		cout<<"caso "<<cont<<endl;

		bool imprimi=false;

		for(int c1=0; c1<=N; c1++){
			if(qtd[c1]>2 || qtd[c1]==1){
				if(imprimi) cout<<" ";
				cout<<dist[c1];
				imprimi=true;
			}
		}

		cout<<endl<<endl;
		
		cont++;
	}

	return 0;
}