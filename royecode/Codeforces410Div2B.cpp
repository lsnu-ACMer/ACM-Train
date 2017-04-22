/* ACMer: royecode
 * Date: 2017-04-22
 * 题目链接: http://codeforces.com/contest/798/problem/B
 * 题目大意: n个等大小的字符串，定义移动一步：将首字符移动
 *           末尾，用最小的移动将n个字符串变成一样的，若不
 *           完成输出-1
 *
 *
 * 解题思路: 由于字符串的大小不超过50，所以可以直接暴力模拟
 *           时间复杂度O(n^3) 
 *
 */
//代码部分
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iterator>

#define MAXN 100007

using namespace std;

bool transform(string gold, string src, int &num)
{
    while(gold != src && num < gold.length())
    {
        src = src.substr(1, src.length() - 1) + src[0];
        num += 1;
    }

    if(num == gold.length())
    {
        return false;
    }
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> st;
    
    for(int i = 0; i < n; ++i)
    {
        string temp;
        cin >> temp;
        st.push_back(temp);
    }

    int ans = 10000007;
    for(int i = 0; i < n; ++i)
    {
        string gold = st[i];
        int count = 0;
        for(int i = 0; i < n; ++i)
        {
            int num = 0;
            if(!transform(gold, st[i], num))
            {
                cout << -1 << endl;
                return 0;
            }

            count += num;
        }

        ans = min(ans, count);
    }

    cout << ans << endl;
    return 0;
}
