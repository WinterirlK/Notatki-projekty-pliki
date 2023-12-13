#include <cstdio>
#include <cstdlib>

struct Lista{
    int liczba;
    struct Lista * Next;
};
struct Lista * Insert(struct Lista * Head, int liczba){
    struct Lista *p = (struct Lista *)calloc(1,sizeof(struct Lista));
    p->liczba=liczba;
    if(Head == NULL){
        p->Next = NULL;
        Head = p;
    }
    else{
        p->Next = Head;
        Head = p;
    }
    return(Head);
}

void Druk(struct Lista * Head){
    while (Head!=NULL){
        printf("%d\n",Head->liczba);
        Head = Head->Next;
    }
}

int ifExist(struct Lista * Head,int liczba){
    for(;Head!=NULL;Head=Head->Next){
        if(Head->liczba == liczba) return 1;
        continue;
    }
    return 0;
}

struct Lista * suma(struct Lista * A, struct  Lista *B){
    struct Lista * wynik = NULL;
    while (A!= NULL){
        wynik = Insert(wynik,A->liczba);
        A=A->Next;
    }
    while (B!= NULL){
        if(!ifExist(wynik,B->liczba)){
            wynik = Insert(wynik,B->liczba);
        }
        B=B->Next;
    }
    return wynik;
}

int len(struct Lista * Head){
    int i = 0;
    for(;Head!=NULL;i++,Head=Head->Next);
    return i;
}

void sort(struct Lista * Head){
    struct Lista * temp = Head;
    int temp_n;
    int size = len(Head);
    for(int i = 0;i<size-1;i++){
        Head = temp;
        for(int j = 0;j<size-1-i;j++,Head=Head->Next){
            if(Head->liczba>Head->Next->liczba){
                temp_n = Head->Next->liczba;
                Head->Next->liczba = Head->liczba;
                Head->liczba = temp_n;
            }
        }
    }
}

struct Lista * iloczyn(struct Lista *A, struct Lista *B){
    struct  Lista * wynik = NULL;
    while(A != NULL && B != NULL){
        if(ifExist(B,A->liczba)) {
            wynik = Insert(wynik,A->liczba);
        }
        A=A->Next; B=B->Next;
    }
    return wynik;
}

struct Lista * roznica(struct Lista * A, struct Lista * B){
    struct Lista * wynik = NULL;
    while (A!=NULL){
        if(B==NULL && A!= NULL){
            while (A!=NULL){
                wynik = Insert(wynik,A->liczba);
                A=A->Next;
            }
            return wynik;
        }
        if(!ifExist(B,A->liczba)){
            wynik = Insert(wynik,A->liczba);
        }
        A=A->Next;
        if(B!=NULL){
            B=B->Next;
        }
    }
    return wynik;
}

int podzbior(struct Lista * A, struct Lista * B) {
    while (A!=NULL){
        if(B==NULL){
            return 0;
        }
        if(!ifExist(B,A->liczba)) {
            return 0;
        }
        A=A->Next;
        if(B!=NULL){
            B=B->Next;
        }
    }
    return 1;
}

int main(){
    struct Lista *A = NULL;
    struct Lista *B = NULL;
    struct Lista *AuB = NULL;
    struct Lista * AnB = NULL;
    struct Lista * A_B = NULL;
    int AcB;
    for(int i = 0;i<25;i+=2){
        A = Insert(A,i);
    }
    printf("A:\n");
    Druk(A);
    putchar('\n');


    for(int i = 1;i<25;i+=2){
        B = Insert(B,i);
    }
    printf("B:\n");
    Druk(B);
    putchar('\n');

    AuB = suma(A,B);
    if(AuB != NULL){
        sort(AuB);
        printf("AuB:\n");
        Druk(AuB);
    }
    else{
        printf("zbior pusty!");
    }

    putchar('\n');

    AnB = iloczyn(A,B);
    printf("AnB:\n");
    if(AnB != NULL){
        sort(AnB);
        Druk(AnB);
    }
    else{
        printf("zbior jest pusty");
    }

    putchar('\n');

    A_B = roznica(A,B);
    printf("A-B:\n");
    if(A_B!=NULL){
        sort(A_B);
        Druk(A_B);
    }
    else{
        printf("zbior jest pusty");
    }

    putchar('\n');
    AcB = podzbior(A,B);
    if(AcB){
        printf("A jest podzbiorem B\n");
    }
    else{
        printf("A nie jest podzbiorem B\n");
    }
}
