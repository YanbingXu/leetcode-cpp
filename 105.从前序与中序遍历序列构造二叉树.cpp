/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start
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
    unordered_map<int, int>inorder_map;

    TreeNode* buildMyTree(vector<int>& preorder, int preLeft, int preRight, unordered_map<int, int>& map, int inLeft, int inRight) {
        // 递归终止条件
        // cout<<"map size:" << map.size() << endl;
        if (preLeft > preRight )
        {
            return nullptr;
        }
        // 得到根节点的val值
        int rootVal = preorder[preLeft];
        // 得到根节点在中序遍历中的索引值
        int pIndex =map[rootVal];
        // cout << "rootVal:" << rootVal << ",pIndex:" << pIndex << endl;
        // 创建根节点
        TreeNode* root = new TreeNode(rootVal);
        // 递归创建左子树
        root->left = buildMyTree(preorder, preLeft + 1, pIndex-inLeft + preLeft, map, inLeft, pIndex-1);
        // 递归创建右子树
        root->right = buildMyTree(preorder, pIndex - inLeft + preLeft +1, preRight, map, pIndex+1, inRight);

        // cout << "root->left:" << root->left << left;

        // 返回根节点
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 前序遍历：根-左-右
        // 中序遍历：左-根-右
        // 根据前序中根的val值确定中序的根的index值，确定左右子树的范围，递归的写出整棵树

        int preSize = preorder.size();
        // 空间换时间，用哈希表存储一遍中序 （val， index）
        for (int i = 0; i < inorder.size(); i++)
        {
            inorder_map[inorder[i]] = i;

        }
        // cout<<"map size total:"<<inorder_map.size()<<endl;
        return buildMyTree(preorder, 0, preSize-1, inorder_map, 0, preSize-1);

    }

};
// @lc code=end

