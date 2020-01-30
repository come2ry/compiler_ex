#include <stdio.h>
int n, sum;
void sum_add(n){
    sum += n;
}

void result(){
    printf("%d",sum);
}

int main(){
    n = 10;
    sum = 0;
    while ( n > 0)
    {
        sum_add(n);
        n --;
    }
    result();
    return 0;
}