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
    struct compare{
        bool operator()(const pair<pair<int,int>,TreeNode*> &a, const pair<pair<int,int>,TreeNode*> &b) const{
            if(a.first.second==b.first.second){
                if(a.first.first==b.first.first) return (a.second->val>b.second->val);
                return (a.first.first>b.first.first);
            }            
            return (a.first.second>b.first.second);
        }
    };
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        priority_queue<pair<pair<int,int>,TreeNode*>,vector<pair<pair<int,int>,TreeNode*>>,compare> pq;
        pq.push({{0,0},root});
        queue<pair<pair<int,int>,TreeNode*>> q;
        q.push({{0,0},root});
        while(!q.empty()){
            auto curr=q.front();
            int x=curr.first.first;
            int y=curr.first.second;
            auto node=curr.second;
            q.pop();
            if(node->left){
                q.push({{x+1,y-1},node->left});
                pq.push({{x+1,y-1},node->left});
            }
            if(node->right){
                q.push({{x+1,y+1},node->right});
                pq.push({{x+1,y+1},node->right});
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            vector<int> temp;
            int x=pq.top().first.second;
            while(!pq.empty() && pq.top().first.second==x){
                auto curr=pq.top();
                pq.pop();
                temp.push_back(curr.second->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};