#include<iostream>
#include<vector>
#include <queue>


using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> que;
        vector<vector<int>> res;
        if (root == NULL) return res;
        que.push(make_pair(root, 0));
        while (!que.empty()) {

            TreeNode* node = que.front().first;
            int level = que.front().second;
            que.pop();

            if (level == res.size())
                res.push_back(vector<int>());
            res[level].push_back(node->val);
            if (node->left)
                que.push(make_pair(node->left, level + 1));
            if (node->right)
                que.push(make_pair(node->right, level + 1));
        }
        return res;

    }
};

int main() {

	system("pause");
	return 0;
}