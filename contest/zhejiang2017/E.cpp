#include <bits/stdc++.h>
#define ll long long
#define MAXN 100000
using namespace std;
int n[MAXN], sd = 78,
    d[16] = {6, 2, 5, 5, 4, 5, 6, 3, 7 , 6, 6, 5, 4, 5, 5, 4};
char m[MAXN][9];


ll char2num(char c) {
    return c >= 'A' ? c - 'A' + 10 : c - '0';
}


ll tail(int n) {
    ll ret = n * (ll)pow(16LL, n - 1) * 78;
    return ret;
}

ll solve(string m, int n) {
    ll ret = 0;
    int len = m.length();
    int p[8] = {0};
    for (int a = 0; a < len; ++a) {
        p[a] = char2num(m[a]);
    }
    for (int a = len - 1, b = 0; a >= 0; --a, ++b) {
        //while (n % (ll)pow(16LL, (ll)b + 1LL)) {
        while (p[a] != 0 && n >= pow(16, b)) {
            ll t1 = 0;
            for (int c = 0; c <= a; ++c) {
                t1 += d[p[c]];
            }
            ll t2 = tail(b);
            ret += t1 * (ll)pow(16LL, b) + t2;
            p[a] += 1;
            n -= (ll)pow(16LL, b);
            //进位
            int c = a;
            while (c >= 0 && p[c] == 16) {
                p[c] = 0;
                c -= 1;
                if (c >= 0) {
                    p[c] += 1;
                }
            }
        }
        if (n < pow(16, b)) {
            for (a = a + 1, b = b - 1; a < len && b >= 0; ++a, --b) {
                while (n >= pow(16, b)) {
                    ll t1 = 0;
                    for (int c = 0; c <= a; ++c) {
                        t1 += d[p[c]];
                    }
                    ll t2 = tail(b);
                    ret += t1 * pow(16, b) + t2;
                    p[a] += 1;
                    n -= pow(16, b);
                    //进位
                    int c = a;
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
    int t;
    scanf("%d", &t);
    for (int a = 0; a < t; ++a) {
        scanf("%d%s", &n[a], m[a]);
    }
    for (int a = 0; a < t; ++a) {
        ll res = solve(m[a], n[a]);
        printf("%lld\n", res);
    }
    return 0;
}
