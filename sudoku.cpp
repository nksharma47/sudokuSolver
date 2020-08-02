#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>&board, int row, int col, int n)
{
    int count = 0;
    for(int i=0; i<n; i++)
    {
        if(board[i][col] == board[row][col])
            count++;
    }
    
    for(int i=0; i<n; i++)
    {
        if(board[row][i] == board[row][col])
            count++;
    }
    
    int block_row = (row/3)*3;
    int block_col = (col/3)*3;
    
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[block_row + i][block_col + j] == board[row][col])
                count++;
        }
    }
    
    if(count == 3)
        return true;
        
    return false;
}

bool solveSudoku(vector<vector<int>>&board, int row, int col, int n)
{
    if(col == n)
    {
        col = 0;
        row++;
    }
    
    if(row == n)
        return true;
        
    if(board[row][col] == 0)
    {
        for(int i=1; i<=9; i++)
        {
            board[row][col] = i;
            if(isSafe(board, row, col, n) && solveSudoku(board, row, col+1, n))
                return true;
            board[row][col] = 0;
        }
    }
    else
        return solveSudoku(board, row, col+1, n);
    
    return false;
}

void print(vector<vector<int>>&board)
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cout<<board[i][j]<<" ";
        }
        // cout<<endl;
    }
    cout<<endl;
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<vector<int>>board(9,vector<int>(9));
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                cin>>board[i][j];
            }
        }
        
        if(solveSudoku(board, 0, 0, 9))
            print(board);
        else
            cout<<"-1\n";
    }
	//code
	return 0;
}
