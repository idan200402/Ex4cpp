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
        ReverseOrder(std::vector<T> reversedView, size_t index = 0)
            : BaseIterator<T>(std::move(reversedView), index) {}

        static std::pair<ReverseOrder, ReverseOrder> make(const MyContainer<T>& container) {
            std::vector<T> data = container.getData();
            std::reverse(data.begin(), data.end());
            return {
                ReverseOrder(data, 0),
                ReverseOrder(data, data.size())
            };
        }
    };
}