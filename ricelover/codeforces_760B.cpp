/*
*codeforces
*760B. Frodo and pillows
*暴力  先每个只兔子发一床被子， 然后给自己发，给和自己相邻的发
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double n, m, k;


int main(){
    
    int res = 1;	//先每个人发一个被子
    cin >> n >> m >> k;
    m -= n;
    double l = min(k, n - k + 1);
    double r = max(k, n - k + 1);
    double temp = 1;
    int t = 1;
    while(m - temp >= 0){
        res += 1;
        m -= temp;
        if(t < l){  //如果还没有碰到靠自己近的边界  那么每发一轮都比上一轮多两个
            temp += 2;
        }else if(t < r){  //如果到了离自己近的边界 但还没有到离自己远的边界  那么每发一轮都比上一轮多一个   
            temp += 1;
        }else{			//若两个边界都已找到  那这一轮发的个数和上一轮一样多
            res += floor(m / temp);
            break;
        }
        t++;
    }
    cout << res << endl;
    return 0;
}
