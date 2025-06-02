#pragma once 
#include <iterator>
#include <vector>
namespace ex4 {
template <typename T>
class BaseIterator{
    protected:
        using iterator = typename std::vector<T>::const_iterator;
        iterator current;
        iterator end;
        BaseIterator() = default;
        BaseIterator(const std::vector<T>& data , bool isBeginning){
            if (isBeginning) {
                current = data.begin();
                end = data.end();
            } else {
                current = data.end();
                end = data.begin();
            }
        }
    public:
        virtual ~BaseIterator() = 0;
        const T& operator*() const {
            return *current;
        }
        BaseIterator& operator++() {
            if (current != end) {
                ++current;
            }
            return *this;
        }
        bool operator!=(const BaseIterator& other) const {
            return current != other.current;
        }
        iteraor getCurrent() const {
            return current;
        }
        iterator getEnd() const {
            return end;
        }
        void setCurrent(iterator newCurrent) {
            current = newCurrent;
        }
        void setEnd(iterator newEnd) {
            end = newEnd;
        }
    };
    template <typename T>
BaseIterator<T>::~BaseIterator() {} // Define the pure virtual destructor
}   