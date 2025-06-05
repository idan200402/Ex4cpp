#pragma once 
#include <vector>
#include "BaseIterator.hpp"
namespace ex4 {
    template <typename T>
    class MyContainer;
    template <typename T>
    class Order : public BaseIterator<T> {
    public:
        /**
         * @brief Constructor for Order.
         * @param traversalView A vector containing the elements to be traversed in order.
         * @param index The starting index for the iterator, default is 0.
         */
        Order(std::vector<T> traversalView, size_t index = 0)
         : BaseIterator<T>(std::move(traversalView), index) {}
        /**
         * @brief make function to create Order iterators from a MyContainer data.
         * @param container The MyContainer object containing the elements to be traversed in order.
         * @return A pair of Order iterators, one at the beginning and one at the end of the ordered data.
         */
         static std::pair<Order, Order> make(const MyContainer<T>& container) {
            //creating a copy of the data from the container and pass it to the Order constructor.
            std::vector<T> data = container.getData();
            return {
                Order(data, 0),
                Order(data, data.size()) 
            };
         }
        };
}