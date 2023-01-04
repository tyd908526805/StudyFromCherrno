#include <iostream>
#include <string>

class Entity
{
    public:
        Entity()
        {
            std::cout << "Created Entity!" << std::endl;
        }
        ~Entity()
        {
            std::cout << "Destory Entity!" << std::endl;
        }
};

/*
int* CreateArray()
{
    int* array = new int[50];
    return array;
}
void CreateArray(int* array)
{
}
*/

class ScopedPtr
{
    private:
        Entity* m_Ptr;
    public:
        ScopedPtr(Entity* ptr)
            : m_Ptr(ptr)
        {
        }
        ~ScopedPtr()
        {
            delete m_Ptr;
        }
};

int main()
{
    /*
    {
        // 基于栈的变量在我们离开作用域时会被摧毁
        // 内存被释放
        Entity e;
    }
    int array[50];
    CreateArray(array);
    */
    {
        ScopedPtr e(new Entity());
        ScopedPtr e1 = new Entity();
    }
}
