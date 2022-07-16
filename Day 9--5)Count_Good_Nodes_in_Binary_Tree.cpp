class Solution {
public:
    int goodNodes(TreeNode* root) {
        int ans=1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            if(q.front()->left)
            {
                if(q.front()->val<=q.front()->left->val)
                    ans++;
                else
                    q.front()->left->val=q.front()->val;
                q.push(q.front()->left);
            }
            if(q.front()->right)
            {
                if(q.front()->val<=q.front()->right->val)
                    ans++;
                else
                    q.front()->right->val=q.front()->val;
                q.push(q.front()->right);
            }
            q.pop();
        }
        return ans;
    }
};

//Link--https://leetcode.com/problems/count-good-nodes-in-binary-tree/