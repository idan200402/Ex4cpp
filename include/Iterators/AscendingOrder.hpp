#pragma once
#include <vector>
#include <algorithm>
#include "BaseIterator.hpp"
namespace ex4 {
    template <typename T>
    // Forward declaration of MyContainer to use it in AscendingOrder
    class MyContainer;
    template <typename T>
    /**
     * @class AscendingOrder
     * @brief An iterator that traverses elements in ascending order.
     * This class inherits from BaseIterator and provides functionality to iterate over a sorted view of the elements.
     */
class AscendingOrder : public BaseIterator<T> {
public:
    /**
     * @brief Constructor for AscendingOrder.
     * @param sortedView A vector containing the elements arranged in ascending order.
     * @param index The starting index for the iterator, default is 0.
     */
    AscendingOrder(std::vector<T> sortedView, size_t index = 0)
        : BaseIterator<T>(std::move(sortedView), index) {}

    /**
     * @brief make function to create an AscendingOrder iterators from a MyContainer data.
     * @param container The MyContainer object containing the elements to be sorted.
     * @return A pair of AscendingOrder iterators, one at the beginning and one at the end of the sorted data.
     */
    static std::pair<AscendingOrder, AscendingOrder> make(const MyContainer<T>& container) {
        std::vector<T> data = container.getData();
        //the sort function will sort the data in ascending order.
        std::sort(data.begin(), data.end());
        return {
            AscendingOrder(data, 0),
            AscendingOrder(data, data.size())
        };
    }
};

}    