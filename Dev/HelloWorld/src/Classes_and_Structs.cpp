#include <iostream>

# define LOG(x) std::cout << x << std::endl

class Player {
    public:
        int x, y;
        int speed;
    
        // The 'Move' function can be moved to inside the class, where it doesn't need to reference a 'Player' class since its already inside of it
        void Move(int xa, int ya) {
            x += xa * speed;
            y += ya * speed;
        }
};

// The below is an example of a function if it was external to the Player class and how to modify its attributes
// void Move(Player& player, int xa, int ya) {
//     player.x += xa * player.speed;
//     player.y += ya * player.speed;
// }

// Cherno's style: 'structs' are only to represent variables and data
// Ex: mathematical vector
struct Vec2 {
    float x, y; // It's just a representation of 2 floats and doesn't need a lot of functionality

    void Add(const Vec2& other) {
        x += other.x;
        y += other.y;
    }
};

int main() {
    /*
    To put it simply, classes are a way to use data and functionality together. Take a video game: might want to have a 3D model representing the player, their stats, etc.
    */

    // int PlayerX0, PlayerY0;
    // int speed = 2;

    // int PlayerX1, PlayerY1;
    Player player;
    // player.x = 5; // Note that player.x will throw a compiler error unless the attributes are declared public
    // Move(player, 1, -1);
    player.Move(1, -1);

    // CLASSES vs STRUCTS
    /*
    Technically, the only difference between 'struct' and 'class', is that the default for struct is that the default is 'public', and not 'private'. However, their usage is different: the only reason they existed is so that its backwards compatible with the C language (C doesn't have classes)

    Ex:
    struct Player {
        private: // <- This would be required if we didn't want the following attributes and methods to be available to the rest of the code
            int x, y;
            int speed;
        
            // The 'Move' function can be moved to inside the class, where it doesn't need to reference a 'Player' class since its already inside of it
            void Move(int xa, int ya) {
                x += xa * speed;
                y += ya * speed;
            }
    };

    What could be done is at the top of the code, we could say '#define struct class' to replace the 'struct' definition with 'class'. The difference semantically comes down to the usage. It really comes down to the style of programming of the user. It's really as trivial to the preference of the coder.

    However, classes are typically reserved for actions that are much more complicated, such as inheritance. Inheritance is typically reserved for classes only, even though there's nothing really stopping you from using structs. Divorcing the two from each other for different use cases is very important.
    */

    std::cin.get();
}