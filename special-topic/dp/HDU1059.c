#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define INF 1000000007
#define MAXN 120000
int package[MAXN], dp[MAXN];
int main() {
    int n[7], s, a, b, c, CASE = 0;
    while (++CASE) {
        s = 0, c = 0;
        for (a = 1; a <= 6; ++a) {
            scanf("%d", n + a);
            s += a * n[a];
            //按照定理将n[a]转换成1,2,4,...,2^k,n[a]+1-2^(k+1)的形式
            for (b = 1; b <= n[a]; b <<= 1) {
                package[c++] = a * b;
                n[a] -= b;
            }
            if (n[a] > 0) {
                package[c++] = n[a] * a;
            }
        }
        if (!s) {
            break;
        }
        //背包必须装满的初始化
        for (dp[0] = 0, a = 1; a < MAXN; ++a) {
            dp[a] = -1 * INF;
        }
        //01背包,从后往前计算,避免先计算的结果影响后计算的结果
        for (a = 0; a < c; ++a) {
            for (b = s / 2; b >= package[a]; --b) {
                dp[b] = MAX(dp[b], dp[b - package[a]] + package[a]);
            }
        }
        printf("Collection #%d:\n%s\n\n", CASE,
            (dp[s/2] == s - s/2 ? "Can be divided." : "Can't be divided."));
    }
            
    return 0;
}
