#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <string>
using namespace std;

template<typename T1, typename T2>
class Graph {

    private:

        template<typename T4>
        class Node;

        template<typename T3>
        class Edge {

            public:

                Node<T3> *adjacentNode;  // Node to which current edge points
                int weight;

                Edge(Node<T3> *adjacentNode, int weight) {
                    this->adjacentNode = adjacentNode;
                    this->weight = weight;
                }

                ~Edge() {
                    delete adjacentNode;
                }

        };

        template<typename T4>  // template<T4>
        class Node {

            public:

                T4 data;
                list<Node<T4>> edges;  // List of edges which current node has
                vector<Edge<T4>> parents;  // List of parents


                Node(T4 data, list<Node<T4>> edges, vector<Edge<T4>> parents) {
                    this->data = data;
                    this->edges = edges;
                    this->parents = parents;
                }
        };

        map<T1, Node<T2>> _graphNodes;

    public:

        // Constructors
        Graph();
        Graph(Graph &otherGraphInstance);
        Graph(Graph &&otherGraphInstance);

        // Searches
        T1& DFS(T1 index);
        T1& BFS(T1 index);

        // Create
        void push(T1 index, T2 data, T1& (*searchAlgorithm)(T1 index) = DFS);

        // Read
        T2& operator[](T1 index);

        // Delete
        void pop(T1 index);
        void pop(T2 data);
};

// Implementations
template<typename T1, typename T2>
Graph<T1, T2>::Graph() {

}

template<typename T1, typename T2>
Graph<T1, T2>::Graph(Graph &otherGraphInstance) {

}

template<typename T1, typename T2>
Graph<T1, T2>::Graph(Graph &&otherGraphInstance) {

}

template<typename T1, typename T2>
T1& Graph<T1, T2>::DFS(T1 index) {
    /*
    Depth-First Search
    */
    
}

template<typename T1, typename T2>
T1& Graph<T1, T2>::BFS(T1 index) {
    /*
    Breadth-First Search
    */

}

template<typename T1, typename T2>
void Graph<T1, T2>::push(T1 index, T2 data, T1& (*searchAlgorithm)(T1 index)) {
    cout << index << endl;
    cout << data << endl;
    // pair<T1, Node<T2>> newPair;
    // if (_graphNodes.empty()) newPair = new pair(index, Node<T2>(data));
    // else {
        
    // }

    // _graphNodes.emplace(newPair);
}

template<typename T1, typename T2>
T2& Graph<T1, T2>::operator[](T1 index) {

}

template<typename T1, typename T2>
void Graph<T1, T2>::pop(T1 index) {

}

template<typename T1, typename T2>
void Graph<T1, T2>::pop(T2 data) {

}


int main() {
    Graph<int, string> graph;
    string str = "Hello, World!";
    graph.push(5, str);
}