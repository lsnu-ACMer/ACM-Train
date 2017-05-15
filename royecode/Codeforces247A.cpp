/* ACMer: royecode
 * Date: 2017-04-20
 * ��Ŀ����: http://codeforces.com/contest/274/problem/A
 * ��Ŀ����: ��һ��������n������һ��k����Ҫ�޳�����������������µ�����
 *           y > x ���� y = x * k
 *
 *
 * ����˼·: ������ȥö��yȻ����x����һ��setά��һ�´𰸣���Ȼ��Ҫ��
 *           ���������������
 * 
 *
 */
//���벿��
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
        // ö��y�����y�ڴ𰸵ļ�����������
        if(val % k == 0 && ans.find(val / k) != ans.end())
        {
            continue;
        }
        ans.insert(val);
    }
    
    cout << ans.size() << endl;
    return 0;
}
