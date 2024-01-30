#include <iostream>
#include <cstdio>
#include <cmath>

class Kartezjusz{
protected:
    int x;
    int y;
public:
    Kartezjusz(int a, int b): x(a),y(b) {}
    Kartezjusz(Kartezjusz &obiekt) : x(obiekt.x),y(obiekt.y) {}
    Kartezjusz(Kartezjusz &&other) : x(std::move(other.x)), y(std::move(other.y)) {
        other.x = 0;
        other.y = 0;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    void setX(int n){
        x=n;
    }
    void setY(int n){
        y=n;
    }
    friend float distance(Kartezjusz &obiekt1, Kartezjusz &obiekt2);
    friend Kartezjusz * middle(Kartezjusz &obiekt1, Kartezjusz &obiekt2);
    friend void prosta(Kartezjusz &obiekt1, Kartezjusz &obiekt2);
    friend void prostopadle_rownolegle(Kartezjusz &obiekt1, Kartezjusz &obiekt2,Kartezjusz &obiekt3, Kartezjusz &obiekt4);
    ~Kartezjusz(){
        printf("Punkt (%d, %d) Destruktor wykonano pomyslnie!\n",x,y);
    }
};

float distance(Kartezjusz &obiekt1, Kartezjusz &obiekt2){
    float wynik = sqrt(((obiekt2.x-obiekt1.x)*(obiekt2.x-obiekt1.x))+((obiekt2.y-obiekt1.y)*(obiekt2.y-obiekt1.y)));
    return wynik;
}

Kartezjusz * middle(Kartezjusz &obiekt1, Kartezjusz &obiekt2){
    Kartezjusz *S = (Kartezjusz *)malloc(sizeof(Kartezjusz));
    S->x=((obiekt2.x+obiekt1.x)/2);
    S->y=((obiekt2.y+obiekt1.y)/2);
    return S;
}

void prosta(Kartezjusz &obiekt1, Kartezjusz &obiekt2){
    float a = (obiekt2.y-obiekt1.y)/(obiekt2.x-obiekt1.x);
    float b = obiekt1.y-(a*obiekt1.x);
    printf("f(x) = %fx + %f\n",a,b);
}

void prostopadle_rownolegle(Kartezjusz &obiekt1, Kartezjusz &obiekt2,Kartezjusz &obiekt3, Kartezjusz &obiekt4){
    float a1 = (obiekt2.y-obiekt1.y)/(obiekt2.x-obiekt1.x);
    float a2 = (obiekt4.y-obiekt3.y)/(obiekt4.x-obiekt3.x);
    if(a1==a2){
        printf("Proste równolegle\n");
    }
    else if(a1*a2==-1){
        printf("Proste prostopadle\n");
    }
    else{
        printf("proste nie sa prostopadle ani rownolegle");
    }
}

int main()
{
    Kartezjusz Punkt1(1,2);
    Kartezjusz Punkt2(5,10);
    Kartezjusz *S = middle(Punkt1,Punkt2);
    Kartezjusz srodek(*S);
    prosta(Punkt1,Punkt2);
    printf("dlugosc = %f\n",distance(Punkt1,Punkt2));
    printf("Srodek = %d %d\n",S->getX(),S->getY());
    free(S);
    Kartezjusz pierwszy(-1,-1);
    Kartezjusz drugi(-2,-2);
    Kartezjusz trzeci(1,-1);
    Kartezjusz czwarty(2,-2);
    prostopadle_rownolegle(pierwszy,drugi,trzeci,czwarty);
    Kartezjusz Przeniesiony = std::move(Punkt1);
    printf("Przeniesiony = %d %d\nPunkt1 = %d %d\n",Przeniesiony.getX(),Przeniesiony.getY(),Punkt1.getX(),Punkt1.getY());
    return 0;
}
