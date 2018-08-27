#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010

int main(){
    int n;
    cin>>n;

    int num[MAXN];

    for(int c1=0; c1<n; c1++) cin>>num[c1];

    int replace=-1;

    for(int c1=0; c1<n; c1++){
        if(num[c1]==0){
            replace=c1;
            break;
        }

        if(num[c1]==5){
            replace=c1;

            if(num[n-1]>=5){
                break;
            }
        }
    }

    if(replace!=-1){
        int aux=num[replace];
        num[replace] = num[n-1];
        num[n-1] = aux;

        for(int c1=0; c1<n; c1++) cout<<num[c1]<<" ";
    }
    else cout<<"-1";

    return 0;
}