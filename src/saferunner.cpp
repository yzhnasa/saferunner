#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
	if(argc != 4){
		usage(argv[0], stderr);
		exit(1);
	}
	Graph graph = new Graph(argv[3]);
	graph.findRoute(argv[1], argv[2]);
}

void usage(char *progName){
	cerr << progName << " distanceInMiles startingIntersection streeMapGraphFile" << endl;
}
