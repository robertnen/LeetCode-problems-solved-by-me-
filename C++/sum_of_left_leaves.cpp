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
 * Runtime: beats 100% of users with C++
 * Memory: beats 81.87% of users with C++
 * Daily problem (Streak 61)
*/

class Solution {
private:
    int ans = 0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        inorder(root);

        return ans;
    }

    void inorder(TreeNode* root) {
        if(!root) return;

        inorder(root->left);

        if(root->left && !root->left->left && !root->left->right) ans += root->left->val;

        inorder(root->right);
    }
};