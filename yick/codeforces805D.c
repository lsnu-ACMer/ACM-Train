#include <stdio.h>
#include <string.h>
#define MAXN 1000000
#define MOD 1000000007
char s[MAXN + 1];
int t[MAXN];
int main() {
    int a, b, len, res = 0;
    scanf("%s", s);
    len = strlen(s), b = 0;
    for (a = len - 1; a >= 0; --a) {
        if (s[a] == 'a') {
            res = (res + b) % MOD;
            b = (b + b) % MOD;
        } else {
            b = (b + 1) % MOD;
        }
    }
    printf("%d\n", res);
    return 0;
}
