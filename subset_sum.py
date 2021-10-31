# Subset Sum Problem
# Language: Python
# Author: Mashu Ajmera
# Approach: Dynamic Programming
# GFG: https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

class Solution:
    def subsetSum(self,a,total) -> bool:
        n=len(a)
        dp=[[0 for i in range(n)] for j in range(n)]
        for i in range(n):
            for j in range(n):
                if i==0:
                    if a[j]>total:
                        dp[i][j]=dp[i][j-1]
                    else:
                        dp[0][j]=a[j]
                elif i>j:
                    dp[i][j]=dp[i-1][j]
                else:
                    x=dp[i-1][j]+dp[i-1][j-i]
                    if x<=total:
                        dp[i][j]=x
                    else:
                        dp[i][j]=dp[i-1][j]
                if dp[i][j]==total:
                    return "True"
            print(dp[i])
        return "False"

if __name__=="__main__":
    a=[2,3,4,5,12,34]
    total=9
    s=Solution()
    print(s.subsetSum(a,total))
