#include <stdio.h>

int cmp(const int *a, const int *b) {
    return *a - *b;
}

int pow_(int a) {
    return a * a;
}

int main() {
    int a[3], b[3];
    scanf("%d%d%d", a + 0, a + 1, a + 2);
    scanf("%d%d%d", b + 0, b + 1, b + 2);
    qsort(a, 3, sizeof(int), cmp);
    qsort(b, 3, sizeof(int), cmp);
    if (pow_(a[0]) + pow_(a[1]) == pow_(a[2]) &&
        a[0] == b[0] && a[1] == b[1] && a[2] == b[2]) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}