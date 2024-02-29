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
 * Runtime: beats 69.24% of users with C++
 * Memory: beats 69.10% of users with C++
 * Daily problem (Streak 16)
*/

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(!(root->val % 2)) return false;

        std::queue<TreeNode*> q, p;
        bool isEven = true;
        TreeNode *node_1, *node_2;
        q.push(root);

        while(!q.empty()) {
            node_1 = q.front();

            if(isEven && !(node_1->val % 2)) return false;
            if(!isEven && node_1->val % 2) return false;
            q.pop();

            if(node_1->left) p.push(node_1->left);
            if(node_1->right) p.push(node_1->right);

            while(!q.empty() && isEven) {
                node_2 = q.front();
                if(!(node_2->val % 2)) return false;
                q.pop();

                if(node_1->val >= node_2->val) return false;
                if(node_2->left) p.push(node_2->left);
                if(node_2->right) p.push(node_2->right);
                node_1->val = node_2->val;
            }

            while(!q.empty() && !isEven) {
                node_2 = q.front();
                if(node_2->val % 2) return false;
                q.pop();

                if(node_1->val <= node_2->val) return false;
                if(node_2->left) p.push(node_2->left);
                if(node_2->right) p.push(node_2->right);
                node_1->val = node_2->val;
            }

            isEven = !isEven;
            q.swap(p);
        }
        return true;
    }
};