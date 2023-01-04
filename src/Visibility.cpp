#include <iostream>
#include <string>

class Entity
{
    // 因为这是一个类
    // 默认的可见性是private
    // private 只有Entity这个类可以访问到这些变量
    // friend 友元函数 可以把其他类或者函数标记为当前类的友元
    // 可以允许你访问这个类的私有成员
    private:
        // 只有Entity类和它的友元才能访问到这些变量
        int X, Y;
    // 这个类以及它所有的派生类都可以访问到这些成员
    protected:
        void Print() {}
    // 所有人都可以访问该成员
    public:
        Entity()
        {
            X = 0;
            Y = 0;
            Print();
        }
};

class Player : public Entity
{
    Player()
    {
        Print();
    }
};
