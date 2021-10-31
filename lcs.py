# Problem: Longest Common Subsequence
# Author: Mashu Ajmera
# Algorithm: Dynamic Programming
# Leetcode: https://leetcode.com/problems/longest-common-subsequence/submissions/
# GFG: https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

class Solution:
    def longestCommonSubsequence(self,a,b):
        la=len(a)
        lb=len(b)
        dp=[[0 for i in range(lb+1)] for j in range(la+1)]
        print(dp[0])
        for i in range(1,la+1):
            for j in range(1,lb+1):
                if i==0 or j==0:
                    dp[i][j]=0
                elif a[i-1]==b[j-1]:
                    dp[i][j]=dp[i-1][j-1]+1
                else:
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j])
            # print(dp[i])
        return dp[la][lb]


if __name__=="__main__":
    a="GXTXAYB"
    b="AGGTAB"
    s=Solution()
    print(s.longestCommonSubsequence(a,b))
