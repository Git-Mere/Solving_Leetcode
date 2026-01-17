#include "Binary.h"
#include "Array.h"
#include "Dynamic Programming.h"
#include "Graph.h"

Node* test_help() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node3);
    node1->neighbors.push_back(node4);

    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node7);

    node3->neighbors.push_back(node1);

    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node5);
    node4->neighbors.push_back(node6);
    node4->neighbors.push_back(node8);

    node5->neighbors.push_back(node4);

    node6->neighbors.push_back(node4);

    node7->neighbors.push_back(node2);

    node8->neighbors.push_back(node4);


    return node1;
}

int main() {

	Graph::cloneGraph(test_help());

    return 0;
}