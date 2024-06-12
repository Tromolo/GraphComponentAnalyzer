#include "Graph.h"
#include <iostream>
#include <chrono>

using namespace std;

int main()
{
	Graph graph("graph1.txt");
	graph.PrintProperties();

	return 0;
}