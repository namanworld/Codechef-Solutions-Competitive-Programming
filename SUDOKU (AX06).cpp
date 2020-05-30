#include <bits/stdc++.h>
using namespace std;

#define N 9

bool findEmpty(int grid[N][N], int &row, int &col){
    for(int i=0; i<N; ++i)
    for(int j=0; j<N; ++j){
        if(grid[i][j]==0){
            row = i;
            col = j;
            return true;
        }
    }
    return false;
}

bool saferow(int grid[N][N], int row, int num){
    for(int i=0; i<N; ++i) if(grid[row][i]==num) return false;
    return true;
}

bool safecol(int grid[N][N], int col, int num){
    for(int i=0; i<N; ++i) if(grid[i][col]==num) return false;
    return true;
}

bool safegrid(int grid[N][N], int row, int col, int num){
    int rowfactor = row - row%3;
    int colfactor = col - col%3;
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; j++){
            if(grid[i+rowfactor][j+colfactor]==num) return false;
        }
    }
    return true;
}

bool safe(int grid[N][N], int row, int col, int num){
    return saferow(grid, row, num) && safecol(grid, col, num) && safegrid(grid, row, col, num);
}

bool printSudoku(int grid[N][N]){
    int row, col;
    if(!findEmpty(grid, row, col)) return true;

    for(int i=1; i<=N; ++i){
        if(safe(grid, row, col, i)){
            grid[row][col] = i;
            if(printSudoku(grid)) return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    int grid[N][N];
    for(int i=0; i<N; ++i){
        string s;
        cin>>s;
        for(int j=0; j<N; ++j) grid[i][j] = s[j]-'0';
    }

    printSudoku(grid);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; ++j) cout<<grid[i][j];
        cout<<endl;
    }

    return 0;
}
