#include <iostream>

/*
在c++中可以不需要typedef就可以Student stu2是因为在c++中struct也是一种类，
所以可以直接使用Student stu2来定义一个Student的对象，但c中去不可以
*/
#define MAX_SIZE 100
#define INIT_SIZE 50

using namespace std;
struct SqList{
    int data[INIT_SIZE];
    int length;
//    int *data;
};
void printSqList(SqList L){
    for (int i = 0; i < L.length; ++i) {
        cout<<"第"<<i+1<<"几个元素为"<<L.data[i]<<endl;
    }
}
bool insertElemSqList(int e,int index,SqList &L){
    if(index<1 or index>L.length+1)
        return false;
    if (L.length>=MAX_SIZE)
        return false;
    for (int i = L.length;i>=index ; ++i) {
        L.data[i]= L.data[i-1];
    }
    L.data[index-1]=e;
    L.length++;
    return true;
}
void testInsertSqList(){
    SqList L;
    L.length=0;
    for (int i = 0; i < 10; ++i) {
        L.data[i]=i;
        L.length+=1;
    }
    printSqList(L);
}


int main() {
    testInsertSqList();//run和debug的运行内容不同
    return 0;
}
