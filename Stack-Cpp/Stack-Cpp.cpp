#include <iostream>
#include "Stack.h"
int main()
{
    JC::Stack<int> test(2);
    std::cout << "Hello World!\n";

    test.push(1);
    test.push(2);
    std::cout << "Added 2 \n";
    test.print();
    test.push(3);
    std::cout << "Added 3 \n";
    test.print();
    int pop = test.pop();
    std::cout << "Popping: " << pop << "\n";
    test.print();

    test.push(3);
    std::cout << "Added 3 \n";
    test.print();
}