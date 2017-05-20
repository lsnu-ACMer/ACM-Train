/* ACMer: Yick
 * Date: 20170520
 * 题目链接: http://acm.hdu.edu.cn/status.php?user=yick2232&pid=5371
 * 题目大意: 
 *     其它题我都没有写题解，我觉得这题有必要说一下。
 *     给一个数串，找出一个子串，能分成三部分(a)(b)(c)
 *     其中(a)(b)和(b)(c)均是回文
 *     求(a)(b)(c)最长为多少
 *
 * 解题思路:
 *     利用manacher算法可以预处理出关于每个位置(包括相邻两个数中的间隔)为中心，能形成回文串的最远的距离
 *     比如abbba，那么以第2个b为中心回文能扩展到最远的距离是2，也就是往前数两个位置和往后数两个位置
 *     代码中用p数组维护以当前点为中心，能扩展的最远距离
 *     假设(a)(b)的中心是x, (b)(c)的中心是y
 *     如果存在p[x] >= dis(x, y), p[y] >= dis(x, y), 那么一定会存在这样的(a)(b)(c)
 *     我能想到的办法也就是枚举x，然后在(x, x + p[x]]的范围内查找满足条件p[y] >= dis(x, y)的y
 *     反过先枚举y，在枚举x也是一样的
 *     但是这样的时间复杂度是O(n * n)的
 *     然后开始在网上查找题解，居然大部分都是这样解的，只是加了一些简单的剪枝，然后卡过去的
 *     然后我就这样卡过去了
 *     但还是有一些题解中用到了set，不过并没有真正的把时间复杂度降下来，实质还是O(n * n)的
 *     
 *     再讲解一些最后还有一个没有实现的思路，理论上时间复杂度能够降到O(n ^ 1.5)
 *     对于每一个x都会对应着一个区间[x-p[x], x+p[x]]
 *     需要查找到这个区间内满足条件y < x && y + p[y] > x的最小的y
 *     或者查找到这个区间内满足条件y > x && y - p[y] < x的最大的y
 *     左右两边都可以用一个set来维护，然后用莫对算法，接下来......
 *
 */

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
    int T, I, n, a, b, ret;
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
        for (a = 2; a < n; a += 2) {
            for (b = p[a] - 1; b > ret; b -= 2) {
                if (p[a + b] >= b) {
                    ret = b;
                    break;
                }
            }
        }
        ret = ret / 2 * 3;
        printf("Case #%d: %d\n", I, ret);
    }
    return 0;
}
