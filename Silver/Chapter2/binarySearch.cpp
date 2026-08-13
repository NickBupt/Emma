#include <iostream>
#include<vector>
using namespace std;

// Find the index in the list (no repeated numbers) where the corresponding number is equal to target
int binarySearch1(vector<int> list, int target)
{
    int start = 0;
    int end = list.size() - 1;
    while(start <= end)
    {
        int mid = (start + end) / 2;
        if (list[mid] == target)
            return mid;
        if (list[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

//find the min index in the list where the corresponding number is equal to target
//1 2 3 3 3 4 5
int binarySearch2_1(vector<int> list, int target)
{
    int start = 0;
    int end = list.size() - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (list[mid] >= target)
            end = mid;
        else
            start = mid + 1;
    }
    if (list[start] == target)
        return start;
    else
        return -1;
}

// Find the max index in the list where the corresponding number is equal to target
int binarySearch2_2(vector<int> list, int target)
{
    int start = 0;
    int end = list.size() - 1;
    while (start < end)
    {
        int mid = (start + end) / 2 + 1;
        if (list[mid] <= target)
            start = mid;
        else
            end = mid - 1;
    }

    if (list[start] == target)
        return start;
    else
        return -1;
}

// Find the max index in the list where the corresponding number is less than or equal to target
int binarySearch3_1(vector<int> list, int target)
{
//    ios::sync_with_stdio(false);//解除scanf和printf的绑定
//    cin.tie(0);//免除缓冲区的刷新
    if (list.empty() || list[0] > target)
        return -1;
    int start = 0;
    int end = list.size() - 1;
    while(start < end)
    {
        int mid = (start + end) / 2 + 1;
        if (list[mid] <= target)
            start = mid;
        else
            end = mid - 1;
    }
    return start;
}

// Find the min index in the list where the corresponding number is greater than or equal to target
int binarySearch3_2(vector<int> list, int target)
{
    if (list.empty() || list[list.size() - 1] < target)
        return -1;
    int start = 0;
    int end = list.size() - 1;
    while(start < end)
    {
        int mid = (start + end) / 2;
        if (list[mid] >= target)
            end = mid;
        else
            start = mid + 1;
    }
    return start;
}

void lower_bound_upper_bound()
{
    vector<int> v(10);
    for (int i = 0; i < 10; ++i)
        v[i] = i + 1;//v:1 2 3 4 5 6 7 8 9 10
    int index = lower_bound(v.begin(), v.end(), 3) - v.begin();//>=
    cout << index << endl;

    index = lower_bound(v.begin(), v.end(), 11) - v.begin();
    cout << index << endl;

    index = upper_bound(v.begin(), v.end(), 3) - v.begin();//>
    cout << index << endl;

    index = upper_bound(v.begin(), v.end(), 11) - v.begin();
    cout << index << endl;

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << lower_bound(arr, arr+5, 3) - arr << endl;
}


int main() {
    vector<int> v;
    for (int i = 0; i < 10; ++i)
        v.push_back(i * 2 + 1);//1 3 5 7 9 11 13 15 17 19
    cout << binarySearch1(v, 7) << endl;
    cout << binarySearch1(v, 1) << endl;
    cout << binarySearch1(v, 11) << endl;

    vector<int> v2;
    for (int i = 0; i < 20; ++i)
        v2.push_back(i % 5);
    sort(v2.begin(), v2.end());//0 0 0 0 0 1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 4 4 4
    for (auto item : v2)
        cout << item << " ";
    cout << endl;

    cout << binarySearch2_1(v2, -1) << " " << binarySearch2_2(v2, 5) << endl;
    cout << binarySearch3_1(v2, 6) << endl;
    cout << binarySearch3_2(v2, 3) << endl;

    lower_bound_upper_bound();
}

