#include "Test.h"
#include <iostream>
#define INF 1000000000
using namespace std;

struct Edge
{
    int from, to, weight;
};

vector<Edge> getEdges(int ** graph, int size)
{
    vector<Edge> edges;
    for (int i = 0; i <size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(graph[i][j]!=-1)
            {
                Edge edge;
                edge.from = i;
                edge.to = j;
                edge.weight = graph[i][j];
                edges.push_back(edge);
            }
        }
    }
    return edges;
}

int* getShortestPath(int** graph, int size, int origin)
{
    int V = size;
    vector<Edge > edges = getEdges(graph,size);
    int E = edges.size();
    int dist[size];
    int * pred = new int[size];

      for (int i = 0; i < V; i++)
      {
            dist[i] = INF;
            pred[i] = NULL;
      }
    dist[origin] = 0;

  for (int i = 1; i <= V-1; i++)
   {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j].from;
            int v = edges[j].to;
            int weight = edges[j].weight;
            if (dist[u] + weight < dist[v] && dist[u]!=INF)
            {
                dist[v] = dist[u] + weight;
                pred[v] = u;
            }
        }
    }


    for (int i = 0; i < E; i++)
    {
        int u = edges[i].from;
        int v = edges[i].to;
        int weight = edges[i].weight;
        if (dist[u] != INF && dist[u] + weight < dist[v])
            printf("Graph contains negative weight cycle");
    }

    return pred;
}

int main ()
{
    test();
    return 0;
}
