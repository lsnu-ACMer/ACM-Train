/* ACMer: royecode
 * Date: 2017-4-2
 * 题目链接: http://codeforces.com/contest/789/problem/A
 * 题目大意：Anastasia有两个口袋，每个口袋一天最多能装k个鹅
 * 卵石，并且一个口袋只能装相同类型的鹅卵石，
 * 有n个类型的鹅卵石，每种鹅卵石有Wi个，问需要多少天，能将
 * 所有的鹅卵石捡完
 *
 * 解题思路: 直接看一种鹅卵石需要多少个口袋装完，需要向上取整
 *   
 *
 */
// 代码部分

#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ans += (x + k - 1) / k;
    }

    // 两个口袋所捡的答案，向上取整
    cout << (ans + 1) / 2 << endl;
    return 0;
}
