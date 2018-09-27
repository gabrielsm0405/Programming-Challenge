#include <bits/stdc++.h>

using namespace std;

int queen[9], x, y, cont;

bool coloca(int n, int linha){
	bool coloca = true;

	for(int c1=1; c1<=8; c1++){
		if(queen[c1] == linha){
			coloca = false;
			break;
		}
	}

	if(coloca){
		for(int c1=n, c2=linha; c1<=8 && c2<=8; c1++, c2++){
			if(queen[c1] == c2){
				coloca = false;
				break;
			}
		}
	}

	if(coloca){
		for(int c1=n, c2=linha; c1>=1 && c2>=1; c1--, c2--){
			if(queen[c1] == c2){
				coloca = false;
				break;
			}
		}
	}

	if(coloca){
		for(int c1=n, c2=linha; c1<=8 && c2>=1; c1++, c2--){
			if(queen[c1] == c2){
				coloca = false;
				break;
			}
		}
	}
	
	if(coloca){
		for(int c1=n, c2=linha; c1>=1 && c2<=8; c1--, c2++){
			if(queen[c1] == c2){
				coloca = false;
				break;
			}
		}
	}

	return coloca;
}

bool backtracking(int n){
	if(n==9){
		printf("%2d      ", ++cont);
		for(int c1=1; c1<=8; c1++){
			cout<<queen[c1];

			if(c1<8) cout<<" ";
		}
		cout<<endl;		

		return false;
	}
	
	if(n == y) return backtracking(n+1);

	bool solution = false;

	for(int c1=1; c1<=8; c1++){
		if(coloca(n, c1)){
			queen[n] = c1;

			if(backtracking(n+1)) solution = true;

			if(!solution) queen[n] = 0;
		}
	}

	return solution;
}

int main(){
	int n;
	cin>>n;
	
	bool ini = true;	

	while(n>0){
		cin>>x>>y;
		
		memset(queen, 0, sizeof(queen));		

		queen[y] = x;
		
		if(!ini) cout<<endl;
		ini = false;		

		cout<<"SOLN       COLUMN"<<endl;
		cout<<" #      1 2 3 4 5 6 7 8"<<endl<<endl;
		
		cont = 0;		

		backtracking(1);

		n--;
	}	

	return 0;
}
