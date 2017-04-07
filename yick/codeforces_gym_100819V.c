#include <stdio.h>
#include <math.h>
#define MAXN 1000
typedef struct {
    int x, y, r;
    int dir;//方向
}Gear;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int influence(Gear a, Gear b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    double dis = sqrt(dx * dx + dy * dy);
    return dis == (double)a.r + b.r;
}

int main() {
    int n, a, b, c, ok = 1;
    Gear gears[MAXN];
    scanf("%d", &n);
    for (a = 0; a < n; ++a) {
        scanf("%d%d%d", &gears[a].x, &gears[a].y, &gears[a].r);
        gears[a].dir = -1;
    }
    gears[0].dir = 0;
    for (a = 1; a < n && ok; ++a) {
        for (b = 0; b < a && ok; ++b) {
            if (gears[b].dir != -1 && influence(gears[a], gears[b])) {
                c = gears[b].dir ^ 1;    
                if (gears[a].dir == -1) {
                    gears[a].dir = c;
                } else if (gears[a].dir != c) {
                    ok = 0;    
                }
            }
        }
    }
    if (ok && gears[n - 1].dir != -1) {
        a = gears[0].r, b = gears[n - 1].r;
        c = gcd(a, b);
        a /= c, b /= c;
        if (gears[n - 1].dir != gears[0].dir) {
            a *= -1;
        }
        printf("%d:%d\n", a, b);
    } else if (!ok) {
        puts("The input gear cannot move.");
    } else {
        puts("The input gear is not connected to the output gear.");
    }
    return 0;    
}
