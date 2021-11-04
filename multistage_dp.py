# Problem: Multistage Graph
# Approach: Dynamic Programming
# Author: Mashu Ajmera
# GFG: https://www.geeksforgeeks.org/multistage-graph-shortest-path/
# Youtube: https://www.youtube.com/watch?v=9iE9Mj4m8jk
# Time Complexity: O(n*n)
# Space Complexity: O(n*n)

from sys import maxsize

def msg(g):
    n=len(g[0])
    dp=[maxsize for i in range(n)]
    for i in range(n-1):
        for j in range(i,n):
            dp[j]=0 if j==0 else min(dp[j],dp[i]+g[i][j]) 
    return dp[n-1]


if __name__=="__main__":
    g = [[maxsize, 1, 2, 5, maxsize, maxsize, maxsize, maxsize],
        [maxsize, maxsize, maxsize, maxsize, 4, 11, maxsize, maxsize],
        [maxsize, maxsize, maxsize, maxsize, 9, 5, 16, maxsize],
        [maxsize, maxsize, maxsize, maxsize, maxsize, maxsize, 2, maxsize],
        [maxsize, maxsize, maxsize, maxsize, maxsize, maxsize, maxsize, 18],
        [maxsize, maxsize, maxsize, maxsize, maxsize, maxsize, maxsize, 13],
        [maxsize, maxsize, maxsize, maxsize, maxsize, maxsize, maxsize, 2]]
    print(msg(g))
