class Solution {
public:
    vector<int>v;
    void helper(TreeNode* root)
    {
        if(!root)
            return;
        if(root->left)
            helper(root->left);
        v.push_back(root->val);
        if(root->right)
            helper(root->right);
    }
    bool isValidBST(TreeNode* root) {
        helper(root);
        for(int i=1;i<v.size();i++)
        {
            if(v[i]<=v[i-1])
                return false;
        }
        return true;
    }
};

//Link--https://leetcode.com/problems/validate-binary-search-tree/submissions/