# class Solution:
#     def longestCommonPrefix(self, strs: List[str]) -> str:
#         if len(strs) == 0:
#             return ""
#         prefix = strs[0]
#         for i in range(1, len(strs)):
#             while strs[i].find(prefix) !=0:
#                 prefix = prefix[0 : len(prefix) - 1]
#                 if prefix == "":
#                     return ""
#         return prefix

# Vertical Scanning
# class Solution:
#     def longestCommonPrefix(self, strs: List[str]) -> str:
#         if strs == None or len(strs) == 0:
#             return ""
#         for i in range(len(strs[0])):
#             c = strs[0][i]
#             for j in range(1, len(strs)):
#                 if i == len(strs[j]) or strs[j][i] != c:
#                     return strs[0][0:i]
#         return strs[0]

# Divide & Conquere
class Solution:
    def longestCommonPrefix(self, strs):
        if not strs:
            return ""

        def LCP(left, right):
            min_len = min(len(left), len(right))
            for i in range(min_len):
                if left[i] != right[i]:
                    return left[:i]
            return left[:min_len]

        def divide_and_conquer(strs, l, r):
            if l == r:
                return strs[l]
            else:
                mid = (l + r) // 2
                lcpLeft = divide_and_conquer(strs, l, mid)
                lcpRight= divide_and_conquer(strs, mid + 1, r)

                return LCP(lcpLeft, lcpRight)

        return divide_and_conquer(strs, 0, len(strs) - 1)


