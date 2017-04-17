def dfs(inwards, outwards, n, flag):
    tmp = inwards[0] * n
    if tmp == inwards and tmp == outwards:
        return ord(tmp[0]) - 65
    if n % 2:
        return -1;
    m = n / 2
    res0 = dfs(inwards[0 : m], inwards[m : n], m, flag ^ 1)
    res1 = dfs(outwards[0 : m], outwards[m : n], m, flag ^ 1)
    if flag == res0 or flag == res1:
        return flag
    if res0 == -1 or res1 == -1:
        return -1
    return flag ^ 1

n = int(raw_input())
inwards = raw_input()
outwards = raw_input()
res = dfs(inwards, outwards, n, 0)
if res == -1:
    print 'Draw'
elif res == 0:
    print 'Alice'
else:
    print 'Bob'
