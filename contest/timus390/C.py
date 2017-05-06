n = int(raw_input())
t = n, s = 0, ok = False
for a in xrange(2, sqrt(n)):
    if pow(a, 20 - s) > t:
        break
    while not (t % a):
        t /= a, s += 1
    if sum > 20:
        break
    if sum == 20 and t == 1:
        ok = True, break
print 'Yes' if ok else 'No'
