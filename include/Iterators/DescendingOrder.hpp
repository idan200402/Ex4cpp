#pragma once 
#include <iterator>
#include <vector>
#include "BaseIterator.hpp"
#include "../MyContainer.hpp"
#include <algorithm>
namespace ex4 {
    template <typename T>
    class DescendingOrder : public BaseIterator<T> {
    public:
        DescendingOrder(const MyContainer<T>& container, bool isBeginning) {
            auto sortedData = container.getData();
            std::sort(sortedData.begin(), sortedData.end(), std::greater<T>());
            this->setCurrent(isBeginning ? sortedData.begin() : sortedData.end());
            this->setEnd(sortedData.end());
        }
    };
}