#include <stdio.h>
double res[2000];
double min(double a, double b) {
    return a > b ? b : a;
}
int cmp(const double *a, const double *b) {
    return *a > *b ? 1 : -1;
}
double abs_(double a) {
    return a > 0 ? a : -1 * a;
}
int main() {
    int T, k, a, c = 0;
    double d, va, vb, t, dis;
    scanf("%d", &T);
    while (T--) {
        scanf("%lf%lf%lf%d", &d, &va, &vb, &k);
        for (a = 1, c = 0; a <= k; ++a) {
            // 枚举相遇时 相向而行 和 同向而行 的两种情况
            res[c++] = (2 * a - 1) * d / (va + vb);
            if (va != vb) {
                res[c++] = (2 * a - 1) * d / abs_(va - vb);
            }
        }
        qsort(res, c, sizeof(double), cmp);
        t = res[k - 1];
        dis = t * va - ((int)((t * va) / d)) * d;
        dis = min(dis, d - dis);
        printf("Time=%.3lf Dist=%.3lf\n", t, dis);
    }
    return 0;
}
