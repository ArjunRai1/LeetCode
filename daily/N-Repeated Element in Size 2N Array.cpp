// First of all, understand that we just need to find the first & only repeating element.

// Logic:
//Can be done with a simple map as well but the below logic takes O(1) extra space and is more efficient
// Since Boyer-Moore's Voting Algorithm is valid only for elements appearing more than ⌊n/2⌋ times,
//  and here in the question the majority element is appearing exactly n/2 times, so we can't apply the algorithm directly. 
//  Instead, what we can do is check & return if any of the first three elements are repeating. 
//  If not we'll apply the algorithm from i=3 to i<n. Hence we'll get our answer.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int repeatedNTimes(vector<int>& arr) {
        // O(1) Space
        int n = arr.size();
        if(arr[0] == arr[1]) return arr[0];
        if(arr[0] == arr[2] || arr[1] == arr[2]) return arr[2];
        // Moore Voting Algorithm
        int ans, freq = 0;
        for(int i=3; i<n; i++){
            if(freq == 0) ans = arr[i];
            if(arr[i] == ans) freq++;
            else freq--;
        }
        return ans;
    }
};