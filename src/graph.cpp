#include "graph.h"

Graph::Graph(char *fileName){
	fstream inputFile(fileName, ios::in);
	GraphVertex tempVertex = NULL;
	string tempLine;
	if(inputFile.fail())
		exit(1);
	if(getline(inputFile, tempLine, '\n') == "INTERSECTIONS:\n"){
		while(!inputFile.eof()){
			getline(inputFile, tempLine, '\n');
			if(tempLine == '\n')
				break;
			else
				putIntoVertexList(tempLine);
		}
	}
	if(getline(inputFile, tempLine, '\n') == "STREETS:\n"){
		while(!inputFile.eof()){
			getline(inputFile, tempLine, '\n');
			putIntoEdgeList(tempLine);
		}
	}
}

void Graph::putIntoVertexList(string line){
	vector<char> tempWord;
	int ID;
	float safetyIndex;
	string name;
	GraphVertex tempVertex;
	int countT = 0;
	int i = 0;
	while(i != line.size()){
		if(line[i] == '\t' || line[i] == '\n'){
			countT++;
			if(countT == 1){
				ID = stoi(tempWord, tempWord.size());
				if(searchVertexID(ID) != NULL)
					exit(1);
			}
			if(countT == 2)
				safetyIndex = stof(tempWord, tempWord.size());
			if(countT == 3){
				name = tempWord;
				tempVertex = new GraphVertex(ID, safetyIndex, name);
				vertexList.push_back(tempVertex);
				countT = 0;
			}
			tempWord.clear();
		}else{
			tempWord.push_back(line[i]);
		}
		i++;
	}
}

void Graph::putIntoEdgeList(string line){
	vector<char> tempWord;
	int startID;
	int endID;
	int distance;
	GraphEdge tempEdge;
	GraphVertex tempVertex;
	int countT = 0;
	int i = 0;
	while(i != line.size()){
		if(line[i] == '\t' || line[i] == '\n' || line[i] == '\t'){
			countT++;
			if(countT == 1)
				startID = stoi(tempWord, tempWord.size());
			if(countT == 2)
				endID = stoi(tempWord, tempWord.size());
			if(countT == 3){
				distance = stoi(tempWord, tempWord.size());
				tempEdge = new GraphEdge(endID, distance);
				tempVertex = searchVerdexID(startID);
				if(tempVertex != NULL)
					tempVertex.addEdge(tempEdge);
				else
					exit(1);
				tempEdge = new GraphEdge(startID, distance);
				tempVertex = searchVertexID(endID);
				if(tempVertex != NULL)
					tempVertex.addEdge(tempEdge);
				else
					exit(1);
				countT = 0;
			}
		}
	}
}

GraphVertex &Graph::searchVertexID(int ID){
	vector<GraphVertex>::iterator itr;
	for(itr = vertexList.begin(); itr != vertexList.end(); itr++){
		if((*itr).getID() == ID)
			return itr;
	}
	return NULL;
}

void Graph::findRoute(int distance, int startID){
	GraphVertex startVertex = searchVertexID(startID);
	if(startID == NULL)
		exit(1);
	vector<GraphEdge>
}

Graph::~Graph(){

}
