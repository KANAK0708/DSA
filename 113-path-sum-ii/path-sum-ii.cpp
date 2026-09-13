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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>currentPath;
        vector<vector<int>> allPaths;


        dfs(root, targetSum, currentPath, allPaths);

        return allPaths; 
    
    }


private:
    void dfs(TreeNode* node, int targetSum, vector<int>& currentPath, vector<vector<int>>& allPaths) {
        // Base Case 1: Empty node
        if (node == nullptr) {
            return;
        }

        currentPath.push_back(node->val);

        if (node->left == nullptr && node->right == nullptr && targetSum == node->val) {
            // We found a valid path! Add a copy of currentPath to allPaths
            allPaths.push_back(currentPath);


        } else {

            // 3. Recursive Step: Not a leaf, or sum didn't match. 
            // Dive down left and right, subtracting the current node's value from the target.
            dfs(node->left, targetSum - node->val, currentPath, allPaths);
            dfs(node->right, targetSum - node->val, currentPath, allPaths);
        }

        // 4. THE BACKTRACKING STEP
        // Remove the current node from the path as we step back up the tree
        currentPath.pop_back();

    }
};