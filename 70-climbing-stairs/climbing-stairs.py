# BruteForce - Recursion - TC(O(2^n)) - SC(O(n))
# class Solution:
#     def climbStairs(self, n: int) -> int:
#         return self.climb_Stairs(0, n)

#     def climb_Stairs(self, i: int, n: int) -> int:
#         if i > n:
#             return 0
#         if i == n:
#             return 1
#         return self.climb_Stairs(i + 1, n) + self.climb_Stairs(i + 2, n)

# Better - Recursion with Memo - TC(O(n)) - SC(O(n))
# class Solution:
#     def climbStairs(self, n:int) -> int:
#         memo = [0] * (n+1)
#         return self.climb_Stairs(0, n, memo)

#     def climb_Stairs(self, i: int, n: int, memo: List[int]) -> int:
#         if i > n:
#             return 0
#         if i == n:
#             return 1
#         if memo[i] > 0:
#             return memo[i]
#         memo[i] = self.climb_Stairs(i+1, n, memo) + self.climb_Stairs(i+2, n, memo)

#         return memo[i]

# Optimal - Dynamic Programming - TC(O(n)) - SC(O(n))
# class Solution:
#     def climbStairs(self, n: int) -> int:
#         if n == 1:
#             return 1
#         dp = [0 for _ in range(n+1)]
#         dp[1] = 1
#         dp[2] = 2
#         for i in range(3, n+1):
#             dp[i] = dp[i - 1] + dp[i - 2]
#         return dp[n]

# Optimal - Fibonacci Number - TC(O(n)) - SC(O(1))
class Solution:
    def climbStairs(self, n):
        if n == 1:
            return 1
        first = 1
        second = 2
        for i in range(3, n + 1):
            third = first + second
            first = second
            second = third
        return second