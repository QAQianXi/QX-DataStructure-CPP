//
// Created by QianXi_Local on 2023/3/23.
//
#include <iostream>
#include "windows.h"


using namespace std;


struct LinkListNode {
    int data;
    LinkListNode *next= nullptr;
};


/*!
 * 使用头插法初始化单链表
 * @return *headNode 首节点的头部指针
 */
LinkListNode *initLinkList_HeadInsert() {
    LinkListNode *headNode= nullptr, *newNode = nullptr;
    headNode = new LinkListNode;
    headNode->data = -9999;
    headNode->next = nullptr;
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
    LinkListNode *headNode, *lastNode, *newNode = nullptr;
    headNode = new LinkListNode;
    headNode->data = -9999;
    headNode->next = nullptr;
    lastNode = headNode;
    int readInt;
    cout << "readInt end 9999\n";
    cin >> readInt;
    while (readInt != 9999) {
        newNode = new LinkListNode;
        newNode->data = readInt;
        newNode->next = nullptr;
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
void PrintLinkList(LinkListNode *L) {
    int count = 1;
    SetConsoleOutputCP(CP_UTF8);
    cout << "现在为第 " << count << " 节点，为首节点,节点值为 " << L->data << "   (定义-9999为nullptr)，" << endl;
    while (true) {
        L = L->next;
        count += 1;
        if (L->next == nullptr) {
            cout << "现在为第 " << count << " 节点，节点值为 " << L->data << "  已到达尾节点" << endl;
            break;
        }
        cout << "现在为第 " << count << " 节点，节点值为 " << L->data << endl;
    }
}

/*!
 * 查找链表中的指定数值
 * @param num 查找的值
 * @param L 给定的链表头部指针
 * @return 查找到的对应值链表节点指针，若没有则返回nullptr
 */
LinkListNode *findLinkListNum(int num, LinkListNode *L) {
    while (TRUE) {
        if (L->data == num) {
            return L;
        } else if (L->next == nullptr) {
            cout << "未找到指定数值!"<<endl;
            break;
        } else {
            L = L->next;
        }
    }
    return nullptr;
}

/*!
 * 查找链表中的指定位置节点
 * @param index 指定的第几节点
 * @param L 给定的链表头部指针
 * @return 查找到的对应位置链表节点指针，若没有则返回nullptr
 */
LinkListNode *findLinkListIndex(int index, LinkListNode *L) {
    int indexCount = 0;
    while (TRUE) {
        if (indexCount == index - 1) {
            return L;
        } else if (L->next == nullptr) {
            cout << "链表节点不存在!"<<endl;
            break;
        } else {
            L = L->next;
            indexCount++;
        }
    }
    return nullptr;
}


int main() {
    LinkListNode *L = initLinkList_TailInsert();
    PrintLinkList(L);
    LinkListNode *L_index = findLinkListIndex(5, L);
    LinkListNode *L_num = findLinkListNum(5, L);
    cout << L_index<<endl;
    cout << L_num<<endl;

    return 0;
}