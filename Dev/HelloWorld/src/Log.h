#pragma once // '#' is a preprocessor. 'pragma once' is called a header guard. 
// Prevents from including a single header file multiple times in a single tranlation unit.
// Note: This doesn't mean that you can't include the header file into multiple .cpp files, just that
// this prevents the compiler from including it multiple times WITHIN the SAME .cpp file -> This 
// prevents duplicate errors

#ifndef _LOG_H // check if a symbol called _LOG_H is defined. If defined, everything inside the ifndef block won't be included
#define _LOG_H // Note: This is the older way of doing the '#pragma once' logic. 

void InitLog();
void Log(const char* message);

struct Player {};

#endif