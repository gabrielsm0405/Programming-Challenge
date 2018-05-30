#include <bits/stdc++.h>

using namespace std;

typedef struct Node{
	long long a, maxX;

	Node *right, *left;
}Node;

Node *bst_insert(Node *root, long long a, long long x){
	if(root==NULL){
		Node *newNode;
		newNode=(Node *)malloc(sizeof(Node));

		newNode->a=a;
		newNode->maxX=x;

		newNode->right=NULL;
		newNode->left=NULL;

		return newNode;
	}
	else if(a<root->a){
		root->left=bst_insert(root->left, a, x);

		return root;
	}
	else if(a>root->a){
		root->right=bst_insert(root->right, a, x);

		return root;
	}
	else{
		if(x>root->maxX) root->maxX=x;

		return root;
	}
}

Node *bst=NULL;

long long soma=0;

void bst_visit(Node *root){
	if(root!=NULL){
		soma+=root->maxX;

		bst_visit(root->right);

		bst_visit(root->left);
	}
}

int main(){
	int n;
	cin>>n;

	for(int c1=0; c1<n; c1++){
		long long a, x;
		cin>>a>>x;

		bst=bst_insert(bst, a, x);
	}

	int m;
	cin>>m;

	for(int c1=0; c1<m; c1++){
		long long b, y;
		cin>>b>>y;

		bst=bst_insert(bst, b, y);
	}

	bst_visit(bst);

	cout<<soma;

	return 0;
}