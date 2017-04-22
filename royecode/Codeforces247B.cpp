/* ACMer: royecode
 * Date: 2017-04-20
 * ��Ŀ����: http://codeforces.com/contest/274/problem/B
 * ��Ŀ����: n���ڵ������n - 1���ߣ�ÿ���ڵ��и�ֵv
 *           ÿ������Զ�һ���������������������1����ڵ㣩��ÿ���ڵ��1���1
 *           �����ٵĲ�����ʹ����������нڵ�ֵΪ0
 *
 *
 * ����˼·: ������dfs�������ά��һ����1�ͼ�1���飬����
 *           
 * PS: �������˺ܾã����������ַ�������ģ�Wrong�˺ܶ��
 *     ֮���˱��˵Ĵ���ſ����ˣ�����������
 *
 */
//���벿��
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
