#pragma once

#include <cstddef>
class BinarySearch
{
private:

    static int recursiveSearch(const int arr[], int left, int right, int target);

public:

    static bool IsSorted(const int arr[], std::size_t size);

    static int Search(const int arr[], std::size_t size, int target);

    static int SearchRecursive(const int arr[], std::size_t size, int target);

    static int FirstOccurrence(const int arr[], std::size_t size, int target);
    static int LastOccurrence(const int arr[], std::size_t size, int target);

    static int LowerBound(const int arr[], std::size_t size, int target);
    static int UpperBound(const int arr[], std::size_t size, int target);
};