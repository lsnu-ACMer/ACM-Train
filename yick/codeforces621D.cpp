/* ACMer: yick
 * Date: 20170329
 * 题目链接: http://codeforces.com/contest/621/problem/D
 * 题目大意：输入x, y, z
 *           比较x^y^z, x^z^y, (x^y)^z, (x^z)^y,
 *               y^x^z, y^z^x, (y^x)^z, (y^z)^x,
 *               z^x^y, z^y^x, (z^x)^y, (z^y)^x
 *           的大小，并输出对应的字符串
 *
 * 解题思路: 计算200^200^200的值太大了，
 *           计算200^200在C/C++中可以用long double存储
 *           f(x) = log(x), f'(x) = 1 / x
 *           当x为正实数时，log(x)单调递增
 *           x^y^z   ==> log(x^y^z) = log(x)*y^z
 *           (x^y)^z = x^(y*z) ==> log(x^(y*z)) = log(x)*y*z
 *           注意：GCC 4.8用powl计算long double
 *                 g++ pow对long double做了重载
 */
#include <bits/stdc++.h>
#define eps 1e-10
using namespace std;

int main() {
    long double x, y, z;
    cin >> x >> y >> z;
    long double mx = log(x) * pow(y, z), tmp;
    string res = "x^y^z";
    
    tmp = log(x) * pow(z, y);
    if (tmp - mx > eps) {
        mx = tmp, res = "x^z^y";
    }

    tmp = log(x) * y * z;
    if (tmp - mx > eps) {
        mx = tmp, res = "(x^y)^z";
    }

    tmp = log(y) * pow(x, z);
    if (tmp - mx > eps) {
        mx = tmp, res = "y^x^z";
    }

    tmp = log(y) * pow(z, x);
    if (tmp - mx > eps) {
        mx = tmp, res = "y^z^x";
    }

    tmp = log(y) * x * z;
    if (tmp - mx > eps) {
        mx = tmp, res = "(y^x)^z";
    }

    tmp = log(z) * pow(x, y);
    if (tmp - mx > eps) {
        mx = tmp, res = "z^x^y";
    }

    tmp = log(z) * pow(y, x);
    if (tmp - mx > eps) {
        mx = tmp, res = "z^y^x";
    }

    tmp = log(z) * x * y;
    if (tmp - mx > eps) {
        mx = tmp, res = "(z^x)^y";
    }

    cout << res << endl;
    return 0;    
}
