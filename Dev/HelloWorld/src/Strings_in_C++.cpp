/* 
A string is a group of characters (text). First thing to learn is what are characters?

There are many different types of characters. So far, we've been using this as a way to cast or do things in terms of a single byte. Its also very useful for string.

A string is just an array of characters (look at arrays if you haven't already)
*/
#include <iostream>
#include <string>

// void PrintString(std::string string) { // Note that this method creates a copy and passes that into the function. Now, especially for strings, this is a costly operation where it needs to dynamically allocate memory onto the heap. Whenever you pass a string like this, and its read only, make sure you pass it as a const reference
//     std::cout << string << std::endl;
// }

// Do the following instead. 'std::string&' means to pass a reference, and 'const' promises not to modify it
void PrintString(const std::string& string) {
    std::cout << string << std::endl;
}

int main() {
    // The reason why most people use const char* is because strings are immutable by default, and so const is a way to ensure that the string isn't attempted to be changed in the future.
    const char* name = "Alan";
    // name[2] = 'a'; // This won't work if name was declared as const

    /* Now, if you look at where the memory is allocated in debug mode, you'll see that 'name' is stored under many bytes, more specifically its defaulted into ASCII. ASCII is in Hexadecimal, and stores 1 byte of memory
    
    You'll also notice that at the end, there's a '00' byte. That's the 'null termination character'. That's how we know where the string ends. It's out when we print out to the console, it hits that '00', and knows to terminate the line there. Let's see what happens when we do this manually.
    */
    // Note: A char by default is defined using single quotes. When using double quotes, it defaults to a char pointer (which will be touched on in a sec)
    char name2[5] = { 'A', 'l', 'a', 'n', 0};
    std::cout << name2 << std::endl;  // This would print out 'Alan' and then a bunch of extra weird characters, since it doesn't know where to stop. However, because 0 got added add the end, NOW it'll know where to stop

    /*
    So, where does C++ fit in all of this? The std library has a template class called 'string', and std::string is a templated specialization, with char as the template parameter.

    Basically, its a char array with a bunch of functions to manipulate it.
    */
    std::string name3 = "Alan";// + " hello!" // This won't work because you're trying to add 2 const char arrays. You can't add two pointers or arrays to each other
    std::cout << name3 << std::endl; // This needs the '#include <string>' contains the overload for std::cout to the console.
    // There's also some useful functions inside the string class
    name3.size()
    bool contains = name3.find("no") != std::string::npos // npos means an illegal position (it doesn't exist)

    // Appending strings
    name3 += " hello!"; // std::string is overloaded to allow this. You can also do something like below
    // Here, you're explicitly calling the string constructor, and then appending a char pointer to it
    std::string name4 = std::string("Alan") + " hello!";
    
    // Now, you may wonder

    std::cin.get();
}