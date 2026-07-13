// STATIC in C++
/*
Static outside of a class means that linkage of that symbol is only going to be visible inside that translation layer.

Static INSIDE of a class means that this memory is going to persist across ALL instances of that class. This also applies to static methods.

Essentially, the 'static' keyword declares the variable 'private' to this translation unit, similar to how we define 'private' in a struct or class

Now think about this deeper: if you declare a variable as 'static' in a .h (header) file, and include that header file in two different .cpp files, then effectively you've acheived the same thing. What you've done is declare the same variable as 'static' in two different files that have no association to each other, which is what you'd want to do in most scenarios since you don't want to declare variables as global unless you absolutely need to.
*/

static int s_Variable = 5; // This variable will only be linked internally to this translation layer. The linker is not going to look outside the scope of this translation unit for the symbol definition. Jump to "Static_in_C++_helper.cpp" to see how this works in practice

// Similar story for functions: anything declared as 'static' will remain private to the scope of this file (translation unit)
static void Function() {
    s_Variable += 1;
}

int main() {
    Function();
    (void)s_Variable;
    return 0;
}