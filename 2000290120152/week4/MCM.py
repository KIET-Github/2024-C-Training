# SHIVANSHU SINGH   2000290120152  
# Matrix Chain Multiplication

# -> We are given n matrices, we have to multiply them in such a way 
#    that the total number of operations are minimum.


# A(1x2) B(2x3) C(3x4) -->   A(BC) => 1x2x3 + 1x3x4 = 18 Operations  or 
#                            (AB)C => 2x3x4 + 1x2x4 = 32 Operations
#SO, (AB)C is more efficient than A(BC)


#--------------Recursive (MEMO)-----------------

n = int(input())
mx = 10**9+7
dp = [[mx]*n]*n

def mcm(a, i, j):
    if j-1 == 1:
        dp[i][j] = a[i-1]*a[i]*a[j]
        return dp[i][j]
    if i == j:
        return 0
    if dp[i][j] != mx:
        return dp[i][j]
    for k in range(i, j):
        tmp = mcm(a, i, k) + mcm(a, k+1, j) + a[i-1]*a[k]*a[j]
        dp[i][j] = min(tmp, dp[i][j])
    
    return dp[i][j]
        
# n = int(input()) on the top
arr = [int(i) for i in input().split()]
print(mcm(arr, 1, n-1))
        
# n = 4
# arr = [1,2,3,4]
# ans = 18



#--------------Tabulation(iterative)--------------



def mcmTab(n, a):
    
    mx = int(10**9+7)
    dp = [[0 for i in range(n)] for i in range(n)]

    for i in range(1, n):
        dp[i][i] = 0
        
    for gap in range(2, n):
        for i in range(1, n-gap+1):
            j = i + gap - 1
            dp[i][j] = mx

            for k in range(i, j):
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + a[i-1]*a[k]*a[j])
    
    return dp[1][n-1]
        
print(mcmTab(n, arr))
        
        
