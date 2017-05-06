#include <stdio.h>
#define MAXN 300000
#define MAXM 2000001

int t[MAXM] = {0},  waves[MAXN][3];

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int max(int a, int b) {
    return a < b ? b : a;
}

int lowbit(int x) {
    return x & (-x);
}

void update(int x, int value) {
    while (x < MAXM) {
        t[x] = max(t[x], value);
        x += lowbit(x);
    }
}

int query(int x) {
    int res = 0;
    while (x > 0) {
        res = max(res, t[x]);
        x -= lowbit(x);
    }
    return res;
}

int main() {
    int n, a, m, f, w;
    scanf("%d", &n);
    for (a = 0; a < n; ++a) {
        scanf("%d%d%d", waves[a] + 0,
            waves[a] + 1, waves[a] + 2);
    }
    qsort(waves, n, sizeof(int) * 3, cmp);
    for (a = 0; a < n; ++a) {
        m = waves[a][0];
        f = waves[a][1];
        w = waves[a][2];
        update(m + w, query(m) + f);    
    }
    printf("%d\n", query(MAXM - 1));
    return 0;
}