#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
#define ls i<<1
#define rs ls | 1
#define mid ((ll+rr)>>1)
#define pii pair<int,int>
#define MP make_pair
typedef long long LL;
const long long INF = 1e18+1LL;
const double Pi = acos(-1.0);
const int N = 1e5+10, M = 1e3+20, mod = 1e9+7, inf = 2e9;


LL d[N],dp[60][3],vis[60][3],dp1[60][3];
LL a[] = {6,2,5,5,4,5,6,3,7,6,6,5,4,5,5,4};
int id(char ch) {
    if(ch >= '0' && ch <= '9') return ch - '0';
    else return ch - 'A' + 10;
}
LL quick_pow(LL x,LL p) {
    if(p<=0) return 1;
    LL ans = quick_pow(x,p>>1);
    ans = ans*ans;
    if(p & 1) ans = ans*x;
    return ans;
}
LL dfs(int dep,int f,LL x) {
    if(dep<0) return 0;
    if(f && vis[dep][f]) return dp[dep][f];
    if(f) {
        LL& ret = dp[dep][f];
        vis[dep][f] = 1;
        ret += 78*quick_pow(16,dep) + 1LL*16*dfs(dep-1,f,quick_pow(16,dep));
        return ret;
    }
    else
    {
        LL ret = 0;
        for(int i = 0; i <= d[dep]; ++i) {
            LL tmp;
            if(i < d[dep]) tmp = quick_pow(16,dep);
            else tmp = x%quick_pow(16,dep)+1;
            ret += (tmp)*a[i] + dfs(dep-1,i<d[dep],tmp-1);
        }
        return ret;
    }
}
LL solve(LL x) {
    if(x < 0) return 0;
    int len = 0;
    LL tmp = x;
    for(LL i = 0; i <= 7; ++i) {
        d[len++] = x%16;
        x/=16;
    }
    return dfs(len-1,0,tmp);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        char s[10];
       scanf("%d%s",&n,s);
       int L = strlen(s);
       LL l = 0,tmp = 1;
       for(int i = L-1; i >= 0; --i) {
        l += id(s[i])*tmp;
        tmp*=16;
       }
       LL r = l+n-1,ans = 0;
       if(r > 4294967295) {
        ans = solve(4294967295) - solve(l-1);
        l = 0;
        r = r-4294967295-1;
       }
       printf("%lld\n",ans + solve(r) - solve(l-1));
    }
    return 0;
}

