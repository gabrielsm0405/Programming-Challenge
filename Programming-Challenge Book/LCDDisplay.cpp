#include <bits/stdc++.h>

using namespace std;

int main(){
	int s; 
	char n[9];

	while(cin>>s>>n){
		char codDisp[strlen(n)][7];

		for(int c1=0; c1<strlen(n); c1++){
			switch(n[c1]){
				case '1':
					codDisp[c1][0]='0';
					codDisp[c1][1]='1';
					codDisp[c1][2]='1';
					codDisp[c1][3]='0';
					codDisp[c1][4]='0';
					codDisp[c1][5]='0';
					codDisp[c1][6]='0';
				break;
				case '2':
					codDisp[c1][0]='1';
					codDisp[c1][1]='1';
					codDisp[c1][2]='0';
					codDisp[c1][3]='1';
					codDisp[c1][4]='1';
					codDisp[c1][5]='0';
					codDisp[c1][6]='1';
				break;
				case '3':
					codDisp[c1][0]='1';
					codDisp[c1][1]='1';
					codDisp[c1][2]='1';
					codDisp[c1][3]='1';
					codDisp[c1][4]='0';
					codDisp[c1][5]='0';
					codDisp[c1][6]='1';
				break;
				case '4':
					codDisp[c1][0]='0';
					codDisp[c1][1]='1';
					codDisp[c1][2]='1';
					codDisp[c1][3]='0';
					codDisp[c1][4]='0';
					codDisp[c1][5]='1';
					codDisp[c1][6]='1';
				break;
				case '5':
					codDisp[c1][0]='1';
					codDisp[c1][1]='0';
					codDisp[c1][2]='1';
					codDisp[c1][3]='1';
					codDisp[c1][4]='0';
					codDisp[c1][5]='1';
					codDisp[c1][6]='1';
				break;
				case '6':
					codDisp[c1][0]='1';
					codDisp[c1][1]='0';
					codDisp[c1][2]='1';
					codDisp[c1][3]='1';
					codDisp[c1][4]='1';
					codDisp[c1][5]='1';
					codDisp[c1][6]='1';
				break;
				case '7':
					codDisp[c1][0]='1';
					codDisp[c1][1]='1';
					codDisp[c1][2]='1';
					codDisp[c1][3]='0';
					codDisp[c1][4]='0';
					codDisp[c1][5]='0';
					codDisp[c1][6]='0';
				break;
				case '8':
					codDisp[c1][0]='1';
					codDisp[c1][1]='1';
					codDisp[c1][2]='1';
					codDisp[c1][3]='1';
					codDisp[c1][4]='1';
					codDisp[c1][5]='1';
					codDisp[c1][6]='1';
				break;
				case '9':
					codDisp[c1][0]='1';
					codDisp[c1][1]='1';
					codDisp[c1][2]='1';
					codDisp[c1][3]='1';
					codDisp[c1][4]='0';
					codDisp[c1][5]='1';
					codDisp[c1][6]='1';
				break;
			}
		}

		for(int c1=0; c1<3+2*s; c1++){
			for(int c2=0; c2<strlen(n); c2++){
				if(c1==0){
					printf("  ");
					if(codDisp[c2][0]=='1'){
						for(int c3=1; c3<=s; c3++) printf("-");
					}
					else{
						for(int c3=1; c3<=s; c3++) printf(" ");	
					}
				}
				else if(c1==s+1){
					printf("  ");

					if(codDisp[c2][6]=='1'){
						for(int c3=1; c3<=s; c3++) printf("-");
					}
					else{
						for(int c3=1; c3<=s; c3++) printf(" ");	
					}	
				}
				else if(c1==2*s+2){
					printf("  ");

					if(codDisp[c2][3]=='1'){
						for(int c3=1; c3<=s; c3++) printf("-");
					}
					else{
						for(int c3=1; c3<=s; c3++) printf(" ");	
					}
				}
				else{
					if(c1>0 && c1<s+1){
						if(codDisp[c2][5]=='1'){
							printf("|");
							for(int c3=1; c3<=s; c3++) printf(" ");
						}
						else{
							printf(" ");
							for(int c3=1; c3<=s; c3++) printf(" ");
						}

						if(codDisp[c2][1]=='1') printf("|");
						else printf(" ");
					}
					else if(c1>s+1 && c1<2*s+2){
						if(codDisp[c2][4]=='1'){
							printf("|");
							for(int c3=1; c3<=s; c3++) printf(" ");
						}
						else{
							printf(" ");
							for(int c3=1; c3<=s; c3++) printf(" ");
						}

						if(codDisp[c2][2]=='1') printf("|");
						else printf(" ");	
					}
				}

				printf(" ");
			}

			printf("\n");
		}
	}

	return 0;
}