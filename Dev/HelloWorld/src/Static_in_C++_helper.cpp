#include <iostream>

int s_Variable = 10; // Remember: this variable is defined in the GLOBAL scope, and not confined to the function.

// Another way to get around the linking error (ex: if in Static_in_C++.cpp, the s_Variable was defined as 'int s_Variable = 10') is to define the variable in this file as:
// extern int s_Variable; // This tells the linker to look for the s_Variable in an external translation unit. This is called 'external linking'. Alternatively, if in 'Static_in_C++.cpp', we declare the variable as static, then we'll get an error 'unresolved external symbol "int s_Variable"'.

// Again, if in Static_in_C++.cpp this function was declared 'static', then in here there won't be a problem compiling the code.
void Function () {

}

int main() {
    std::cout << s_Variable << std::endl; // There's no problems running this and getting 10 printed to the console, so long as in 'Static_in_C++.cpp', the variable 's_Variable' has 'static' in front of it, which restricts the variable to that file's translation unit (prevents global discovery and prevents a linking error)
    std::cin.get();
}