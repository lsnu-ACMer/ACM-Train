
/* ACMer: royecode
 * Date: 2017-03-31
 * 题目链接: http://poj.org/problem?id=2251
 * 题目大意：在一个三维的迷宫里，从S出发到达E点，可行走6个方向，北南东西上下
 *
 *
 * 解题思路:
 *  就是一个bfs嘛，感觉我做了好久，脑子坏死了啊！
 */
//代码部分

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 27007

using namespace std;

int dir[6][3] = {
    0, -1, 0,
    0, 1, 0,
    1, 0, 0, 
    -1, 0, 0,
    0, 0, 1,
    0, 0, -1
};
 
char map[35][35][35];  
int vis[35][35][35];  
int k,n,m,sx,sy,sz,ex,ey,ez;  
  
struct node  
{  
    int x,y,z,step;  
};  
  
bool check(int x,int y,int z)  
{  
    if(x < 0 || y < 0 || z < 0 || x >= k || y >= n || z >= m)  
        return false;  
    else if(map[x][y][z] == '#')  
        return false;  
    else if(vis[x][y][z])  
        return false;  
    return true;  
}  
  
int bfs()  
{    
    node a, next;  
    queue<node> que;  
    a.x = sx, a.y = sy, a.z = sz;  
    a.step = 0;  
    vis[sx][sy][sz] = 1;  
    que.push(a); 

    while(!que.empty())  
    {  
        a = que.front();  
        que.pop();  
        if(a.x == ex && a.y == ey && a.z == ez)  
            return a.step;  
        for(int i = 0; i < 6; i++)  
        {  
            next = a;  
            next.x = a.x + dir[i][0];  
            next.y = a.y + dir[i][1];  
            next.z = a.z + dir[i][2];  
            if(!check(next.x, next.y, next.z))  
                continue;  
            vis[next.x][next.y][next.z] = 1;  
            next.step = a.step+1;  
            que.push(next);  
        }  
    }  
    return 0;  
}  
  
int main()  
{  
    while(scanf("%d%d%d",&k,&n,&m),n+m+k)  
    {  
        for(int i = 0; i < k; i++)  
        {  
            for(int j = 0; j < n; j++)  
            {  
                scanf("%s", map[i][j]);  
                for(int r = 0; r < m; r++)  
                {  
                    if(map[i][j][r] == 'S')  
                    {  
                        sx = i, sy = j, sz = r;  
                    }  
                    if(map[i][j][r] == 'E')  
                    {  
                        ex = i, ey = j, ez = r;  
                    }  
                }  
            }  
        }  

        memset(vis,0,sizeof(vis));  
        
        int ans;  
        ans = bfs();  
        if(ans)  
        {
            printf("Escaped in %d minute(s).\n",ans);  
        
        }
        else  
        {
            printf("Trapped!\n"); 
        } 
    }  
  
    return 0;  
}
