def buy_sell(arr,n):
    aux=[]
    m=0
    for i in range(n):
        if arr[n-i-1]>m:
            aux.append(arr[n-i-1])
            m=arr[n-i-1]
        else:
            aux.append(m)
    aux.reverse()
    profit=0
    for i in range(n):
        k=aux[i]-arr[i]  
        if k>profit:
            profit=k 
    return profit

arr=list(map(int,input().split()))
n=len(arr) 
print(buy_sell(arr,n))

