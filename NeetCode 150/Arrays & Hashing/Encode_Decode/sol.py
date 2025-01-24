from typing import List
from collections import defaultdict

#solution 1 O(n*m) complexity
class Solution:

    def encode(self, strs: List[str]) -> str:
        s = ""
        for word in strs:
            s += word + '`'
        return s

    def decode(self, s: str) -> List[str]:
        return s.split('`')[:-1]
    
    
#solution 2 O(n*m) complexity
    
class Solution:  
    def encode(self, strs: List[str]) -> str:
        res = ""
        for s in strs:
            res += str(len(s)) + "#" + s
        return res

    def decode(self, s: str) -> List[str]:
        res = []
        i = 0
        
        while i < len(s):
            j = i
            while s[j] != '#':
                j += 1
            length = int(s[i:j])
            i = j + 1
            j = i + length
            res.append(s[i:j])
            i = j
            
        return res
    
    
