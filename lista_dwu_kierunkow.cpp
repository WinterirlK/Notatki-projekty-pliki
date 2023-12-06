#include <cstdio>
#include <cstdlib>

struct Lista{
    int liczba;
    struct Lista * Next;
    struct Lista * Prev;
};

struct Lista * Append(struct Lista *Head, int liczba){
    struct Lista *p = (struct Lista *)calloc(1,sizeof(struct Lista));
    p->liczba = liczba;
    if(Head == NULL){
        p->Next = NULL;
        p->Prev = NULL;
        Head = p;
    }
    else{
        struct Lista *temp = Head;
        while (temp->Next != NULL){
            temp=temp->Next;
        }
        temp->Next = p;
        struct Lista *temp_sec = temp;
        temp = temp->Next;
        temp->Prev = temp_sec;
    }
    return Head;
}
struct  Lista * Insert(struct Lista *Head, int liczba){
    struct Lista *p = (struct Lista *)calloc(1,sizeof(struct Lista));
    p->liczba = liczba;
    if(Head == NULL){
        p->Next = NULL;
        p->Prev = NULL;
        Head = p;
    }
    else{
        struct Lista * temp = Head;
        p->Next = temp;
        temp->Prev = p;
        Head = p;
    }
    return Head;
}

int count(struct Lista * Head){
    int l = 0;
    while (Head!=NULL){
        Head = Head->Next;
        l++;
    }
    return l;
}

struct Lista * dodaj(struct Lista * Head, int liczba, int id){
    if(id==0){
        return Insert(Head,liczba);
    }
    else if(id == count(Head)){
        return Append(Head, liczba);
    }
    else if(id>0 && id< count(Head)){
        struct Lista *p = (struct Lista *)calloc(1,sizeof(struct Lista));
        p->liczba = liczba;
        struct Lista * temp_P = Head;
        for(int i = 0; i<id-1;i++)temp_P = temp_P->Next;
        struct Lista * temp_N = temp_P->Next;
        temp_N->Prev = p;
        temp_P->Next = p;
        p->Prev = temp_P;
        p->Next = temp_N;
        return Head;
    }
    else{
        return Head;
    }
}

void Druk(struct Lista*Head){
    if(Head!=NULL){
        printf("%d\n",Head->liczba);
        Druk(Head->Next);
    }
}

struct Lista * Del(struct Lista * Head, int id){
    if(id > 0 && id < count(Head)-1){
        struct Lista * temp = Head;
        for(int i = 0; i<id; i++){
            Head = Head->Next;
        }
        struct Lista * temp_P = Head->Prev;
        struct Lista * temp_N = Head->Next;
        temp_P->Next = temp_N;
        temp_N->Prev = temp_P;
        free(Head);
        return temp;
    }
    else if(id==0){
        struct Lista * temp_N = Head->Next;
        temp_N->Prev = NULL;
        free(Head);
        return temp_N;
    }
    else if(id == count(Head)-1){
        struct Lista * temp = Head;
        while(temp->Next!=NULL){
            temp=temp->Next;
        }
        struct Lista * f = temp;
        temp=temp->Prev;
        free(f);
        temp->Next = NULL;
        return Head;
    }
    return Head;
}
struct Lista * start(struct Lista * Head){
    while (Head->Prev!=NULL) Head = Head->Prev;
    return Head;
}
int ifExist(struct Lista * Head, int liczba){
    while (Head!=NULL){
        if(Head->liczba == liczba){
            return 1;
        }
        Head = Head->Next;
    }
    return 0;
}

int main() {
    struct Lista * Head;
    Head = Append(Head,1);
    Head = Insert(Head,2);
    Head = Insert(Head,3);
    Head = Append(Head,4);
    Head = Insert(Head,5);
    Head = Append(Head,6);
    Druk(Head);
    printf("ilosc: %i\n", count(Head));
    Head = Del(Head,3);
    Druk(Head);
    printf("dodajemy 1\n");
    Head = dodaj(Head,1,3);
    Druk(Head);
    if(ifExist(Head,1)){
        printf("istnije 1\n");
    }
    else{
        printf("nie istnieje 1\n");
    }

    return 0;
}
