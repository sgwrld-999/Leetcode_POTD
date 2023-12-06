#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createTree(vector<int>& nodes, int i) {
    if (i >= nodes.size() || nodes[i] == -1) {
        return NULL;
    }
    TreeNode* root = new TreeNode(nodes[i]);
    root->left = createTree(nodes, 2 * i + 1);
    root->right = createTree(nodes, 2 * i + 2);
    return root;
}

class Solution {
public:
    // BFS
    // Time: O(n)
    // Space: O(n)
    //Explanation: We use BFS to traverse the tree level by level and keep track of the maximum value in each level.
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return {};
        
        queue<TreeNode*> que;
        que.push(root);
        
        vector<int> result;
        
        while(!que.empty()) {
            
            int n = que.size();
            int maxEl = INT_MIN;
            while(n--) {
                
                TreeNode* node = que.front();
                que.pop();
                
                maxEl = max(maxEl, node->val);
                
                if(node->left)
                    que.push(node->left);
                
                if(node->right)
                    que.push(node->right);
            }
            
            result.push_back(maxEl);
            
        }
        
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    vector<int> res = s.largestValues(root);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}
