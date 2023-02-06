#include <iostream>
#include <string>

class Entity
{
    public:
        int x;
        void Print() const { std::cout << "Hello!" << std::endl; }
};

class ScopedPtr
{
    private:
        Entity* m_Obj;
    public:
        ScopedPtr(Entity* entity)
            : m_Obj(entity)
        {
        }
        ~ScopedPtr()
        {
            delete m_Obj;
        }

        Entity* GetObect() { return m_Obj; }

        Entity* operator->()
        {
            return m_Obj;
        }

        const Entity* operator->() const
        {
            return m_Obj;
        }
};

#if 0
struct Vector3
{
    float x, y, z;
};

int main()
{
    Entity e;
    e.Print();

    Entity* ptr = &e;
    (*ptr).Print();
    ptr->Print();
    ptr->x = 2;

    ScopedPtr entity = new Entity();
    // 未重载->
    entity.GetObect()->Print();
    // 重载->
    entity->Print();

    const Entity* enti = new Entity();
    enti->Print(); 

    // 获取内存偏移量
    // int offset = (int)&((Vector3*)0)->x;
    // int offset = (int)&((Vector3*)nullptr)->x;
    // int offset = (int)&((Vector3*)nullptr)->y;
    // int offset = (int)&((Vector3*)nullptr)->z;
    // std::cout << offset << std::endl;
}
#endif 
