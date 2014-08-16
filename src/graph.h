#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
using namespace std;

class Graph{
	private:
		vector<GraphVertex> vertexList;
		initialGraph(string fileName);
	public:
		explicit Graph(string fileName);
		~Graph();
};
#endif
