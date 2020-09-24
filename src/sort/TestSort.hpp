//
// Created by pl on 2020/9/24.
//

#ifndef ALGORITHM_TESTSORT_HPP
#define ALGORITHM_TESTSORT_HPP
#include "MeasureAlgoTime.hpp"
#include "SelectionSort.hpp"
#include "PrintSTL.hpp"
#include "SortTestHelper.hpp"
#include "BubbleSort.hpp"

namespace Test {
    void GenerateRandomArray() {
        auto notOrderedArray = SortTestHelper::GenerateNotOrderedArray<int>(20);
        PrintVectorElems(notOrderedArray, "Completely Disordered[20]");

        auto randomArray = SortTestHelper::GenerateRangeRandomArray(20, 0, 10000);
        PrintVectorElems(randomArray, "Random Array[0, 10000]");

        auto nearlyOredredArray = SortTestHelper::GenerateNearlyOrderedArray<int>(20, 3);
        PrintVectorElems(nearlyOredredArray, "Nearly Ordered Array[Swap 3 times]");
    }

    void SelectionSort() {
        auto randomData = SortTestHelper::GenerateRangeRandomArray(100, 0, 100000);
        SortTestHelper::TestSort<int>(Algo::Sort::SelectionSort<int>, randomData, "Selection Sort", false);
        SortTestHelper::TestSort<int>(Algo::Sort::SelectionSort<int>, randomData, "Selection Sort", false);
    }

    void BubbleSort() {
        auto randomData = SortTestHelper::GenerateRangeRandomArray(100, 0, 100000000);
        auto randomDataAdvance = randomData;
        SortTestHelper::TestSort<int>(Algo::Sort::BubbleSort<int>, randomData, "Bubble Sort");
        SortTestHelper::TestSort<int>(Algo::Sort::BubbleSortAdvance<int>, randomDataAdvance, "Bubble Sort Advance");

        auto nearlyOrderedArray = SortTestHelper::GenerateNearlyOrderedArray<int>(100, 1);
        auto nearlyOrderedArrayAdvance = nearlyOrderedArray;
        SortTestHelper::TestSort<int>(Algo::Sort::BubbleSort<int>, nearlyOrderedArray, "Bubble Sort Nearly Ordered Array");
        SortTestHelper::TestSort<int>(Algo::Sort::BubbleSortAdvance<int>, nearlyOrderedArrayAdvance, "Bubble Sort Advance Nearly Ordered Array");

        auto orderedArray = SortTestHelper::GenerateOrderedArray<int>(100000);
        auto orderedArrayAdvance = nearlyOrderedArray;
        //SortTestHelper::TestSort<int>(Algo::Sort::BubbleSort<int>, orderedArray, "Bubble Sort Nearly Ordered Array");
        SortTestHelper::TestSort<int>(Algo::Sort::BubbleSortAdvance<int>, orderedArrayAdvance, "Bubble Sort Advance Nearly Ordered Array");
    }


} // namespace Test

#endif //ALGORITHM_TESTSORT_HPP
