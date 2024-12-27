#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d)
    {
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }
    ~Node()
    {
        int val = this -> data;
        if(next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data" << val << endl;
    }

};

void print(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int getlength(Node* head)
{
    int len = 0;
    Node* temp = head;

    while(temp != NULL)
    {
        len++;
        temp = temp -> next;
    }
    return len;
}

void inserthead(Node* &tail, Node* &head, int d)
{
    if(head == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    }
}

void inserttail(Node* &tail, Node* &head, int d)
{
    cout << " tail " << tail <<endl;
    if(tail == NULL)
    {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
    Node* temp = new Node(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
    }
}

void insertposition(Node* &tail, Node* &head,int position, int d)
{
    if(position == 1)
    {
        inserthead(tail, head, d);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < position-1)
    {
        temp = temp -> next;
        count++;
    }
    if(temp -> next == NULL)
    {
        inserttail(tail, head, d);
        return;
    }

    //creating a node for d
    Node* nodetoinsert = new Node(d);

    nodetoinsert -> next = temp -> next;
    temp -> next -> prev = nodetoinsert;
    temp -> next = nodetoinsert;
    nodetoinsert -> prev = temp;
}

void deletenode(int position, Node* &head)
{
    if(position == 1)
    {
    Node* temp = head;
    temp -> next -> prev = NULL;
    head = temp -> next;
    temp -> next = NULL;
    delete temp;
    }

    else
    {
    Node* curr = head;
    Node* prev = NULL;

    int count = 1;
    while(count < position)
    {
        prev = curr;
        curr = curr -> next;
        count++;
    }
    curr -> prev = NULL;
    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
    }

}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    
    //print(head);
    //cout << getlength(head) <<endl;
    inserthead(tail, head, 15);
    print(head);

    inserthead(tail, head, 22);
    print(head);
    
    inserttail(tail, head, 25);
    print(head);

    insertposition(tail, head, 2, 100);
    print(head);

    deletenode(1, head);
    print(head);
    cout << " head " << head -> data << endl;
    cout << " tail " << tail -> data << endl;
    return 0; 
}