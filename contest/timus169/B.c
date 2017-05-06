#include <stdio.h>
int main() {
    int n, k, a, b, booms = 0, droids = 0;
    scanf("%d%d", &n, &k);
    droids = n * k;
    for (a = 0; a < n; ++a) {
        scanf("%d", &b);
        booms += b > k ? b - k : 0;
        droids -= b > k ? k : b;
    }
    printf("%d %d\n", booms, droids);
    return 0;
}
