row, col= map(int, input().split())

matrix = []
for i in range(row):
    matrix.append(str(input()))

def surrounded_bomb(x,y):
    count=0
    if x>0: #위
        if matrix[x-1][y]=='*':
            count+=1
    if x+1<row: #아래
        if matrix[x+1][y]=='*':
            count+=1
    if y>0: #왼쪽
        if matrix[x][y-1]=='*':
            count+=1 
    if y+1<col: #오른쪽
        if matrix[x][y+1]=='*':
            count+=1

    if x>0 and y>0: #왼쪽 위
        if matrix[x-1][y-1]=='*':
            count+=1
    if x>0 and y+1<col: #오른쪽 위
        if matrix[x-1][y+1]=='*':
            count+=1
    if x+1<row and y>0: #왼쪽 아래
        if matrix[x+1][y-1]=='*':
            count+=1
    if x+1<row and y+1<col: #오른쪽 아래
        if matrix[x+1][y+1]=='*':
            count+=1
    return count

for i in range(row):
    for j in range(col):
        if matrix[i][j]=='*':
            print(matrix[i][j],end='')
        else:
            print(surrounded_bomb(i,j),end='')
    print()

