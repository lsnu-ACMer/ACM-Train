#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(~scanf("%d", &n)) {
        set<string> old;
        int ret = 0;
        for (int a = 0; a < n; ++a) {
            string sin;
            cin >> sin;
            string ss = sin + sin;
            bool ok = false;
            for (int a = 0; a < sin.size(); ++a) {
                string sub = ss.substr(a, sin.size());
                if (old.find(sub) != old.end()) {
                    ok = true;
                }
            }
            if (!ok) {
                ret += 1;
            }
            old.insert(sin);
        }
        cout << ret << endl;
    }
    return 0;
}
