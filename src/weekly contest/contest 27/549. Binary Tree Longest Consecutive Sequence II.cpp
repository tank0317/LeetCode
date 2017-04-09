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
    struct Result{
        TreeNode *node;
        int inc;
        int dec;
    };
    
    int lenMax = 0;
    
    int longestConsecutive(TreeNode* root) {
        tranvase(root);
        return lenMax;
    }
    
    Result* tranvase(TreeNode* root){
        if(!root) return nullptr;
        
        Result* left = tranvase(root->left);
        Result* right = tranvase(root->right);
        
        Result* cur = new Result();
        cur->node = root;
        cur->inc = 1;
        cur->dec = 1;
        
        if(left){
            if(root->val - left->node->val == 1){
                cur->inc = max(cur->inc, left->inc+1);
            }
            if(root->val - left->node->val == -1){
                cur->dec = max(cur->dec, left->dec+1);
            }
        }
        if(right){
            if(root->val - right->node->val == 1){
                cur->inc = max(cur->inc, right->inc + 1);
            }
            if(root->val - right->node->val == -1){
                cur->dec = max(cur->dec, right->dec + 1);
            }
        }
        
        lenMax = max(lenMax, cur->inc + cur->dec - 1);
        
        return cur;
    }
};