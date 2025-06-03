#pragma once
#include <vector>
#include <algorithm>
#include "BaseIterator.hpp"
#include <memory>


namespace ex4 {
    template <typename T>
    class MyContainer;
    template <typename T>
    class ReverseOrder : public BaseIterator<T> {
    public:
        ReverseOrder(const MyContainer<T>& container, bool isBeginning) {
            std::vector<T> reversedData = container.getData();
            std::reverse(reversedData.begin(), reversedData.end());
            this->view = std::make_shared<std::vector<T>>(std::move(reversedData));
            this->setCurrent(isBeginning ? this->view->begin() : this->view->end());
            this->setEnd(this->view->end());
        }
    };
}