/* ACMer: royecode
 * Date: 2017-04-20
 * 题目链接: http://codeforces.com/contest/274/problem/A
 * 题目大意: 给一个集合有n个数，一个k，需要剔除这个集合中满足如下的数：
 *           y > x 并且 y = x * k
 *
 *
 * 解题思路: 很明显去枚举y然后找x，用一个set维护一下答案，当然需要对
 *           输入的数做个排序
 * 
 *
 */
//代码部分
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    set<int> arr;
    set<int> ans;

    for(int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        arr.insert(val);
    }

    for(set<int>::iterator begin = arr.begin(); begin != arr.end(); ++begin)
    {
        int val = *begin;
        // 枚举y，如果y在答案的集合中则跳过
        if(val % k == 0 && ans.find(val / k) != ans.end())
        {
            continue;
        }
        ans.insert(val);
    }
    
    cout << ans.size() << endl;
    return 0;
}
