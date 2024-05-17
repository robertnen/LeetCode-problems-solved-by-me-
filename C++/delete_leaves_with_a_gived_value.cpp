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
 * Runtime: beats 9.51% of users with C++
 * Memory: beats 98.58% of users with C++
 * Daily problem (Streak 94)
*/

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return NULL;
        if(!root->left && !root->right)
            if(root->val == target) return NULL;
            else return root;

        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        if(!root->left && !root->right && root->val == target) return NULL;

        return root;
    }
};
