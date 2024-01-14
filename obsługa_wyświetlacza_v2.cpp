#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>

int pobierz_cyfre(int liczba, int id);
int sprawdz();
int zmiana_cyfry(int* liczba, int id, int ncyfra);
void wypisz();

int liczby, id_strona_prawa;
static int iliczby[500000];
char* dodanie_zapalki[10] = {"8", "7", "", "9", "", "69", "8", "", "", "8"};
char* zamiana_zapalki[10] = {"69", "", "3", "25", "", "3", "09", "", "", "06"};
char* po_odebraniu_zapalki[10] = {"", "", "", "", "", "", "5", "1", "069", "35"};

int main(){
	int i, j, k, l, m, n, cyfra, cyfra2, tmp, tmp2;

	char cliczba[16];

	for (i=0; ; i++){ //zaczytanie danych
		if ((*cliczba = getchar()) == '='){
			id_strona_prawa = i;
			*cliczba = getchar();
		}
		for (j=1; ((cliczba[j] = getchar()) != '+' && cliczba[j] != '-' && cliczba[j] != '=' && cliczba[j] != '\n' && cliczba[j] != EOF); j++);
		ungetc(cliczba[j], stdin);
		if (cliczba[j] == '\n' || cliczba[j] == EOF){
			cliczba[j] = '\0';
			iliczby[i] = atoi(cliczba);
			break;
		}
		cliczba[j] = '\0';
		iliczby[i] = atoi(cliczba);
	}
	liczby = i+1;

	for (i=0; i<liczby; i++){ // zamiana zapałki w obrębie liczby. i - id liczby
		for (j=0; (cyfra = pobierz_cyfre(iliczby[i], j)) >= 0; j++){ // j - id cyfry w liczbie (liczone od końca)
			for (k=0; zamiana_zapalki[cyfra][k] != '\0'; k++){
				tmp = iliczby[i];
				zmiana_cyfry(&iliczby[i], j, zamiana_zapalki[cyfra][k]-'0');
				if (sprawdz()){
					wypisz();
					return 0;
				}
				iliczby[i] = tmp;
			}
		}
	}


	for (i=0; i<liczby; i++){ // zamiana zapałek między liczbami
		for (j=0; (cyfra = pobierz_cyfre(iliczby[i], j)) >= 0; j++){
			for (k=0; po_odebraniu_zapalki[cyfra][k] != '\0'; k++){
				tmp = iliczby[i];
				zmiana_cyfry(&iliczby[i], j, po_odebraniu_zapalki[cyfra][k]-'0');
				
				for (l=0; l<liczby; l++){ // dodawanie od początku
					for (m=0; (cyfra2 = pobierz_cyfre(iliczby[l], m)) >= 0; m++){
						for (n=0; dodanie_zapalki[cyfra2][n] != '\0'; n++){
							tmp2 = iliczby[l];
							zmiana_cyfry(&iliczby[l], m, dodanie_zapalki[cyfra2][n]-'0');
							if (sprawdz()){
								wypisz();
								return 0;
							}
							iliczby[l] = tmp2;
						}
					}
				}
				iliczby[i] = tmp;
			}
		}
	}

	printf("no");
	
	return 0;
}

int pobierz_cyfre(int liczba, int id){
	int potega = pow(10, id);
	if (liczba < 0)
		liczba *= -1;

	if (liczba < potega)
		return -1;

	return (liczba/potega)%10;
}

int sprawdz(){
	int l=0, p=0, i;
	
	for (i=0; i<id_strona_prawa; i++)
		l += iliczby[i];
	for (; i<liczby; i++)
		p += iliczby[i];

	return l == p;
}

int zmiana_cyfry(int* liczba, int id, int ncyfra){
	int potega = pow(10, id), ujemna=1;
	if (*liczba < 0){
		*liczba *= -1;
		ujemna = -1;
	}

	if (*liczba < potega){
		*liczba *= ujemna;
		return 1;
	}

	int tmp = *liczba / potega;
	tmp = tmp % 10;

	*liczba -= tmp * potega;
	*liczba += ncyfra * potega;
	*liczba *= ujemna;

	return 0;
}

void wypisz(){
	int i;
	printf("%d", *iliczby);
	for (i=1; i<id_strona_prawa; i++){
		if (iliczby[i] < 0)
			printf("%d", iliczby[i]);
		else
			printf("+%d", iliczby[i]);
	}
	putchar('=');
	printf("%d", iliczby[i++]);
	for (; i<liczby; i++){
		if (iliczby[i] < 0)
			printf("%d", iliczby[i]);
		else
			printf("+%d", iliczby[i]);
	}
}