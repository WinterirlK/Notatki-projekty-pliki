#include <cstdio>
#include <cstring>
#define N 26
struct Osoba{
    char Nazwisko[20];
    int wiek;
};

int main(){
    struct Osoba O[5];
    struct Osoba plik[2];
    FILE * fp = fopen("plik.txt","w");
    for(int i = 0;i<5;i++){
        O[i].wiek = (i+2)*10;
    }
    strcpy(O[0].Nazwisko,"qwertyuiop");
    strcpy(O[1].Nazwisko,"qwertyuiopasdfghjkl");
    strcpy(O[2].Nazwisko,"qwert");
    strcpy(O[3].Nazwisko,"qwertyuiopasdfg");
    strcpy(O[4].Nazwisko,"k");
    for(int i = 0;i<5;i++){
        fseek(fp,N*i,SEEK_SET);
        fprintf(fp,"%20s %5d ",O[i].Nazwisko, O[i].wiek);
        fseek(fp,0,SEEK_END);
    }
    fclose(fp);
    fp = fopen("plik.txt","r");
    if(!fp) {
        printf("blad");
        return 0;
    }
    for(int i = 0;i<2;i++){
        fseek(fp,26,SEEK_CUR);
        fscanf(fp,"%s %d",plik[i].Nazwisko, &plik[i].wiek);
    }
    for(int i = 0;i<2;i++){
        printf("%20s %5d\n",plik[i].Nazwisko,plik[i].wiek);
    }
    fclose(fp);
    return 0;
}
