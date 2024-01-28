#include <cstdio>
#include <cstdlib>

struct okres{
	unsigned int start;
	unsigned int koniec;
	unsigned int cena;
	struct okres* next;
};

void dodaj(struct okres* dni, unsigned int* ceny_poczatkowe);

unsigned int suma=0;

int main(){
	unsigned int produkty, promocje;
	unsigned int i;

	scanf("%u %u", &produkty, &promocje);

	unsigned int ceny_poczatkowe[produkty+1];

	for (i=1; i<=produkty; i++){
		scanf("%d", ceny_poczatkowe+i);
		suma += ceny_poczatkowe[i];
	}

	unsigned int najnizsza_cena=suma, najnizszy_dzien;

	struct okres* dni = (struct okres*) calloc(1, sizeof(struct okres));
	dni->start = 1;
	dni->koniec--;
	dni->cena = suma;

	while (promocje){
		dodaj(dni, ceny_poczatkowe);
		promocje--;
	}

	while (dni != NULL){
		if (dni->cena < najnizsza_cena){
			najnizsza_cena = dni->cena;
			najnizszy_dzien = dni->start;
		}
		//printf("s: %u k: %u c: %u\n", dni->start, dni->koniec, dni->cena);
		dni = dni->next;
	}

	printf("%d %d", najnizsza_cena, najnizszy_dzien);

	return 0;
}

void dodaj(struct okres* dni, unsigned int* ceny_poczatkowe){
	static unsigned int id, dzien_poczatkowy, dzien_koncowy, ncena, tmp;

	scanf("%u %u %u %u", &id, &dzien_poczatkowy, &dzien_koncowy, &ncena);

	while (dni->koniec < dzien_poczatkowy) dni = dni->next;

	if(dni->start < dzien_poczatkowy){
		struct okres* nowy = (struct okres*) malloc(sizeof(struct okres));
		nowy->start = dzien_poczatkowy;
		nowy->koniec = dni->koniec;
		dni->koniec = dzien_poczatkowy-1;
		tmp = dni->cena;
		nowy->cena = dni->cena - ceny_poczatkowe[id] + ncena;
		nowy->next = dni->next;
		dni->next = nowy;
		dni = nowy; // dni = dni->next;
	}
	else if (dni->start == dzien_poczatkowy){
		tmp = dni->cena;
		dni->cena = dni->cena - ceny_poczatkowe[id] + ncena;
	}

	while (dni->koniec < dzien_koncowy){
		dni = dni->next;
		tmp = dni->cena;
		dni->cena = dni->cena - ceny_poczatkowe[id] + ncena;
	}
	
	if (dni->koniec == dzien_koncowy)
		;
	else {// (dni->koniec > dzien_koncowy)
		struct okres* nowy = (struct okres*) malloc(sizeof(struct okres));
		nowy->start = dzien_koncowy+1;
		nowy->koniec = dni->koniec;
		dni->koniec = dzien_koncowy;
		nowy->cena = tmp;
		nowy->next = dni->next;
		dni->next = nowy;
	}
}