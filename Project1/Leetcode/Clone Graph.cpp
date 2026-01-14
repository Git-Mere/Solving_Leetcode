#include "Graph.h"

Node* test_help() {
    Node* arr[4];
    Node* node1 = new Node(1);
    Node* node2 = new Node(1);
    Node* node3 = new Node(1);
    Node* node4 = new Node(1);

    return arr;
}

Node* Graph::cloneGraph(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }

    Node* first_node = new Node((*node).val);
    if ((*first_node).neighbors.empty()) {
        return first_node;
    }
    Node* current = first_node;
    queue<Node*> waiting_list;
    waiting_list.push(first_node);

    while (!waiting_list.empty()) {
        current = waiting_list.front();
        waiting_list.pop();

        Node* listnode = node + (*current).val - 1;
        for (int i = 0; i < (*listnode).neighbors.size(); i++) {
            if (find((*current).neighbors.begin(), (*current).neighbors.end(), listnode->neighbors[i])
                == (*current).neighbors.end()) {
                Node* nei = new Node((*listnode).neighbors[i]->val);
                (*nei).neighbors.push_back(current);
                (*first_node).neighbors.push_back(nei);
                waiting_list.push(nei);
            }
        }
    }


    return first_node;
}