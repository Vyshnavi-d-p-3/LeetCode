# class Solution:
#     def trap(self, height: List[int]) -> int:
#         if not height: return 0
#         l, r = 0, len(height) - 1
#         leftMax, rightMax = height[l], height[r]
#         res = 0

#         while l<r:
#             if leftMax < rightMax:
#                 l += 1
#                 leftMax = max(leftMax, height[l])
#                 res += leftMax - height[l]
#             else:
#                 r -= 1
#                 rightMax = max(rightMax, height[r])
#                 res += rightMax - height[r]
#         return res

# class Solution:
#     def trap(self, height):
#         ans = 0
#         size = len(height)
#         for i in range(1, size - 1):
#             left_max = 0
#             right_max = 0
#             # Search the left part for max bar size
#             for j in range(i, -1, -1):
#                 left_max = max(left_max, height[j])
#             # Search the right part for max bar size
#             for j in range(i, size):
#                 right_max = max(right_max, height[j])
#             ans += min(left_max, right_max) - height[i]
#         return ans

# class Solution:
#     def trap(Self, height: List[int]) -> int:
#         # Case of empty height list
#         if len(height) == 0:
#             return 0
#         ans = 0
#         size = len(height)
#         # Create left and right max arrays
#         left_max, right_max = [0] * size, [0] * size
#         # Initialize first height in to left max
#         left_max[0] = height[0]
#         for i in range(1, size):
#             # Update left max with current max
#             left_max[i] = max(height[i], left_max[i - 1])
#         # Initialize last height in to right max
#         right_max[size - 1] = height[size-1]
#         for i in range(size-2, -1, -1):
#             # update right max with current max
#             right_max[i] = max(height[i], right_max[i + 1])
#         # Calculate the trapped water
#         for i in range(1, size - 1):
#             ans += min(left_max[i], right_max[i]) - height[i]
#         # Return amount of trapped water
#         return ans

class Solution:
    def trap(self, height):
        left, right = 0 , len(height) - 1
        ans = 0
        left_max, right_max = 0, 0
        while left < right:
            if height[left] < height[right]:
                left_max = max(left_max, height[left])
                ans += left_max - height[left]
                left += 1
            else:
                right_max = max(right_max, height[right])
                ans += right_max - height[right]
                right -= 1
        return ans