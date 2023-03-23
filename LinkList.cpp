//
// Created by QianXi_Local on 2023/3/23.
//
#include <iostream>
#include "windows.h"

using namespace std;


struct LinkListNode {
    int data;
    LinkListNode *next;
};

/*!
 * 使用头插法初始化单链表
 * @return *headNode 首节点的头部指针
 */
LinkListNode *initLinkList_HeadInsert() {
    LinkListNode *headNode, *newNode = NULL;
    headNode = new LinkListNode;
    headNode->data = -9999;
    headNode->next = NULL;
    int readInt;
    cout << "readInt end 9999\n";
    cin >> readInt;
    while (readInt != 9999) {
        newNode = new LinkListNode;
        newNode->data = readInt;
        newNode->next = headNode->next;
        headNode->next = newNode;
        cin >> readInt;
    }
    return headNode;
}

/*!
 * 使用尾查法初始化单链表
 * @return *headNode 首节点的头部指针
 */
LinkListNode *initLinkList_TailInsert() {
    LinkListNode *headNode, *lastNode, *newNode = NULL;
    headNode = new LinkListNode;
    headNode->data = -9999;
    headNode->next = NULL;
    lastNode = headNode;
    int readInt;
    cout << "readInt end 9999\n";
    cin >> readInt;
    while (readInt != 9999) {
        newNode = new LinkListNode;
        newNode->data = readInt;
        newNode->next = NULL;
        lastNode->next = newNode;
        lastNode = newNode;
        cin >> readInt;
    }
    return headNode;
}
/*!
 * 输出单链表的全部内容
 * @param L
 */
void printLinkList(LinkListNode *L) {
    int count = 0;
    SetConsoleOutputCP(CP_UTF8);
    cout << "现在为第 " << count << " 节点，为首节点，节点值为 " << L->data << "   (定义-9999为NULL)" << endl;
    while (L->next != NULL) {
        L = L->next;
        count += 1;
        cout << "现在为第 " << count << " 节点，节点值为 " << L->data << endl;
    }
    cout << "现在为第 " << count << " 节点，已到达尾节点，节点值为 " << L->data << endl;

}

int main() {
    LinkListNode *L = initLinkList_HeadInsert();
    printLinkList(L);

    LinkListNode *L2 = initLinkList_HeadInsert();
    printLinkList(L2);


    return 0;
}