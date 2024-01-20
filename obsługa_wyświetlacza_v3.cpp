#include <cstdio>
#include <cstdlib>
#include <cctype>

void podstaw(int id, long long int sliczba, long long int nliczba);
void wypisz();


static char cliczby[500001][12];
static long long int iliczby[500000];
int id_strona_prawa, liczby;
long long int strona_lewa=0, strona_prawa=0;

int main(){
	int i, j, k, l, m, n, tmp, tmp2;
	char* dodanie_zapalki[10] = {"8", "7", "", "9", "", "69", "8", "", "", "8"};
	char* zamiana_zapalki[10] = {"69", "", "3", "25", "", "3", "09", "", "", "06"};
	char* po_odebraniu_zapalki[10] = {"", "", "", "", "", "", "5", "1", "069", "35"};
	int odebranie_zapalki[10] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1};


	for (i=0; ; i++){ //zaczytanie danych
		if ((*(cliczby[i]) = getchar()) == '='){
			id_strona_prawa = i;
			*(cliczby[i]) = getchar();
		}
		for (j=1; ((cliczby[i][j] = getchar()) != '+' && cliczby[i][j] != '-' && cliczby[i][j] != '=' && cliczby[i][j] != '\n' && cliczby[i][j] != EOF); j++);
		ungetc(cliczby[i][j], stdin);
		if (cliczby[i][j] == '\n' || cliczby[i][j] == EOF){
			cliczby[i][j] = '\0';
			break;
		}
		cliczby[i][j] = '\0';
	}
	liczby = i+1;

	for (i=0; i<liczby; i++)
		iliczby[i] = atoll(cliczby[i]);

	for (i=0; i<id_strona_prawa; i++)
		strona_lewa += iliczby[i];
	for (; i<liczby; i++)
		strona_prawa += iliczby[i];

	for (i=0; i<liczby; i++){ // zamiana zapałki w obrębie liczby
		for (j=0; cliczby[i][j] != '\0'; j++){
			if (isdigit(cliczby[i][j])){
				for (k=0; zamiana_zapalki[ cliczby[i][j]-'0' ][k] != '\0'; k++){
					tmp = cliczby[i][j];
					cliczby[i][j] = zamiana_zapalki[ cliczby[i][j]-'0' ][k];
					podstaw(i, iliczby[i], atoll(cliczby[i]));
					if (strona_lewa == strona_prawa){
						wypisz();
						return 0;
					}
					cliczby[i][j] = tmp;
				}
			}
		}
		podstaw(i, iliczby[i], atoll(cliczby[i]));
	}

	for (i=0; i<liczby; i++){ // zamiana zapałek między liczbami
		for (j=0; cliczby[i][j] != '\0'; j++){
			if (isdigit(cliczby[i][j]) && odebranie_zapalki[ cliczby[i][j]-'0' ]){
				for (k=0; po_odebraniu_zapalki[ cliczby[i][j]-'0' ][k] != '\0'; k++){
					tmp = cliczby[i][j];
					cliczby[i][j] = po_odebraniu_zapalki[ cliczby[i][j]-'0' ][k];
					podstaw(i, iliczby[i], atoll(cliczby[i]));
					for (l=0; l<liczby; l++){ // dodawanie od początku
						for (m=0; cliczby[l][m] != '\0'; m++){
							if (isdigit(cliczby[l][m])){
								for (n=0; dodanie_zapalki[ cliczby[l][m]-'0' ][n] != '\0'; n++){
									tmp2 = cliczby[l][m];
									cliczby[l][m] = dodanie_zapalki[ cliczby[l][m]-'0' ][n];
									podstaw(l, iliczby[l], atoll(cliczby[l]));
									if (strona_lewa == strona_prawa){
										wypisz();
										return 0;
									}
									cliczby[l][m] = tmp2;
								}
							}
						}
						podstaw(l, iliczby[l], atoll(cliczby[l]));
					}
					cliczby[i][j] = tmp;
				}
			}
		}
		podstaw(i, iliczby[i], atoll(cliczby[i]));
	}
	printf("no");

	return 0;
}

void podstaw(int id, long long int sliczba, long long int nliczba){
	if (id < id_strona_prawa)
		strona_lewa = strona_lewa - sliczba + nliczba;
	else
		strona_prawa = strona_prawa - sliczba + nliczba;
	
	iliczby[id] = nliczba;
}

void wypisz(){
	int i;
	for (i=0; i<id_strona_prawa; i++)
		printf("%s", cliczby[i]);
	putchar('=');
	for (; i<liczby; i++)
		printf("%s", cliczby[i]);
}