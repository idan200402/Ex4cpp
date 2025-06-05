#pragma once
#include <vector>
#include <algorithm>
#include "BaseIterator.hpp"


namespace ex4 {
    template <typename T>
    // Forward declaration of MyContainer to use it in MiddleOutOrder
    class MyContainer;
    template <typename T>
    /**
     * @class MiddleOutOrder
     * @brief An iterator that traverses elements in a middle-out order.
     * This class inherits from BaseIterator and provides functionality to iterate over a view of the elements arranged in a middle-out order.
     */
    class MiddleOutOrder : public BaseIterator<T> {
        public:
            /**
             * @brief Default constructor for MiddleOutOrder.
             * Initializes an empty iterator , useful for edge cases where no elements are present.
             */
            MiddleOutOrder() = default;
            /**
             * @brief Constructor that initializes the iterator with a middle-out view of the elements.
             * @param middleOutView A vector containing the elements arranged in a middle-out order.
             * @param index The starting index for the iterator, default is 0.
             */
            MiddleOutOrder(std::vector<T> middleOutView, size_t index = 0):
                BaseIterator <T>(std::move(middleOutView), index) {} 
            /**
             * @brief make function to create MiddleOutOrder iterators from a MyContainer data.
             * @param container The MyContainer object containing the elements to be arranged in a middle-out order.
             * @return A pair of MiddleOutOrder iterators, one at the beginning and one at the end of the middle-out ordered data.
             */
            static std::pair<MiddleOutOrder<T>, MiddleOutOrder<T>> make(const MyContainer<T>& container){
                std::vector<T> data = container.getData();
                int n = data.size();
                std::vector<T> middleOutView;
                // Reserve space in the middleOutView to avoid multiple reallocations
                middleOutView.reserve(n);
                // If the container is empty, return an empty MiddleOutOrder
                if(n == 0) {
                    return { MiddleOutOrder<T>(), MiddleOutOrder<T>() };
                }
                int middle = n / 2;
                //the first element in the middleOutView will be the middle element of the data.
                middleOutView.push_back(data[middle]);
                int left = middle - 1;
                int right = middle + 1;
                bool leftTurn = true;
                // We will alternate between left and right, starting from the middle element until we exhaust all elements.
                while (left >= 0 || right < n) {
                    // If leftTurn is true, we take from the left side, otherwise from the right side.
                    if (leftTurn && left >= 0) {
                        middleOutView.push_back(data[left]);
                        --left;
                    // If leftTurn is false, we take from the right side.
                    } else if (!leftTurn && right < n) {
                        middleOutView.push_back(data[right]);
                        ++right;
                    }
                    leftTurn = !leftTurn;
                }
                // Return a pair of MiddleOutOrder iterators, one at the beginning and one at the end of the middleOutView.
                return {
                    MiddleOutOrder<T>(middleOutView, 0),
                    MiddleOutOrder<T>(middleOutView, middleOutView.size())
                };
            }
        };
    }
                