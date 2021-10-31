# Problem: Minimum Subset Sum Difference
# Author: Mashu Ajmera
# Approach: Dynamic Programming
# Leetcode: https://leetcode.com/problems/last-stone-weight-ii/
# Github: https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
# YouTube: https://youtu.be/FB0KUhsxXGY

class Solution:
    def lastStoneWeightII(self, stones) -> int:
        n=len(stones)
        s=sum(stones)
        ns=s//2
        dp=[[False for i in range(ns+1)] for j in range(n+1)]

        for i in range(n+1):
            for j in range(ns+1):
                if j==0:
                    dp[i][j]=True
                elif i==0:
                    dp[i][j]=False
                elif j<stones[i-1]:
                    dp[i][j]=dp[i-1][j]
                else:
                    dp[i][j]=dp[i-1][j] or dp[i-1][j-stones[i-1]]
            print(dp[i])
        
        for i in range(ns,-1,-1):
            if dp[n][i]==True:
                return s-2*i

if __name__=="__main__":
    # a=[1,6,11,5] #1
    # a=[3, 1, 4, 2, 2, 1] #1
    # a=[91] #91
    a=[31,26,33,21,40] #5
    s=Solution()
    print(s.lastStoneWeightII(a))
