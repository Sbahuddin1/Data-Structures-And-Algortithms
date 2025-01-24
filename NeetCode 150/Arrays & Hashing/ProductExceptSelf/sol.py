from typing import List
from collections import defaultdict


#solution 1 O(n^2) complexity
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        output =[]       
        for num in range(len(nums)):
            exluded_num_array = nums[:num] + nums[num+1:]
            product = 1
            for i in exluded_num_array:
                product *= i
            output.append(product)
        return output
    
    
#solution 2 O(n) complexity
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        output =[1] * (len(nums))

        prefix = 1
        for i in range(len(nums)):
            output[i] = prefix
            prefix *= nums[i]

        postfix = 1
        for i in range(len(nums)-1,-1,-1):
            output[i] *= postfix
            postfix *= nums[i]
        return output