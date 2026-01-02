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

//Another better way:
//Pigeonhole Principle
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (int i = 0; i < A.size() - 2; ++i)
            if (A[i] == A[i + 1] || A[i] == A[i + 2])
                return A[i];
        return A.back();
    }
};

// Intuition
// The array contains 2n elements where one element repeats n times and all others appear once. This means the repeated element occupies exactly half the array.

// The pigeonhole principle tells us that if we place n items into 2n slots, certain patterns become impossible to avoid.

// Given all other elements are distinct:

// Thus, within some subsequence (or a subarray), the repeated element must appear more than 50%.
// Proof by Pigeonhole Principle:
// The repeated element takes up n out of 2n positions (50% of the array)
// Pick the smallest useful subarray (window size: 3)
// Then, we have 3 slots to check:
// With 50% density throughout the array, at least 2 of these 3 slots must contain the repeated element.
// Essentially:
// Check if position i matches position i+1 or position i+2. This covers all possible 3-element windows.


// Edge Case
// Since we ignored out-of-bounds windows:

// There must be some case where we can't find a comparison match:
// However, the problem is guranteed to return the repeating element:

// The only remaining unchecked candidate is the last element:
// Therefore, it must be the repeated value.
// Algorithm
// For each position i from 0 to length−2:

// Check if A[i]=A[i+1]. If yes, return A[i]
// Check if A[i]=A[i+2]. If yes, return A[i]
// If no match found in loop, return the last element.

// This handles patterns like [x,a,b,x] where the repeated element is at positions 0 and 3.
// The algorithm exploits the mathematical guarantee that the repeated element cannot be spread too far apart.

// Within every 3-element window, at least two positions must contain the repeated element.

// Time Complexity: O(n)
// Space Complexity: O(1)