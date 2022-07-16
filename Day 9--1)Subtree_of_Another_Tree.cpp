class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot,int flag=0) {
        if(!root and !subRoot)
            return true;
        if(!root or !subRoot)
            return false;
        if(root->val!=subRoot->val)
        {
            if(flag==0)
                return isSubtree(root->left,subRoot,0) or isSubtree(root->right,subRoot,0);
            else
                return false;
        }
        if(flag==1)
            return (isSubtree(root->left,subRoot->left,1) and isSubtree(root->right,subRoot->right,1));
        return (isSubtree(root->left,subRoot->left,1) and isSubtree(root->right,subRoot->right,1))
                or isSubtree(root->left,subRoot,0) or isSubtree(root->right,subRoot,0);
    }
};

//Link--https://leetcode.com/problems/subtree-of-another-tree/