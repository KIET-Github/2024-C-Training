# SHIVANSHU SINGH 2000290120152

# LCS: Longest Common Subsequence 

# Given two strings, S1 and S2, the task is to find the length of the Longest Common Subsequence, 
# i.e. longest subsequence present in both of the strings. 

# A longest common subsequence is defined as the longest subsequence which is common in all given input sequences.


#--------------Recursive---------------TLE O(2^(m*n))
def LCS(s1, s2, n, m):
    if n == 0 or m == 0:
        return 0
    elif s1[n-1] == s2[m-1]:
        return 1+LCS(s1, s2, n-1, m-1)
    else:
        return max(LCS(s1, s2, n, m-1), LCS(s1, s2, n-1, m))
        
s1 = "abcde"
s2 = "ace"
print(LCS(s1, s2, len(s1), len(s2)))


#--------------DP(MEMO)------------- O(m*n)

def LCSDP(s1, s2, n, m, dp):
    if n == 0 or m == 0:
        return 0
    if dp[n][m] != -1:
        return dp[n][m]
    if s1[n-1] == s2[m-1]:
        dp[n][m] = 1 + LCSDP(s1, s2, n-1, m-1, dp)
        return dp[n][m]
    
    dp[n][m] = max(LCSDP(s1, s2, n-1, m, dp), LCSDP(s1, s2, n, m-1, dp))
    return dp[n][m]
    
n, m = len(s1), len(s2)
dp = [[-1]*(m+1) for i in range(n+1)]
print(LCSDP(s1, s2, n, m, dp))


#-------------DP(TAB)----------------O(m*n)

def LCSDPTab(s1, s2, n, m):
    dp = [[0 for _ in range(m+1)] for _ in range(n+1)]
    
    for i in range(n):
        for j in range(m):
            if s1[i] == s2[j]:
                dp[i+1][j+1] = dp[i][j] + 1
            else:
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1])
                
    return max(max(k) for k in dp)


print(LCSDPTab(s1, s2, n, m))
