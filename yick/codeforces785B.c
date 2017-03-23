/* ACMer: yick
 * Date: 20170323
 * 题目链接: http://codeforces.com/problemset/problem/785/B
 * 题目大意：象棋课和编程课，象棋课一天有n次机会可以上，时间片段为(l1i, r1i)；
 *           编程课一天有m次机会可以上，时间片段为(l2i, r2i);
 *           两门课程都想上，求中间最多能休息多久？
 * 解题思路: 如果先上象棋课，那么最长休息时间为：max_l2 - min_r1
 *           如果先上编程课，那么最长休息时间为: max_l1 - min_r2
 *           两者求大则为答案，注意处理答案为0的情况
 *
 */
//代码部分
#include <stdio.h>
int main() {
	int n, m, l, r;
	int max_l1 = 1, min_r1 = 1e9, max_l2 = 1, min_r2 = 1e9;
	int i, res1, res2;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d%d", &l, &r);
		max_l1 = l > max_l1 ? l : max_l1; 
		min_r1 = r < min_r1 ? r : min_r1;
	}
	scanf("%d", &m);
	for (i = 0; i < m; ++i) {
		scanf("%d%d", &l, &r);
		max_l2 = l > max_l2 ? l : max_l2;
		min_r2 = r < min_r2 ? r : min_r2;
	}
	if (min_r1 >= max_l2 && min_r2 >= max_l1) {
		printf("0\n");
	}
	else {
		res1 = max_l2 - min_r1;
		res2 = max_l1 - min_r2;
		printf("%d\n", res1 > res2 ? res1 : res2);
	}
	return 0;
}
