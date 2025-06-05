#pragma once
#include <vector>
#include <algorithm>
#include "BaseIterator.hpp"
#include <memory>


namespace ex4 {
    template <typename T>
    // Forward declaration of MyContainer to use it in ReverseOrder
    class MyContainer;
    template <typename T>
    /**
     * @class ReverseOrder
     * @brief An iterator that traverses elements in reverse order.
     * This class inherits from BaseIterator and provides functionality to iterate over a reversed view of the elements.
     */
    class ReverseOrder : public BaseIterator<T> {
    public:
        /**
         * @brief Constructor for ReverseOrder.
         * @param reversedView A vector containing the elements arranged in reverse order.
         * @param index The starting index for the iterator, default is 0.
         */
        ReverseOrder(std::vector<T> reversedView, size_t index = 0)
            : BaseIterator<T>(std::move(reversedView), index) {}
        /**
         * @brief make function to create ReverseOrder iterators from a MyContainer data.
         * @param container The MyContainer object containing the elements to be reversed.
         * @return A pair of ReverseOrder iterators, one at the beginning and one at the end of the reversed data.
         */
        static std::pair<ReverseOrder, ReverseOrder> make(const MyContainer<T>& container) {
            std::vector<T> data = container.getData();
            // The reverse function will reverse the data in place.
            std::reverse(data.begin(), data.end());
            return {
                ReverseOrder(data, 0),
                ReverseOrder(data, data.size())
            };
        }
    };
}