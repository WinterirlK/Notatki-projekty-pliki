#include <stdio.h>

int length(const char *str) {
    int i = 0;
    for (; *str != '\0'; i++, str++);
    return i;
}

int string_compare(char *to_compare) {
    int i = 0;
    int condition = 0;
    int pierwsza = 0;
    int ostatnia = 0;
    int u = 0;
    int suma = 0;
    int xd = 0;
    char txt[18][9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    while (to_compare[i] != '\0') {
        for (int j = 0; j < 18; j++) {
            for (int k = 0; k < length(txt[j]); k++) {
                if (to_compare[i + k] != txt[j][k]) {
                    condition = 0;
                    break;
                }
                condition = 1;
            }
            if (condition == 1) {
                if(xd == 0) {
                    pierwsza = j;
                    ostatnia = j;
                    xd = 1;
                }
                else {
                    ostatnia = j;
                }
                u++;
                printf("%s\t",txt[j]);


            }
        }
        i++;
    }
    pierwsza++;
    ostatnia++;
    if(pierwsza>9) {
        pierwsza -= 9;

    }
    if(ostatnia>9) {
        ostatnia -= 9;
    }
    suma = pierwsza *10 + ostatnia;

    return suma;
}

int main() {
    FILE *f_in = fopen("input.txt","r");
    if(!f_in){
        printf("blad");
        return 0;
    }
    char str[50];
    int suma = 0;
    while (!feof(f_in)){
        fscanf(f_in,"%s",str);
        int result =string_compare(str);
        printf("\n\n");
        suma += result;
    }
    printf("%d", suma);
    return 0;
}
