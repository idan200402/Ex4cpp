#pragma once 
#include <iterator>
#include <vector>
#include <memory>
#include <stdexcept>
namespace ex4 {
// Forward declaration of MyContainer to use it in BaseIterator
template <typename T>
class MyContainer;
template <typename T>
/**
 * @class BaseIterator
 * @brief A base iterator class that provides common functionality for iterators in the MyContainer class.
 */
class BaseIterator {
protected:
    // The view is a vector that holds the elements to be traversed.
    std::vector<T> view;
    // The current index of the iterator in the view.
    size_t currentIndex;
    // The end index of the view, used to determine when the iterator has reached the end.
    size_t endIndex;

public:
    /**
     * @brief Default constructor for BaseIterator.
     * Initializes the iterator with an empty view and sets the current index and end index to 0.
     */
    BaseIterator() : currentIndex(0), endIndex(0) {}
    /**
     * @brief Constructor for BaseIterator that initializes the iterator with a given traversal view.
     * @param traversalView A vector containing the elements to be traversed.
     * @param startIndex The starting index for the iterator, default is 0.
     */
    BaseIterator(std::vector<T> traversalView, size_t startIndex = 0)
        : view(std::move(traversalView)), currentIndex(startIndex), endIndex(view.size()) {}
    /**
     * @brief pure virtual destructor for BaseIterator.
     * This ensures that we wont be able to instantiate BaseIterator directly, as it is meant to be a base class for other iterators.
     */
    virtual ~BaseIterator() = default;
    /**
     * @brief method to dereference the iterator.
     * @return A reference to the current element in the view.
     * @throw std::out_of_range if the current index is past the end of the view.
     */
    const T& operator*() const {
        if (currentIndex >= endIndex) {
            throw std::out_of_range("Dereferencing past the end");
        }
        return view[currentIndex];
    }
    /**
     * @brief Overloaded pre-increment operator to move the iterator to the next element.
     * @return A reference to the current iterator after incrementing.
     */
    BaseIterator& operator++() {
        ++currentIndex;
        return *this;
    }
    /**
     * @brief Overloaded not equal operator to compare two iterators. This operator checks if the current index and view of two iterators are equal.
     * @param other The other iterator to compare with.
     * @return true if the iterators are not equal, false otherwise.
     */
    bool operator!=(const BaseIterator& other) const {
        return !(*this == other);
    }
    /**
     * @brief Overloaded equality operator to compare two iterators.
     * @param other The other iterator to compare with.
     * @return true if the current index and view of both iterators are equal, false otherwise.
     */
    bool operator==(const BaseIterator& other) const {
        return currentIndex == other.currentIndex && view == other.view;
    }
    /**
     * @brief Overloaded pre-decrement operator to move the iterator to the previous element.
     * @return A reference to the current iterator after decrementing.
     * @throw std::out_of_range if the current index is already at the beginning of the view.
     */
    BaseIterator& operator--() {
        if (currentIndex == 0) {
            throw std::out_of_range("Cannot decrement past the beginning");
        }
        --currentIndex;
        return *this;
    }
    /**
     * @brief Method to get the view of the iterator.
     * @return A vector containing the elements that the iterator is traversing.
     */
    std::vector<T> getView() const {
        return view;
    }
};

}  // namespace ex4