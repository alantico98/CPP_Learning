/*
Enums are a way to define a set of named integral constants that can be used to represent a collection of related values. In C++, enums can be defined using the `enum` keyword, and they can be either unscoped (traditional enums) or scoped (enum classes).

NOTE: Let's take a look back at the Log class in 'Writing_a_CPP_CLass.cpp' and see how we can use enums to define the log levels. Instead of using integer values to represent the log levels, we can define an enum to make the code more readable and maintainable.
*/

# include <iostream>

enum Example : unsigned char {  // The colon and datatype specify the type of the enum, which is `int` in this case. This is optional, but it can be useful for ensuring that the enum values are of a specific type. By default, enums are a 32-bit signed integer, but in this case, we don't need 32 bits, so we can specify `unsigned char` to save memory.
    A, B, C  // Keep in mind these are integers at the end of the day, so they can be compared to integers.

    // Also note the below example: If you start the enum from a value other than 0, the subsequent values will increment from that starting point. For example, if you start with `A = 5`, then `B` will be `6`, and `C` will be `7`.
    // A = 5, B, C
};

int a = 0;
int b = 1;
int c = 2;

int main() {
    Example value = Example::B;

    if (value == Example::B) {
        // Do something here
    }

    std::cin.get();
}