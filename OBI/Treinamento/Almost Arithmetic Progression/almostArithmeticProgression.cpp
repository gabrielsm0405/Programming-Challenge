#include <bits/stdc++.h>

using namespace std;

int n;
long long seq[100010], r;
priority_queue <int, vector<int>, greater<int> > min_heap;
bool found=false;

void verifica(long long x, int pos, int soma){
	if(pos==n){
		found=true;
		min_heap.push(soma);

		return;
	}

	if((seq[pos]-1)-x==r || pos==1){
		r=(seq[pos]-1)-x;
		verifica(seq[pos]-1, pos+1, soma+1);
	}

	if((seq[pos])-x==r || pos==1){
		r=(seq[pos])-x;
		verifica(seq[pos], pos+1, soma);
	}

	if((seq[pos]+1)-x==r || pos==1){
		r=(seq[pos]+1)-x;
		verifica(seq[pos]+1, pos+1, soma+1);
	}
}

int main(){
	cin>>n;

	for(int c1=0; c1<n; c1++) cin>>seq[c1];

	verifica(seq[0]-1, 1, 1);
	verifica(seq[0], 1, 0);
	verifica(seq[0]+1, 1, 1);

	if(found) cout<<min_heap.top();
	else cout<<"-1";
	
	return 0;
}