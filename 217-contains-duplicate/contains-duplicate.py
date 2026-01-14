# Brute Force : TC(O(N^2))
# class Solution:
#     def containsDuplicate(self, nums: List[int]) -> bool:
#         n = len(nums)
#         for i in range(n - 1):
#             for j in range(i + 1, n):
#                 if nums[i] == nums[j]:
#                     return True
#         return False


# Sorting the array and searching : TC(O(NlogN))
# class Solution:
#     def containsDuplicate(self, nums: List[int]) -> bool:
#         nums.sort()
#         n = len(nums)
#         for i in range(1, n):
#             if nums[i] == nums[i-1]:
#                 return True
#         return False

# Hash Set : TC(O(N))
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        List_NoDuplicates = set()
        for num in nums:
            if num in List_NoDuplicates:
                return True
            List_NoDuplicates.add(num)
        return False

# Hash Map : TC(O(N))
# class Solution:
#     def containsDuplicate(Self, nums: List[int]) -> bool:
#         seen = {}
#         for num in nums:
#             if num in seen and seen[num] >= 1:
#                 return True
#             seen[num] = seen.get(num, 0) + 1
#         return False

# Short Form - Hash Set - TC(O(n)), SC(O(n))
# class Solution:
#     def containsDuplicate(self, nums:List[int]) -> bool:
#         return True if len(set(nums)) < len(nums) else False