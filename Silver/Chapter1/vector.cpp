#include<iostream>
#include <vector>
using namespace std;


void printVector(vector<int> v)
{
//    for(auto it = v.begin();it!=v.end();it++){
//        cout << *it << endl;
//    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
}

void createVectors()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i)
        v.push_back(i + 1);//1,2,3,4,5,6,7,8,9,10
    printVector(v);

    vector<int> v1(v.begin(), v.end()-1);
    printVector(v1);

    vector<int> v2(10, 1);// 创建一个含有10个1的vector
    printVector(v2);

    vector<int> v3(v2);
    printVector(v3);
}

void traversal()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i)
        v.push_back(i + 1);

    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    for (int item : v)
        cout << item << " ";
    cout << endl;

    for (auto &item : v)
        item++;
    printVector(v);

    vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}

void operations(){
    vector<int> v;
    for (int i = 0; i < 10; ++i)
        v.push_back(i + 1);

    cout << v.size() << endl;
    cout << v[0] << endl;
    cout << v.at(1) << endl;//v[1]
    cout << v.front() << endl;
    cout << v.back() << endl;

    v.push_back(100);
    printVector(v);

    v.pop_back();
    printVector(v);//1 2 3 4 5 6 7 8 9 10

    v.insert(v.begin() + 3, 20);//1 2 3 20 4 5 6 7 8 9 10
    printVector(v);

    v.erase(v.begin());//2 3 20 4 5 6 7 8 9 10
    printVector(v);

    v.erase(v.begin(), v.begin() + 3);//4 5 6 7 8 9 10
    printVector(v);

    v.clear();
    printVector(v);

    if(v.empty()){
        cout << "vector is empty" <<endl;
    }

    v.resize(20);//扩展，后续位默认为0
    printVector(v);

}

int main()
{
    operations();
}
