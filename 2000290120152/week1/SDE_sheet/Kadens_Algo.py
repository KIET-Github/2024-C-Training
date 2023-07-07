# Kadane’s Algorithm : Maximum Subarray Sum in an Array
# Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
# has the largest sum and returns its sum and prints the subarray.

# max subarray sum (array with both +ve and -ve values)

def kadensAlgo(arr):
        
    ans = float('-inf')
    sm = 0
    
    for i in range(len(arr)):
        
        sm += arr[i]
        
        ans = max(ans, sm)
        
        if sm < 0:
            sm = 0
            
    return ans
    
a = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
print(kadensAlgo(a))


#------------------------------------------------------/
# print the one of subarray with max sum

def printmaxSumSubarray(arr):
    mx = float('-inf')
    sm = 0
    start = 0
    ansStart, ansEnd = 0, 0
    for i in range(len(arr)):
        if sm == 0:
            start = i
            
        sm += arr[i]
        
        if sm > mx:
            mx = sm
            ansStart = start
            ansEnd = i
        
        if sm < 0:
            sm = 0
    ans = arr[ansStart:ansEnd+1]
    return ans
print(printmaxSumSubarray(a))
