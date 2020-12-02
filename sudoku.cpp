#include <iostream>
using namespace std;
#define N 9
void print(int arr[N][N]){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}
bool isSafe(int A[N][N],int r,int c,int val){
    for (int i=0;i<N;i++){
        if (A[r][i]==val)
            return false;
    }
    for (int i=0;i<N;i++){
        if (A[i][c]==val)
            return false;
    }
    int r1=r-r%3,c1=c-c%3;
    for (int i=r1;i<r1+3;i++){
        for (int j=c1;j<c1+3;j++){
            if (A[i][j]==val)
                return false;
        }
    }
    return true;
}
bool solveSudoku(int A[N][N],int r,int c){
    if (r==N-1 && c==N)
        return true;
    if (c==N){
        c=0;
        r++;
    }
    if (A[r][c]>0)
        return solveSudoku(A,r,c+1);
    for (int k=1;k<10;k++){
        if (isSafe(A,r,c,k)){
            A[r][c]=k;
            if (solveSudoku(A,r,c+1)){
                return true;
            }
        }
        A[r][c]=0;
    }
    return false;
}
int main(){
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
					{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
					{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
					{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
					{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
					{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
					{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

	if (solveSudoku(grid, 0, 0))
		print(grid);
	else
		cout << "no solution exists " << endl;

	return 0;
}
