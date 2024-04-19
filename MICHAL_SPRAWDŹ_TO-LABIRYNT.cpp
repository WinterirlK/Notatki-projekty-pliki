//LABIRYNT
#include <cstdio>
#include <iostream>
#define N 10

int * Set_Generator(int ** Array, int x, int y, char direction){
    int *Set = (int *)malloc(16);
    int l = 0;
    if(x == 0 && y == 0){ // lewy górny róg
        if(direction == 'n'){//start
            if(Array[y][x+1]!=-1){
                Set[l] = Array[y][x+1];
                ++l;
            }//if
            if(Array[y+1][x]!=-1){
                Set[l] = Array[y+1][x];
                ++l;
            }//if
        }//if
        else if(direction == 't'){
            if(Array[y][x+1]!=-1){
                Set[l] = Array[y][x+1];
                ++l;
            }//if
        }//else if
        else if(direction == 'l'){
            if(Array[y+1][x]!=-1){
                Set[l] = Array[y+1][x];
                ++l;
            }//if
        }//else if
        if(l==0){
           Set[l] = -1;
        }//if
        return Set;
    }//if
    else if(y==0 && x<N-1){//góra ale nie róg
        if(direction == 'n'){//start
            if(Array[y][x+1]!=-1){
                Set[l] = Array[y][x+1];
                ++l;
            }//if
            if(Array[y+1][x]!=-1){
                Set[l] = Array[y+1][x];
                ++l;
            }//if
            if(Array[y][x-1]!=-1){
                Set[l] = Array[y][x-1];
                ++l;
            }//if
        }//if
        else if(direction == 'r'){
            if(Array[y][x+1]!=-1){
                Set[l] = Array[y][x+1];
                ++l;
            }//if
            if(Array[y+1][x]!=-1){
                Set[l] = Array[y+1][x];
                ++l;
            }//if

        }//else if
        else if(direction == 't'){
            if(Array[y][x+1]!=-1){
                Set[l] = Array[y][x+1];
                ++l;
            }//if
            if(Array[y][x-1]!=-1){
                Set[l] = Array[y][x-1];
                ++l;
            }//if
        }//else if
        else if(direction == 'l'){
            if(Array[y+1][x]!=-1){
                Set[l] = Array[y+1][x];
                ++l;
            }//if
            if(Array[y][x-1]!=-1){
                Set[l] = Array[y][x-1];
                ++l;
            }//if
        }
        if(l==0){
            Set[l] = -1;
        }//if
        return Set;
    }
    else if(y==0 && x==N-1){//prawy górny róg
        if(direction == 'n'){//start
            if(Array[y][x-1]!=-1){
                Set[l] = Array[y][x-1];
                ++l;
            }//if
            if(Array[y+1][x]!=-1){
                Set[l] = Array[y+1][x];
                ++l;
            }//if
        }//if
        else if(direction == 'r'){
            if(Array[y+1][x]!=-1){
                Set[l] = Array[y+1][x];
                ++l;
            }//if
        }
        else if(direction == 't'){
            if(Array[y][x-1]!=-1){
                Set[l] = Array[y][x-1];
                ++l;
            }//if
        }
        if(l==0){
            Set[l] = -1;
        }//if
        return Set;
    }
    else if(x == N-1 && y<N-1){//prawo ale nie róg
        if(direction == 'n'){//start
            if(Array[y+1][x])//CHUJ
        }
    }
}

int main(){
    //labirynt 10 x 10
    int labirynth[N][N] = {{0,-1,-1,-1,-1,-1,6,7,8,9},{10,-1,12,13,14,-1,16,-1,-1,-1},{20,21,22,-1,24,-1,25,-1,-1,29},{-1,31,-1,-1,34,35,36,37,38,39},{40,41,-1,-1,44,-1,46,-1,-1,-1},{-1,51,-1,-1,54,-1,56,-1,-1,-1},{60,61,-1,-1,64,-1,66,67,68,69},{-1,-1,-1,73,74,75,-1,-1,-1,79},{-1,-1,-1,-1,-1,85,-1,-1,-1,89},{-1,-1,-1,-1,94,95,-1,-1,-1,99}};
    int i,j;
    int start = 0; //początkowe pole robota
    int current = 0; // obecne pole robota
    int end = 99; // wyjście z labiryntu - rozwiązanie
    char direction = 'n'; // kierunek skąd przyszliśmy | poczotkowa wartosc n oznacza ze jestemy na starcie i nigdzie nie szlismy
    int Droga[100]; // kolejność po jakich polach szedł robot
    for(i=0;i<100;i++){
        Droga[i] = 0;
    }//for

    for(i=0;i<10;++i){ // Pokazanie labirytnu
        for(j=0;j<10;j++){
            printf("%d ",labirynth[i][j]);
        }//for j
        putchar('\n');
    }//for i
    printf("Droga:\n"); // Pokazanie drogi
    for(i=0;i<100;i++){
        printf("%d ",Droga[i]);
    }//for

    int k = 0;
    while (k>-1){

    }

    return 0;
}//main
