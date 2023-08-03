# Unbounded Knapsack (Item Repetition allowed)

# Given a knapsack weight W and a set of n items with certain value vali and weight wti, 
# we need to calculate the maximum amount that could make up this quantity exactly.


# --------------Recursive----------------

def UnboundedKnapsack(W, idx, Val, wt):
    if idx == 0:
        return (W//wt[0])*val[0]
    no = 0 + UnboundedKnapsack(W, idx-1, val, wt)
    yes = -100000
    if wt[idx] <= W:
        yes = val[idx] + UnboundedKnapsack(W-wt[idx], idx, val, wt)
    return max(yes, no)
    
W = 20
val = [5, 20, 12]
wt = [1, 4, 3]
n = len(val)
print(UnboundedKnapsack(W, len(val)-1, val, wt))

# --------------Memoization--------------------


def UnboundedKnapsackMemo(W, wt, val, idx, dp):
    if idx == 0:
        return (W//wt[0])*val[0]
    if dp[idx][W] != -1:
        return dp[idx][W]
    no = UnboundedKnapsackMemo(W, wt, val, idx-1, dp)
    yes = float('-inf')
    if wt[idx] <= W:
        yes = val[idx] + UnboundedKnapsackMemo(W-wt[idx], wt, val, idx, dp)
    dp[idx][W] = max(yes, no)
    return dp[idx][W]
    
dp = [[-1 for i in range(W+1)] for i in range(n)]
print(UnboundedKnapsackMemo(W, wt, val, n-1, dp))



# --------------Tabulation-------------

def UnboundedKnapsackTab(W, n, val, wt):
    dp = [0 for i in range(W + 1)]
    ans = 0
    
    for i in range(W+1):
        for j in range(n):
            if wt[j] <= i:
                dp[i] = max(dp[i], dp[i-wt[j]]+val[j])
    return dp[W]
    
print(UnboundedKnapsackTab(W, n, val, wt))
