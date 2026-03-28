#include <iostream>
#include <fstream>
#include <vector>
#include <chrono> // For stopwatch
#include "Rating.h"
#include "MergeSort.h"

using namespace std;
using namespace std::chrono; //readability

int main() {
    vector<Rating> ratings;
    ifstream file("u.data");

    if (!file.is_open()) {
        cout << "Error: Could not open u.data. Check your folder!" << endl;
        return 1;
    }

    int uId, mId, r;
    long ts;
    while (file >> uId >> mId >> r >> ts) {
        Rating newRating = {uId, mId, r, ts};
        ratings.push_back(newRating);
    }
    file.close();
    cout << "Successfully loaded " << ratings.size() << " movie ratings!" << endl;

    // Make a copy of the unsorted data
    // This is crucial so partner has the original unsorted data for his QuickSort later.
    vector<Rating> mergeData = ratings;

    cout << "\nStarting MergeSort..." << endl;

    // Start clock
    auto start = high_resolution_clock::now();


    mergeSort(mergeData, 0, mergeData.size() - 1);

    // Stop the clock
    auto stop = high_resolution_clock::now();

    // Calculate the duration
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "MergeSort finished in: " << duration.count() << " milliseconds!" << endl;

    bool isSorted = true;
    for (size_t i = 0; i < mergeData.size() - 1; i++) {
        if (mergeData[i].rating > mergeData[i+1].rating) {
            isSorted = false;
            break;
        }
    }

    if (isSorted) {
        cout << "Status: SUCCESS (Data is sorted perfectly by rating)" << endl;
    } else {
        cout << "Status: FAILED (Data is not sorted)" << endl;
    }
    return 0;
}