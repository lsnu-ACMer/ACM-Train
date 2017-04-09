/* ACMer:
 * Date:
 * 题目链接:
 * 题目大意: 读不懂题目，懒的求读
 * 解题思路: 看的网上的解题报告的代码
 *          还是求没有讲题目意思
 *
 */

#include <stdio.h>
#include <math.h>
#include <malloc.h>
#define MAX(a, b) (a > b ? a : b)
int main() {
    int n, w, v, safe = 0, prize = 0;
    char *str = (char *)malloc(sizeof(char) * 7);
    double p, ans = 0, prob = 1, now = 0, win, lose;
    scanf("%d%d", &n, &w);
    while (n--) {
        scanf("%s%lf%d", str, &p, &v);
        prize = v;
        win = prob * p * log(1 + (double)prize / w);
        lose = prob * (1 - p) * log(1 + (double)safe / w);
        ans = MAX(ans, now + win + lose);
        now += lose, prob *= p;
        if (str[0] == 's') {
            safe = prize;    
        }
    }
    printf("$%.2f\n", w * (exp(ans) - 1));
    return 0;
}
