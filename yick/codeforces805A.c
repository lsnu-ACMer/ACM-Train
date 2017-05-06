#include <stdio.h>
int main() {
    int l, r, res, mx = 0, t, a;
    scanf("%d%d", &l, &r);
    res = l
    for (a = 2; a * a <= r; ++a) {
        t = r / a - l / a;
        if (mx < t) {
            res = a;
            mx = t;
        }
    }
    printf("%d\n", res);
    return 0;
}
