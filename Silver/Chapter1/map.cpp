#include<bits/stdc++.h>
using namespace std;

void printMap(map<string, int> m)
{
    for (auto it = m.begin(); it != m.end(); it++)
        cout << it->first << " " << (*it).second << endl;
}

void createMap()
{
    map<string, int> m;
    m.insert({"a", 1});
    m.insert(make_pair("b", 2));
    m.insert(pair<string, int>("c", 3));
    m["d"] = 4;
    printMap(m);
}

void traversal()
{
    map<string, int> m;
    m.insert({"a", 1});
    m.insert(make_pair("b", 2));
    m.insert(pair<string, int>("c", 3));
    m["d"] = 4;

    for (auto item : m)
        cout << item.second << " ";
    cout << endl;

    map<string, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); ++iter)
        cout << iter->second << " ";
    cout << endl;
}

void operations()
{
    map<string, int> m;
    m.insert({"a", 1});
    m.insert(make_pair("b", 2));
    m.insert(pair<string, int>("c", 3));
    m["d"] = 4;
    m["d"] = 5;
    printMap(m);

    m.erase("d");
    printMap(m);

    cout << m.size() << endl;

    map<string, int>::iterator it;
    it = m.find("c");
    if (it != m.end())
        cout << it->second << endl;

    m.clear();
    printMap(m);
}

struct Node
{
    int data;
    string str;
    Node(int data, string str) : data(data), str(str) {}
    bool operator==(const Node& node2) const
    {
        return data == node2.data && str.size() == node2.str.size();
    }
};

struct hsh
{
    size_t operator()(const Node& n) const
    {
        return n.data * n.str.size();
    }
};

void unorderedMap()
{
    unordered_map<Node, int, hsh> unorderedMap;
    Node n1(1, "a");
    Node n2(2, "ab");
    Node n3(3, "abc");
    Node n4(3, "bcd");

    unorderedMap.insert({n1, 1});
    unorderedMap.insert({n2, 2});
    unorderedMap.insert({n3, 3});
    unorderedMap.insert({n4, 4});

    for (auto item : unorderedMap)
        cout << item.first.str << endl;
}

int main()
{
    unorderedMap();
}
