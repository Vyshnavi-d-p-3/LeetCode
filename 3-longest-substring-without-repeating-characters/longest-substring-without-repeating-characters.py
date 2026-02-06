# class Solution:
#     def lengthOfLongestSubstring(self, s: str) -> int:
#         charSet = set()
#         l = 0
#         res = 0
#         for r in range(len(s)):
#             while s[r] in charSet:
#                 charSet.remove(s[l])
#                 l += 1
#             charSet.add(s[r])
#             res = max(res, r-l+1)
#         return res

# Approach: Brute Force, TC: O(n^3), SC: O(k) --> O(min(n, m)) 
# class Solution:
#     def lengthOfLongestSubstring(self, s: str) -> int:
#         def check(start, end):
#             chars = set()
#             for i in range(start, end +1):
#                 c = s[i]
#                 if c in chars:
#                     return False
#                 chars.add(c)
#             return True

#         n = len(s)

#         res = 0
#         for i in range(n):
#             for j in range(i, n):
#                 if check(i, j):
#                     res = max(res, j - i + 1)
#         return res

# Approach 2: Sliding Window, TC: O(n), SC: O(k) -> O(1)

class Solution:
    def lengthOfLongestSubstring(Self, s: str) -> int:
        chars = Counter()
        left = right = 0
        res = 0
        while right < len(s):
            r = s[right]
            chars[r] += 1
            
            while chars[r] > 1:
                l = s[left]
                chars[l] -= 1
                left += 1
            
            res = max(res, right - left + 1)

            right += 1

        return res