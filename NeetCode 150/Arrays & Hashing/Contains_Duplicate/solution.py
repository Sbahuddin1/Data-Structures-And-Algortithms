from typing import List

class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        hashset = set()
        for num in nums:
            if num in hashset:
                return True
            else:
                hashset.add(num)
        return False

solution = Solution()

nums = [1, 2, 3, 3]
print(solution.hasDuplicate(nums))
         