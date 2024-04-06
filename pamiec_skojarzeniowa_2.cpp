#include<cstdio>
#include<cstdlib>
#include<cstring>


int Hash(char* txt, int i){
    int size = 0;
    while (*txt!='\0'){
        size += *txt;
        txt++;
    }
    return (size%7)+i;
}

void zamien(char* to, char* from){
    while(*from != '\0'){
        *to = *from;
        to++; from++;
    }
    *to = '\0';
}

void Insert(char** Array, char *txt, int size){
    int i = 0;
    do{
        int j = Hash(txt, i);
        if(Array[j] == NULL){
            Array[j] = (char*)malloc(strlen(txt) + 1);
            zamien(Array[j],txt);
            return;
        }
        else{
            i++;
        }
    } while (i<size);
    printf("Pełna tablica!\n");
}

int Search(char **Array, char *txt, int size){
    int i = 0;
    do{
        int j = Hash(txt,i);
        if(Array[j]!=NULL){
            if(strcmp(Array[j],txt)==0){
                return j;
            }
            else{
                i++;
            }
        }
        else{
            return -1;
        }
    }while(i<size);
    return -1;
}

int main(){
    char **Array = (char **) malloc(10*sizeof(char *));
    for(int i = 0;i<10;i++){
        Array[i] = NULL;
    }
    char txt1[] = "abc"; // hash zwróci 0
    char txt2[] = "bbb"; // hash zwróci 0
    char txt3[] = "cab"; // hash zwróci 0
    Insert(Array,txt1,10);
    Insert(Array,txt2,10);
    Insert(Array,txt3,10);
    for(int i = 0;i<10;i++){
        if(Array[i]!=NULL){
            printf("%s\n",Array[i]);
        }
    }
    char str1[] = "abc";
    char str2[] = "bbb";
    char str3[] = "cab";
    char str4[] = "asd";
    printf("%s %d\n",str1,Search(Array,str1,10));
    printf("%s %d\n",str2,Search(Array,str2,10));
    printf("%s %d\n",str3,Search(Array,str3,10));
    printf("%s %d\n",str4,Search(Array,str4,10)); //gdy nie ma -1
}
