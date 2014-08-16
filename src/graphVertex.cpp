#include "graphVertex.h"

GraphVertex::GraphVertex(int id, float safetyIndex, string name){
	this->id = id;
	this->safetyIndex = safetyIndex;
	this->name = name;
}

int GraphVertex::getId(){
	return id;
}

float GraphVertex::getSafetyIndex(){
	return safetyIndex;
}

string GraphVertex::getName(){
	return name;
}

void GraphVertex::addEdge(GraphEdge edge){
	edges.push_back(edge);
}

GraphVertex::~GraphVertex(){

}
