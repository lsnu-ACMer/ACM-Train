/*
 *题目大意
 给定n个齿轮的圆心坐标  和半径
 第一个为起始齿轮  最后一个为结束齿轮  问转动第一个 最后一个会不会转动
 如果会  他们转动的比例是多少（如第一个转3圈  最后一个转两圈  比例就是-2:3）
 如果不能转动  是卡死了不能转  还是第一个齿轮的转动不能影响到最后一个

 思路：
 从第一个齿轮开始找和它挨着的  再把和它挨着的加到队列里面   接着去找和队列这些齿轮挨着的
 如果一个齿轮受到来自两个齿轮的影响  并且它们影响的方向不一样  那就卡死了  所有的都动不了  就can not move 
 否则就看最后一个齿轮  它有没有被影响到  如果没有 就无法到达 
 * */





#include<iostream>
#include<queue>
using namespace std;

int d[1007][1007];          //标记两个齿轮的影响关系已被找到过
long long cor[1007][2];     //圆心坐标
long long r[1007];          //半径
int sta[1007];              //每个齿轮转动状态   1：和第一个齿轮同向转动  -1：和第一个齿轮反向转动  0：不动
queue<int> q;

int gcd(int x, int y){
    int z = y;
    while(x % y != 0){
        z = x % y;
        x = y;
        y = z;
    }
    return z;
}

int abs(int x){
    if(x < 0) return -x;
    return x;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> cor[i][0] >> cor[i][1];
        cin >> r[i];
    }
    sta[0] = 1;
    for(int j = 1; j < n; j++){
        d[0][j] = 1;
        if(((cor[j][0] - cor[0][0]) * (cor[j][0] - cor[0][0])) + ((cor[j][1] - cor[0][1]) * (cor[j][1] - cor[0][1])) == ((r[0] + r[j]) * (r[0] + r[j]))){//找出和第一个齿轮挨着的所有齿轮  两圆心的距离一定等于两个齿轮的半径和
             sta[j] = -sta[0];      //两个挨着的（相互受影响的）齿轮一定是顺着相反的方向转动
             q.push(j);               
        }
    }
    int flag = 0;
    while(q.size()){
        int f = q.front();
        q.pop();
        for(int j = 1; j < n; j++){
            if(d[f][j] == 1 || f == j) continue;
            d[f][j] = 1;
            d[j][f] = 1;
            if(((cor[j][0] - cor[f][0]) * (cor[j][0] - cor[f][0])) + ((cor[j][1] - cor[f][1]) * (cor[j][1] - cor[f][1])) == ((r[f] + r[j]) * (r[f] + r[j]))){
                int temp = -sta[f];
                if(sta[j] != 0 && sta[j] != temp){//如果当前齿轮已经受另一齿轮影响将往一个方向转动  而受f齿轮影响将往另一个方向转动  出现卡死  所有齿轮都不能再转动
                    flag = 1;
                    cout << "The input gear cannot move." << endl;
                    break;
                }
                sta[j] = temp;
                q.push(j);               
            }
        }
        if(flag != 0) break;
    }
    if(flag == 0){
        if(sta[n - 1] == 1){   //如果最后一个齿轮的状态值为1  说明和第一个齿轮是朝同一方转动
            int z = gcd(r[n - 1], r[0]);
            cout << abs(r[0] / z) << ":" << r[n - 1] / z << endl;
        }else if(sta[n - 1] == -1){  //如果最后一个齿轮的状态值为-1  说明和第一个齿轮是朝反方向转动
            int z = gcd(r[n - 1], r[0]);
            cout << -abs(r[0] / z )<< ":" << r[n - 1] / z << endl;
        }else{          //状态值依旧为0 说明不会收到影响
            cout << "The input gear is not connected to the output gear." << endl;
        }
    }
    return 0;
}

