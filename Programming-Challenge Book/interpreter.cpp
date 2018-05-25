#include <bits/stdc++.h>

#define MAX 1010

using namespace std;

int main(){
	int numberCases, c1;

	cin>>numberCases;

	int answers[numberCases];

	memset(answers, 0, sizeof(answers));

	c1=numberCases;

	while(c1>0){
		bool over=false;
		char instructions[MAX][4];
		int location=0;

		do{
			cin>>instructions[location];

			location++;
		}while(instructions[location-1][0]!='1');

		location=0;

		do{

		}while(1);

		c1--;
	}

	return 0;
}