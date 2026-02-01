class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums_set = set(nums)
        smallest_num = sys.maxsize
        ans = 1
        for i in range(len(nums)):
            if nums[i] > 0 and nums[i] < smallest_num:
                smallest_num = nums[i]
        i = 0
        if smallest_num > 1:
                return ans
        while i < len(nums):
            if smallest_num + 1 in nums_set: 
                smallest_num += 1
            else:
                ans = smallest_num + 1
                return ans

        return ans


