"""
  You are given a binary string S.
  In one second, the following scenario happens simultaneously and independently for all the bits which are set to 1 in the string:
  - Change the bit from 1 to 0.
  - If the left neighbour exists and is 0, change it to 1.
  - If the right neighbour exists and is 0, change it to 1.
  For example, if S = 010 initially, then after 1 second, S = 101 (the 11 bit and both its neighbours were changed). After another second, S = 010. 
  Here, the first and the last bit were changed to 0 because earlier they were 1. The middle bit was changed because it was 0 earlier and 
  it was a neighbour of a 1 bit.
  
  Find out the string S after K seconds.
  
  SAMPLE:
                    INPUT               OUTPUT
                    3                   010
                    3 1                 10101
                    101                 01100101010101
                    5 2
                    10001
                    14 3
                    10011010111000
"""


for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input()
    t = [0]*n
    for i in range(n):
        if s[i] == '0':
            continue
        t[i] = 0
        if i > 0 and s[i-1] == '0':
            t[i-1] = 1
        if i+1 < n and s[i+1] == '0':
            t[i+1] = 1
    k -= 1
    dist = [n+1]*n
    prv = -1
    for i in range(n):
        if t[i] == 1:
            prv = i
        if prv != -1:
            dist[i] = i - prv
    prv = -1
    for i in reversed(range(n)):
        if t[i] == 1:
            prv = i
        if prv != -1:
            dist[i] = min(dist[i], prv - i)
    ans = ''
    for i in range(n):
        first = dist[i]
        if first == n+1 or first > k:
            ans += '0'
        else:
            if (k-first)%2 == 0:
                ans += '1'
            else:
                ans += '0'
    print(ans)
