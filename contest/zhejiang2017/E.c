#include <stdio.h>
#define ll long long
#define sd 78
int d[16] = {6, 2, 5, 5, 4, 5, 6, 3, 7 , 6, 6, 5, 4, 5, 5, 4};

ll pow_(ll a, ll b) {
    ll ret = 1;
    while (b > 0) {
        ret *= a;
        b -= 1;
    }
    return ret;
}

ll char2num(char c) {
    return c >= 'A' ? c - 'A' + 10 : c - '0';
}

char num2char(int n) {
    return n >= 10 ? n + 'A' : n + '0';
}

ll tail(int n) {
    ll ret = n * pow_(16, n - 1) * sd;
    return ret;
}

ll solve(int *p, int n) {
    ll ret = 0, t;
    int a, b, c;
    for (a = 7, b = 0; a >= 0; --a, ++b) {
        while (p[a] != 0 && n >= pow_(16, b)) {
            t = 0;
            for (c = 0; c <= a; ++c) {
                t += d[p[c]];
            }
            ret += t * pow_(16, b) + tail(b);
            p[a] += 1;
            n -= pow_(16, b);
            c = a;
            while (c >= 0 && p[c] == 16) {
                p[c] = 0;
                c -= 1;
                if (c >= 0) {
                    p[c] += 1;
                }
            }
        }
        if (n < pow_(16, b)) {
            for (a = a + 1, b = b - 1; a < 8 && b >= 0; ++a, --b) {
                while (n >= pow_(16, b)) {
                    t = 0;
                    for (c = 0; c <= a; ++c) {
                        t += d[p[c]];
                    }
                    ret += t * pow_(16, b) + tail(b);
                    p[a] += 1;
                    n -= pow_(16, b);
                    c = a;
                    while (c >= 0 && p[c] == 16) {
                        p[c] = 0;
                        c -= 1;
                        if (c >= 0) {
                            p[c] += 1;
                        }
                    }
                }
            }
            break;
        }
    }
    return ret;
}

int main() {
    int t, n, p[8], a;
    char m[9];
    scanf("%d", &t);
    while (t--) {
        scanf("%d%s", &n, m);
        for (a = 0; a < 8; ++a) {
            p[a] = char2num(m[a]);
        }
        printf("%lld\n", solve(p, n));
    }
    return 0;
}
