//
// Created by Gabriel Marques on 03/05/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct HEAP{
    int *vetor;

    int qtdElt;
};

void add();
void initHeaps();
void heap_insert(int, int);
void bubble_up(int);
int heap_extract(int);
void heapify(int, int);
void res();
int teto(double);

struct HEAP min_heap, max_heap;
int minEle=-1, maxEle=-1;

int main(){
    initHeaps();
    char comand[4];

    while(scanf("%s", comand)!=EOF){
        if(strcmp(comand, "ADD")==0) add();
        if(strcmp(comand, "MIN")==0) printf("%d\n", minEle);
        if(strcmp(comand, "MAX")==0) printf("%d\n", maxEle);
        if(strcmp(comand, "MED")==0){
            if(min_heap.qtdElt>0) printf("%d\n", min_heap.vetor[0]);
            else printf("-1\n");
        }
        if(strcmp(comand, "RES")==0) res();
    }

    return 0;
}

void initHeaps(){
    min_heap.vetor=NULL;
    min_heap.qtdElt=0;

    max_heap.vetor=NULL;
    max_heap.qtdElt=0;
}

void add(){
    int v;

    scanf(" %d", &v);

    if(min_heap.qtdElt==0) heap_insert(0, v);
    else if(v<min_heap.vetor[0]) heap_insert(1, v);
    else heap_insert(0, v);

    if(max_heap.qtdElt>min_heap.qtdElt) heap_insert(0, heap_extract(1));

    if(max_heap.qtdElt+1<min_heap.qtdElt) heap_insert(1, heap_extract(0));

    if(minEle==-1 || v<minEle) minEle=v;
    if(maxEle==-1 || v>maxEle) maxEle=v;

    printf("%d %d %d\n", minEle, min_heap.vetor[0], maxEle);
}

void heap_insert(int opt, int v){
    if(opt==0){
        min_heap.vetor=(int *)realloc(min_heap.vetor, (min_heap.qtdElt+1)*sizeof(int));

        min_heap.vetor[min_heap.qtdElt]=v;

        min_heap.qtdElt++;

        bubble_up(opt);
    }
    else{
        max_heap.vetor=(int *)realloc(max_heap.vetor, (max_heap.qtdElt+1)*sizeof(int));

        max_heap.vetor[max_heap.qtdElt]=v;

        max_heap.qtdElt++;

        bubble_up(opt);
    }
}

void bubble_up(int opt){
    int i;

    if(opt==0){
        i=min_heap.qtdElt-1;

        while(i>0 && min_heap.vetor[i]<min_heap.vetor[teto((double)i/2)-1]){
            int aux=min_heap.vetor[i];
            min_heap.vetor[i]=min_heap.vetor[teto((double)i/2)-1];
            min_heap.vetor[teto((double)i/2)-1]=aux;

            i=teto((double)i/2)-1;
        }
    }
    else{
        i=max_heap.qtdElt-1;

        while(i>0 && max_heap.vetor[i]>max_heap.vetor[teto((double)i/2)-1]){
            int aux=max_heap.vetor[i];
            max_heap.vetor[i]=max_heap.vetor[teto((double)i/2)-1];
            max_heap.vetor[teto((double)i/2)-1]=aux;

            i=teto((double)i/2)-1;
        }
    }
}

int teto(double num){
    int aux=(int)num;

    if(num==aux) return aux;
    else return  aux+1;
}

int heap_extract(int opt){
    int r;

    if(opt==0) {
        r=min_heap.vetor[0];

        min_heap.vetor[0]=min_heap.vetor[min_heap.qtdElt-1];

        min_heap.vetor[min_heap.qtdElt-1]=r;

        min_heap.qtdElt--;
    }
    else{
        r=max_heap.vetor[0];

        max_heap.vetor[0]=max_heap.vetor[max_heap.qtdElt-1];

        max_heap.vetor[max_heap.qtdElt-1]=r;

        max_heap.qtdElt--;
    }

    heapify(opt, 0);

    return r;
}

void heapify(int opt, int i){
    int m=i, l=2*i+1, r=2*i+2;

    if(opt==0){
        if(l<min_heap.qtdElt && min_heap.vetor[l]<min_heap.vetor[m]) m=l;
        if(r<min_heap.qtdElt && min_heap.vetor[r]<min_heap.vetor[m]) m=r;

        if(m!=i){
            int aux=min_heap.vetor[i];
            min_heap.vetor[i]=min_heap.vetor[m];
            min_heap.vetor[m]=aux;

            heapify(opt, m);
        }
    }
    else{
        if(l<max_heap.qtdElt && max_heap.vetor[l]>max_heap.vetor[m]) m=l;
        if(r<max_heap.qtdElt && max_heap.vetor[r]>max_heap.vetor[m]) m=r;

        if(m!=i){
            int aux=max_heap.vetor[i];
            max_heap.vetor[i]=max_heap.vetor[m];
            max_heap.vetor[m]=aux;

            heapify(opt, m);
        }
    }
}

void res(){
    printf("%d\n", min_heap.qtdElt+max_heap.qtdElt);

    free(min_heap.vetor);
    min_heap.vetor=NULL;
    min_heap.qtdElt=0;

    free(max_heap.vetor);
    max_heap.vetor=NULL;
    max_heap.qtdElt=0;

    minEle=-1;
    maxEle=-1;
}