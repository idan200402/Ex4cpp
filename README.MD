# EX4: Custom Container with Multiple Iterators

## Overview

This project implements a generic, dynamic container class `MyContainer<T>`, which supports a variety of operations on elements of any comparable type (default: `int`) in order for the container to contain any class or struct , it has to overload  , < , > , ==  operators>
The container provides advanced iteration strategies through multiple custom iterators such as:

- AscendingOrder
- DescendingOrder
- SideCrossOrder
- ReverseOrder
- Order (insertion order)
- MiddleOutOrder
---

## Project Structure
main.cpp: demonstrates the usage of `MyContainer` with different iterators.
include/
    MyContainer.h: contains the definition of the `MyContainer` class and its iterators.
    iterators/
        BaseIterator.h: defines the base iterator class , with implementation of common iterator functionality.
        AscendingOrder.h: defines the ascending order iterator.
        DescendingOrder.h: defines the descending order iterator.
        SideCrossOrder.h: defines the side cross order iterator.
        ReverseOrder.h: defines the reverse order iterator.
        Order.h: defines the insertion order iterator.
        MiddleOutOrder.h: defines the middle out order iterator.
tests.cpp: contains unit tests for the `MyContainer` class and its iterators.
Makefile: used to build the project.

## Features
- **Dynamic Container**: Supports dynamic resizing and element management.
- **Multiple Iterators**: Provides various iterators for different traversal strategies.
- **Generic Type Support**: Can handle any type that supports comparison operators.
- **Custom Memory Management**: Implements custom memory management for dynamic arrays.
- **Unit Tests**: Includes unit tests to ensure the correctness of the container and iterators.
- **Documentation**: Well-documented code with clear comments and explanations.
- **Example Usage**: Demonstrates how to use the container and iterators in `main.cpp`.
- **Data Leak Check**: Ensures no memory leaks occur during the usage of the container.

## How to Build and Run
1. Clone the repository.
2. Navigate to the project directory.
3. make commands:
```
    - `make Main`: Compiles the main program and executes it.
    - `make tests`: Compiles the unit tests and executes them.
    - `make clean`: Cleans up the build files.
    - `make valgrind`: Runs the unit tests and the main with Valgrind to check for memory leaks.
```
Denote: Ensure you have a C++ compiler and the necessary build tools installed on your system.

## Example Usage
```cpp
MyContainer<int> container;
container.addElement(7);
container.addElement(15);
container.addElement(6);
container.addElement(1);
container.addElement(2);
container.addElement(2);
container.removeElement(2);
std::cout << container << std::endl;

for (auto it = container.begin_reverse_order(); it != container.end_reverse_order(); ++it) {
    std::cout << *it << ' ';
}
```
Expected Output:
```
7 15 6 1
1 6 15 7
```

## Author
Developed by Idan Shumski as a part of Ex4 in the C++ course.
