"""
    -There are N Pokemon trainers numbered from 1 to N. Each trainer has one Pokemon. All the trainers have arrived to participate in a contest.
    -There are two battle arenas, one in ground and other in water. Each Pokemon may have different power in both the arenas.
    -When two Pokemon fight in an arena, the Pokemon having higher power in that arena wins. It is guaranteed that all Pokemon have distinct powers 
     in the same arena to avoid any ties.
    -The strength of a Pokemon trainer is determined to be the number of other Pokemon his Pokemon can defeat in at least one arena.
    -It is known that only the Pokemon trainers with the highest strength will qualify for the next round (multiple trainers may have the same strength). 
     Find the number of Pokemon trainers who will qualify for the next round.
     
     SAMPLE:
                            Input                     Output
                            4                         1
                            2                         2
                            1 2                       2
                            3 4                       3
                            2
                            1 2
                            2 1
                            3
                            1 2 3
                            1 4 2
                            5
                            2 3 5 4 1
                            4 2 1 5 6
"""
# For the no. of test cases
for _ in range(int(input())):
    # Asking the number of players
    n = int(input())
    # Next three lines of codes will pair the players ground and water strength
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = [(a[i], b[i]) for i in range(n)]
    # This sorting function will sort the list according to the first value of the tuple in each element..Means according to the ground strength
    # For example.. If the list is like -> [(5, 1), (4, 5), (2, 4)]..then the sorted list will be -> [(2, 4), (4, 5), (5, 1)]
    c.sort()
    ans, mx = 0, 0
    # Taking the reversed range so that ground strength will automatically be taken in action
    for i in reversed(range(n)):
        # we know that the last element of the list will beat everyone in the ground field..So it will have maximum strength..
        # Next player will only be able to win the match if and only if he is losing from only the last element in ground field and beating him in water arena
        # Then next player will be the one to get defeated by the above two in ground and defeating them in water and so on....
        if c[i][1] > mx:
            ans += 1
        mx = max(mx, c[i][1])
    print(ans)
