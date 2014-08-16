#ifndef GRAPH_VERTEX_H
#define GRAPH_VERTEX_H
#include <iostream>
using namespace std;

class GraphVertex{
	private:
		int ID;
		float safetyIndex;
		string name;
		vector<GraphEdge> edges;
	public:
		explicit GraphVertex(int id, float safetyIndex, string name);
		int getId();
		float getSafetyIndex();
		string getName();
		~GraphVertex();
}
#endif
