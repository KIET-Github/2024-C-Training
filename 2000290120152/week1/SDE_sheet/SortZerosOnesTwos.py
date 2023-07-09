# Problem Statement: Given an array consisting of only 0s, 1s, and 2s. 
# Write a program to in-place sort the array without using inbuilt sort functions. 
# ( Expected: Single pass-O(N) and constant space)



def sortwithCount(arr):
    n = len(arr)
    cnt = [0]*3
    for i in range(n):
        if arr[i] == 0:
            cnt[0] += 1
        elif arr[i] == 1:
            cnt[1] += 1
        else:
            cnt[2] += 1
    for i in range(cnt[0]):
        arr[i] = 0
    for i in range(cnt[0],cnt[0]+cnt[1]):
        arr[i] = 1
    for i in range(cnt[0]+cnt[1],cnt[0]+cnt[1]+cnt[2]):
        arr[i] = 2
x = [2,0,2,1,1,0,1,0]
sortwithCount(x)
print(x)




# ----------------------------OR----------------------------------





def sortZerosOnesTwos(arr):
    # Dutch National flag algorithm
    # using three pointers
    n = len(arr)
    low, mid, high = 0, 0, n - 1
    
    while(mid <= high):
        if arr[mid] == 0:
            arr[low], arr[mid] = arr[mid], arr[low]
            low += 1
            mid += 1
        elif arr[mid] == 1:
            mid += 1
        else:
            arr[mid], arr[high] = arr[high], arr[mid]
            high -= 1

a = [2,0,2,1,1,0,1,0]
sortZerosOnesTwos(a)
print(a)
