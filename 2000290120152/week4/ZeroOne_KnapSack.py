# SHIVANSHU SINGH  2000290120152
# 0/1 Knapsack Problem

# We are given N items where each item has some weight and profit associated with it. 
# We are also given a bag with capacity W, [i.e., the bag can hold at most W weight in it]. 
# The target is to put the items into the bag such that the sum of 
# profits associated with them is the maximum possible. 

# Note: The constraint here is we can either put an item completely into the bag or cannot
# put it at all [It is not possible to put a part of an item into the bag].


#-------------brute force (recursive)------------ TLE

def Knapsack(wt, val, idx, cap):
    if idx == 0:
        if wt[0] <= cap:
            return val[0];
        else:
            return 0;
    include = 0
    if wt[idx] <= cap:
        include = val[idx] + Knapsack(wt, val, idx-1, cap-wt[idx])
    
    exclude = Knapsack(wt, val, idx-1, cap)
    
    return max(include, exclude)

wt = [1, 2, 4, 5]
val = [5, 4, 8, 6]
n = len(wt)
maxCapacity = 5
print(Knapsack(wt, val, n-1, maxCapacity))




#----------------optimized (DP - memo)---------------- O(N*W)

dp = [[-1]*(maxCapacity+1) for i in range(n)]

def KnapsackDP(wt, val, idx, cap, dp):
    if idx == 0:
        if wt[0] <= cap:
            return val[0];
        else:
            return 0;
            
    if dp[idx][cap] != -1:
        return dp[idx][cap]
            
    include = 0
    if wt[idx] <= cap:
        include = val[idx] + KnapsackDP(wt, val, idx-1, cap-wt[idx], dp)
    
    exclude = KnapsackDP(wt, val, idx-1, cap, dp)
    
    dp[idx][cap] = max(include, exclude)
    return dp[idx][cap]

print(KnapsackDP(wt, val, n-1, maxCapacity, dp))



#------------------DP - Tabulation-------------O(N*W)

def KnapsackDPTab(wt, val, n, cap):
    
    dp = [[0]*(cap+1) for i in range(n)]
    
    for w in range(wt[0], cap+1):
        if wt[0] <= cap:
            dp[0][w] = wt[0]
        else:
            dp[0][w] = 0
    
    for idx in range(n):
        for w in range(cap+1):
            include = 0
            if wt[idx] <= w:
                include = val[idx] + dp[idx-1][w-wt[idx]]
            exclude = dp[idx-1][w]
            
            dp[idx][w] = max(include, exclude)
    
    return dp[n-1][cap]
    
print(KnapsackDPTab(wt, val, n, maxCapacity))




#----------------optimized DP-Tabulation---------------O(2*W)


def KnapsackDPTab(wt, val, n, cap):
    
    # dp = [[0]*(cap+1) for i in range(n)]
    prev = [0]*(cap+1)
    cur = [0]*(cap+1)
    
    for w in range(wt[0], cap+1):
        if wt[0] <= cap:
            prev[w] = wt[0]
        else:
            perv[w] = 0
    
    for idx in range(n):
        for w in range(cap+1):
            include = 0
            if wt[idx] <= w:
                include = val[idx] + prev[w-wt[idx]]
            exclude = prev[w]
            
            cur[w] = max(include, exclude)
        
        prev = cur[::]
    
    return prev[cap]
    
print(KnapsackDPTab(wt, val, n, maxCapacity))

            
                
    
