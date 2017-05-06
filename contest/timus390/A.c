#include <stdio.h>
#include <string.h>
int main() {
    int n, a, res = 2, len;
    char name[21], *index;
    scanf("%d", &n);
    for (a = 0; a < n; ++a) {
        scanf("%s", name);
        len = strlen(name);
        index = strstr(name, "+one");
        res += (index != NULL && index - name + 4 == len) ? 2 : 1;
    }
    if (res == 13) {
        res += 1;
    }
    printf("%d\n", res * 100);
    return 0;
}
