/*
*题目大意：
*	给定四天线段  判断四条线段是否能组成一个平行于坐标轴的矩形
*解题思路：
*	四个判断点
*		是否只有四个点
*		是否每个点出现过两次
*		是否每条线段要不横坐标相同 要么纵坐标相同
*		是否横坐标相同的线段正好两条  纵坐标相同的线段也正好两条
*
*/

#include<iostream>
using namespace std;
typedef pair<pair<int, int>, int>P;

P c[17];

int main(){
    int cx = 0;
    int cy = 0;
    int flag = 0;
    int t = 0;
    for(int i = 0; i < 4; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int flag1 = 0;
        int flag2 = 0;
        if(t == 0){
            c[t].first.first = x1;
            c[t].first.second = y1;
            c[t++].second = 1;
            c[t].first.first = x2;
            c[t].first.second = y2;
            c[t++].second = 1;
        }else{
            for(int j = 0; j < t; j++){
                if(x1 == c[j].first.first && y1 == c[j].first.second){
                    c[j].second += 1;
                    flag1 = 1;
                }
                if(x2 == c[j].first.first && y2 == c[j].first.second){
                    c[j].second += 1;
                    flag2 = 1;
                    if(flag1 == 1){
                        break;
                    }
                }
            }
            if(flag1 == 0){
                c[t].first.first = x1;
                c[t].first.second = y1;
                c[t++].second = 1;
            }
            if(flag2 == 0){
                c[t].first.first = x2;
                c[t].first.second = y2;
                c[t++].second = 1;
            }
        }

        if(x1 == x2){
            cx += 1;
        }else if(y1 == y2){
            cy += 1;
        }else{
            cout << "NO" << endl;
            flag = 1;
            break;
        }
    }
    if(flag != 1){
        if(t != 4  || cx != 2 || cy != 2){
            cout << "NO" << endl;
        }else{
            for(int i = 0; i < 4; i++){
                if(c[i].second != 2){
                    cout << "NO" << endl;
                    flag = 1;
                    break;
                }
            }
            if(flag != 1){
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}