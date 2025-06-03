#pragma once
#include <vector>
#include <algorithm>
#include "BaseIterator.hpp"


namespace ex4 {
    template <typename T>
    class MyContainer;
    template <typename T>
    class MiddleOutOrder : public BaseIterator<T> {
        public:
            MiddleOutOrder(const MyContainer<T>& container, bool isBeginning) {
                const auto& data = container.getData();
                int n = data.size();
                if(n == 0) {
                    this->setCurrent(this->view.begin());
                    this->setEnd(this->view.end());
                    return;
                }
                int middle = n / 2;
                this->view.push_back(data[middle]);
                int left = middle - 1;
                int right = middle + 1;
                bool leftTurn = true;
                while (left >= 0 || right < n) {
                    if (leftTurn && left >= 0) {
                        this->view.push_back(data[left]);
                        --left;
                    } else if (!leftTurn && right < n) {
                        this->view.push_back(data[right]);
                        ++right;
                    }
                    leftTurn = !leftTurn;
                }
                this->setCurrent(isBeginning ? this->view.begin() : this->view.end());
                this->setEnd(this->view.end());
            }
        };
    }
                