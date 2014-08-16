#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H
#include <iostream>
using namespace std;

class GraphEdge{
	private:
		//int startID;
		//int endID;
		int nextID;
		int distance;
	public:
		//explicit GraphEdge(int startID, int endID, int distance);
		explicit GraphEdge(int nextID, int distance);
		int getStartID();
		int getEndID();
		int getDistance();
		~GraphEdge();
}
#endif
