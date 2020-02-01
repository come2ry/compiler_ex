#include <stdio.h>

int n, m;

void twoprint(int n, int m) {
   printf("%d\n", n);
   printf("%d\n", m);
}

int main() {
   scanf("%d", &n);
   scanf("%d", &m);
   twoprint(n, m);
   return 0;
}