# Problem: Matrix Chain Multiplication
# Author: Mashu Ajmera
# GFG: https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
# Approach Dynamic Programming
# Time Complexity: O(n*n)
# Space Complexity: O(n*n)

def mcm(a):
    n=len(a)-1
    dp=[[0 for i in range(n)] for i in range(n)]
    for i in range (1,n):
        for j in range(n-i):
            if i==1: 
                dp[j][i+j]=a[j]*a[j+1]*a[j+2]
            dp[j][i+j]=min(dp[j][i+j-1] + a[j]*a[i+j]*a[i+j+1]        ,dp[j+1][i+j] + a[j]*a[j+1]*a[i+j+1])
    print(dp)    
    return dp[0][n-1]

if __name__=="__main__":
    a=[40, 20, 30, 10, 30] # 26000
    a=[10, 20, 30, 40, 30] # 30000
    a=[10, 20, 30] # 6000
    a=[1, 2, 3, 4, 3] # 30
    a=[1, 2, 3, 4] # 18
    print(mcm(a))
