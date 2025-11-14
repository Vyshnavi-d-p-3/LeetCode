# class Solution:
#     def longestPalindrome(self, s: str) -> str:
#         def check(i, j):
#             left = i
#             right = j - 1

#             while left < right:
#                 if s[left] != s[right]:
#                     return False

#                 left += 1
#                 right -= 1

#             return True

#         for length in range(len(s), 0, -1):
#             for start in range(len(s) - length + 1):
#                 if check(start, start + length):
#                     return s[start : start + length]

#         return ""

# Dynamic Programming
class Solution:
    def longestPalindrome(self, s:str) -> str:
        n = len(s)
        dp = [[False] * n for _ in range(n)]
        ans = [0, 0]

        for i in range(n):
            dp[i][i] = True

        for i in range(n - 1):
            if s[i] == s[i + 1]:
                dp[i][i + 1] = True
                ans = [i, i+1]

        for diff in range(2, n):
            for i in range(n - diff):
                j = i + diff
                if s[i] == s[j] and dp[i + 1][j - 1]:
                    dp[i][j] = True
                    ans = [i, j]

        i, j = ans
        return s[i : j + 1]