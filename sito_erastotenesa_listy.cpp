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

int count(struct Lista * Head){
    int i = 0;
    for(;Head!=NULL;i++,Head=Head->Next);
    return i;
}

struct Lista*Del(struct Lista * Head){
    struct Lista *p = Head->Next;
    Head->Next=Head->Next->Next;
    free(p);
    return Head;
}

struct Lista * SitoErastotenesa(int n){
    struct Lista *Head = NULL;
    for(int i = 2;i<=n;i++){
        Head = Insert(Head,i);
    }
    struct Lista * tmp = Head;
    for(int i=2;i*i<=n;i++){
        tmp=Head;
        while (tmp->liczba<i){
            tmp=tmp->Next;
        }
        for(int j = i+i;j<=n;j+=i){
            while (tmp->Next!=NULL && tmp->Next->liczba<j){
                tmp=tmp->Next;
            }
            if(tmp->Next!=NULL && tmp->Next->liczba>j){
                continue;
            }
            else if(tmp->Next!=NULL){
                tmp=Del(tmp);
            }
        }
    }
    return Head;
}

int main(){
    struct Lista* tab = SitoErastotenesa(100000);
    struct Lista* tab2;
    int i, tmp;

    for (i=2; i<=100000; i++){
        printf("%d -", i);
        tmp = i;
        while(tmp > 1){
            for (tab2 = tab; ; tab2 = tab2->Next){
                if ((tmp % tab2->liczba) == 0){
                    tmp /= tab2->liczba;
                    printf(" %d", tab2->liczba);
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
