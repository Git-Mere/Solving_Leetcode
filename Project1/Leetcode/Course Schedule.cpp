#include "Graph.h"

class Node {
public:
    int num;
    vector<int> ends;
	vector<Node*> nexts;
    Node(int _num) {
        num = _num;
    }

};

bool end_update(std::vector<Node*>& db, Node* start, Node* end) {
    for (int i = 0; i < db.size(); i++) {
        if (db[i] == nullptr) {
            continue;
        }
		for (int j = 0; j < db[i]->ends.size(); j++) {
            if (db[i]->ends[j] == start->num) {
                if (db[i]->ends[j] == end->num) {
                    return false;
                }
                else {
                    db[i]->ends[j] = end->num;
                }
            }
        }
    }
    return true;
}

bool Graph::canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    std::vector<Node*> v(numCourses, nullptr);
    for (int i = 0; i < prerequisites.size(); i++) {
        Node* course = nullptr;
        Node* precourse = nullptr;
        if (v[prerequisites[i][0]] != nullptr) {
            course = v[prerequisites[i][0]];
        }
        else {
            course = new Node(prerequisites[i][0]);
            v[prerequisites[i][0]] = course;
        }

        if (v[prerequisites[i][1]] != nullptr) {
            precourse = v[prerequisites[i][1]];
        }
        else {
            precourse = new Node(prerequisites[i][1]);
            v[prerequisites[i][1]] = precourse;
        }
        precourse->ends.push_back(prerequisites[i][0]);


        //precourse->nexts.push_back(course);
        if (!end_update(v, precourse, course)) {
            return false;
        }

    }
    return true;
}