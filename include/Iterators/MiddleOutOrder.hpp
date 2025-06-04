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
            MiddleOutOrder() = default;
            MiddleOutOrder(std::vector<T> middleOutView, size_t index = 0):
                BaseIterator <T>(std::move(middleOutView), index) {} 
            static std::pair<MiddleOutOrder<T>, MiddleOutOrder<T>> make(const MyContainer<T>& container){
                std::vector<T> data = container.getData();
                int n = data.size();
                std::vector<T> middleOutView;
                middleOutView.reserve(n);
                if(n == 0) {
                    return { MiddleOutOrder<T>(), MiddleOutOrder<T>() };
                }
                int middle = n / 2;
                middleOutView.push_back(data[middle]);
                int left = middle - 1;
                int right = middle + 1;
                bool leftTurn = true;
                while (left >= 0 || right < n) {
                    if (leftTurn && left >= 0) {
                        middleOutView.push_back(data[left]);
                        --left;
                    } else if (!leftTurn && right < n) {
                        middleOutView.push_back(data[right]);
                        ++right;
                    }
                    leftTurn = !leftTurn;
                }
                return {
                    MiddleOutOrder<T>(middleOutView, 0),
                    MiddleOutOrder<T>(middleOutView, middleOutView.size())
                };
            }
        };
    }
                