# class Solution:
#     def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
#         seen = {}

#         for i, val in enumerate(nums):
#             if val in seen and i - seen[val] <= k:
#                 return True
#             else:
#                 seen[val] = i
#         return False

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        seen = set()
        left = 0

        for right, val in enumerate(nums):
            if val in seen:
                return True

            seen.add(val)

            if right - left >= k:
                seen.remove(nums[left])
                left += 1

        return False