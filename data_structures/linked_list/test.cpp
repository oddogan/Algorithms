#include "linked_list.hpp"

int main() {
    LinkedList listLinked;
    int iChoice = 0;
    int iChoiceIns = 0;
    int iValue = 0;
    int iInd = 0;

    do {
        std::cout << "\n1. Insert";
        std::cout << "\n2. Delete";
        std::cout << "\n3. Display";
        std::cout << "\n0. Exit";
        std::cout << "\nEnter your choice: ";
        std::cin >> iChoice;

        switch (iChoice)
        {
        case 0:
            std::cout << "\nExiting the program.\n";
            break;

        case 1:
            do {
                std::cout << "\n1. Insert first";
                std::cout << "\n2. Insert last";
                std::cout << "\n3. Insert after";
                std::cout << "\n0. Back to main menu";
                std::cout << "\nEnter your choice: ";
                std::cin >> iChoiceIns;

                switch (iChoiceIns)
                {
                case 0:
                    break;
                
                case 1:
                    std::cout << "\nEnter the value to be inserted: ";
                    std::cin >> iValue;
                    listLinked.InsertFirst(iValue);
                    break;
                
                case 2:
                    std::cout << "\nEnter the value to be inserted: ";
                    std::cin >> iValue;
                    listLinked.InsertLast(iValue);
                    break;
                
                case 3:
                    std::cout << "\nEnter the node index to insert after: ";
                    std::cin >> iInd;
                    std::cout << "\nEnter the value to be inserted: ";
                    std::cin >> iValue;
                    listLinked.InsertAfter(iInd, iValue);
                    break;

                default:
                    std::cout << "\nPlease give a valid input.";
                    break;
                }
            } while (iChoiceIns != 0);
            break;
        
        case 2:
            std::cout << "Enter the value to be deleted: ";
            std::cin >> iValue;
            listLinked.DeleteData(iValue);
            break;

        case 3:
            std::cout << "Linked List: ";
            listLinked.Display();
            break;

        default:
            std::cout << "\nPlease give a valid input.";
            break;
        }
    } while (iChoice != 0);

    return 0;
}