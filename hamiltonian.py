# Problem: Hamiltonian Cycle
# Author: Mashu Ajmera
# Approach: Backtracking
# Time Complexity: 
# Space Complexity:
# GFG: https://www.geeksforgeeks.org/hamiltonian-cycle-backtracking-6/

def check(s,g,n,vis):
    ans=0
    for i in range(1,n):
        if vis[i]==-1:
            ans+=1
            if g[s][i]==1:
                vis[i]=s
                check(i,g,n,vis)
    if ans==0 and g[s][0]==1:
        res=[s]
        while res[-1]!=0:
            res.append(vis[res[-1]])
        print(res)
    vis[s]=-1

def hamiltonian(g):
    n=len(g)
    vis=[-1 for i in range(n)]
    check(0,g,n,vis)

if __name__=="__main__":
    g=[ [0, 1, 0, 1, 0], [1, 0, 1, 1, 1],
        [0, 1, 0, 0, 1,], [1, 1, 0, 0, 1],
        [0, 1, 1, 1, 0], ] # [1, 2, 4, 3, 0]
    # g=[ [0, 1, 0, 1, 0], [1, 0, 1, 1, 1],
    #     [0, 1, 0, 0, 1,], [1, 1, 0, 0, 0],
    #     [0, 1, 1, 0, 0], ] # no solution
    # g=[ [0, 1, 0, 1, 0], [1, 0, 1, 1, 1],
    #         [0, 1, 0, 0, 1,],[1, 1, 0, 0, 1],
    #         [0, 1, 1, 1, 0], ] # [1, 2, 4, 3, 0]
    hamiltonian(g)