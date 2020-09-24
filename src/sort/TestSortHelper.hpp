//
// Created by pl on 2020/9/23.
//

#ifndef ALGORITHM_TESTSORTHELPER_HPP
#define ALGORITHM_TESTSORTHELPER_HPP
#include "PrintSTL.hpp"
#include "MeasureAlgoTime.hpp"
#include <functional>
#include <string>
#include <iomanip>
#include <cassert>
#include <random>

namespace TestSortHelper {

    template<typename T>
    using SortFunc = std::function<void(std::vector<T>&)>;

    template <typename T>
    bool IsSorted(const std::vector<T> &data) {
        assert(!data.empty() && "The input data is empty.");

        for (int i = 1; i < data.size(); ++i) {
            if (data[i] < data[i-1]) return false;
        }
        return true;
    }

    template <typename T>
    void TestSort(SortFunc<T> sortFunc, std::vector<T>&data, const std::string &title, bool debug = false) {
        if (debug) {
            PrintVectorElems(data, title + "[Sort Before]");
        }

        Tools::Time::AlgoTimeUs::Start();
        sortFunc(data);
        auto timeSecond = Tools::Time::AlgoTimeUs::Elapsed() / 1000000.0;

        if (debug) {
            PrintVectorElems(data, title + "[Sort After]");
        }
        std::cout << title << "[Running Time]: " << std::setiosflags(std::ios::fixed) << timeSecond << " s" << std::endl;
        std::cout << title << "[Successful]: " << (IsSorted(data) ? "true" : "false") << std::endl;
    }

    template <typename T>
    std::vector<T> GenerateRangeRandomArray(size_t n, T min, T max) {
        static_assert(std::is_arithmetic<T>::value, "The element type is not arithmetic.");

        // 1. 定义 random_device 对象
        std::random_device rd;

        // 2. 选择随机引擎（默认、线性、梅森、斐波那契）的实现类，
        // 将 random_device 的随机结果传入作为种子
        // std::mt19937 -- mersenne_twister_engine梅森旋转法，这种生成的随机数质量比较高
        // std::minstd_rand -- linear_congruential_engine线性同余法,这种速度最快、最常用
        std::mt19937 gen(rd());

        // 3. 选择要的分布，创建分布对象，将引擎传入作为种子，让分布对象输出随机数
        // std::uniform_int_distribution -- 整数均匀分布，范围为 [min,max]
        // uniform_real_distribution -- 浮点数均匀分布, 范围为 [min,max)

        std::vector<T> randomData;
        randomData.reserve(n);

        if (std::is_integral<T>::value) {
            std::uniform_int_distribution<T> dis(min,max); // 生成 [min, max] 之间的随机数
            for(int i=0; i<n; i++){
                randomData.push_back(dis(gen));
            }

        } else if (std::is_floating_point<T>::value) {
            // TODO
        }

        return randomData;
    }

    // 产生一个近乎有序的数组的基本思想：
    // 1. 先生成一个有序的数组
    // 2. 然后产生需要交换值的两个位置的随机数，交换两个随机位置的值（指定需要交换的次数）
    template <typename T>
    std::vector<T> GenerateNearlyOrderedArray(size_t n, size_t swapTimes) {
        static_assert(std::is_arithmetic<T>::value, "The element type is not arithmetic.");

        std::vector<T> data;
        data.reserve(n);
        for (size_t i = 0; i < n; i++) {
            data.push_back(i);
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        if (std::is_integral<T>::value) {
            std::uniform_int_distribution<T> dis(0,n-1);
            for(size_t i=0; i<swapTimes; i++){
                T posx = dis(gen);
                T posy = dis(gen);
                std::swap(data[posx], data[posy]);
            }
        } else if (std::is_floating_point<T>::value) {
            // TODO
        }

        return data;
    }

    template <typename T>
    std::vector<T> GenerateNotOrderedArray(size_t n) {
        std::vector<T> data;
        data.reserve(n);
        for (size_t i = n; i > 0; i--) {
            data.push_back(i);
        }

        return data;
    }
}

#endif //ALGORITHM_TESTSORTHELPER_HPP
