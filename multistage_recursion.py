# Problem: Multistage Graph
# Approach: Recursion
# Author: Mashu Ajmera
# GFG: https://www.geeksforgeeks.org/multistage-graph-shortest-path/
# Youtube: https://www.youtube.com/watch?v=9iE9Mj4m8jk
# Time Complexity: 
# Space Complexity: O(1)

from sys import maxsize

def msg(g,s=0):
    return 0 if s==len(g) else min(g[s][i]+msg(g,i) if g[s][i]!=0 else maxsize for i in range(len(g[s])))

if __name__=="__main__":
    g = [[0, 1, 2, 5, 0, 0, 0, 0],
        [0, 0, 0, 0, 4, 11, 0, 0],
        [0, 0, 0, 0, 9, 5, 16, 0],
        [0, 0, 0, 0, 0, 0, 2, 0],
        [0, 0, 0, 0, 0, 0, 0, 18],
        [0, 0, 0, 0, 0, 0, 0, 13],
        [0, 0, 0, 0, 0, 0, 0, 2]]
    print(msg(g))
