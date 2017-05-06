#include <stdio.h>
#include <malloc.h>
#define MAXN 10
int main() {
    int n, par[MAXN];
    char *op[MAXN];
    int res, a, b, t, flag;
    scanf("%d", &n);
    for (a = 0; a < n; ++a) {
        op[a] = (char *)malloc(sizeof(char) * 10);
        scanf("%s%d", op[a], &par[a]);
    }
    res = 0;
    for (a = 1; a <= 100; ++a) {
        t = a, flag = 0;
        for (b = 0; b < n; ++b) {
            if (!strcmp(op[b], "ADD")) {
                t += par[b];
            }
            if (!strcmp(op[b], "SUBTRACT")) {
                t -= par[b];
                flag |= t < 0;
            }
            if (!strcmp(op[b], "MULTIPLY")) {
                t *= par[b];
            }
            if (!strcmp(op[b], "DIVIDE")) {
                flag |= t % par[b];
                t /= par[b];
            }
        }
        if (flag) {
            res += 1;
        }
    }
    printf("%d\n", res);
    return 0;
}
