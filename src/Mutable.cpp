#include <iostream>
#include <string>

class Entity
{
    private:
        std::string m_Name;
        // 类中const方法可以修改这个成员
        mutable int m_DebugCount = 0;
    public:
        const std::string& GetName() const 
        { 
            m_DebugCount++;
            return m_Name; 
        }
};

#if 0
int main()
{
    const Entity e;
    e.GetName();

    int x = 9;
    // = 值传递
    // & 引用传递
    auto f = [=]() mutable
    {
        // 使用mutable会创建一个局部变量
        // 如果是引用传递会修改x的值
        x++;
        int y = x;
        y++;
        std::cout << y << std::endl;
    };
    f();
}
#endif
