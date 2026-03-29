#pragma once
#include <vector>
#include "Rating.h"
using namespace std;

inline void quickSort(vector<Rating>& arr, int low, int high) {
    if (low >= high) return;

    int pivot = arr[low + (high - low) / 2].rating;
    int lt = low;
    int gt = high;
    int i = low;

    while (i <= gt) {
        if (arr[i].rating < pivot) {
            swap(arr[lt], arr[i]);
            lt++;
            i++;
        } else if (arr[i].rating > pivot) {
            swap(arr[i], arr[gt]);
            gt--;
        } else {
            i++;
        }
    }

    quickSort(arr, low, lt - 1);
    quickSort(arr, gt + 1, high);
}
