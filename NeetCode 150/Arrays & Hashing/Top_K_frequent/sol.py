from typing import List
from collections import defaultdict


#solution 1 O(nlogn) complexity
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hashmap = defaultdict(int)
        for num in nums:           
            hashmap[num] +=1
        ans = [key for key, value in sorted(hashmap.items(), key = lambda item: item[1], reverse=True)][:k]
        return ans
    


#solution 2 O(n) complexity
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hashmap = defaultdict(int)
        occurance = [[] for i in range(len(nums) + 1)]

        for num in nums:           
            hashmap[num] +=1
        for key, val in hashmap.items():
            occurance[val].append(key)

        res = []
        for index in range(len(occurance) -1 , 0 ,-1):
            for num in occurance[index]:
                res.append(num)
                if len(res) == k:
                    return res


        
        

        