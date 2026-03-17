# class Solution:
#     def fizzBuzz(self, n: int) -> List[str]:
#         ans = []
#         for num in range(1, n+1):
#             divisible_by_3 = (num % 3 == 0)
#             divisible_by_5 = (num % 5 == 0)

#             if divisible_by_3 and divisible_by_5:
#                 ans.append("FizzBuzz")
#             elif divisible_by_3:
#                 ans.append("Fizz")
#             elif divisible_by_5:
#                 ans.append("Buzz")
#             else:
#                 ans.append(str(num))
#         return ans

# class Solution:
#     def fizzBuzz(self, n: int) -> List[str]:
#         ans = []
#         for num in range(1, n + 1):
#             divisible_by_3 = (num % 3 == 0)
#             divisible_by_5 = (num % 5 == 0)
#             nums_ans_str = ""
#             if divisible_by_3:
#                 nums_ans_str += "Fizz"
#             if divisible_by_5:
#                 nums_ans_str += "Buzz"
#             if not nums_ans_str:
#                 nums_ans_str = str(num)
#             ans.append(nums_ans_str)

#         return ans

class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        ans = []

        fizz_buzz_dict = {3 : "Fizz", 5 : "Buzz"}
        divisors = [3, 5]

        for num in range(1, n + 1):
            nums_ans_str = []
            for key in divisors:
                if num % key == 0:
                    nums_ans_str.append(fizz_buzz_dict[key])

            if not nums_ans_str:
                nums_ans_str.append(str(num))

            ans.append(''.join(nums_ans_str))
        return ans