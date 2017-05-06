#include <stdio.h>
#define MAXN 1000000

int v[2][MAXN];

int main() {
    int L, T, Va, Vb, n, w, t, d,
        a, b, res = 0;
    scanf("%d%d%d%d", &L, &T, &Va, &Vb);
    scanf("%d", &n);
    for (a = 0; a <= T; ++a) {
        v[0][a] = Va, v[1][a] = Vb;
    }
    for (a = 0; a < n; ++a) {
        scanf("%d%d%d", &w, &t, &d);
        for (b = 0; b < d; ++b) {
            v[w - 1][t + b] = 0;
        }
    }
    for (a = 0; a < T; ++a) {
        res += v[0][a] + v[1][a];
    }
    printf("%d\n", res / L);
    return 0; 
}
