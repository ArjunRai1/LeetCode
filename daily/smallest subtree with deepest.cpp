// Smallest Subtree with all the Deepest Node
// Given the root of a binary tree, the depth of each node is the shortest distance to the root.

// Return the smallest subtree such that it contains all the deepest nodes in the original tree.

// A node is called the deepest if it has the largest depth possible among any node in the entire tree.

// The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.


// //Logic:
// Perform dfs to get the max depth of all nodes from the root. At each recursion, check for maxdepth and update lca as the root
// if the depth of left and right subtree is the same. If not same, the deeper one is the lca



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth = 0;
    TreeNode* lca = NULL;
    int helper(TreeNode* root, int depth)
    {
        maxDepth=max(maxDepth, depth);
        if(!root) 
            return depth;
        int l = helper(root->left, depth+1);
        int r = helper(root->right, depth+1);
        if(l==maxDepth && r==maxDepth) 
            lca=root;
        return max(l, r);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        helper(root, 0);
        return lca;
    }
};