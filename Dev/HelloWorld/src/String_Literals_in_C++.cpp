/*
String Literals (extends from Strings_in_C++.cpp)

String literals are a series of characters inbetween two double quotes.
*/
#include <iostream>
#include <string>

#include <stdlib.h>

int main() {
    // "Alan"; // This is a (const char [5]) array, where the 5th byte is a null termination character

    const char* name = "Alan";

    std::cout << strlen(name) << std::endl; // Ifwe left name as "Al\0an", this would print out '2', since it only counts up to \0

    // Now, 

    std::cin.get();
}