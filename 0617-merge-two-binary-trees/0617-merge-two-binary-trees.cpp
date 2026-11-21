/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        if (root1 == NULL)
            return root2;

        if (root2 == NULL)
            return root1;

        queue<TreeNode*> q1, q2;
        int size = 0;
        TreeNode* curr1;
        TreeNode* curr2;

        root1->val = root1->val + root2->val;
        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty()) {

            size = max(q1.size(), q2.size());

            for (int i = 0; i < size; i++) {

                curr1 = q1.front(), q1.pop();
                curr2 = q2.front(), q2.pop();

                if (curr1->left && curr2->left) {

                    curr1->left->val = curr1->left->val + curr2->left->val;
                    q1.push(curr1->left);
                    q2.push(curr2->left);

                } else if (!curr1->left && curr2->left)
                    curr1->left = curr2->left;

                if (curr1->right && curr2->right) {

                    curr1->right->val = curr1->right->val + curr2->right->val;
                    q1.push(curr1->right);
                    q2.push(curr2->right);

                } else if (!curr1->right && curr2->right)
                    curr1->right = curr2->right;
            }
        }

        return root1;
    }
};