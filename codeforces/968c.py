from collections import OrderedDict


def solve():
    a = input()
    s = input()
    m = {}
    for c in s:
        if c not in m:
            m[c] = 1
        else:
            m[c] += 1
    m = dict(sorted(m.items(), key=lambda item: item[1]))
    m = list(m.items())
    final = "".join([k * v for k, v in m[2:]])
    final = m[0][0] * m[0][1] + final
    if len(m) > 2:
        final = final + m[1][0] * m[1][1]
    print(final)


t = int(input())
while t:
    t -= 1
    solve()
