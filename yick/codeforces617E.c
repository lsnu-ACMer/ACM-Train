/* ACMer: yick
 * Date: 20170331
 * 题目链接: http://codeforces.com/contest/617/problem/E
 *
 * 题目大意：给出n个数，m次询问,每次询问包含一个l和r,
 *          对于每次询问需要算出区间[l,r]有多少个子区间的异或和等于k。
 *
 * 解题思路: 先考虑暴力求解的时间复杂度，O(m * n),
 *          但1 ≤ n, m ≤ 100000, 0 ≤ k ≤ 1000000。
 *          由于原序列是一个静态序列,
 *          我们可以考虑用离线查询的方式来处理。
 *          如果能将[l, r]的结果经过O(1)的时间复杂度,
 *          转移得到[l-1, r], [l+1, r], [l, r-1], [l, r+1]的结果,
 *          那么我们就能用莫队算法在O((n+m)*sqrt(n))的时间复杂度下解决所有的询问。
 *          对于[l, r]的结果怎么O(1)的转移到相邻的四个区间，
 *          采用前缀异或和，xor[l,r] = pre[r] ^ pre[r-1],
 *          区间转移时pre[r+1] ^ xor[i,r] == k, l <= i <= r,
 *          ========> x[i,r] == k ^ pre[r+1],
 *          所以，只需要知道区间内有多少个区间[i,r],使得xor[i,r] == k ^ pre[r+1]，
 *          即可从区间[l,r]转移到[l,r+1],
 *          同理可以转移到区间[l-1,r],[l+1,r],[l,r-1]。
 *
 *
 */
#include <stdio.h>
#include <math.h>
#define MAXN 1<<20
typedef struct {
    int id;
    int l, r;
    int block_id;
}Node;

int count[MAXN] = {0}, pre_xor[MAXN] = {0};
long long answers[MAXN];
Node queries[MAXN];

int cmp(const Node *a, const Node *b) {
    return a->block_id != b->block_id ? a->block_id - b->block_id : a->r - b->r;
}

int main() {
    int n, m, k, block_size,
        L, R, a;
    long long res;
    scanf("%d%d%d", &n, &m, &k);
    block_size = (int)sqrt(n);
    for (a = 1; a <= n; ++a) {
        scanf("%d", pre_xor + a);
        pre_xor[a] = pre_xor[a - 1] ^ pre_xor[a];
    }
    for (a = 0; a < m; ++a) {
        scanf("%d%d", &queries[a].l, &queries[a].r);
        queries[a].block_id = queries[a].l / block_size;
        queries[a].id = a;
    }
    qsort(queries, m, sizeof(Node), cmp);
    L = 1, R = 0, res = 0;
    for (a = 0; a < m; ++a) {
        while (L < queries[a].l - 1) {
            count[pre_xor[L] ^ k] -= 1;
            res -= count[pre_xor[L]];
            L += 1;
        }
        while (L > queries[a].l - 1) {
            L -= 1;
            res += count[pre_xor[L]];
            count[pre_xor[L] ^ k] += 1;
        }
        while (R < queries[a].r) {
            R += 1;
            res += count[pre_xor[R]];
            count[pre_xor[R] ^ k] += 1;
        }
        while (R > queries[a].r) {
            count[pre_xor[R] ^ k] -= 1;
            res -= count[pre_xor[R]];
            R -= 1;
        }
        answers[queries[a].id] = res;
    }
    for (a = 0; a < m; ++a) {
        printf("%lld\n", answers[a]);
    }
    return 0;
}
