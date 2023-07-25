n,m=map(int,input().split())
matrix=[]
for _ in range(n):
    t=list(map(int,input().split()))
    matrix.append(t)
for i in range(n):
    for j in range(i):
        matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
# reversing each row of the matrix
for i in range(n):
    matrix[i].reverse()
print(matrix)