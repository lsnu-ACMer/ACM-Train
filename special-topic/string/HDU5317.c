#include <stdio.h>
#define MAXN 200010
#define MIN(a, b) ((a) > (b) ? (b) : (a))

int arr[MAXN], p[MAXN];

int preprocess(int n) {
    int a, b;
    for (a = 0, b = 0; a < n; ++a) {
        p[b++] = -1;
        p[b++] = arr[a];
    }
    p[b++] = -1;
    for (a = 0; a < b; ++a) {
        arr[a] = p[a];
    }
    return b;
}

int manacher(int n) {
    int id = 0, mx = 0, a, b;
    n = preprocess(n);
    for (a = 1; a < n; ++a) {
        if (mx > a) {
            p[a] = MIN(mx - a, p[id * 2 - a]);
        } else {
            p[a] = 1;
        }
        while (arr[a + p[a]] == arr[a - p[a]]) {
            p[a] += 1;
        }
        if (a + p[a] > mx) {
            mx = a + p[a];
            id = a;
        }
    }
    return n;
}

int main() {
    int T, I, n, a, ret;
    scanf("%d", &T);
    for (I = 1; I <= T; ++I) {
        for (a = 0; a < MAXN; ++a) {
            arr[a] = p[a] = -1;
        }
        scanf("%d", &n);
        for (a = 0; a < n; ++a) {
            scanf("%d", arr + a);
        }
        n = manacher(n);
        ret = 0;
        for (a = 0; a < n; ++a) {
            if (arr[a] == -1 && p[a] == a + 1 && p[a + a] >= a + 1) {
                ret = a / 2 * 3;
            }
        }
        printf("Case #%d: %d\n", I, ret);
    }
    return 0;
}
