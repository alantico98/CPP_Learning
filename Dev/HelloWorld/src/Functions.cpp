#include <iostream>
#include "Log.h"

int Multiply(int a, int b) {
    return a * b;
}

void MultiplyAndLog(int a, int b) {
    int result = Multiply(a, b);
    std::cout << result << std::endl;
}

int main() {
    // Note: While all functions are required to return whatever they're specified to return, the 'main' function is special
    // Only the 'main' function is exempt from this, and if you don't specifiy a 'return' keyword, it defaults to returning '0'

    int result = Multiply(3, 2);
    std::cout << result << std::endl;

    int result2 = Multiply(8, 5);
    std::cout << result2 << std::endl;

    int result3 = Multiply(90, 45);
    std::cout << result3 << std::endl;

    MultiplyAndLog(3, 5);
    MultiplyAndLog(8, 5);
    MultiplyAndLog(90, 45);
    
    InitLog();
    Log("Hello World!");
    std::cin.get();
}