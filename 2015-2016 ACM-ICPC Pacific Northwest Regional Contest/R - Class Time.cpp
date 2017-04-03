#include <bits/stdc++.h>
#define MAXN 100
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    string name[MAXN], first_name, last_name;
    for (int a = 0; a < n; ++a) {
        cin >> first_name >> last_name;
        name[a] = last_name + " " + first_name;
    }
    sort(name, name + n);
    for (int a = 0; a < n; ++a) {
        int idx = name[a].find(' ');
        last_name = name[a].substr(0, idx);
        first_name = name[a].substr(idx + 1);
        cout << first_name << " " << last_name << endl;
    }
    return 0;
}