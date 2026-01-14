#  BruteForce - Two Pointer Approach - TC(O(n^2)), SC(O(1))
# class Solution:
#     def containsNearbyDuplicate(self, nums: List[int], k:int) -> bool:
#         i, j = 0, len(nums) - 1
#         while i < j:
#             if nums[i] == nums[j] and abs(i-j) <= k:
#                 return True
#             else:
#                 j -= 1
#                 if j == i:
#                     i += 1
#                     j = len(nums) - 1
#         return False

# Hash Map(Dictionary) - TC(O()), SC(O())
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        d = {}
        for i, num in enumerate(nums):
            if num in d and i - d[num] <=k:
                return True
            d[num] = i
        return False
