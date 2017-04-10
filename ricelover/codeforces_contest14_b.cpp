/**
 *题目大意：
 *    一个摄影师要为跑道上的n名运动员拍照，给定运动员跑步的起始位置ai和结束位置bi，给定摄影师的位置p
 *    摄影师只能站在运动员跑步的范围内才能为该运动员拍照  求摄影师移到一个可以为所有运动员拍照的位置需要多少步  找不到这样一个位置输出-1
 *
 *解题思路：
 *      只需要找到最大的起始位置s和最小的结束位置e 
 *      如果s小于等于e说明可以有满足条件的位置存在  移到这个范围内离自己最近的位置
 *      如果s大于e  输出-1
 *
 *
 */


#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n, p;
    cin >> n >> p;
    int mx, mn;
    int t1, t2;
    for(int i = 0; i < n; i++){
        cin >> t1 >> t2;
        if(i == 0){
            mx = min(t1, t2);
            mn = max(t1, t2);
        }else{
            mx = max(mx, min(t1, t2));
            mn = min(mn, max(t1, t2));
        }
    } 
    if(mx > mn){
       cout << "-1" << endl;
    }else if(p > mx && p < mn){
        cout << 0 << endl;
    }else{
        int res = min(abs(mx - p), abs(mn - p));
        cout << res << endl;
    }
       
    return 0;
}
