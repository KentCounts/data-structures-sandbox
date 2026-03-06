#include "binary_search.h"

bool BinarySearch::IsSorted(const int arr[], std::size_t size)
{
    if (size < 2) return true;

    for (std::size_t i = 1; i < size; ++i)
    {
        if (arr[i - 1] > arr[i]) return false;
    }
    return true;
}


int BinarySearch::recursiveSearch(const int arr[], int left, int right, int target)
{
    if (left > right) return -1;

    const int mid = left + (right - left) / 2;

    if (arr[mid] == target) return mid;

    if (target < arr[mid])
        return recursiveSearch(arr, left, mid - 1, target);

    return recursiveSearch(arr, mid + 1, right, target);
}

int BinarySearch::Search(const int arr[], std::size_t size, int target)
{
    if (size == 0) return -1;
    if (!IsSorted(arr, size)) return -1;

    int left = 0;
    int right = static_cast<int>(size) - 1;

    while (left <= right)
    {
        const int mid = left + (right - left) / 2;

        if (arr[mid] == target) return mid;

        if (target < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

int BinarySearch::SearchRecursive(const int arr[], std::size_t size, int target)
{
    if (size == 0) return -1;
    if (!IsSorted(arr, size)) return -1;

    return recursiveSearch(arr, 0, static_cast<int>(size) - 1, target);
}


int BinarySearch::FirstOccurrence(const int arr[], std::size_t size, int target)
{
    if (size == 0) return -1;
    if (!IsSorted(arr, size)) return -1;

    int left = 0;
    int right = static_cast<int>(size) - 1;
    int result = -1;

    while (left <= right)
    {
        const int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            result = mid;
            right = mid - 1;
        }
        else if (target < arr[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return result;
}

int BinarySearch::LastOccurrence(const int arr[], std::size_t size, int target)
{
    if (size == 0) return -1;
    if (!IsSorted(arr, size)) return -1;

    int left = 0;
    int right = static_cast<int>(size) - 1;
    int result = -1;

    while (left <= right)
    {
        const int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            result = mid;
            left = mid + 1;
        }
        else if (target < arr[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return result;
}