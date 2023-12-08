#include <cstdio>
#include <cstdlib>

int length(char *str){
    int i = 0;
    for(;*str!='\0';i++,str++);
    return i;
}
int convert(int *array, int size){
    int l[size];
    int j = 0;
    for(int i = 0;i<size;i++){
        if(array[i]>=0 && array[i] <= 8){
            l[j] = array[i]+1;
            j++;
        }
        else{
            l[j] = array[i]-8;
            j++;
        }
    }
    int suma = (l[0])*10+(l[size-1]);
    return suma;
}

int join(char * str){
    char txt[18][6] = {"1","2","3","4","5","6","7","8","9","one","two","three","four","five","six","seven","eight","nine"};
    int tab[50];
    int k = 0;
    int condition;
    while (*str!='\0'){
        char * temp = str;
        for(int i = 0;i<18;i++){
            str = temp;
            for(int j=0;j < length(txt[i]);j++){
                if(*str == txt[i][j]){
                    condition=1;
                    str++;
                    continue;
                }
                condition=0;
                break;
            }
            if(condition){
                tab[k] = i;
                k++;
            }
        }
        str++;
    }
    if(k==1){
        tab[k] = tab[0];
        k++;
    }
    printf("%d\t%d\n",tab[0],tab[1]);
    return convert(tab,k);
}

int main() {
    printf("%d", join("n57"));
    return 0;
}
