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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Approach 1 : Recursive Approach
        // int parentVal = root->val;
        // int pVal = p->val;
        // int qVal = q->val;
        // if(pVal > parentVal && qVal > parentVal) {
        //     return lowestCommonAncestor(root->right, p, q);
        // } else if(pVal < parentVal && qVal < parentVal) {
        //     return lowestCommonAncestor(root->left, p, q);
        // } else {
        //     return root;
        // }

        // Approach 2 : Iterative Approach
        int pVal = p->val;
        int qVal = q->val;
        TreeNode* node = root;
        while(node!= NULL) {
            int parentVal = node->val;
            if(pVal > parentVal && qVal > parentVal) {
                node = node->right;
            } else if(pVal < parentVal && qVal < parentVal) {
                node = node->left;
            } else {
                return node;
            }
        }
        return nullptr;
    }
};