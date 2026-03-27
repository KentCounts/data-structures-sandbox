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
    if (left >= right)
        return;

    int pivotIndex = partition(arr, left, right);

    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}

int QuickSort::partition(int arr[], int left, int right)
{
    int pivot = arr[left];

    int i = left + 1;
    int j = right;

    while (i <= j)
    {
        if (arr[i] <= pivot)
        {
            ++i;
        }
        else if (arr[j] > pivot)
        {
            --j;
        }
        else
        {
            std::swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    }

    std::swap(arr[left], arr[j]);

    return j;
}