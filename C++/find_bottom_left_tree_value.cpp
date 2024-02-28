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
 * Runtime: beats 90.18% of users with C++
 * Memory: beats 88.43% of users with C++
 * Daily problem (Streak 15)
*/

class Solution {
private:
    int value = INT_MIN;
    int height = -1;
public:
    void dfs(TreeNode* root, int height) {
        if(!root) return;
        if(!root->left && !root->right) {
            if(height > this->height) {
                value = root->val;
                this->height = height;
            }
        }

        dfs(root->left, height + 1);
        dfs(root->right, height + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return value;
    }
};