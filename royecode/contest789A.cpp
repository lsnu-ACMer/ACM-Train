/* ACMer: royecode
 * Date: 2017-4-2
 * ��Ŀ����: http://codeforces.com/contest/789/problem/A
 * ��Ŀ���⣺Anastasia�������ڴ���ÿ���ڴ�һ�������װk����
 * ��ʯ������һ���ڴ�ֻ��װ��ͬ���͵Ķ���ʯ��
 * ��n�����͵Ķ���ʯ��ÿ�ֶ���ʯ��Wi��������Ҫ�����죬�ܽ�
 * ���еĶ���ʯ����
 *
 * ����˼·: ֱ�ӿ�һ�ֶ���ʯ��Ҫ���ٸ��ڴ�װ�꣬��Ҫ����ȡ��
 *   
 *
 */
// ���벿��

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

    // �����ڴ�����Ĵ𰸣�����ȡ��
    cout << (ans + 1) / 2 << endl;
    return 0;
}
