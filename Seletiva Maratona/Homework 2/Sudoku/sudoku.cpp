#include <bits/stdc++.h>

using namespace std;

int n, matrix[10][10];

bool coloco(int a, int x, int y){
	bool coloco = true;

	for(int c1=0; c1<n; c1++){
		if(c1!=y){
			if(matrix[x][c1] == a){
				coloco = false;
				break;
			}
		}
	}

	if(coloco){		
		for(int c1=0; c1<n; c1++){
			if(c1!=x){
				if(matrix[c1][y] == a){
					coloco = false;
					break;
				}
			}	
		}
	}

	if(coloco){
		int limx0, limx1, limy0, limy1;
		switch(n){
			case 1:
				limx0=0;
				limx1=0;
				limy0=0;
				limy1=0;
			break;
			case 4:
				if(x<=1){
					limx0 = 0;
					limx1 = 1;
				}
				else{	
					limx0 = 2;
					limx1 = 3;
				}

				if(y<=1){
					limy0 = 0;
					limy1 = 1;
				}
				else{	
					limy0 = 2;
					limy1 = 3;
				}
			break;
			case 9:
				if(x<=2){
					limx0 = 0;
					limx1 = 2;
				}
				else if(x<=5){
					limx0 = 3;
					limx1 = 5;
				}
				else{
					limx0 = 6;
					limx1 = 8;
				}

				if(y<=2){
					limy0 = 0;
					limy1 = 2;
				}
				else if(y<=5){
					limy0 = 3;
					limy1 = 5;
				}
				else{
					limy0 = 6;
					limy1 = 8;
				}
			break;
		}

		for(int c1=limx0; c1<=limx1; c1++){
			for(int c2=limy0; c2<=limy1; c2++){
				if(c1!=x || c2!=y){
					if(matrix[c1][c2] == a){
						coloco = false;
						break;
					}
				}
			}
		}
		
	}

	return coloco;
}

bool backtracking(int x, int y){	
	if(x==n) return true;

	if(matrix[x][y] != 0){
		if(y==n-1) return backtracking(x+1, 0);
		else return backtracking(x, y+1);
	}
	else{
		bool solution = false;		

		for(int c1=1; c1<=n; c1++){
			if(coloco(c1, x, y)){
				matrix[x][y] = c1;

				if(y==n-1){
					if(backtracking(x+1, 0)) solution = true;
				}
				else if(backtracking(x, y+1)) solution = true;

				if(!solution) matrix[x][y] = 0;
			}
		}
		
		return solution;
	}
}

int main(){
	bool ini=true;	

	while(cin>>n){
		if(!ini) cout<<endl;
		
		ini=false;		

		n*=n;
		for(int c1=0; c1<n; c1++){
			for(int c2=0; c2<n; c2++) cin>>matrix[c1][c2];
		}

		if(!backtracking(0, 0)){
			cout<<"NO SOLUTION"<<endl;
		}
		else{
			for(int c1=0; c1<n; c1++){
				for(int c2=0; c2<n; c2++){
					cout<<matrix[c1][c2];
					
					if(c2<n-1) cout<<" ";
				}
				cout<<endl;
			}
		}
	}

	return 0;
}
