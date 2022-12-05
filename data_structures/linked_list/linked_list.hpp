#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

class Node {
    public:
        Node(int iInputData = 0);

        int GetData();
        Node* GetNextNode();
        void SetNextNode(Node* npInputNode);
    private:
        int iData;
        Node *npNext;
};

class LinkedList {
    public:
        LinkedList();

        void InsertFirst(int iInputData);
        void InsertLast(int iInputData);
        void InsertAfter(int iIndex, int iInputData);
        void DeleteData(int iInputData);
        void Display();
    private:
        int iLength;
        Node *npHead;
        Node *npTail;
};

#endif