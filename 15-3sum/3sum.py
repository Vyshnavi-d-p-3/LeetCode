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


# class Solution:
#     def threeSum(self, nums: List[int]) -> List[List[int]]:
#         res, dups = set(), set()
#         seen = {}
#         for i, val1 in enumerate(nums):
#             if val1 not in dups:
#                 dups.add(val1)
#                 for j, val2 in enumerate(nums[i+1 :]):
#                     complement = -val1 - val2
#                     if complement in seen and seen[complement] == i:
#                         res.add(tuple(sorted((val1, val2, complement))))
#                     seen[val2] = i
#         return [list(x) for x in res]   

# Brute Force code - Three loops and sort the elements before pushing to set - TC(O(N^3)), SC(O(1)) --- TLE Error
# class Solution:
#     def threeSum(self, nums: List[int]) -> List[List[int]]:
#         res = set()
#         for i in range(len(nums) - 2):
#             for j in range(i+1, len(nums)):
#                 for k in range(j+1, len(nums)):
#                     if(nums[i] + nums[j] + nums[k] == 0):
#                         res.add(tuple(sorted([nums[i], nums[j], nums[k]])))


#         return list(res)

# Approach - Better Approach - Using Hash Set - TC((O(n^2))), SC(O(N)) - TLE Error if input contains lot of Zero's
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = set()
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            tempSet = set()
            for j in range(i+1, len(nums)):
                k = -(nums[i] + nums[j])
                if k in tempSet:
                    res.add(tuple(sorted([nums[i], nums[j], k])))
                
                tempSet.add(nums[j])
            
        
        return [list(x) for x in res]
                