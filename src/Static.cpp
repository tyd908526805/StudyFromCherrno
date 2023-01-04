#include <iostream> 

// static 根据上下文分为两种
// 一种是在类class或者结构体struct外使用static
// 另一种是在类class或者结构体struct内使用static
// 类外的static修饰符号在Link阶段是局部的
// 它只对定义它的编译单元(.obj)可见
// 类内的表示这部分内存是这个类的所有实例共享的
// 就像实例化了很多次这个类或者结构体
// 但是静态变量只会有一个实例
// 类里面的静态方法没有该实例的指针(this)

// static 表示这个变量在link的时候只在这个编译单元(.obj)里可见
// 定义的函数和变量只对它的声明所在文件是可见的
//static int s_Variable = 5;
int s_Variable = 5;

// 如果在类内定义了一个实例
// 这个类的所有实例中 这个变量只有一个实例
// 通过类实例来引用静态变量是没意义的
// 静态方法不能访问类的实例
struct Entity
{
    // 将x,y 在所有的Entity类的实例中只有一个副本
    // 指向同一个内存空间
    // 在单元内部进行链接 而不是在整个项目中全局可见
    static int x, y;
    // 静态方法不能访问非静态成员
    // 因为静态方法没有类实例
    // 在类里写的每个非静态方法都会获得当前的类实例作为参数(this)
    static void Print()
    {
        std::cout << "x: " << x << " y: " << y << std::endl;
    }
};

int Entity::x;
int Entity::y;

#if 0
int  main()
{
    Entity e;
    e.x = 2; //等同于 Entity::x = 2;
    e.y = 3; //等同于 Entity::y = 3;

    Entity e1;
    e1.x = 5; //等同于 Entity::x = 5;
    e1.y = 8; //等同于 Entity::y = 8;

    //Entity e1 = {5, 8};
    e.Print(); //等同于 Entity::Print()
    e1.Print(); //等同于 Entity::Print()
}
#endif
