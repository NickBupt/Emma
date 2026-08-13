#include<bits/stdc++.h>
using namespace std;

void printSet(set<int> s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
        cout << *it << " ";
    cout << endl;
}

void createSet()
{
    set<int> s;
    for (int i = 0; i < 10; ++i)
        s.insert(i+1);
    printSet(s);
}

void traverse()
{
    std::set<int> s;
    for (int i = 0; i < 10; ++i)
        s.insert(i+1);

    for (auto item : s)
        cout << item << " ";
    cout << endl;

    s.insert(10);
    std::set<int>::iterator iter;
    for (iter = s.begin(); iter != s.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}

void operations()
{
    set<int> s;
    for (int i = 0; i < 10; ++i)
        s.insert(i+1);
    printSet(s);

    s.insert(10);
    printSet(s);

    s.erase(10);
    printSet(s);

    cout << s.size() << endl;

    set<int>::iterator it;
    it = s.find(20);

    if (it != s.end())
        cout << "The set contains the item." << endl;

    s.clear();
    printSet(s);
}

int main()
{
    operations();
}
