#1 KANPSACK ALGORITHM
def knapSack(W, wt, val): 
    n=len(val)
    table = [[0 for x in range(W + 1)] for x in range(n + 1)] 
 
    for i in range(n + 1): 
        for j in range(W + 1): 
            if i == 0 or j == 0: 
                table[i][j] = 0
            elif wt[i-1] <= j: 
                table[i][j] = max(val[i-1]  
+ table[i-1][j-wt[i-1]],  table[i-1][j]) 
            else: 
                table[i][j] = table[i-1][j] 
   
    return table[n][W] 
 
val = [50,107,170,200]
wt = [8,16,72,40]
W = 64
 
print(knapSack(W, wt, val))


#2 LONGEST_COMMON_SUBSEQUENCE ALGORITHM
def longest_common_subsequence(string1, string2):
    m, n = len(string1), len(string2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if string1[i - 1] == string2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    lcs = []
    i, j = m, n
    while i > 0 and j > 0:
        if string1[i - 1] == string2[j - 1]:
            lcs.append(string1[i - 1])
            i -= 1
            j -= 1
        elif dp[i - 1][j] > dp[i][j - 1]:
            i -= 1
        else:
            j -= 1

    return ''.join(reversed(lcs))
string1 = "ABCDGH"
string2 = "AEDFHR"
print(longest_common_subsequence(string1, string2))  


#3 MATRIX CHAIN MULTIPLICATION ALGORITHM
def matrix_chain_multiplication(dimensions):
    n = len(dimensions) - 1
    dp = [[float('inf')] * (n + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        dp[i][i] = 0

    for length in range(2, n + 1):
        for i in range(1, n - length + 2):
            j = i + length - 1
            for k in range(i, j):
                cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j]
                dp[i][j] = min(dp[i][j], cost)

    return dp[1][n]

dimensions = [10, 30, 5, 60]
print(matrix_chain_multiplication(dimensions)) 


#4 UNBOUNDED KANPSACK
def unbounded_knapsack(items, knapsack_capacity):
    dp = [0] * (knapsack_capacity + 1)

    for i in range(1, knapsack_capacity + 1):
        for item in items:
            weight, value = item
            if weight <= i:
                dp[i] = max(dp[i], dp[i - weight] + value)

    return dp[knapsack_capacity]
items = [(2, 10), (3, 15), (5, 30)]
knapsack_capacity = 8
print(unbounded_knapsack(items, knapsack_capacity))  


#5 LONGEST INCREASING SUBSEQUENCE ALGORITHM
def lis(arr):
    n = len(arr)
    lis_lengths = [1] * n 

    for i in range(1, n):
        for j in range(i):
            if arr[i] > arr[j]:
                lis_lengths[i] = max(lis_lengths[i], lis_lengths[j] + 1)

    return max(lis_lengths)

arr = [10, 22, 9, 33, 21, 50, 41, 60, 80]
print(lis(arr))  


