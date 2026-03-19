#include "merge_sort.h"
#include <iostream>

void MergeSort::Sort(int arr[], std::size_t size)
{
    if (arr == nullptr || size <= 1)
        return;

    mergeSort(arr, 0, static_cast<int>(size) - 1);
}

bool MergeSort::IsSorted(const int arr[], std::size_t size)
{
    if (arr == nullptr || size <= 1)
        return true;

    for (std::size_t i = 1; i < size; ++i)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }

    return true;
}
// mergesort

// merge