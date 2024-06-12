#include "Graph.h"

Graph::~Graph()
{
}

void Graph::AddEdge(int from, int to)
{
    if (from == to)
        return;
    adjList[from].push_back(to);
    adjList[to].push_back(from);
}

Graph::Graph(string path) {
    ifstream file(path);
    if (!file.is_open()) {
        cerr << "Failed to open file " << path << endl;
        return;
    }

    int max_vertex_index = 0;
    int from, to;
    while (file >> from >> to) {
        if (file.fail()) {
            cerr << "Failed to read from file " << path << endl;
            break;
        }
        max_vertex_index = max(max_vertex_index, max(from, to));
    }
    file.close();

    adjList = vector<vector<int>>(max_vertex_index + 1);

    file.open(path);
    while (file >> from >> to) {
        if (file.fail()) {
            cerr << "Failed to read from file " << path << endl;
            break;
        }
        AddEdge(from, to); 
    }
    file.close();
}

int Graph::DFS(int v, vector<bool>& visited, vector<int>& component)
{
    visited[v] = true;
    component.push_back(v);

    stack<int> stk;
    stk.push(v); 

    while (!stk.empty()) {  
        int curr = stk.top();
        stk.pop();

        for (int i = 0; i < adjList[curr].size(); i++) {  
            int to = adjList[curr][i];
            if (!visited[to]) {     
                visited[to] = true;
                component.push_back(to); 
                stk.push(to);
            }
        }
    }

    return component.size();
}

int Graph::findEccentricities(int start, vector<bool>& visited)
{
    queue<int> q;   
    vector<int> distance(adjList.size(), 0);   

    q.push(start);
    visited[start] = true;     

    int eccentricity = 0;

    while (!q.empty()) {               
        int current = q.front();
        q.pop();

        for (int neighbor : adjList[current]) {   
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[current] + 1;    

                eccentricity = max(eccentricity, distance[neighbor]);  
                q.push(neighbor);         
            }
        }
    }

    return eccentricity;   
}


void Graph::radiusdiameter(int& radius, int& diameter) {
    
    radius = INT_MAX;
    diameter = INT_MIN; 

    vector<bool> visited(adjList.size(), false);

    int largestComponentSize = 0;
    vector<int> largestComponentNodes; 

    for (int i = 0; i < adjList.size(); i++) {  
        if (!visited[i]) {                     
            vector<int> componentNodes;         
            int componentSize = DFS(i, visited, componentNodes);
            if (componentSize > largestComponentSize) {
                largestComponentSize = componentSize;
                largestComponentNodes = componentNodes;
            }   
        }
    }
    
    vector<bool> visitedBFS(adjList.size()); 

    for (int node : largestComponentNodes) {
        visitedBFS.assign(adjList.size(), false);
        visitedBFS[node] = true;

        int eccentricity = findEccentricities(node, visitedBFS);  

        radius = min(radius, eccentricity);
        diameter = max(diameter, eccentricity);  
    }
}

void Graph::PrintProperties() {
    int radius, diameter;
    radiusdiameter(radius, diameter);

    cout << "The Diameter Of The Graph Is: " << diameter << endl;
    cout << "The Radius Of The Graph Is: " << radius << endl;
}
