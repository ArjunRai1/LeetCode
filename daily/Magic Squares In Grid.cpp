// A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

// Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?

// Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

//Logic:
//Simple sliding window approach - slide over all 3x3 matrices and check for the given conditions and increment count as needed
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool solve(vector<vector<int>>& grid, int r, int c)
    {
        unordered_set<int>st;
        for(int i = 0; i<3; i++)
        {
            for(int j = 0; j<3; j++)
            {
                int num = grid[r+i][c+j];
                if(st.find(num)!=st.end() || num<1 || num>9)
                    return false;
                else
                    st.insert(num);
            }
        }
        int sum = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        for(int i = 0; i<3; i++)
        {
            if(grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2]!=sum)
                return false;
            if(grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i]!=sum)
                return false;
        }
        if(grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2]!=sum)
            return false;
        if(grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c]!=sum)
            return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int res = 0;
        for(int i = 0; i<=r-3; i++)
        {
            for(int j = 0; j<=c-3; j++)
                if(solve(grid, i, j))
                    res++;
        }
        return res;
    }
};