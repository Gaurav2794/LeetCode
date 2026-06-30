/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder(struct TreeNode* root, int* ans, int* index)
{
    if(root == NULL)
        return;

    inorder(root->left, ans, index);

    ans[*index] = root->val;
    *index = *index + 1;

    inorder(root->right, ans, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* ans = (int*)malloc(sizeof(int) * 100);

    *returnSize = 0;

    inorder(root, ans, returnSize);

    return ans;
}