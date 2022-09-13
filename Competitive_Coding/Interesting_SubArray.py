"""
    It is the answer of the same problem that was discussed in Interesting_SubArray.cpp
"""
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    mn, mx = min(a), max(a)
    print(min(mn*mn, mn*mx, mx*mx), max(mn*mn, mx*mx))
