#include <stdio.h>

void get_other_point(int *a, int *b, int *c, int *d) {
    double midpoint[2];
    midpoint[0] = (a[0] + b[0]) * 1.0 / 2;
    midpoint[1] = (a[1] + b[1]) * 1.0 / 2;
    d[0] = 2 * midpoint[0] - c[0];
    d[1] = 2 * midpoint[1] - c[1];
    return;
}

int main() {
    int a[2], b[2], c[2], d[2];
    scanf("%d%d", a, a + 1);
    scanf("%d%d", b, b + 1);
    scanf("%d%d", c, c + 1);

    printf("3\n");
    get_other_point(a, b, c, d);
    printf("%d %d\n", d[0], d[1]);
    get_other_point(a, c, b, d);
    printf("%d %d\n", d[0], d[1]);
    get_other_point(b, c, a, d);
    printf("%d %d\n", d[0], d[1]);
    return 0;    
}
