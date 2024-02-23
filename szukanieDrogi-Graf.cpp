#include <cstdio>
#include <cstdlib>

int V[4] = {0,0,0,0};

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

int CzyJestDroga(int i_A, int nr_B, struct Lista ** Graf) {
    int R;
    if( V[i_A] == 0 ) { // nie byl odwiedzony
        if(i_A != nr_B ) {
            for(int i=0; i< 4; i++) {
                if(Graf[i_A]->v > -1) {
                    V[i]=1; // odwiedzony
                    R=CzyJestDroga( Graf[i_A]->v, nr_B,Graf);
                    if(R == 1)  return(1);
                }
                Graf[i_A]=Graf[i_A]->Next;
            }
        }
        else {
       return(1);
        }
    return(0);
    }
    else {
        return(0); // juz odwiedzony
    }
   
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
    if(CzyJestDroga(3,2,Graf)){
        printf("Jest Droga!");
    }
    else{
        printf("nie ma dorgi");
    }
}
