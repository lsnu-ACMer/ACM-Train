#include <stdio.h>
#define ll long long
#define MAXP 100001

ll fact[MAXP];

ll _pow(ll a, ll b, ll p) {
    ll ret = 1;
    while (b) {
        if (b & 1) {
            ret = ret * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return ret;
}

void preprocess(p) {
    int a;
    for (a = 1, fact[0] = 1; a <= p; ++a) {
        fact[a] = fact[a - 1] * a % p;
    }
}

ll c(ll n, ll m, ll p) {
    if (m > n) {
        return 0;
    }
    return fact[n] * _pow(fact[m] * fact[n - m] % p, p - 2, p) % p;
}

ll lucas(ll n, ll m, ll p) {
    if (m == 0) {
        return 1;
    }
    return c(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
}

int main() {
    int t, n, m, p;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &m, &p);
        preprocess(p);
        printf("%lld\n", lucas(n + m, m, p));
    }
    return 0;
}
