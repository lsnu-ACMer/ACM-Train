#include <stdio.h>
int cmp(const int *a, const int *b) {
    return *a - *b;
}
int main(){
    int t, n, nums[200], a, ok;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (a = 0; a < n; ++a) {
            scanf("%d", nums + a);
        }
        qsort(nums, n, sizeof(int), cmp);
        ok = 1;
        if (n < 10 || n > 13) {
            ok = 0;
        }
        if (nums[0] != nums[1] || nums[0] != 1) {
            ok = 0;
        }
        for (a = 0; a < n - 2; ++a) {
            if (nums[a + 1] - nums[a] > 2) {
                ok = 0;
            }
        }
        printf(ok ? "Yes\n" : "No\n" );
    }
    return 0;
}
