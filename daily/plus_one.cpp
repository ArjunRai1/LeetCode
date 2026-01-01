// Plus One
// You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
// Increment the large integer by one and return the resulting array of digits.


// //Logic:
// Firstly start from the last digit as we have to increment the number by one. If that digit is less than 9, we can simply add 1 and return.
// If it is equal to 9, we make that digit 0 and move i backwards. The while loop also handles the case if the number is like 19, 199 because
// in this case, we make the 9s to 0s and carry part is handles by the if condition inside the while loop. Lastly, we check the case if all
// digits are 9s, in which we make them 0 and insert a 1 at the beginning.



#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        while(i>=0)
        {
            if(digits[i]<9)
            {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
            i--;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};