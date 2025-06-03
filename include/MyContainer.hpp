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
    public:
        MyContainer() = default;
        void addElement(const T& value){
            static_assert(std::is_integral<T>::value, "T must be an integral type");
            data.push_back(value);    
        }
        void removeElement(const T& value){
            static_assert(std::is_integral<T>::value, "T must be an integral type");
            auto newEnd = std::remove(data.begin(), data.end(), value);
            if (newEnd == data.end() && std::find(data.begin(), data.end(), value) == data.end()) {
                throw std::runtime_error("This element does not exist in the container");
            }
            data.erase(newEnd, data.end());
        }
        size_t size() const {
            return data.size();
        }
        void print(std::ostream& os = std::cout) const{
            for (const auto& elem : data) {
                os << elem << ' ';
            }
            os << std::endl;
        }
        const std::vector<T>& getData() const {
            return data;
        }
        Order<T> begin_order() const {
            return Order<T>(*this, true);
        }
        Order<T> end_order() const {
            return Order<T>(*this, false);
        }
        AscendingOrder<T> begin_ascending_order() const {
            return AscendingOrder<T>(*this, true);
        }
        AscendingOrder<T> end_ascending_order() const {
            return AscendingOrder<T>(*this, false);
        }
        DescendingOrder<T> begin_descending_order() const {
            return DescendingOrder<T>(*this, true);
        }
        DescendingOrder<T> end_descending_order() const {
            return DescendingOrder<T>(*this, false);
        }
        SideCrossOrder<T> begin_side_cross_order() const {
            return SideCrossOrder<T>(*this, true);
        }
        SideCrossOrder<T> end_side_cross_order() const {
            return SideCrossOrder<T>(*this, false);
        }
        ReverseOrder<T> begin_reverse_order() const {
            return ReverseOrder<T>(*this, true);
        }
        ReverseOrder<T> end_reverse_order() const {
            return ReverseOrder<T>(*this, false);
        }
        MiddleOutOrder<T> begin_middle_out_order() const {
            return MiddleOutOrder<T>(*this, true);
        }
        MiddleOutOrder<T> end_middle_out_order() const {
            return MiddleOutOrder<T>(*this, false);
        }

       
        
    };
template <typename T>
std::ostream& operator<<(std::ostream& os, const MyContainer<T>& container) {
    container.print(os);
    return os;  
}
}