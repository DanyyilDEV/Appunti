#include <iostream>
using namespace std;

struct Node {
    int vertex;
    Node* next;

    Node(int v) : vertex(v), next(nullptr) {}
};

class Graph {
private:
    int numVertices;
    Node** adjLists;

public:
    // Costruttore
    Graph(int vertices) : numVertices(vertices) {
        adjLists = new Node*[vertices];
        for (int i = 0; i < vertices; i++)
            adjLists[i] = nullptr;
    }

    // Distruttore
    ~Graph() {
        for (int i = 0; i < numVertices; i++) {
            Node* current = adjLists[i];
            while (current) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] adjLists;
    }

    // Aggiunge un arco non orientato
    void addEdge(int s, int d) {
        // Arco da s a d
        Node* newNode = new Node(d);
        newNode->next = adjLists[s];
        adjLists[s] = newNode;

        // Arco da d a s
        newNode = new Node(s);
        newNode->next = adjLists[d];
        adjLists[d] = newNode;
    }

    // Stampa il grafo
    void printGraph() const {
        for (int v = 0; v < numVertices; v++) {
            Node* temp = adjLists[v];
            cout << "\nVertex " << v << ": ";
            while (temp) {
                cout << temp->vertex << " -> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.printGraph();
    return 0;
}
