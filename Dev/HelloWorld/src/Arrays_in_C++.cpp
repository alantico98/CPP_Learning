/*
Arrays are a way for C++ to represent a collection of values (note to brush up on pointers before proceeding further). Multiple variables in a single variable

Now, everything below is the 'raw' way of creating an array. In C++11, they introduced the 'std::array'. This is a safe, modern wrapper around traditional C-style arrays that keeps track of the size of your array and includes 'bounds' checking (can't index out of the allocated size)

On the topic of size, you aren't able to know the size of the array you created. You can somewhat find the size, but its compiler dependent (sometimes its stored in the -1 index). It depends on a lot of things, so you shouldn't be accessing the size of the array on the memory itself (this is very dangerous).
*/

#include <iostream>
#include <array>

class Entity {
public:
    // The lines below is what you're used to. If you go to the memory address of 'example' you'll see that the Entity memory address contains all of the twos.
    // int example[5];

    // Entity() {
    //     for (int = 0; i < 5; i++)
    //         example[i] = 2;
    // }

    /* However, if you switch this to be created on the heap, and (in debugging mode) you look at where the memory is stored, you don't see the '2s' at all. Instead, you have a different memory address that is pointing to where the array is stored in memory. This means that you're basically jumping around memory, which can result in a memory hit.
    */

    int* example = new int[5];
    Entity() {
        for (int i = 0; i < 5, i++)
            entity[i] = 2;
    }

    // Refer to the header note, but there isn't a straightforward way of checking the size of an array. Here's one way that you might go about it
    int a[5];
    int count = sizeof(a) / sizeof(int) // This will return the total count of elements in the array, which is 5

    // However, if you run this with 'example'
    int count_2 = sizeof(example) / sizeof(int) // This will return back to you the size of the integer pointer, which is 4 / 4 -> 1. This trick only works with stack allocated arrays.

    // Here's another way that you can go about maintaining the size yourself (C++ you just have to maintain it yourself, as none of the above options are reliable or trustworthy)
    static const int exampleSize = 5; // the reason that this needs to be static is because the variable needs to know what exampleSize is at compile time
    int example[exampleSize];

    // Here's the standard array from C++11 onwards
    std::array<int, 5> another;
    for (int i = 0; i < another.size(); i++)
        example[i] = 2;
}

int main() {
    int example[5]; // This is static memory allocation. It gets destroying once scope is finished executing
    example[0] = 2;
    example[1] = 2;
    example[2] = 2;
    example[3] = 2;
    example[4] = 2;

    // example[-1] = 5; // Both of these will cause a 'memory access violation'. You're trying to access memory that doesn't belong to you.
    // example[5] = 5; // This means that, unless you're in debug mode, it won't tell you this error. What this does in practice, is that you access a memory location that isn't allocated to your array, you modify it, and now you have no idea which variable in the program you just modified

    // Use a 'for' loop to index each element of the array and set them to a value of 2
    for (int i = 0; i < 5; i++)
        example[i] = 2

    // Remember: arrays are really just pointers (in this case an integer pointer) to where in memory we're storing the 5 integers
    int* ptr = example;

    example[2] = 5; // This is at an offset of 8-bytes of where 'example' is pointing to
    *(ptr + 2) = 6;
    /* 
    You might be asking 'why the plus 2'? When dealing with pointer arithmetic (when adding/setting a value of 2 to a pointer), the number of bytes that its going to add as an offset is depending on the type of pointer. In this case, this is an integer pointer. So 'plus 2' is really 2*4 because 4 bytes is the size of each integer (which lands you at index 2 for the array)
    */
    // *(int*)((char*)ptr + 8) = 6; // <- This is essentially what example[2] is acheiving to modify the bytes in place (to modify the bytes directly, you need to cast a single byte type to the pointer, offset it by the byte amount, the recast it to an 'int' before dereferencing it)

    int* another = new int[5]; // This is 'heap' memory allocation. It must be manually destroyed using the 'delete' keyword. Note that because this is an array (using the [] operator), we need to also us '[]' for the delete keyword
    for (int i = 0; i < 5; i++)
        another[i] = 2;
    delete[] another

    /*
    So, whats the reason why you would dynamically allocate memory using the 'new' keyword vs statically allocate it? Biggest reason is lifetimes.

    For example: If you have a function returning an array (and that array was created inside the function), you HAVE to allocate using the 'new' keyword. Otherwise, it would get destroyed as soon as the function is finished executing.

    Another thing to think about is memory indirection. What this means is that since the array is actually holding a pointer, and that pointer is pointing to another block of memory which holds the actual array, which can result in memory fragmentation and caching issues.
    */

    std::cout << example[0] << std::endl; // this will print out the value at index '0'
    std::cout << exmaple << std::endl; // this will print the memory address


    std::cin.get();
}