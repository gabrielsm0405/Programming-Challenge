#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;

	while(cin>>n){
		queue<int> q;
		stack<int> s;
		priority_queue<int> m;

		bool isq=true, iss=true, ism=true;

		for(int c1=0; c1<n; c1++){
			int num1, num2;
			cin>>num1>>num2;

			if(num1==1){
				q.push(num2);
				s.push(num2);
				m.push(num2);
			}
			else{
				if(!q.empty()){
					if(q.front()!=num2) isq=false;
					q.pop();
				}
				else isq=false;

				if(!s.empty()){
					if(s.top()!=num2) iss=false;
					s.pop();
				}
				else iss=false;

				if(!m.empty()){
					if(m.top()!=num2) ism=false;
					m.pop();
				}
				else ism=false;
			}
		}

		int resp=100*isq+10*iss+ism;

		switch(resp){
			case 100:
				cout<<"queue"<<endl;
			break;
			case 10:
				cout<<"stack"<<endl;
			break;
			case 1:
				cout<<"priority queue"<<endl;
			break;
			case 0:
				cout<<"impossible"<<endl; 	
			break;
			default:
				cout<<"not sure"<<endl;
			break;
		}
	}

	return 0;
}