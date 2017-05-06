#include <stdio.h>
#include <malloc.h>
#define MAXN 500000
typedef struct Node {
    int rollback;
    int learn;
    struct Node *pre;
}Clone;

Clone *cc[MAXN] = {NULL};
int count = 1;

void learn(int idx, int p) {
    Clone *t = (Clone *)malloc(sizeof(Clone));
    t->rollback = 0, t->learn = p;
    t->pre = cc[idx];
    cc[idx] = t;
}

void rollback(int idx) {
    int c1 = 1, c2 = 0;
    Clone *t = (Clone *)malloc(sizeof(Clone));
    t->rollback = 1, t->learn = cc[idx]->learn, t->pre = cc[idx];
    cc[idx] = t;
    t = t->pre;
    while (c1 > c2) {
        if (t->rollback) {
            c1 += 1;
        } else {
            c2 += 1;
        }
        t = t->pre;
    }
    cc[idx]->learn = t == NULL ? 0 : t->learn;
}

void relearn(int idx) {
    Clone *t = (Clone *)malloc(sizeof(Clone));
    Clone *p = cc[idx];
    while (p != NULL && p->rollback != 0) {
        p = p->pre;
    }
    t->rollback = p->rollback, t->learn = p->learn, t->pre = cc[idx];
    cc[idx] = t;
}


void clone(int idx) {
    Clone *t = (Clone *)malloc(sizeof(Clone));
    t->rollback = cc[idx]->rollback;
    t->learn = cc[idx]->learn;
    t->pre = cc[idx]->pre;
    cc[++count] = t;
}
    
int check(int idx) {
    if (cc[idx] == NULL) {
        return 0;
    }
    return cc[idx]->learn;
}

int main() {
    int n, m, c, p, ret;
    char opt[10];
    scanf("%d%d", &n, &m);
    while (n--) {
        scanf("%s", opt);
        if (opt[0] == 'l') {//learn
            scanf("%d%d", &c, &p);
            learn(c, p);
        } else if (opt[0] == 'r' && opt[1] == 'o') {//rollback
            scanf("%d", &c);
            rollback(c);
        } else if (opt[0] == 'r' && opt[1] == 'e') {//relearn
            scanf("%d", &c);
            relearn(c);
        } else if (opt[0] == 'c' && opt[1] == 'l') {//clone
            scanf("%d", &c);
            clone(c);
        } else if (opt[0] == 'c' && opt[1] == 'h') {//check
            scanf("%d", &c);
            ret = check(c);
            if (ret) {
                printf("%d\n", ret);
            } else {
                printf("basic\n");
            }
        }
    }
    return 0;
}
