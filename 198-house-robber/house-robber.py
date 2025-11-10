# Recursion - TC(O(N)) - SC(O(N))
# class Solution:
#     def __init__(self):
#         self.memo = {}
#     def rob(self, nums: List[int]) -> int:
#         self.memo = {}
#         return self.robFrom(0, nums)
#     def robFrom(self, i, nums):
#         if i>= len(nums):
#             return 0
#         if i in self.memo:
#             return self.memo[i]
#         ans = max(self.robFrom(i + 1, nums), self.robFrom(i + 2, nums) + nums[i])
#         self.memo[i] = ans
#         return ans

# Dynamic Programming - TC(O()) - SC(O())
class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        N = len(nums)
        maxRobbedAmount = [0 for _ in range(N+1)]
        maxRobbedAmount[N] = 0
        maxRobbedAmount[N - 1] = nums[N - 1]
        for i in range(N - 2, -1, -1):
            maxRobbedAmount[i] = max(maxRobbedAmount[i + 1], maxRobbedAmount[i + 2] + nums[i])
        return maxRobbedAmount[0]