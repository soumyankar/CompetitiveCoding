#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void push_data(Node** head_ref, int new_data)
{
    Node* new_node=new Node();
    new_node->data=new_data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}

void print_data(Node* head_ref)
{
    while(head_ref!=NULL)
    {
        cout << head_ref->data << ", ";
        head_ref=head_ref->next;
    }
    cout<<endl;
}

void append(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while(last->next!=NULL)
        last = last->next;

    last->next=new_node;
    return;
}

int main()
{
    Node* first=new Node();
    first->data=10;
    first->next=NULL;

    print_data(first);
    push_data(&first, 20);
    print_data(first);
    append(&first, 40);
    print_data(first);
}

