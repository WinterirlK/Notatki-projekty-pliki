#include <cstdio>
#include <cstring>

int my_strcmp(char *str1, char *str2){
    while(*str1 != '\0' && *str2 != '\0' && *str1 == *str2){
        str1++;
        str2++;
    }
    if(*str1 == '\0' && *str2 == '\0'){
        return 0;
    }
    else if(*str1 > *str2){
        return 1;
    }
    else {
        return -1;
    }
}

void sortowanie(char word[][20],int size ,int*id){
    char str[20];
    int temp;
    for(int i = 0;i<size;i++){
        for(int j = 0;j<size-1-i;j++){
            if(my_strcmp(word[j],word[j+1])==1){
                temp = id[j];
                id[j] = id[j+1];
                id[j+1]=temp;
                strcpy(str,word[j]);
                strcpy(word[j],word[j+1]);
                strcpy(word[j+1],str);
            }
        }
    }
}
void sortowanie_adresu(char word[][40],int size ,int*id){
    char str[40];
    int temp;
    for(int i = 0;i<size;i++){
        for(int j = 0;j<size-1-i;j++){
            if(my_strcmp(word[j],word[j+1])==1){
                temp = id[j];
                id[j] = id[j+1];
                id[j+1]=temp;
                strcpy(str,word[j]);
                strcpy(word[j],word[j+1]);
                strcpy(word[j+1],str);
            }
        }
    }
}

void sortowanieWiek(float *tab, int size, int *id){
    int temp, temp_second;
    for(int i = 0;i<size;i++){
        for(int j = 0;j<size-1-i;j++){
            if(tab[j]>tab[j+1]){
                temp = id[j];
                id[j] = id[j+1];
                id[j+1]=temp;
                temp_second=tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp_second;
            }
        }
    }
}

int main(){
    FILE * fp = fopen("plik.txt","w+");
    char naz[10][20] = {"Rutkowski","Tomaszewski","Sikorska","Przybylski","Kozlowski","Wroblewski","Zielinski","Ostrowski","Piotrowski","Duda"};
    char imie[10][20] = {"Franciszek","Kacper","Andrzej","Klaudiusz","Emil","Roman","Jedrzej","Filip","Igor","Joachim"};
    char adres[10][40] = {"rondoMika8/2","os.Jagielski250","wyb.Misiak0/6","skwerFurman388","pl.Czyz96c","skwerKowalik23a","rondoMazurkiewicz70","wyb.Trzcinski2/9","rynekWrona6/1","rondoMuszynski24b"};
    float wiek[10] = {45,34,65,74,24,53,82,37,25,28};

    for(int i = 0;i<10;i++){
        fprintf(fp,"%20s %20s %40s %5.1f\n",naz[i],imie[i],adres[i],wiek[i]);
    }

    fseek(fp,0,SEEK_SET);
    FILE *fi = fopen("nazwiskoIndeksowy.txt","w+");
    char nazwiska_sort[10][20];
    int id[10];
    for(int i = 0;i<10;i++){
        id[i] = ftell(fp);
        fscanf(fp,"%s",nazwiska_sort[i]);
        fseek(fp,69,SEEK_CUR);
    }
    sortowanie(nazwiska_sort,10,id);
    for(int i = 0;i<10;i++){
        fprintf(fi,"%s %d\n",nazwiska_sort[i],id[i]);
    }

    fseek(fp,21,SEEK_SET);
    fclose(fi);
    fi = fopen("imieIndeksowy.txt","w+");
    char imie_sort[10][20];
    for(int i = 0;i<10;i++){
        id[i] = ftell(fp);
        fscanf(fp,"%s",imie_sort[i]);
        fseek(fp,69,SEEK_CUR);
    }
    sortowanie(imie_sort,10,id);
    for(int i = 0;i<10;i++){
        fprintf(fi,"%s %d\n",imie_sort[i],id[i]);
    }

    
    
    
    //ADRES POPRAW
    
    
    fseek(fp,41,SEEK_SET);
    fclose(fi);
    fi = fopen("adresIndeksowy.txt","w+");
    char adres_sort[10][40];
    for(int i = 0;i<10;i++){
        id[i] = ftell(fp);
        fscanf(fp,"%s",adres_sort[i]);
        fseek(fp,49,SEEK_CUR);
        //printf("%s %d\n",adres[i],id[i]);
    }
    sortowanie_adresu(adres,10,id);
    for(int i = 0;i<10;i++){
        fprintf(fi,"%s %d\n",adres_sort[i],id[i]);
    }

    
    
    
    
    
    fseek(fp,83,SEEK_SET);
    fclose(fi);
    fi = fopen("wiekIndeksowy.txt","w+");
    float wiek_sort[10];
    for(int i = 0;i<10;i++){
        id[i] = ftell(fp);
        fscanf(fp,"%f",&wiek_sort[i]);
        fseek(fp,84,SEEK_CUR);
    }
    sortowanieWiek(wiek_sort,10,id);
    for(int i = 0;i<10;i++){
        fprintf(fi,"%.1f %d\n",wiek_sort[i],id[i]);
    }
    return 0;
}
