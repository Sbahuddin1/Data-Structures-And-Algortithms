from collections import defaultdict
from typing import List


# Time: O(n*mlogm) where n is the number of strings and m is the length of the longest string
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = defaultdict(list)
        for s in strs:
            sortedS = ''.join(sorted(s))
            res[sortedS].append(s)
        return list(res.values())


# Time: O(n*m) where n is the number of strings and m is the length of the longest string
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashlist = defaultdict(list)
        for s in strs:
            count = [0]*26
            for c in s:
                count[ord(c) -ord('a')] +=1
            hashlist[tuple(count)].append(s)
        return hashlist.values()