/*
Interfaces (pure virtual functions) allow us to implement methods in a class that doesn't have an implementation, and then force sub classes to implement that method. Think of this as similar to abstract methods in Python. This is useful for creating a base class that defines an interface, and then having derived classes implement that interface.
*/

#include <iostream>
#include <string>

class Printable { // We're calling this an interface because it has a pure virutal function
    public:
        virtual std::string GetGlassName() = 0; // This is a pure virtual function, which means that this class is now an abstract class, and can't be instantiated. Any class that inherits from this class must implement this method, or it will also be an abstract class. This is useful for creating a base class that defines an interface, and then having derived classes implement that interface.
};

class Entity : public Printable {
    public:
        // virtual std::string GetName() { return "Entity"; }
        virtual std::string GetName() = 0;
        virtual ~Entity() = default;

        std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity {
    private:
        std::string m_Name;
    public:
        Player(const std::string& name) : m_Name(name) {}
        std::string GetName() override { return m_Name; }
        std::string GetGlassName() override { return "Player"; }
};

void PrintName(Entity* entity) {
    std::cout << entity->GetName() << std::endl;
}

class A : public Printable {
    public:
        std::string GetGlassName() override { return "Class A"; }
};

void Print(Printable* obj) {
    std::cout << obj->GetGlassName() << std::endl;
}

int main() {
    // Entity* e = new Entity(); // This will throw an error because we can't instantiate an abstract class
    Player* p = new Player("Alice"); // You can only instantiate a class that implements the pure virtual function
    PrintName(p);
    delete p;
}