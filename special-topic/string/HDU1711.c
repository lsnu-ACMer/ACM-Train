#include <stdio.h>
#define MAXN 1000000
#define MAXM 10000

int arr[MAXN], brr[MAXM];
int next[MAXM];

int init(int m) {
    int i = 0, j = -1;
    next[0] = -1;
    while (i < m) {
        if (j == -1 || brr[i] == brr[j]) {
            i += 1;
            j += 1;
            if (brr[i] == brr[j]) {
                next[i] = next[j];
            } else {
                next[i] = j;
            }
        } else {
            j = next[j];
        }
    }
}


int kmp(int n, int m) {
    int i = 0, j = 0;
    init(m);
    while (i < n && j < m) {
        if (j == -1 || arr[i] == brr[j]) {
            i += 1;
            j += 1;
        } else {
            j = next[j];
        }
    }
    if (j == m) {
        return i - m + 1;
    }
    return -1;
}

int main() {
    int T, n, m, a;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (a = 0; a < n; ++a) {
            scanf("%d", arr + a);
        }
        for (a = 0; a < m; ++a) {
            scanf("%d", brr + a);
        }
        printf("%d\n", kmp(n, m));
    }
    return 0;
}
