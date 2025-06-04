#pragma once 
#include <vector>
#include "BaseIterator.hpp"
namespace ex4 {
    template <typename T>
    class MyContainer;
    template <typename T>
    class Order : public BaseIterator<T> {
    public:
        Order(std::vector<T> traversalView, size_t index = 0)
         : BaseIterator<T>(std::move(traversalView), index) {}
        
         static std::pair<Order, Order> make(const MyContainer<T>& container) {
            std::vector<T> data = container.getData();
            return {
                Order(data, 0),
                Order(data, data.size()) 
            };
         }
        };
}