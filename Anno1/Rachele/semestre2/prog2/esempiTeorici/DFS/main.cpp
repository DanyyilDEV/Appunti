// BFS algorithm in C++
#include <iostream>

// ===== QUEUE =====
class Queue {
private:
    static const int SIZE = 40;
    int items[SIZE];
    int head;
    int tail;

public:
    Queue() : head(-1), tail(-1) {}

    bool isEmpty() const {
        return tail == -1;
    }

    void enqueue(int value) {
        if (tail == SIZE - 1) {
            std::cout << "\nQueue is Full!!\n";
            return;
        }
        if (head == -1) head = 0;
        tail++;
        items[tail] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        int item = items[head];
        head++;
        if (head > tail) {
            std::cout << "Resetting queue\n";
            head = tail = -1;
        }
        return item;
    }

    void print() const {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
        } else {
            std::cout << "\nQueue contains:\n";
            for (int i = head; i <= tail; i++)
                std::cout << items[i] << " ";
            std::cout << "\n";
        }
    }
};

// ===== LINKED LIST NODE (per le adjacency list) =====
struct Node {
    int vertex;
    Node* next;

    Node(int v) : vertex(v), next(nullptr) {}
};

// ===== ADJACENCY LIST =====
class AdjList {
public:
    Node* head;

    AdjList() : head(nullptr) {}

    ~AdjList() {
        Node* curr = head;
        while (curr) {
            Node* tmp = curr->next;
            delete curr;
            curr = tmp;
        }
    }

    void insert(int v) {
        Node* newNode = new Node(v);
        newNode->next = head;
        head = newNode;
    }
};

// ===== GRAPH =====
class Graph {
private:
    int numVertices;
    AdjList* adjLists;
    bool* visited;

public:
    Graph(int vertices) : numVertices(vertices) {
        adjLists = new AdjList[vertices];
        visited  = new bool[vertices];
        for (int i = 0; i < vertices; i++)
            visited[i] = false;
    }

    ~Graph() {
        delete[] adjLists;
        delete[] visited;
    }

    void addEdge(int src, int dest) {
        adjLists[src].insert(dest);
        adjLists[dest].insert(src);
    }

    void bfs(int startVertex) {
        Queue q;
        visited[startVertex] = true;
        q.enqueue(startVertex);

        while (!q.isEmpty()) {
            q.print();
            int currentVertex = q.dequeue();
            std::cout << "Visited " << currentVertex << "\n";

            Node* temp = adjLists[currentVertex].head;
            while (temp) {
                int adjVertex = temp->vertex;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    q.enqueue(adjVertex);
                }
                temp = temp->next;
            }
        }
    }

    void resetVisited() {
        for (int i = 0; i < numVertices; i++)
            visited[i] = false;
    }
};

int main() {
    Graph graph(6);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 4);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);

    graph.bfs(0);

    return 0;
}
