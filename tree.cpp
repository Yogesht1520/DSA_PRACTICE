#include<iostream>
#include<stack>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;    
};
class tree{
    public:
    Node* root;
    Node* stack[100];
    int top = -1;
    tree()
    {
        root = NULL;
    }
    void create();
    void display();
    void insert1(Node* root, Node* temp);
    void preorder(Node* temp);
    void inorder(Node* temp);
    void postorder(Node* temp);
    void nrpreorder(Node* temp);
    void nrinorder(Node* temp);
    void nrpostorder(Node* temp);
    void push(Node* root)
    {
        stack[++top] = root;
    }
    Node* pop()
    {
        Node* t;
        t = stack[top --];
        return t;
    }
};
void tree :: create(){
    Node* temp;
    int val;
    char ch;
    do
    {
    temp = new Node();
    cout<<"Enter value-";
    cin>>val;
    temp-> data = val;
    temp -> left  = NULL;
    temp-> right = NULL;
    if (root ==NULL)
    {
        root = temp;

    }
    else
    {
        insert1(root,temp);
    }
        cout<<"Do you want to add another node-";
        cin>>ch;
    
    }while(ch == 'y' || ch == 'Y');
}
void tree ::insert1(Node* root, Node* temp){
    int pos = 0;
    cout<<"Current root element-"<<temp-> data<<endl;
    cout<<"Enter the position for addition of new root-(left=1 or right = 2)";
    cin>>pos;
    if (pos == 1)
    {
        if (root-> left == NULL)
        {
            root -> left = temp;
        }
        else
        {
            insert1(root->left, temp);
        }
    }
    else{
        if(root-> right == NULL)
        {
            root -> right = temp;
        }
        else{
            insert1(root-> right, temp);
        }
    }

}
void tree::display()
{
    int choice;
    cout<<"1. pre- order traversal-"<<endl;
    cout<<"2. post order traversal-"<<endl;
    cout<<"3. In-order traversal-"<<endl;
    cout<<"4. Non-recursive pre-order"<<endl;
    cout<<"5. Non-recursive post-order"<<endl;
    cout<<"6. Non-recursive in-order"<<endl;
    cout<<"7. Exit"<<endl;
    cout<<"Enter your choice-";
    cin>>choice;

    switch(choice)
    {
        case 1 : preorder(root);
                break;

        case 2 : postorder(root);
                break;

        case 3 : inorder(root);
                break;

        case 4: nrpreorder(root);
                break;    

        case 5: nrpostorder(root);
                break;    

        case 6: nrinorder(root);
                break;    

        case 7: default:
                break;
    }
}
void tree :: preorder(Node* temp)
{
    if(temp!= NULL)
    {
        cout<<" "<<temp->data;
        preorder(temp->left);
        preorder(temp->right);
    }
}
void tree :: inorder(Node *temp) {
  if (temp != NULL) {
    inorder(temp->left);
    cout << " " << temp->data;
    inorder(temp->right);
  }
}
void tree :: postorder(Node *temp) {
  if (temp != NULL) 
  {
    postorder(temp->left);
    postorder(temp->right);
    cout << " " << temp->data;
  }
}
void tree:: nrpreorder(Node* root)
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
            if(top != -1)
            {
                temp = pop();
            }
            else{
                break;
            }
        }
    }
}
void tree:: nrinorder(Node* root)
{
    Node* temp;
    temp = root;
    while (temp != NULL) 
    {
        while (temp != NULL) 
        {    
            push(temp->left);
            temp = temp->left;
        }
        if(top = -1)
        {
            temp = pop();
        }
        cout << temp->data << " ";
        temp = temp->right;
    }
}
void tree:: nrpostorder(Node* temp)
 {
//     temp = root;
//     root = NULL;
//     while (top == -1)
//     {
//         if(temp != NULL){
//             push(temp);
//         }
//         else{
//             temp = top[stack];
//             if (temp -> right == NULL || temp->right == temp)
//             {
//                 cout<< " "<< temp-> data;
//                 pop();
//                 temp->left = temp;
//                 temp = NULL;
//             }
//             else
//             {
//                 temp = temp-> right;
//             }
//         }
//     }
 }
int main()
{
    //Node* temp;
    //Node* root = temp;
    tree t;
    t.create();
    t.display();
    //t.insert(t.root,t.temp);
    return 0;
}