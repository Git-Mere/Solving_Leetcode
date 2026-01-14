#pragma once
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

namespace Graph {
	Node* cloneGraph(Node* node);
}