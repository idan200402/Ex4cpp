#pragma once 
#include <iterator>
#include <vector>
#include "BaseIterator.hpp"
#include <algorithm>
namespace ex4 {
    template <typename T>
    class MyContainer;
    template <typename T>
    class DescendingOrder : public BaseIterator<T> {
    public:
        DescendingOrder(const MyContainer<T>& container, bool isBeginning) {
            this->view = container.getData();
            std::sort(this->view.begin(), this->view.end(), std::greater<T>());
            this->setCurrent(isBeginning ? this->view.begin() : this->view.end());
            this->setEnd(this->view.end());
        }
    };
}