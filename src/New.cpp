#include <iostream>
#include <string>
// new 主要目的是分配内存 在堆上分配内存
// 空闲列表 会维护有空闲字节的地址
class Entity
{
    private:
        std::string m_Name;
    public:
        Entity() : m_Name("Unknown") {}
        Entity(const std::string& name) : m_Name(name) {}

        const std::string& GetName() const { return m_Name; }
};

#if 0
int main()
{
    int a = 2;
    // b 存储的就是内存地址
    int* b = new int;
    // 分配数组 50 * 4 = 200bytes
    int* bArray = new int[4];
    // 存在默认构造函数可以省略()
    Entity* e = new Entity;
    // Entity数组
    Entity* eArray = new Entity[50];
    // new 不仅分配空间 还调用构造函数
    // new 是操作符
    // 汇编中返回了一个void* 指针
    // 一个_Size参数 
    // 通常调用new关键字 会调用底层的c函数malloc
    
    // 传入一个size(需要的字节数) 返回一个void*指针
    // Entity* e = new Entity 等同于
    Entity* pE = (Entity*)malloc(sizeof(Entity));
    // 区别在于Entity* e = new Entity 调用了构造函数
    // malloc仅仅是分配了内存 然后返回一个指向那个内存的指针 没有调用构造函数
    
    // delete 在汇编中参数有*_Block和_Size
    // 调用了C函数free free可以释放malloc申请的内存
    // 使用new时 内存没有被释放 没有被标记为空闲 不会被放回空闲列表
    // 再调用new时 这些内存不会再被分配 直到调用delete 必须手动释放
    delete e;
    delete[] eArray;
    free(pE);
}
#endif
