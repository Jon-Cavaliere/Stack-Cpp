#include <iostream>
#include "Stack.h"

// Unit test
int main()
{
    // Create stack of type int
    JC::Stack<int> test(2);

    // Push 1 and 2 onto stack
    test.push(1);
    test.push(2);
    // Print top element
    std::cout << "Added 2, Top: " << *test.peek() << "\n";
    // Print entire stack
    test.print();

    // Push 3 onto stack
    test.push(3);
    // Print top element
    std::cout << "Added 3, Top: " << *test.peek() << "\n";
    // Print entire stack
    test.print();

    // Pop the top element 
    int pop = test.pop();
    // Print that element
    std::cout << "Popping: " << pop << "\n";
    // Print stack
    test.print();
    // Print top element
    std::cout << "Top: " << *test.peek() << "\n";

    // Push 3 back onto stack
    test.push(3);
    std::cout << "Added 3, Top: " << *test.peek() << "\n";
    test.print();

    // Check if stack has elements before popping
    if (test.hasNext())
    {
        pop = test.pop();
        std::cout << "Popping: " << pop << "\n";
        test.print();
    }

    // Check if top element exists
    if (test.peek() != nullptr)
        std::cout << "Top: " << *test.peek() << "\n";

    // Check if stack has elements before popping
    if (test.hasNext())
    {
        pop = test.pop();
        std::cout << "Popping: " << pop << "\n";
        test.print();
    }

    // Check if top element exists
    if (test.peek() != nullptr)
        std::cout << "Top: " << *test.peek() << "\n";

    // Check if stack has elements before popping
    if (test.hasNext())
    {
        pop = test.pop();
        std::cout << "Popping: " << pop << "\n";
        test.print();
    }

    // Check if top element exists
    if(test.peek() != nullptr)
        std::cout << "Top: " << *test.peek() << "\n";

    // Check if stack has elements before popping
    if (test.hasNext())
    {
        pop = test.pop();
        std::cout << "Popping: " << pop << "\n";
        test.print();
    }

    // Check if top element exists
    if (test.peek() != nullptr)
        std::cout << "Top: " << *test.peek() << "\n";
    else
        std::cout << "Stack is empty.\n";
}