//
// Created by pl on 2020/9/23.
//

#ifndef ALGORITHM_SELECTIONSORT_HPP
#define ALGORITHM_SELECTIONSORT_HPP
#include <vector>

template <typename T>
void SelectionSort(std::vector<T> &data) {
    for (size_t i = 0; i < data.size(); ++i) {
        size_t minIndex = i;
        for (size_t j = i; j < data.size(); ++j) {
            if (data[j] < data[minIndex]) minIndex = j;
        }
        std::swap(data[i], data[minIndex]);
    }
}

#endif //ALGORITHM_SELECTIONSORT_HPP
