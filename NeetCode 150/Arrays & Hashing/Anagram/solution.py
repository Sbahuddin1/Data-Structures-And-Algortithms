#Solution 1 --------------O(n^2)----------------
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        for word in s:
            if word in t:
                t = t.replace(word,"",1)
                print(t)
            else:
                return False
        return  t == ""

        
        
sol = Solution()
sol.isAnagram("racecar","carrace")  



#Solution 2 --------------O(n)----------------

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        countS, countT = {}, {}

        for i in range(len(s)):
            countS[s[i]] = 1 + countS.get(s[i], 0)
            countT[t[i]] = 1 + countT.get(t[i], 0)
        return countS == countT