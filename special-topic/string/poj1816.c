/* ACMer: Yick
 * Date: 20170520
 * 题目链接: http://poj.org/problem?id=1816
 * 题目大意：题意比较简单，花一分钟读题吧
 *
 * 解题思路:
 *     一看数据范围，感觉可以直接爆，然后就写了
 *     AC完了搜题解，很多人是利用模式串建立字典树
 *     思路挺好的，当模式串的量再大一些，建立字典树是比一个比较不错的方法
 *     如果写暴力求解，只是考察了一下代码能力
 *
 */


#include <stdio.h>
#include <string.h>
#define MAXN 100000
char ps[MAXN][8], word[22];
int answers[MAXN + 1];

int match(int idx, int idxp, int idxs) {
    int a = idxp, b = idxs, ret = 0;
    while (a <= ps[idx][0] && b <= word[0]) {
        if (ps[idx][a] == '*') {
            while (b <= word[0]) {
                ret |= match(idx, a + 1, b);
                b += 1;
            }
            ret |= match(idx, a + 1, b);
            return ret;
        } else if (ps[idx][a] == word[b] || ps[idx][a] == '?') {
            a += 1, b += 1;
        } else {
            return 0;
        }
    }
    while (a <= ps[idx][0] && ps[idx][a] == '*') {
        a += 1;
    }
    return ret | (a == ps[idx][0] + 1 && b == word[0] + 1);
}

int main() {
    int N, M, a, b, len;
    scanf("%d%d", &N, &M);
    for (a = 0; a < N; ++a) {
        scanf("%s", ps[a]);
        len = strlen(ps[a]);
        for (b = len; b > 0; --b) {
            ps[a][b] = ps[a][b - 1];
        }
        ps[a][0] = len;
    }
    for (a = 0; a < M; ++a) {
        scanf("%s", word + 1);
        word[0] = strlen(word + 1);
        answers[0] = 0;
        for (b = 0; b < N; ++b) {
            if (match(b, 1, 1)) {
                answers[++answers[0]] = b;
            }
        }
        if (!answers[0]) {
            printf("Not match\n");
            continue;
        }
        for (b = 1; b <= answers[0]; ++b) {
            printf("%d", answers[b]);
            putchar(b == answers[0] ? '\n' : ' ');
        }
    }
    return 0;
}
