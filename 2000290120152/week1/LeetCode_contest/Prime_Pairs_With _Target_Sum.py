import math
class Solution:
    def findPrimePairs(self, n: int) -> List[List[int]]:
        is_prime = [1]*(n+1)
        for i in range(2,n+1):
            if not is_prime[i]:
                continue
            for j in range(2*i,n+1,i):
                is_prime[j] = 0
        ans = []
        for i in range(2, (n//2)+1):
            if is_prime[i] and is_prime[n-i]:
                ans.append([i, n-i])
        return ans
