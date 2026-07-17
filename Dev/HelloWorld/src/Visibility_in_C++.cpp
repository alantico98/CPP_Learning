/*
Visibility is purely something that exists to help you write better code. It has no effect on the performance. In C++, there are 3 levels of visibility:

1. Public
2. Private
3. Protected
*/
#include <iostream>
#include <string>

class Entity {
// private:  // Only this entity class can access these variables. However, there are things called 'friend' classes and functions that can access private variables.
    // int X, Y;

    // void Print() {}

// protected: // Only this entity class and classes
public:
    int X, Y;
    void Print() {}

public:
    Entity() {
        X = 0;
        Print(); // These work fine because the constructor is part of the class, and therefore has access to private variables and methods
    };
};

class Player : public Entity {
public:
    Player() {
        X = 2; // This will throw an error because X is a private variable in the Entity class, and the Player class is trying to access it. This is because the Player class is a derived class of the Entity class, and it doesn't have access to the private variables of the Entity class.
        Print(); // This will also throw an error
    }
};

int main() {
    Entity e;
    e.Print(); // If void is protected, then only in the code block existing in Player can access it. Instances of the class still can't access them.
    e.X = 2;
    std::cin.get();
}