// Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

// Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

// Note that you need to maximize the answer before taking the mod and not after taking it.


// Logic:
// Basically we need to find total sum and then calculate (totalsum-cursum)*cursum for every node and update maxi.
// Removing an edge above a node means:

// One subtree = entire subtree rooted at that node

// Other subtree = rest of the tree

// So for every node, if you cut the edge connecting it to its parent: Product =(subtree sum)*(total sum-subtree sum)
// Hence, the problem reduces to:
// Compute the sum of every subtree, and find the one that maximizes S*(T-S)


class Solution {
public:
    long long MOD = 1e9 + 7;
    long long maxi = 0;
    long long dfs(TreeNode* root)
    {
        if(!root)
            return 0;
        root->val += dfs(root->left) + dfs(root->right);
        return root->val;
    }

    int maxProduct(TreeNode* root) {
        long long total = dfs(root);

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) continue;

            long long cur = (total - node->val) * node->val;
            maxi = max(maxi, cur);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        return maxi % MOD;
    }
};