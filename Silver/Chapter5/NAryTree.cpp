#include <iostream>
using namespace std;

struct TreeNode
{
    int value;
    vector<TreeNode*> next;
};

TreeNode* createNode(int value)
{
    TreeNode* node = new TreeNode();
    node->value = value;
    return node;
}

void createTree(TreeNode* cur)
{
    if (cur->value >= 10)
        return;
    vector<TreeNode*> next;
    for (int i = 0; i < 3; ++i)
    {
        TreeNode* nextNode = createNode(cur->value * 3 + i);
        next.push_back(nextNode);
        createTree(nextNode);
    }
    cur->next = next;
}

void preOrderTraversal(TreeNode* cur)
{
    if (cur == NULL)
        return;
    cout << cur->value << " ";
    for(auto& next: cur->next)
        preOrderTraversal(next);
}

void postOrderTraversal(TreeNode* cur)
{
    if (cur == NULL)
        return;
    for(auto& next: cur->next)
        postOrderTraversal(next);
    cout << cur->value << " ";
}

void levelOrderTraversal(TreeNode* cur)
{
    queue<TreeNode*> q;
    q.push(cur);

    while(q.size())
    {
        TreeNode* cur = q.front();
        q.pop();
        cout << cur->value << " ";
        for (auto& next: cur->next)
        {
            if (next != NULL)
                q.push(next);
        }
    }
}

int main(){
    TreeNode *root1 = createNode(1);
    createTree(root1);

    preOrderTraversal(root1);
    cout << endl;
    postOrderTraversal(root1);
    cout << endl;
    levelOrderTraversal(root1);
}

