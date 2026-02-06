# class Solution:
#     def characterReplacement(self, s: str, k: int) -> int:
#         count = {}
#         res = 0
#         l = 0
#         maxf = 0
#         for r in range(len(s)):
#             count[s[r]] = 1 + count.get(s[r], 0)
#             maxf = max(maxf, count[s[r]])
#             while (r - l + 1) - maxf > k:
#                 count[s[l]] -= 1
#                 l += 1
#             res = max(res, r - l + 1)
#         return res

#Appraoch: Binary Search & Sliding Window - TC(O(nlogn)), SC(O(1))
# class Solution:
#     def characterReplacement(self, s: str, k: int) -> int:
#         lo = 1
#         hi = len(s) + 1
#         while lo + 1 < hi:
#             mid = lo + (hi - lo) // 2
#             if self.can_make_valid_substring(s, mid, k):
#                 lo = mid
#             else:
#                 hi = mid

#         return lo

#     def can_make_valid_substring(Self, s: str, substring_length: int, k: int):
#         freq_map = {}
#         max_frequency = 0
#         start = 0
#         for end in range(len(s)):
#             freq_map[s[end]] = freq_map.get(s[end], 0) + 1
#             if end + 1 - start > substring_length:
#                 freq_map[s[start]] -= 1
#                 start += 1

#             max_frequency = max(max_frequency, freq_map[s[end]])
#             if substring_length - max_frequency <= k:
#                 return True

#         return False

# Approach: Two Pointers & Sliding Window,TC(O(mn)),SC: O(m)-> n: No. chars in string & m: No. Unique chars, m set to store unique chars
# class Solution:
#     def characterReplacement(self, s: str, k: int) -> int:
#         all_letters = set(s)
#         max_length = 0

#         for letter in all letters:
#             start = 0
#             count = 0

#             for end in range(len(s)):
#                 if s[end] == letter:
#                     count += 1

#                 while not self.is_window_valid(start, end, count, k):
#                     if s[start] == letter:
#                         count -= 1
#                     start += 1

#                 max_length = max(max_length, end + 1 - start)
#         return max_length

#         def is_window_valid(self, start: int, end: int, count: int, k: int):
#             return end + 1 - start - count <= k

# Approach: Two Pointer & Sliding Window, TC: O(n), SC: O(m) -> m no. chars in english i.e 26
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        start = 0
        freq_map = {}
        max_freq = 0
        longest_substring_length = 0
        for end in range(len(s)):
            freq_map[s[end]] = freq_map.get(s[end], 0) + 1

            max_freq = max(max_freq, freq_map[s[end]])

            is_valid = (end + 1 - start - max_freq <= k)
            if not is_valid:
                freq_map[s[start]] -= 1
                start += 1

            longest_substring_length = end + 1 - start

        return longest_substring_length