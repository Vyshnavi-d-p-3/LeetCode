# My Solution : TC: O(n), SC: O(n)
# class Solution:
#     def firstMissingPositive(self, nums: List[int]) -> int:
#         nums_set = set(nums)
#         smallest_num = sys.maxsize
#         ans = 1
#         for i in range(len(nums)):
#             if nums[i] > 0 and nums[i] < smallest_num:
#                 smallest_num = nums[i]
#         i = 0
#         if smallest_num > 1:
#                 return ans
#         while i < len(nums):
#             if smallest_num + 1 in nums_set: 
#                 smallest_num += 1
#             else:
#                 ans = smallest_num + 1
#                 return ans

#         return ans

class Solution:
    def firstMissingPositive(self, nums):
        n = len(nums)
        seen = [False] * (n + 1)

        for num in nums:
            if 0 < num <= n:
                seen[num] = True

        for i in range(1, n+1):
            if not seen[i]:
                return i
        return n + 1
