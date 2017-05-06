#include <stdio.h>
int main() {
    int n, a;
    scanf("%d", &n);
    for (a = 0; a < n; ++a) {
        if (a % 4 == 0 || a % 4 == 1) {
            putchar('a');
        } else {
            putchar('b');
        }
    }
    putchar('\n');
    return 0;
}
