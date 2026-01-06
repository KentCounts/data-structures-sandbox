#include <iostream>
#include "linked_list.h"

void show_main_menu()
{
    std::cout << "\n=== Main Menu ===\n";
    std::cout << "1. Linked List\n";
    std::cout << "2. Stack and Queue\n";
    std::cout << "3. Binary Search\n";
    std::cout << "4. Hash Table\n";
    std::cout << "5. Tree\n";
    std::cout << "6. Quick Sort\n";
    std::cout << "7. Merge Sort\n";
    std::cout << "0. Exit\n";
    std::cout << "Choice: ";
}

void show_linked_list_menu()
{
    std::cout << "\n--- Linked List Menu ---\n";
    std::cout << "1. Initialize list\n";
    std::cout << "2. Print list\n";
    std::cout << "3. Is list empty?\n";
    std::cout << "4. Clear list\n";
    std::cout << "9. Main Menu\n";
    std::cout << "0. Exit\n";
    std::cout << "Choice: ";
}

bool linked_list_menu(LinkedList& list)
{
    int choice = -1;

    while (true)
    {
        show_linked_list_menu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            list.init();
            std::cout << "Linked list initialized.\n";
            break;

        case 2:
            list.print();
            break;

        case 3:
            if (list.isEmpty())
            {
                std::cout << "The list is empty.\n";
            }

            else
            {
                std::cout << "The list is NOT empty. \n";
            }
            break;

        case 4:
            list.clear();
            std::cout << "List cleared.\n";
            break;

        case 9:
            return true;  // Return to main menu

        case 0:
            return false; // Exit program

        default:
            std::cout << "Invalid choice.\n";
            break;
        }
    }
}

int main()
{
    LinkedList list;
    int choice = -1;
    bool running = true;

    while (running)
    {
        show_main_menu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            running = linked_list_menu(list);
            break;

        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            std::cout << "Feature not implemented yet.\n";
            break;

        case 0:
            running = false;
            break;

        default:
            std::cout << "Invalid choice.\n";
            break;
        }
    }

    std::cout << "Exiting program.\n";
    return 0;
}
