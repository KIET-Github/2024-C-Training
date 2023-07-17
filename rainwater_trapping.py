def max_water(arr,n):
    l=[]
    r=[]
    lm,rm=0,0
    for i in range(0,n):
        if lm<arr[i] and rm<arr[n-1-i]:
            l.append(arr[i])
            r.append(arr[n-1-i])
            lm=arr[i]
            rm=arr[n-1-i]
        elif lm>arr[i] and rm<arr[n-1-i]:
            l.append(lm)
            r.append(arr[n-1-i])
            
            rm=arr[n-1-i]
        elif lm<arr[i] and rm>arr[n-1-i]:
            l.append(arr[i])
            r.append(rm)
            
            lm=arr[i]
        else:
            l.append(lm)
            r.append(rm)
    r.reverse()
    ans=0
    for i in range(n):
        ans=ans+min(l[i],r[i])-arr[i]
    return ans


arr=list(map(int,input().split()))
n=len(arr)
print(max_water(arr,n))