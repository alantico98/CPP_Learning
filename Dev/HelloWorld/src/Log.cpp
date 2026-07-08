// #include "Common.h" //without #pragma once in Log.h, because Common.h also includes Log.h, it will copy and paste the same function definition here twice
#include "Log.h"
#include <iostream> // key note: angular brackets (the "<>" that you see in this include statement) searches you're include directory for files names this
                    // Double quotes "" are typically reserved for packages and files that are relative to the current directory (ex: either "../Log.h" if its up a directory)

void InitLog() {
    Log("Initializing Log");
}

void Log(const char* message) {
    std::cout << message << std::endl;
}