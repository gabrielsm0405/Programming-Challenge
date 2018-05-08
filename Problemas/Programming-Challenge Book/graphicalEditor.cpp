#include <bits/stdc++.h>

#define MAX 100

using namespace std;

void backtrack(int X, int Y, int C, char **image, int M, int N){
	if(X<M){
		if(image[X][Y-1]==image[X-1][Y-1]) backtrack(X+1, Y, C, image, M, N);
	}

	if(X-2>=0){
	 	if(image[X-2][Y-1]==image[X-1][Y-1]) backtrack(X-1, Y, C, image, M, N);
	}

	if(Y<N){
		if(image[X-1][Y]==image[X-1][Y-1]) backtrack(X, Y+1, C, image, M, N);
	}

	if(Y-2>=0){
		if(image[X-1][Y-2]==image[X-1][Y-1]) backtrack(X, Y-1, C, image, M, N);
	}

	image[X-1][Y-1]=C;
}

int main(){
	char operador, **image=NULL, name[MAX], C;
	int M, N, X, Y, Y1, Y2, X1, X2;

	do{
		cin>>operador;

		switch(operador){
			case 'I':
				cin>>M>>N;

				image=(char **)malloc(M*sizeof(char *));

				for(int c1=0; c1<M; c1++){
					image[c1]=(char *)malloc(N*sizeof(char));
				}
			break;
			case 'C':
				for(int c1=0; c1<M; c1++){
					for(int c2=0; c2<N; c2++) image[c1][c2]='0';
				}
			break;
			case 'L':
				cin>>X>>Y;

				cin>>C;

				image[X-1][Y-1]=C;
			break;
			case 'V':
				cin>>X;

				cin>>Y1>>Y2;

				cin>>C;

				for(int c1=Y1; c1<=Y2; c1++) image[c1-1][X-1]=C;
			break;
			case 'H':
				cin>>X1>>X2;

				cin>>Y;

				cin>>C;

				for(int c1=X1; c1<=X2; c1++) image[Y-1][c1-1]=C;
			break;
			case 'K':
				cin>>X1>>Y1;

				cin>>X2>>Y2;

				cin>>C;

				for(int c1=Y1; c1<=Y2; c1++){
					for(int c2=X1; c2<=X2; c2++) image[c1-1][c2-1]=C;
				}
			break;
			case 'F':
				cin>>X>>Y;

				cin>>C;

				backtrack(X, Y, C, image, M, N);
			break;
			case 'S':
				cin>>name;

				cout<<name<<"\n";

				for(int c1=0; c1<M; c1++){
					for(int c2=0; c2<N; c2++) cout<<image[c1][c2];

					cout<<"\n";
				}
			break;
		}
	}while(operador!='X');

	return 0;
}