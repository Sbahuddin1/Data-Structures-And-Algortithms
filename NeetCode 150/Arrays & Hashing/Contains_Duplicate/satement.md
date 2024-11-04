# Duplicate Integer

## Problem Statement
The goal of this problem is to determine if an integer array contains any duplicate values. A duplicate is defined as any value that appears more than once in the array. Your task is to implement a function that checks for duplicates and returns a boolean result.

### Function Signature
```python
def hasDuplicate(nums: List[int]) -> bool:
```

### Input
- A list of integers `nums`, where `1 <= nums.length <= 10^5` and `-10^9 <= nums[i] <= 10^9`.

### Output
- Return `true` if any integer appears more than once in the array; otherwise, return `false`.

### Examples
#### Example 1
- **Input:** `nums = [1, 2, 3, 3]`
- **Output:** `true`
  
In this example, the integer `3` appears twice in the array.

#### Example 2
- **Input:** `nums = [1, 2, 3, 4]`
- **Output:** `false`
  

## Starting Code

```python
from typing import List

class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        # Your implementation here
        



# Example usage
solution = Solution()
nums = [1, 2, 3, 3]
print(solution.hasDuplicate(nums))  # Output: True
```

---