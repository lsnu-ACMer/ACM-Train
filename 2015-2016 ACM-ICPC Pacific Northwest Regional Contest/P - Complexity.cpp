#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAXN 101

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int max(int a, int b) {
    return a < b ? b : a;
}

int main() {
    int cnt[26] = {0}, a, res, len;
    char str[MAXN];
    scanf("%s", str);
    for (a = 0, len = strlen(str); a < len; ++a) {
        cnt[str[a] - 'a'] += 1;
    }
    qsort(cnt, 26, sizeof(int), cmp);
    for (a = 0, res = 0; a < 24; ++a) {
        res += cnt[a];
    }
    printf("%d\n", res);
    return 0;
}