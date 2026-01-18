//#include "Graph.h"
//
//class Node {
//public:
//    int val;
//    vector<Node*> neighbors;
//    Node() {
//        val = 0;
//        neighbors = vector<Node*>();
//    }
//    Node(int _val) {
//        val = _val;
//        neighbors = vector<Node*>();
//    }
//    Node(int _val, vector<Node*> _neighbors) {
//        val = _val;
//        neighbors = _neighbors;
//    }
//};
//
//void help(vector<Node*> visited, Node* node, Node* current) {
//    vector<Node*>* origin_node_vec = &node->neighbors;
//    for (int i = 0; i < (*origin_node_vec).size(); i++) {
//        if ((*origin_node_vec)[i] == (*current).neighbors[i]) {
//            if (visited[(*current).neighbors[i]->val]) {
//                (*current).neighbors[i] = visited[(*current).neighbors[i]->val];
//            }
//            else {
//                (*current).neighbors[i] = new Node((*origin_node_vec)[i]->val, (*origin_node_vec)[i]->neighbors);
//                visited[(*current).neighbors[i]->val] = (*current).neighbors[i];
//
//            }
//            Node* tmp = (*current).neighbors[i];
//            for (int j = 0; j < tmp->neighbors.size(); j++) {
//                if (tmp->neighbors[j]->val == current->val) {
//                    tmp->neighbors[j] = current;
//                    break;
//                }
//            }
//            help(visited, (*origin_node_vec)[i], (*current).neighbors[i]);
//        }
//    }
//}
//
//Node* Graph::cloneGraph(Node* node) {
//    if (node == nullptr) {
//        return nullptr;
//    }
//    Node* first_node = new Node(node->val, node->neighbors);
//    Node* current = first_node;
//    vector<Node*> visited(101, nullptr);
//    visited[current->val] = current;
//    help(visited, node, current);
//
//    return first_node;
//}