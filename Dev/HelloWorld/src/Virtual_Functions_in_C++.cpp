/*
Virtual functions allow for methods to be overridden in derived classes, and for the correct method to be called based on the type of the object, rather than the type of the pointer.

However, there are two issues with virtual functions. First, its the additional memory that is required in order for us to store that vtable. Secondly, its the performance hit that we take since its required to go through that vtable in order to call the method.

That being said, the performance hit more often than not is negligible, as is the memory hit. Unless there are strict memory bounds or performance requirements (such as embedded platforms), then virtual functions are a great tool to use in order to achieve polymorphism.
*/

#include <iostream>
#include <string>

class Entity {
    public:
        // std::string GetName() { return "Entity"; }
        virtual std::string GetName() { return "Entity"; }
        virtual ~Entity() = default;
};

class Player : public Entity {
    private:
        std::string m_Name;
    public:
        // For the below syntax, the ':' is called an 'initializer list', and it allows us to initialize member variables before the constructor body is executed. This is more efficient than assigning values in the constructor body, as it avoids the overhead of default construction followed by assignment. In this case, we're initializing m_Name with the value of name.
        Player(const std::string& name) : m_Name(name) {}
        std::string GetName() override { return m_Name; } // 'override' is a keyword that tells the compiler that this method is intended to override a virtual method in the base class. While not required, it does make the code more readable, and helps prevent bugs if you accidentally misspell the method name.
};

void PrintName(Entity* entity) {
    // In its current state (Entity* entity), this will always print "Entity". If we just declare the functions normally, then when its time to call a method, then its just going to call the method that belongs to the type. It looks at 'Entity' and calls GetName. We have to let C++ know that it needs to actually call the method that belongs to the type of the object passed in, not the type of the pointer. This is where 'virtual' comes in. This is called 'dynamic dispatch', which compilers implement using a 'vtable' (virtual table). This is a table of function pointers that the compiler generates for each class that has virtual functions. When you call a virtual function, the compiler looks up the function pointer in the vtable and calls the function that belongs to the type of the object, not the type of the pointer. This is how C++ implements polymorphism.
    std::cout << entity->GetName() << std::endl;
}

int main() {
    Entity* e = new Entity();
    // For the below, the '->' operator is used to access the member function of the object that the pointer is pointing to. Instead of writing (*e).GetName(), we can just write e->GetName(). This is just syntactic sugar that makes the code more readable.
    std::cout << e->GetName() << std::endl; // This will print "Entity"
    PrintName(e); // This will also print "Entity"

    Player* p = new Player("Alan");
    std::cout << p->GetName() << std::endl; // This will print "Alan"
    PrintName(p); // This will also print "Entity"

    // However, if we start referring to the Player as an Entity, then that's where we'll run into problems.

    Entity* entity = p; // Upcasting: Player* to Entity*
    std::cout << entity->GetName() << std::endl; // This will print "Entity" because the method is not virtual. This is because even though the object is of type Player, the pointer is of type Entity, and the method GetName() is not virtual, so it will call the method of the base class (Entity) instead of the derived class (Player).

    delete e;
    delete p;

    return 0;
}