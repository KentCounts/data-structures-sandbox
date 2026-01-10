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
    std::cout << "5. Push Front\n";
    std::cout << "6. Push Back\n";
    std::cout << "7. Pop front\n";
    std::cout << "8. Pop back\n";
    std::cout << "9. Get list size\n";
    std::cout << "10. Insert at index\n";
    std::cout << "0. Main Menu\n";
    std::cout << "Choice: ";
}

bool linked_list_menu(LinkedList& list)
{
    int choice = -1;

    int value = 0;

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

        case 5:
            std::cout << "Enter value to push to front: ";
            std::cin >> value;
            list.PushFront(value);
            std::cout << "Value pushed to front.\n";
            break;

        case 6:
            std::cout << "Enter value to push to back: ";
            std::cin >> value;
            list.PushBack(value);
            std::cout << "Value pushed to back.\n";
            break;

        case 7:
            list.PopFront();
            break;

        case 8:
            list.PopBack();
            break;

        case 9:
            std::cout << "List size: " << list.GetSize() << "\n";
            break;

        case 10:
        {
            std::size_t index;
            int value;

            std::cout << "Enter index (0 to " << list.GetSize() << "): ";
            std::cin >> index;

            std::cout << "Enter value: ";
            std::cin >> value;

            if (list.InsertAt(index, value))
            {
                std::cout << "Inserted " << value << " at index " << index << ".\n";
            }
            else
            {
                std::cout << "Invalid index. No insertion performed.\n";
            }
            break;
        }

        case 0:
            return true; // return to main menu

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
