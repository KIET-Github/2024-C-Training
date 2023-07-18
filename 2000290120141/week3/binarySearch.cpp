#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Returns the index of the target element in the sorted vector, or -1 if not found.
int binarySearch(const std::vector<int>& sortedArr, int target) {
    int left = 0;
    int right = sortedArr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (sortedArr[mid] == target) {
            return mid; // Target found, return the index.
        } else if (sortedArr[mid] < target) {
            left = mid + 1; // Target may be in the right half.
        } else {
            right = mid - 1; // Target may be in the left half.
        }
    }

    return -1; // Target not found in the array.
}
