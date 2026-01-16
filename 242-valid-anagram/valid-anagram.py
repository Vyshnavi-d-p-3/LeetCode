# class Solution:
#     def isAnagram(self, s: str, t: str) -> bool:
#         if len(s) != len(t):
#             return False
#         countS, countT = {}, {}
#         for i in range(len(s)):
#             countS[s[i]] = 1 + countS.get(s[i],0)
#             countT[t[i]] = 1 + countT.get(t[i],0)
#         for c in countS:
#             if countS[c] != countT.get(c,0):
#                 return False
#         return True


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        counter = {}

        for char in s:
            counter[char] = counter.get(char, 0) + 1

        for char in t:
            if char not in counter or counter[char] == 0:
                return False
            counter[char] -= 1

        return True