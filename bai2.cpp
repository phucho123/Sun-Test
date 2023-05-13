#include<bits/stdc++.h>
using namespace std;


vector<vector<int>>dir{{1,0},{-1,0},{0,1},{0,-1}};

int solve(vector<vector<int>>&board,int r,int c,int color){
    if(r >= board.size() || c >= board[0].size() || board[r][c] == 0 || board[r][c] != color) return 0;
    board[r][c] = 0;
    int res = 1;
    for(int i = 0;i<4;i++){
        if(r+dir[i][0] < board.size() && c+dir[i][1] < board[0].size()){
            res+=solve(board,r+dir[i][0],c+dir[i][1],color);
        }
    }
    return res;
}
int countExplodedGems(int rows, int cols, vector<vector<int>> gems, vector<vector<int>> hits){
    int res = 0;
    vector<vector<int>>board(rows,vector<int>(cols,0));
    for(int i = 0;i<gems.size();i++){
        board[gems[i][0]][gems[i][1]] = gems[i][2];
    }
    for(int i = 0;i<hits.size();i++){
        res+=solve(board,hits[i][0],hits[i][1],board[hits[i][0]][hits[i][1]]);
    }
    return res;
}
int main(){
    int rows = 7,cols = 12;
    vector<vector<int>>gems{{2, 6, 1},{0, 6, 1},{4, 6, 1},{4, 10, 2},{5, 8, 2},{2, 11, 2},{0, 7, 1},{2, 5, 1},{2, 7, 1},{5, 7, 1},{3, 8, 2},{5, 10, 2},{2, 4, 1},{0, 10, 2},{2, 9, 2},{0, 8, 2},{0, 9, 2},{3, 11, 2},{4, 5, 1},{1, 8, 2},{5, 5, 1},{3, 10, 2},{2, 2, 1},{4, 8, 2},{3, 6, 1},{1, 10, 2},{4, 9, 2},{5, 6, 1},{2, 8, 2},{3, 5, 1},{2, 3, 1},{2, 10, 2},{3, 7, 1},{4, 7, 1},{0, 5, 1}};
    vector<vector<int>>hits{{2, 2}, {2, 9}, {2,2}, {0, 0}, {0, 1}, {0, 2}, {0, 3}};
    cout<<countExplodedGems(rows,cols,gems,hits);
    return 0;
}