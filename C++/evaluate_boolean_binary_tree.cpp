#include <bits/stdc++.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Runtime: beats 93.93% of users with C++
 * Memory: beats 75.72% of users with C++
 * Daily problem (Streak 92)
*/

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(!root->val || root->val == 1) return root->val == true;
        if(root->val == 2) return evaluateTree(root->left) || evaluateTree(root->right);
        if(root->val == 3) return evaluateTree(root->left) && evaluateTree(root->right);

        return false;
    }
};