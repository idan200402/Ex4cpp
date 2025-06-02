#pragma once 
#include <vector>
#include "../MyContainer.hpp"
#include "BaseIterator.hpp"
namespace ex4 {
    template <typename T>
    class Order : public BaseIterator<T> {
    public:
        Order(const MyContainer<T>& container, bool isBeginning)
            : BaseIterator<T>(container.getData(), isBeginning) {}
    }
}