#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int>P;
int a[207];
int b[207];
queue<int> que;
P p;


int main(){
    int t;
    cin >> t;
    int n, m, x, y;
    for(int i = 0; i < t; i++){
        cin >> n >> m >> x >> y;
        int ans = 0;
        for(int j = 0; j < 2 * x; j += 2){
            cin >> a[j] >> a[j + 1];
        }
        for(int j = 0; j < 2 * y; j += 2){
            cin >> b[j] >> b[j + 1];
        }
        int t1 = 0, t2 = 0;
        while(t1 < 2 * x && t2 < 2 * y){
            if(a[t1] < b[t2]){
                if(a[t1 + 1] < b[t2]){
                    t1 += 2;
                }else if(a[t1 + 1] > b[t2]){
                    if(a[t1 + 1] > b[t2 + 1]){
                        ans += max(0, b[t2 + 1] - b[t2] + 2 - m);
                        t2 += 2;
                    }else{
                        ans += max(0, a[t1 + 1] - b[t2] + 2 - m);
                        t1 += 2;
                    }
                }
            }else if(a[t1] == b[t2]){
                if(a[t1 + 1] > b[t2 + 1]){
                    ans += max(0, b[t2 + 1] - b[t2] + 2 - m);
                    t2 += 2;
                }else if(a[t1 + 1] == b[t2 + 1]){
                    ans += max(0, b[t2 + 1] - b[t2] + 2 - m);
                    t1 += 2;
                    t2 += 2;
                }else{
                    ans += max(0, a[t1 + 1] - a[t1] + 2 - m);
                    t1 += 2;
                }
            }else {
                if(a[t1] > b[t2 + 1]){
                    t2 += 2;
                }else if(b[t2 + 1] > a[t1]){
                    if(b[t2 + 1] > a[t1 + 1]){
                        ans += max(0, a[t1 + 1] - a[t1] + 2 - m);
                        t1 += 2;
                    }else{
                        ans += max(0, b[t2 + 1] - a[t1] + 2 - m);
                        t2 += 2;
                    }
                }
            }

        }
        cout << ans << endl;
    }
    return 0;
}
