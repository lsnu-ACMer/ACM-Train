/* ACMer: royecode
 * Date: 2017-03-29
 * 题目链接: http://acm.hdu.edu.cn/showproblem.php?pid=2086  
 * pastebin: http://pastebin.ubuntu.com/24275016/
 * 题目大意：...
 *
 *
 * 解题思路:
 * Ai=(Ai-1+Ai+1)/2 - Ci, 
      A1=(A0  +A2  )/2 - C1;
      A2=(A1  +  A3)/2 - C2 , ...
      A1+A2 = (A0+A2+A1+A3)/2 - (C1+C2)
      A1+A2 =  A0+A3 - 2(C1+C2) 
   同理可得：
      A1+A1 =  A0+A2 - 2(C1) 
      A1+A2 =  A0+A3 - 2(C1+C2)
      A1+A3 =  A0+A4 - 2(C1+C2+C3)
      A1+A4 =  A0+A5 - 2(C1+C2+C3+C4)
      ...
      A1+An = A0+An+1 - 2(C1+C2+...+Cn)
      左右求和
     (n+1)A1+(A2+A3+...+An) = nA0 +(A2+A3+...+An) + An+1 - 2(nC1+(n-1)C2+...+2Cn-1+Cn)
    
     (n+1)A1 = nA0 + An+1 - 2(nC1+(n-1)C2+...+2Cn-1+Cn)

     A1 = [nA0 + An+1 - 2(nC1+(n-1)C2+...+2Cn-1+Cn)]/(n+1)

   注意：用scanf，RT了一把！！  
 *
 */
//代码部分

#include <iostream>
#include<cstdio>  
#include<cmath>  

using namespace std;  
  
double c[5000];  
  
int main()  
{  
    int n;  
    double a,aa;  
    while(cin >> n)  
    {  
        cin >> a >> aa;
        for(int i = 1; i <= n; i++)  
        {  
            scanf("%lf", &c[i]);  
        }  
        double ans = 0;  
        int k = 1;  
        int nn = n;  
        while(n)  
        {  
            ans = ans + n * c[k];  
            n--;   
            k++;  
        }  
  
        ans = (nn * a + aa - 2 * ans) / (nn + 1);  
        printf("%.2lf\n",ans);  
    }  
    return 0;  
}