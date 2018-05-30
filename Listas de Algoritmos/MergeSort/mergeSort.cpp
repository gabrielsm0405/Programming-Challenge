#include <bits/stdc++.h>

using namespace std;

void mergeSort(vector<int> &v){
	if(v.size()==1) return;

	vector<int> u1, u2;

	for(int c1=0; c1<v.size()/2; c1++) u1.push_back(v[c1]);

	for(int c1=v.size()/2; c1<v.size(); c1++) u2.push_back(v[c1]);

	mergeSort(u1);
	mergeSort(u2);
	
	u1.push_back(1000000);
	u2.push_back(1000000);

	int p1=0, p2=0;

	for(int c1=0; c1<v.size(); c1++){
		if(u1[p1]<u2[p2]) v[c1]=u1[p1++];
		else v[c1]=u2[p2++];
	}
}

int main(){
	std::vector<int> v;

	for(int c1=0; c1<10; c1++){
		v.push_back(rand()%100);

		cout<<v[c1]<<" ";
	}

	cout<<endl;

	mergeSort(v);

	for(int c1=0; c1<10; c1++) cout<<v[c1]<<" ";

	getchar();
	getchar();

	return 0;
}