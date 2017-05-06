def solve(s):
    d = dict()
    find_pos = lambda f: (s.find(f[0]), s.find(f[1]))
    d['object'] = find_pos(('{', '}'))
    d['subject'] = find_pos(('(', ')'))
    d['verb'] = find_pos(('[', ']'))
    ret, start, idx = '', 0, 0
    for pos in sorted(d.values(), key=lambda item: item[0]):
        ret += s[start:pos[0]]
        if idx == 0:
            ret += s[d['object'][0] + 1:d['object'][1]]
        elif idx == 1:
            ret += s[d['subject'][0] + 1:d['subject'][1]]
        elif idx == 2:
            ret += s[d['verb'][0] + 1:d['verb'][1]]
        start = pos[1] + 1
        idx += 1
    return ret

s = raw_input()
segs = s.split(',')
s = ','.join([solve(seg) for seg in segs]).lower()
print s[0].upper() + s[1:]
