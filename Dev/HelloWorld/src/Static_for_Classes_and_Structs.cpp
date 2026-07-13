// Static in Classes and Structs:
/*
Static means that there's only going to be one instance of a variable across all instances of the class. That means if one of those instances change the static variable, then it'll be reflected across ALL instances.

Static methods are similar where you don't have access to the class instance. You can call the class method without the instance, and similarly, inside that method you can't write code that refers to the attributes or methods of the class instance. Read the following code and comments before resuming here...

Resume:
You could of course just create a global variable, or a static global variable, as it would have the same effect as the below code. However, it makes sense code wise and for organizational purposes, if you only want to persist information globally across instances of Entity.


*/

# include <iostream>

struct Entity {
    // int x, y;
    static int x, y;

    // void Print() {
    //     std::cout << x << ", " << y << std::endl;
    // }

    /*
    This will work fine since 'x' and 'y' are also declared as 'static' variables. If they weren't, then this would break, since the method itself is trying to access variable instances pertaining to the class instance

    Key thing to know is that 'static' methods CANT access 'non-static' variables. The reason is that a 'static' method doesn't have a class instance. Every method (non-static) always gets an instance of its class as a parameter. A static method is the same as if you wrote the method outside of the class. Refer to the comment block outside of this 'struct'
    */
    static void Print() {
        std::cout << x << ", " << y << std::endl;
    }
};

// Writing the 'static void Print()' is essentially the same as the below. Here, its a lot more clear as to the 'why' the Print function can't access 'x' or 'y'.
// static void Print() {
//     std::cout << x << ", " << y << std::endl;
// }

// Now imagine if you took the same function above, and passed 'Entity' as a parameter
static void Print(Entity e) {
    std::cout << e.x << ", " << e.y << std::endl;
}

static void UsePrint() {
    Entity e{};
    Print(e);
}

// If x and y are declared static to the struct/class, then we need to define the static variables somewhere
int Entity::x; // '::' defines the scope of a class or struct
int Entity::y;

int main() {
    Entity e;
    (void)e;
    // e.x = 2;
    // e.y = 3;
    Entity::x = 2; // Refer to the comments below, but this makes more sense logically, as you're changing the value of 'x' and 'y' globally across the 'Entity' class (it's namespace, if you will)
    Entity::y = 3;

    // Entity e1 = { 5, 8}; // When x and y are 'static', this initializer will fail because x and y are no longer class members
    Entity e1; // The next 2 lines of code below is not structurally written correct, but for the purposes of the example, it'll work.
    (void)e1;
    // e1.x = 5;
    // e1.y = 8;

    // When declared static, we can actually refer to variables as so:
    Entity::x = 5; // Essentially, 'x' and 'y' are variables that exist in the 'Entity' namespace. They don't really belong to the class
    Entity::y = 8;

    // The below code is only applicable if the 'Print' method isn't declared 'static'
    // e.Print(); // When 'x' and 'y' are declared static, then this will print out '5' and '8'.
    // e1.Print();

    // When 'Print' is 'static', then the below convention is the correct way to invoke it
    Entity::Print();
    Entity::Print();
    UsePrint();
    std::cin.get();
}