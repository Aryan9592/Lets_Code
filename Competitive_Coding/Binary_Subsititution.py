"""
  Chef has binary string SS of length NN.
  Chef can perform the following operation on the string:

  1. Choose a contiguous subarray such that the count of set bits in the subarray is equal to the count of unset bits in the subarray.
     Replace the chosen subarray with either a set bit or an unset bit.
  2. Chef wants to reduce the string to minimum possible length using minimum number of given operations. Help Chef by telling him the minimum length and 
     also the operations required to obtain that. If there are multiple ways to obtain the answer, print any.
     
  SAMPLE:
                    Input                   Output
                    3                       1 1
                    4                       1 4 0
                    1100                    1 0
                    1                       1 2
                    1                       1 4 1
                    5                       1 2 1
                    11000
"""


for _ in range(int(input())):
    # Asking the user for the length of the array
    n = int(input())
    # Asking for the input
    s = input()
    # Counting the number of zeros and ones and comparing that if they are equal or not
    if s.count('0') == n or s.count('1') == n:
        # If Equal..then print the length and any replacing digit
        print(n, 0)
        continue
    # For the difference between the two
    dif = s.count('0') - s.count('1')
    # Printing the minimum length and the number of minimum operation required to do so
    print(1, abs(dif) + 1)
    # Looping till the difference is zero
    while dif != 0:
        # Updating the length of the string
        n = len(s)
        for i in range(n):
            # Finding the place where we get different indexes consisting of zero and one
            if s[i] != s[i+1]:
                which = '0'
                # If difference is a positive number..then this indicates that the number of zeros are more than the ones...
                # Hence there's a need of decreasing zeros in order to make the count equal
                if dif > 0:
                    which = '1'
                # This next statement decreases either zero and one depending on which is in more amount
                s = s[0:i] + which + s[i+2:]
                print(i+1, i+2, which)
                break
        dif = s.count('0') - s.count('1')
    n = len(s)
    print(1, n, 1)
