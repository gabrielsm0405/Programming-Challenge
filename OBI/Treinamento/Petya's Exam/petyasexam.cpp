#include <bits/stdc++.h>

using namespace std;

struct Exam{
	int s, d, c;
	int id;
};

bool compare(Exam a, Exam b){
	return a.d<b.d;
}

int main(){
	int n, m;
	cin>>n>>m;

	Exam exams[110];

	int days[110];
	memset(days, 0, sizeof(days));

	for(int c1=0; c1<m; c1++){
		cin>>exams[c1].s>>exams[c1].d>>exams[c1].c;

		days[exams[c1].d-1]=m+1;

		exams[c1].id=c1+1;
	}

	sort(exams, exams+m, compare);

	bool ndeu;

	for(int c1=0; c1<m; c1++){
		ndeu=true;

		for(int c2=exams[c1].s-1; c2<n; c2++){
			if(c2==exams[c1].d-1) break;

			if(days[c2]==0){
				days[c2]=exams[c1].id;

				exams[c1].c--;

				if(exams[c1].c==0){
					ndeu=false;

					break;
				}
			}
		}

		if(ndeu) break;
	}

	if(ndeu) cout<<"-1";
	else{
		for(int c1=0; c1<n; c1++){
			if(c1==n-1) cout<<days[c1];
			else cout<<days[c1]<<"-";
		}
	}

	getchar();
	getchar();

	return 0;
}