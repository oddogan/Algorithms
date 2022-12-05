#include "linked_list.hpp"

Node::Node(int iInputData) {
    iData = iInputData;
    npNext = nullptr;
}

int Node::GetData() {
    return iData;
}

Node* Node::GetNextNode() {
    return npNext;
}

void Node::SetNextNode(Node* npInputNode) {
    npNext = npInputNode;
}

LinkedList::LinkedList() {
    npHead = nullptr;
    npTail = nullptr;
    iLength = 0;
}

void LinkedList::InsertFirst(int iInputData) {
    Node *npTemp = new Node(iInputData);

    if (npHead == nullptr) {
        npHead = npTemp;
        npTail = npHead;
    } else {
        npTemp->SetNextNode(npHead);
        npHead = npTemp;
    }
    iLength++;
}

void LinkedList::InsertLast(int iInputData) {
    Node *npTemp = new Node(iInputData);
    
    if (npTail == nullptr) {
        npHead = npTemp;
        npTail = npHead;
    } else {
        npTail->SetNextNode(npTemp);
        npTail = npTemp;
    }
    iLength++;
}

void LinkedList::InsertAfter(int iIndex, int iInputData) {
    if (iIndex < 0) {
        std::cout << "\nThe index should be positive.";
        return;
    } else if (iIndex < iLength) {
        Node *npTemp = new Node(iInputData);
        
        Node *npTrav = npHead;
        int i = 0;
        while (i != iIndex) {
            npTrav = npTrav->GetNextNode();
            i++;
        }

        npTemp->SetNextNode(npTrav->GetNextNode());
        npTrav->SetNextNode(npTemp);
        iLength++;
    } else {
        std::cout << "\nIndex is out of bounds.";
    }
}

void LinkedList::DeleteData(int iInputData) {
    if (npHead == nullptr) {
        std::cout << "\nThe linked list is empty.";
        return;
    }
    
    Node *npTrav = npHead;
    while (npTrav->GetNextNode() != nullptr && npTrav->GetNextNode()->GetData() != iInputData) {
        npTrav = npTrav->GetNextNode();
    }

    if (npTrav->GetNextNode() == nullptr) {
        std::cout << "\nThe data does not exist in the linked list." << std::endl;
    } else {
        Node *npTemp = npTrav->GetNextNode();
        npTrav->SetNextNode(npTemp->GetNextNode());
        delete npTemp;
        iLength--;
    }
}

void LinkedList::Display() {
    if (npHead == nullptr) {
        std::cout << "\nThe linked list is empty.";
        return;
    }

    Node *npTrav = npHead;
    while (npTrav != nullptr) {
        std::cout << npTrav->GetData() << "  ";
        npTrav = npTrav->GetNextNode();
    }
}

