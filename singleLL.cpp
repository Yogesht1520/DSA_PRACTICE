#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* link;
};
class SLL{
    public:
    Node* head;
    Node* tail;
    SLL()
    {
        head = NULL;
        tail = NULL;
    }
    void create();
    void insert();
    void display();
};

void SLL:: create()
{
    Node* temp;
    int val;
    char ch;
    do{
        temp = new Node;
        cout<<"Enter value-";
        cin>>val;
        temp->data = val;
        temp->link = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->link = temp;
            tail = temp;
        }
        cout<<"Do you want to continue-"<<endl;
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');
}
void SLL:: display()
{
     Node* temp = head;

    while(temp != NULL){
        cout<< temp -> data << " ";
        temp = temp -> link;
    }
}

void SLL:: insert()
{
    int value, choice, position;
    do
    {
        Node* temp = new Node();
        cout<<"1. Insert at  beginning";
        cout<<"2. Insert at end";
        cout<<"3. insert in the middle";
        cout<<"4. Exit";
        cout<<"Enter your choice-";
        cin>>choice;
        switch (choice)
        {
            case 1:
                cout<<"Enter the value to be inserted-";
                cin>>value;
                temp->data = value;
                temp -> link = head;
                head = temp;
                break;
            case 2:
                cout<<"Enter the value to be inserted at end-";
                cin>>value;
                temp->data = value;
                tail -> link = temp;
                tail = temp;
            case 3:
                cout<<"Enter the value to be inserted in the middle-";
                cin>>value;
                cout<<"Enter the position for adding new node-";
                cin>>position;

            default:
                break;
        }
    
    }while(choice == 4);
}
int main()
{
    SLL s1;
    s1.create();
    s1.display();
    s1.insert();
    s1.display();
    return 0;
}