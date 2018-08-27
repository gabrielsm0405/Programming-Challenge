#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010

struct Balde{
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
};

Balde baldes[MAXN];

int opr2(int a, int b){
    int dif1, dif2;

    int maior=0, menor=1000000, id;

    for(int c1=a-1; c1<=b-1; c1++){
        if(baldes[c1].max_heap.top()>maior){
            maior = baldes[c1].max_heap.top();
            id=c1;
        }
    }

    for(int c1=a-1; c1<=b-1; c1++){
        if(baldes[c1].min_heap.top()<menor && c1!=id){
            menor = baldes[c1].min_heap.top();
        }
    }

    dif1 = maior-menor;

    maior=0;
    menor=1000000;

    for(int c1=a-1; c1<=b-1; c1++){
        if(baldes[c1].min_heap.top()<menor){
            menor = baldes[c1].min_heap.top();
            id=c1;
        }
    }

    for(int c1=a-1; c1<=b-1; c1++){
        if(baldes[c1].max_heap.top()>maior && c1!=id){
            maior = baldes[c1].max_heap.top();
        }
    }

    dif2 = maior-menor;

    return max(dif1, dif2);
}

int main(){
    int n, m;
    cin>>n>>m;

    for(int c1=0; c1<n; c1++){
        int bola;
        cin>>bola;

        baldes[c1].min_heap.push(bola);
        baldes[c1].max_heap.push(bola);
    }

    for(int c1=0; c1<m; c1++){
        int opr, a, b;

        cin>>opr>>a>>b;

        if(opr==1){
            baldes[b-1].min_heap.push(a);
            baldes[b-1].max_heap.push(a);
        }
        else{
            cout<<opr2(a, b)<<endl;
        }
    }

    return 0;
}