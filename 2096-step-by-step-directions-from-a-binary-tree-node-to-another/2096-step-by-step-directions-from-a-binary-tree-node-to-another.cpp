// Do lc 236 lowest common ancestor(IMP) before this , then u will understand
// the logic

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
    string ans = "";
    string startst = "";
    string endst = "";
    TreeNode* start = new TreeNode(-1);
    TreeNode* end = new TreeNode(0);

    TreeNode* finddirections(TreeNode* root, int startValue, int destValue) {

        if (root == NULL)
            return NULL;

        TreeNode* left = finddirections(root->left, startValue, destValue);
        TreeNode* right = finddirections(root->right, startValue, destValue);

        if ((left && right) || ((left || right) && (root->val == startValue ||
                                                    root->val == destValue))) {

            if (left == end)
                endst += 'L';
            else if (right == end)
                endst += 'R';

            reverse(endst.begin(), endst.end());

            ans = startst + endst;
        }

        if (root->val == startValue) {
            start = root;
            startst += 'U';
            return start;
        } else if (left == start || right == start) {
            startst += 'U';
            return start;
        } else if (root->val == destValue) {
            end = root;
            return end;
        } else if (left == end) {
            endst += 'L';
            return end;
        } else if (right == end) {
            endst += 'R';
            return end;
        } else
            return NULL;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {

        finddirections(root, startValue, destValue);

        return ans;
    }
};