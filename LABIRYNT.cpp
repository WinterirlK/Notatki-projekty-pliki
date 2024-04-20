#include <cstdio>
#include <iostream>
#define N 10
#define True 1

char Where(int labirynth[N+2][N+2], int x, int y, char direction){//zwraca w którą stronę należy się udać
    if(direction=='n'){//startowe pole
        if(labirynth[y-1][x]!=-1){//góra
            direction = 't';
        }//if
        else if(labirynth[y][x+1]!=-1){//prawo
            direction = 'r';
        }//else if
        else if(labirynth[y+1][x]!=-1){//dół
            direction = 'b';
        }//else if
        else if(labirynth[y][x-1]!=-1){//lewo
            direction = 'l';
        }//else if
    }//if
    else if(direction == 't'){//góra
        if(labirynth[y][x-1]!=-1){//lewo
            direction = 'l';
        }//if
        else if(labirynth[y-1][x]!=-1){//góra
            direction = 't';
        }//else if
        else if(labirynth[y][x+1]!=-1){//prawo
            direction = 'r';
        }//else if
        else if(labirynth[y+1][x]!=-1){//dół
            direction = 'b';
        }//else if
    }//else if
    else if(direction=='r'){//prawo
        if(labirynth[y-1][x]!=-1){//góra
            direction = 't';
        }//if
        else if(labirynth[y][x+1]!=-1){//prawo
            direction = 'r';
        }//else if
        else if(labirynth[y+1][x]!=-1){//dół
            direction = 'b';
        }//else if
        else if(labirynth[y][x-1]!=-1){//lewo
            direction = 'l';
        }//else if
    }//else if
    else if(direction =='b'){//dół
        if(labirynth[y][x+1]!=-1){//prawo
            direction = 'r';
        }//if
        else if(labirynth[y+1][x]!=-1){//dół
            direction = 'b';
        }//else if
        else if(labirynth[y][x-1]!=-1){//lewo
            direction = 'l';
        }//else if
        else if(labirynth[y-1][x]!=-1){//góra
            direction = 't';
        }//else if
    }
    else if(direction == 'l'){//lewo
        if(labirynth[y+1][x]!=-1){//dół
            direction = 'b';
        }//if
        else if(labirynth[y][x-1]!=-1){//lewo
            direction = 'l';
        }//else if
        else if(labirynth[y-1][x]!=-1){//góra
            direction = 't';
        }//else if
        else if(labirynth[y][x+1]!=-1){//prawo
            direction = 'r';
        }//else if
    }
    return direction;
}//Where

int main(){
    //labirynt 10 x 10 | 12x12 aby zewnetrzne sciany zostaly zrobione
    int labirynth[N+2][N+2] = {{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},{-1,0,-1,-1,-1,-1,-1,6,7,8,9,-1},{-1,10,-1,12,13,14,-1,16,-1,-1,-1,-1},{-1,20,21,22,-1,24,-1,26,-1,-1,29,-1},{-1,-1,31,-1,-1,34,35,36,37,38,39,-1},{-1,40,41,-1,-1,44,-1,46,-1,-1,-1,-1},{-1,-1,51,-1,-1,54,-1,56,-1,-1,-1,-1},{-1,60,61,-1,-1,64,-1,66,67,68,69,-1},{-1,-1,-1,-1,73,74,75,-1,-1,-1,79,-1},{-1,-1,-1,-1,-1,-1,85,-1,-1,-1,89,-1},{-1,-1,-1,-1,-1,94,95,-1,-1,-1,99,-1},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};
    int ile_razy_odwiedzane[N][N]; //ile razy robot odwiedzi dane pole - jesli wiecej niz 4 to oznacza ze nie ma rozwiazania (kreci sie w kółko) np end = 100
    int i,j;
    int startX = 1, startY = 1; //początkowe pole robota
    int x = 1, y = 1; // obecne pole robota
    int end = 99; // wyjście z labiryntu - rozwiązanie
    //int end = 100; // nie ma wyjścia
    char direction = 'n'; // kierunek skąd przyszliśmy | poczotkowa wartosc n oznacza ze jestemy na starcie i nigdzie nie szlismy
    //t = top r = right b = bottom l = left
    int Droga[100]; // kolejność po jakich polach szedł robot
    for(i=0;i<100;i++){
        Droga[i] = -1;
    }//for
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            ile_razy_odwiedzane[i][j]=0;
        }//for j
    }//for i

    for(i=0;i<N+2;++i){ // Pokazanie labirytnu
        for(j=0;j<N+2;j++){
            printf("%d ",labirynth[i][j]);
        }//for j
        putchar('\n');
    }//for i

    i=0;
    Droga[i++] = labirynth[y][x];//zapisanie drogi
    ile_razy_odwiedzane[y-1][x-1]++;
    while (True){//True = 1
        direction = Where(labirynth,x,y,direction);//ustalenie gdzie należy iść
        if(direction == 't')y--;//pojscie w góre
        else if(direction == 'r')x++;//pojscie w prawo
        else if(direction=='b')y++;//pójście w dół
        else if(direction =='l')x--;//pójscie w lewo
        Droga[i++] = labirynth[y][x];//zapisanie drogi
        ile_razy_odwiedzane[y-1][x-1]++;
        if(labirynth[y][x]==end){
            printf("\nZnaleziono Wyjscie!\n");
            break;
        }
        if(ile_razy_odwiedzane[y-1][x-1]>4){
            printf("\n-----Brak rozwiazania-----\n");
            printf("Droga:\n"); // Pokazanie drogi
            for(i=0;i<100;i++){
                printf("%d ",Droga[i]);
            }//for
            return 1;
        }

    }
    printf("Droga:\n"); // Pokazanie drogi
    for(i=0;i<100;i++){
        printf("%d ",Droga[i]);
    }//for
    return 0;
}//main
