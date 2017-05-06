#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main()
{
    int n, m, b;
    int a[2][128][128];
    int dx[9]={-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int dy[9]={-1, 0, 1, -1, 0, 1, -1, 0, 1};

    cin >> m >> n >> b;
	for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
		    cin >> a[0][i][j];
        }
    }

	for(int k = 1; k <= b; ++k)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
	        {
		        a[k & 1][i][j] = 0;
		        for(int dir = 0; dir <= 8; ++dir)
                {
			        a[k & 1][i][j] 
                        += a[!(k & 1)][(i + dx[dir] + n)%n][(j + dy[dir] + m) % m];
                }
            }
        }
	}

    // 取非重复的值
    set<int> s;
	for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
		    s.insert(a[b & 1][i][j]);
        }
    }

	cout << s.size() << endl;;
	return 0;
}
