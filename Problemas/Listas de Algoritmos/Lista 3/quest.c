#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

typedef struct{
	char *name;
	char *val;
}ATTR;

struct NODE{
	char *val;
	int adressDoc;
	struct NODE *right;
	struct NODE *left;
}NODE;

typedef struct{
	ATTR ID;

	ATTR *unics;
	int qtdUnics;

	ATTR *index;
	int qtdIndex;

	ATTR *nSpecial;
	int qtdNSpecial;

	int excluido;
}DOC;

typedef struct{
	struct NODE *root;
	char *attr;
}TREE;

int getNum();
void getAttrs(int);
void createTree(char *);
void insert();
void createDoc();
void createId(char *, char *);
void createUnic(char *, char *);
void createIndex(char *, char *);
void createNSpecial(char *, char *);
int searchTree(char *);
struct NODE *bstInsert(struct NODE *, char *, char *);
void selecionar();
void searchNSpecial(char *, int *, int *, char *);
void bstSearch(struct NODE *, char *, int *, int *, char *);
void deletar();
struct NODE *bstDelete(struct NODE *, char *, char, int);
struct NODE *bstDeleteMin(struct NODE *, char *, int *);

TREE *trees;
DOC *docs;
int qtdTrees=0, numDoc=0;

int main(){
	int N=getNum();

	getAttrs(N);

	char comand[MAX];
	while(scanf(" %s", comand)!=EOF){
		switch(comand[0]){
			case 'I':
				insert();
			break;
			case 'S':
				selecionar();
			break;
			case 'D':
				deletar();
			break;
		}
	}

	return 0;
}

int getNum(){
	int num;
	scanf("%d", &num);

	return num;
}

void getAttrs(int N){
	int c1;
	for(c1=0; c1<N; c1++){
		char attr[MAX];
		scanf(" %s", attr);

		if(attr[0]=='*' || attr[0]=='!' || attr[0]=='?') createTree(attr);
	}
}

void createTree(char attr[MAX]){
	if(qtdTrees==0) trees=(TREE *)malloc(sizeof(TREE));
	else trees=(TREE *)realloc(trees, (qtdTrees+1)*sizeof(TREE));

	trees[qtdTrees].root=NULL;

	trees[qtdTrees].attr=(char *)malloc((strlen(attr)+1)*sizeof(char));
	strcpy(trees[qtdTrees].attr, attr);

	qtdTrees++;
}

void insert(){
	createDoc();

	int N=getNum();

	int c1;
	for(c1=0; c1<N; c1++){
		char attr[MAX], val[MAX];
		scanf(" %s %s", attr, val);

		if(attr[0]=='*' || attr[0]=='!' || attr[0]=='?'){
			int adrees=searchTree(attr);

			if(adrees!=-1) trees[adrees].root=bstInsert(trees[adrees].root, val, attr);
		}

		switch(attr[0]){
			case '*':
				createId(attr, val);
			break;
			case '!':
				createUnic(attr, val);
			break;
			case '?':
				createIndex(attr, val);
			break;
			default:
				createNSpecial(attr, val);
			break;
		}
	}

	numDoc++;
}

void createDoc(){
	if(numDoc==0) docs=(DOC *)malloc(sizeof(DOC));
	else docs=(DOC *)realloc(docs, (numDoc+1)*sizeof(DOC));

	docs[numDoc].qtdUnics=0;
	docs[numDoc].qtdIndex=0;
	docs[numDoc].qtdNSpecial=0;

	docs[numDoc].excluido=0;
}

void createId(char attr[MAX], char val[MAX]){
	docs[numDoc].ID.name=(char *)malloc((strlen(attr)+1)*sizeof(char));
	strcpy(docs[numDoc].ID.name, attr);

	docs[numDoc].ID.val=(char *)malloc((strlen(val)+1)*sizeof(char));
	strcpy(docs[numDoc].ID.val, val);
}	

void createUnic(char attr[MAX], char val[MAX]){
	if(docs[numDoc].qtdUnics==0) docs[numDoc].unics=(ATTR *)malloc(sizeof(ATTR));
	else docs[numDoc].unics=(ATTR *)realloc(docs[numDoc].unics, (docs[numDoc].qtdUnics+1)*sizeof(ATTR));

	docs[numDoc].unics[docs[numDoc].qtdUnics].name=(char *)malloc((strlen(attr)+1)*sizeof(char));
	strcpy(docs[numDoc].unics[docs[numDoc].qtdUnics].name, attr);

	docs[numDoc].unics[docs[numDoc].qtdUnics].val=(char *)malloc((strlen(val)+1)*sizeof(char));
	strcpy(docs[numDoc].unics[docs[numDoc].qtdUnics].val, val);

	docs[numDoc].qtdUnics++;
}

