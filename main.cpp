#include <iostream>
#include "linked_list.h"
#include "stack_queue.h"

void show_main_menu()
{
    std::cout << "\n=== Main Menu ===\n";
    std::cout << "1. Linked List\n";
    std::cout << "2. Stack\n";
    std::cout << "3. Queue\n";
    std::cout << "4. Binary Search\n";
    std::cout << "5. Hash Table\n";
    std::cout << "6. Tree\n";
    std::cout << "7. Quick Sort\n";
    std::cout << "8. Merge Sort\n";
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
    std::cout << "11. Remove at Index\n";
    std::cout << "12. Search for value\n";
    std::cout << "13. Deep copy\n";
    std::cout << "0. Main Menu\n";
    std::cout << "Choice: ";
}

void show_stack_menu()
{
    std::cout << "\n--- Stack Menu ---\n";
    std::cout << "1. Initialize stack\n";
    std::cout << "2. Print stack\n";
    std::cout << "3. Is stack empty?\n";
    std::cout << "4. Clear stack\n";
    std::cout << "5. Push\n";
    std::cout << "6. Pop\n";
    std::cout << "7. Peek\n";
    std::cout << "0. Main Menu\n";
    std::cout << "Choice: ";
}

void show_queue_menu()
{
    std::cout << "\n--- Queue Menu ---\n";
    std::cout << "1. Initialize queue\n";
    std::cout << "2. Print queue\n";
    std::cout << "3. Is queue empty?\n";
    std::cout << "4. Clear queue\n";
    std::cout << "5. Enqueue\n";
    std::cout << "6. Dequeue\n";
    std::cout << "7. Peek front\n";
    std::cout << "0. Back\n";
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

        case 11:
        {
            std::size_t index;

            if (list.GetSize() == 0)
            {
                std::cout << "List is empty. Nothing to remove.\n";
                break;
            }

            std::cout << "Enter index (0 to " << (list.GetSize() - 1) << "): ";
            std::cin >> index;

            if (list.RemoveAt(index))
            {
                std::cout << "Removed node at index " << index << ".\n";
            }
            else
            {
                std::cout << "Invalid index. No removal performed.\n";
            }

            break;
        }

        case 12:
        {
            int value;
            std::cout << "Enter value to search for: ";
            std::cin >> value;

            int index = list.Index(value);

            if (index != -1)
            {
                std::cout << "Value " << value << " found at index " << index << ".\n";
            }
            else
            {
                std::cout << "Value " << value << " NOT found in list.\n";
            }

            break;
        }

        case 13:
        {
            std::cout << "Original: ";
            list.print();

            std::cout << "Copy constructing a new list from original...\n";
            LinkedList copyConstructed(list);

            std::cout << "CopyConstructed: ";
            copyConstructed.print();

            std::cout << "Mutating original (PushBack 99)...\n";
            list.PushBack(99);

            std::cout << "Original: ";
            list.print();

            std::cout << "CopyConstructed (should be unchanged): ";
            copyConstructed.print();

            std::cout << "Testing copy assignment...\n";
            LinkedList assigned;
            assigned = list;

            std::cout << "Assigned: ";
            assigned.print();

            std::cout << "Clearing original...\n";
            list.clear();

            std::cout << "Original: ";
            list.print();

            std::cout << "Assigned (should still contain previous values): ";
            assigned.print();

            break;
        }

        case 0:
            // return to main menu
            return true;

        default:
            std::cout << "Invalid choice.\n";
            break;
        }
    }
}

bool stack_menu(Stack& stack)
{
    int choice = -1;

    while (true)
    {
        show_stack_menu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            stack.Clear();

            stack.Push(10);
            stack.Push(20);
            stack.Push(30);
            stack.Push(40);
            stack.Push(50);

            std::cout << "Stack initialized with sample data.\n";
            break;

        case 2:
        {
            if (stack.IsEmpty())
            {
                std::cout << "(empty)\n";
                break;
            }

            Stack copy = stack; // deep copy
            std::cout << "Top -> ";

            int v = 0;
            while (copy.Peek(v))
            {
                std::cout << v << " ";
                copy.Pop();
            }

            std::cout << "<- Bottom\n";
            break;
        }

        case 3:
            std::cout << (stack.IsEmpty() ? "Stack is empty.\n" : "Stack is NOT empty.\n");
            break;

        case 4:
            stack.Clear();
            std::cout << "Stack cleared.\n";
            break;

        case 5:
        {
            int value;
            std::cout << "Enter value to push: ";
            std::cin >> value;
            stack.Push(value);
            std::cout << "Pushed.\n";
            break;
        }

        case 6:
            if (!stack.Pop())
                std::cout << "Stack is empty. Nothing to pop.\n";
            else
                std::cout << "Popped.\n";
            break;

        case 7:
        {
            int topVal;
            if (stack.Peek(topVal))
                std::cout << "Top: " << topVal << "\n";
            else
                std::cout << "Stack is empty.\n";
            break;
        }

        case 0:
            return true;

        default:
            std::cout << "Invalid choice.\n";
            break;
        }
    }
}

bool queue_menu(Queue& queue)
{
    int choice = -1;

    while (true)
    {
        show_queue_menu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            queue.Clear();

            // Example queue data (front -> back: 10 20 30 40 50)
            queue.Enqueue(10);
            queue.Enqueue(20);
            queue.Enqueue(30);
            queue.Enqueue(40);
            queue.Enqueue(50);

            std::cout << "Queue initialized with sample data.\n";
            break;

        case 2:
        {
            if (queue.IsEmpty())
            {
                std::cout << "(empty)\n";
                break;
            }

            Queue copy = queue; // deep copy, so original remains unchanged
            std::cout << "Front -> ";

            int v = 0;
            while (copy.PeekFront(v))
            {
                std::cout << v << " ";
                copy.Dequeue();
            }

            std::cout << "<- Back\n";
            break;
        }

        case 3:
            std::cout << (queue.IsEmpty() ? "Queue is empty.\n" : "Queue is NOT empty.\n");
            break;

        case 4:
            queue.Clear();
            std::cout << "Queue cleared.\n";
            break;

        case 5:
        {
            int value;
            std::cout << "Enter value to enqueue: ";
            std::cin >> value;
            queue.Enqueue(value);
            std::cout << "Enqueued.\n";
            break;
        }

        case 6:
            if (!queue.Dequeue())
                std::cout << "Queue is empty. Nothing to dequeue.\n";
            else
                std::cout << "Dequeued.\n";
            break;

        case 7:
        {
            int frontVal;
            if (queue.PeekFront(frontVal))
                std::cout << "Front: " << frontVal << "\n";
            else
                std::cout << "Queue is empty.\n";
            break;
        }

        case 0:
            return true;

        default:
            std::cout << "Invalid choice.\n";
            break;
        }
    }
}

int main()
{
    LinkedList list;
    Stack stack;
    Queue queue;
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
            running = stack_menu(stack);
            break;

        case 3:
            running = queue_menu(queue);
            break;

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
