#include <iostream>
#include <string>

class Entity
{
    private:
        std::string m_Name;
        int m_Age;
    public:
        Entity(const std::string& name)
            : m_Name(name), m_Age(-1)
        {
        }
        explicit Entity(int age)
            : m_Name("Unknown"), m_Age(age)
        {
        }
};

#if 0
void PrintEntity(const Entity& entity)
{
    //
}

int main()
{
    Entity a("Tang");
    Entity aa = std::string("Tang");
    //会把字符串char*隐式转换std::string 传入 Entity
    PrintEntity(Entity("Tang"));
    PrintEntity(std::string("Tang"));
    // explicit 必须显示的调用构造函数
    // explicit 会禁用隐式转换
    // explicit 必须放在构造函数前面
    // 禁用隐式转换后
    Entity b = Entity(22);
    Entity bb = (Entity)22;
    // Entity bb = 22; //报错
    //Entity bbb(222); //报错
    //PrintEntity(22); //报错

    // explicit 显示调用构造函数 而不让c++编译器隐式的转换
}
#endif 
