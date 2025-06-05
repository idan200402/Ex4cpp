#pragma once
#include <vector>
#include <algorithm>
#include "BaseIterator.hpp"

namespace ex4 {
    template <typename T>
    // Forward declaration of MyContainer to use it in SideCrossOrder
    class MyContainer;
    template <typename T>
    /**
     * @class SideCrossOrder
     * @brief An iterator that traverses elements in a side-cross order.
     * This class inherits from BaseIterator and provides functionality to iterate over a view of the elements arranged in a side-cross order.
     */
    class SideCrossOrder : public BaseIterator<T> {
    public:
        /**
         * @brief constructor for SideCrossOrder.
         * @param sideCrossView A vector containing the elements arranged in a side-cross order.
         * @param index The starting index for the iterator, default is 0.
         */
        SideCrossOrder(std::vector<T> sideCrossView, size_t index = 0):
            BaseIterator<T>(std::move(sideCrossView), index) {}
        /**
         * @brief make function to create SideCrossOrder iterators from a MyContainer data.
         * @param container The MyContainer object containing the elements to be arranged in a side-cross order.
         * @return A pair of SideCrossOrder iterators, one at the beginning and one at the end of the side-cross ordered data.
         */
        static std::pair<SideCrossOrder<T>, SideCrossOrder<T>> make(const MyContainer<T>& container) {
        std::vector<T> data = container.getData();
        //first we will sort the data in ascending order to ensure the side-cross order is correct.
        std::sort(data.begin(), data.end());
        std::vector<T> sideCrossView;
        size_t left = 0;
        size_t right = data.size() - 1;
        // setting the left and right pointers to the beginning and end of the data vector.
        // We will alternate between the left and right ends of the sorted data until we exhaust all elements.
        while (left <= right) {
            //stop condition: if left pointer is equale to the right pointer, we have traversed all elements.
            if (left == right) {
                sideCrossView.push_back(data[left]);
                break;
            }
            // We will push the left element first, then the right element ,and move the indexes accordinglly.
            sideCrossView.push_back(data[left++]);
            sideCrossView.push_back(data[right--]);
        }

        return {
            SideCrossOrder<T>(sideCrossView, 0),
            SideCrossOrder<T>(sideCrossView, sideCrossView.size())
        };
    }
    };
}