//
// Created by QianXi_Local on 2023/3/24.
//
#include <iostream>

#define MAX_SIZE 50

using namespace std;

struct SqList {  //在c++中可以不需要typedef因为在c++中struct也是一种类，但c不可以
    int data[MAX_SIZE];
    int length;
};

/*!
 * P17 二.01
 * 遍历顺序表
 * 空间复杂度O(1)
 * 时间复杂度O(n) 取决与顺序表长度
 */
bool deleteSqListNum_01(SqList &L, int &e) {
    if (L.length = 0) {
        cout << "顺序表为空" << endl;
        return false;
    }
    int minNum = L.data[0];
    int minIndex = 0;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] < minNum) {
            minNum = L.data[i];
            minIndex = i;
        }
    }
    e = minNum;
    L.data[minIndex] = L.data[L.length - 1];
    L.length--;//todo ！！在移除数据后顺序表长度应减一
    return true;
}

/*!
 * P17 二.02
 * 首尾双指针对应替换
 * 空间复杂度 O(1) -- 3个 int 变量
 * 时间复杂度 O(n) -- 运行 L.length/2 次
 */
void reverseSqList(SqList &L) {
    int firstIndex = 0;
    int lastIndex = L.length - 1;
    int temp;
    while (lastIndex > firstIndex) {
        temp = L.data[firstIndex];
        L.data[firstIndex] = L.data[lastIndex];
        L.data[lastIndex] = temp;
        firstIndex++;
        lastIndex--;
    }
}

/*!
 * P17 二.03
 * 删除顺序表所有指定元素
 * 空间复杂度 O(1) -- 1个 int 变量
 * 时间复杂度 O(n) -- 运行L.length次
 */
void deleteSqListNum_03(SqList &L, int n) {
//    for (int i = 0; i < L.length; ++i) {//todo 时间复杂度不满足
//        if (L.data[i]==n){
//            for (int j = i; j <L.length-1 ; ++j) {
//                L.data[j]=L.data[j+1];
//
//            }
//        }
    int newIndex = 0;//不等于x的元素计数
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] != n) {
            L.data[newIndex] = L.data[i];
            newIndex++;
        }
    }
    L.length = newIndex;

};


int main() {
    SqList L;
    for (int i = 0; i < 9; ++i) {
        L.data[i]=i;
        cout<<L.data[i]<<" ";
        L.length++;
    }
    cout<<endl;
    deleteSqListNum_03(L, 4);
    for (int i = 0; i < L.length; ++i) {
        cout<<L.data[i]<<" ";
    }
    return 0;
}
