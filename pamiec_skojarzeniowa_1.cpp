#include <cstdio>
#include <cstdlib>
#include <cstring>

int Hash(int key, int i){
    return (key % 7) +i;
}

void Insert(int *Array, int key, int size){
    int i = 0;
    do{
        int j = Hash(key, i);
        if(Array[j] == NULL){
            Array[j] = key;
            return;
        }
        else{
            i++;
        }
    } while (i<size);
    printf("Pełna tablica!\n");
}

int Search(int* Array, int key, int size){
    int i = 0;
    do{
        int j = Hash(key, i);
        if(Array[j] == key){
            return j;
        }
        else if(Array[j] != NULL){
            i++;
        }
        else{
            return -1;
        }
    } while (i<size);
    return -1;
}

int main(){
    int Array[10] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
    Insert(Array,7,10);
    Insert(Array,14,10);
    Insert(Array,21,10);
    Insert(Array,2,10);
    for(int i = 0; i<10; i++){
        printf("Array[%d] = %d\n",i,Array[i]);
    }
    for(int i = 7;i<=21;i+=7){
        printf("Indeks: %d liczby %d\n", Search(Array,i,10),i);
    }
    printf("Indeks: %d liczby %d\n", Search(Array,10,10),10); //gdy nie ma -1

}
