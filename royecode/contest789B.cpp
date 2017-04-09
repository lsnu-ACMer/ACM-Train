/* ACMer: royecode
 * Date: 2017-4-2
 * 题目链接: http://codeforces.com/contest/789/problem/A
 * 题目大意：输入b1,q,l,m, 接下来是m个数ai，其中b[i] = b[i-1] * q,
 * 问：有多少个abs(b[i])<=l并且不等于a中的任何一个数，
 * 如果有无限个满足条件的数则输出inf
 *
 *
 * 解题思路: 分类讨论一下
 * (1)|b1| > l,输出inf;
 * (2)b1==0 ,如果m个数中有0， 输出0；没有输出inf；
 * (3)q=0 , 如果0 不在 m个数中，输出inf； 否则 如果b1不在m个数中，输出1；否则输出0；
 * (4)q=1， 如果b1在 已知数中，输出0；否则输出inf；
 * (5)q=-1,如果b[1]和-b[1] 都不在已知数中，输出inf，否则只有一个在输出1，否则输出0；
 * (6)其他情况:依次暴力
 *
 */
//代码部分

#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <cmath>  

#define MAXN 100010
#define LL long long
#define INF 0x3f3f3f  

using namespace std;  

LL b[MAXN], a[MAXN];  

int main()  
{  
    int q, l, m;  

    cin >> b[1]  >> q >> l >> m;  
    for(int i = 0; i <= m; ++i)
    {
        a[i] = INF;
    }
    for(int i = 0; i < m; ++i)  
    {
        cin >> a[i];
    }
    
    sort(a, a + m);  
    
    bool isInf = false;
    int ans = 0;
    if(abs(b[1]) > l)
    {  
        ans = 0; 
    } 
    else if(b[1] == 0 || q == 1)  
    {  
        int pos = lower_bound(a, a + m, b[1]) - a;  
        if(a[pos] == b[1])
        {
            ans = 0;  
        } 
        else
        {
            isInf = true;
        }  
    }  
    else if(q == 0)  
    {  
        int pos1 = lower_bound(a, a + m, 0) - a;  
        int pos2 = lower_bound(a, a + m, b[1]) - a;  
        if(a[pos1] != 0)
        {
            isInf = true;
        }  
        else if(a[pos2] == b[1])  
        {
            ans = 0;
        }
        else  
        {
            ans = 1;
        }  
    }  
    else if(q == -1)  
    {  
        int pos1 = lower_bound(a, a + m, b[1]) - a;  
        int pos2 = lower_bound(a, a + m, -b[1]) -a;  
        if(a[pos1] == b[1] && a[pos2] == -b[1])  
        {
            ans = 0;
        }
        else  
        {
            isInf = true;
        }
    }  
    else
    {  
        int cnt = 0;  
        for(LL i = b[1]; abs(i) <= l; i *= q)  
        {  
            int pos = lower_bound(a, a + m, i) - a;  
            if(a[pos] != i)
            {
                ans ++;  
            }
        }   
    }  
    if(isInf)
    {
        cout << "inf" << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;  
}  
