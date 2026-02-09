# class Solution:
#     def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
#         output = []
#         q = collections.deque() #contains index
#         l = r = 0
#         while r < len(nums):
#             #pop smaller values from the queue
#             while q and nums[q[-1]] < nums[r]:
#                 q.pop()
#             q.append(r)
#             # remove left value from the window
#             if l > q[0]:
#                 q.popleft()
#             if (r + 1) >= k:
#                 output.append(nums[q[0]])
#                 l += 1
#             r += 1
#         return output

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        dq = deque()
        res = []
        for i in range(k):
            while dq and nums[i] >=  nums[dq[-1]]:
                dq.pop()

            dq.append(i)
        res.append(nums[dq[0]])

        for i in range(k, len(nums)):
            if dq and dq[0] == i-k:
                dq.popleft()
            while dq and nums[i] >= nums[dq[-1]]:
                dq.pop()
            dq.append(i)
            res.append(nums[dq[0]])
        return res
            












# Approach: Brute Force, TC(O(nk)) where n is size of the array and k is the sliding window size, SC(O(n - k + 1)) -- Error TLE
# class Solution:
#     def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
#         output = []
#         l = 0
#         r = k - 1
#         while r < len(nums) and r - l + 1 <= k:
#             ele = nums[l]
#             for i in range(l, r+1):
#                 ele = max(nums[i], ele)
            
#             l += 1
#             r += 1
#             output.append(ele)
#         return output

# class Solution:
#     def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
#         dq = deque()
#         res = []
#         for i in range(k):
#             while dq and nums[i] > nums[dq[-1]]:
#                 dq.pop()
#             dq.append(i)

#         res.append(nums[dq[0]])
#         for i in range(k, len(nums)):
#             if dq and dq[0] == i - k:
#                 dq.popleft()
#             while dq and nums[i] >= nums[dq[-1]]:
#                 dq.pop()

#             dq.append(i)
#             res.append(nums[dq[0]])

#         return res

