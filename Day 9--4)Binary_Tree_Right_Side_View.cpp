class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int x=q.size();
            for(int i=0;i<x;i++)
            {
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                if(i==x-1)
                    ans.push_back(q.front()->val);
                q.pop();
            }
        }
        return ans;
    }
};

//Link--https://leetcode.com/problems/binary-tree-right-side-view/submissions/