#include "Binary.h"
#include "Array.h"
#include "Dynamic Programming.h"
#include "Graph.h"

vector<vector<int>> test_help() {
	vector<vector<int>> prerequisites;
	prerequisites.push_back({ 5,5,5,5 });
	prerequisites.push_back({ 4,4,4,4 });
	prerequisites.push_back({ 5,5,5,5 });
	return prerequisites;
}

int main() {
	vector<vector<int>> test = test_help();
	Graph::pacificAtlantic(test);

    return 0;
}