#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int flow;
    int capacity;
    int u, v;
    Edge(int flow, int capacity, int u, int v){
        this->flow = flow;
        this->capacity = capacity;
        this->u = u;
        this->v = v;
    }
};

struct Vertex
{
    int height, e_flow;
    Vertex(int height, int e_flow)
    {
        this->height = height;
        this->e_flow = e_flow;
    }
};
class Graph
{
    int V;
    vector<Vertex> vertex;
    vector<Edge> edge;
    bool push(int u);
    void relabel(int u);
    void preflow(int source);
    void ReverseEdgeFlowUpdate(int i, int flow);
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    int getMaximumFlow(int source, int sink);
};

Graph::Graph(int V)
{
    this->V = V;
    for (int i = 0; i < V; i++)
        vertex.push_back(Vertex(0, 0));
}

// To push flow from overflowing Vertex u
bool Graph::push(int u)
{
    for (int i=0; i <edge.size(); i++){
        if (edge[i].u == u){
            if (edge[i].flow == edge[i].capacity)
                continue;
            if (vertex[u].height > vertex[edge[i].v].height){
                int flow = min(edge[i].capacity - edge[i].flow, vertex[u].e_flow);
                vertex[u].e_flow = vertex[u].e_flow-flow;
                vertex[edge[i].v].e_flow = vertex[edge[i].v].e_flow + flow;
                edge[i].flow = edge[i].flow + flow;
                ReverseEdgeFlowUpdate(i, flow);
                return true;
            }
        }
    }
    return false;
}
void Graph::relabel(int u)
{
    int maximum_height = INT_MAX;
    int n=edge.size();
    for (int i = 0; i < n; i++){
        if (edge[i].u == u){
            if (edge[i].flow == edge[i].capacity)
                continue;
            if (vertex[edge[i].v].height < maximum_height){
                maximum_height = vertex[edge[i].v].height;
                vertex[u].height = maximum_height + 1;
            }
        }
    }
}
void Graph::preflow(int source)
{
    vertex[source].height = vertex.size();
    int n=edge.size();
    for (int i = 0; i < n; i++){
        if (edge[i].u == source){
            edge[i].flow = edge[i].capacity;
            vertex[edge[i].v].e_flow = vertex[edge[i].v].e_flow + edge[i].flow;
            edge.push_back(Edge(-edge[i].flow, 0, edge[i].v, source));
        }
    }
}
void Graph::addEdge(int u, int v, int capacity)
{
    edge.push_back(Edge(0, capacity, u, v));
}
void Graph::ReverseEdgeFlowUpdate(int i, int flow)
{
    int u = edge[i].v;
    int v = edge[i].u;
    int j=0, n=edge.size();
    while (j < n){
        if (edge[j].v == v && edge[j].u == u){
            edge[j].flow -= flow;
            return;
        }
        j++;
    }
    Edge e = Edge(0, flow, u, v);
    edge.push_back(e);
}
int overFlowVertex(vector<Vertex>& vertex)
{
    int n=vertex.size();
    for (int i = 1; i < n - 1; i++)
        if (vertex[i].e_flow > 0)
            return i;
    return -1;
}
int Graph::getMaximumFlow(int source, int sink)
{
    preflow(source);
    while (overFlowVertex(vertex) != -1){
        int u = overFlowVertex(vertex);
        if (!push(u))
            relabel(u);
    }
    return vertex.back().e_flow;
}
int main()
{
    int V = 6;
    Graph g(V);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 3, 10);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 2, 4);
    g.addEdge(1, 4, 8);
    g.addEdge(3, 4, 9);
    g.addEdge(2, 5, 10);
    g.addEdge(4, 5, 10);
    g.addEdge(4, 2, 6);
    int source = 0, sink = 5;
    cout << "Maximum flow is " << g.getMaximumFlow(source, sink);
    return 0;
}