#include <cstdio>
#include <cstdlib>

struct Lista {
    int liczba;
    struct Lista * Next;
};

struct Lista * Insert(struct Lista * Head, int liczba){
    struct Lista * p = (struct Lista *)calloc(1,sizeof(struct Lista));
    p->liczba = liczba;
    if(Head==NULL){
        p->Next = NULL;
        Head=p;
    }
    else{
        struct Lista * temp = Head;
        while (temp->Next!=NULL) temp=temp->Next;
        temp->Next=p;
        p->Next=NULL;
    }
    return Head;
}

void Druk(struct Lista * Head){
    while(Head!=NULL){
        printf("%d\n",Head->liczba);
        Head = Head->Next;
    }
}

struct Lista * Del(struct Lista * Head){
    Head=Head->Next;
    return Head;
}

struct Lista * SitoErastotenesa(int n){
    struct Lista * Head = NULL;
    for(int i = 2;i<=n;i++){
        Head = Insert(Head,i);
    }
    struct Lista * temp = Head;
    for(int i = 2;i<=n;i++){
        temp = Head;
        for(int j = i+i;j<=n;j+=i){
            while (temp!=NULL){
                if(temp->liczba==j) temp = Del(Head);
                temp=temp->Next;
            }
        }
    }
    return Head;
}

int main(){
    struct Lista * Head = SitoErastotenesa(10);
    Druk(Head);
    return 0;
}
