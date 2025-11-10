class Solution:
    def __init__(self):
        self.memo = {}

    def rob(self, nums: List[int]) -> int:
        self.memo = {}
        return self.robForm(0, nums)
    def robForm(self, i, nums):
        # No more houses left to examine.
        if i >= len(nums):
            return 0
        # REturn cached value.
        if i in self.memo:
            return self.memo[i]
        # Recursive relation evaluation to get the optimal answer.
        ans = max(self.robForm(i + 1, nums), self.robForm(i + 2, nums) + nums[i])

        # Cache for future use
        self.memo[i] = ans
        return ans