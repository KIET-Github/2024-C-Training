def total_profit(arr,n):
    profit=0
    
    for i in range(1,n):
        if arr[i]>arr[i-1]:
            profit=profit+arr[i]-arr[i-1]
        
    return profit

arr=list(map(int,input().split()))
n=len(arr) 
print(total_profit(arr,n))

        
