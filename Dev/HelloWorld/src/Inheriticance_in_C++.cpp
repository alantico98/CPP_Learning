/*
Fundamentals of C++ Programming

Allows for a hieararchy of classes, where a class can inherit from another class, and gain access to its members and methods. This allows for code reuse and a more organized structure. Primary reason its useful is because it helps avoid code duplication.
*/

#include <iostream>

class Entity {
    public:
        float X, Y;

        void Move(float xa, float ya) {
            X += xa;
            Y += ya;
        }

};

class Player : public Entity{
    // The Player class now also has the type of Entity.
    public:
        const char* Name;

        void PrintName() {
            std::cout << Name << std::endl;
        }
};

int main() {
    std::cout << sizeof(Entity) << std::endl; // 8 bytes, since it has 2 floats, and each float is 4 bytes
    std::cout << sizeof(Player) << std::endl; // 12 bytes, since it contains the 2 floats from Entity, plus the const char* Name, which is 4 bytes.

    Player player;
    player.Move(5, 5); // This is possible because the Player class inherits from the Entity class, and therefore has access to its members and methods.
    player.Name = "Alan";
    player.PrintName();
    std::cin.get();
}