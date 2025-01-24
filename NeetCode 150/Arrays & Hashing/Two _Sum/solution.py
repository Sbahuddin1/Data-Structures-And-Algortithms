from typing import List

# Solution 1 : Brute Force O(n^2)
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if nums[i] + nums[j] == target:
                    return [i,j]
        
        return []
    
    
# Solution 2 : Using Hash Table O(n)

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        Map = {}
        for i, n in enumerate(nums):
            diff = target - n
            if diff in Map:
                return [Map[diff],i]
            Map[n] = i
        return


#------------------Test-------------------
sol = Solution()
print(sol.twoSum([2,7,11,15],9)) # Output: [0,1]
