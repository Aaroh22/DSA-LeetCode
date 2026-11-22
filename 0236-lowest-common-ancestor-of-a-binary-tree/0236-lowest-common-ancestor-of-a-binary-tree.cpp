
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* LCA;

    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == NULL)
            return NULL;

        TreeNode* left = findLCA(root->left, p, q);

        TreeNode* right = findLCA(root->right, p, q);

        if ( left != NULL && right != NULL) 
            LCA = root;
        else if ( (left != NULL || right != NULL ) && (root == p || root == q) )
            LCA = root; 

        if ( (root == p || root == q) || (left != NULL || right != NULL) )
            return root;
        else
            return NULL;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        findLCA(root, p, q);

        return LCA;
    }
};
