#include <cstdio>
#include <cstdlib>
#include <cctype>

int sprawdz(int iliczby[500000], int id_strona_prawa, int liczby);
void wypisz(char cliczby[500001][12], int id_strona_prawa, int liczby);

int main(){
	int i, j, k, l, m, n, liczby, id_strona_prawa, tmp, tmp2;
	char* dodanie_zapalki[10] = {"8", "7", "", "9", "", "69", "8", "", "", "8"};
	char* zamiana_zapalki[10] = {"69", "", "3", "25", "", "3", "09", "", "", "06"};
	char* po_odebraniu_zapalki[10] = {"", "", "", "", "", "", "5", "1", "069", "35"};
	int odebranie_zapalki[10] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1};

	static int iliczby[500000];
	static char cliczby[500001][12];

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

	for (i=1; i<liczby; i++)
		iliczby[i] = atoi(cliczby[i]);

	for (i=0; i<liczby; i++){ // zamiana zapałki w obrębie liczby
		for (j=0; cliczby[i][j] != '\0'; j++){
			if (isdigit(cliczby[i][j])){
				for (k=0; zamiana_zapalki[ cliczby[i][j]-'0' ][k] != '\0'; k++){
					tmp = cliczby[i][j];
					cliczby[i][j] = zamiana_zapalki[ cliczby[i][j]-'0' ][k];
					iliczby[i] = atoi(cliczby[i]);
					if (sprawdz(iliczby, id_strona_prawa, liczby)){
						wypisz(cliczby, id_strona_prawa, liczby);
						return 0;
					}
					cliczby[i][j] = tmp;
				}
			}
		}
		iliczby[i] = atoi(cliczby[i]);
	}

	for (i=0; i<liczby; i++){ // zamiana zapałek między liczbami
		for (j=0; cliczby[i][j] != '\0'; j++){
			if (isdigit(cliczby[i][j]) && odebranie_zapalki[ cliczby[i][j]-'0' ]){
				for (k=0; po_odebraniu_zapalki[ cliczby[i][j]-'0' ][k] != '\0'; k++){
					tmp = cliczby[i][j];
					cliczby[i][j] = po_odebraniu_zapalki[ cliczby[i][j]-'0' ][k];
					iliczby[i] = atoi(cliczby[i]);
					for (l=0; l<liczby; l++){ // dodawanie od początku
						for (m=0; cliczby[l][m] != '\0'; m++){
							if (isdigit(cliczby[l][m])){
								for (n=0; dodanie_zapalki[ cliczby[l][m]-'0' ][n] != '\0'; n++){
									tmp2 = cliczby[l][m];
									cliczby[l][m] = dodanie_zapalki[ cliczby[l][m]-'0' ][n];
									iliczby[l] = atoi(cliczby[l]);
									if (sprawdz(iliczby, id_strona_prawa, liczby)){
										wypisz(cliczby, id_strona_prawa, liczby);
										return 0;
									}
									cliczby[l][m] = tmp2;
								}
							}
						}
					}
					cliczby[i][j] = tmp;
				}
			}
		}
		iliczby[i] = atoi(cliczby[i]);
	}
	printf("no");

	return 0;
}

int sprawdz(int iliczby[500000], int id_strona_prawa, int liczby){
	int l=0, p=0, i;
	
	for (i=0; i<id_strona_prawa; i++)
		l += iliczby[i];
	for (; i<liczby; i++)
		p += iliczby[i];

	return l == p;
}

void wypisz(char cliczby[500001][12], int id_strona_prawa, int liczby){
	int i;
	for (i=0; i<id_strona_prawa; i++)
		printf("%s", cliczby[i]);
	putchar('=');
	for (; i<liczby; i++)
		printf("%s", cliczby[i]);
}