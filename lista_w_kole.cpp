#include <cstdio>
#include <cstdlib>

struct Lista{
    int liczba;
    struct Lista * Next;
    int pierwszy;
};

struct Lista * Append(struct Lista *Head, int liczba){
    struct Lista *p = (struct Lista *)calloc(1,sizeof(struct Lista));
    p->liczba = liczba;
    if(Head == NULL){
        p->Next = p;
        p->pierwszy = 1;
        Head = p;
    }
    else{
        struct Lista * temp = Head;
        p->Next = Head;
        p->pierwszy=0;
        while (temp->Next != Head) temp=temp->Next;
        temp->Next = p;
    }
    return Head;
}
struct  Lista * Insert(struct Lista *Head, int liczba){
    struct Lista *p = (struct Lista *)calloc(1,sizeof(struct Lista));
    p->liczba = liczba;
    if(Head==NULL){
        p->Next=p;
        p->pierwszy=1;
        Head=p;
    }
    else{
        p->pierwszy=1;
        Head->pierwszy=0;
        struct Lista * temp = Head;
        while (temp->Next!=Head)temp=temp->Next;
        temp->Next = p;
        p->Next=Head;
        Head=p;
    }
    return Head;
}

int count(struct Lista * Head){
    int l = 1;
    Head = Head->Next;
    while (Head->pierwszy!=1){
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
        for(int i = 0;i<id-1;i++,temp_P=temp_P->Next);
        struct Lista *temp_N=temp_P->Next;
        temp_P->Next = p;
        p->Next = temp_N;
        p->pierwszy=0;
        return Head;
    }
    else{
        return Head;
    }
}

void Druk(struct Lista*Head){
    printf("%i\n",Head->liczba);
    Head=Head->Next;
    while(Head->pierwszy!=1){
        printf("%d\n",Head->liczba);
        Head = Head->Next;
    }
}

struct Lista * Del(struct Lista * Head, int id){
    if(id > 0 && id < count(Head)-1){
        struct Lista * temp = Head;
        for(int i = 0; i<id-1; i++){
            Head = Head->Next;
        }
        struct Lista * temp_P = Head;
        struct Lista * temp_N = Head->Next;
        temp_N= temp_N->Next;
        Head = Head->Next;
        temp_P->Next = temp_N;
        free(Head);
        return temp;
    }
    else if(id==0){
        struct Lista * temp_N = Head->Next;
        temp_N->pierwszy = 1;
        free(Head);
        return temp_N;
    }
    else if(id == count(Head)-1){
        struct Lista * temp = Head;
        while(temp->Next!=Head){
            temp=temp->Next;
        }
        struct Lista * f = Head;
        while (f->Next!=temp) f=f->Next;
        f->Next=Head;
        free(temp);
        return Head;
    }
    return Head;
}
struct Lista * start(struct Lista * Head){
    while (Head->pierwszy!=1) Head = Head->Next;
    return Head;
}
int ifExist(struct Lista * Head, int liczba){
    if(Head->liczba==liczba) return 1;
    Head=Head->Next;
    while (Head->pierwszy!=1){
        if(Head->liczba == liczba){
            return 1;
        }
        Head = Head->Next;
    }
    return 0;
}

void edit(struct Lista * Head, int liczba, int id){
    if(id>=0 && id < count(Head)){
        for(int i = 0; i<id;i++,Head=Head->Next);
        Head->liczba=liczba;
    }
}

int get(struct Lista * Head, int id){
    for(int i = 0;i<id;i++,Head=Head->Next);
    return Head->liczba;
}

int main() {
    struct Lista * Head;
    Head = Append(Head,1);
    Head = Append(Head,2);
    Head = Insert(Head,18);
    Head = Append(Head,3);
    Head = Insert(Head,8);
    Head = Insert(Head,12);
    Head = dodaj(Head,100,2);
    Druk(Head);
    printf("ilosc: %i\n", count(Head));
    printf("usuwamy 4 indeks\n");
    Head = Del(Head,4);
    Druk(Head);
    printf("ilosc: %i\n", count(Head));
    printf("czy istnieje 100: %i\n", ifExist(Head,100));
    edit(Head,1000,2);
    Druk(Head);
    printf("Lista[%i] = %d\n",5,get(Head,5));
    return 0;
}
