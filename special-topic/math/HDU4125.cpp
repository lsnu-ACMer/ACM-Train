#include <iostream>
#include <cstring>
#define MAXN 501

using namespace std;

int gcd(int a, int b)
{
    return (b > 0)? gcd(b, a % b): a;
}

void init(int *ans)
{
    int sume[MAXN], sumf[MAXN];
    memset(sume, 0, sizeof(sume));
    memset(sumf, 0, sizeof(sumf));

    for(int i = 1; i < MAXN; ++i)
    {
        int sum1 = 0, sum2 = 0;
        for(int j = 1; j <= i; ++j)
        {
            if(gcd(i, j) == 1)
            {
                sum1 += 1;
            }
            if(i % j == 0)
            {
                sum2 += 1;
            }
        }
        sume[i] += sume[i - 1] + sum1;
        sumf[i] += sumf[i - 1] + sum2;

        //cout << sume[i] << " " << sumf[i] << endl;
    }

    for(int i = 0; i < MAXN; ++i) ans[i] = 0;
    for(int i = 1; i < MAXN; ++i)
    {
        for(int j = i; j < MAXN; ++j)
        {
            int sum1 = sume[j] - sume[i - 1];
            int sum2 = sumf[j] - sumf[i - 1];
            if(sum1 == sum2)
            {
                ans[j] += 1;
            }
        }

        ans[i] += ans[i - 1];
    }
    //for(int i = 1; i < MAXN; ++i)
    //{
    //    cout << ans[i] << endl;
    //}
}

int main()
{
    int ans[MAXN];
    init(ans);

    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i)
    {
        int N;
        cin >> N;

        cout << "Case " << i << ": ";
        if(N < MAXN)
        {
            cout << ans[N] << endl;;
        } 
        else
        {
            cout << 10 << endl;
        }
    }
    return 0;
}
