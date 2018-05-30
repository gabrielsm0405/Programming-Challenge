#include <bits/stdc++.h>

using namespace std;

class Dorm{
	long long valOri, valAlt;

public:
	Dorm(long long _valOri, long long _valAlt){
		valOri=_valOri;
		valAlt=_valAlt;
	}

	Dorm(){}

	long long getValOri() const { return valOri; }

	long long getValAlt() const { return valAlt; }
};

class MyComparator{
public:
	int operator() (const Dorm& p1, const Dorm& p2){
		return p1.getValAlt() > p2.getValAlt();
	}
};

int main(){
	int n, m;
	cin>>n>>m;

	priority_queue <Dorm, vector<Dorm>, MyComparator > min_heap;

	long long regis=0;
	for(int c1=0; c1<n; c1++){
		long long aux;
		cin>>aux;

		min_heap.push(Dorm(aux, aux+regis));

		regis=aux+regis;
	}

	int dormNumber=1;
	for(int c1=0; c1<m; c1++){
		long long b;
		cin>>b;

		bool sair=false;
		while(!sair){
			if(b<=min_heap.top().getValAlt()){
				cout<<dormNumber<<" "<<min_heap.top().getValOri()-(min_heap.top().getValAlt()-b)<<endl;
				sair=true;
			}
			else{
				min_heap.pop();

				dormNumber++;
			}
		}
	}

	return 0;
}