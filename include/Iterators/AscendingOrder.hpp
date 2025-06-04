#pragma once
#include <vector>
#include <algorithm>
#include "BaseIterator.hpp"
namespace ex4 {
    template <typename T>
    class MyContainer;
    template <typename T>
class AscendingOrder : public BaseIterator<T> {
public:
    AscendingOrder(std::vector<T> sortedView, size_t index = 0)
        : BaseIterator<T>(std::move(sortedView), index) {}

    // Factory method to construct begin and end iterators
    static std::pair<AscendingOrder, AscendingOrder> make(const MyContainer<T>& container) {
        std::vector<T> data = container.getData();
        std::sort(data.begin(), data.end());
        return {
            AscendingOrder(data, 0),
            AscendingOrder(data, data.size())
        };
    }
};

}    