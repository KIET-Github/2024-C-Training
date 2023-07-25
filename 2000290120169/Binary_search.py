
def binary_search(arr, l, r, x):
    if l <= r:
        mid = l+(r-l)//2

        if arr[mid] == x:
            return mid
        if x > arr[mid]:
            return binary_search(arr, mid+1, r, x)
        else:
            return binary_search(arr, l, mid-1, x)
    return -1

arr = [2,3,5,6,7,8,9] #sorted arr
x = 5
findx = binary_search(arr, 0,len(arr)-1, x)

if findx == -1:
    print(x, "Not Found !!")
else:
    print(x, "Found at index: ", findx)


#Iterative Binary Search

def binary_search(arr, l, r, x):
    while l <= r:
        mid = l+(r-l)//2

        if arr[mid] == x:
            return mid
        if x > arr[mid]:
            l = mid + 1
        else:
            r = mid-1
    return -1

arr = [2,3,5,6,7,8,9] #sorted arr
x = 5
findx = binary_search(arr, 0,len(arr)-1, x)

if findx == -1:
    print(x, "Not Found !!")
else:
    print(x, "Found at index: ", findx)