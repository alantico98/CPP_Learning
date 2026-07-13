/*
Constructors are special method that runs every time that we isntantiate a new object of a class. It is used to initialize the object and set its initial state. It has the same name as the class and does not have a return type, not even void. It can take parameters, which allows us to pass values to the constructor when we create an object.

Destructors are the evil twin. It's used to 'uninitialize' an object and free up any resources that the object may have acquired during its lifetime. It applies to both stack and heap allocated objects.
*/

#include <iostream>

class Entity {
    public:
        float X, Y;

        // void Init() {
        //     X = 0.0f;
        //     Y = 0.0f;
        // }

        // Now, the above is a lot of code for a simple case, and would bloat your script if you had a lot of classes like this. So, we can use a constructor to do the same thing in a more concise way. Every time you construct an object of the class, it gets called. It doesn't have a return type, not even void, and it has the same name as the class.
        Entity() {
            X = 0.0f;
            Y = 0.0f;
            std::cout << "Created Entity!" << std::endl;
        }
        // NOTE: Every class has a default constructor provided, but essentially its just the block of code that we have above, but empty.

        // Another way to write this is passing parameters to the constructor. This allows you to construct your entity with parameters
        // Entity(float x, float y) {
        //     X = x;
        //     Y = y;
        // }

        ~Entity() {
            std::cout << "Destroyed Entity!" << std::endl;
        }

        void Print() {
            std::cout << X << ", " << Y << std::endl;
        }
};

// Now lets say for example that you don't want someone to instantiate a class and only let them access it through static methods. You can do this by making the constructor private, and then providing static methods to access the class.
class Log {
    // private:
    //     Log() {} // This is a private constructor, so no one can instantiate this class. However, this still provides a default constructor. We can tell the compiler to not provide one but using the below method

    public:
        Log() = delete; // This tells the compiler to not provide a default constructor, so no one can instantiate this class. However, we can still access it through static methods.

        static void Write(const char* message) {
            std::cout << message << std::endl;
        }
};

void Function() {
    Entity e; // This will call the constructor and initialize the object. If we didn't have a constructor, this would just create an uninitialized object, and the values of X and Y would be garbage values.
    e.Print();
    // e.~Entity(); // This calls the destructor manually

} // Now, this is called and created on the stack, so when this function goes out of scope, the destructor will be called and the object will be destroyed. If we had created this object on the heap, we would have to manually call delete to destroy it. That being said, its not common practice and not recommended to create objects on the heap unless you have a specific reason to do so. The stack is much faster and more efficient, and the memory is automatically managed for you.


int main() {
    // Entity e;
    // Entity e(5.0f, 8.0f); // This will call the constructor with parameters, and set X and Y to 5.0f and 8.0f respectively, assuming that the constructor is defined as such.

    // e.Init();  // Initialize the object before using it
    // Let's try an alternative method: printing X and Y directly
    // std::cout << e.X << ", " << e.Y << std::endl;  // If we try to compile this without calling Init(), we'll get an 'error C4700: uninitialized local variable 'e' used. In other words, it won't compile because we're trying to use memory that hasn't been initialized.

    // e.Print();  // Technically this will work, but the values of X and Y are uninitialized, so they will contain garbage values. This is because we haven't set them to any specific values yet.
    Function ();
    std::cin.get();
}