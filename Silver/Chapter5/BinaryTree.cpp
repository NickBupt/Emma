#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int value) {
    TreeNode* node = new TreeNode();
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void createTree(TreeNode* cur) {
    if (cur->value >= 10)
        return;
    TreeNode* left = createNode(cur->value * 2);
    TreeNode* right = createNode(cur->value * 2 + 1);
    cur->left = left;
    cur->right = right;
    createTree(left);
    createTree(right);
}

void preOrderTraversal(TreeNode* cur) {
    if (cur == NULL)
        return;
    cout << cur->value << " ";
    preOrderTraversal(cur->left);
    preOrderTraversal(cur->right);
}

void inOrderTraversal(TreeNode* cur) {
    if (cur == NULL)
        return;
    inOrderTraversal(cur->left);
    cout << cur->value << " ";
    inOrderTraversal(cur->right);
}

void postOrderTraversal(TreeNode* cur) {
    if (cur == NULL)
        return;
    postOrderTraversal(cur->left);
    postOrderTraversal(cur->right);
    cout << cur->value << " ";
}

void levelOrderTraversal(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        cout << cur->value << " ";
        if (cur->left != NULL)
            q.push(cur->left);
        if (cur->right != NULL)
            q.push(cur->right);
    }
}

int main() {
    TreeNode* root = createNode(1);
    createTree(root);
    preOrderTraversal(root);
    cout << endl;
    inOrderTraversal(root);
    cout << endl;
    postOrderTraversal(root);
    cout << endl;
    levelOrderTraversal(root);
    cout << endl;
}

