#include <iostream>
#include <string>
// 通过this可以访问成员函数(属于某个类的函数或方法)
// this是指向这个函数所属的当前对象实例的指针

class Entity;
void PrintEntity(Entity* e);
void PrintEntity2(const Entity& e);

class Entity
{
    public:
        int x, y;

        Entity(int x, int y)
        {
            Entity* const e = this;
            this->x = x;
            this->y = y;

            Entity& en = *this;
            PrintEntity(this);
            PrintEntity2(*this);
        }

        int GetX() const
        {
            const Entity* e = this;
            return x;
        }

};

#if 0
void PrintEntity(Entity* e)
{
}
void PrintEntity2(const Entity& e)
{
}
int main()
{
}
#endif
