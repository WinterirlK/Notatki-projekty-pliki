#include <cstdio>
#include <cstdlib>

struct pole{
    int tab[6][6];
};

struct gen{
    struct pole P;
    struct gen* Next;
};

struct mark{
    int ocena;
    struct pole P;
};

struct mark Ranga_min_max(struct pole P, int aRuch, int NRuch);
struct gen* Generuj(struct pole* P, char Poziom);
struct gen* Insert(struct gen* Lista, struct pole* nowy, int x, int y, char tryb);
struct pole ruch(struct pole P, struct pole N);
char Fpoziom(struct pole P, int aRuch, int NRuch);
int len(struct gen* Lista);
int Ocena(struct pole P);
int wygrana(struct pole P);
void wypisz(struct pole P);

int main(){
    struct pole P;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            P.tab[i][j] = 0;
        }
    }
    wypisz(P);
    int w = wygrana(P);
    int x,y;
    int tmp;
    while (w!=-2){
        start:
            printf("\npodaj ruch (0-35): ");
            scanf("%i",&tmp);
            x = tmp/6;
            y=tmp%6;
            if(P.tab[x][y]!=0){
                goto start;
            }
            P.tab[x][y]=-1;
            w = wygrana(P);
            if(w==-1){
                printf("Gratulacje wygrales!\n");
                wypisz(P);
                exit(0);
            }
            struct mark R = Ranga_min_max(P,0,2);
            P= ruch(P,R.P);
            w = wygrana(P);
            if(w==1){
                printf("Przegrales!\n");
                wypisz(P);
                exit(0);
            }
            wypisz(P);
    }
    printf("Remis\n");
    return 0;
}

struct mark Ranga_min_max(struct pole P, int aRuch, int NRuch){
    struct mark X;
    char Poziom = Fpoziom(P,aRuch, NRuch);
    if(Poziom=='L'){
        X.ocena = Ocena(P);
        X.P = P;
        return X;
    }
    else{
        struct gen* Z=NULL;
        Z = Generuj(&P,Poziom);
        if(Z==NULL){
            printf("Brak mozliwych działan\n");
            exit(0);
        }
        if(Poziom=='G'){
            X.ocena = -1000;
        }
        else{
            X.ocena = 1000;
        }
        int l = len(Z);
        struct mark *TMP = (struct mark*)malloc(l*sizeof(struct mark));
        for(int i = 0;i<l;i++){
            TMP[i] = Ranga_min_max(Z->P,aRuch+1,NRuch);
            Z=Z->Next;
        }
        for (int i = 0; i < l; i++) {
            if (Poziom == 'G') {
                if (TMP[i].ocena > X.ocena) {
                    X = TMP[i];
                }
            } else {
                if (TMP[i].ocena < X.ocena) {
                    X = TMP[i];
                }
            }
        }
        free(TMP);
        return X;
    }
}

int Ocena(struct pole P){
    int score = 0;
    // Sprawdź poziome linie
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j <= 1; j++) {
            int x_count = 0, o_count = 0;
            for (int k = 0; k < 5; k++) {
                if (P.tab[i][j + k] == -1) x_count++;
                if (P.tab[i][j + k] == 1) o_count++;
            }
            if (x_count == 5) return -5;
            if (o_count == 5) return 5;
            if (x_count > 0 && o_count == 0) score -= x_count;
            if (o_count > 0 && x_count == 0) score += o_count;
        }
    }
    // Sprawdź pionowe linie
    for (int j = 0; j < 6; j++) {
        for (int i = 0; i <= 1; i++) {
            int x_count = 0, o_count = 0;
            for (int k = 0; k < 5; k++) {
                if (P.tab[i + k][j] == -1) x_count++;
                if (P.tab[i + k][j] == 1) o_count++;
            }
            if (x_count == 5) return -5;
            if (o_count == 5) return 5;
            if (x_count > 0 && o_count == 0) score -= x_count;
            if (o_count > 0 && x_count == 0) score += o_count;
        }
    }
    if (score > 5) score = 5;
    if (score < -5) score = -5;
    return score;
}

