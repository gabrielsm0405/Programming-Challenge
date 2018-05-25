#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, cont=1;

	do{
		cin>>n>>m;

		if(n!=0 && m!=0){
			char mapIn[n][m];
			int **coordMines=NULL, qtdMines=0;

			for(int c1=0; c1<n; c1++){
				for(int c2=0; c2<m; c2++){
					cin>>mapIn[c1][c2];

					if(mapIn[c1][c2]=='*'){
						coordMines=(int **)realloc(coordMines, (qtdMines+1)*sizeof(int *));

						coordMines[qtdMines]=(int *)malloc(2*sizeof(int));

						coordMines[qtdMines][0]=c1;
						coordMines[qtdMines][1]=c2;

						qtdMines++;
					}
				}
			}

            char mapOut[n][m];

            memset(mapOut, '0', sizeof(mapOut));

            for(int c3=0; c3<qtdMines; c3++){
                mapOut[coordMines[c3][0]][coordMines[c3][1]]='*';

                for(int c1=0; c1<n; c1++){
                    for(int c2=0; c2<m; c2++){
                        if(sqrt(pow(coordMines[c3][0]-c1, 2)+pow(coordMines[c3][1]-c2, 2))<2 && mapOut[c1][c2]!='*') mapOut[c1][c2]++;
                    }
                }
            }

			cout<<"Field #"<<cont<<"\n";

            for(int c1=0; c1<n; c1++){
                for(int c2=0; c2<m; c2++) cout<<mapOut[c1][c2];

                cout<<"\n";
            }

            cout<<"\n";
		}
	}while(n!=0 || m!=0);

	return 0;
}