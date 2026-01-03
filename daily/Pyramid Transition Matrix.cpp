// Pyramid Transition Matrix

// You are stacking blocks to form a pyramid. Each block has a color, which is represented by a single letter. 
// Each row of blocks contains one less block than the row beneath it and is centered on top.

// To make the pyramid aesthetically pleasing, there are only specific triangular patterns that are allowed. 
// A triangular pattern consists of a single block stacked on top of two blocks. The patterns are given as a list of three-letter strings allowed, 
// where the first two characters of a pattern represent the left and right bottom blocks respectively, and the third character is the top block.

// For example, "ABC" represents a triangular pattern with a 'C' block stacked on top of an 'A' (left) and 'B' (right) block. 
// Note that this is different from "BAC" where 'B' is on the left bottom and 'A' is on the right bottom.
// You start with a bottom row of blocks bottom, given as a single string, that you must use as the base of the pyramid.

// Given bottom and allowed, return true if you can build the pyramid all the way to the top
// such that every triangular pattern in the pyramid is in allowed, or false otherwise.


//LOGIC:
//We begin building the pyramid from the allowed bases. We take the first two letters of the string as they form the left and right of the base and
// the third letter forms the top. So first we store the first two in the map and then for each pair like this stored in the map, we try to build
// the pyramid. Basically, we iterate through each such pair and then compute the top in a sliding window manner. 
// After we reach the last index of the base, we move to the top and continue with that as the base. 
// If we reach length of 1, that means we have placed the final top block of the pyramid and return true. 

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    unordered_map<string, bool>t;
    bool solve(unordered_map<string, vector<char>>&mp, int index, string above, string current)
    {
        if(current.length()==1)
            return true;
        string key = current + "_" + to_string(index) + "_" + above;
        if(t.count(key))
            return t[key];
        if(index==current.length()-1)
            return t[key] = solve(mp, 0, "", above);
        string pair = current.substr(index, 2);
        if(mp.find(pair)==mp.end())
            return t[key] = false;
        for(char ch:mp[pair])
        {
            above.push_back(ch);
            if(solve(mp, index+1, above, current))
                return t[key] = true;
            above.pop_back();
        }
        return t[key] = false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>>mp;
        for(auto it:allowed)
            mp[it.substr(0, 2)].push_back(it[2]);
        return solve(mp, 0, "", bottom);
    }
};