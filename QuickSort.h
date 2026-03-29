#pragma once
#include <vector>
#include "Rating.h"
using namespace std;

inline int partition(vector<Rating>& arr, int low, int high) {
    int mid = low + (high - low) / 2;

    if (arr[mid].rating < arr[low].rating)
        swap(arr[low], arr[mid]);
    if (arr[high].rating < arr[low].rating)
        swap(arr[low], arr[high]);
    if (arr[mid].rating < arr[high].rating)
        swap(arr[mid], arr[high]);

    int pivot = arr[high].rating;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].rating <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

inline void quickSort(vector<Rating>& arr, int low, int high) {
    if (low >= high) return;

    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
}
