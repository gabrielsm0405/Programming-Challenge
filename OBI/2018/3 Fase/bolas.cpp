#include <bits/stdc++.h>

using namespace std;

int main(){
    int nums[10], maior=0;

    memset(nums, 0, sizeof(nums));

    for(int c1=0; c1<8; c1++){
        int num;
        cin>>num;

        nums[num]++;

        if(nums[num]>maior) maior = nums[num];
    }

    if(maior<=4) cout<<"S";
    else cout<<"N";

    return 0;
}