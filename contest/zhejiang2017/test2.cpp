#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<map>  
#include<string>  
#include<set>  
#include<cctype>  
using namespace std;  
typedef long long ll;  
const ll mod = (ll)0xffffffff+1;  
int val[16] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 6, 5, 4, 5, 5, 4};  
int a[20];  
ll dp[20][1005];  
  
ll change(char *str)  
{  
    ll tmp = 0;  
    for(int i = 0; i < 8; i++)  
    {  
        if(str[i]>= '0' && str[i] <= '9')  
            tmp = tmp*16+str[i]-'0';  
        else  
            tmp = tmp*16+str[i]-'A'+10;  
    }  
    return tmp;  
}  
  
ll dfs(int pos, ll sum, int limit)  
{  
    if(pos < 0) return sum;  
    if(!limit && dp[pos][sum] != -1) return dp[pos][sum];  
    int up = limit ? a[pos] : 15;  
    ll tmp = 0;  
    for(int i = 0; i <= up; i++)  
        tmp += dfs(pos-1, sum+val[i], limit&&(i==a[pos]));  
    if(!limit) dp[pos][sum] = tmp;  
    return tmp;  
}  
  
ll solve(ll x)  
{  
    int pos = 0;  
    memset(a, 0, sizeof(a));  
    while(x)  
    {  
        a[pos++] = x%16;  
        x /= 16;  
    }  
    return dfs(7, 0, 1);//因为前导0也要花费，所以不管怎么样都从第七位开始  
}  
  
int main(void)  
{  
    ll setp;  
    int t;  
    char str[20];  
    memset(dp, -1, sizeof(dp));  
    cin >> t;  
    while(t--)  
    {  
        scanf("%lld %s", &setp, str);  
        setp--;  
        ll l = change(str);  
        ll bei = setp/mod;  //一开始做以为n会很大，还处理了n是0xFFFFFFFF的倍数的情况，其实不需要。  
        setp = setp%mod;  
        if(l+setp >= mod)  
        {  
            ll r = (l+setp)%mod;  
            printf("%lld\n", (bei+1)*solve((ll)0xffffffff)-(solve(l-1)-solve(r)));  
        }  
        else  
        {  
            ll r = l+setp;  
            printf("%lld\n", bei*solve((ll)0xffffffff)+solve(r)-solve(l-1));  
        }  
    }  
    return 0;  
}  
