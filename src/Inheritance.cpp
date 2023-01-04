#include <iostream>
 
#if 0
class Entity
{
    public:
        float X, Y;

        void Move(float xa, float ya)
        {
            X += xa;
            Y += ya;
        }
};

// Entity中所有不是private的成员
// Player都可以访问
class Player : public Entity
{
    public:
        const char* Name;
        
        void PrintName()
        {
            std::cout << "Name: " << Name << std::endl;
        }
};

int main()
{
    std::cout << "Entity: " << sizeof(Entity) << std::endl;
    std::cout << "Player: " << sizeof(Player) << std::endl;
    Player player;
    player.Move(5, 4);
    player.X = 1;
}
#endif
