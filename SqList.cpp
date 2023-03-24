#include <iostream>
#include "windows.h"

#define MAX_SIZE 50

using namespace std;

/*!
 * 静态顺序表
 */
struct SqList {  //在c++中可以不需要typedef因为在c++中struct也是一种类，但c不可以
    int data[MAX_SIZE];
    int length;
};

/*!
 * 输出顺序表
 * @param L
 */
void PrintSqList(SqList L) {//疑是cout中字符串导致的输出问题导致run和debug的运行内容不同

//    system("chcp 65001");//方案1 影响输出
    SetConsoleOutputCP(CP_UTF8);//方案2 需要导入window.h
    for (int i = 0; i < L.length; ++i) {
        cout << "第" << i + 1 << "个元素为" << L.data[i] << endl;
//      printf("第%d个元素为%d\n", (i + 1), L.data[i]);//测试用C输出方法同样BUG
    }
}

/*!
 * 向顺序表指定位置插入数据
 * @param e 插入数据的值
 * @param index 插入数据的位置
 * @param L 操作的顺序表
 * @return 操作的是否成功
 */
bool insertSqListNum(int e, int index, SqList &L) {

    if (index < 1 or index > L.length + 1)
        return false;
    if (L.length >= MAX_SIZE)
        return false;
    for (int i = L.length; i >= index; --i) {
        L.data[i] = L.data[i - 1];
    }
    L.data[index - 1] = e;
    L.length++;
    return true;
}

/*!
 * 向顺序表指定删除第几个数据
 * @param index 插入数据的位置
 * @param L 操作的顺序表
 * @return 操作的是否成功
 */
bool deleteSqListNum(int index, SqList &L) {
    if (index < 1 or index > L.length)
        return false;
    for (int i = index - 1; i <= L.length; ++i) {
        L.data[i] = L.data[i + 1];
    }
    L.length--;
    return true;
}

/*!
 * 向传入顺序表中增加指定的从0开始的升序整数
 * @param L 操作的顺序表
 * @param n 需要增加的数据位数
 */
void intiSqList(SqList &L, int n) {
    L.length = 0;
    for (int i = 0; i < n; ++i) {
        L.data[i] = i;
        L.length += 1;
    }

}
/*!
 * 在顺序表中查找第一个元素等于e的元素
 * @param L 查找的顺序表L
 * @param e 查找的元素e
 * @return 找到的元素位序，若未找到则返回0
 */
int findSqListNum(SqList L,int e){
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i]==e)
            return i+1;
    }
    return false;
}


int main() {
    SqList L;
    intiSqList(L, 10);
    PrintSqList(L);
    cout << endl;
    if (insertSqListNum(4555, 5, L)) {
        PrintSqList(L);
    } else {
        cout << "False";
    }
    cout << endl;
    if (deleteSqListNum(5, L)) {
        PrintSqList(L);
    } else {
        cout << "False";
    }
    return 0;
}
