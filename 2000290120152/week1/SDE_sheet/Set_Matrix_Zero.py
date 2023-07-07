# Problem Statement: Given a matrix if an element in the matrix is 0 then
# you will have to set its entire column and row to 0 and then return the matrix.

def SetMatrixZero(matrix):
    n, m = len(matrix), len(matrix[0])
    row = [0] * n
    col = [0] * m
    
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 0:
                row[i] = 1
                col[j] = 1
    
    for i in range(n):
        for j in range(m):
            if row[i] == 1 or col[j] == 1:
                matrix[i][j] = 0
    return matrix
