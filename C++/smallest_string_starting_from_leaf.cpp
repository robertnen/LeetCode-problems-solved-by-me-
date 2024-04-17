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
 * Runtime: beats 65.38% of users with C++
 * Memory: beats 67.10% of users with C++
 * Daily problem (Streak 64)
*/

class Solution {
public:
    std::string smallestFromLeaf(TreeNode* root) {
        std::string ans;

        dfs(root, "", ans);

        return ans;
    }

    void dfs(TreeNode *root, std::string path, std::string &ans) {
        if(!root) return;

        path += 'a' + root->val;

        if(!root->left && !root->right) {
            path = std::string(path.rbegin(), path.rend());

            if(ans.empty() || path < ans) ans = path;

            std::reverse(path.begin(), path.end());
        }

        dfs(root->left, path, ans);
        dfs(root->right, path, ans);
    }
};