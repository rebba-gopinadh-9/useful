def findNext(A):
    for i in range(9):
        for j in range(9):
            if A[i][j]==0:
                return i,j
    return -1,-1

def isOkay(A,x,y,val):
    if x<9 and y<9 and A[x][y]==0:
        for i in range(9):
            if A[x][i]==val:
                return False
        for j in range(9):
            if A[j][y]==val:
                return False
        return True
    return False

def solveSudoku(A,x,y):
    if findNext(A)==(-1,-1):
        return True
    if x< 9 and y<9 and A[x][y]==0:
        for i in range(1,10):
            if isOkay(A,x,y,i):
                A[x][y]=i
                if solveSudoku(A,findNext(A)[0],findNext(A)[1])==True:
                    return True
            A[x][y]=0
    return False

def solve(A):
    a,b=findNext(A)
    if solveSudoku(A,a,b)==False:
        print("No SOLUTION")
        return 
    solveSudoku(A,0,0)
    for i in A:
        print(i)

A=[ [3, 0, 6, 5, 0, 8, 4, 0, 0], 
    [5, 2, 0, 0, 0, 0, 0, 0, 0], 
    [0, 8, 7, 0, 0, 0, 0, 3, 1], 
    [0, 0, 3, 0, 1, 0, 0, 8, 0], 
    [9, 0, 0, 8, 6, 3, 0, 0, 5], 
    [0, 5, 0, 0, 9, 0, 6, 0, 0], 
    [1, 3, 0, 0, 0, 0, 2, 5, 0], 
    [0, 0, 0, 0, 0, 0, 0, 7, 4], 
    [0, 0, 5, 2, 0, 6, 3, 0, 0] ]

solve(A)
