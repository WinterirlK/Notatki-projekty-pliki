Sito:
int * sito(int n){
    int A = (int)malloc((n+1)*4);
    for(int i = 2;i<=n;i++){
        A[i]= i;
    }
    for(int i = 2;i*i<=n;i++){
        for(int j = 2*i;j<=n;j+=i){
            A[j] = 0;
        }
    }
    return A;
}

int main()
{
    int n;
    printf("podaj zakres: ");scanf("%d",&n);
    int *A = sito(n);
    for(int i = 2;i<=n;i++){
        if(A[i]!=0) printf("%d ",A[i]);
    }
    return 0;
}
