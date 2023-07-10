# pascal's Triangle =>  [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1],...]
def printPascalTriangle(n):
    ans = [[1]]
    for i in range(n):
        temp = [0] + ans[-1] + [0]
        row = []
        for j in range(len(ans[-1])+1):
            row.append(temp[j] + temp[j+1])
        ans.append(row)
    print(ans)

printPascalTriangle(5)

# for specific element nCr or 11^r 

# nCr :

def pascalVal(r,c):#row:r and col:c in pascla's triangle val = rCc
    #pascal's triangle = [[1],[1,1],[1,3,3,1],[1,4,6,4,1]...]
    
    n,d = 1,1
    temp = r
    
    for i in range(c):
        n *= temp
        temp -= 1
    for i in range(c,1,-1):
        d *= i
        
    return n//d

print(pascalVal(5,2))


#---------------------OR --------------------------

def nCr(n,r):
    ans = 1
    for i in range(r):
        ans *= (n-i)
        ans //= (i+1)
    return ans
print(nCr(5,2))


#------------------------------------------------\
# variation : print Nth Row of PascalTriangle

def nCr(n,r):
    ans = 1
    for i in range(r):
        ans *= n-i
        ans //= i+1
    return ans
    
    
def printNthRowofPascaltriangle(n):
    row = [0]*(n+1)
    for c in range(n+1):
        row[c] =  nCr(n,c)
    return row

print(printNthRowofPascaltriangle(4))
