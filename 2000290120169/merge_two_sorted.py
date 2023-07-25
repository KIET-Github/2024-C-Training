def merge_st(a,b):
        
    k=len(a)

    a=a+b  
    a.sort()
    b=a[k::1]
    a=a[:k]

    print(a)
    print(b)
    print(k)

a=list(map(int,input().split()))
b=list(map(int,input().split()))
print(merge_st(a,b))