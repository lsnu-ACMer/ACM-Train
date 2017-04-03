#include <iostream>
#include <algorithm>
#define MAXN 100007

using namespace std;

int arr[MAXN];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int ans = 1000007;
    for(int i = 0; i < n; ++i)
    {
        ans = min(ans, arr[i] + arr[n - i - 1]);
    }
    cout << ans << endl;
    return 0;
}
