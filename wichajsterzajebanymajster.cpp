#include <cstdio>
#include <cstdbool>
#define MOD 1000000007


bool Left_to_right = true;
bool Right_to_left = false;

unsigned long long int silnia(int n);
int Permutacja(int size, int k);
int zmieszanie(int *A, int size);
int FindMaxMobileElement(int * A, bool * arrow, int size);
void change_arrow(int *A, int zmieniany, bool * arrow, int size);
long long modInverse(long long a, long long mod);

//18446744073709551615
//silnia 65-max
int main() {
    int x,y;
    scanf("%d %d",&x,&y);
    long long result = (Permutacja(x,y) * modInverse(silnia(x), MOD)) % MOD;
    printf("%lld", result);
}

unsigned long long int silnia(int n){
    if(n<3){
        return n;
    }
    else{
        unsigned long long int wynik = n;
        for(unsigned long long int i = 2;i<n;i++){
            wynik *= i;
        }
        return wynik;
    }
}
//rl false
//lr true
int Permutacja(int size, int k){
    int A[size];
    bool arrow[size];
    int ilosc = 0;
    for(int i = 1; i<=size; i++){
        A[i-1]=i;
        arrow[i-1] = Right_to_left;
    }
    if(k==zmieszanie(A,size))ilosc++;
    unsigned long long int liczba_permutacji = silnia(size)-1;
    int tmp1, tmp2;
    bool tmp3;
    int zmieniany;
    for (int i = 0; i < liczba_permutacji; i++) {
        tmp1 = FindMaxMobileElement(A,arrow,size);
        zmieniany = A[tmp1];
        if(arrow[tmp1]){
            tmp2 = A[tmp1+1];
            A[tmp1+1] = A[tmp1];
            A[tmp1] = tmp2;
            tmp3 = arrow[tmp1+1];
            arrow[tmp1+1] = arrow[tmp1];
            arrow[tmp1] = tmp3;
        }
        else{
            tmp2 = A[tmp1-1];
            A[tmp1-1] = A[tmp1];
            A[tmp1] = tmp2;
            tmp3 = arrow[tmp1-1];
            arrow[tmp1-1] = arrow[tmp1];
            arrow[tmp1] = tmp3;
        }
        change_arrow(A,zmieniany,arrow,size);
        if(k==zmieszanie(A,size))ilosc++;
    }


    return ilosc;
}

void change_arrow(int *A, int zmieniany, bool * arrow, int size){
    for(int i =0;i<size;i++){
        if(zmieniany<A[i]){
            if(arrow[i])arrow[i]= false;
            else arrow[i] = true;
        }
    }
}

int FindMaxMobileElement(int * A, bool * arrow, int size){
    int id = 0;
    int najwiekszy = 0;
    for(int i = 0;i<size;i++){
        if(arrow[i]){
            if(i<size-1 && A[i]>A[i+1]){
              if(A[i]>najwiekszy){
                  najwiekszy = A[i];
                  id = i;
              }
            }
        }
        else{
            if(i>0 && A[i]>A[i-1]){
                if(A[i]>najwiekszy){
                    najwiekszy = A[i];
                    id = i;
                }
            }
        }
    }
    return id;
}

int zmieszanie(int *A, int size){
    int k=1;
    int B[size];
    for(int i = 0;i<size;i++){
        B[i] = A[i];
    }
    etykieta:
        for(int i = 0;i<size;i++){
            B[i] = A[B[i]-1];
        }
    for(int i =0;i<size;i++){
        if(A[i] != B[i]){
            k++;
            goto etykieta;
        }
    }
    return k;
}

long long modInverse(long long a, long long mod){
    long long result = 1;
    for (int exp = mod - 2; exp > 0; exp /= 2) {
        if (exp % 2 == 1){
            result = (result * a) % mod;
        }
    a = (a * a) % mod;
    }
    return result;
}
