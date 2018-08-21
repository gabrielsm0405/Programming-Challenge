#include <bits/stdc++.h>

using namespace std;

#define MAX 1010

vector<pair<int, int>> adj[MAX];
int dist[MAX];

void dikjistra(int orig){
    priority_queue< pair<int, int>, vector<pair <int, int>>, greater<pair <int, int>> > heap;

    memset(dist, 0x3f, sizeof dist);
    dist[orig]=0;

    heap.push({0, orig});

    while(!heap.empty()){
        int d = heap.top().first;
        orig = heap.top().second;

        heap.pop();

        if(d > dist[orig]) continue;

        for(auto& p : dist[orig]){
            int x = p.first;
            int y = p.second;

            if(dist[x] + x < dist[y]){
                dist[y] = dist[orig] + x;
                heap.push({dist[y], y});
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    for(int c1=0; c1<m; c1++){
        int u, v, p;
        cin>>u>>v>>p;

        adj[u].push_back({v, p});
        adj[v].push_back({u, p});
    }

    int orig;
    cin>>orig;

    dikjistra(orig);

    return 0;
}