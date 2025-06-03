#pragma once
#include <vector>
#include <algorithm>
#include "BaseIterator.hpp"
namespace ex4 {
    template <typename T>
    class MyContainer;
    template <typename T>
class AscendingOrder : public BaseIterator<T> {
    std::vector<T> sortedView;

    public:
        AscendingOrder(const MyContainer<T>& container, bool isBeginning)
            : sortedView(container.getData())  // first, copy
        {
            std::sort(sortedView.begin(), sortedView.end());
            this->setView(sortedView);  // assign to BaseIterator properly
            this->setCurrent(isBeginning ? sortedView.begin() : sortedView.end());
            this->setEnd(sortedView.end());
        }
    };


}
            