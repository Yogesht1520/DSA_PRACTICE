#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Stack
{
public:
    Node *head;
    Stack()
    {
        head = NULL;
    }
    void push(int data)
    {
        Node *temp = new Node();
        temp->data = data;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    int pop()
    {
        Node *temp = head;
        head = head->next;
        return temp->data;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
};

class Queue
{
public:
    Node *front, *rear;
    Queue()
    {
        front = rear = NULL;
    }
    void enqueue(int data)
    {
        Node *temp = new Node();
        temp->data = data;
        if (front == NULL)
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = rear->next;
    }
    int dequeue()
    {
        Node *temp = front;
        if (front == NULL)
        {
            cout << "Empty queue" << endl;
            return 0;
        }
        front = front->next;
        temp->next = NULL;
        int data = temp->data;
        delete temp;
        return data;
    }
};
class Graphmatrix{
public:
    int g[100][100];
    int n, v1, v2;
    int v[10];
    int st[10],top=-1; 
    Graphmatrix(){
        cout<<"Enter the number of vertices- ";
        cin>>n;
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = 0;
            }
        }
        for (int i = 0; i< 10; i++)
        {
            v[i] = 0;
        }
    }
    void addedge(int i, int j)
    {
        int ch;
        do{
            cout<<"Enter 2 vertices having edges- ";
            cin>>v1>>v2;
            g[v1][v2] = 1;
            g[v2][v1] = 1;
            cout << "Do you want to continue?, press 1 ";
            cin>>ch;
        }while(ch == 1);
    }
    void printmatrix()
    {
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout<<g[i][j]<< " ";
            }
            cout<<endl;
        }
    }
    void BFStraversal(int startvertex)
    {
         vector<bool> visited(n, false); 
         queue<int> q;
         visited[startvertex] = true; 
         q.push(startvertex); 
         while (!q.empty()) {
             int currvertex = q.front();
             cout << currvertex << " "; 
             q.pop();
             for (int i = 0; i < n; i++) {
                 if (g[currvertex][i] == 1 && !visited[i]) {
                     visited[i] = true;
                     q.push(i);
                 }
             }
         }
         cout << "\n";
    }
    void push(int v)
    {
        if(top<=9)
            st[++top]=v;
        else
            cout<<"stack is full";
    }
    int pop()
    {
        int v =-1;
        if(top!=-1)
        {
            v=st[top];
            top--;
        }
        else
        {
            cout<<"stack is empty ";
        }
        return v;
    }
    void DFStraversal(int sv)
    {
        int visited[n+1];
        for(int i=0;i<=n-1;i++)
        {
            visited[i]=0;
        }
        push(sv);
        while(top!=-1)
        {
            sv=pop();
            if(visited[sv]==0)
            {
                cout<<sv<<" "; 
                visited[sv]=1;  
                for(int i =0;i<=n-1;i++)
                {
                    if(g[sv][i]>=0)  
                        push(i);
                }
            }
        }
    }
};
int main()
{
    int i, j;
    Graphmatrix m;
    m.addedge(i,j);
    cout<<"The Adjacency Matrix is- "<<endl;
    m.printmatrix();
    int startvertex;
    cout << "Enter the start vertex for BFS: ";
    cin >> startvertex;
    cout << "BFS Traversal starting from vertex " << startvertex << ": "<< endl;
    m.BFStraversal(startvertex);
    int sv;
    cout<<"Enter start vertex for DFS: ";
    cin>>sv;
    cout<<"DFS Traversal from vertex "<< sv <<": "<<endl ;
    m.DFStraversal(sv);
    return 0;
}