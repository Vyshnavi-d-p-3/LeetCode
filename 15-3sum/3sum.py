# Approach: Sorting and TwoSum of elements , TC(O(nlogn + n^2)), SC(O(logn) - O(n))
# class Solution:
#     def threeSum(self, nums: List[int]) -> List[List[int]]:
#         res = []
#         nums.sort()
#         for i in range(len(nums)):
#             if nums[i] > 0:
#                 break
#             if i == 0 or nums[i-1] != nums[i]:
#                 self.twoSumII(nums, i, res)
#         return res
#     def twoSumII(self, nums: List[int], i: int, res: List[List[int]]):
#         lo, hi = i + 1, len(nums) - 1
#         while lo < hi:
#             sum = nums[i] + nums[lo] + nums[hi]
#             if sum < 0:
#                 lo += 1
#             elif sum > 0:
#                 hi -= 1
#             else:
#                 res.append([nums[i], nums[lo], nums[hi]])
#                 lo += 1
#                 hi -= 1
#                 while lo < hi and nums[lo] == nums[lo - 1]:
#                     lo += 1


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res, dups = set(), set()
        seen = {}
        for i, val1 in enumerate(nums):
            if val1 not in dups:
                dups.add(val1)
                for j, val2 in enumerate(nums[i+1 :]):
                    complement = -val1 - val2
                    if complement in seen and seen[complement] == i:
                        res.add(tuple(sorted((val1, val2, complement))))
                    seen[val2] = i
        return [list(x) for x in res]                