class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            swap(q.front()->left,q.front()->right);
            if(q.front()->left)
                q.push(q.front()->left);
            if(q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
        return root;
    }
};

//Link--https://leetcode.com/problems/invert-binary-tree/