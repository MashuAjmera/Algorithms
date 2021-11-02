# Problem: Next Permutation
# Author: Mashu Ajmera
# GFG: https://www.geeksforgeeks.org/find-the-next-lexicographically-greater-word-than-a-given-word/
# Leetcode: https://leetcode.com/problems/next-permutation
# Time Complexity: O(n)+ max((O(n)+O(nlogn)),O(n)) = O(nlogn)
# Space Complexity: O(1)

from sys import maxsize

class Solution:
    def nextPermutation(self, nums) -> None:
        N=len(nums)
        for i in range(N-1):
            if nums[N-i-2]<nums[N-i-1]:
                max=maxsize
                maxi=-1
                for j in range(i+1):
                    if nums[N-i-1+j]>nums[N-i-2] and nums[N-i-1+j]<max:
                        max=nums[N-i-1+j]
                        maxi=N-i-1+j
                nums[N-i-2],nums[maxi]=nums[maxi],nums[N-i-2]
                nums[N-i-1:N] = sorted(nums[N-i-1:N])
                return 
        nums.reverse()

if __name__=="__main__":
    # nums=[1,3,2] # [2,1,3]
    nums=[2,3,1,3,3] # [2,3,3,1,3]
    s=Solution()
    s.nextPermutation(nums)
    print(nums)
