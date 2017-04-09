/* ACMer: royecode
 * Date: 2017-4-2
 * 题目链接: http://codeforces.com/contest/789/problem/C
 * 题目大意：求f(l,r)的最大值，公式如原题所示
 *
 *
 * 解题思路: f(l,r)=f(0,r)-f(0,l),所以可以用O(N)的复杂度求到
 * 所有的f(l,r),最难处理的是(-1)^(i-l)。分两种情况讨论一下
 * (-1)^(i-l)的值，取两次最大就好
 *
 */
//代码部分

#include <iostream>
#include <cmath>
#define MAXN 100007

using namespace std;
typedef long long LL;
LL a[MAXN], sum1[MAXN], sum2[MAXN];

int main()
{
    int n;
    
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    for(int i = 1; i < n; ++i)
    {
        sum1[i] = sum1[i - 1] + abs(a[i + 1] - a[i]) * ((i - 1) &1? -1: 1);
    }
    for(int i = 1; i < n; ++i)
    {
        sum2[i] = sum2[i - 1] + abs(a[i + 1] - a[i]) * ((i - 1) &1? 1:-1);
    }
    LL ans = -1e9, minn = 1e9;
    for(int i = 1; i < n; ++i)
    {
        ans = max(ans, max(sum1[i], sum1[i] - minn));
        minn = min(minn, sum1[i]);
    }
    minn = 1e9;
    for(int i = 1; i < n; ++i)
    {
        ans = max(ans, max(sum2[i], sum2[i] - minn));
        minn = min(minn, sum2[i]);
    }

    cout << ans << endl;
    return 0;
}
