/* ACMer: royecode
 * Date: 2017-03-29
 * ��Ŀ����: http://acm.hdu.edu.cn/showproblem.php?pid=1597
 * pastebin: http://pastebin.ubuntu.com/24275016/
 * ��Ŀ���⣺...
 *
 *
 * ����˼·:
 * ��һ����Ԫһ�η��̣�ˮһ��������
 *
 */
//���벿��

#include <iostream>
#include <cmath>
#define LL long long
#define sum(n)  ((n & 1)?( n * (n + 1) / 2): (n / 2 * ( n + 1))) 

using namespace std;

int main()
{
    int k;
    cin >> k;
    while(k--)
    {
        LL n;
        cin >> n;
        //m * (1 + m) / 2 <= n;
        LL m = ceil((sqrt(1+ 8 * n ) -1 ) /2);
        LL ans = n - m * (m - 1) / 2;
        cout << (ans % 9 == 0? 9: ans % 9) << endl;
    }
    return 0;
}
