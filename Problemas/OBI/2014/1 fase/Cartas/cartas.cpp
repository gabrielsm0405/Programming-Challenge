#include <bits/stdc++.h>

using namespace std;

int main(){
	int numAnt=-1, numAt, cres=-1, resp=0;

	while(cin>>numAt){
		if(numAnt!=-1){
			if(numAnt<numAt){
				if(cres==-1){
					cres=1;

					resp=1;
				}
				else if(cres!=1) resp=-1;
			}
			else if(numAnt>numAt){
				if(cres==-1){
					cres=0;

					resp=0;	
				}
				else if(cres!=0) resp=-1;
			}
		}

		numAnt=numAt;
	}

	if(resp==-1) cout<<"N";
	if(resp==1) cout<<"C";
	if(resp==0) cout<<"D";

	return 0;
}