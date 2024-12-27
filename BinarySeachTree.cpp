#include<iostream>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode *left, *right;
};

class Binary_Search_Tree
{
    BSTNode *root;
    public:
    Binary_Search_Tree()  
    {
        root = NULL;
    }
    void Insert_Node1(int d)
    {
        Insert_Node(d, root);
    }
    void Insert_Node(int d, BSTNode *r)
    {
        if (root == NULL) // Empty
        {
            BSTNode *t = new BSTNode();
            t -> data = d;
            t -> left = t -> right = NULL;
            root = t;
        }
        else
        {
            if (d < r -> data)
            {                         
               if (r -> left == NULL)
               {
                    BSTNode *t = new BSTNode();
                    t -> data = d;
                    t -> left = t -> right = NULL;
                    r -> left = t;
               }
               else 
               {
                Insert_Node(d, r -> left);
               }
            }
            else
            {
                if (r -> right== NULL)
               {
                    BSTNode *t = new BSTNode();
                    t -> data = d;
                    t -> left = t -> right = NULL;
                    r -> right = t;
               }
               else 
               {
                Insert_Node(d, r -> right);
               }
            } 
        }
    }
    void inorder(BSTNode *t)
    {  
        if (t != NULL)
        {
            inorder (t -> left);
            cout << t -> data <<" ";
            inorder (t -> right);
        }
    }
    void inorder1()
    {
        cout<<"inorder- ";
        inorder(root);
    } 
    void preorder(BSTNode* root)
    {
        if (root!= NULL)
        {
            cout<<root-> data<<" ";
            preorder(root-> left);
            preorder(root-> right);
        }
    }
    void preorder1()
    {
        cout<<"preorder- ";
        preorder(root);
    }
};

int main()
{
    Binary_Search_Tree B1;
    B1.Insert_Node1(10);
    B1.Insert_Node1(5);
    B1.Insert_Node1(34);
    B1.Insert_Node1(26);
    B1.Insert_Node1(15);
    B1.Insert_Node1(46);
    cout << "Tree is "<<endl;
    B1.inorder1();
    B1.preorder1();
    return 0;
}

/*
node* queue[20]
int leafheight(node* root)
{
    if(root == NULL)
    {
        return 0;
        if (root-> left == NULL && root-> right == NULL)
        {
            return 1;
        }
    }
    else
    {
        return (leaf(root-> left) + leaf(root-> right));
    }
    return (max(height(root-> left), height(root->right)+ 1));
}

mirror(node* root)
{
    node* temp;
    mirror(root-> left);
    mirror(root-> right);
    temp1 = root-> left;
    root -> left = root -> right;
    root-> right = temp1;
}
*/