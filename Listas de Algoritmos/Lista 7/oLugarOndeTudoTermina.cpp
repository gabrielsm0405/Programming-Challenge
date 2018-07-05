#include <bits/stdc++.h>

using namespace std;

#define INF 1000000;

struct Celula{
    int pont;
    bool calculado;
    int resp;
};

Celula cubo[101][101][101];
int M, N, S;
int Fi, Fj, Fk;

int backtracking(int I, int J, int K){
	if(cubo[I][J][K].calculado) return cubo[I][J][K].resp;

    if(I==Fi && J==Fj && K==Fk){
        return cubo[Fi][Fj][Fk].pont;
    }

    int pont1=-INF;
    int pont2=-INF;
    int pont3=-INF;

    if(I-1>=0){
        pont1=backtracking(I-1, J, K);
    }
    if(J+1<N){
        pont2=backtracking(I, J+1, K);
    }
    if(K+1<S){
        pont3=backtracking(I, J, K+1);
    }

    cubo[I][J][K].calculado=true;

    return cubo[I][J][K].resp=max(pont1, max(pont2, pont3))+cubo[I][J][K].pont;
}

int main(){ 
    cin>>M>>N>>S;

    cin>>Fi>>Fj>>Fk;

    for(int c1=0; c1<M; c1++){
        for(int c2=0; c2<N; c2++){
            for(int c3=0; c3<S; c3++){
                cin>>cubo[c1][c2][c3].pont;
                cubo[c1][c2][c3].calculado=false;
            }
        }
    }

    int P;
    cin>>P;

    for(int c1=0; c1<P; c1++){
        int I, J, K;
        cin>>I>>J>>K;

        cout<<backtracking(I, J, K)<<endl;
    }

    return 0;
}