#include <iostream>
#include <string>
#include <memory>
// 智能指针本质是一个原始指针的包装
// 当你调用智能指针的时候 会调用new并且为你分配内存

// unqiue_ptr 作用域指针 超出作用域时 会被销毁 调用delete
// 不能复制unique_ptr 如果复制了一个unique_ptr
// 那么你会有两个指针指向同一个内存块
// 如果其中一个死了 会释放掉那个内存 也就是另一个unique_ptr指向了已经释放的内存

// shared_ptr 共享指针 是通过引用计数 跟踪你的指针有多少个引用
// 一旦引用计数达到0 就会被删除
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

        void Print() {}
};

int main()
{
    {
        // 因为unique_ptr 内部是explict 需要显式构造函数
        // 没有构造函数的隐式转换 
        // std::unique_ptr<Entity> entity = new Entity(); //错误
        //std::unique_ptr<Entity> entity(new Entity());
        // 如果构造函数碰巧抛出异常 会安全一些
        // 不会得到一个没有引用的悬空指针 从而造成内存泄露
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();

        entity->Print();
        // unique_ptr 的拷贝构造函数和拷贝构造操作符杯删除了
        // 所以不能赋值给另一个unique_ptr
        //std::unique_ptr<Entity> e0 = entity; // 报错
        // 作用域结束时 entity会被自动销毁
    }
    {
        std::shared_ptr<Entity> e0;
        {
            // 需要分配另一块内存(控制块) 用来存储引用计数
            // 如果先创建一个new Entity 然后将其传递给shared_ptr构造函数
            // 会进行两次内存分配 先做new Entity的分
            // 然后是shared_ptr的控制内存块的分配
            // 使用make_shared会更有效率 将二者结合起来
            //std::shared_ptr<Entity> sharedEntity(new Entity()); // 同理
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            e0 = sharedEntity; // 不会报错 (引用计数+1)
        }
    }
    {
        std::weak_ptr<Entity> weakEntity;
        {
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            // weak_ptr 不会增加引用计数
            weakEntity = sharedEntity; // 不会报错 (引用计数不变)
        }
    }
}
