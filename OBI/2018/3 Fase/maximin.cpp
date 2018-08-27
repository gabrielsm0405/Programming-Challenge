#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010

int main(){
    int n;
    long long l, r;

    cin>>n>>l>>r;

    int a[MAXN];

    for(int c1=0; c1<n; c1++){
        cin>>a[c1];
    }

    long long maior = -1000000000;

    for(long long c1=l; c1<=r; c1++){
        long long menor = 1000000000;
        for(int c2=0; c2<n; c2++){
            if(abs(c1-a[c2])<menor) menor = abs(c1-a[c2]);
        }

        if(menor>maior) maior = menor;
    }

    cout<<maior;

    return 0;
}