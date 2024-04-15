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
 * Runtime: beats 26.49% of users with C++
 * Memory: beats 96.99% of users with C++
 * Daily problem (Streak 62)
*/

class Solution {
private:
    int sum = 0;
public:
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);

        return sum;
    }

    void dfs(TreeNode* root, int n) {
        if(!root) return;

        if(!root->left && !root->right) {
            sum += n * 10 + root->val;
            return;
        }

        dfs(root->left, n * 10 + root->val);
        dfs(root->right, n * 10 + root->val);
    }
};