#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"
#include <stdexcept>
using namespace ex4;

// Define a simple struct to use as a test case for various operations in MyContainer and to test the quality and correctness of the container's iterators.
struct Student {
            std::string name;
            int age;
            bool operator==(const Student& other) const {
                return name == other.name && age == other.age;
            }
            bool operator<(const Student& other) const {
                return age < other.age;
            }
            bool operator>(const Student& other) const {
                return age > other.age;
            }
            friend std::ostream& operator<<(std::ostream& os, const Student& student) {
                os << student.name << " , " << student.age;
                return os;
            }
        };
TEST_CASE("MyContainer basic operations") {
    SUBCASE("Checking if the container defult type is int") {
        MyContainer<> container;
        CHECK_NOTHROW(container.addElement('a'));
        CHECK_NOTHROW(container.addElement(1));
        CHECK_EQ(container.size(), 2);
        CHECK(container.getData().at(0) == 97); // ASCII value of 'a'
        CHECK(container.getData().at(1) == 1);
        //CHECK_THROWS(container.addElement("mango")); // this is a compile-time error.
        CHECK_NOTHROW(container.addElement(3.14)); // This should be allowed since T is int by default
        CHECK_EQ(container.size(), 3);
        CHECK(container.getData().at(2) == 3); // 3.14 is truncated to 3
    }
    SUBCASE("Checking if the container can hold strings") {
        MyContainer<std::string> stringContainer;
        CHECK_NOTHROW(stringContainer.addElement("apple"));
        CHECK_NOTHROW(stringContainer.addElement("banana"));
        // should be size of 2
        CHECK_EQ(stringContainer.size(), 2);
        CHECK(stringContainer.getData().at(0) == "apple");
        CHECK(stringContainer.getData().at(1) == "banana");
    }
    SUBCASE("Checking if the container can hold stucts of students") {
        
        MyContainer<Student> studentContainer;
        CHECK_NOTHROW(studentContainer.addElement({"Alice", 20}));
        CHECK_NOTHROW(studentContainer.addElement({"Bob", 22}));
        CHECK_EQ(studentContainer.size(), 2);
        CHECK(studentContainer.getData().at(0) == Student{"Alice", 20});
        CHECK(studentContainer.getData().at(1) == Student{"Bob", 22});
        CHECK_NOTHROW(studentContainer.removeElement({"Alice", 20}));
        CHECK_EQ(studentContainer.size(), 1);
    }
    SUBCASE("Add Element") {
        MyContainer<int> container;
        container.addElement(5);
        container.addElement(10);
        // should be size of 2
        CHECK_EQ(container.size(), 2);
        // should contain 5 and 10
        CHECK_EQ(container.getData().at(0), 5);
        CHECK_EQ(container.getData().at(1), 10);
    }
    SUBCASE("Remove Element") {
        MyContainer<int> container;
        container.addElement(5);
        container.addElement(10);
        CHECK_EQ(container.size(), 2);
        CHECK_NOTHROW(container.removeElement(5)); // should remove the only instance of 
        CHECK_EQ(container.size(), 1);
        CHECK_EQ(container.getData().at(0), 10);
        CHECK_THROWS_AS(container.removeElement(5), std::runtime_error); // should throw an error since 5 is not in the container anymore
        container.addElement(3); // add 3 twice to test if the removeElement removes all the instances of the element.
        container.addElement(3);
        CHECK_EQ(container.size(), 3);
        CHECK_NOTHROW(container.removeElement(3)); // should remove all instances of 3 , 2 elements.
        CHECK_EQ(container.size(), 1);
        CHECK_EQ(container.getData().at(0), 10); // should contain only 10 now
    }
    SUBCASE("Size") {
        MyContainer<int> container;
        CHECK_EQ(container.size(), 0); // initially empty
        container.addElement(1);
        CHECK_EQ(container.size(), 1); // after adding one element
        container.addElement(2);
        CHECK_EQ(container.size(), 2); // after adding another element
        container.removeElement(1);
        CHECK_EQ(container.size(), 1); // after removing one element
    }
    SUBCASE("overloaded << operator") {
        MyContainer<int> container;
    container.addElement(42);
    container.addElement(17);
    std::ostringstream out;
    out << container;
    CHECK(out.str() == "42 17 \n");
    }
    SUBCASE("getData") {
        MyContainer<int> container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
        const std::vector<int>& data = container.getData();
        CHECK(data.size() == 3);
        CHECK(data[0] == 1);
        CHECK(data[1] == 2);
        CHECK(data[2] == 3);
    }
}
TEST_CASE("Iterators Functionality") {
    //denode: since all the iterators are derived from BaseIterator, we will pick one of the iterators to test the functionality of the iterators.
    // we will use the Order iterator to test the functionality of the iterators.
    MyContainer<int> container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
    SUBCASE("Iterator * dereference operator overload") {
        auto it = container.begin_order();
        CHECK(*it == 1); // first element should be 1
        ++it;
        CHECK(*it == 2); // second element should be 2
        ++it;
        CHECK(*it == 3); // third element should be 3
    }
    SUBCASE("Iterator ++ pre-increment operator overload") {
        auto it = container.begin_order();
        CHECK(*it == 1); // first element should be 1
        ++it; // move to the second element
        CHECK(*it == 2); // second element should be 2
        ++it; // move to the third element
        CHECK(*it == 3); // third element should be 3
    }
    SUBCASE("Iterator != not equal operator overload") {
        auto it1 = container.begin_order();
        auto it2 = container.begin_order();
        CHECK(it1 == it2); // they should not be equal
        ++it2; // move to the second element
        CHECK(it1 != it2); // they should still not be equal
        ++it1; // move to the second element
        CHECK(it1 == it2); // now they should be equal
        MyContainer<int> anotherContainer;
        anotherContainer.addElement(1);
        anotherContainer.addElement(2);
        auto it3 = anotherContainer.begin_order();
        --it1; // move back to the first element
        CHECK(it1 != it3); // they should not be equal since they are from different containers
    }
    SUBCASE("Iterator -- pre-decrement operator overload") {
        auto it = container.begin_order();
        CHECK(*it == 1); // first element should be 1
        ++it; // move to the second element
        CHECK(*it == 2); // second element should be 2
        --it; // move back to the first element
        CHECK(*it == 1); // should still be 1
        CHECK_THROWS_AS(--it, std::out_of_range); // should throw an error since we are trying to decrement past the beginning
    }
    SUBCASE("Iterator == equal operator overload") {
        auto it1 = container.begin_order();
        auto it2 = container.begin_order();
        CHECK(it1 == it2); // they should be equal
        ++it2; // move to the second element
        CHECK(it1 != it2); // they should not be equal anymore
        ++it1; // move to the second element
        CHECK(it1 == it2); // now they should be equal again
    }
    SUBCASE("Iterator out of range exception") {
        auto it = container.begin_order();
        CHECK(*it == 1); // first element should be 1
        ++it; // move to the second element
        ++it; // move to the third element
        CHECK(*it == 3); // third element should be 3
        ++it; // move past the end
        CHECK_THROWS_AS(*it, std::out_of_range); // should throw an error since we are trying to dereference past the end
    }
    SUBCASE("Trying to dereference an iterator that is past the end") {
        auto it = container.begin_order();
        ++it; // move to the second element
        ++it; // move to the third element
        ++it; // move past the end
        CHECK_THROWS_AS(*it, std::out_of_range); // should throw an error since we are trying to dereference past the end
    }
    SUBCASE("getView method") {
        auto it = container.begin_order();
        CHECK(it.getView() == container.getData()); // should return the same view as the container's data
        ++it; // move to the second element
        CHECK(it.getView() == container.getData()); // should still return the same view
    }
}
TEST_CASE("Checking the make method of each derived iterator class") {
    SUBCASE("Order Iterator Make Method") {
        MyContainer<int> container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
        auto [begin, end] = Order<int>::make(container);
        CHECK(begin.getView() == container.getData());
        CHECK(end.getView() == container.getData());
    }
    SUBCASE("Ascending Order Iterator Make Method") {
        MyContainer<int> container;
        container.addElement(3);
        container.addElement(1);
        container.addElement(2);
        auto [begin, end] = AscendingOrder<int>::make(container);
        std::vector<int> expected = {1, 2, 3};
        CHECK(begin.getView() == expected);
        CHECK(end.getView() == expected);
    }
    SUBCASE("Descending Order Iterator Make Method") {
        MyContainer<int> container;
        container.addElement(3);
        container.addElement(1);
        container.addElement(2);
        auto [begin, end] = DescendingOrder<int>::make(container);
        std::vector<int> expected = {3, 2, 1};
        CHECK(begin.getView() == expected);
        CHECK(end.getView() == expected);
    }
    SUBCASE("Side Cross Order Iterator Make Method") {
        MyContainer<int> container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);
        auto [begin, end] = SideCrossOrder<int>::make(container);
        std::vector<int> expected = {1, 4, 2, 3};
        CHECK(begin.getView() == expected);
        CHECK(end.getView() == expected);
    }
    SUBCASE("Reverse Order Iterator Make Method") {
        MyContainer<int> container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
        auto [begin, end] = ReverseOrder<int>::make(container);
        std::vector<int> expected = {3, 2, 1};
        CHECK(begin.getView() == expected);
        CHECK(end.getView() == expected);
    }
    SUBCASE("Middle Out Order Iterator Make Method") {
        MyContainer<int> container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);
        auto [begin, end] = MiddleOutOrder<int>::make(container);
        std::vector<int> expected = {3, 2, 4, 1};
        CHECK(begin.getView() == expected);
        CHECK(end.getView() == expected);
    }
    SUBCASE("Empty Container Make Method") {
        MyContainer<int> emptyContainer;
        auto [begin, end] = Order<int>::make(emptyContainer);
        CHECK(begin.getView().empty());
        CHECK(end.getView().empty());
    }

}
TEST_CASE("Iterators Traversal Correctness") {
    SUBCASE("Order Iterator") {
        MyContainer<int> container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(4);
        container.addElement(3);
        int i = 0;
        // Check if the order iterator iterates through the elements in the order they were added
        for(auto it = container.begin_order(); it != container.end_order(); ++it) {
            CHECK(*it == container.getData().at(i));
            ++i;
        }
    }
    SUBCASE("Ascending Order Iterator") {
        MyContainer<int> container;
        container.addElement(3);
        container.addElement(1);
        container.addElement(4);
        container.addElement(2);
        int i = 0;
        // Check if the ascending order iterator iterates through the elements in ascending order
        for(auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it) {
            CHECK_FALSE(*it == container.getData().at(i));
            CHECK(*it == i + 1); // since we added 1,2,3,4 in the container
            ++i;
        }
    }
    SUBCASE("Descending Order Iterator") {
        MyContainer<int> container;
        container.addElement(3);
        container.addElement(1);
        container.addElement(4);
        container.addElement(2);
        int i = 3; // since we added 1,2,3,4 in the container
        // Check if the descending order iterator iterates through the elements in descending order
        for(auto it = container.begin_descending_order(); it != container.end_descending_order(); ++it) {
            CHECK_FALSE(*it == container.getData().at(i));
            CHECK(*it == i + 1); // since we added 1,2,3,4 in the container
            --i;
        }
    }
    SUBCASE("Side Cross Order Iterator") {
        MyContainer<int> container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);
        // Check if the side cross order iterator iterates through the elements in side cross order
        auto it = container.begin_side_cross_order();
        CHECK(*it == 1); // first element should be 1
        ++it;
        CHECK(*it == 4); // second element should be 4
        ++it;
        CHECK(*it == 2); // third element should be 2
        ++it;
        CHECK(*it == 3); // fourth element should be 3
        ++it;
        CHECK(it == container.end_side_cross_order()); // should reach the end
    }
    SUBCASE("Reverse Order Iterator") {
        MyContainer<int> container;
        container.addElement(20);
        container.addElement(10);
        container.addElement(30);
        container.addElement(40);
        auto it = container.begin_reverse_order();
        CHECK(*it == 40); // first element should be 40
        ++it;
        CHECK(*it == 30); // second element should be 30
        ++it;
        CHECK(*it == 10); // third element should be 10
        ++it;
        CHECK(*it == 20); // fourth element should be 20
        ++it;
        CHECK(it == container.end_reverse_order()); // should reach the end
    }
    SUBCASE("Middle Out Order Iterator") {
        MyContainer<int> container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);
        auto it = container.begin_middle_out_order();
        CHECK(*it == 3); // first element should be 2 (middle)
        ++it;
        CHECK(*it == 2); // second element should be 3
        ++it;
        CHECK(*it == 4); // third element should be 1
        ++it;
        CHECK(*it == 1); // fourth element should be 4
        ++it;
        CHECK(it == container.end_middle_out_order()); // should reach the end
    }
}
            
    

