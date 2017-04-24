t = int(raw_input())
for tt in xrange(0, t):
    sin = raw_input().split(' ')
    n = int(sin[0])
    p = int(sin[1])
    sin = raw_input().split(' ')
    c = int(sin[0])
    names = sin[1:]
    d = dict()
    for name in names:
        d[name] = 0
    for a in xrange(0, p):
        sin = raw_input().split(' ')
        for name in sin[1:]:
            d[name] |= 1 << a
    v = [-1] * n
    for a in xrange(0, n):
        sin = raw_input().split(' ')
        t = 0
        for b in xrange(0, p):
            if sin[b] == '1':
               t |= 1 << b 
        v[a] = t
    flag = [True] * n
    for a in xrange(0, n):
        for b in xrange(a + 1, n):
            if v[a] == v[b]:
                flag[a] = flag[b] = False
    for a in xrange(0, n):
        ls = list()
        for name in d.keys():
            if d[name] == v[a]:
                ls.append(name)
        if len(ls) == 1:
            print ls[0]
        else:
            print "Let's go to the library!!"
