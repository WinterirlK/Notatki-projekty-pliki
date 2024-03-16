#include <cstdio>
#include <cstdlib>

//kolejka FIFO-first IN firts OUT

struct FIFO{
    int number;
    struct FIFO * Next;
};

struct FIFO *EnQueue(struct FIFO * IN, int number){
    struct FIFO *tmp = (struct FIFO *)malloc(sizeof(struct FIFO));
    tmp->number=number;
    tmp->Next=NULL;
    if(IN==NULL){
        IN = tmp;
    }
    else{
        IN->Next = tmp;
        IN = tmp;
    }
    return IN;
}

struct FIFO * DeQueue(struct FIFO *OUT, int *n){
    *n = OUT->number;
    struct FIFO *tmp = OUT->Next;
    free(OUT);
    return tmp;
}

void ShowQueue(struct FIFO* OUT){
    while (OUT!=NULL){
        printf("kolejka = %d\n",OUT->number);
        OUT = OUT->Next;
    }
}

int IsEmpty(struct FIFO * OUT){
    if(OUT==NULL){
        return 1;
    }
    return 0;
}

//INSTRUKCJE DO FIFO

//    struct FIFO *IN = NULL;
//    IN= EnQueue(IN,0);
//    struct FIFO *OUT = IN;
//    for(int i = 1;i<100;i++){
//        IN= EnQueue(IN,i);
//    }
//    ShowQueue(OUT);
//    printf("czy pusta: %d\n", IsEmpty(OUT));
//    int n;
//    OUT = DeQueue(OUT,&n);
//    printf("n=%d\nOUT=%d\nIN=%d\n",n,OUT->number,IN->number);


//Graf

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

//BFS
int V[4] = {0,0,0,0};
int Kolor[4] = {0,0,0,0};
int d[4] = {0,0,0,0};

void BFS(int s, struct Lista** Graf){
    struct FIFO * IN=NULL;
    IN = EnQueue(IN,s);
    struct FIFO * OUT=IN;
    int u,v;
    int Nr=0;
    while(IsEmpty(OUT)!=1){
        if(IN == OUT){
            IN = NULL;
        }
        OUT= DeQueue(OUT,&u);
        while (Graf[u]->v != -1){
            v = Graf[u]->v;
            if(Kolor[v]==0){
                Kolor[v] = 1;
                d[v] = d[u]+1;
                IN = EnQueue(IN,v);
                if(OUT == NULL){
                    OUT = IN;
                }//if
            }//if
            V[u] = ++Nr;
            Kolor[u] = 2;
            Graf[u]=Graf[u]->Next;
        }//while
    }//while
}//BFS

int main(){
    struct Lista **Graf = (struct Lista **)malloc(4*sizeof(struct Lista *));

    //Listy Incydencji
    Graf[0] = Append(Graf[0],1);
    Graf[0] = Append(Graf[0],-1);

    Graf[1] = Append(Graf[1],0);
    Graf[1] = Append(Graf[1],2);
    Graf[1] = Append(Graf[1],-1);

    Graf[2] = Append(Graf[2],1);
    Graf[2] = Append(Graf[2],3);
    Graf[2] = Append(Graf[2],-1);

    Graf[3] = Append(Graf[3],2);
    Graf[3] = Append(Graf[3],0);
    Graf[3] = Append(Graf[3],-1);
    BFS(0,Graf);
    for(int i = 0;i<4;i++){
        printf("V[%d] = %d\n",i,V[i]);
    }

    return 0;
}
