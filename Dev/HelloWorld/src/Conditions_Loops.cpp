#include <iostream>
#include "Log.h"

# define LOG(x) std::cout << x << std::endl

int main() {
    // CONDITIONS and BRANCHES
    int x = 6;
    // bool comparisonResult = x == 5;
    // if (comparisonResult) {
    if (x == 5) {
        Log("Hello World!");
    }

    const char* ptr = "Hello";
    ptr = nullptr;
    if (ptr)
        Log(ptr);
    else if (std::string(ptr ? ptr : "") == "Hello")
        Log("Ptr is Hello!");
    else
        Log("Ptr is null!");
    
        // LOOPS IN C++
    for (int i = 0; i < 5; i++) {
    // Let's break this down:
    //  1. First argument you have to declare/use a variable. Executed once only
    //  2. Second argument is the condition. Evaluated before the next iteration
    //  3. Third argument is code that get's called at the end of the iteration (in this case, i++ is the same as i = i + 1, or i += 1)
        Log("Hello World!");
    }

    // This is another flavor of the above for loop, just broken down into separate parts
    int i = 0;
    bool condition = true;
    for ( ; condition; ) {  // note that 'for ( ; ; )' will run forever since there's no condition to evaluate against
        Log("Hello World!");
        i++;
        if (!(i < 5))
            condition = false;
    }

    Log("==============================");

    // While loops
    while (i < 5) {
        Log("Hello World!");
        i++;
    }

    // 'do while' loop
    do { // These kind of loops are guarenteed to execute at least once, even if the 'while' condition is false; executes the code in the 'do' block
        const char* some_string = "Some execution of code...";
        std::cout << some_string << std::endl;
    } while (condition);

    // CONTROL FLOW IN C++: continue, break, return
    // 'continue': Jumps to the next iteration of the loop
    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0)
            continue;
        Log("Hello World");
        std::cout << i << std::endl;
    }
    // 'break': Breaks out of the loop entirely
    for (int i = 0; i < 5; i++) {
        if ((i + 1) % 2 == 0)
            break;  // Break out of the loop if the number is even
        Log("Hello World");
        std::cout << i << std::endl;
    }
    // 'return': Leaves the function entirely. This doesn't need to be in a loop; 'return' can be placed anywhere in the function to leave the function
    // The loop below is commented out so that running doesn't exit out of the function prematurely
    // for (int i = 0; i < 5; i++) {
    //     if ((i + 1) % 2 == 0)
    //         return 0; // Breaks out of the function
    //     Log("Hello World");
    //     std::cout << i << std::endl;
    // }
    std::cin.get();
}