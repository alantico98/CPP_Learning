#include <iostream>
#include "Log.h"

int Multiply(int a, int b) {
    return a * b;
}

void MultiplyAndLog(int a, int b) {
    int result = Multiply(a, b);
    std::cout << result << std::endl;
}

# define LOG(x) std::cout << x << std::endl

// void Increment(int value) {
//     value++;
// }
// void Increment(int* value) {
//     (*value)++; // recall that '*' is to deference the pointer. Without this, it'll just increment the memory address, not the actual value of the operator. If you're wondering why the parenthesis, its because we need to dereference first, and then increment (if we left it as *value++, it would increment the memory address first, and then dereference)
// }
// Alternatively, we could use a reference to simplify what was acheived above
void Increment(int& value) {
    value++;
}

int main() {
    // Note: While all functions are required to return whatever they're specified to return, the 'main' function is special
    // Only the 'main' function is exempt from this, and if you don't specifiy a 'return' keyword, it defaults to returning '0'

    // int result = Multiply(3, 2);
    // std::cout << result << std::endl;

    // int result2 = Multiply(8, 5);
    // std::cout << result2 << std::endl;

    // int result3 = Multiply(90, 45);
    // std::cout << result3 << std::endl;

    MultiplyAndLog(3, 5);
    MultiplyAndLog(8, 5);
    MultiplyAndLog(90, 45);
    
    int a = 8;
    a++;
    const char* string = "Hello";

    for (int i = 0; i < 5; i++) {
        const char c = string[i];
        std::cout << c << std::endl;

    }

    // CONDITIONS and BRANCHES
    int x = 6;
    // bool comparisonResult = x == 5;
    // if (comparisonResult) {
    if (x == 5) {
        Log("Hello World!");
    }

    // const char* ptr = "Hello";
    // const char* ptr = nullptr;
    // if (ptr)
    //     Log(ptr);
    // else if (ptr == "Hello")
        // Log("Ptr is Hello!");
    // else
    //     Log("Ptr is null!)");

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

    /* MVP: POINTERS IN C++ (Raw pointers, not smart pointers)
     Brief: A pointer is an integer that stores a memory address!!
     Analogy: Memory in a computer is a one dimensional line. Imagine a city with one straight, and that straight is a row of houses. Every house on that street has an address. Each one of those houses is a byte.

     The 'pointer' is that specific homes address. You don't need to use them, but they're extremely useful, especially for C++ since the language provides precise memory control.

     Now 'types' have nothing to do with pointers. Types are fiction that we created to make our lives easier: they're meaningless. A 'pointer' for ALL types, is an integer.

     Recall: the asterisk '*' defines a pointer
    */
    // void* ptr = 0; // '0' is not a valid memory address
    // void* ptr = NULL; // Same with this
    // void* ptr = nullptr; // This was introduced in C++11

    int var = 8;
    // void* ptr = &var; // The '&' is asking for the memory address of the variable, and then we're assigning it to a new variable called 'ptr'
    int* ptr = &var;
    // double* ptr = (double*)&var;
    /* Again, types don't matter. They're useful for manipulation of that memory so if we wanted to read and write to that memory, types can help us out because the compiler will know, for example, that an integer is supposed to be 4 bytes of memory. But in the end (and int future videos) we'll go into more depth as to why and how types are meaningless
    */
    *ptr = 10; // In order to access the actual data, we 'dereference' by using '*' in front of the pointer
    LOG(var); // You'll notice that we successfully changed the value of 'var' from 8 to 10

    char* buffer = new char[8];  // This is asking for 8 bytes of memory; allocated 8 bytes of memory and returning 8 bytes to that beginning of memory
    memset(buffer, 0, 8); // Fills the block of memory with the data that we specify. Takes in a variable, sets the value ('0' in this case), and how much memory it should fill up (8 bytes)

    char** ptr = &buffer; // double pointer that's set to the memory address of 'buffer'

    // REFERENCES IN C++
    // References an existing variable -> They need to reference an already existing variable. They aren't new variables or occupy new storage
    int a = 5;
    int& ref = a; // Slightly different from the example of &a, which is asking for the memory address of 'a'
    ref = 2; // Imagine that 'ref' is now an alias. You now have direct access to 'a'
    LOG(a); // This will print out '2'

    /* Now imagine that we have the Increment function void Increment(int value) -> value++. This will copy 'a' into the variable 'value', and then increment the value of 'value', so 'a' will remain as '5'. What you actually need to do is point to the actual variable. Key thing to know is that there's nothing that you can do with a reference, that you can't also acheive with a reference. Pointers are like refernces, but even more useful and more powerful. However, if you can get away with using references, take that route. 

    Something else to note, but once you declare a reference, you can't change what its referencing.

    Ex:
    int a = 5;
    int b = 8;

    int& ref = a;
    ref = b;  <- This will set 'a' equal to the value of 'b', which is 8

    You also can't declare a reference without assigning it to somehting
    int& ref; <- Compiler will complain about this

    Now for pointers, you can re-assign it
    int* ref = &a;
    ref = &b; <- This is valid

    You can do some neat tricks with this as well:
    int* ref = &a;
    *ref = 2;
    ref = &b;
    *ref = 1;

    LOG(a); <- This will output '2'
    LOG(b); <- This will output '1'
    */

    delete[] buffer;

    // InitLog();
    // Log("Hello World!");
    std::cin.get();
}