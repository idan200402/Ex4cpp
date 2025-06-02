#pragma once
#include <vector>
#include <algorithm>
#include "BaseIterator.hpp"
#include "../MyContainer.hpp"
namespace ex4 {
    template <typename T>
    class AscendingOrder : public BaseIterator<T> {
    public:
        AscendingOrder(const MyContainer<T>& container, bool isBeginning){
            auto sortedData = container.getData();
            std::sort(sortedData.begin(), sortedData.end());
            this->setCurrent(isBeginning ? sortedData.begin() : sortedData.end());
            this->setEnd(sortedDAta.end());
        }
    }
}
            