struct pole ruch(struct pole P, struct pole N){
    for(int i =0;i<6;i++){
        for(int j =0;j<6; j++){
            if(P.tab[i][j] != N.tab[i][j]){
                if(N.tab[i][j]==1){
                    P.tab[i][j] = 1;
                    return P;
                }
            }
        }
    }
}

int wygrana(struct pole P){
    int w = 0;
    int r=1;
    for(int i = 0;i<6;i++){
        for(int j = 0;j<6;j++){
            if(P.tab[i][j]==-1){
                if((P.tab[i][0]==-1 && P.tab[i][1]==-1 && P.tab[i][2]==-1 && P.tab[i][3]==-1 && P.tab[i][4]==-1) || (P.tab[i][1]==-1 && P.tab[i][2]==-1 && P.tab[i][3]==-1 && P.tab[i][4]==-1 && P.tab[i][5]==-1) || (P.tab[0][j]==-1 && P.tab[1][j]==-1 && P.tab[2][j]==-1 && P.tab[3][j]==-1 && P.tab[4][j]==-1)||(P.tab[1][j]==-1 && P.tab[2][j]==-1 && P.tab[3][j]==-1 && P.tab[4][j]==-1 && P.tab[5][j]==-1)){
                    return -1;
                }
            }
            else if(P.tab[i][j]==1){
                if((P.tab[i][0]==1 && P.tab[i][1]==1 && P.tab[i][2]==1 && P.tab[i][3]==1 && P.tab[i][4]==1) || (P.tab[i][1]==1 && P.tab[i][2]==1 && P.tab[i][3]==1 && P.tab[i][4]==1 && P.tab[i][5]==1) || (P.tab[0][j]==1 && P.tab[1][j]==1 && P.tab[2][j]==1 && P.tab[3][j]==1 && P.tab[4][j]==1)||(P.tab[1][j]==1 && P.tab[2][j]==1 && P.tab[3][j]==1 && P.tab[4][j]==1 && P.tab[5][j]==1)){
                    return 1;
                }
            }
            if(P.tab[i][j]==0){
                r=0;
            }
        }
    }
    if(r){
        return -2;
    }
    return 0;
}

void wypisz(struct pole P){
    for(int i=0;i<6;i++){
        for(int j = 0;j<6;j++){
            if(P.tab[i][j]==1) printf("o ");
            else if(P.tab[i][j]==-1) printf("x ");
            else printf("w ");
        }
        putchar('\n');
    }
}

struct gen* Generuj(struct pole* P, char Poziom){
    struct gen* p = NULL;
    int i,j;
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            if(P->tab[i][j]==0){
                p= Insert(p,P,i,j,Poziom);
            }
        }
    }
    return p;
}

char Fpoziom(struct pole P, int aRuch, int NRuch){
    if(aRuch==NRuch){
        return 'L';
    }
    else{
        if(aRuch % NRuch){
            return 'P';
        }
        else{
            return 'G';
        }
    }
}

struct gen* Insert(struct gen* Lista, struct pole* nowy, int x, int y, char tryb){
    struct gen* p = (struct gen*)malloc(sizeof(struct gen));
    p->Next=NULL;
    for(int k = 0;k<6;k++){
        for(int m=0;m<6;m++){
            p->P.tab[k][m] = nowy->tab[k][m];
        }
    }
    if(tryb=='G'){
        p->P.tab[x][y]=1;
    }
    else{
        p->P.tab[x][y]=-1;
    }
    if(Lista==NULL){
        Lista=p;
        Lista->Next=NULL;
    }
    else{
        struct gen* tmp = Lista;
        while(tmp->Next!=NULL){
            tmp=tmp->Next;
        }
        tmp->Next=p;
    }
    return Lista;
}

int len(struct gen*Lista){
    int i = 0;
    while (Lista!=NULL){
        ++i;
        Lista=Lista->Next;
    }
    return i;
}
