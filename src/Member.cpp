#include <iostream>
#include <string>

#if 0
class Example
{
    private:
        int x;
    public:
        Example()
        {
            std::cout << "Example createrd" << std::endl;
        }
        Example(int x)
        {
            std::cout << "Example createrd with " << x << std::endl;
        }
};

class Entity
{
    private:
        std::string m_Name;
        int m_Score;
        Example m_Example;
    public:
        // 不论怎么写都会按照类成员的定义顺序去初始化 
        Entity()
            : m_Name("Unknow"), m_Score(0), m_Example(8)
        {
            // 会先执行默认构造函数创建m_Name
            // 舍弃之后 再用m_Name = "Unknow" 赋值
            // m_Name = "Unknow";
            //m_Example = Example(8);
        }
        Entity(const std::string& name)
            : m_Name(name)
        {
        }

        const std::string& GetName() const { return m_Name; }
};

int main()
{
    Entity e;
    /*
    std::cout << e.GetName() << std::endl;

    Entity e1("Tang");
    std::cout << e1.GetName() << std::endl;
    */
}
#endif
