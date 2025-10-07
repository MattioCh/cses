def solve():
    n, k = [int(i) for i in input().split(" ")]
    s = input()
    s_set = set(s)
    if n == 1:
        print("NO")
        return
    if len(s_set) == 1:
        print("NO")
        return
    if k == 0:
        l = 0
        r = len(s) - 1
        while l < r:
            if s[l] < s[r]:
                print("YES")
                return
            elif s[l] > s[r]:
                print("NO")
                return
            l += 1
            r -= 1
        print("NO")
        return
    print("YES")


t = int(input())
while t:
    solve()
    t -= 1
