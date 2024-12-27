#include <iostream>
using namespace std;
const int INF = 1e9; // Representation of infinity
class Graph {
public:
    int V; // Number of vertices
    int **adjMatrix;
    Graph(int V) {
        this->V = V;
        adjMatrix = new int*[V];
        for (int i = 0; i < V; i++) {
            adjMatrix[i] = new int[V];
            for (int j = 0; j < V; j++)
                adjMatrix[i][j] = 0;
        }
    }
    ~Graph() {
        for (int i = 0; i < V; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
    void addEdge(int u, int v, int w) {
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w; 
    }
    int minDistance(int dist[], bool sptSet[]) {
        int min = INF, min_index;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && dist[v] <= min)
                min = dist[v], min_index = v;
        return min_index;
    }
    void dijkstra(int src) {
        int dist[V]; 
        bool sptSet[V]; 
        for (int i = 0; i < V; i++)
        {
            dist[i] = INF, sptSet[i] = false;
        }
        dist[src] = 0;
        for (int count = 0; count < V - 1; count++) {
            int u = minDistance(dist, sptSet);
            sptSet[u] = true;

            for (int v = 0; v < V; v++)
            {
                if (!sptSet[v] && adjMatrix[u][v] && dist[u] != INF && dist[u] + adjMatrix[u][v] < dist[v]){
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }
        printSolution(dist);
    }
    void printSolution(int dist[]) {
        cout << "Vertex \t Distance from Source\n";
        for (int i = 0; i < V; i++)
            cout << i << " \t\t" << dist[i] << "\n";
    }
};
int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    Graph g(V);
    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter the edges in the format: src dest weight\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    int src;
    cout << "Enter the source vertex for Dijkstra's algorithm: ";
    cin >> src;
    g.dijkstra(src);
    return 0;
}