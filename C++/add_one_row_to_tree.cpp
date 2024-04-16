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
 * Runtime: beats 40.93% of users with C++
 * Memory: beats 49.35% of users with C++
 * Daily problem (Streak 63)
*/

class Solution {
private:
    TreeNode* addLevel(TreeNode *root, int val, int depth, int step) {
        if(!root) return NULL;

        if(step == depth - 1) {
            TreeNode *left = root->left, *right = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left = left;
            root->right->right = right;

            return root;
        }

        root->left = addLevel(root->left, val, depth, step + 1);
        root->right = addLevel(root->right, val, depth, step + 1);

        return root;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode *node = new TreeNode(val);
            node->left = root;

            return node;
        }

        return addLevel(root, val, depth, 1);
    }
};