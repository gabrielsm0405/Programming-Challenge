#include <bits/stdc++.h>

using namespace std;

struct Prog{
	unsigned int skill;
	int resp;
};

class MyComparator{
public:
	int operator() (Prog *a, Prog *b){
		return a->skill > b->skill;
	}
};

priority_queue <Prog *, vector<Prog *>, MyComparator> min_heap;

int main(){
	int n, k;
	cin>>n>>k;

	Prog progs[200010];

	for(int c1=0; c1<n; c1++){
		unsigned int skill;
		cin>>skill;

		progs[c1].skill=skill;

		min_heap.push(&progs[c1]);
	}

	unsigned int ant=0;
	int reg;

	for(int c1=0; c1<n; c1++){
		if(ant!=min_heap.top()->skill) reg=0;
		else reg++;

		min_heap.top()->resp=c1-reg;

		ant=min_heap.top()->skill;

		min_heap.pop();
	}

	for(int c1=0; c1<k; c1++){
		int x, y;
		cin>>x>>y;

		if(progs[x-1].skill<progs[y-1].skill) progs[y-1].resp--;
		else if(progs[y-1].skill<progs[x-1].skill) progs[x-1].resp--;
	}

	for(int c1=0; c1<n; c1++){
		if(c1!=n-1) cout<<progs[c1].resp<<" ";
		else cout<<progs[c1].resp;
	}

	return 0;
}

