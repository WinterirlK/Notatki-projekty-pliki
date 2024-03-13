#include <stdio.h>
#include <stdlib.h>

struct Stos{
  int liczba;
  struct Stos * Next;
};

struct Stos * push(struct Stos * Head, int l){
    struct Stos *p = (struct Stos *)malloc(sizeof(struct Stos));
    p->liczba = l;
    if(Head == NULL){
        p->Next = NULL;
        Head = p;
    }
    else{
        p->Next = Head;
        Head = p;
    }
    return Head;
}

struct Stos *pop(struct Stos * Head, int * n){
    *n = Head->liczba;
    struct Stos * tmp = Head->Next;
    free(Head);
    return tmp;
}


void pokaz(struct Stos * Head){
    while(Head!=NULL){
        printf("%i\n",Head->liczba);
        Head= Head->Next;
    }
}

int silnia(int n){
    int wynik = 1;
    struct Stos * S = NULL;
    S=push(S,n);
    int tmp;
    while(S!=NULL){
        S=pop(S,&tmp);
        if(tmp>1){
            wynik *= tmp;
            S=push(S,tmp-1);
        }
    }
    return wynik;
    
}

int Fib(int n){
    int wynik = 0;
    struct Stos * S = NULL;
    S=push(S,n);
    int tmp;
    while(S!=NULL){
        S=pop(S,&tmp);
        if(tmp>2){
            S=push(S,tmp-1);
            S=push(S,tmp-2);
        }
        else{
            wynik+=1;
        }
    }
    return wynik;
}

int Podzial(int *A, int p, int r){
    int pivot = A[r];
    int tmp;
    int i = (p - 1);
    for(int j = p; j<r;j++){
        if(A[j]<=pivot){
            tmp = A[++i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    tmp = A[++i];
    A[i] = A[r];
    A[r] = tmp;
    return (i);
}

void QuickSort(int *A, int p, int r){
    struct Stos * S = NULL;
    int q;
    S=push(S,p);
    S=push(S,r);
    while(S!=NULL){
        S=pop(S,&r);
        S=pop(S,&p);
        q = Podzial(A,p,r);
        if(q-1>p){
            S=push(S,p);
            S=push(S,q-1);
        }
        if(q+1<r){
            S=push(S,q+1);
            S=push(S,r);
        }
    }
}




struct Lista{
  int v;
  struct Lista * Next;
};

struct Lista * Append(struct Lista * Head, int liczba){
    struct Lista * p = (struct Lista *)malloc(sizeof(struct Lista));
    p->v=liczba;
    p->Next = NULL;
    if(Head == NULL){
        Head = p;
    }
    else{
        struct Lista * tmp = Head;
        while(tmp->Next!=NULL){
            tmp = tmp->Next;
        }
        tmp->Next = p;
    }
    return Head;
}

void Display(struct Lista * Head){
    while(Head!=NULL){
        printf("%d ",Head->v);
        Head=Head->Next;
    }
    putchar('\n');
}


//kolejność odwiedzania wierzchołków
int V[4] = {0,0,0,0};

int DFS(int i_A, struct Lista ** Graf) {
    int Nr=0; //licznik
    struct Stos * Top = NULL;
    struct Lista *tmp = Graf[i_A];
    V[i_A] = ++Nr;
    while(tmp!=NULL && tmp->v != -1){ //wrzucenie na stos po kolei wszystkich sąsiadów
        Top = push(Top, tmp->v);
        tmp=tmp->Next;
    while(Top!=NULL){
        Top = pop(Top,&i_A); //zczytywanie ze stosu | jeśli przeszła pętla while to wierzchołek sprawdzany będzie ostatnim zapisanym sąsiadem
        if(V[i_A]==0){
            V[i_A] = ++Nr;
            tmp = Graf[i_A];
            while(tmp!=NULL && tmp->v != -1){ //wrzucenie na stos po kolei wszystkich sąsiadów
                Top = push(Top, tmp->v);
                tmp=tmp->Next;
            }
        }
    }
    
    }
}


int main()
{
    //c różnica c++
    int size = 5;
    
    //   int A[size];
    //     A[0] = 5;
    //     A[1] = 7;
    //     A[2] = 1;
    //     A[3] = 9;
    //     A[4] = 0;
    
    // int A[size] = {5,7,1,9,0};
    
    int A[5] = {5,7,1,9,0};
    
    QuickSort(A,0,size-1);
    for(int i = 0;i<5;i++){
        printf("%d ",A[i]);
    }
    printf("\n%d\n",silnia(5));
    printf("%d\n",Fib(8));


    struct Lista ** Graf;
    int n = 4;
    Graf = (struct Lista **)calloc(n,sizeof(struct Lista*));
    //1 lista grafa
    Graf[0] = Append(Graf[0],1);
    Graf[0] = Append(Graf[0],-1);
    Graf[0] = Append(Graf[0],-1);
    Graf[0] = Append(Graf[0],-1);
    
    //2 lista grafa
    Graf[1] = Append(Graf[1],2);
    Graf[1] = Append(Graf[1],-1);
    Graf[1] = Append(Graf[1],-1);
    Graf[1] = Append(Graf[1],-1);
    
    //3 lista grafa
    Graf[2] = Append(Graf[2],3);
    Graf[2] = Append(Graf[2],-1);
    Graf[2] = Append(Graf[2],-1);
    Graf[2] = Append(Graf[2],-1);
    
    //4 lista grafa
    Graf[3] = Append(Graf[3],-1);
    Graf[3] = Append(Graf[3],-1);
    Graf[3] = Append(Graf[3],-1);
    Graf[3] = Append(Graf[3],-1);
    
    for(int i = 0;i<4;i++){
        Display(*(Graf+i));
    }
    DFS(0,Graf);
    for(int i = 0;i<4;i++){
        printf("V[%d] = %d\n",i,V[i]);
    }

  
    return 0;
}
