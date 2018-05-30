#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;

	int nums[110];

	for(int c1=0; c1<n/2; c1++) cin>>nums[c1];	

	sort(nums, nums+n/2);
		
	int dist1=0, dist2=0;

	for(int c1=0; c1<n/2; c1++){
		dist1+=abs((2*c1+1)-nums[c1]);
		dist2+=abs((2*c1+2)-nums[c1]);
	}

	cout<<min(dist1, dist2);

	return 0;
}