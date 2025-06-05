#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <type_traits>
#include "Iterators/BaseIterator.hpp"
#include "Iterators/Order.hpp"
#include "Iterators/AscendingOrder.hpp"
#include "Iterators/DescendingOrder.hpp"
#include "Iterators/SideCrossOrder.hpp"
#include "Iterators/ReverseOrder.hpp"
#include "Iterators/MiddleOutOrder.hpp"



namespace ex4 {
/**
 * @class MyContainer 
 * @brief A generic container class that holds elements of type T and provides various iterators for traversing the elements in different orders.
 */
template <typename T = int> class MyContainer{
    private:
        // the internal storage for the container using a generic type T std::vector<T> to hold the elements.
        std::vector<T> data;
        // A private method to print the elements of the container to an output stream , its a helper function for the operator<< overload.
        void print(std::ostream& os = std::cout) const{
            for (const auto& elem : data) {
                os << elem << ' ';
            }
            os << std::endl;
        }
    public:
        /**
         * @brief Default constructor for MyContainer.
         * Initializes an empty container.
         * This constructor allows the creation of a MyContainer object without any initial elements.
         * It is useful when you want to add elements later.
         */
        MyContainer() = default;
        /**
         * @brief add an element to the container.
         * @param value The value to be added to the container , has to be of type T.
         */
        void addElement(const T& value){
            data.push_back(value);    
        }
        /**
         * @brief remove an element from the container , if this element has multiple instances, all instances will be removed.
         * @param value The value to be removed from the container , has to be of type T.
         * @throw std::runtime_error if the element does not exist in the container.
         */
         
        void removeElement(const T& value){
            //if the element is found , we will move them to the end of the vector and then erase them.
            auto newEnd = std::remove(data.begin(), data.end(), value);
            //if the end iterator stays the same  , and we did not find the element, we will throw an error.
            if (newEnd == data.end() && std::find(data.begin(), data.end(), value) == data.end()) {
                throw std::runtime_error("This element does not exist in the container");
            }
            //erase the elements from the new end (the begin of the elements that we want to remove) to the end of the vector.
            data.erase(newEnd, data.end());
        }
        /**
         * @brief Get the size of the container.
         * @return The number of elements in the container.
         */
        size_t size() const {
            return data.size();
        }
        /**
         * @brief Overloaded output stream operator to print the container's elements.
         * @param os The output stream to which the elements will be printed.
         * @param container The MyContainer object whose elements are to be printed.
         * @return The output stream after printing the elements.
         */
        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const MyContainer<U>& container);

        /**
         * @brief Get the data stored in the container.
         * @return A constant reference to the vector containing the elements of type T.
         */
        const std::vector<T>& getData() const {
            return data;
        }
        /**
         * @brief this method creates an begin iterator for the container , in a regular order.
         * @return An iterator that points to the first element of the container.
         */
        Order<T> begin_order() const {
            return Order<T>::make(*this).first;
        }
        /**
         * @brief this method creates an end iterator for the container , in a regular order.
         * @return An iterator that points to the end of the container.
         */
        Order<T> end_order() const {
            return Order<T>::make(*this).second;
        }
        /**
         * @brief Creates iterator for the container in ascending order.
         * @return An iterator that points to the first element of the container in ascending order.
         */
        AscendingOrder<T> begin_ascending_order() const {
            return AscendingOrder<T>::make(*this).first;
        }
        /**
         * @brief Creates an end iterator for the container in ascending order.
         * @return An iterator that points to the end of the container in ascending order.
         */
        AscendingOrder<T> end_ascending_order() const {
            return AscendingOrder<T>::make(*this).second;
        }
        /**
         * @brief Creates an iterator for the container in descending order.
         * @return An iterator that points to the first element of the container in descending order.
         */
        DescendingOrder<T> begin_descending_order() const {
            return DescendingOrder<T>::make(*this).first;
        }
        /**
         * @brief Creates an end iterator for the container in descending order.
         * @return An iterator that points to the end of the container in descending order.
         */
        DescendingOrder<T> end_descending_order() const {
            return DescendingOrder<T>::make(*this).second;
        }
        /**
         * @brief Creates an iterator for the container in side cross order.
         * @return An iterator that points to the first element of the container in side cross order.
         */
        SideCrossOrder<T> begin_side_cross_order() const {
            return SideCrossOrder<T>::make(*this).first;
        }
        /**
         * @brief Creates an end iterator for the container in side cross order.
         * @return An iterator that points to the end of the container in side cross order.
         */
        SideCrossOrder<T> end_side_cross_order() const {
            return SideCrossOrder<T>::make(*this).second;
        }
        /**
         * @brief Creates an iterator for the container in reverse order.
         * @return An iterator that points to the first element of the container in reverse order.
         */
        ReverseOrder<T> begin_reverse_order() const {
            return ReverseOrder<T>::make(*this).first;
        }
        /**
         * @brief Creates an end iterator for the container in reverse order.
         * @return An iterator that points to the end of the container in reverse order.
         */
        ReverseOrder<T> end_reverse_order() const {
            return ReverseOrder<T>::make(*this).second;
        }
        /**
         * @brief Creates an iterator for the container in middle out order.
         * @return An iterator that points to the first element of the container in middle out order.
         */
        MiddleOutOrder<T> begin_middle_out_order() const {
            return MiddleOutOrder<T>::make(*this).first;
        }
        /**
         * @brief Creates an end iterator for the container in middle out order.
         * @return An iterator that points to the end of the container in middle out order.
         */
        MiddleOutOrder<T> end_middle_out_order() const {
            return MiddleOutOrder<T>::make(*this).second;
        }

       
        
    };
// Overloaded output stream operator for MyContainer , outside the class definition we implement the operator<< function.
template <typename T>
std::ostream& operator<<(std::ostream& os, const MyContainer<T>& container) {
    container.print(os);
    return os;  
}
}