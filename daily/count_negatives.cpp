// Count Negative Numbers in a Sorted Matrix
// Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.


//Logic:
// Brute force works fine by cehcking each cell and gives a complexity of O(m*n)

// To optimize for O(m+n), we can start at the bottom left cell. In the grid, as we move to the right, the values become smaller 
// and as we move up, they become larger. So starting from the bottom left, if that value is negative, the values to its right will also be negative, 
// so we add (n-j) to our result and move up. If the value is positive, we simply move to the right to check the smaller value. This results in a staircase
// type checking giving complexity of O(m+n). 

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int i = m-1, j = 0;
        int res = 0;
        while(i>=0 && j<n)
        {
            if(grid[i][j]<0)
            {
                res += n-j;
                i--;
            }
            else
                j++;
        }
        return res;
    }
};