

def sum_arr(arr):
    curr_sum=0
    max_sum=0
    for i in range (len(arr)):
        curr_sum=curr_sum+arr[i]
        if curr_sum >max_sum:
            max_sum=curr_sum
        
        elif curr_sum<0:
            curr_sum=0 
    return max_sum

k=list(map(int,input().split()))
print(sum_arr(k))