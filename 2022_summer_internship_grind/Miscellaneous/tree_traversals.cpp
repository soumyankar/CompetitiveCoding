#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

// Utility function to create a new new_node
Node *new_node(int data)
{
    Node *temp=new Node();
    temp->data=data;
    temp->left = temp->right = NULL;
    return temp;
}

// Given a tree, print it's post-order traversal
void printPostOrder(struct Node *tree)
{
    if(tree==NULL)
        return;
    printPostOrder(tree->left);

    printPostOrder(tree->right);

    cout<<tree->data<<", ";

}
// Preorder traversal
void printPreOrder(struct Node *bt)
{
    if(bt==NULL)
        return;
    cout<<bt->data<<", ";
    printPreOrder(bt->left);

    printPreOrder(bt->right);
}

// Inorder
void printInOrder(struct Node *tree)
{
    if(tree==NULL)
        return;
    printInOrder(tree->left);
    cout<<tree->data<<", ";
    printInOrder(tree->right);
}

void printBFS(struct Node *root)
{
    if(root==NULL)
        return;
    queue<Node*> q;
    q.push(root);
    while(q.empty()==false)
    {
        Node *next=q.front();
        cout<<next->data<<" ";
        if(next->left!=NULL)
            q.push(next->left);
        if(next->right!=NULL)
            q.push(next->right);
        q.pop();
    }
}
int main()
{
    struct Node* tree = new_node(1);
    tree->left=new_node(5);
    tree->right=new_node(10);
    tree->left->left=new_node(55);
    tree->right->right=new_node(50);
    tree->left->right=new_node(60);
    tree->right->left=new_node(200);
    printPostOrder(tree);
    cout<<"\n";
    printPreOrder(tree);
    cout<<"\n";
    printInOrder(tree);
    cout<<"\n";

    printBFS(tree);
}