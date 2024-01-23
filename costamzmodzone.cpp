
#include <cstdbool>
#include <boost/multiprecision/cpp_int.hpp> //dodaj tę linię
#define MOD 1000000007

using namespace boost::multiprecision; //dodaj tę linię
using namespace std;
bool Left_to_right = true;
bool Right_to_left = false;

cpp_int silnia(int n); //zmień typ na cpp_int
int Permutacja(int size, int k);
int zmieszanie(int *A, int size, int k);
int FindMaxMobileElement(int * A, bool * arrow, int size);
void change_arrow(int *A, int zmieniany, bool * arrow, int size);
cpp_int modInverse(cpp_int a, cpp_int mod); //zmień typ na cpp_int

//18446744073709551615
//silnia 65-max
int main() {
    int x,y;
    scanf("%d %d",&x,&y);
    cpp_int result = (Permutacja(x,y) * modInverse(silnia(x), MOD)) % MOD; //zmień typ na cpp_int
    cout<< result.str().c_str();
    
}

cpp_int silnia(int n){ //zmień typ na cpp_int
     // Jeśli n jest 0 lub 1, zwróć 1
    if (n == 0 || n == 1)
        return 1;
    
    // W przeciwnym razie, zwróć n * silnia(n-1)
    return n * silnia(n - 1);
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
    if(k==1)ilosc++;
    cpp_int liczba_permutacji = silnia(size)-1; //zmień typ na cpp_int
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
        if(zmieszanie(A,size,k))ilosc++;
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

int zmieszanie(int *A, int size, int k){
    int B[size];
    int temp;
    for(int i = 0;i<size;i++){
        B[i] = A[i];
    }
    for(int i = 0;i<k;i++){
        temp = 1;
        for(int j = 0;j<size;j++){
            B[j] = A[B[j]-1];
        }
        for(int j = 0;j<size;j++){
            if(A[j]!=B[j]){
                temp = 0;
            }
        }
        if(temp && i<k-1){
            return 0;
        }
        else if(temp && i==k-1){
            return 1;
        }
    }
    return 0;
}
//B[i] = A[B[i]-1];
cpp_int modInverse(cpp_int a, cpp_int mod){ //zmień typ na cpp_int
    cpp_int result = 1; //zmień typ na cpp_int
    for (cpp_int exp = mod - 2; exp > 0; exp /= 2) {
        if (exp % 2 == 1){
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
    }
    return result;
}
