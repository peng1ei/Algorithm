//
// Created by pl on 2020/9/23.
//
#include "TestSort.hpp"

int main() {
#ifdef TEST_GENERATE_RANDOM
    Test::GenerateRandomArray();
#endif

#ifdef TEST_SELECTION_SORT
    Test::SelectionSort();
#endif

#ifdef TEST_BUBBLE_SORT
    Test::BubbleSort();
#endif

    return 0;
}

