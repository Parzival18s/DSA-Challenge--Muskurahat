class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int x=q.size();
            vector<int>tmp;
            for(int i=0;i<x;i++)
            {
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                tmp.push_back(q.front()->val);
                q.pop();
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

//Link--https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/