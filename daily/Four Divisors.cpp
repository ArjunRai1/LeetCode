// Four Divisors
// Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. 
// If there is no such integer in the array, return 0.

// Logic:
// Basically for each number present in the array, find its factors. We use sieve of eratosthenes here. Also we need to keep in mind that
// if we find a fact1 that divides a num, then there also exists a fact2 num/fact1 of that number and hence we obtain a pair. In case of perfect 
// squares, be careful not to add two factors like this as it will be repeated 

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int num)
    {
        int sum = 0, divisors = 0;
        for(int i = 1; i*i<=num; i++)
        {
            if(num%i==0)
            {
                int other = num/i;
                if(other==i)
                {
                    divisors += 1;
                    sum += i;
                }
                else
                {
                    divisors += 2;
                    sum += other+i;
                }
            }
            if(divisors>4)
                break;
        }
        return divisors==4?sum:0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for(int i:nums)
        {
            res += solve(i);
        }
        return res;
    }
};