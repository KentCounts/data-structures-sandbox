#pragma once

#include <cstddef>

class MergeSort
{
private:

    static void mergeSort(int arr[], int left, int right);

    // [left..mid] and [mid+1..right]
    static void merge(int arr[], int left, int mid, int right);

public:

    static void Sort(int arr[], std::size_t size);

    static bool IsSorted(const int arr[], std::size_t size);
};