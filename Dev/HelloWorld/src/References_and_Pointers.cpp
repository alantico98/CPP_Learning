#include <iostream>
#include <cstring>

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

    (void)buffer; // Keep the buffer allocation example without introducing an unused variable warning

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