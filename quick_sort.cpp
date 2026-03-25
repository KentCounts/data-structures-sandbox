#include "quick_sort.h"
#include <utility>


void QuickSort::Sort(int arr[], std::size_t size)
{
    if (arr == nullptr || size <= 1)
        return;

    quickSort(arr, 0, static_cast<int>(size) - 1);
}

bool QuickSort::IsSorted(const int arr[], std::size_t size)
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

void QuickSort::quickSort(int arr[], int left, int right)
{
    // no logic yet
}

int QuickSort::partition(int arr[], int left, int right)
{
    // no logic yet
}