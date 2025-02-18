/* 
   function Dijkstra();
   function readGraphFromFile(filename):
    graph = empty unordered_map
    open filename
    for each line in filename:
        read u, v, w from line
        add {v, w} to graph[u]
    close filename
    return graph

*/

#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <unordered_map>

using namespace std;

struct Edge {
    int target;
    int weight;
};

unordered_map<int, vector<Edge>> readGraphFromFile(const string& filename) {
    unordered_map<int, vector<Edge>> graph;

    ifstream file(filename);

    if (file.is_open()) {
        int u, v, w;
        while (file >> u >> v >> w) {
            graph[u].push_back({v, w});
        }

        file.close();
    } else {
        cerr << "Unable to open file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    return graph;
}

int main() {
    unordered_map<int, vector<Edge>> graphFromFile = readGraphFromFile("USA-road-d.FLA");

    int source, target;

    cout << "Enter source node: ";
    cin >> source;

    cout << "Enter target node: ";
    cin >> target;
    //Dijkstra(const GRAPH& graph, const std::vector<int>& weight)  function defined im Dijkstra.h
    int shortestPathLengthFromFile = dijkstra(graphFromFile, source, target);

    cout << "Shortest Path Length (Different Approach): " << shortestPathLengthFromFile << endl;

    return 0;
}


