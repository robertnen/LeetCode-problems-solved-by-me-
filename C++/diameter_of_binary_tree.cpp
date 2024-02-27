#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Runtime: beats 35.06% of users with C++
 * Memory: beats 44.95% of users with C++
 * Daily problem (Streak 14)
*/

class Solution {
private:
    int height = 0;
public:
    int dfs(TreeNode *root) {
        if(!root) return 0;
        int left, right;

        left = dfs(root->left);
        right = dfs(root->right);
        height = std::max(height, left + right);
        return std::max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return height;
    }
};