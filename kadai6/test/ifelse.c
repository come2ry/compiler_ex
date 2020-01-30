#include <stdio.h>

int x;
int main() {
    scanf("%d", &x);
    if (x == 1) {
        printf("%d\n", x);
    } else {
        printf("not 1\n");
    }

    return 0;
}