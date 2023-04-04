#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > FormAdjMatrix(){
    vector< vector<int> > adjMatrix;
    const int n = 6;
    for(int i = 0; i < n; i++){
        vector<int> row;
        adjMatrix.push_back(row);
        for(int j = 0; j < n; j++)
            adjMatrix[i].push_back(0);
    }
    adjMatrix[0][1] = 15;
    adjMatrix[0][2] = 12;
    adjMatrix[1][2] = 9;
    adjMatrix[1][3] = 11;
    adjMatrix[2][1] = 5;
    adjMatrix[2][4] = 13;
    adjMatrix[3][2] = 9;
    adjMatrix[3][5] = 25;
    adjMatrix[4][3] = 8;
    adjMatrix[4][5] = 6;
    return adjMatrix;
}
bool BFS(vector< vector<int> > &resAdjMatrix, int &source, int &sink, vector<int> &parent){
    int n = resAdjMatrix.size();
    bool visited[n] = { false };   
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;
    while(q.empty() == false){
        int u = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            int v = i;
            int capacity = resAdjMatrix[u][v];
            if(visited[v] == false && capacity > 0){
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    } 
    if(visited[sink] == true) 
        return true; 
    return false;
}
int FordFulkerson(vector< vector<int> > &adjMatrix, int &source, int &sink){
    int maxflow = 0;
    vector< vector<int> > resAdjMatrix;
    int n = adjMatrix.size();
    for(int i = 0; i < n; i++){
        vector<int> row;
        resAdjMatrix.push_back(row);
        for(int j = 0; j < adjMatrix[i].size(); j++)
            resAdjMatrix[i].push_back(adjMatrix[i][j]);
        
    }
    vector<int> parent;
    for(int i = 0; i < n; i++)
        parent.push_back(-1);
    while(BFS(resAdjMatrix, source, sink, parent) == true){
        int pathflow = 10000007;
        int v = sink;
        while(v != source){
            int u = parent[v]; // The parent.
            int capacity = resAdjMatrix[u][v];
            pathflow = min(pathflow, capacity);
            v = u;
        }
        v = sink;
        while(v != source){
            int u = parent[v];
            resAdjMatrix[u][v] -= pathflow;
            resAdjMatrix[v][u] += pathflow;
            v = u;
        }
        maxflow += pathflow;
    }
    return maxflow;
}  
int main() 
{
    cout << "Program started.\n";
    vector< vector<int> > adjMatrix = FormAdjMatrix();
    int source = 0,sink = 6;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            int source = i,sink = j;
            if(i == j) { continue; }
            cout << "The max flow from " << source << " to " << sink << " is: ";
            cout << FordFulkerson(adjMatrix, source, sink) << endl;
        }
        cout << endl;
    }
    cout << "Program ended.\n";
    return 0;
}