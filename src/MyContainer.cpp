#include "MyContainer.hpp"
namespace ex4 {
template <typename T>
    void MyContainer<T>::addElement(const T& value) {
        data.push_back(value);
    }
template <typename T>
    void MyContainer<T>::removeElement(const T& value) {
        auto newEnd = std::remove(data.begin(), data.end(), value);
        if (newEnd == data.end() && std::find(data.begin(), data.end(), value) == data.end()) {
            throw std::runtime_error("This element does not exist in the container");
        }
        data.erase(newEnd, data.end());
    }
template <typename T>
    size_t MyContainer<T>::size() const {
        return data.size();
    }
template <typename T>
    void MyContainer<T>::print(std::ostream& os) const {
        for (const auto& elem : data) {
            os << elem << ' ';
        }
        os << std::endl;
    }
template <typename T>
    std::ostream& operator<<(std::ostream& os, const MyContainer<T>& container) {
    container.print(os);
    return os;  
    }
}
