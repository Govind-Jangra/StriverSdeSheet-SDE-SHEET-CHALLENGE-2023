// https://leetcode.com/problems/sudoku-solver/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool safe(vector<vector<char>>& board,char c,int row,int col){
 for (int i = 0; i < 9; i++) {
    if (board[i][col] == c)
      return 0;

    if (board[row][i] == c)
      return 0;

    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return 0;
  }
  return 1;
    
}
bool solve(vector<vector<char>>& board){
    

    for(int x=0;x<9;x++){
        for(int y=0;y<9;y++){
            if(board[x][y]=='.'){
                for(char i='1';i<='9';i++){
                    if(safe(board,i,x,y)){
                        board[x][y]=i;
                        if(solve(board)) return 1;
                            
                         board[x][y]='.';

                    }
                }
                return 0;
            }
        }
    }
    return 1;
}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};