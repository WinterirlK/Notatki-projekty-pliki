#include <cstdio>
#include <cstdlib>

int join(char * str){
    int l = 0;
    char kon[2];
    char * temp = str;
    for(;*str!='\0';str++)
        if(*str >= '0' && *str <= '9')l++;
    str = temp;
    if(l==0){
        return 0;
    }
    else if(l==1){
        for(;*str!='\0';str++)
            if(*str >= '0' && *str <= '9'){
                kon[0] = *str;
                kon[1] = *str;
            }
    }
    else if(l==2){
        int i = 0;
        for(;*str!='\0';str++)
            if(*str >= '0' && *str <= '9'){
                kon[i] = *str;
                i++;
            }
    }
    else{
        int i = 0;
        for(;*str!='\0';str++)
            if(*str >= '0' && *str <= '9'){
                    kon[i] = *str;
                    i=1;
                }
            }
    int suma = 0;
    suma = (kon[0]-'0') * 10 + (kon[1]-'0');
    return suma;
}

int main() {
    FILE *f_in = fopen("input.txt","r");
    FILE *f_out = fopen("output.txt","w");
    if(!f_in){
        printf("blad");
        return 0;
    }
    char str[50];
    int suma = 0;
    while (!feof(f_in)){
        fscanf(f_in,"%s",str);
        suma += join(str);
        printf("%s\t%d\n",str,suma);
    }
    fprintf(f_out,"%d",suma);
    return 0;
}
