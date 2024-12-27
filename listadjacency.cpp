#include <iostream>
using namespace std;
struct Node {
    int vertex;
    Node* next;
};
class Graph {
public:
    int numVertices;    // Number of vertices in the graph
    Node** adjList;     // Pointer to an array containing adjacency lists
    Graph(int vertices) : numVertices(vertices) {
        adjList = new Node*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjList[i] = nullptr;
        }
    }
    ~Graph() {
        for (int i = 0; i < numVertices; i++) {
            Node* ptr = adjList[i];
            while (ptr != nullptr) {
                Node* toDelete = ptr;
                ptr = ptr->next;
                delete toDelete;
            }
        }
        delete[] adjList;
    }
    void addEdge(int u, int v) {
        Node* newNode = new Node{v, adjList[u]};
        adjList[u] = newNode;
        newNode = new Node{u, adjList[v]};
        adjList[v] = newNode;
    }
    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            Node* ptr = adjList[i];
            cout << "Adjacency list of vertex " << i << ": head";
            while (ptr != nullptr) {
                cout << " -> " << ptr->vertex;
                ptr = ptr->next;
            }
            cout << endl;
        }
    }
};
int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.printGraph();
    return 0;
}
