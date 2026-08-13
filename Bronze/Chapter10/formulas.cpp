#include<iostream>
using namespace std;
//计算长度，宽，面积
long long area(int x1,int y1,int x2,int y2){
    long long length = x2 - x1;
    long long width = y2-y1;
    return length * width;
}
//判断是否有重合
bool intersect(vector<int> s1,vector<int> s2){
    int bl_ax = s1[0], bl_ay=s1[1], tr_ax = s1[2], tr_ay = s1[3];
    int bl_bx = s2[0], bl_by=s2[1], tr_bx = s2[2], tr_by = s2[3];

    if(bl_ax>=tr_bx||tr_ax<=bl_bx||bl_ay>=tr_by||tr_ay<=bl_by){
        return false;
    }else{
        return true;
    }
}
//计算重合部分面积
int intersectionArea(vector<int> s1,vector<int> s2){
    int bl_ax = s1[0], bl_ay=s1[1], tr_ax = s1[2], tr_ay = s1[3];
    int bl_bx = s2[0], bl_by=s2[1], tr_bx = s2[2], tr_by = s2[3];

    return (min(tr_ax, tr_bx) - max(bl_ax, bl_bx)) *
           (min(tr_ay, tr_by) - max(bl_ay, bl_by));
}