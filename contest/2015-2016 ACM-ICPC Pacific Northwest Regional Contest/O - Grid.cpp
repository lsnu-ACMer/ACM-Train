#include <iostream>
#include <queue>
#include <cstring>
#define INF 10000007

using namespace std;

typedef pair<int, int> p;

int m, n;
string maze[505];
int val[505][505];

bool check(int row, int col, int old_row, int old_col)
{
    if(row >= 0 && row < m && col >= 0 && col < n
            && val[row][col] == INF)
    {
        return true;
    }
    return false;
}

void bfs()
{
    for(int i = 0; i < 505; ++i)
    {
        for(int j = 0; j < 505; ++j)
        {
            val[i][j] = INF;
        }
    }
    queue<p> que;
    que.push(p(0, 0));
    val[0][0] = 0;

    while(!que.empty())
    {
        p point = que.front();
        que.pop();
        //cout << point.first << " " << point.second << " " << val[point.first][point.second] << endl;    
        if(point == p(m - 1, n - 1))
        {
            cout << val[point.first][point.second] << endl;
            return; 
        }
        int power = maze[point.first][point.second] - '0';
        // up
        if(check(point.first - power, point.second, point.first, point.second))
        {
            que.push(p(point.first - power, point.second));
            val[point.first - power][point.second] =
                val[point.first][point.second] + 1;
        }
        // down
        if(check(point.first + power, point.second, point.first, point.second))
        {
            que.push(p(point.first + power, point.second));
            val[point.first + power][point.second] =
                val[point.first][point.second] + 1;
        }
        // left
        if(check(point.first, point.second - power, point.first, point.second))
        {
            que.push(p(point.first, point.second - power));
            val[point.first][point.second - power] =
                val[point.first][point.second] + 1;
        }
        // right
        if(check(point.first, point.second + power, point.first, point.second))
        {
            que.push(p(point.first, point.second + power));
            val[point.first][point.second + power] =
                val[point.first][point.second] + 1;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
int main()
{
    cin >> m >> n;
    for(int i = 0; i < m; ++i)
    {
        cin >> maze[i];
    }

    bfs();
    return 0;
}