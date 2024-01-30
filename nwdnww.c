EUKLIDES:
int NWD(int a, int b){
    int temp;
    if(b>a){
        temp = b;
        b = a;
        a = temp;
    }
    else if(a==b){
        return a;
    }
    while((temp = a%b)!=0){
        a = b;
        b = temp;
    }
    return b;
}

int NWW(int a, int b){
    return(a*b/NWD(a,b));
}


int main()
{
    int a,b;
    printf("podaj a i b:");scanf("%d %d",&a, &b);
    printf("%d\n",NWD(a,b));
    printf("%d\n",NWW(a,b));
    return 0;
}
