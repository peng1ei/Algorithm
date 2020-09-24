//
// Created by pl on 2020/9/23.
//
#include "MeasureAlgoTime.hpp"
#include "SelectionSort.hpp"
#include "PrintSTL.hpp"
#include "TestSortHelper.hpp"
#include <iostream>
#include <thread>
#include <chrono>

int main() {

    std::vector<int> vec{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    auto notOrdered = TestSortHelper::GenerateNotOrderedArray<int>(20);
    PrintVector(notOrdered);

    auto randomData = TestSortHelper::GenerateRangeRandomArray(100, 0, 10000);
    //PrintVector(randomData, "Random Data[0, 10]");
    auto nearlyOredrArray = TestSortHelper::GenerateNearlyOrderedArray<int>(100, 3);
    PrintVector(nearlyOredrArray);

    TestSortHelper::TestSort<int>(SelectionSort<int>, randomData, "Selection Sort", false);

    return 0;
}

