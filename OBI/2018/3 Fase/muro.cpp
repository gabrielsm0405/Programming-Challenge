#include <bits/stdc++.h>

using namespace std;

#define MAXN 10010

long long dp[MAXN];

long long backtracking(int n){
    if(n==2) return 5;
    if(n==1 || n==0) return 1;

    if(dp[n]!=-1) return dp[n];

    return dp[n] = (1*backtracking(n-1))%(1000000000+7) + (4*backtracking(n-2))%(1000000000+7) + (2*backtracking(n-3))%(1000000000+7);
}

int main(){
    int n;
    cin>>n;

    memset(dp, -1, sizeof(dp));

    cout<<backtracking(n);

    return 0;
}