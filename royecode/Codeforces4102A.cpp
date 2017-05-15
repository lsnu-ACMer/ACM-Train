/* ACMer: royecode
 * Date: 2017-04-22
 * 题目链接: http://codeforces.com/contest/798/problem/A
 * 题目大意: 问字符串s，能否仅仅改变一个字符，使s为回文
 *           能则YES，否则NO
 *
 *
 * 解题思路: 令cnt为：使s为回文的最小改变次数
 *           有两种情况为YES，cnt为1，或cnt等于0并且s的大小
 *           为奇数。
 *           当初考虑不完全把，Wrong了2次，尴尬！
 * 
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

int main()
{
    std::ios_base::sync_with_stdio(false);
    string st;
    cin >> st;
    int times = 0;
    for(int i = 0; i < st.length() / 2; ++i)
    {
        if(st[i] != st[st.length() - 1 - i])
        {
            times += 1;
        }
    }
    if(times == 1 || (times == 0 && st.length() % 2 == 1))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
