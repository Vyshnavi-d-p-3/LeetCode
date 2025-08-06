/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Approach 1 : Recursive Approach
    // vector<vector<int>> levels;
    // void helper(TreeNode* node, int level) {
    //     if(levels.size() == level) 
    //         levels.push_back(vector<int>());
    //     levels[level].push_back(node->val);
    //     if(node->left != nullptr) helper(node->left, level + 1);
    //     if(node->right != nullptr) helper(node->right, level + 1);
    // }
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     if(root == nullptr) return levels;
    //     helper(root, 0);
    //     return levels;
    // }

    // Approach 2 : Iterative Approach
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> levels;
        if(root == NULL) return levels;
        deque<TreeNode*> queue;
        queue.push_back(root);
        int level = 0;
        while(!queue.empty()) {
            levels.push_back({});
            int level_length = queue.size();
            for(int i = 0; i < level_length; ++i) {
                TreeNode* node = queue.front();
                queue.pop_front();
                levels[level].push_back(node->val);
                if(node->left != NULL) queue.push_back(node->left);
                if(node->right != NULL) queue.push_back(node->right);
            }
            level++;
        }
        return levels;
    }
};