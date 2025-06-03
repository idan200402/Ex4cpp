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
        SideCrossOrder(const MyContainer<T>& container, bool isBeginning) {
            const auto& data = container.getData();
            this->view.reserve(data.size());
            size_t left = 0;
            size_t right = data.size() - 1;

            while (left <= right) {
                if (left == right) {
                    this->view.push_back(data[left]);
                } else {
                    this->view.push_back(data[left]);
                    this->view.push_back(data[right]);
                }
                ++left;
                --right;
            }

            this->setCurrent(isBeginning ? this->view.begin() : this->view.end());
            this->setEnd(this->view.end());
        }
    };
}