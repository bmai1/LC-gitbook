# 🥰 binary (search) tree

```cpp
// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

```

* Binary search trees are sorted binary trees such that left node values will be strictly less than the parent node value, and right node values are strictly greater.

**Common traversal templates:**

```cpp
// uses: create a copy of the tree (serialization)
//       validate the structure of a tree
//       perform some operation on each node before traversing children
void preorder(TreeNode* root) {
    if (!root) return;
    // do stuff
    preorder(root->left);
    preorder(root->right);
}

// uses: retrieve the elements of a binary search tree (BST) in sorted order
//       validate BST
void inorder(TreeNode* root) {
    if (!root) return;
    preorder(root->left);
    // do stuff
    preorder(root->right);
}

// uses: delete the tree
//       process children before parent
//       evaluate expressions in a syntax tree
void postorder(TreeNode* root) {
    if (!root) return;
    preorder(root->left);
    preorder(root->right);
    // do stuff
}

```
