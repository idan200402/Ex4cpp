#pragma once 
#include <iterator>
#include <vector>
#include <memory>
#include <stdexcept>
namespace ex4 {
template <typename T>
class MyContainer;
template <typename T>
class BaseIterator {
protected:
    std::vector<T> view;
    size_t currentIndex;
    size_t endIndex;

public:
    BaseIterator() : currentIndex(0), endIndex(0) {}

    BaseIterator(std::vector<T> traversalView, size_t startIndex = 0)
        : view(std::move(traversalView)), currentIndex(startIndex), endIndex(view.size()) {}

    virtual ~BaseIterator() = default;

    const T& operator*() const {
        if (currentIndex >= endIndex) {
            throw std::out_of_range("Dereferencing past the end");
        }
        return view[currentIndex];
    }

    BaseIterator& operator++() {
        ++currentIndex;
        return *this;
    }

    bool operator!=(const BaseIterator& other) const {
        return !(*this == other);
    }
    bool operator==(const BaseIterator& other) const {
        return currentIndex == other.currentIndex && view == other.view;
    }
    BaseIterator& operator--() {
        if (currentIndex == 0) {
            throw std::out_of_range("Cannot decrement past the beginning");
        }
        --currentIndex;
        return *this;
    }
    std::vector<T> getView() const {
        return view;
    }
};

}  // namespace ex4