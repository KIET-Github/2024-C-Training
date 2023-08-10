# LIS : Longest Increasing Subsequence

# -> Given an array arr[] of size N, the task is to find the length of the Longest Increasing Subsequence (LIS) 
# i.e. the longest possible subsequence in which the elements of the subsequence are sorted in increasing order.


from bisect import bisect_left 

def LISlength(nums):
    sub = []
    for x in nums:
        if len(sub) == 0 or sub[-1] < x:
            sub.append(x)
        else:
            idx = bisect_left(sub, x)
            sub[idx] = x
    return len(sub)
    
arr = [10,9,2,5,3,7,101,18]
print("Length of LIS is:", LISlength(arr))


#---------------without using bisect------------

def LISalgo(arr):
    n = len(arr)
    lis = [1]*n
    for i in range(1, n):
        for j in range(0, i):
            if arr[i] > arr[j] and lis[i] < lis[j]+1:
                lis[i] = lis[j]+1
    mx = 0
    for i in range(n):
        mx = max(mx, lis[i])
    return mx
    
arr = [10,9,2,5,3,7,101,18]
print("Length of LIS is:", LISalgo(arr))
