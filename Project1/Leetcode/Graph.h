#pragma once
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <stack>


using namespace std;

//for Clone Graph
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



namespace Graph {
	//Node* cloneGraph(Node* node);
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites);
}