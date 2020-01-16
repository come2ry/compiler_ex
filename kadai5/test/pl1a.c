#include <stdio.h>
#include <stdlib.h>

int n, temp;

void fact(n){
	if (n <= 1) {
		temp = 1;
		temp = temp * 2;
	}
	else
	{
		fact(n-1);
		temp = temp * n;
	}
}

void main() {
	scanf("%d", &n);
	fact(n);
	printf("%d\n", temp);
}