void createIndex(char attr[MAX], char val[MAX]){
	if(docs[numDoc].qtdIndex==0) docs[numDoc].index=(ATTR *)malloc(sizeof(ATTR));
	else docs[numDoc].index=(ATTR *)realloc(docs[numDoc].index, (docs[numDoc].qtdIndex+1)*sizeof(ATTR));

	docs[numDoc].index[docs[numDoc].qtdIndex].name=(char *)malloc((strlen(attr)+1)*sizeof(char));
	strcpy(docs[numDoc].index[docs[numDoc].qtdIndex].name, attr);

	docs[numDoc].index[docs[numDoc].qtdIndex].val=(char *)malloc((strlen(val)+1)*sizeof(char));
	strcpy(docs[numDoc].index[docs[numDoc].qtdIndex].val, val);

	docs[numDoc].qtdIndex++;
}

void createNSpecial(char attr[MAX], char val[MAX]){
	if(docs[numDoc].qtdNSpecial==0) docs[numDoc].nSpecial=(ATTR *)malloc(sizeof(ATTR));
	else docs[numDoc].nSpecial=(ATTR *)realloc(docs[numDoc].nSpecial, (docs[numDoc].qtdNSpecial+1)*sizeof(ATTR));

	docs[numDoc].nSpecial[docs[numDoc].qtdNSpecial].name=(char *)malloc((strlen(attr)+1)*sizeof(char));
	strcpy(docs[numDoc].nSpecial[docs[numDoc].qtdNSpecial].name, attr);

	docs[numDoc].nSpecial[docs[numDoc].qtdNSpecial].val=(char *)malloc((strlen(val)+1)*sizeof(char));
	strcpy(docs[numDoc].nSpecial[docs[numDoc].qtdNSpecial].val, val);

	docs[numDoc].qtdNSpecial++;
}

int searchTree(char attr[MAX]){
	int c1;
	for(c1=0; c1<qtdTrees; c1++){
		if(strcmp(attr, trees[c1].attr)==0) return c1;
	}

	return -1;
}

struct NODE *bstInsert(struct NODE *root, char val[MAX], char attr[MAX]){
	if(root==NULL){
		struct NODE *N;
		N=(struct NODE *)malloc(sizeof(NODE));

		N->val=(char *)malloc((strlen(val)+1)*sizeof(char));
		strcpy(N->val, val);

		N->adressDoc=numDoc;

		N->right=NULL;
		N->left=NULL;

		return N;
	}
	else if(strcmp(val, root->val)<0){
		root->left=bstInsert(root->left, val, attr);

		return root;
	}
	else{
		root->right=bstInsert(root->right, val, attr);

		return root;
	}
}

void selecionar(){
	int N=getNum();

	char **attr;
	attr=(char **)malloc(N*sizeof(char *));

	int c1;
	for(c1=0; c1<N; c1++){
		attr[c1]=(char *)malloc(MAX*sizeof(char));
		scanf(" %s", attr[c1]);
	}

	char where[10];
	scanf(" %s", where);

	char findAttr[MAX], val[MAX];
	scanf(" %s %s", findAttr, val);

	int findDocs[MAX], qtdFindDocs=0;

	if(findAttr[0]=='*' || findAttr[0]=='!' || findAttr[0]=='?'){
		int treeAdrees=searchTree(findAttr);

		bstSearch(trees[treeAdrees].root, val, findDocs, &qtdFindDocs, findAttr);
	}
	else searchNSpecial(val, findDocs, &qtdFindDocs, findAttr);

	for(c1=0; c1<qtdFindDocs; c1++){
		int c2;
		for(c2=0; c2<N; c2++){
			int c3, achei;

			switch(attr[c2][0]){
				case '*':
					if(strcmp(docs[findDocs[c1]].ID.name, attr[c2])==0) printf("%s", docs[findDocs[c1]].ID.val);
					else printf("?");
				break;
				case '!':
					achei=0;

					for(c3=0; c3<docs[findDocs[c1]].qtdUnics; c3++){
						if(strcmp(docs[findDocs[c1]].unics[c3].name, attr[c2])==0){
							printf("%s", docs[findDocs[c1]].unics[c3].val);

							achei=1;
						}
					}

					if(achei==0) printf("?");
				break;
				case '?':
					achei=0;

					for(c3=0; c3<docs[findDocs[c1]].qtdIndex; c3++){
						if(strcmp(docs[findDocs[c1]].index[c3].name, attr[c2])==0){
							printf("%s", docs[findDocs[c1]].index[c3].val);
							achei=1;
						}
					}

					if(achei==0) printf("?");
				break;
				default:
					achei=0;

					for(c3=0; c3<docs[findDocs[c1]].qtdNSpecial; c3++){
						if(strcmp(docs[findDocs[c1]].nSpecial[c3].name, attr[c2])==0){
							printf("%s", docs[findDocs[c1]].nSpecial[c3].val);
							achei=1;
						}
					}

					if(achei==0) printf("?");
				break;
			}

			if(c2<N-1) printf(" ");
		}

		printf("\n");
	}

	printf("\n");
}

