#include <stdio.h>
int main(){
    int t, n, num, a, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        a = 0, b = 0;
        while (n--) {
            scanf("%d", &num);
            if (num == 1) {
                a += 1;
            } else if (num == 2) {
                b += 1;
            }
        }
        if (a == b) {
            printf("Draw\n");
        } else if (a > b) {
            printf("Kobayashi\n");
        } else {
            printf("Tohru\n");
        }
    }
    return 0;
}
