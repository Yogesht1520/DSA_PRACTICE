#include<iostream>
#include<stack>
using namespace std;

class BTree{
    public:
    int Stack[100];
    int top = -1;
    int data;
    void preorder(TreeNode * root);
}
void BTree::preorder(TreeNode *root) {   
    TreeNode *temp;
    stack<TreeNode*> S;
    temp = root;
    while(1){
        while(temp != NULL){
            cout << temp ->data<<" ";
            S.push(temp);           
            temp = temp->left;
        }
        if(S.empty()) {
            break;
        }
        S.pop();
        temp = S.top();       
        temp = temp->right;
}
}

void push(Node* root)
{
    Stack[++top] = root;
}


Node* pop()
{
    Node* t;
    t = pop();
    return t;
}

void preorder(Node* root)
{
    Node* temp;
    temp = root;
    while (1)
    {
        if(temp != NULL)
        {
            cout<<temp->data;
            push(temp-> right);
            temp = temp->left;
        }
        else
        {
            if(top != NULL)
            {
                temp = pop();
            }
        }
    }
}
