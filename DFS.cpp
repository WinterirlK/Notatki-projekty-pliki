#include <cstdio>
#include <cstdlib>

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

int V[4] = {0,0,0,0}; //tablica kolejność odwiedzancyh wierzchołków
int Nr=0; // globany licznik

int DFS(int i_A, struct Lista ** Graf) {
    if(V[i_A] == 0) {
        Nr++;
        V[i_A]=Nr; // odwiedzony
      for(int i=0; i<4;i++) {
          if(Graf[i]->v > -1) {
            DFS(Graf[i]->v,Graf);
          }//if
           
      }// for
    }//if
    else {
        return (0);
    }// if
}

int main(){
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
    
    int i = 0;
    DFS(0,Graf);
    for(;i<4;i++){
        printf("V[%d] = %d\n",i,V[i]);
    }
}
