#pragma once

#include <cstddef>

class QuickSort
{
private:

    // quickstort recursive
    static void quickSort(int arr[], int left, int right);

    // Partition step
    static int partition(int arr[], int left, int right);

public:

    // Public sort call
    static void Sort(int arr[], std::size_t size);

    // sort check
    static bool IsSorted(const int arr[], std::size_t size);
};