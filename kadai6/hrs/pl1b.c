#include<stdio.h>
int n, m, temp;
void fact(n, m){
    if (n <= 1){
        temp = 1;
    } else {
        fact(n-1, m);
        temp = temp * n;
    }
}

int main(){
    scanf("%d",&n);
    m = 1;
    fact(n, m);
    printf("%d\n",temp);
    return 0;
}