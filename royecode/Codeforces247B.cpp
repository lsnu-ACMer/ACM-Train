/* ACMer: royecode
 * Date: 2017-04-20
 * 题目链接: http://codeforces.com/contest/274/problem/B
 * 题目大意: n个节点的树，n - 1条边，每个节点有个值v
 *           每次你可以对一个子树（此子树必须包含1这个节点）的每个节点加1或减1
 *           用最少的步数，使这棵树的所有节点值为0
 *
 *
 * 解题思路: 可以用dfs来解决，维护一个加1和减1数组，即可
 *           
 * PS: 当初想了很久，不是用这种方法解决的，Wrong了很多次
 *     之后看了别人的代码才看懂了！！啊啊！！
 *
 */
//代码部分
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const int N = 100007;

int v[N];
vector<int> g[N];

pll dfs(int u, int p)
{
    ll inc = 0, dec = 0;
    for(int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i];
        if (v == p) continue;

        pll sub = dfs(v,u);
        inc = max(inc, sub.first);
        dec = max(dec, sub.second);
    }

    v[u] += inc - dec;
    if(v[u] > 0) dec += v[u];
    else inc += -v[u];
    
    return {inc, dec};
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; ++i) 
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
    }

    pll ret = dfs(1, -1);

    cout << ret.first + ret.second << endl;
    return 0;
}
