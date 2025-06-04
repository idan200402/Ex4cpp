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

template <typename T = int> class MyContainer{
    private:
        std::vector<T> data;
        void print(std::ostream& os = std::cout) const{
            for (const auto& elem : data) {
                os << elem << ' ';
            }
            os << std::endl;
        }
    public:
        MyContainer() = default;
        void addElement(const T& value){
            data.push_back(value);    
        }
        void removeElement(const T& value){
            auto newEnd = std::remove(data.begin(), data.end(), value);
            if (newEnd == data.end() && std::find(data.begin(), data.end(), value) == data.end()) {
                throw std::runtime_error("This element does not exist in the container");
            }
            data.erase(newEnd, data.end());
        }
        size_t size() const {
            return data.size();
        }
        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const MyContainer<U>& container);

        const std::vector<T>& getData() const {
            return data;
        }
        Order<T> begin_order() const {
            return Order<T>::make(*this).first;
        }
        Order<T> end_order() const {
            return Order<T>::make(*this).second;
        }
        AscendingOrder<T> begin_ascending_order() const {
            return AscendingOrder<T>::make(*this).first;
        }

        AscendingOrder<T> end_ascending_order() const {
            return AscendingOrder<T>::make(*this).second;
        }

        DescendingOrder<T> begin_descending_order() const {
            return DescendingOrder<T>::make(*this).first;
        }
        DescendingOrder<T> end_descending_order() const {
            return DescendingOrder<T>::make(*this).second;
        }
        SideCrossOrder<T> begin_side_cross_order() const {
            return SideCrossOrder<T>::make(*this).first;
        }
        SideCrossOrder<T> end_side_cross_order() const {
            return SideCrossOrder<T>::make(*this).second;
        }
        ReverseOrder<T> begin_reverse_order() const {
            return ReverseOrder<T>::make(*this).first;
        }
        ReverseOrder<T> end_reverse_order() const {
            return ReverseOrder<T>::make(*this).second;
        }
        MiddleOutOrder<T> begin_middle_out_order() const {
            return MiddleOutOrder<T>::make(*this).first;
        }
        MiddleOutOrder<T> end_middle_out_order() const {
            return MiddleOutOrder<T>::make(*this).second;
        }

       
        
    };
template <typename T>
std::ostream& operator<<(std::ostream& os, const MyContainer<T>& container) {
    container.print(os);
    return os;  
}
}