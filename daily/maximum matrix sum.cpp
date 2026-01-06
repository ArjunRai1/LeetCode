// You are given an n x n integer matrix. You can do the following operation any number of times:

// Choose any two adjacent elements of matrix and multiply each of them by -1.
// Two elements are considered adjacent if and only if they share a border.

// Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.


// Logic:
// Count the number of negative elements - if even, all of them can be made positive and if odd, one will remain negative. The goal is to make sure
// that the one remaining has the lowest absolute value

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int c = 0;
        int mini = INT_MAX;
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0) c++;

                mini = min(mini, abs(matrix[i][j]));
            }
        }
        
        if(c % 2) sum -= 2*mini;
        
        return sum;
    }
};