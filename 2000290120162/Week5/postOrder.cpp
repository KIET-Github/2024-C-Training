
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int v)
    {
        data = v;
        left = right = NULL;
    }
};
 
void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;

    printPostorder(node->left);
 
    printPostorder(node->right);
 
    cout << node->data << " ";
}
 

int main()
{
    struct Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(60);
 
    cout << "Postorder traversal of binary tree is: \n";
    printPostorder(root);
 
    return 0;
}
