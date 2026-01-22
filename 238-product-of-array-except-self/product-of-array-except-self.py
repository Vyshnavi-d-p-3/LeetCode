# class Solution:
#     def productExceptSelf(self, nums: List[int]) -> List[int]:
#         res = [1] * (len(nums))
#         prefix = 1
#         for i in range(len(nums)):
#             res[i] = prefix
#             prefix *= nums[i]
#         postfix = 1
#         for i in range(len(nums) - 1, -1, -1):
#             res[i] *= postfix
#             postfix *= nums[i]
#         return res

# TC(O(N)), SC(O(1))
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        length = len(nums)
        ans = [0] * length
        ans[0] = 1
        for i in range(1, length):
            ans[i] = ans[i - 1] * nums[i - 1]

        R = 1
        for i in reversed(range(length)):
            ans[i] *= R
            R *= nums[i]

        return ans

# TC(O(N)), SC(O(N))
    # class Solution:
    #     def productExceptSelf(self, nums: List[int]) -> List[int]:
    #         length = len(nums)
    #         L, R, answer =[0]* length, [0] * length, [0] * length
    #         L[0] = 1
    #         for i in range(1, length):
    #             L[i] = L[i - 1] * nums[i - 1]

    #         R[length - 1] = 1
    #         for i in reversed(range(length - 1)):
    #             R[i] = R[i + 1] * nums[i + 1]

    #         for i in range(length):
    #             answer[i] = L[i] * R[i]
            
    #         return answer