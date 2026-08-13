#include <iostream>
#include<map>
#include<set>
using namespace std;

// Undirected, no weight
void createGraph1(vector<pair<int, int>> edges)
{
    map<int, set<int>> graph;
    for (auto& e: edges)
    {
        graph[e.first].insert(e.second);
        graph[e.second].insert(e.first);
    }

    for (auto& v: graph)
    {
        cout << v.first << ": ";
        for (auto& nei: v.second)
            cout << nei << " ";
        cout << endl;
    }

    cout << endl;
}

// Directed, no weight
void createGraph2(vector<pair<int, int>> edges)
{
    map<int, set<int>> graph;
    for (auto& e: edges)
    {
        graph[e.first].insert(e.second);
    }

    for (auto& v: graph)
    {
        cout << v.first << ": ";
        for (auto& nei: v.second)
            cout << nei << " ";
        cout << endl;
    }

    cout << endl;
}

struct Edge{
    int v,u,w;
    Edge(int v,int u,int w):v(v),u(u),w(w){}
};

// Undirected, with weight
void createGraph3(vector<Edge> edges)
{
    map<int, map<int, int>> graph;
    for (auto& e: edges)
    {
        graph[e.v].insert({e.u, e.w});
        graph[e.u].insert({e.v, e.w});
    }

    for (auto& v: graph)
    {
        cout << v.first << ": ";
        for (auto& nei: v.second)
            cout << nei.first << "," << nei.second << " ";
        cout << endl;
    }

    cout << endl;
}


// Directed, with weight
void createGraph4(vector<Edge> edges)
{
    map<int, map<int, int>> graph;
    for (auto& e: edges)
    {
        graph[e.v].insert({e.u, e.w});
    }

    for (auto& v: graph)
    {
        cout << v.first << ": ";
        for (auto& nei: v.second)
            cout << nei.first << "," << nei.second << " ";
        cout << endl;
    }

    cout << endl;
}

// Undirected, no weight
void createGraphVector1(vector<pair<int, int>> edges, int n)
{
    vector<vector<int>> graph(n+1);
    for (auto& e: edges)
    {
        graph[e.first].push_back(e.second);
        graph[e.second].push_back(e.first);
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << i << ": ";
        for (auto& nei: graph[i])
            cout << nei << " ";
        cout << endl;
    }

    cout << endl;
}

int main()
{
    int n = 5;
    vector<pair<int, int>> edges;//边集
    edges.push_back({1, 2});
    edges.push_back({1, 3});
    edges.push_back({3, 4});
    edges.push_back({4, 5});
    edges.push_back({2, 5});

    createGraph1(edges);
    createGraph2(edges);

    createGraphVector1(edges, n);

    vector<Edge> edgesWithWeight;
    edgesWithWeight.push_back(Edge(1, 2, 10));
    edgesWithWeight.push_back(Edge(1, 3, 11));
    edgesWithWeight.push_back(Edge(3, 4, 12));
    edgesWithWeight.push_back(Edge(4, 5, 13));
    edgesWithWeight.push_back(Edge(2, 5, 14));

    createGraph3(edgesWithWeight);
    createGraph4(edgesWithWeight);
}
