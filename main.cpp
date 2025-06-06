#include <iostream>
#include "MyContainer.hpp"
using namespace ex4;
int main() {
    MyContainer<int> container;
    container.addElement(7);
    container.addElement(15);
    container.addElement(6);
    container.addElement(1);
    container.addElement(2);
    container.addElement(2); 

    std::cout << "Size of container: " << container.size() << std::endl;
    container.removeElement(2);  // Remove one instance of 2
    std::cout << "Size of container after removing one instance of 2: " << container.size() << std::endl;
    std::cout <<"This is the containers content: "<<container<<std::endl;  
    try{
        container.removeElement(2);  // Attempt to remove another instance of 2
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;  // This should throw an error
    }
    std::cout << "iterating over the container using acsending order iterator: "<<std::endl;
     for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it) {
         std::cout << *it << ' ';   
     }
    std::cout << std::endl;
     std::cout << "iterating over the container using descending order iterator: "<<std::endl;
    for (auto it = container.begin_descending_order(); it != container.end_descending_order(); ++it) {
        std::cout << *it << ' ';  
    }
    std::cout << std::endl;
    std::cout << "This is the containers content in side cross order: "<<std::endl;
    for (auto it = container.begin_side_cross_order(); it != container.end_side_cross_order(); ++it) {
        std::cout << *it << ' ';  
    }
    std::cout << std::endl;

    std::cout << "This is the containers content in reverse order: "<<std::endl;
    for (auto it = container.begin_reverse_order(); it != container.end_reverse_order(); ++it) {
        std::cout << *it << ' ';  
    }
    std::cout << std::endl;

    std::cout << "This is the containers content in normal order: "<<std::endl;
    for (auto it = container.begin_order(); it != container.end_order(); ++it) {
        std::cout << *it << ' ';  
    }
    std::cout << std::endl;
    std::cout << "This is the containers content in middle out order: "<<std::endl;
    for (auto it = container.begin_middle_out_order(); it != container.end_middle_out_order(); ++it) {
        std::cout << *it << ' ';  
    }
    std::cout << std::endl;

  

    return 0;
}