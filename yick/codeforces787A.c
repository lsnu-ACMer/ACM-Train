/* ACMer: yick
 * Date: 20170324
 * 题目链接: http://codeforces.com/problemset/problem/787/A
 * 题目大意：输入a,b,c,d,
 *           Rick尖叫的时刻是b,b+a,b+2a,b+3a,...
 *           Morty尖叫的时刻是d,d+c,d+2c,d+3c,...
 *           求两人同时尖叫的时刻。
 *
 * 解题思路: 数据量不大，直接暴力应该能解
 *           但是很明显，可以用扩展欧几里得来求解。
 *           扩展欧几里得:
 *           ax + by = c
 *           d = gcd(a, b)
 *           if c % d == 0: (x, y)有正整数解
 *           else: (x, y)无正整数解
 *           其中，x, y的步长分别为step_x, step_y
 *           step_x = abs(b / d)
 *           step_y = abs(a / d)
 *
 */

#include <stdio.h>


int ex_gcd(int a, int b, int *x, int *y) {
    int t, d;
    if (b == 0) {
        *x = 1, *y = 0;
        return a;
    }
    d = ex_gcd(b, a % b, x, y);
    t = *x;
    *x = *y;
    *y = t - a / b * *y;
    return d;
}


int main() {
    int a, b, c, d, x, y, dd, m, stepx, stepy;
    scanf("%d%d", &a, &b);
    scanf("%d%d", &c, &d);
    dd = ex_gcd(a, -c, &x, &y);
    if ((d - b) % dd == 0) {
        m = (d - b) / dd;//倍数
        x *= m, y *= m;//还原
        //求出x,y的步长
        stepx = c / dd > 0 ? c / dd : -1 * c / dd;
        stepy = a / dd > 0 ? a / dd : -1 * a / dd;
        x %= stepx, y = (a * x + b - d) / c;//求出当x为非负整数时，y的值
        while (x < 0 || y < 0) {//求出x,y都是非负整数的解
            x += stepx, y += stepy;
        }
        printf("%d\n", x * a + b);
    }
    else {
        printf("-1\n");
    }
    return 0;    
}
