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

void MergeSort::mergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void MergeSort::merge(int arr[], int left, int mid, int right)
{
    int n = right - left + 1;

    int* temp = new int[n];

    int i = left;      // pointer for left
    int j = mid + 1;   // pointer for right
    int k = 0;         // pointer for temp array

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (int t = 0; t < n; ++t)
    {
        arr[left + t] = temp[t];
    }

    delete[] temp;
}