void searchNSpecial(char val[MAX], int findDocs[MAX], int *qtdFindDocs, char attr[MAX]){
	int c1;
	for(c1=0; c1<numDoc; c1++){
		if(docs[numDoc].excluido==0){
			int c2, sair=0;
			for(c2=0; c2<docs[c1].qtdNSpecial && sair==0; c2++){
				if(strcmp(attr, docs[c1].nSpecial[c2].name)==0){
					if(strcmp(val, docs[c1].nSpecial[c2].val)==0){
						findDocs[*qtdFindDocs]=c1;
						(*qtdFindDocs)++;
						sair=1;
					}
				}
			}
		}
	}
}

void bstSearch(struct NODE *root, char val[MAX], int findDocs[MAX], int *qtdFindDocs, char attr[MAX]){
	if(root!=NULL){
		if(strcmp(val, root->val)==0){
			findDocs[*qtdFindDocs]=root->adressDoc;

			(*qtdFindDocs)++;

			if(attr[0]!='!') bstSearch(root->right, val, findDocs, qtdFindDocs, attr);
		}
		else if(strcmp(val, root->val)<0) bstSearch(root->left, val, findDocs, qtdFindDocs, attr);
		else bstSearch(root->right, val, findDocs, qtdFindDocs, attr);	
	}	
}

void deletar(){
	char attr[MAX], val[MAX];
	scanf(" %s %s", attr, val);

	int findDocs[MAX], qtdFindDocs=0;

	if(attr[0]=='*' || attr[0]=='!' || attr[0]=='?'){
		int treeAdrees=searchTree(attr);

		bstSearch(trees[treeAdrees].root, val, findDocs, &qtdFindDocs, attr);
	}
	else searchNSpecial(val, findDocs, &qtdFindDocs, attr);

	int c1;
	for(c1=0; c1<qtdFindDocs; c1++){
		int c2;
		for(c2=0; c2<qtdTrees; c2++){
			int c3;

			switch(trees[c2].attr[0]){
				case '*':
					trees[c2].root=bstDelete(trees[c2].root, docs[findDocs[c1]].ID.val, '*', findDocs[c1]);
				break;
				case '!':
					for(c3=0; c3<docs[findDocs[c1]].qtdUnics; c3++){
						trees[c2].root=bstDelete(trees[c2].root, docs[findDocs[c1]].unics[c3].val, '!', findDocs[c1]);
					}
				break;
				case '?':
					for(c3=0; c3<docs[findDocs[c1]].qtdIndex; c3++){
						trees[c2].root=bstDelete(trees[c2].root, docs[findDocs[c1]].index[c3].val, '?', findDocs[c1]);
					}
				break;
			}
		}

		docs[c1].excluido=1;
	}
}

struct NODE *bstDelete(struct NODE *root, char val[MAX], char attr, int doc){
	if(root==NULL){
		return NULL;
	}
	else if(strcmp(val, root->val)<0){
		root->left=bstDelete(root->left, val, attr, doc);

		return root;
	}
	else if(strcmp(val, root->val)>0){
		root->right=bstDelete(root->right, val, attr, doc);

		return root;
	}
	else{
		if(root->left==NULL){
			struct NODE *r;
			r=(struct NODE *)malloc(sizeof(NODE));

			if(root->adressDoc!=doc){
				root->right=bstDelete(root->right, val, attr, doc);

				r=root;
			}
			else{
				if(attr!='!') root->right=bstDelete(root->right, val, attr, doc);

				r=root->right;
			}

			return r;
		}
		else if(root->right==NULL){
			struct NODE *l;
			l=(struct NODE *)malloc(sizeof(NODE));

			if(root->adressDoc!=doc){
				root->left=bstDelete(root->left, val, attr, doc);

				l=root;
			}
			else{
				if(attr!='!') root->left=bstDelete(root->left, val, attr, doc);

				l=root->left;
			}

			return l;
		}
		else{
			if(root->adressDoc!=doc){
				root->right=bstDelete(root->right, val, attr, doc);

				return root;
			}
			else{
				if(attr!='!') root->right=bstDelete(root->right, val, attr, doc);

				char curVal[MAX];
				int curDoc;

				strcpy(curVal, val);
				curDoc=doc;
				
				root->right=bstDeleteMin(root->right, val, &doc);
				strcpy(root->val, val);
				root->adressDoc=doc;

				strcpy(val, curVal);
				doc=curDoc;

				return root;
			}
		}
	}
}

struct NODE *bstDeleteMin(struct NODE *root, char val[MAX], int *doc){
	if(root->left==NULL){
		struct NODE *r;
		r=(struct NODE *)malloc(sizeof(NODE));

		strcpy(val, root->val);
		*doc=root->adressDoc;

		r=root->right;

		return r;
	}
	else{
		root->left=bstDeleteMin(root->left, val, doc);

		return root;
	}
}