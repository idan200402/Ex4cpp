#pragma once
#include <vector>
#include <algorithm>
#include "BaseIterator.hpp"

namespace ex4 {
    template <typename T>
    class MyContainer;
    template <typename T>
    class SideCrossOrder : public BaseIterator<T> {
    public:
        SideCrossOrder(std::vector<T> sideCrossView, size_t index = 0):
            BaseIterator<T>(std::move(sideCrossView), index) {}
        static std::pair<SideCrossOrder<T>, SideCrossOrder<T>> make(const MyContainer<T>& container) {
        std::vector<T> data = container.getData();
        std::sort(data.begin(), data.end());

        std::vector<T> sideCrossView;
        size_t left = 0;
        size_t right = data.size() - 1;

        while (left <= right) {
            if (left == right) {
                sideCrossView.push_back(data[left]);
                break;
            }
            sideCrossView.push_back(data[left++]);
            sideCrossView.push_back(data[right--]);
        }

        return {
            SideCrossOrder<T>(sideCrossView, 0),
            SideCrossOrder<T>(sideCrossView, sideCrossView.size())
        };
    }
    };
}