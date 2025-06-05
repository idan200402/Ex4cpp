#pragma once 
#include <iterator>
#include <vector>
#include "BaseIterator.hpp"
#include <algorithm>
namespace ex4 {
    template <typename T>
    // Forward declaration of MyContainer to use it in DescendingOrder
    class MyContainer;
    template <typename T>
    /**
     * @class DescendingOrder
     * @brief An iterator that traverses elements in descending order.
     * This class inherits from BaseIterator and provides functionality to iterate over a sorted view of the elements.
     */
    class DescendingOrder : public BaseIterator<T> {
    public:
        /**
         * @brief constructor for DescendingOrder.
         * @param sortedView A vector containing the elements arranged in descending order.
         * @param index The starting index for the iterator, default is 0.
         */
        DescendingOrder(std::vector<T> sortedView, size_t index = 0)
            : BaseIterator<T>(std::move(sortedView), index) {}
        /**
         * @brief make function to create DescendingOrder iterators from a MyContainer data.
         * @param container The MyContainer object containing the elements to be sorted.
         * @return A pair of DescendingOrder iterators, one at the beginning and one at the end of the sorted data.
         */
        static std::pair<DescendingOrder, DescendingOrder> make(const MyContainer<T>& container) {
            std::vector<T> data = container.getData();
            // The sort function will sort the data in descending order if we add std::greater<T>() as the third argument.
            std::sort(data.begin(), data.end(), std::greater<T>());
            return {
                DescendingOrder(data, 0),
                DescendingOrder(data, data.size())
            };
        }
    };
}