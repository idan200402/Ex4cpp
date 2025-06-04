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
        DescendingOrder(std::vector<T> sortedView, size_t index = 0)
            : BaseIterator<T>(std::move(sortedView), index) {}

        static std::pair<DescendingOrder, DescendingOrder> make(const MyContainer<T>& container) {
            std::vector<T> data = container.getData();
            std::sort(data.begin(), data.end(), std::greater<T>());
            return {
                DescendingOrder(data, 0),
                DescendingOrder(data, data.size())
            };
        }
    };
}