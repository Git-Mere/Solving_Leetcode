#include "Binary.h"
#include "Array.h"
#include "Dynamic Programming.h"
#include "Graph.h"

vector<vector<int>> test_help() {
	vector<vector<int>> prerequisites;
	prerequisites.push_back({ 1,0 });
	prerequisites.push_back({ 2,0 });
	prerequisites.push_back({ 2,3 });
	prerequisites.push_back({ 3,1 });
	prerequisites.push_back({ 1,3 });
	//prerequisites.push_back({ 3,0 });
	return prerequisites;
}

int main() {
	vector<vector<int>> test = test_help();
	cout << Graph::canFinish(test.size(), test);

    return 0;
}