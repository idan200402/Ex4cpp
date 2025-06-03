#pragma once 
#include <iterator>
#include <vector>
#include <memory>
#include <stdexcept>
namespace ex4 {
template <typename T>
class MyContainer;
template <typename T>
class BaseIterator{
    protected:
        using iterator = typename std::vector<T>::const_iterator;
        iterator current;
        iterator end;
        const std::vector<T>*view = nullptr; // Reference to the vector being iterated over
    public:
        BaseIterator()  = default; // Default constructor
       
        BaseIterator(const std::vector<T>& data, bool isBeginning)
        : view(&data) {
            current = isBeginning ? view->begin() : view->end();
            end = view->end();
        }

        virtual ~BaseIterator() = 0;

        const T& operator*() const {
            if (current == end) {
                throw std::out_of_range("Trying to dereference an end iterator");
            }
            return *current;
        }
        BaseIterator& operator++() {
            ++current;
            return *this;
        }
        bool operator!=(const BaseIterator& other) const {
            return current != other.current;
        }
        iterator getCurrent() const {
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
        void setView(const std::vector<T> &newView) {
            view = &newView;
        }
    };
    template <typename T>
BaseIterator<T>::~BaseIterator() {} // Define the pure virtual destructor
}   