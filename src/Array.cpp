#include <iostream>
#include <array>

class Entity
{
    public:
        // 内存实际为一行 包含了数组所有的2
        // 为栈中数组申请内存时 必须是一个编译时就需要知道的常量
        // const int size = 5; 错误
        static const int size = 5; //正确
        int example[size];
        // 内存显示为另一个内存地址(就是指针)
        // 通过另一个地址可以访问到真正的数据 数组中所有的2
        int* another = new int[5];

        std::array<int, 5> arr;

        Entity()
        {
            for (int i = 0; i < size ; i++)
                example[i] = 2;
            // 可以使用array的函数size()
            // 会有内存额外开销
            for (int i = 0; i < arr.size(); i++)
                arr[i] = 2;
        }
};

#if 0
int main()
{
    /*
    example[0] = 2;
    example[4] = 4;

    // debug模式下内存访问冲突会导致程序崩溃
    // release模式下 可能不会收到错误 意味着改动了不属于你的内存
    // 数组中的数据是连续的
    int a = example[0];
    // 所以索引2的元素就是 地址偏移就是2乘每个元素大小(这里就是2*4, 内存地址向后8个字节)
    // 所以example[2]赋值时会被写入内存的这个位置
    // 数组本质是一个指针
    // int example[5] 一个指向包含5个整数的内存块的整形指针
    int* ptr = example;

    example[2] = 5;
    // 指针会根据实际类型来计算实际的字节数
    // 因为是整型指针 所以是加上2*4(每个整型是4字节)
    *(ptr + 2) = 5;
    // 如果想用字节处理
    // 因为想写入的是4字节的整数 不是1字节的char 所以+8
    // 因是char类型 需要转换回int*类型
    *(int*)((char*)ptr + 8) = 6;

    //std::cout << example[0] << std::endl;
    std::cout << example[2] << std::endl;
    // 只会打印内存地址 本质是一个指针
    std::cout << example << std::endl;

    // 和int example[5]含义相同
    // 生命周期不同
    // int example[5] 
    // 创造在栈上 跳出作用域时会被销毁
    // int anthoer = new int[5] 
    // 创建在堆上 一直存活到直到我们把它销毁或程序结束
    // 需要用delete关键字来删除
    int* another = new int[5];
    delete[] another;
    // 如果你想返回的是函数内新创建的数组
    // 需要用new关键字来创建
    */

    // 内存间接寻址(memory indirection)
    // 在e的地址上得到了另一个地址 这个地址指向了我们实际的数组
    // 如果要访问这个数组 要在代码中跳跃 会影响性能
    Entity e;
    
    // c++11 中std::array
    // 有边界检查 记录数组大小的优点
    // 原生数组的大小其实没有办法计算
    // int example[5] 如果使用sizeof(example)
    // 得到的实际为这个数组占了多少字节
    // int是4个字节 有5个元素 所以是20字节
    // 想知道有多少个元素应该为 sizeof(example) / sizeof(int)
    // 只能栈上分配的数组使用
    // 如果是int* another = new int[5];
    // sizeof(another) 得到是一个整型指针的大小 4字节
    // sizeof(another) / sizeof(int) = 1 并不是实际元素的大小
}
#endif
