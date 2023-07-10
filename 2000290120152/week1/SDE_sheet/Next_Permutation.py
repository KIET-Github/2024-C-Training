# Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the 
# lexicographically next greater permutation of numbers.
# If such an arrangement is not possible, it must rearrange to the 
# lowest possible order (i.e., sorted in ascending order).

def nextPermutation(arr):
    n = len(arr)
    #find break Point:
    bp = -1
    for i in range(n - 2, -1, -1):
        if arr[i] < arr[i+1]:
            bp = i
            break
    
    # if no break point: lowest possible arrangement
    if bp == -1:
        arr.reverse()
        return arr
    
    #if there exist a break point:
    for i in range(n - 1, bp, -1):
        if arr[i] > arr[bp]:
            arr[i], arr[bp] = arr[bp], arr[i]
            break
    arr[bp+1:] = reversed(arr[bp+1:])
    return arr
    
a = [2,1,5,4,3,0,0]
print(nextPermutation(a))
